<?php

/**
 * Display the view as a two column table.
 */
function template_preprocess_views_view_two_column_table(&$vars) {
  $view = $vars['view'];
  $fields = &$view->field;
  $handler  = $view->style_plugin;

  // Divert rendered rows into result, similar to table
  $result = $vars['result'] = $vars['rows'];
  $vars['rows'] = array();

  $vars['header'] = array();
  $vars['fields'] = array();
  foreach ($fields as $field => $field_handler) {
    // Prepare labels for use in header column
    if (empty($field_handler->options['exclude'])) {
      $label = check_plain(!empty($fields[$field]) ? $fields[$field]->label() : '');
      $vars['header'][$field] = $label;
    }

    // Create a second variable so we can easily find what fields we have and what the
    // CSS classes should be.
    $vars['fields'][$field] = views_css_safe($field);
  }

  // Render all values
  $renders = $handler->render_fields($result);

  foreach ($renders as $num => $row_output) {
    // Prepare row
    $vars['rows'][$num] = array();
    foreach ($row_output as $field => $field_output) {
      if (!empty($fields[$field]->options['exclude'])) {
        // Skip excluded fields
        continue;
      }

      if ($vars['options']['skip_blank'] && empty($field_output)) {
        // Skip empty fields if specified
        continue;
      }

      $vars['rows'][$num][$field] = $field_output;
    }
  }

  $vars['row_classes'] = array();
  foreach ($vars['rows'] as $num => $row) {
    $count = 0;
    foreach ($row as $field => $column) {
      $vars['row_classes'][$num][$field][] = ($count++ % 2 == 0) ? 'odd' : 'even';
    }
    $vars['row_classes'][$num][0][] = 'views-row-first';
    $vars['row_classes'][$num][count($vars['row_classes'][$num]) - 1][] = 'views-row-last';
  }

  $vars['class'] = 'views-two-column-table';
}
