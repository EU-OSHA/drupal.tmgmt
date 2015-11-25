<?php

function osha_tmgmt_config_form($form, &$form_state) {
  $form = array();
  $content_types = node_type_get_types();
  $items = array();

  $form['items'] = array(
    '#title' => 'Translation workflow status',
    '#description' => 'Check the types of content you want to enable the translation workflow',
    '#type' => 'checkboxes',
    '#options' => $items,
  );

  foreach ($content_types as $name => $content_type) {
    $fields = field_info_instances('node', $name);
    $et_var_name = 'language_content_type_' . $name;
    $is_active = array_key_exists('field_page_count', $fields);
    $can_be_activated = variable_get($et_var_name) == 4 && array_key_exists('title_field', $fields);
    $form['items']['#options'][$name] = $content_type->name;
    if ($is_active) {
      $form['items'][$name]['#disabled'] = TRUE;
      $form['items']['#default_value'][$name] = $name;
    }
    if (!$is_active && !$can_be_activated) {
      $form['items'][$name]['#disabled'] = TRUE;
      $error = ' <span class="error">(Cannot be enabled, enable <b>' . l('multilingual support, with field translation', 'admin/structure/types/manage/' . $name) . '</b> and <b>' . l('replace the title field', 'admin/structure/types/manage/' . $name . '/fields') . '</b>)</span>';
      $form['items']['#options'][$name] .= $error;
    }
  }

  $enabled_types = array_filter(variable_get('entity_translation_entity_types', array()));
  if (empty($enabled_types['taxonomy_term'])) {
    drupal_set_message('<strong>Warning:</strong> Entity translation of taxonomy terms is disabled or not properly configured. ' . l('Visit configuration screen', 'admin/config/regional/entity_translation'), 'warning');
  }

  $form['osha_tmgmt_send_mail'] = array(
    '#title' => 'Send mail',
    '#type' => 'checkbox',
    '#default_value' => variable_get('osha_tmgmt_send_mail', FALSE),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );
  return $form;
}

function osha_tmgmt_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $items = array_filter($values['items']);
  foreach ($items as $k => $name) {
    $fields = field_info_instances('node', $name);
    $is_active = array_key_exists('field_page_count', $fields);
    $et_var_name = 'language_content_type_' . $name;
    $can_be_activated = variable_get($et_var_name) == 4 && array_key_exists('title_field', $fields);
    if (!$is_active && $can_be_activated) {
      _osha_tmgmt_create_field_character_count($name);
      _osha_tmgmt_create_field_page_count($name);
    }
  }

  variable_set('osha_tmgmt_send_mail', $form_state['values']['osha_tmgmt_send_mail']);
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
