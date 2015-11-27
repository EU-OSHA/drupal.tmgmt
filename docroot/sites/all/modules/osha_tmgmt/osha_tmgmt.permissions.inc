<?php

/**
 * Define extra permissions used by this module.
 */
function osha_tmgmt_extra_permissions() {
  $perms = array(
    'administer osha tmgmt' => array(
      'title' => 'Administer EU-OSHA TMGMT',
      'description' => 'Configure the EU-OSHA translation workflow',
      'restrict access' => TRUE,
    ),

    'osha tmgmt upload translation file' => array(
      'title' => t('Upload translation file to a Job'),
    ),
    'osha tmgmt preview layout validation' => array(
      'title' => t('Access node layout validation preview screen'),
      'description' => t('Allows Layout Validators to preview the node before accepting translation'),
    ),
    'osha tmgmt validate layout translation' => array(
      'title' => t('Can validate a translation layout'),
      'description' => t('Allows Layout Validators to validate'),
    ),
    'osha tmgmt view translation job' => array(
      'title' => t('View the list of translation jobs and job details'),
    ),
    'osha tmgmt view translation job item' => array(
      'title' => t('View the job item details'),
    ),
    'osha tmgmt edit translation job item' => array(
      'title' => t('Can edit job item no matter the state.'),
    ),
    'osha tmgmt view translation content validators' => array(
      'title' => t('View the job item Content Validators'),
    ),
    'osha tmgmt can be a content validator' => array(
      'title' => t('Can be a Translation Content Validator'),
    ),
    'osha tmgmt edit translation content validators' => array(
      'title' => t('Edit the job item Content Validators'),
    ),
    'osha tmgmt set job item to translated state' => array(
      'title' => t('Can set the job to Translated state'),
    ),
    'osha tmgmt set job item to require content validation state' => array(
      'title' => t('Can set the job item to Require Content Validation'),
    ),
    'osha tmgmt set job item to ready to publish state' => array(
      'title' => t('Can set the job item to Translation Ready to Publish'),
    ),
    'osha tmgmt abort job item' => array(
      'title' => t('Can abort a job item.'),
    ),
    'osha tmgmt accept job item translation' => array(
      'title' => t('Accept (saves to entity) job item translation!'),
    ),
    'osha tmgmt manage content in translators group entity collections' => array(
      'title' => t('Manage Content Validators Groups'),
    ),
  );
  return $perms;
}
