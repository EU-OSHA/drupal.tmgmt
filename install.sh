#!/bin/bash

# Go to docroot/
cd /var/www/html/docroot/

drush sql-drop -y
drush -v site-install drupal_tmgmt -y
drush cc all
drush -v php-eval "module_load_include('inc', 'drupal_tmgmt'); drupal_tmgmt_post_install();"
drush -v php-eval "module_load_include('inc', 'drupal_tmgmt'); drupal_tmgmt_post_install2();"
drush -v php-eval "module_load_include('inc', 'drupal_tmgmt'); drupal_tmgmt_create_sample_content();"
