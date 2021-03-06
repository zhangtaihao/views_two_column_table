<?php

/**
 * @file views-view-two-column-table.tpl.php
 * Default simple view template to display a two column table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $class : A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each table, each row,
 *   indexed by table then by row.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * @ingroup views_templates
 */
?>


<div class="<?php print $class; ?>">
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($rows as $count => $row): ?>
    <table class="views-row-table">
      <tbody>
        <?php foreach ($row as $field => $content): ?>
          <tr class="views-field-row views-field-row-<?php print $fields[$field]; ?> <?php print implode(' ', $row_classes[$count][$field]); ?>">
            <th class="views-field-label views-field-label-<?php print $fields[$field]; ?>">
              <?php print $header[$field]; ?>
            </th>
            <td class="views-field views-field-<?php print $fields[$field]; ?>">
              <?php print $content; ?>
            </td>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  <?php endforeach; ?>
</div>

