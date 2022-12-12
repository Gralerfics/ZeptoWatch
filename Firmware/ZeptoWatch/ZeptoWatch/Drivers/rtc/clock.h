#ifndef __CLOCK_H
#define __CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
#include "rtc.h"

extern RTC_DateTypeDef RTC_Date;
extern RTC_TimeTypeDef RTC_Time;

void RTC_Update();

uint8_t RTC_GetHours();
uint8_t RTC_GetMinutes();
uint8_t RTC_GetSeconds();

uint8_t RTC_GetYear();
uint8_t RTC_GetMonth();
uint8_t RTC_GetDay();
uint8_t RTC_GetWeekDay();

#ifdef __cplusplus
}
#endif

#endif
