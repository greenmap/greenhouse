<?php

/*
 *   the key to the array must be '#pattern#' where pattern is the string to
 *   match. See the manual for preg_replace for details. 
 *
 *   You can also use '/pattern/'
 */
$by_referer_config = array(
  // key is a pattern to match in a drupal path
    '#icons/#' => array(
    // string 'referers' is always the key here
    'referers' => array(
      // key is pattern for referer, value is name of theme
      '#file:///var/mobile/Applications/#' => 'iphoneappreferral', '#findsites/icons#' => 'iphoneappreferral'
    ),
  ),
       'DEBUG' => FALSE,
);
