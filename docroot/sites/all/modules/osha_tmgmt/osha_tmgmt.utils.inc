<?php

/**
 * Loads active job entities that have a job item with the identifiers.
 *
 * @param string $plugin
 *   The source plugin.
 * @param $item_type
 *   The source item type.
 * @param $item_id
 *   The source item id.
 * @param string $source_language
 *   The source language of the item.
 *
 * @return array
 *   An array of job entities.
 */
function _osha_tmgmt_job_item_load_latest($plugin, $item_type, $item_id, $source_language) {
  $query = db_select('tmgmt_job_item', 'tji');
  $query->innerJoin('tmgmt_job', 'tj', 'tj.tjid = tji.tjid');
//  $state_or = db_or()->condition('tji.state', TMGMT_JOB_ITEM_STATE_ACCEPTED, '<>')
//    ->condition(
//      db_and()->condition('tji.state', TMGMT_JOB_ITEM_STATE_ACCEPTED)
//        ->condition('tji.merged', NULL)
//    );
  $result = $query->condition('tj.source_language', $source_language)
    // Only query for jobs that are currently active.
    ->condition('tj.state', array(TMGMT_JOB_STATE_UNPROCESSED, TMGMT_JOB_STATE_ACTIVE))
    // And only query for job items that are not yet finished.
    ->condition('tji.state', TMGMT_JOB_ITEM_STATE_ACCEPTED, '<>')
    ->condition('tji.plugin', $plugin)
    ->condition('tji.item_type', $item_type)
    ->condition('tji.item_id', $item_id)
    ->fields('tji', array('tjiid'))
    ->fields('tj', array('target_language'))
    ->orderBy('tji.changed', 'DESC')
    ->groupBy('tji.tjiid')
    ->execute();
  if ($items = $result->fetchAllKeyed()) {
    $return = array();
    foreach (tmgmt_job_item_load_multiple(array_keys($items)) as $key => $item) {
      $return[$item->target_language] = $item;
    }
    return $return;
  }
  return FALSE;
}


/**
 * Returns the number of JobItems with a state for a Job
 * @param OshaTMGMTJob $job
 * @param $state
 *
 * @return int
 */
function _osha_tmgmt_job_statistic_items(OshaTMGMTJob $job, $state) {
  $statistics = _osha_tmgmt_job_statistics_items_load(array($job->tjid));
  if (!empty($statistics[$state][$job->tjid])) {
    return $statistics[$state][$job->tjid];
  }
  return 0;
}

/**
 * Returns the number of Job's Job Items for each state.
 * Keyed by state and tjid.
 * @param $tjids
 *
 * @return array
 */
function _osha_tmgmt_job_statistics_items_load($tjids) {
  $statistics = &drupal_static(__FUNCTION__, array());

  // First try to get the values from the cache.
  $return = array();
  $tjids_to_load = array();
  foreach ($tjids as $tjid) {
    if (isset($statistics[$tjid])) {
      // Info exists in cache, get it from there.
      $return[$tjid] = $statistics[$tjid];
    }
    else {
      // Info doesn't exist in cache, add job to the list that needs to be
      // fetched.
      $tjids_to_load[] = $tjid;
    }
  }

  // If there are remaining jobs, build a query to fetch them.
  if (!empty($tjids_to_load)) {
    // Build the query to fetch the statistics.
    $query = db_select('tmgmt_job_item', 'tji')
      ->fields('tji', array('tjid', 'state'));
    $query->addExpression('count(tjiid)', 'count');
    $result = $query->groupBy('tjid')
      ->groupBy('state')
      ->condition('tjid', $tjids_to_load)
      ->execute();
    $stats = $result->fetchAll();
    // Key by [state][tjid].
    foreach ($stats as $row) {
      $return[$row->state][$row->tjid] = $row->count;
    }
  }
  return $return;
}

function _osha_tmgmt_get_job_item_states() {
  return array(
    TMGMT_JOB_ITEM_STATE_ACTIVE => t('On Translation'),
    TMGMT_JOB_ITEM_STATE_REVIEW => t('Translated'), // was: Layout Validated
    OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidationRequired => t('Content Validation Required'),
    TMGMT_JOB_ITEM_STATE_ABORTED => t('Translation Rejected'),
    OSHA_TMGMT_JOB_ITEM_STATE_TranslationValidated => t('Translation Validated'),
//    OSHA_TMGMT_JOB_ITEM_STATE_TranslatedReadyToPublish => t('Translated Ready to Publish'),
    TMGMT_JOB_ITEM_STATE_ACCEPTED => t('Ready to Publish'),
//    TMGMT_JOB_ITEM_STATE_ACCEPTED => t('Published'),
  );
}

/**
 * Get language list.
 */
function osha_tmgmt_language_list() {
  $languages = language_list();
  drupal_alter('osha_tmgmt_language_list', $languages);
  return $languages;
}


/**
 * Get language list as options.
 */
function osha_tmgmt_language_list_as_options() {
  $languages = osha_tmgmt_language_list();
  unset($languages[language_default('language')]);
  drupal_alter('osha_tmgmt_language_list', $languages);
  $options = array();
  foreach ($languages as $lang_code => $language) {
    $options[$lang_code] = $language->name;
  }
  return $options;
}

/**
 * Retrieve the list of target translation languages.
 *
 * @param array $filter
 *   Additional filter containing languages code (i.e. fr, de)
 * @return array
 *   Array with language names as values and codes as keys.
 */
function osha_tmgmt_get_translation_languages_options($filter = array()) {
  $languages = tmgmt_available_languages();
  $languages = array_intersect_key($languages, osha_tmgmt_language_list_as_options());
  return array_diff($languages, $filter);
}

/**
 * Returns osha state label of a job item state.
 */
function _osha_tmgmt_get_job_item_state_label($state) {
  $states = _osha_tmgmt_get_job_item_states();
  return $states[$state];
}

function _osha_tmgmt_mark_job_item_retranslation($entity, &$job_item) {
  $messages = array();
  $valid_languages = array();
  $invalid_languages = array();
  OshaTMGMTRetranslate::validate_can_retranslate($entity, $messages, $valid_languages, $invalid_languages);
  if (!empty($valid_languages)) {
    // make an update here instead of overwrite/rewrite addJobItem in tmgmt_ui.cart.inc
    $job_item->is_full_translation = 0;
    $job_item->source_language = $entity->language;
    $job_item->target_language = $valid_languages[0];
  } else {
    // retranslation is impossible
    foreach ($messages as $severity => $message_list) {
      foreach ($message_list as $message) {
        drupal_set_message($message, $severity);
      }
    }
  }
}

function _osha_tmgmt_form_alter_add_source_target_info(&$form, $form_state) {
  if (isset($form_state['item'])) {
    $job = $form_state['item'];
    $form['info']['source'] = array(
      '#type' => 'item',
      '#prefix' => '<div class="tmgmt-ui-source-type tmgmt-ui-info-item">',
      '#suffix' => '</div>',
      '#title' => t('Source language'),
      '#markup' => locale_language_name($job->source_language),
      '#weight' => 9,
    );
    $form['info']['target'] = array(
      '#type' => 'item',
      '#prefix' => '<div class="tmgmt-ui-source-type tmgmt-ui-info-item">',
      '#suffix' => '</div>',
      '#title' => t('Target language'),
      '#markup' => locale_language_name($job->target_language),
      '#weight' => 10,
    );
  }
}

function _osha_tmgmt_disabled_language_list() {
  return variable_get('osha_tmgmt_disabled_languages', array());
}

/**
 * Show job priority as translatable string.
 *
 * @param object $job
 *   Job
 *
 * @return string
 *   Job priority in current language
 */
function _osha_tmgmt_job_priority_name($job) {
  if (isset($job->priority)) {
    switch ($job->priority) {
      case OSHA_TMGMT_JOB_PRIORITY_HIGH:
        return t('High');

      case OSHA_TMGMT_JOB_PRIORITY_LOW:
        return t('Low');

      default:
        return t('Normal');
    }
  }
  return '';
}

/**
 * Add english version to a specified lang.
 */
function _osha_tmgmt_create_english_translations($language, $node) {
  // This function is similar to osha_lingua_tools_create_translations, but copies all fields
  $source_lang = $node->translations->original;
  // Must update translation handler because of multiple subsequent calls to entity_translation_get_handler
  // otherwise the 2nd+ translations are not created
  $translation_handler = entity_translation_get_handler('node', $node, TRUE);
  $type = $node->type;
  $fields = _osha_tmgmt_translatable_field_instances($type);
  $translation_handler->setTranslation(
    array(
      'translate' => 0,
      'status' => 1,
      'uid' => 1,
      'language' => $language,
      'source' => $source_lang,
    )
  );
  $translation_handler->saveTranslations();

  $new_node = new stdClass();
  $new_node->id = $node->nid;
  $new_node->nid = $node->nid;
  $new_node->vid = $node->vid;
  $new_node->type = $type;
  $new_node->bundle = $type;
  $new_node->translations = $node->translations;
  foreach ($fields as $field) {
    if (!isset($node->{$field['field_name']}[$source_lang])) {
      continue;
    }
    $field_name = $field['field_name'];
    $field_info = field_info_field($field_name);
    if ( $field_info['type'] == 'file' || $field_info['type'] == 'image' ) {
      if ($field_info['cardinality'] == 1) {
        // don't clone fields with cardinality 1
        continue;
      } else {
        // Set for all existing languages also, otherwise it is removed by file_field_update
        // see https://www.drupal.org/node/1483736 and https://jira.osha.europa.eu/browse/MDR-767
        $new_node->{$field_name} = $node->{$field_name};
      }
    }
    $new_node->{$field_name}[$language] = $node->{$field_name}[$source_lang];
  }
  field_attach_update('node', $new_node);

  // clone url_aliases
  $args = array(
    'source' => 'node/' . $node->nid,
    'alias' => $node->path['alias'],
    'language' => $language,
  );
  path_save($args);
  entity_get_controller('node')->resetCache(array($node->nid));
}

/**
 * Helper function to get translatable fields of a node type.
 *
 * @param $bundle
 *  The type of the node to call field_info_instances().
 * @return array
 *  Array of fields.
 */
function _osha_tmgmt_translatable_field_instances($bundle) {
  $translatable_fields = array();
  $fields = field_info_instances('node', $bundle);
  foreach ($fields as $field) {
    if (istranslatable($field['field_id'])) {
      $translatable_fields[] = $field;
    }
  }
  return $translatable_fields;
}

/**
 * Check if there's an active job for this node in the same target language.
 *
 * @param int $nid
 *   Node NID
 * @param string $target_language
 *   Target language
 * @param string $bundle
 *   Item bundle
 *
 * @return bool
 *   Returns TRUE if there's another job in progress
 */
function _osha_tmgmt_is_duplicate_job_item($nid, $target_language, $bundle) {
  $r = db_query(
    "SELECT count(*) FROM {tmgmt_job_item} a
      INNER JOIN {tmgmt_job} b ON a.tjid = b.tjid
      WHERE (b.state = :s1 OR b.state = :s1)
        AND a.target_language = :target_language
        AND a.item_type = :bundle
        AND a.item_id = :nid",
    array(
      ':s1' => TMGMT_JOB_STATE_ACTIVE,
      ':s2' => TMGMT_JOB_STATE_UNPROCESSED,
      ':bundle' => $bundle,
      ':target_language' => $target_language,
      ':nid' => $nid,
    ))->fetchCol(0);
  return $r[0] > 0;
}

function _osha_tmgmt_get_roles_by_perm($perm) {
  $query = db_select('role_permission', 'rp');
  $alias = $query->innerJoin('role', 'r', 'rp.rid=r.rid');
  $roles = $query->fields('r', array('rid', 'name'))
    ->condition('permission', $perm)
    ->execute()
    ->fetchAllKeyed();
  return $roles;
}

function _osha_tmgmt_get_users_by_perm($perm) {
  $users = array();
  $roles = _osha_tmgmt_get_roles_by_perm($perm);
  if (!empty($roles)) {
    foreach ($roles as $role) {
      $users = array_merge($users, _osha_tmgmt_users_get_users_from_role($role));
    }
  }
  return $users;
}

function _osha_tmgmt_user_has_role($role, $user = NULL) {
  if (empty($user)) {
    global $user;
  }
  if (isset($user->roles)) {
    return in_array($role, $user->roles);
  }
  return FALSE;
}

/**
 * Retrieve the list of users from a role, ordered by name.
 *
 * @param string $role_name
 *   Name of the Role
 *
 * @return array
 *   Array of user objects
 */
function _osha_tmgmt_users_get_users_from_role($role_name) {
  $ret = array();
  if ($role = user_role_load_by_name($role_name)) {
    $query = db_select('users', 'u')->fields('u', array('uid'));
    $query->join('users_roles', 'ur', 'ur.uid = u.uid');
    $uids = $query->condition('ur.rid', $role->rid)
      ->orderBy('u.name')
      ->groupBy('u.uid')
      ->execute()->fetchCol();
    $ret = user_load_multiple($uids);
  }
  return $ret;
}

/**
 * Get un-merged accepted job items for a revision.
 * @param $vid
 * @param null $language
 * @return array
 */
/*function _osha_tmgmt_get_job_items_by_vid($vid, $language = NULL) {
  $tjiids = db_select('tmgmt_job_item', 'tji')
    ->fields('tji', array('tjiid', 'tjiid'))
    ->condition('vid', $vid)
    ->condition('state', TMGMT_JOB_ITEM_STATE_ACCEPTED)
    ->condition('merged', NULL);
  if (!empty($language)) {
    $tjiids->condition('target_language', $language);
  }
  $tjiids = $tjiids->execute()
    ->fetchAllKeyed();
  $job_items = array();
  if (!empty($tjiids)) {
    $job_items = tmgmt_job_item_load_multiple($tjiids);
  }
  return $job_items;
}*/

/**
 * Loads latest job created.
 */
function _osha_tmgmt_get_cart_job_item_id($entity_type, $entity_id) {
  $query = db_select('tmgmt_job_item', 'tji')
    ->fields('tji', array('tjiid'))
    ->condition('tjid', 0)
    ->condition('item_type', $entity_type)
    ->condition('item_id', $entity_id)
    ->orderBy('tjiid', 'DESC')
    ->range(0,1);
  $result = $query->execute()->fetchField(0);
  return $result;
}

/**
 * Check incoming string if requires translation and add to locale source.
 *
 * @param string $string
 *   Translated or untranslated string
 *
 * @return string
 *   Returns the $string if translation or its translation
 */
function _osha_tmgmt_literal_get_translation($string) {
  if (empty($string)) {
    return $string;
  }
  global $language;
  $decoded_string = decode_entities($string);
  $q = db_query('SELECT lid FROM {locales_target} t WHERE translation=:string and language = :language',
    array(':string' => $decoded_string, ':language' => $language->language));
  if ($q->fetchField()) {
    return $string;
  }
  else {
    return t($string); // Applies only to english untranslated strings
  }
}

function osha_tmgmt_et_taxonomy_enabled() {
  $enabled_types = array_filter(variable_get('entity_translation_entity_types', array()));
  return !empty($enabled_types['taxonomy_term']);
}