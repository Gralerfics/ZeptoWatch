#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

void StartApplicationExecuting(void const * argument) {
	for (;;) {
		if (Applications_IsRunning()) {
			Application_ExecuteFromFS(Applications_GetApplicationPath());

			Debug_Printf("Executed.");
			Applications_HaltApplication();
			_ui_screen_change(ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
//			lv_label_set_text(ui_appfieldTestLabel, "Halted.");
		}
		osDelay(10);
	}
}

#ifdef __cplusplus
}
#endif
