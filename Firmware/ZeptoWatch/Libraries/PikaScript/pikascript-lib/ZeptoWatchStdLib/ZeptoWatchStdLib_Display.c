#include "pikaScript.h"

#include "brightness.h"

int ZeptoWatchStdLib_Display_getBrightness(PikaObj *self) {
	return (int) Brightness_GetValue();
}

void ZeptoWatchStdLib_Display_setBrightness(PikaObj *self, int val) {
	Brightness_SetValue(val);
}
