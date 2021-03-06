Description
------

Syndication.module offers a web page which centralizes all of the RSS feeds
generated by Drupal. This helps users find interesting feeds from your web site.

Currently, the syndication page helps visitors find the following feeds:
- the blog feed of any user or all users
- node feeds for taxonomy terms
- a directory of all feeds being consumed by the aggregator.module

Also, modules may insert their own boxes onto this page using the 'syndication' hook. See Help for details

Feel free to improve this module and upload patches. I am also looking for a new maintainer.

Installation
------------

1. Copy the syndication.module to the Drupal modules directory. Drupal should
automatically detect it. Then enable the module in Admin -> Site Configuration -> Modules

2. Browse to Admin -> Blocks and enable the Syndication (more) block. You'll also want
to disable the plain Syndication block offerred by node.module.

3. Visit the admin/settings/syndication page and choose which vocabularies (if any) you want to highlight on the syndication page.

To see your new Syndication page, follow the 'more' link which appears in the Block, or browse to q=syndication.

Author
------

Moshe Weitzman <weitzman AT tejasa {dot} com>

Contributors
------------

David Kent Norman <deekayen at: deekayen {dot} net>
http://deekayen.net/