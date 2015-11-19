<?php

/**
 * Configure the installation during profile install
 */
function drupal_tmgmt_install_project() {
  variable_set('error_level', 0);
  variable_set('dblog_row_limit', 100);
  global $cfg;
  $variables = $cfg->variables;
  foreach ($variables as $k => $v) {
    variable_set($k, $v);
    watchdog('drupal_tmgmt', 'Setting !variable = !value', array('!variable' => $k, '!value' => $v), WATCHDOG_NOTICE);
  }
}

/**
 * Post-install step to execute some configuration in another transaction
 */
function drupal_tmgmt_post_install() {
  module_enable(array('osha_taxonomies'));
  module_enable(array('osha'));
  module_enable(array('osha_tmgmt'));
  module_enable(array('osha_workflow'));
}

/**
 * Post-install step to execute some configuration in another transaction
 */
function drupal_tmgmt_post_install2() {
  drupal_tmgmt_create_roles();
}

function drupal_tmgmt_create_roles() {
  $newRoles = array('Editor', 'Review Manager', 'Project Manager', 'Approver',
    'Translation Manager', 'Translation Liaison', 'Layout Validator', 'Content Validator'
  );
  foreach ($newRoles as $r){
    if (!user_role_load_by_name($r)) {
      $role = new stdClass();
      $role->name = $r;
      user_role_save($role);
      watchdog('drupal_tmgmt', 'Creating new role: !role', array('!role' => $r), WATCHDOG_INFO);
    }
  }

  module_load_include('inc', 'osha_tmgmt', 'osha_tmgmt.workflow');
  osha_tmgmt_workflow_create_roles();
  osha_workflow_create_roles();

  drupal_tmgmt_setup_sections();
  drupal_tmgmt_create_test_users();
}

function drupal_tmgmt_setup_sections() {
  $ids = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('section');
  $s1 = new stdClass();
  $s1->name = 'Section 1';
  $s1->vid = $vocabulary->vid;
  $s1->language = 'en';
  taxonomy_term_save($s1);
  $ids[] = $s1->tid;

  $s2 = new stdClass();
  $s2->name = 'Section 2';
  $s2->vid = $vocabulary->vid;
  $s2->language = 'en';
  taxonomy_term_save($s2);
  $ids[] = $s2->tid;

  // Give the admin account access to all sections.
  workbench_access_user_section_save(1, 'section', 'taxonomy');
}

/**
 * Create test users for the workflow
 */
function drupal_tmgmt_create_test_users() {

  $editor = user_role_load_by_name('EDITOR');
  $rm = user_role_load_by_name('REVIEW MANAGER');
  $pm = user_role_load_by_name('PROJECT MANAGER');
  $tm = user_role_load_by_name('TRANSLATION MANAGER');
  $tl = user_role_load_by_name('TRANSLATION LIAISON');
  $lv = user_role_load_by_name('LAYOUT VALIDATOR');
  $cv = user_role_load_by_name('CONTENT VALIDATOR');
  $approver = user_role_load_by_name('APPROVER');

  $users = array(
    'editor1' => array(
      'mail' => 'editor1@example.com',
      'roles' => array($editor->rid => 'EDITOR')
    ),
    'editor2' => array(
      'mail' => 'editor2@example.com',
      'roles' => array($editor->rid => 'EDITOR')
    ),
    'rm' => array(
      'mail' => 'rm@example.com',
      'roles' => array($rm->rid => 'REVIEW MANAGER')
    ),
    'pm' => array(
      'mail' => 'pm@example.com',
      'roles' => array($pm->rid => 'PROJECT MANAGER')
    ),
    'tm' => array(
      'mail' => 'tm@example.com',
      'roles' => array($tm->rid => 'TRANSLATION MANAGER')
    ),
    'tl' => array(
      'mail' => 'tl@example.com',
      'roles' => array($tl->rid => 'TRANSLATION LIAISON')
    ),
    'lv' => array(
      'mail' => 'lv@example.com',
      'roles' => array($lv->rid => 'LAYOUT VALIDATOR')
    ),
    'cv' => array(
      'mail' => 'cv@example.com',
      'roles' => array($cv->rid => 'CONTENT VALIDATOR')
    ),
    'approver1' => array(
      'mail' => 'approver1@example.com',
      'roles' => array($approver->rid => 'APPROVER')
    ),
    'approver2' => array(
      'mail' => 'approver2@example.com',
      'roles' => array($approver->rid => 'APPROVER')
    ),
  );

  $fields = array(
    'pass' => 'vagrant',
    'status' => 1,
    'init' => 'email address',
  );
  foreach($users as $name => $config) {
    $c = array_merge($fields, $config);
    $c['name'] = $name;
    watchdog('drupal_tmgmt', 'Creating user: !user ...', array('!user' => $name), WATCHDOG_INFO);
    user_save('', $c);
  }

  // Add approvers to the queue
  $a1 = user_load_by_name('approver1');
  $a2 = user_load_by_name('approver2');
  $et = entity_collection_load('approvers');
  $context = _entity_collection_get_contexts($et);
  $item = new EntityCollectionTreeNode('user', $a1->uid, $a1);
  entity_collection_append_item($et, $item, $context);
  $item = new EntityCollectionTreeNode('user', $a2->uid, $a2);
  entity_collection_append_item($et, $item, $context);

  // Configure review manager rm for all sections
  $rm = user_load_by_name('rm');
  $form_state['values'] = array(
    'add_user' => $rm->uid,
    'workbench_access' => array(
      'access_id' => 'section',
      'access_scheme' => 'taxonomy',
    ),
  );
  osha_workflow_access_rm_form_submit(array(), $form_state);

  module_load_include('inc', 'osha_workflow', 'osha_workflow.admin');
  // Configure project manager pm for all sections
  $pm = user_load_by_name('pm');
  $form_state['values'] = array(
    'add_user' => $pm->uid,
    'workbench_access' => array(
      'access_id' => 'section',
      'access_scheme' => 'taxonomy',
    ),
  );
  osha_workflow_access_pm_form_submit(array(), $form_state);

  // Configure Editorial access per section - roles below have access to all sections
  $role_administrator = user_role_load_by_name('ADMINISTRATOR');
  $role_rm = user_role_load_by_name('REVIEW MANAGER');
  $role_pm = user_role_load_by_name('PROJECT MANAGER');
  $role_approver = user_role_load_by_name('APPROVER');
  $role_tm = user_role_load_by_name('TRANSLATION MANAGER');
  $role_lv = user_role_load_by_name('LAYOUT VALIDATOR');

  $values = array(
    'roles' => array(
      $role_administrator->rid => $role_administrator->rid,
      $role_rm->rid => $role_rm->rid,
      $role_pm->rid => $role_pm->rid,
      $role_approver->rid => $role_approver->rid,
      $role_tm->rid => $role_tm->rid,
      $role_lv->rid => $role_lv->rid,
    ),
  );
  foreach ($values['roles'] as $rid => $status) {
    workbench_access_role_section_save($rid, 'section', 'taxonomy');
  }

  // Assign editor1 to 'Section 1', editor2 to 'Section 2'
  $terms = taxonomy_get_term_by_name('Section 1', 'section');
  $s1 = reset($terms);
  $terms = taxonomy_get_term_by_name('Section 2', 'section');
  $s2 = reset($terms);
  $editor1 = user_load_by_name('editor1');
  workbench_access_user_section_save($editor1->uid, $s1->tid, 'taxonomy');
  $editor2 = user_load_by_name('editor2');
  workbench_access_user_section_save($editor2->uid, $s2->tid, 'taxonomy');
}

function drupal_tmgmt_create_sample_content() {
  $vocabulary = taxonomy_vocabulary_machine_name_load('section');
  $sections = taxonomy_get_tree($vocabulary->vid);

  $n1 = new stdClass();
  $n1->title = 'Sample draft article';
  $n1->type = 'article';
  $n1->body['en'][0]['value'] = 'This node should be in Draft mode';
  $n1->workbench_access = array($sections[0]->tid => $sections[0]->tid);
  node_object_prepare($n1);
  node_save($n1);


  $n1 = new stdClass();
  $n1->title = 'Final draft article';
  $n1->type = 'article';
  $n1->body['en'][0]['value'] = 'This node should be in Final mode';
  $n1->workbench_access = array($sections[1]->tid => $sections[1]->tid);
  node_object_prepare($n1);
  node_save($n1);

  workbench_moderation_moderate($n1, 'final_draft');
}
