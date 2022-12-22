#include "builtin-ui_user.h"

#include "builtin-ui.h"
#include "vibrator.h"

static int woodenf_merits = 0;

void woodenfMeritsInc(lv_event_t * e) {
	woodenf_merits += 1;
//	Vibrator_Assert(100, 60);
	char tmpStr[20];
	sprintf(tmpStr, "Merits: %d", woodenf_merits);
	lv_label_set_text(ui_woodenfAccLabel, tmpStr);
}
