<?php

class OshaTMGMTStatistics {

  /**
   * Compute statistics such as character/page count for a job item.
   *
   * @param TMGMTJobItem $job_item
   *   Attach statistical information to the job item
   */
  public static function computeJobItemStatistics(&$job_item) {
    $job_item->character_count = 0;
    $job_item->page_count = 0;
    // When job items is still in cart, getData() returns nothing, so we simulate character count
    $data = $job_item->getSourceData();
    if (empty($data)) {
      if ($job_item->item_type == "node" || $job_item->item_type == "taxonomy_term") {
        $entity = entity_load_single($job_item->item_type, $job_item->item_id);
        if (!$entity) {
          throw new TMGMTException(t('Unable to load entity %type with id %id', array('%type' => $job_item->item_type, '%id' => $job_item->item_id)));
        }
        if ($job_item->item_type == "node") {
          if (function_exists('workbench_moderation_node_current_load')) {
            $entity = workbench_moderation_node_current_load($entity);
          }
        }
        self::computeEntityStatistics($entity, $job_item->item_type);
        $job_item->character_count = $entity->character_count;
        $job_item->page_count = $entity->page_count;
      }
    } else {
      // Call default behaviour
      self::count($data, $ret);
      $job_item->character_count = $ret;
      if ($job_item->character_count > 0) {
        $cpp = variable_get('osha_tmgmt_characters_per_page', 1500);
        $job_item->page_count = $job_item->character_count / $cpp;
      }
    }
  }

  /**
   * Compute characters/page count for node/taxonomy_term entity types.
   *
   * @param object $node
   *   Object to compute data for. Will return with fields character_count and
   *   page_count set.
   * @param string $entity_type
   *   Type of entity, e.g. 'node', 'taxonomy_term'
   */
  public static function computeEntityStatistics(&$node, $entity_type) {
    $node->character_count = 0;
    $node->page_count = 0;

    $language = entity_language($entity_type, $node);
    $data = tmgmt_field_get_source_data($entity_type, $node, $language, TRUE);
    self::count($data, $ret);
    $node->character_count = $ret;
    if ($node->character_count > 0) {
      $cpp = variable_get('osha_tmgmt_characters_per_page', 1500);
      $node->page_count = $node->character_count / $cpp;
    }
  }

  /**
   * Compute statistics such as character/page count for a job.
   *
   * @param TMGMTJob $job
   *   Attach statistical information to the job
   */
  public static function computeJobStatistics(&$job) {
    $job->character_count = 0;
    $job->page_count = 0;
    $items = $job->getItems();
    /* @var TMGMTJobItem $item */
    foreach ($items as $item) {
      if (empty($item->character_count)) {
        self::computeJobItemStatistics($item);
      }
    }
    // Create array with unique items (count only once if has more target languages)
    $unique_items = array();
    foreach ($job->getItems() as $item) {
      if (!isset($unique_items[$item->item_type][$item->item_id])) {
        $unique_items[$item->item_type][$item->item_id] = $item;
      }
    }
    foreach ($unique_items as $item_type => $item_id_array) {
      foreach ($item_id_array as $item_id => $item) {
        if ($item->character_count > 0) {
          $job->character_count += $item->character_count;
        }
      }
    }
    // Will have correct numbers only if job is consistent (same content x all languages).

    if ($job->character_count > 0) {
      $cpp = variable_get('osha_tmgmt_characters_per_page', 1500);
      $job->page_count = $job->character_count / $cpp;
    }
  }

  /**
   * Recursively count the length of inner #text keys of this data array.
   *
   * The HTML tags are ignored.
   * The Whitespaces/tabs/newlines are ignored.
   * The &nbsp; are ignored.
   *
   * @param array $item
   *   Array with field data - prepared by tmgmt.
   * @param int $count
   *   Number of characters from all structures (ie. fields)
   */
  public static function count($item, &$count) {
    if (!empty($item['#text'])) {
      if (_tmgmt_filter_data($item)) {
        // Before stripping tags, get the count of title/alt attributes.
        if($doc = OshaTMGMTRetranslate::getDOMDocument($item['#text'])) {
          $selectors = array(
            'title' => "//*[@title]", 'alt' => "//img[@alt]"
          );
          $sxml = simplexml_import_dom($doc);
          foreach ($selectors as $attribute => $expr) {
            $tags = $sxml->xpath($expr);
            foreach ($tags as $tag) {
              $attributes = $tag->attributes();
              $value = $attributes[$attribute];
              $count += mb_strlen((string) $value, 'utf-8');
            }
          }
        }
        $text = strip_tags(html_entity_decode($item['#text']));
        // C2A0 is unicode nbsp.
        $text = preg_replace("/\x{00A0}|&nbsp;|\s/", '', $text);
        $count += mb_strlen($text, 'utf-8');
      }
    }
    elseif (is_array($item)) {
      foreach (element_children($item) as $key) {
        if (is_string($key) && $key == "node_title") {
          continue;
        }
        self::count($item[$key], $count);
      }
    }
  }

  /**
   * Returns the job target languages.
   *
   * @param TMGMTJob $job
   *   The job.
   *
   * @return array
   *   Array of language codes
   */
  public static function getJobTargetLanguages(TMGMTJob $job) {
    $target_languages = array();
    foreach ($job->getItems() as $item) {
      $target_languages[] = $item->target_language;
    }

    return array_unique($target_languages);
  }
}
