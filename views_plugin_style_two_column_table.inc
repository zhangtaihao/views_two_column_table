<?php
// $Id$

/**
 * @file
 * Contains the two column table style plugin.
 */

/**
 * Style plugin to render each item in a two column table.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_two column_table extends views_plugin_style_table {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}

