<?php
/**
 * @file
 * osha_tmgmt.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_tmgmt_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "entity_collection" && $api == "entity_collection_bundles_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_tmgmt_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}