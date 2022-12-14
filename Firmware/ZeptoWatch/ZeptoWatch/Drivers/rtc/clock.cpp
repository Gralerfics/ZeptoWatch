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
	return RTC_Time.Hours;
}

uint8_t RTC_GetMinutes() {
	return RTC_Time.Minutes;
}

uint8_t RTC_GetSeconds() {
	return RTC_Time.Seconds;
}

uint8_t RTC_GetYear() {
	return RTC_Date.Year;
}

uint8_t RTC_GetMonth() {
	return RTC_Date.Month - (RTC_Date.Month > 9 ? 6 : 0); // Maybe to be modified.
}

uint8_t RTC_GetDay() {
	return RTC_Date.Date;
}

uint8_t RTC_GetWeekDay() {
	return RTC_Date.WeekDay;
}
