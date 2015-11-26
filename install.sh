#!/bin/bash

# Go to docroot/
cd docroot/

drush sql-drop -y
drush site-install standard -y
drush en -y osha_tmgmt
drush en -y devel simpletest
drush dis -y overlay
drush cc all
