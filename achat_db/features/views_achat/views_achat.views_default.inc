<?php
/**
 * @file
 * views_achat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_achat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'achat';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'centity';
  $view->human_name = 'achat';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Achat';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer achat db';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_achat_allow_users_target_id']['id'] = 'field_achat_allow_users_target_id';
  $handler->display->display_options['relationships']['field_achat_allow_users_target_id']['table'] = 'field_data_field_achat_allow_users';
  $handler->display->display_options['relationships']['field_achat_allow_users_target_id']['field'] = 'field_achat_allow_users_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_achat_enter_users_target_id']['id'] = 'field_achat_enter_users_target_id';
  $handler->display->display_options['relationships']['field_achat_enter_users_target_id']['table'] = 'field_data_field_achat_enter_users';
  $handler->display->display_options['relationships']['field_achat_enter_users_target_id']['field'] = 'field_achat_enter_users_target_id';
  /* Field: Centity: Centity ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'centity';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = 'ID';
  $handler->display->display_options['fields']['cid']['element_type'] = '0';
  $handler->display->display_options['fields']['cid']['element_default_classes'] = FALSE;
  /* Field: Centity: 状态 */
  $handler->display->display_options['fields']['field_achat_status']['id'] = 'field_achat_status';
  $handler->display->display_options['fields']['field_achat_status']['table'] = 'field_data_field_achat_status';
  $handler->display->display_options['fields']['field_achat_status']['field'] = 'field_achat_status';
  $handler->display->display_options['fields']['field_achat_status']['element_type'] = '0';
  $handler->display->display_options['fields']['field_achat_status']['element_default_classes'] = FALSE;
  /* Field: Centity: 限制用户 */
  $handler->display->display_options['fields']['field_achat_limit']['id'] = 'field_achat_limit';
  $handler->display->display_options['fields']['field_achat_limit']['table'] = 'field_data_field_achat_limit';
  $handler->display->display_options['fields']['field_achat_limit']['field'] = 'field_achat_limit';
  $handler->display->display_options['fields']['field_achat_limit']['element_type'] = '0';
  $handler->display->display_options['fields']['field_achat_limit']['element_default_classes'] = FALSE;
  /* Field: Centity: 允许进入用户 */
  $handler->display->display_options['fields']['field_achat_allow_users']['id'] = 'field_achat_allow_users';
  $handler->display->display_options['fields']['field_achat_allow_users']['table'] = 'field_data_field_achat_allow_users';
  $handler->display->display_options['fields']['field_achat_allow_users']['field'] = 'field_achat_allow_users';
  $handler->display->display_options['fields']['field_achat_allow_users']['element_type'] = '0';
  $handler->display->display_options['fields']['field_achat_allow_users']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_achat_allow_users']['empty'] = '-';
  $handler->display->display_options['fields']['field_achat_allow_users']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_achat_allow_users']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_achat_allow_users']['multi_type'] = 'ul';
  /* Field: Centity: 进入用户 */
  $handler->display->display_options['fields']['field_achat_enter_users']['id'] = 'field_achat_enter_users';
  $handler->display->display_options['fields']['field_achat_enter_users']['table'] = 'field_data_field_achat_enter_users';
  $handler->display->display_options['fields']['field_achat_enter_users']['field'] = 'field_achat_enter_users';
  $handler->display->display_options['fields']['field_achat_enter_users']['element_type'] = '0';
  $handler->display->display_options['fields']['field_achat_enter_users']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_achat_enter_users']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_achat_enter_users']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_achat_enter_users']['multi_type'] = 'ul';
  /* Field: Centity: 创建时间 */
  $handler->display->display_options['fields']['field_achat_created']['id'] = 'field_achat_created';
  $handler->display->display_options['fields']['field_achat_created']['table'] = 'field_data_field_achat_created';
  $handler->display->display_options['fields']['field_achat_created']['field'] = 'field_achat_created';
  $handler->display->display_options['fields']['field_achat_created']['element_type'] = '0';
  $handler->display->display_options['fields']['field_achat_created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_achat_created']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Centity: Exprt Log */
  $handler->display->display_options['fields']['achat_db_export_log']['id'] = 'achat_db_export_log';
  $handler->display->display_options['fields']['achat_db_export_log']['table'] = 'centity';
  $handler->display->display_options['fields']['achat_db_export_log']['field'] = 'achat_db_export_log';
  $handler->display->display_options['fields']['achat_db_export_log']['label'] = '操作';
  $handler->display->display_options['fields']['achat_db_export_log']['text'] = '导出聊天记录';
  /* Sort criterion: Centity: Centity ID */
  $handler->display->display_options['sorts']['cid']['id'] = 'cid';
  $handler->display->display_options['sorts']['cid']['table'] = 'centity';
  $handler->display->display_options['sorts']['cid']['field'] = 'cid';
  $handler->display->display_options['sorts']['cid']['order'] = 'DESC';
  /* Filter criterion: Centity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'centity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'achat' => 'achat',
  );
  /* Filter criterion: Centity: Centity ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'centity';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Centity: 状态 (field_achat_status) */
  $handler->display->display_options['filters']['field_achat_status_value']['id'] = 'field_achat_status_value';
  $handler->display->display_options['filters']['field_achat_status_value']['table'] = 'field_data_field_achat_status';
  $handler->display->display_options['filters']['field_achat_status_value']['field'] = 'field_achat_status_value';
  $handler->display->display_options['filters']['field_achat_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_achat_status_value']['expose']['operator_id'] = 'field_achat_status_value_op';
  $handler->display->display_options['filters']['field_achat_status_value']['expose']['label'] = '状态';
  $handler->display->display_options['filters']['field_achat_status_value']['expose']['operator'] = 'field_achat_status_value_op';
  $handler->display->display_options['filters']['field_achat_status_value']['expose']['identifier'] = 'field_achat_status_value';
  $handler->display->display_options['filters']['field_achat_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Centity: 限制用户 (field_achat_limit) */
  $handler->display->display_options['filters']['field_achat_limit_value']['id'] = 'field_achat_limit_value';
  $handler->display->display_options['filters']['field_achat_limit_value']['table'] = 'field_data_field_achat_limit';
  $handler->display->display_options['filters']['field_achat_limit_value']['field'] = 'field_achat_limit_value';
  $handler->display->display_options['filters']['field_achat_limit_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_achat_limit_value']['expose']['operator_id'] = 'field_achat_limit_value_op';
  $handler->display->display_options['filters']['field_achat_limit_value']['expose']['label'] = '限制用户';
  $handler->display->display_options['filters']['field_achat_limit_value']['expose']['operator'] = 'field_achat_limit_value_op';
  $handler->display->display_options['filters']['field_achat_limit_value']['expose']['identifier'] = 'field_achat_limit_value';
  $handler->display->display_options['filters']['field_achat_limit_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/achat';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Achat';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Achat';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['achat'] = array(
    t('Master'),
    t('Achat'),
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
    t('User entity referenced from field_achat_allow_users'),
    t('User entity referenced from field_achat_enter_users'),
    t('ID'),
    t('状态'),
    t('限制用户'),
    t('允许进入用户'),
    t('-'),
    t('进入用户'),
    t('创建时间'),
    t('操作'),
    t('导出聊天记录'),
    t('Page'),
  );
  $export['achat'] = $view;

  return $export;
}
