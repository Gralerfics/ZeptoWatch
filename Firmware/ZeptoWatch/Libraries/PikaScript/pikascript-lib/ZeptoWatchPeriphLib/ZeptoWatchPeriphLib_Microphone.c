#include "pikaScript.h"

#include "msm261s.h"

int ZeptoWatchPeriphLib_Microphone_getRawData(PikaObj *self) {
	return Microphone_GetSampleData();
}

void ZeptoWatchPeriphLib_Microphone_startSampling(PikaObj *self) {
	Microphone_StartSampling();
}

void ZeptoWatchPeriphLib_Microphone_stopSampling(PikaObj *self) {
	Microphone_StopSampling();
}
