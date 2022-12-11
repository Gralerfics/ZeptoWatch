#include "power.h"

/* 0: Normal
 * 1: Pause
 * 2: Shutdown */
int Power_CurrentState = 0;

int Power_GetState() {
	return Power_CurrentState;
}

void Power_SetState(int state) {
	if (state == 0 || state == 1 || state == 2) {
		Power_CurrentState = state;
	}
}
