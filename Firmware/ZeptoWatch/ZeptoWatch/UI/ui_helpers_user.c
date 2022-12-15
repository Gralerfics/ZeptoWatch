#include "ui_helpers_user.h"

#include "applications.h"

void UI_Applications_InitList() {
	for (int i = 0; i < APPLICATION_MAX; i ++) {
		// Icons
		Application_LVIcons[i] = lv_btn_create(ui_applicationsList);
		lv_obj_set_width(Application_LVIcons[i], 50);
		lv_obj_set_height(Application_LVIcons[i], 50);
		lv_obj_set_x(Application_LVIcons[i], (lv_coord_t) (-35 + (i % 2) * 65));
		lv_obj_set_y(Application_LVIcons[i], (lv_coord_t) (-32 + (i / 2) * 76));
		lv_obj_set_align(Application_LVIcons[i], LV_ALIGN_CENTER);
		lv_obj_add_flag(Application_LVIcons[i], LV_OBJ_FLAG_SCROLL_ON_FOCUS);
		lv_obj_clear_flag(Application_LVIcons[i], LV_OBJ_FLAG_SCROLLABLE);
		lv_obj_set_style_radius(Application_LVIcons[i], 25, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_bg_opa(Application_LVIcons[i], 255, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_add_flag(Application_LVIcons[i], LV_OBJ_FLAG_HIDDEN); // Hide first.
		lv_obj_add_event_cb(Application_LVIcons[i], ui_event_appButtons, LV_EVENT_ALL, NULL);

		// Labels
		Application_LVLabels[i] = lv_label_create(ui_applicationsList);
		lv_obj_set_width(Application_LVLabels[i], LV_SIZE_CONTENT);
		lv_obj_set_height(Application_LVLabels[i], LV_SIZE_CONTENT);
		lv_obj_set_x(Application_LVLabels[i], (lv_coord_t) (-35 + (i % 2) * 65));
		lv_obj_set_y(Application_LVLabels[i], (lv_coord_t) (2 + (i / 2) * 76));
		lv_obj_set_align(Application_LVLabels[i], LV_ALIGN_CENTER);
		lv_obj_set_style_text_font(Application_LVLabels[i], &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_add_flag(Application_LVLabels[i], LV_OBJ_FLAG_HIDDEN); // Hide first.
	}
}

void UI_Applications_Listing() {
	for (int i = 0; i < Applications_GetAppNumber(); i ++) {
		lv_obj_set_style_bg_img_src(Application_LVIcons[i], Applications_GetAppIcon(i), LV_PART_MAIN | LV_STATE_DEFAULT); // TODO. Icon selector.
		lv_obj_set_style_bg_color(Application_LVIcons[i], lv_color_hex(Applications_GetAppColor(i)), LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_label_set_text(Application_LVLabels[i], Applications_GetAppName(i));
		lv_obj_clear_flag(Application_LVIcons[i], LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(Application_LVLabels[i], LV_OBJ_FLAG_HIDDEN);
	}
	for (int i = Applications_GetAppNumber(); i < APPLICATION_MAX; i ++) {
		lv_obj_add_flag(Application_LVIcons[i], LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(Application_LVLabels[i], LV_OBJ_FLAG_HIDDEN);
	}
}

void UI_Animate_PtrTicking(lv_obj_t *TargetObject, int start, int end, int time, int delay) {
	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, time);
	lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
	lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
	lv_anim_set_values(&PropertyAnimation_0, start, end);
	lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
	lv_anim_set_delay(&PropertyAnimation_0, delay);
	lv_anim_set_playback_time(&PropertyAnimation_0, 0);
	lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
	lv_anim_set_early_apply(&PropertyAnimation_0, false);
	lv_anim_start(&PropertyAnimation_0);
}

void UI_Animate_PtrIniting(lv_obj_t * TargetObject, int end, int delay) {
	lv_anim_t PropertyAnimation_0;
	lv_anim_init(&PropertyAnimation_0);
	lv_anim_set_time(&PropertyAnimation_0, 600);
	lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
	lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
	lv_anim_set_values(&PropertyAnimation_0, 0, end);
	lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
	lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
	lv_anim_set_playback_time(&PropertyAnimation_0, 0);
	lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
	lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
	lv_anim_set_early_apply(&PropertyAnimation_0, false);
	lv_anim_start(&PropertyAnimation_0);
	lv_anim_t PropertyAnimation_1;
	lv_anim_init(&PropertyAnimation_1);
	lv_anim_set_time(&PropertyAnimation_1, 300);
	lv_anim_set_user_data(&PropertyAnimation_1, TargetObject);
	lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
	lv_anim_set_values(&PropertyAnimation_1, 0, 255);
	lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in);
	lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
	lv_anim_set_playback_time(&PropertyAnimation_1, 0);
	lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
	lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
	lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
	lv_anim_set_early_apply(&PropertyAnimation_1, false);
	lv_anim_start(&PropertyAnimation_1);
}
