<?php

/**
 * Implements hook_views_data()
 */
function achat_db_views_data_alter(&$data) {
  $data['centity']['achat_db_export_log'] = array(
    'field' => array(
      'title' => t('Exprt Log'),
      'help' => t('Provide a link to export log.'),
      'handler' => 'achat_db_handler_achat_db_export_log_field',
    ),
  );
}