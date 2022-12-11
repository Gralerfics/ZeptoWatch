#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

void StartApplicationExecuting(void const * argument) {
	for (;;) {
		if (Applications_IsRunningApplicationExisted()) {
			Application_ExecuteFromFS(Applications_GetRunningApplicationPath());
		}
		osDelay(10);
	}
}

#ifdef __cplusplus
}
#endif
