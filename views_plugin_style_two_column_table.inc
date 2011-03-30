<?php

/**
 * @file
 * Contains the two column table style plugin.
 */

/**
 * Style plugin to render each item in a two column table.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_two_column_table extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['skip_blank'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    $form['skip_blank'] = array(
      '#type' => 'checkbox',
      '#default_value' => $this->options['skip_blank'],
      '#title' => t('Skip empty fields'),
      '#description' => t('If a field has no content, the corresponding row will not be shown.'),
    );
  }
}

