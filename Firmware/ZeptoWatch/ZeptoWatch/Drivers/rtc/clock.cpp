#include "clock.h"

RTC_DateTypeDef RTC_Date = {0};
RTC_TimeTypeDef RTC_Time = {0};

int RTC_IsValid() {
	return !(RTC_Time.Hours >= 24 || RTC_Time.Minutes >= 60);
}

void RTC_Update() {
	do {
		HAL_RTC_GetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &RTC_Date, RTC_FORMAT_BIN);
	} while(!RTC_IsValid());
}

uint8_t RTC_GetHours() {
	RTC_Update();
	return RTC_Time.Hours;
}

uint8_t RTC_GetMinutes() {
	RTC_Update();
	return RTC_Time.Minutes;
}

uint8_t RTC_GetSeconds() {
	RTC_Update();
	return RTC_Time.Seconds;
}

uint8_t RTC_GetSubseconds() {
	RTC_Update();
	return RTC_Time.SubSeconds;
}

uint8_t RTC_GetYear() {
	RTC_Update();
	return RTC_Date.Year;
}

uint8_t RTC_GetMonth() {
	RTC_Update();
	return RTC_Date.Month; // - (RTC_Date.Month > 9 ? 6 : 0); // Maybe to be modified.
}

uint8_t RTC_GetDay() {
	RTC_Update();
	return RTC_Date.Date;
}

uint8_t RTC_GetWeekDay() {
	RTC_Update();
	return RTC_Date.WeekDay;
}

void RTC_SetHours(uint8_t val) {
	RTC_Time.Hours = val;
	HAL_RTC_SetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);
}

void RTC_SetMinutes(uint8_t val) {
	RTC_Time.Minutes = val;
	HAL_RTC_SetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);
}

void RTC_SetSeconds(uint8_t val) {
	// Stop Alarm
	HAL_RTC_DeactivateAlarm(&hrtc, RTC_ALARM_A);

	RTC_Time.Seconds = val;
	HAL_RTC_SetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);

	// Restart Alarm
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Seconds = (val + 1) % 60;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}
}

void RTC_SetTime(uint8_t h, uint8_t m, uint8_t s) {
	// Stop Alarm
	HAL_RTC_DeactivateAlarm(&hrtc, RTC_ALARM_A);

	RTC_Time.Hours = h;
	RTC_Time.Minutes = m;
	RTC_Time.Seconds = s;
	HAL_RTC_SetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);

	// Restart Alarm
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Seconds = (s + 1) % 60;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS | RTC_ALARMMASK_MINUTES;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}
}

void RTC_SetDate(uint8_t Y, uint8_t M, uint8_t D) {
	RTC_Date.Year = Y;
	if (M < 10) {
		RTC_Date.Month = M - 1;
	} else {
		RTC_Date.Month = M + 5;
	}
	RTC_Date.Date = D - 1;
	HAL_RTC_SetDate(&hrtc, &RTC_Date, RTC_FORMAT_BIN);
}
