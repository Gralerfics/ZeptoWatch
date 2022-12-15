#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "ui_helpers_user.h"

#include "clock.h"

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *mHrtc) {
	RTC_Update();
	uint8_t rtcHours = RTC_GetHours(), rtcMinutes = RTC_GetMinutes(), rtcSeconds = RTC_GetSeconds();

	// Restart Alarm
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Seconds = (rtcSeconds + 1) % 60;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(mHrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}

	uint16_t secPtrAngle = (uint16_t) (60 * (uint32_t) rtcSeconds);
	uint16_t minPtrAngle = (uint16_t) (60 * (uint32_t) rtcMinutes + (uint32_t) rtcSeconds);
	uint16_t hourPtrAngle = (uint16_t) (300 * (uint32_t) rtcHours + 5 * (uint32_t) rtcMinutes + (uint32_t) rtcSeconds / 12);
	UI_Animate_PtrTicking(ui_secPtr, secPtrAngle - 60, secPtrAngle, 100, 0);
	lv_img_set_angle(ui_minPtr, minPtrAngle);
	lv_img_set_angle(ui_hourPtr, hourPtrAngle);

	char timeLabel[16] = {0};
	sprintf(timeLabel, "%d%d : %d%d : %d%d", rtcHours / 10, rtcHours % 10, rtcMinutes / 10, rtcMinutes % 10, rtcSeconds / 10, rtcSeconds % 10);
	lv_label_set_text(ui_dropdownTimeLabel, timeLabel);
	lv_label_set_text(ui_appDropdownTimeLabel, timeLabel);
}

#ifdef __cplusplus
}
#endif
