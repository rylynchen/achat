<?php
/**
 * @file
 * centity_achatlog.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function centity_achatlog_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'centity-achatlog-field_achat'
  $field_instances['centity-achatlog-field_achat'] = array(
    'bundle' => 'achatlog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achat',
    'label' => 'Achat',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_created'
  $field_instances['centity-achatlog-field_achatlog_created'] = array(
    'bundle' => 'achatlog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_created',
    'label' => '创建时间',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_file'
  $field_instances['centity-achatlog-field_achatlog_file'] = array(
    'bundle' => 'achatlog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_file',
    'label' => '文件',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'achatlog/file',
      'file_extensions' => 'jpg flv txt doc',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_receiver'
  $field_instances['centity-achatlog-field_achatlog_receiver'] = array(
    'bundle' => 'achatlog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_receiver',
    'label' => '接收者',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_secret'
  $field_instances['centity-achatlog-field_achatlog_secret'] = array(
    'bundle' => 'achatlog',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_secret',
    'label' => '密聊',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_sender'
  $field_instances['centity-achatlog-field_achatlog_sender'] = array(
    'bundle' => 'achatlog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_sender',
    'label' => '发送者',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_text'
  $field_instances['centity-achatlog-field_achatlog_text'] = array(
    'bundle' => 'achatlog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_text',
    'label' => '文本',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'centity-achatlog-field_achatlog_type'
  $field_instances['centity-achatlog-field_achatlog_type'] = array(
    'bundle' => 'achatlog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'centity',
    'field_name' => 'field_achatlog_type',
    'label' => '信息类型',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Achat');
  t('信息类型');
  t('创建时间');
  t('发送者');
  t('密聊');
  t('接收者');
  t('文件');
  t('文本');

  return $field_instances;
}
