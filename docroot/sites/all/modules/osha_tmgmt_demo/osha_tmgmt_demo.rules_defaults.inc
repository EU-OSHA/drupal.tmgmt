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
  $items['rules_osha_tmgmt_demo_trans_no_cv_action'] = entity_import('rules_config', '{ "osha_tmgmt_demo_osha_tmgmt_demo_trans_no_cv_action" : {
      "LABEL" : "Translation doesn\\u0027t need CV action",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "osha_tmgmt" ],
      "ON" : { "osha_tmgmt_no_need_cv_approval" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "OSHA TMGMT Demo: No action required",
            "message" : "The job item doesn\\u0027t needs your attention anymore: [tmgmt-job-item:url] ",
            "language" : [ "user:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_osha_tmgmt_demo_translation_cv_action'] = entity_import('rules_config', '{ "osha_tmgmt_demo_osha_tmgmt_demo_translation_cv_action" : {
      "LABEL" : "Translation needs content validator action",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "osha_tmgmt" ],
      "ON" : { "osha_tmgmt_needs_cv_approval" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : "OSHA TMGMT Demo: New content translated",
            "message" : "New content was translated and requires your attention: [tmgmt-job-item:url]",
            "language" : [ "user:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_osha_tmgmt_demo_job_item_re_enabled'] = entity_import('rules_config', '{ "rules_osha_tmgmt_demo_job_item_re_enabled" : {
      "LABEL" : "Translation job item re-enabled",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "tmgmt" ],
      "ON" : { "tmgmt_job_item_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "tmgmt-job-item-unchanged:state" ], "value" : "4" } },
        { "data_is" : { "data" : [ "tmgmt-job-item:state" ], "value" : "1" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "6" : "6" } },
            "subject" : "OSHA TMGMT Demo: A translation has been re-enabled",
            "message" : "A translation job item was re-enabled: [tmgmt-job-item:url]"
          }
        }
      ]
    }
  }');
  $items['rules_osha_tmgmt_demo_job_item_translated'] = entity_import('rules_config', '{ "rules_osha_tmgmt_demo_job_item_translated" : {
      "LABEL" : "Job item set to Translated",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "tmgmt" ],
      "ON" : { "tmgmt_job_item_update" : [] },
      "IF" : [
        { "NOT data_is" : { "data" : [ "tmgmt-job-item-unchanged:state" ], "value" : "2" } },
        { "data_is" : { "data" : [ "tmgmt-job-item:state" ], "value" : "2" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "7" : "7" } },
            "subject" : "OSHA TMGMT Demo: New content translated",
            "message" : "New content was translated and requires your attention: [tmgmt-job-item:url]"
          }
        }
      ]
    }
  }');
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
            "roles" : { "value" : { "7" : "7" } },
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
            "roles" : { "value" : { "6" : "6" } },
            "subject" : "OSHA TMGMT Demo: New translation job",
            "message" : "New translation job available: [tmgmt-job:label] [tmgmt-job:url]"
          }
        }
      ]
    }
  }');
  $items['rules_osha_tmgmt_demo_translation_rejected'] = entity_import('rules_config', '{ "rules_osha_tmgmt_demo_translation_rejected" : {
      "LABEL" : "Translation rejected",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "tmgmt" ],
      "ON" : { "tmgmt_job_item_update" : [] },
      "IF" : [
        { "NOT data_is" : { "data" : [ "tmgmt-job-item-unchanged:state" ], "value" : "4" } },
        { "data_is" : { "data" : [ "tmgmt-job-item:state" ], "value" : "4" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "6" : "6" } },
            "subject" : "OSHA TMGMT Demo: A translation has been rejected",
            "message" : "A translation job item was rejected: [tmgmt-job-item:url]"
          }
        }
      ]
    }
  }');
  $items['rules_osha_tmgmt_demo_translation_validated'] = entity_import('rules_config', '{ "rules_osha_tmgmt_demo_translation_validated" : {
      "LABEL" : "Translation validated",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OSHA TMGMT DEMO" ],
      "REQUIRES" : [ "rules", "tmgmt" ],
      "ON" : { "tmgmt_job_item_update" : [] },
      "IF" : [
        { "NOT data_is" : { "data" : [ "tmgmt-job-item-unchanged:state" ], "value" : "6" } },
        { "data_is" : { "data" : [ "tmgmt-job-item:state" ], "value" : "6" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "7" : "7" } },
            "subject" : "OSHA TMGMT Demo: New translation validated",
            "message" : "New translation job item was validated: [tmgmt-job-item:url]"
          }
        }
      ]
    }
  }');
  return $items;
}
