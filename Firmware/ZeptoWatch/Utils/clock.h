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
uint8_t RTC_GetHour12();

#ifdef __cplusplus
}
#endif

#endif
