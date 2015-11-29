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

  if (!osha_tmgmt_et_taxonomy_enabled()) {
    drupal_set_message('<strong>Warning:</strong> Entity translation of taxonomy terms is disabled or not properly configured. ' . l('Visit configuration screen', 'admin/config/regional/entity_translation'), 'warning');
  }

  $form['osha_tmgmt_send_mail'] = array(
    '#title' => 'Send e-mails related to translation workflow',
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
  module_load_include('inc', 'osha_tmgmt', 'osha_tmgmt.fields');
  $values = $form_state['values'];
  $items = array_filter($values['items']);
  foreach ($items as $k => $name) {
    $fields = field_info_instances('node', $name);
    $is_active = array_key_exists('field_page_count', $fields);
    $et_var_name = 'language_content_type_' . $name;
    $can_be_activated = variable_get($et_var_name) == 4 && array_key_exists('title_field', $fields);
    if (!$is_active && $can_be_activated) {
      $config = osha_tmgmt_field_character_count_instance();
      $config['bundle'] = $name;
      field_create_instance($config);

      $config = osha_tmgmt_field_page_count_instance();
      $config['bundle'] = $name;
      field_create_instance($config);
    }
  }

  variable_set('osha_tmgmt_send_mail', $form_state['values']['osha_tmgmt_send_mail']);
}
