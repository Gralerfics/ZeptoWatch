#include "powerkey.h"

/* 0: Normal
 * 1: Pause
 * 2: Shutdown */
int currentPowerState = 0;

int Power_GetState() {
	return currentPowerState;
}

void Power_SetState(int state) {
	if (state == 0 || state == 1 || state == 2) {
		currentPowerState = state;
	}
}
