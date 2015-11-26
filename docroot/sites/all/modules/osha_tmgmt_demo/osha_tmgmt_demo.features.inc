<?php
/**
 * @file
 * osha_tmgmt_demo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_tmgmt_demo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function osha_tmgmt_demo_node_info() {
  $items = array(
    'osha_tmgmt_demo_article' => array(
      'name' => 'TMGMT Article',
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
