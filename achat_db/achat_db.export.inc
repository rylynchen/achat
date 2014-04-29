<?php

/**
 * Export achat log.
 *
 * @param $centity
 */
function achat_db_ajax_export_callback($centity) {
  module_load_include('inc', 'phpexcel');
  $data = array($centity->cid => array());
  $headers = array($centity->cid => array(t('发送人'), t('时间'), t('接收人'), t('内容')));

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'centity')
    ->entityCondition('bundle', 'achatlog')
    ->fieldCondition('field_achat', 'target_id', $centity->cid)
    ->fieldOrderBy('field_achatlog_created', 'value', 'ASC');
  $result = $query->execute();
  if (isset($result['centity'])) {
    $cids = array_keys($result['centity']);
    $centities = centity_load_multiple($cids);
    foreach ($centities as $log) {
      $wrapper = entity_metadata_wrapper('centity', $log);
      $accepters = array();
      foreach($wrapper->field_achatlog_receiver->value() as $account) {
        $accepters[] = $account->name;
      }
      switch ($wrapper->field_achatlog_type->value()) {
        case 'text':
          $content = $wrapper->field_achatlog_text->value();
          break;
        case 'image':
        case 'video':
        case 'doc':
          $file = (object) $wrapper->field_achatlog_file->value();
          $content = file_create_url($file->uri);
          break;
        default:
          $content = $wrapper->field_achatlog_text->value();
          break;
      }
      $data[$centity->cid][] = array(
        $wrapper->field_achatlog_sender->name->value(),
        date('Y-m-d H:i:s', $wrapper->field_achatlog_created->value()),
        implode(",", $accepters),
        $content,
      );
    }
  }

  $dir = file_stream_wrapper_get_instance_by_uri('public://')->realpath();
  $filename = date('Y-m-d-H-i-s') . '.xls';
  $path = "$dir/$filename";
  $options = array('format' => 'xls');
  if (phpexcel_export($headers, $data, $path, $options)) {
    $file = new stdClass();
    $file->uri = "public://$filename";
    $file = file_save($file);
    file_transfer($file->uri, array(
      'Content-type' => 'application/vnd.ms-excel; charset=ISO-8859-1',
      'Content-Disposition' => 'attachment; filename="FilteredStructures.xls"',
      'Cache-Control' => 'max-age=0',
    ));
  }
}