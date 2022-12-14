#include "ui_helpers_user.h"

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
