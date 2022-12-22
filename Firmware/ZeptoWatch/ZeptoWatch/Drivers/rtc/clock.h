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
uint8_t RTC_GetSubseconds();

uint8_t RTC_GetYear();
uint8_t RTC_GetMonth();
uint8_t RTC_GetDay();
uint8_t RTC_GetWeekDay();

void RTC_SetHours(uint8_t val);
void RTC_SetMinutes(uint8_t val);
void RTC_SetSeconds(uint8_t val);
void RTC_SetTime(uint8_t h, uint8_t m, uint8_t s);

void RTC_SetDate(uint8_t Y, uint8_t M, uint8_t D);

#ifdef __cplusplus
}
#endif

#endif
