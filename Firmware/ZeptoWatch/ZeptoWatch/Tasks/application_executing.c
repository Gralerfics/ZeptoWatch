#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

void StartApplicationExecuting(void const * argument) {
	Debug_Printf("Detecting ...\n");
	for (;;) {
		if (Applications_IsRunning()) {
			Debug_Printf("Detected Application.\n");
			if (Applications_IsBuiltIn()) {
				Application_ExecuteFromBuiltins(Applications_GetApplicationPath());
			} else {
				Application_ExecuteFromFS(Applications_GetApplicationPath());
			}
			Applications_HaltApplication();
			_ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
		}
		osDelay(50);
	}
}

#ifdef __cplusplus
}
#endif
