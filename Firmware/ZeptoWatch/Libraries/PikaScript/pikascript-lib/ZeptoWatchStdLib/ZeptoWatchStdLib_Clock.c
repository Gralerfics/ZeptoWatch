#include "pikaScript.h"

#include "clock.h"

int ZeptoWatchStdLib_Clock_getDay(PikaObj *self) {
	return RTC_GetDay();
}

int ZeptoWatchStdLib_Clock_getHours(PikaObj *self) {
	return RTC_GetHours();
}

int ZeptoWatchStdLib_Clock_getMinutes(PikaObj *self) {
	return RTC_GetMinutes();
}

int ZeptoWatchStdLib_Clock_getMonth(PikaObj *self) {
	return RTC_GetMonth();
}

int ZeptoWatchStdLib_Clock_getSeconds(PikaObj *self) {
	return RTC_GetSeconds();
}

int ZeptoWatchStdLib_Clock_getSubseconds(PikaObj *self) {
	return RTC_GetSubseconds();
}

int ZeptoWatchStdLib_Clock_getWeekDay(PikaObj *self) {
	return RTC_GetWeekDay();
}

int ZeptoWatchStdLib_Clock_getYear(PikaObj *self) {
	return RTC_GetYear();
}

void ZeptoWatchStdLib_Clock_setHours(PikaObj *self, int val) {
	RTC_SetHours(val);
}

void ZeptoWatchStdLib_Clock_setMinutes(PikaObj *self, int val) {
	RTC_SetMinutes(val);
}

void ZeptoWatchStdLib_Clock_setSeconds(PikaObj *self, int val) {
	RTC_SetSeconds(val);
}

void ZeptoWatchStdLib_Clock_setTime(PikaObj *self, int h, int m, int s) {
	RTC_SetTime(h, m, s);
}
