#include "ui_user.h"

#include "ui.h"

#include "applications.h"
#include "clock.h"
#include "power.h"

lv_obj_t* UI_Current_Page = NULL;

void setUICurrentPage(lv_obj_t *v) {
	UI_Current_Page = v;
}

lv_obj_t* getUICurrentPage() {
	return UI_Current_Page;
}

void ui_event_appButtons(lv_event_t *e) {
	lv_event_code_t event_code = lv_event_get_code(e);
	if (event_code == LV_EVENT_CLICKED) {
		_ui_screen_change(ui_Appfield, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
		callApplication(e);
	}
}

void shutdownConfirmed(lv_event_t *e) {
	Power_Standby();
}

void shutdownBack(lv_event_t *e) {
	lv_event_code_t event_code = lv_event_get_code(e);
	if (event_code == LV_EVENT_CLICKED) {
		if (getUICurrentPage() == NULL) setUICurrentPage(ui_Home);
		_ui_screen_change(getUICurrentPage(), LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
	}
}

void quitFromApplication(lv_event_t *e) {
	Applications_HaltApplication();
}

void callApplication(lv_event_t *e) {
	lv_obj_t* target = lv_event_get_target(e);
	for (int i = 0; i < Applications_GetAppNumber(); i ++) {
		if (target == Application_LVIcons[i]) {
			Applications_ActivateApplication(Applications_GetAppPath(i));
			break;
		}
	}
}

void callShutdown() {
	_ui_screen_change(ui_Shutdown, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
	dropdownDropping_Animation(ui_shundownPanel, 0);
}

void refreshAppList(lv_event_t *e) {
	extern int SystemScanningEnabled;
	SystemScanningEnabled = 1;
}

void UI_Clock_Arrows_Reset() {
	lv_img_set_angle(ui_secPtr, 0);
	lv_img_set_angle(ui_minPtr, 0);
	lv_img_set_angle(ui_hourPtr, 0);
//	lv_obj_set_style_opa(ui_secPtr, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//	lv_obj_set_style_opa(ui_minPtr, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//	lv_obj_set_style_opa(ui_hourPtr, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void UI_Clock_InitArrows() {
	RTC_Update();
	uint8_t rtcHours = RTC_GetHours(), rtcMinutes = RTC_GetMinutes(), rtcSeconds = RTC_GetSeconds();
	uint16_t secPtrAngle = (uint16_t) (60 * (uint32_t) rtcSeconds);
	uint16_t minPtrAngle = (uint16_t) (60 * (uint32_t) rtcMinutes + (uint32_t) rtcSeconds);
	uint16_t hourPtrAngle = (uint16_t) (300 * (uint32_t) rtcHours + 5 * (uint32_t) rtcMinutes + (uint32_t) rtcSeconds / 12);
	lv_img_set_angle(ui_secPtr, secPtrAngle);
	lv_img_set_angle(ui_minPtr, minPtrAngle);
	lv_img_set_angle(ui_hourPtr, hourPtrAngle);
//	UI_Animate_PtrIniting(ui_secPtr, secPtrAngle, 0);
//	UI_Animate_PtrIniting(ui_minPtr, minPtrAngle, 0);
//	UI_Animate_PtrIniting(ui_hourPtr, hourPtrAngle, 0);
}
