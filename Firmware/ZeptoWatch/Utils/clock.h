#ifndef __CLOCK_H
#define __CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "rtc.h"

/* ==================== Body ==================== */
extern RTC_DateTypeDef RTC_Date;
extern RTC_TimeTypeDef RTC_Time;

void RTC_Update();

uint8_t RTC_GetHourIn12();

uint16_t RTC_LVGL_GetHourRotation();
uint16_t RTC_LVGL_GetMinuteRotation();
uint16_t RTC_LVGL_GetSecondRotation();

#ifdef __cplusplus
}
#endif

#endif
