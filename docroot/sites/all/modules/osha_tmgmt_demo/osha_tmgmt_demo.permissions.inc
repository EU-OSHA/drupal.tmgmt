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
    'demo_lv1' => array(
      'name' => 'demo_lv1',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($lv->rid => 'layout validator')
    ),
    'demo_lv2' => array(
      'name' => 'demo_lv2',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($lv->rid => 'layout validator')
    ),
    'demo_lv3' => array(
      'name' => 'demo_lv3',
      'pass' => 'demo',
      'status' => 1,
      'roles' => array($lv->rid => 'layout validator')
    ),
  );
}

