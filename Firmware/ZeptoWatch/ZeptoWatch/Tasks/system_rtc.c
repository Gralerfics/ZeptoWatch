#include "clock.h"

#ifdef __cplusplus
extern "C" {
#endif

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *mHrtc) {
	RTC_Update();

	// Restart Alarm
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Seconds = RTC_Time.Seconds + 1;
	if (sAlarm.AlarmTime.Seconds > 59) sAlarm.AlarmTime.Seconds = 0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(mHrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}

	// Move the arrows
//	uint16_t cSecAngle = RTC_LVGL_GetSecondRotation();
//	uint16_t cMinAngle = RTC_LVGL_GetMinuteRotation();
//	uint16_t cHourAngle = RTC_LVGL_GetHourRotation();
//	Step_Animation(ui_Sec,  cSecAngle - 60, cSecAngle);
//	if (RTC_Time.Seconds == 0) {
//		Step_Animation(ui_Min,  cMinAngle - 60, cMinAngle);
//	}
//	lv_img_set_angle(ui_Hour, cHourAngle);
}

#ifdef __cplusplus
}
#endif
