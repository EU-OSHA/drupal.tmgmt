<?php
/**
 * @file
 * osha_tmgmt_demo.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_tmgmt_demo_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_osha_tmgmt_demo_article';
  $strongarm->value = 0;
  $export['comment_anonymous_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_osha_tmgmt_demo_article';
  $strongarm->value = 0;
  $export['comment_default_mode_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_osha_tmgmt_demo_article';
  $strongarm->value = '50';
  $export['comment_default_per_page_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_osha_tmgmt_demo_article';
  $strongarm->value = 0;
  $export['comment_form_location_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_osha_tmgmt_demo_article';
  $strongarm->value = '1';
  $export['comment_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_osha_tmgmt_demo_article';
  $strongarm->value = '0';
  $export['comment_preview_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_osha_tmgmt_demo_article';
  $strongarm->value = 0;
  $export['comment_subject_field_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_comment_filter_osha_tmgmt_demo_article';
  $strongarm->value = 0;
  $export['entity_translation_comment_filter_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_osha_tmgmt_demo_article';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_osha_tmgmt_demo_article';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__osha_tmgmt_demo_article';
  $strongarm->value = array(
    'default_language' => 'en',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_osha_tmgmt_demo_article';
  $strongarm->value = '4';
  $export['language_content_type_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_osha_tmgmt_demo_article';
  $strongarm->value = array();
  $export['menu_options_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_osha_tmgmt_demo_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_osha_tmgmt_demo_article';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_osha_tmgmt_demo_article';
  $strongarm->value = '0';
  $export['node_preview_osha_tmgmt_demo_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_osha_tmgmt_demo_article';
  $strongarm->value = 0;
  $export['node_submitted_osha_tmgmt_demo_article'] = $strongarm;

  return $export;
}
