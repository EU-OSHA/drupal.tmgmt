<?php
/**
 * @file
 * osha_tmgmt_demo.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function osha_tmgmt_demo_default_rules_configuration() {
  $items = array();
  $items['rules_osha_tmgmt_demo_new_content_translatable'] = entity_import('rules_config', '{ "rules_osha_tmgmt_demo_new_content_translatable" : {
      "LABEL" : "New content translatable",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "title_field" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "OSHA TMGMT Demo: New content can be translated",
            "message" : "New content can be translated: [node:title] [node:url]"
          }
        }
      ]
    }
  }');
  $items['rules_osha_tmgmt_demo_new_translation_job'] = entity_import('rules_config', '{ "rules_osha_tmgmt_demo_new_translation_job" : {
      "LABEL" : "New translation job",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "tmgmt" ],
      "ON" : { "tmgmt_job_insert" : [] },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "OSHA TMGMT Demo: New translation job",
            "message" : "New translation job available: [tmgmt-job:label] [tmgmt-job:url]"
          }
        }
      ]
    }
  }');
  return $items;
}
