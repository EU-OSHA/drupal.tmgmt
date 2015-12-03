@echo off
cd docroot/

if exist call drush sql-drop -y
call drush site-install standard -y
call drush en -y osha_tmgmt osha_tmgmt_demo
call drush en -y devel simpletest views_ui
call drush dis -y overlay
call drush cc all

# Create a demo user to test permissions
call drush user-create demo
call drush upwd --password=demo demo
