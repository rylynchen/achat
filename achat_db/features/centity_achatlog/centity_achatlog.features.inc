<?php
/**
 * @file
 * centity_achatlog.features.inc
 */

/**
 * Implements hook_default_centity_type().
 */
function centity_achatlog_default_centity_type() {
  $items = array();
  $items['achatlog'] = entity_import('centity_type', '{ "type" : "achatlog", "label" : "Achatlog", "rdf_mapping" : [] }');
  return $items;
}
