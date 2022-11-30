#include "clock.h"

RTC_DateTypeDef RTC_Date = {0};
RTC_TimeTypeDef RTC_Time = {0};

void RTC_Update() {
	HAL_RTC_GetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &RTC_Date, RTC_FORMAT_BIN);
}

uint8_t RTC_GetHourIn12() {
	return RTC_Time.Hours > 12 ? (RTC_Time.Hours - 12) : RTC_Time.Hours;
}

uint16_t RTC_LVGL_GetHourRotation() {
	return (uint16_t) (3600 * ((uint32_t) RTC_GetHourIn12() * 3600 + RTC_Time.Minutes * 60 + RTC_Time.Seconds) / 43200);
}

uint16_t RTC_LVGL_GetMinuteRotation() {
	return (uint16_t) (3600 * (uint32_t) RTC_Time.Minutes / 60);
}

uint16_t RTC_LVGL_GetSecondRotation() {
	return (uint16_t) (3600 * (uint32_t) RTC_Time.Seconds / 60);
}
