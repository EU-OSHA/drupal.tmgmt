<?php
/**
 * @file
 * osha_tmgmt_demo.features.roles_permissions.inc
 */

/**
 * Implements hook_default_roles_permissions().
 */
function osha_tmgmt_demo_default_roles_permissions() {
  $roles = array();

  // Exported role: osha tmgmt demo content validator
  $roles['osha tmgmt demo content validator'] = array(
    'name' => 'osha tmgmt demo content validator',
    'weight' => 6,
    'permissions' => array(
      'access administration pages' => TRUE,
      'access content' => TRUE,
      'access toolbar' => TRUE,
      'can be a content validator' => TRUE,
      'view on translation content list' => TRUE,
      'view the administration theme' => TRUE,
      'view translation content validators' => TRUE,
      'view translation job' => TRUE,
      'view translation job item' => TRUE,
    ),
  );

  // Exported role: osha tmgmt demo layout validator
  $roles['osha tmgmt demo layout validator'] = array(
    'name' => 'osha tmgmt demo layout validator',
    'weight' => 5,
    'permissions' => array(
      'abort job item' => TRUE,
      'access administration pages' => TRUE,
      'access content' => TRUE,
      'access toolbar' => TRUE,
      'edit any article content' => TRUE,
      'osha tmgmt upload translation file' => TRUE,
      'preview layout validation' => TRUE,
      'set job item to translated state' => TRUE,
      'translate admin strings' => TRUE,
      'translate any entity' => TRUE,
      'translate user-defined strings' => TRUE,
      'validate layout translation' => TRUE,
      'view on translation content list' => TRUE,
      'view the administration theme' => TRUE,
      'view translation job' => TRUE,
      'view translation job item' => TRUE,
    ),
  );

  // Exported role: osha tmgmt demo translation liaison
  $roles['osha tmgmt demo translation liaison'] = array(
    'name' => 'osha tmgmt demo translation liaison',
    'weight' => 4,
    'permissions' => array(
      'access administration pages' => TRUE,
      'access toolbar' => TRUE,
      'view the administration theme' => TRUE,
      'view translation job' => TRUE,
    ),
  );

  // Exported role: osha tmgmt demo translation manager
  $roles['osha tmgmt demo translation manager'] = array(
    'name' => 'osha tmgmt demo translation manager',
    'weight' => 3,
    'permissions' => array(
      'abort job item' => TRUE,
      'accept job item translation' => TRUE,
      'access administration pages' => TRUE,
      'access content' => TRUE,
      'access toolbar' => TRUE,
      'edit translation content validators' => TRUE,
      'edit translation job item' => TRUE,
      'manage content in translators group entity collections' => TRUE,
      'osha tmgmt upload translation file' => TRUE,
      'preview layout validation' => TRUE,
      'set job item to ready to publish state' => TRUE,
      'set job item to require content validation state' => TRUE,
      'set job item to translated state' => TRUE,
      'validate layout translation' => TRUE,
      'view the administration theme' => TRUE,
      'view translation content validators' => TRUE,
      'view translation job' => TRUE,
      'view translation job item' => TRUE,
    ),
  );

  return $roles;
}
