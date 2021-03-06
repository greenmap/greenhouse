<?php
// $Id: image.imagemagick.inc,v 1.2.2.3 2007/02/19 03:55:15 walkah Exp $

/**
 * Return information about the imagemagick toolkit
 */
function image_imagemagick_info() {
  return array('name' => 'imagemagick', 'title' => 'ImageMagick Toolkit.');
  
}

/**
 * Validate and return toolkit specific settings
 */
function image_imagemagick_settings() {
  $form['image_imagemagick_convert'] = array(
    '#type' => 'textfield',
    '#title' => t('Location of the "convert" binary'),
    '#default_value' => variable_get('image_imagemagick_convert', '/usr/bin/convert'),
    '#size' => 64,
    '#validate' => array('image_imagemagick_valid_file' => array('image_imagemagick_convert')),
  );
  return $form;
}

function image_imagemagick_valid_file($formelement = NULL, $fieldname = NULL) {
  $convert_file = $formelement['#value'];

  if (!empty($convert_file) && !file_exists($convert_file)) {
    form_set_error($fieldname, t('%file does not exist or is not executable.', array('%file' => $convert_file)));
  }
}

/**
 * Resize an image to the given width and height
 */
function image_imagemagick_resize($source, $dest, $width, $height) {
  $filter = ' -scale '. $width . 'x' . $height . ' -filter QUADRATIC';
  return _image_imagemagick_convert($source, $dest, $filter);
}

/**
 * Rotate an image
 */
function image_imagemagick_rotate($source, $dest, $degrees) {
  $filter = ' -rotate ' . escapeshellarg($degrees) . ' -background #000000';  
  return _image_imagemagick_convert($source, $dest, $filter);  
}

/**
 * Crop an image to the specified dimensions
 */
function image_imagemagick_crop($source, $dest, $x, $y, $width, $height) {
  $filter = ' -crop ' . $width . 'x' . $height . '+' . $x . '+' . $y;
  return _image_imagemagick_convert($source, $dest, $filter);  
}

/**
 * Helper function: Escape filename for Unix or Windows shell.
 *
 * @param $filename filename to escape -- may contain spaces or other problematic characters
 *
 * @return escaped version of $filename which should pass through shell
 */
function _image_escape_shell($filename) {
  if (strstr($_SERVER['SERVER_SOFTWARE'], 'Win32') || strstr($_SERVER['SERVER_SOFTWARE'], 'IIS')) {
    return '"' . addslashes($filename) . '"';
  } else {
    return escapeshellarg($filename);
  }
}

/**
 * Calls the convert executable with the specified filter
 */
function _image_imagemagick_convert($source, $dest, $filter) {
  $convert_path = variable_get('image_imagemagick_convert', '/usr/bin/convert');
  if (!file_exists($convert_path)) {
    return false;
  }
  
  $filter = preg_replace("/[^A-Za-z0-9\.\-\+\040]/", '', $filter);
  $source = _image_escape_shell($source);
  $dest = _image_escape_shell($dest);
  $err = _image_exec("$convert_path $filter $source $dest");
  if ($err) {
    return false;
  }
  if (!file_exists(trim($dest, "'"))) {
    return false;
  }
  
  return true;
}

function _image_exec($cmd) {
  if (substr(php_uname(), 0, 7) == "Windows"){
    if ($h = popen("start \"bla\" $cmd", "r")) {
      pclose($h);
      return true;
    } else {
      return false;
    }
  } else {
    return exec($cmd);    
  }
} 

