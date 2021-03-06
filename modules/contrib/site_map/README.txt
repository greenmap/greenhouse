Drupal site map module:
----------------------
Original author - Nic Ivy http://njivy.org
Author - Fredrik Jonsson fredrik at combonet dot se
Requires - Drupal 4.7
License - GPL (see LICENSE)


Overview:
--------
This module provides a site map that gives visitors an overview of 
your site. It can also display the RSS feeds for all blogs and 
categories. Drupal generates the RSS feeds automatically but few seems 
to be aware that they exist.

The site map can display the following items:

* A message to be displayed above the site map
* The latest blogs.
* Any books that optionally will be displayed fully expanded.
* Any menus that will be displayed fully expanded.
* Any categories, i.e vocabulary, with all the terms expanded.
  Optionally with node counts and RSS feeds.
* A syndication block, the "more" link goes to the site map.

Support for menus was contributed by keve. Blogs, books and layout
changes by frjo. The rest is by the original author.


Installation:
------------
1. Copy the site_map directory to the Drupal modules/ directory.
2. Go to "administer" -> "modules" and enable the module.
3. Check the "administer" -> "access control" page to enable use of
   this module to different roles.
4. Make sure the menu item is enabled in "administer" -> "menus".
5. Visit http://example.com/sitemap.


Last updated:
------------
$Id: README.txt,v 1.5.2.2 2006/10/25 08:55:15 frjo Exp $