<?php

/**
 * Implements hook_rules_event_info().
 */
function osha_tmgmt_rules_event_info() {
  $items = array(
    'osha_tmgmt_needs_cv_approval' => array(
      'label' => t('When content validators actions are required'),
      'group' => t('EU-OSHA TMGMT'),
      'variables' => array(
        'tmgmt_job_item' => array(
          'type' => 'tmgmt_job_item',
          'label' => t('Approved job item'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('Next approver'),
        ),
        'users' => array(
          'type' => 'list<user>',
          'label' => t('Remaining approvers'),
        ),
      ),
      'access callback' => 'rules_node_integration_access',
    ),
    'osha_tmgmt_no_need_cv_approval' => array(
      'label' => t('After canceling content validators action'),
      'group' => t('EU-OSHA TMGMT'),
      'variables' => array(
        'tmgmt_job_item' => array(
          'type' => 'tmgmt_job_item',
          'label' => t('Approved job item'),
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('Next approver'),
        ),
        'users' => array(
          'type' => 'list<user>',
          'label' => t('Remaining approvers'),
        ),
      ),
      'access callback' => 'rules_node_integration_access',
    ),
  );
  return $items;
}
