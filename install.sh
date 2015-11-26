#!/bin/bash

# Go to docroot/
cd docroot/

if [ -f sites/default/settings.php ]; then
    drush sql-drop -y
fi
drush site-install standard -y
drush en -y osha_tmgmt osha_tmgmt_demo
drush en -y devel simpletest
drush dis -y overlay
drush cc all
