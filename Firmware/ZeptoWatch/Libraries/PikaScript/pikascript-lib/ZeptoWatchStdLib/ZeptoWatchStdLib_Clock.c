#include "pikaScript.h"

#include "clock.h"

int ZeptoWatchStdLib_Clock_getDay(PikaObj *self) {
	return RTC_GetDay();
}

int ZeptoWatchStdLib_Clock_getHours(PikaObj *self) {
	return RTC_Time.Hours;
}

int ZeptoWatchStdLib_Clock_getMinutes(PikaObj *self) {
	return RTC_Time.Minutes;
}

int ZeptoWatchStdLib_Clock_getMonth(PikaObj *self) {
	return RTC_GetMonth();
}

int ZeptoWatchStdLib_Clock_getSeconds(PikaObj *self) {
	return RTC_Time.Seconds;
}

int ZeptoWatchStdLib_Clock_getWeekDay(PikaObj *self) {
	return RTC_GetWeekDay();
}

int ZeptoWatchStdLib_Clock_getYear(PikaObj *self) {
	return RTC_GetYear();
}
