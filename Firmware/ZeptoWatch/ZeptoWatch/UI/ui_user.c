#include "ui_user.h"

#include "ui.h"
#include "ui_helpers_user.h"

#include "clock.h"

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
	UI_Animate_PtrIniting(ui_secPtr, secPtrAngle, 0);
	UI_Animate_PtrIniting(ui_minPtr, minPtrAngle, 0);
	UI_Animate_PtrIniting(ui_hourPtr, hourPtrAngle, 0);
}
