<?php
/**
 * @file
 * centity_achat.features.inc
 */

/**
 * Implements hook_default_centity_type().
 */
function centity_achat_default_centity_type() {
  $items = array();
  $items['achat'] = entity_import('centity_type', '{ "type" : "achat", "label" : "Achat", "rdf_mapping" : [] }');
  return $items;
}
