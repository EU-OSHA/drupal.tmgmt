<?php

function osha_workflow_permissions_download_file_entities() {
  return array(
    'download any audio files',
    'download any document files',
    'download any image files',
    'download any video files',
    'download own audio files',
    'download own document files',
    'download own image files',
    'download own video files',
  );
}

function osha_workflow_permissions_manage_content() {
  return array(
    'create article content',
    'create files',
    'create page content',
    'create url aliases',
    'delete own audio files',
    'delete own document files',
    'delete own image files',
    'delete own video files',
    'edit any article content',
    'edit any audio files',
    'edit any document files',
    'edit any image files',
    'edit any page content',
    'edit any video files',
    'edit own article content',
    'edit own audio files',
    'edit own document files',
    'edit own image files',
    'edit own page content',
    'edit own video files',

    'access media browser',

    'view files',
    'view own files',

    'view private files',
    'view own private files',
  );
}

function osha_workflow_permissions_common() {
  return array(
    'access content',
    'view osh content tab',

    'search content',
    'use advanced search',

    'use text format filtered_html',
    'use text format full_html',

  );
}

function osha_worfklow_permissions_moderator() {
  return array(
    // Important for everyone (editor ... to ... admin) to have it, otherwise
    // they cannot access unpublished content.
    'access workbench access by role',

    'access administration pages',
    'access contextual links',
    'access dashboard',
    'access toolbar',
    'view the administration theme',

    'access workbench',
    'use workbench_moderation my drafts tab',
    'view moderation messages',
    'view revisions',
    'view workbench access information',
    'view moderation history',

    'view own unpublished content',
    'view all unpublished content',
  );
}

/**
 * Array of permissions for the Editor role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_editor() {
  $ret = array_merge(
    array(
      'edit any content in draft',
      'edit any content in published',
      'moderate content from draft to final_draft',
      'access contextual links',
      'access dashboard',
      'create files',
      'view own private files',
      'view own files',
      'view private files',
      'edit own image files',
      'edit any image files',
      'delete own image files',
      'download own image files',
      'download any image files',
      'edit own video files',
      'edit any video files',
      'delete own video files',
      'download own video files',
      'download any video files',
      'edit own audio files',
      'edit any audio files',
      'delete own audio files',
      'download own audio files',
      'download any audio files',
      'edit own document files',
      'edit any document files',
      'delete own document files',
      'delete any document files',
      'download own document files',
      'download any document files',

      'use text format full_html',
      'use text format filtered_html',
      'access media browser',
      'access content',
      'view own unpublished content',
      'view revisions',
      'create article content',
      'edit own article content',
      'edit any article content',

      'edit any content in draft',
      'edit any content in published',
      'view osh content tab',

      'create url aliases',
      'access administration pages',
      'access toolbar',
      'access workbench',
      'access workbench access by role',
      'view workbench access information',
      'view all unpublished content',
      'view moderation messages',
      'use workbench_moderation my drafts tab',
      'moderate content from draft to final_draft',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}

/**
 * Array of permissions for the Review Manager role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_review_manager() {
  $ret = array_merge(
    array(
      'view osh review manager needs review tab',
      'access content overview',
      'assign workbench access',

      'access site in maintenance mode',
      'accept translation jobs',
      'administer files',
      'administer nodes',
      'administer taxonomy',
      'bypass workbench moderation',
      'create translation jobs',
      'submit translation jobs',

      'edit any content in draft',
      'edit any content in final_draft',
      'edit any content in ready_to_publish',
      'edit any content in published',
      'edit any content in to_be_approved',
      'edit any content in needs_review',
      'edit any content in rejected',
      'edit any content in approved',

      'moderate content from draft to final_draft',
      'moderate content from final_draft to ready_to_publish',
      'moderate content from final_draft to draft',
      'moderate content from final_draft to needs_review',
      'moderate content from final_draft to to_be_approved',
      'moderate content from approved to ready_to_publish',
      'moderate content from rejected to ready_to_publish',
      'moderate content from ready_to_publish to published',
      'edit any content in ready_to_publish',
      'access contextual links',
      'access dashboard',
      'administer files',
      'create files',
      'view own private files',
      'view own files',
      'view private files',
      'edit own image files',
      'edit any image files',
      'delete own image files',
      'download own image files',
      'download any image files',
      'edit own video files',
      'edit any video files',
      'delete own video files',
      'download own video files',
      'download any video files',
      'edit own audio files',
      'edit any audio files',
      'delete own audio files',
      'download own audio files',
      'download any audio files',
      'edit own document files',
      'edit any document files',
      'delete own document files',
      'delete any document files',
      'download own document files',
      'download any document files',
      'use text format full_html',
      'use text format filtered_html',
      'access media browser',
      'administer nodes',
      'access content overview',
      'access content',
      'view own unpublished content',
      'view revisions',
      'create article content',
      'edit own article content',
      'edit any article content',
      'create page content',
      'edit own page content',
      'edit any page content',
      'edit any content in draft',
      'edit any content in approved',
      'edit any content in approved',
      'edit any content in final_draft',
      'edit any content in needs_review',
      'edit any content in to_be_approved',
      'edit any content in ready_to_publish',
      'edit any content in published',
      'view osh review manager needs review tab',
      'view osh content tab',
      'create url aliases',
      'access administration pages',
      'view the administration theme',
      'administer taxonomy',
      'access toolbar',
      'create translation jobs',
      'submit translation jobs',
      'accept translation jobs',
      'access workbench',
      'assign workbench access',
      'access workbench access by role',
      'view workbench access information',
      'view all unpublished content',
      'bypass workbench moderation',
      'view moderation history',
      'view moderation messages',
      'use workbench_moderation my drafts tab',
      'moderate content from draft to final_draft',
      'moderate content from rejected to draft',
      'moderate content from rejected to final_draft',
      'moderate content from rejected to to_be_approved',
      'moderate content from rejected to ready_to_publish',
      'moderate content from approved to ready_to_publish',
      'moderate content from final_draft to draft',
      'moderate content from final_draft to needs_review',
      'moderate content from final_draft to to_be_approved',
      'moderate content from final_draft to ready_to_publish',
      'moderate content from ready_to_publish to published',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}


/**
 * Array of permissions for the Project Manager role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_project_manager() {
  $ret = array_merge(
    array(
      'edit any content in needs_review',
      'view osh project manager needs review tab',
      'mark access section as reviewed',

      'moderate content from needs_review to final_draft',
      'edit any content in approved',
      'edit any content in rejected',
      'moderate content from final_draft to draft',
      'moderate content from rejected to final_draft',
      'moderate content from rejected to to_be_approved',
      'moderate content from needs_review to to_be_approved',
      'moderate content from needs_review to ready_to_publish',
      'moderate content from needs_review to to_be_approved',
      'moderate content from approved to ready_to_publish',
      'moderate content from approved to final_draft',
      'access contextual links',
      'access dashboard',
      'create files',
      'view own private files',
      'view own files',
      'view private files',
      'edit own image files',
      'edit any image files',
      'delete own image files',
      'download own image files',
      'download any image files',
      'edit own video files',
      'edit any video files',
      'delete own video files',
      'download own video files',
      'download any video files',
      'edit own audio files',
      'edit any audio files',
      'delete own audio files',
      'download own audio files',
      'download any audio files',
      'edit own document files',
      'edit any document files',
      'delete own document files',
      'delete any document files',
      'download own document files',
      'download any document files',
      'use text format full_html',
      'use text format filtered_html',
      'access media browser',
      'access content',
      'view own unpublished content',
      'view revisions',
      'edit own article content',
      'edit any article content',
      'edit any content in approved',
      'edit any content in approved',
      'edit any content in needs_review',
      'view osh project manager needs review tab',
      'view osh content tab',
      'mark access section as reviewed',
      'create url aliases',
      'access administration pages',
      'view the administration theme',
      'access toolbar',
      'access workbench',
      'access workbench access by role',
      'view workbench access information',
      'view all unpublished content',
      'view moderation history',
      'view moderation messages',
      'use workbench_moderation my drafts tab',
      'moderate content from rejected to draft',
      'moderate content from rejected to final_draft',
      'moderate content from rejected to to_be_approved',
      'moderate content from approved to final_draft',
      'moderate content from approved to ready_to_publish',
      'moderate content from needs_review to final_draft',
      'moderate content from needs_review to to_be_approved',
      'moderate content from needs_review to ready_to_publish',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}

/**
 * Array of permissions for the Approver role.
 * @return array
 *   Permissions
 */
function osha_workflow_permissions_role_approver() {
  $ret = array_merge(
    array(
      'edit any content in to_be_approved',
      'view osh approver needs review tab',

      'moderate content from to_be_approved to approved',
      'moderate content from to_be_approved to rejected',
    ),
    osha_workflow_permissions_common(),
    osha_workflow_permissions_manage_content(),
    osha_workflow_permissions_download_file_entities(),
    osha_worfklow_permissions_moderator()
  );
  return $ret;
}
