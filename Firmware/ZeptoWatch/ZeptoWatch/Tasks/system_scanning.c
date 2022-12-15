#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

int SystemScanningEnabled = 0;

void startSystemScanning(void const * argument) {
	for (;;) {
		if (SystemScanningEnabled) {
			lv_label_set_text(ui_applicationsLabel, "Refreshing ...");
			Applications_Scan();
			UI_Applications_Listing();

			lv_label_set_text(ui_applicationsLabel, "Applications");
			SystemScanningEnabled = 0;
		}

		osDelay(1);
	}
}

#ifdef __cplusplus
}
#endif
