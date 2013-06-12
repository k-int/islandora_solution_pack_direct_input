<?php

/**
 * @file
 *
 * Handles the uploading of the document file as part of the ingest process.
 */

/**
 * Defines a text box for a URL entry.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 * @return
 *   The drupal form definition.
 */
 
function islandora_direct_input_direct_input_form(array $form, array &$form_state) {
  $form = array(
        'direct_input_url' => array(
                  '#type' => 'text_format',
                  '#title' => 'WYSIWYG Textarea',
                  '#base_type' => 'textarea',
                  '#format' => 'filtered_html',
                  '#default_value' => NULL,
                        '#size' => 100,
        //              '#maxlength' => 5000,
                        '#required' => TRUE,
        )
  );
  return $form;
}

/**
 * Adds the link to the obj datastream.
 *
 * @param array $form
 *   The drupal form.
 * @param array $form_state
 *   The drupal form state.
 */
function islandora_direct_input_direct_input_form_submit(array $form, array &$form_state) {
	
	// Get the current object.
  $object = islandora_ingest_form_get_object($form_state);
  
  // Either create a dataset or return the dataset.
  if (empty($object['OBJ'])) { 
	$ds = $object->constructDatastream('OBJ', 'M');
    $object->ingestDatastream($ds);
  }
  else {
    $ds = $object['OBJ'];
  }
  
  // Set the OBJ.
  $ds->obj = $form_state['values']['direct_input'];
//changed from:
//$ds->url = $form_state['values']['direct_input'];
}
