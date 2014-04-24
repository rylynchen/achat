<?php

/**
 * Form builder; Configure he username settings for this site.
 */
function achat_settings_form($form, &$form_state) {
	$settings = $form_state['settings'] = achat_settings();
	$default_num = isset($settings['blocks']) ? count($settings['blocks']) : 1;
  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Blocks'),
    '#prefix' => '<div id="fieldset_wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );
  $form_state['num'] = isset($form_state['num']) ? $form_state['num'] : $default_num;
  $real_num = isset($form_state['storage']['remove_ids']) ? $form_state['num'] - count($form_state['storage']['remove_ids']) : $form_state['num'];
  
  $form['fieldset']['block'] = array(
    '#prefix' => '<div id="fieldset_blocks_wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
  );
  for ($i = 0; $i < $form_state['num']; $i++) {
    // pass the remove item
    if (isset($form_state['storage']['remove_ids']) && in_array($i, $form_state['storage']['remove_ids'])) {
      continue;
    }
  	$form['fieldset']['block'][$i] = array(
	    '#prefix' => '<div class="container-inline">',
	    '#suffix' => '</div>',
      '#tree' => TRUE,
  	);
    $form['fieldset']['block'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Block %i title', array('%i' => $i)),
      '#size' => 20,
      '#default_value' => isset($settings['blocks'][$i]) ? $settings['blocks'][$i] : '',
    );
    if ($real_num > 1) {
  		$form['fieldset']['block'][$i]['remove'] = array(
	      '#type' => 'submit',
        '#name' => 'names_fieldset_name_remove' . $i,
	      '#value' => t('Remove'),
	      '#submit' => array('achat_settings_form_remove_submit'),
	      '#validate' => array(),
	      '#ajax' => array(
	        'callback' => 'achat_settings_form_ajax_callback',
	        'wrapper' => 'fieldset_blocks_wrapper',
	        'progress' => array(
	        	'type' => 'throbber',
		        'message' => '',
		      ), 
	      ),
  		);
    }
  }
  $form['fieldset']['add'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
    '#submit' => array('achat_settings_form_add_submit'),
    '#validate' => array(),
    '#ajax' => array(
      'callback' => 'achat_settings_form_ajax_callback',
      'wrapper' => 'fieldset_blocks_wrapper',
      'progress' => array(
      	'type' => 'throbber',
        'message' => '',
      ), 
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['#validate'][] = 'achat_settings_form_validate';
  $form['#submit'][] = 'achat_settings_form_submit';
	return $form;
}

/**
 * Submit handler for the "Add" button.
 */
function achat_settings_form_add_submit($form, &$form_state) {
  $form_state['num']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback for both ajax-enabled buttons.
 */
function achat_settings_form_ajax_callback($form, $form_state) {
  return $form['fieldset']['block'];
}

/**
 * Submit handler for the "Remove" button.
 */
function achat_settings_form_remove_submit($form, &$form_state) {
  if ($form_state['num'] > 1) {
    $form_state['storage']['remove_ids'][] = $form_state['triggering_element']['#parents'][2];
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Validate handler for achat_settings_form.
 */
function achat_settings_form_validate($form, &$form_state) {
  $blocks = array();
  foreach ($form_state['values']['fieldset']['block'] as $key => $val) {
  	if (empty($val['title'])) {
  		form_set_error('fieldset][block][' . $key . '][title', t('Title %i can\'t be empty!', array('%i' => $key)));
  	} elseif (in_array($val['title'], $blocks)) {
  		form_set_error('fieldset][block][' . $key . '][title', t('Duplicate title %i !', array('%i' => $key)));
  	}
  	$blocks[$key] = $val['title'];
  }
}

/**
 * Submit handler for achat_settings_form.
 */
function achat_settings_form_submit($form, &$form_state) {
  $blocks = array();
  foreach ($form_state['values']['fieldset']['block'] as $key => $val) {
  	$blocks[] = $val['title'];
  }
  $settings['blocks'] = $blocks;
  variable_set('achat_settings', serialize($settings));
  drupal_set_message(t('Success ! Now you can go to ' .l(t('config'), 'admin/structure/block') . ' the blocks.'));
}