<?php

$aliases['staging'] = array(
  'uri' => 'staging.project.org',
  'db-allows-remote' => TRUE,
  'remote-host' => 'staging.project.org',
  'remote-user' => 'php',
  'root' => '/var/www/html/docroot',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
);

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
