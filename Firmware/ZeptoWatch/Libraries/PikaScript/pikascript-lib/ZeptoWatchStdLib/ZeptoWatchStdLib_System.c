#include "pikaScript.h"

#include "cmsis_os.h"

void ZeptoWatchStdLib_System_delayMs(PikaObj *self, int time) {
	osDelay(time);
}
