#Patches

When patching a contrib module or core, the following steps should be followed:
1. Copy the patch file in this folder: <module_name>/<patch_file>
2. Apply the patch to the module
3. Commit

List of patches (alphabetically)

* core
  * Modules are enabled before the installation profile
  * patches/core/core-simpletest-install-profile.patch

* i18n_string
    * Fixes undefined method strings_remove and strings_update
    * patches/i18n/strings_remove_update_undefined_method.patch

* entity_collection
  * Fixed bug when using autocomplete for entities
  * https://www.drupal.org/node/2351417
  * patches/entity_collection/entity_collection-disable_bundle_query-2351417-1-D7.patch

* entity_collection
  * Fix position and depth when adding new item
  * patches/entity_collection/entity_collection-depth-position.patch

* entity_collection
  * Fix bug when saving different entities with same eid (overwrites one another)
  * patches/entity_collection/entity_collection-entities-with-same-eid.patch

* entity_collection
  * Fixed undefined variable
  * [https://www.drupal.org/node/2330513](https://www.drupal.org/files/issues/entity_collection_undefined_variable.patch)
  * patches/entity_collection/entity_collection_undefined_variable.patch
  * patches/entity_collection/content_add_form_validation.patch

* entity_translation
  * Fix bug of incorrect language none for pathauto alias
  * https://www.drupal.org/node/1925848
  * patches/entity_translation/entitytranslation-incorrect_pathauto_pattern-1925848-8.patch

* entity_translation
  * Added entity_translation in views (to be able to filter by language)
  * https://www.drupal.org/node/1330332 (https://www.drupal.org/files/issues/entity_translation-filter_views-1330332-47.patch)
  * patches/entity_translation/entity_translation-filter_views-1330332-47.patch

* rules
  * added && if isset($data[$hook]) to avoid error when running update.sh (https://www.drupal.org/node/2161847)
  * https://www.drupal.org/files/issues/rules-fix-unsupported-operand-types-2161847-2.patch
  * patches/rules/rules-fix-unsupported-operand-types-2161847-2.patch

* tmgmt
  * Menu link source search is not case sensitive
  * patches/tmgmt/i18n_string-search-case-insensitive.patch

* tmgmt
  * Notice: Undefined index: format in text_tmgmt_source_translation_structure() (line 27 of /Users/cristiroma/Work/osha/project/docroot/sites/all/modules/contrib/tmgmt/sources/field/tmgmt_field.module). when creating nodes
  * patches/tmgmt/undefined_index_format.patch

* workbench_moderation
  * Fix saving 2 current statuses for same revision
  * [https://www.drupal.org/node/1436260](https://www.drupal.org/files/issues/1436260-workbench_moderation-states-node_save-74.patch)

* workbench_moderation
  * Added patch for hard-coded label
  * [https://www.drupal.org/node/2360059](https://www.drupal.org/files/issues/workbench_moderation_hardcoded_set_moderation_state-2360059-1.patch)
  * patches/workbench_moderation/workbench_moderation_hardcoded_set_moderation_state-2360059-1.patch

* workbench_moderation
  * path to add access check in workbench moderation form to prevent change of status
  * /patches/workbench_moderation/workbench_moderation_access_check_in_moderation_form.patch

* workbench_moderation
  * Fix bug CW-438 when URL in original language is lost when adding a new translation
  * [https://www.drupal.org/node/1946392](https://www.drupal.org/files/et_language-1946392-1.patch)
  * patches/workbench_moderation/et_language-1946392-1.patch

* workbench_moderation
  * Fix bug when insert/update node, current revision exclude form updating
  * patches/workbench_moderation/workbench_moderation_bug_set_revision_state_0_of_current_revision.patch
---
