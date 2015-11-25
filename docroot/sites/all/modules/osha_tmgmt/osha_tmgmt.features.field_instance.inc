<?php
/**
 * @file
 * osha_tmgmt.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function osha_tmgmt_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_osha_tmgmt_notification'
  $field_instances['user-user-field_osha_tmgmt_notification'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_osha_tmgmt_notification',
    'label' => 'Receive OSHA translation notifications',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Receive OSHA translation notifications');

  return $field_instances;
}
