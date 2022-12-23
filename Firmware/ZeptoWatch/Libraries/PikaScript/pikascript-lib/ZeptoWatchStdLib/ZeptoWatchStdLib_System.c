#include "pikaScript.h"

#include "cmsis_os.h"
#include "delay.h"

void ZeptoWatchStdLib_System_delayMs(PikaObj *self, int time) {
	extern SemaphoreHandle_t lvglMutexHandle;
	xSemaphoreGive(lvglMutexHandle);
	osDelay(time);
	xSemaphoreTake(lvglMutexHandle, portMAX_DELAY);
}

void ZeptoWatchStdLib_System_delayMsBlocking(PikaObj *self, int time) {
	Delay_ms(time);
}

void ZeptoWatchStdLib_System_delayUsBlocking(PikaObj *self, int time) {
	Delay_us(time);
}
