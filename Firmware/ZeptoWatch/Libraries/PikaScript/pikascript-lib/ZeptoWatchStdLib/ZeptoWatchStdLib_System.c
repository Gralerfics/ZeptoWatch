#include "pikaScript.h"

#include "cmsis_os.h"
#include "delay.h"

void ZeptoWatchStdLib_System_delayMs(PikaObj *self, int time) {
	osDelay(time);
}

void ZeptoWatchStdLib_System_delayMsBlocking(PikaObj *self, int time) {
	Delay_ms(time);
}

void ZeptoWatchStdLib_System_delayUsBlocking(PikaObj *self, int time) {
	Delay_us(time);
}
