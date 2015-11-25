<?php

/**
 * Define extra permissions used by this module.
 */
function osha_tmgmt_extra_permissions() {
  $perms = array(
    'osha tmgmt upload translation file' => array(
      'title' => t('Upload translation file to a Job'),
    ),
    'preview layout validation' => array(
      'title' => t('Access node layout validation preview screen'),
      'description' => t('Allows Layout Validators to preview the node before accepting translation'),
    ),
    'validate layout translation' => array(
      'title' => t('Can validate a translation layout'),
      'description' => t('Allows Layout Validators to validate'),
    ),
    'view translation job' => array(
      'title' => t('View the list of translation jobs and job details'),
    ),
    'view translation job item' => array(
      'title' => t('View the job item details'),
    ),
    'edit translation job item' => array(
      'title' => t('Can edit job item no matter the state.'),
    ),
    'view translation content validators' => array(
      'title' => t('View the job item Content Validators'),
    ),
    'can be a content validator' => array(
      'title' => t('Can be a Translation Content Validator'),
    ),
    'edit translation content validators' => array(
      'title' => t('Edit the job item Content Validators'),
    ),
    'set job item to translated state' => array(
      'title' => t('Can set the job to Translated state'),
    ),
    'set job item to require content validation state' => array(
      'title' => t('Can set the job item to Require Content Validation'),
    ),
    'set job item to ready to publish state' => array(
      'title' => t('Can set the job item to Translation Ready to Publish'),
    ),
    'abort job item' => array(
      'title' => t('Can abort a job item.'),
    ),
    'accept job item translation' => array(
      'title' => t('Accept (saves to entity) job item translation!'),
    ),
    'view on translation content list' => array(
      'title' => t('View "On Translation" tab from workbench'),
    ),
    'view needs content validation list' => array(
      'title' => t('View "Needs Content Validation" tab from workbench'),
    ),
    'view untranslated jobs' => array(
      'title' => t('View "Needs Translation" tab from workbench'),
      'description' => t('Applies to translation liaison role'),
    ),
    'manage content in translators group entity collections' => array(
      'title' => t('Manage Content Validators Groups'),
    ),
  );
  return $perms;
}
