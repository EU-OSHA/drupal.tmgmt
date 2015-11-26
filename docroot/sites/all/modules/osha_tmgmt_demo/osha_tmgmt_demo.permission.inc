<?php

function osha_tmgmt_demo_translation_manager_permission() {
  return array(
    'view translation job',
    'access administration pages',
    'view the administration theme',
    'access toolbar',
    'osha tmgmt upload translation file',
    'preview layout validation',
    'validate layout translation',
    'view translation job item',
    'edit translation job item',
    'view translation content validators',
    'edit translation content validators',
    'set job item to translated state',
    'set job item to require content validation state',
    'set job item to ready to publish state',
    'set job item to ready to publish state',
    'abort job item',
    'accept job item translation',
    'manage content in translators group entity collections',
    'access content',
  );
}

function osha_tmgmt_demo_translation_liaison_permission() {
  return array(
    'view translation job',
    'access administration pages',
    'view the administration theme',
    'access toolbar',
    'access content',
    'view on translation content list',
  );
}

function osha_tmgmt_demo_layout_validator_permission() {
  return array(
    'view translation job',
    'access administration pages',
    'view the administration theme',
    'access toolbar',
    'osha tmgmt upload translation file',
    'preview layout validation',
    'validate layout translation',
    'view translation job item',
    'set job item to translated state',
    'access content',
    'abort job item',
    'view on translation content list',
    'view translation job',
    'translate user-defined strings',
    'translate admin strings',
  );
}

function osha_tmgmt_demo_content_validator_permission() {
  return array(
    'view translation job',
    'access administration pages',
    'view the administration theme',
    'access toolbar',
    'access content',
    'view on translation content list',
    'view translation content validators',
    'can be a content validator',
    'view translation job item',
  );
}