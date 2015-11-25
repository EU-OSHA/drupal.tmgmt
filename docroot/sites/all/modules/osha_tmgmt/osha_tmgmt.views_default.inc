<?php
/**
 * @file
 * osha_tmgmt.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_tmgmt_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'osha_job_overview_job_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'tmgmt_job_item';
  $view->human_name = 'Osha Job Overview Job Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Osha Job Overview Job Items';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field-revision_id' => 'title_field-revision_id',
    'label' => 'label',
    'source_language' => 'source_language',
    'target_language' => 'target_language',
    'page_count' => 'page_count',
    'character_count' => 'character_count',
    'type' => 'type',
    'section' => 'section',
    'field_activity-revision_id' => 'field_activity-revision_id',
    'state' => 'state',
    'changed' => 'changed',
    'name' => 'name',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field-revision_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'target_language' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'page_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'character_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'section' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity-revision_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No job items found for your search.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node_revision']['id'] = 'job_item_to_node_revision';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node_revision']['field'] = 'job_item_to_node_revision';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'job_item_to_node_revision';
  /* Relationship: Translation Management Job Item: Content */
  $handler->display->display_options['relationships']['job_item_to_node']['id'] = 'job_item_to_node';
  $handler->display->display_options['relationships']['job_item_to_node']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['relationships']['job_item_to_node']['field'] = 'job_item_to_node';
  /* Field: Content (historical data): Title */
  $handler->display->display_options['fields']['title_field-revision_id']['id'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['table'] = 'field_revision_title_field';
  $handler->display->display_options['fields']['title_field-revision_id']['field'] = 'title_field-revision_id';
  $handler->display->display_options['fields']['title_field-revision_id']['relationship'] = 'job_item_to_node_revision';
  $handler->display->display_options['fields']['title_field-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field-revision_id']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field-revision_id']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Translation Management Job Item: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['empty'] = '[title_field-revision_id]';
  /* Field: Translation Management Job Item: Source language */
  $handler->display->display_options['fields']['source_language']['id'] = 'source_language';
  $handler->display->display_options['fields']['source_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['source_language']['field'] = 'source_language';
  /* Field: Translation Management Job Item: Job Item Target Language */
  $handler->display->display_options['fields']['target_language']['id'] = 'target_language';
  $handler->display->display_options['fields']['target_language']['table'] = 'views_entity_tmgmt_job_item';
  $handler->display->display_options['fields']['target_language']['field'] = 'target_language';
  $handler->display->display_options['fields']['target_language']['label'] = 'Target Language';
  $handler->display->display_options['fields']['target_language']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['target_language']['format_name'] = 1;
  /* Field: Translation Management Job Item: Page count */
  $handler->display->display_options['fields']['page_count']['id'] = 'page_count';
  $handler->display->display_options['fields']['page_count']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['page_count']['field'] = 'page_count';
  $handler->display->display_options['fields']['page_count']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['page_count']['precision'] = '2';
  $handler->display->display_options['fields']['page_count']['decimal'] = ',';
  $handler->display->display_options['fields']['page_count']['separator'] = '';
  /* Field: Translation Management Job Item: Character count */
  $handler->display->display_options['fields']['character_count']['id'] = 'character_count';
  $handler->display->display_options['fields']['character_count']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['character_count']['field'] = 'character_count';
  /* Field: Translation Management Job Item: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  /* Field: Translation Management Job Item: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Translation Management Job Item: Changed date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'osha_day_only';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Translation Management Job Item: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  /* Contextual filter: Translation Management Job Item: Tjid */
  $handler->display->display_options['arguments']['tjid']['id'] = 'tjid';
  $handler->display->display_options['arguments']['tjid']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['arguments']['tjid']['field'] = 'tjid';
  $handler->display->display_options['arguments']['tjid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tjid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tjid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['tjid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tjid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tjid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Translation Management Job Item: State */
  $handler->display->display_options['arguments']['state']['id'] = 'state';
  $handler->display->display_options['arguments']['state']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['arguments']['state']['field'] = 'state';
  $handler->display->display_options['arguments']['state']['exception']['value'] = 'any';
  $handler->display->display_options['arguments']['state']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['state']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['state']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['state']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['state']['specify_validation'] = TRUE;
  /* Contextual filter: Translation Management Job Item: Target language */
  $handler->display->display_options['arguments']['target_language']['id'] = 'target_language';
  $handler->display->display_options['arguments']['target_language']['table'] = 'tmgmt_job_item';
  $handler->display->display_options['arguments']['target_language']['field'] = 'target_language';
  $handler->display->display_options['arguments']['target_language']['exception']['value'] = 'any';
  $handler->display->display_options['arguments']['target_language']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['target_language']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['target_language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['target_language']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['target_language']['limit'] = '0';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'job_job_items');
  $handler->display->display_options['path'] = 'admin/tmgmt/job-items';
  $translatables['osha_job_overview_job_items'] = array(
    t('Master'),
    t('Osha Job Overview Job Items'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No results'),
    t('No job items found for your search.'),
    t('Content Revision'),
    t('revision user'),
    t('Content'),
    t('Title'),
    t('Label'),
    t('[title_field-revision_id]'),
    t('Source language'),
    t('Target Language'),
    t('Page count'),
    t(','),
    t('Character count'),
    t('Type'),
    t('State'),
    t('Changed date'),
    t('Name'),
    t('Operations'),
    t('All'),
    t('Page'),
  );
  $export['osha_job_overview_job_items'] = $view;

  $view = new view();
  $view->name = 'tmgmt_node_selection_view';
  $view->description = '';
  $view->tag = 'Workbench';
  $view->base_table = 'node';
  $view->human_name = 'Content selection';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content selection';
  $handler->display->display_options['css_class'] = 'tmgmt_node_selection_view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create translation jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100, 200';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'body' => 'body',
    'title_1' => 'title_1',
    'type' => 'type',
    'state' => 'state',
    'name' => 'name',
    'changed' => 'changed',
    'field_character_count' => 'field_character_count',
    'field_page_count' => 'field_page_count',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_character_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_page_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results. Please broaden your filters above.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['required'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::tmgmt_node_ui_tmgmt_nodes_add_items_to_cart' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Add to cart (full translation)',
    ),
    'rules_component::osha_tmgmt_add_items_to_cart_retranslate' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Add to cart (retranslation)',
    ),
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type of content';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Updated date';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'uid';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Author name';
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['sorts']['type']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['type']['expose']['label'] = 'Type';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type of content';
  $handler->display->display_options['filters']['type']['expose']['description'] = 'Use CTRL to select multiple items';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Free text';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_summary' => 'field_summary',
    'body' => 'body',
    'title_1' => 'title_1',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Node ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Entity translation: Translation exists */
  $handler->display->display_options['filters']['translation_exists']['id'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['translation_exists']['field'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['translation_exists']['operator'] = 'not in';
  $handler->display->display_options['filters']['translation_exists']['value'] = array(
    'bg' => 'bg',
    'cs' => 'cs',
    'da' => 'da',
    'de' => 'de',
    'el' => 'el',
    'es' => 'es',
    'et' => 'et',
    'fi' => 'fi',
    'hr' => 'hr',
    'fr' => 'fr',
    'hu' => 'hu',
    'is' => 'is',
    'it' => 'it',
    'lv' => 'lv',
    'lt' => 'lt',
    'nl' => 'nl',
    'mt' => 'mt',
    'no' => 'no',
    'pl' => 'pl',
    'pt' => 'pt',
    'ro' => 'ro',
    'ru' => 'ru',
    'sk' => 'sk',
    'sl' => 'sl',
    'sv' => 'sv',
    'tr' => 'tr',
  );
  $handler->display->display_options['filters']['translation_exists']['group'] = 1;
  $handler->display->display_options['filters']['translation_exists']['exposed'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['expose']['operator_id'] = 'translation_exists_op';
  $handler->display->display_options['filters']['translation_exists']['expose']['label'] = 'Not translated in';
  $handler->display->display_options['filters']['translation_exists']['expose']['description'] = 'Use CTRL to select multiple items';
  $handler->display->display_options['filters']['translation_exists']['expose']['operator'] = 'translation_exists_op';
  $handler->display->display_options['filters']['translation_exists']['expose']['identifier'] = 'translation_exists';
  $handler->display->display_options['filters']['translation_exists']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['translation_exists']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['translation_exists']['entity_type'] = 'node';
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['filters']['timestamp_1']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp_1']['operator'] = '>=';
  $handler->display->display_options['filters']['timestamp_1']['group'] = 1;
  $handler->display->display_options['filters']['timestamp_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp_1']['expose']['operator_id'] = 'timestamp_1_op';
  $handler->display->display_options['filters']['timestamp_1']['expose']['label'] = 'Updated after';
  $handler->display->display_options['filters']['timestamp_1']['expose']['operator'] = 'timestamp_1_op';
  $handler->display->display_options['filters']['timestamp_1']['expose']['identifier'] = 'from_date';
  /* Filter criterion: Content revision: Updated date */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = '<=';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Updated before';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'to_date';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Content selection */
  $handler = $view->new_display('page', 'Content selection', 'tmgmt_node_selection_view_page');
  $handler->display->display_options['path'] = 'admin/tmgmt/sources/osha';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Content (nodes)';
  $handler->display->display_options['menu']['weight'] = '-30';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['tmgmt_node_selection_view'] = array(
    t('Master'),
    t('Content selection'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('There are no results. Please broaden your filters above.'),
    t('author'),
    t('Translations'),
    t('- Choose an operation -'),
    t('Add to cart (full translation)'),
    t('Add to cart (retranslation)'),
    t('Title'),
    t('Type of content'),
    t('Author'),
    t('Updated'),
    t('Published'),
    t('Post date'),
    t('Updated date'),
    t('Author name'),
    t('Type'),
    t('Use CTRL to select multiple items'),
    t('Free text'),
    t('Node ID'),
    t('Not translated in'),
    t('Updated after'),
    t('Updated before'),
  );
  $export['tmgmt_node_selection_view'] = $view;

  return $export;
}
