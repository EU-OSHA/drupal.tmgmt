<?php
/**
 * @file
 * osha_tmgmt_demo.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function osha_tmgmt_demo_user_default_roles() {
  $roles = array();

  // Exported role: osha tmgmt demo layout validator.
  $roles['osha tmgmt demo layout validator'] = array(
    'name' => 'osha tmgmt demo layout validator',
    'weight' => 5,
  );

  // Exported role: osha tmgmt demo translation liaison.
  $roles['osha tmgmt demo translation liaison'] = array(
    'name' => 'osha tmgmt demo translation liaison',
    'weight' => 4,
  );

  // Exported role: osha tmgmt demo translation manager.
  $roles['osha tmgmt demo translation manager'] = array(
    'name' => 'osha tmgmt demo translation manager',
    'weight' => 3,
  );

  return $roles;
}
