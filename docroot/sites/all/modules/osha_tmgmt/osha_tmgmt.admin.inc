<?php

function osha_tmgmt_config_form($form, &$form_state) {
  $form = array();
  $content_types = node_type_get_types();
  $already_activated = array();
  $can_be_activated = array();
  foreach ($content_types as $name => $content_type) {
    $fields = field_info_instances('node', $name);
    if (array_key_exists('field_page_count', $fields)) {
      $already_activated[] = $name;
      continue;
    }
    $et_var_name = 'language_content_type_' . $name;
    if (variable_get($et_var_name) == 4 && array_key_exists('title_field', $fields)) {
      $can_be_activated[$name] = $content_type->name;
    }
  }

  $form['activated'] = array(
    '#type' => 'markup',
    '#markup' => implode(', ', $already_activated),
  );

  $form['activate'] = array(
    '#title' => 'Activate for these content types',
    '#type' => 'checkboxes',
    '#options' => $can_be_activated,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  return $form;
}

function osha_tmgmt_config_form_submit($form, &$form_state) {
  $activate = array_filter($form_state['input']['activate']);
  foreach ($activate as $name) {
    _osha_tmgmt_create_field_character_count($name);
    _osha_tmgmt_create_field_page_count($name);
  }
}

function _osha_tmgmt_create_field_character_count($bundle) {
  $instance = array(
    'bundle' => $bundle,
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Automatically calculated when saving. The count of characters found in the default language text (English).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_character_count',
    'label' => 'Character count',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );
  field_create_instance($instance);
}

function _osha_tmgmt_create_field_page_count($bundle) {
  $instance = array(
    'bundle' => $bundle,
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Automatically calculated when saving. The count of pages of text in the default language (English).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_count',
    'label' => 'Page count',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );
  field_create_instance($instance);
}
