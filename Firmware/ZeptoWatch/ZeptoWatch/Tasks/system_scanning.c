#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "applications.h"

int SystemScanningEnabled = 0;

void startSystemScanning(void const * argument) {
	// Enable Scanning
	SystemScanningEnabled = 1;

	for (;;) {
		if (SystemScanningEnabled) {
			lv_label_set_text(ui_applicationsLabel, "Refreshing ...");
			Applications_Scan();
			UI_Applications_Listing();

			lv_label_set_text(ui_applicationsLabel, "Applications");
			SystemScanningEnabled = 0;
		}

		osDelay(100);
	}
}

#ifdef __cplusplus
}
#endif
