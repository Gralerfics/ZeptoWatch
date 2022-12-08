#include "clock.h"

RTC_DateTypeDef RTC_Date = {0};
RTC_TimeTypeDef RTC_Time = {0};

void RTC_Update() {
	HAL_RTC_GetTime(&hrtc, &RTC_Time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &RTC_Date, RTC_FORMAT_BIN);
}

uint8_t RTC_GetHour12() {
	return RTC_Time.Hours > 12 ? (RTC_Time.Hours - 12) : RTC_Time.Hours;
}
