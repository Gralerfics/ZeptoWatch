#include "pikaScript.h"

#include "vibrator.h"

void ZeptoWatchPeriphLib_Vibrator_stop(PikaObj *self) {
	Vibrator_Stop();
}

void ZeptoWatchPeriphLib_Vibrator_vibrate(PikaObj *self, int ms, int pulse) {
	Vibrator_Assert(ms, pulse);
}
