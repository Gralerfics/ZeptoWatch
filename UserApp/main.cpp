#include "common.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "ui.h"

#include "tim.h"

#include "oled.h"
#include "rtc_handler.h"

void Main() {
	OLED_Initialize();

	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	ui_init();

	HAL_TIM_Base_Start_IT(&htim2); // Lvgl Heart Beat Interrupt

	while (true) {
		lv_task_handler();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim2) {
		lv_tick_inc(1);
	}
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc) {
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
	if (HAL_RTC_SetAlarm_IT(hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}

	// Test
	OLED_ShowString(1, 3, (char *) ":  :");
	OLED_ShowNum(1, 1, RTC_Time.Hours, 2);
	OLED_ShowNum(1, 4, RTC_Time.Minutes, 2);
	OLED_ShowNum(1, 7, RTC_Time.Seconds, 2);

	// Move the arrows
	uint16_t cSecAngle = RTC_LVGL_GetSecondRotation();
	uint16_t cMinAngle = RTC_LVGL_GetMinuteRotation();
	uint16_t cHourAngle = RTC_LVGL_GetHourRotation();
	Step_Animation(ui_Sec,  cSecAngle - 60, cSecAngle);
	if (RTC_Time.Seconds == 0) {
		Step_Animation(ui_Min,  cMinAngle - 60, cMinAngle);
	}
	lv_img_set_angle(ui_Hour, cHourAngle);
}
