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
		}
		osDelay(10);
	}
}

#ifdef __cplusplus
}
#endif
