<?php

/**
 * Workflow demo roles
 * @return array
 */
function osha_tmgmt_demo_roles() {
  return array(
    (object) array(
      'name' => 'content validator',
      'weight' => 6,
    ),
    (object) array(
      'name' => 'layout validator',
      'weight' => 5,
    ),
    (object) array(
      'name' => 'translation liaison',
      'weight' => 4,
    ),
    (object) array(
      'name' => 'translation manager',
      'weight' => 3,
    ),
  );
}

function osha_tmgmt_demo_users() {
  $tm = user_role_load_by_name('translation manager');
  $tl = user_role_load_by_name('translation liaison');
  $cv = user_role_load_by_name('content validator');
  $lv = user_role_load_by_name('layout validator');
  return array(
    'demo_tm' => array(
      'name' => 'demo_tm',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($tm->rid => 'translation manager')
    ),
    'demo_tl' => array(
      'name' => 'demo_tl',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($tl->rid => 'translation liaison')
    ),
    'demo_cv1' => array(
      'name' => 'demo_cv1',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($cv->rid => 'content validator'),
      'tmgmt_translation_skills' => array(LANGUAGE_NONE => array(0 => array('language_from' => 'en', 'language_to' => 'es'))),
    ),
    'demo_cv2' => array(
      'name' => 'demo_cv2',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($cv->rid => 'content validator'),
      'tmgmt_translation_skills' => array(LANGUAGE_NONE => array(0 => array('language_from' => 'en', 'language_to' => 'fr'))),
    ),
    'demo_cv3' => array(
      'name' => 'demo_cv3',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($cv->rid => 'content validator'),
      'tmgmt_translation_skills' => array(LANGUAGE_NONE => array(0 => array('language_from' => 'en', 'language_to' => 'de'))),
    ),
    'demo_lv' => array(
      'name' => 'demo_lv',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($lv->rid => 'layout validator')
    ),
  );
}

function osha_tmgmt_demo_roles_permissions() {
  $roles = array();

  // Exported role: content validator
  $roles['content validator'] = array(
    'name' => 'content validator',
    'weight' => 6,
    'permissions' => array(
      'accept translation jobs' => TRUE,
      'access administration pages' => TRUE,
      'access content' => TRUE,
      'access toolbar' => TRUE,
      'osha tmgmt can be a content validator' => TRUE,
      'osha tmgmt view translation content validators' => TRUE,
      'osha tmgmt view translation job' => TRUE,
      'osha tmgmt view translation job item' => TRUE,
      'use text format filtered_html' => TRUE,
      'use text format full_html' => TRUE,
      'view the administration theme' => TRUE,
    ),
  );

  // Exported role: layout validator
  $roles['layout validator'] = array(
    'name' => 'layout validator',
    'weight' => 5,
    'permissions' => array(
      'accept translation jobs' => TRUE,
      'access administration pages' => TRUE,
      'access content' => TRUE,
      'access toolbar' => TRUE,
      'osha tmgmt abort job item' => TRUE,
      'osha tmgmt preview layout validation' => TRUE,
      'osha tmgmt set job item to translated state' => TRUE,
      'osha tmgmt upload translation file' => TRUE,
      'osha tmgmt validate layout translation' => TRUE,
      'osha tmgmt view translation job' => TRUE,
      'osha tmgmt view translation job item' => TRUE,
      'translate admin strings' => TRUE,
      'translate any entity' => TRUE,
      'translate user-defined strings' => TRUE,
      'use text format filtered_html' => TRUE,
      'use text format full_html' => TRUE,
      'view the administration theme' => TRUE,
    ),
  );

  // Exported role: translation liaison
  $roles['translation liaison'] = array(
    'name' => 'translation liaison',
    'weight' => 4,
    'permissions' => array(
      'access administration pages' => TRUE,
      'access toolbar' => TRUE,
      'osha tmgmt view translation job' => TRUE,
      'view the administration theme' => TRUE,
    ),
  );

  // Exported role: translation manager
  $roles['translation manager'] = array(
    'name' => 'translation manager',
    'weight' => 3,
    'permissions' => array(
      'accept translation jobs' => TRUE,
      'access administration pages' => TRUE,
      'access content' => TRUE,
      'access toolbar' => TRUE,
      'create translation jobs' => TRUE,
      'osha tmgmt abort job item' => TRUE,
      'osha tmgmt accept job item translation' => TRUE,
      'osha tmgmt edit translation content validators' => TRUE,
      'osha tmgmt edit translation job item' => TRUE,
      'osha tmgmt manage content in translators group entity collections' => TRUE,
      'osha tmgmt preview layout validation' => TRUE,
      'osha tmgmt set job item to ready to publish state' => TRUE,
      'osha tmgmt set job item to require content validation state' => TRUE,
      'osha tmgmt set job item to translated state' => TRUE,
      'osha tmgmt upload translation file' => TRUE,
      'osha tmgmt validate layout translation' => TRUE,
      'osha tmgmt view translation content validators' => TRUE,
      'osha tmgmt view translation job' => TRUE,
      'osha tmgmt view translation job item' => TRUE,
      'submit translation jobs' => TRUE,
      'translate content' => TRUE,
      'use text format filtered_html' => TRUE,
      'use text format full_html' => TRUE,
      'view the administration theme' => TRUE,
    ),
  );

  return $roles;
}
