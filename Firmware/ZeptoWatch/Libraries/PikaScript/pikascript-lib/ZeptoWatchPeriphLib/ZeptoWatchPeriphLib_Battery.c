#include "pikaScript.h"

#include "battery.h"

int ZeptoWatchPeriphLib_Battery_getRawData(PikaObj *self) {
	return Battery_GetADCData();
}

int ZeptoWatchPeriphLib_Battery_isCharging(PikaObj *self) {
	return Battery_IsCharging();
}
