#include "ui_user.h"

#include "ui.h"

#include "applications.h"
#include "clock.h"
#include "power.h"

lv_obj_t* UI_Current_Page = NULL;

void setUICurrentPage(lv_obj_t *v) {
	UI_Current_Page = v;
}

lv_obj_t* getUICurrentPage() {
	return UI_Current_Page;
}

void ui_event_appButtons(lv_event_t *e) {
	lv_event_code_t event_code = lv_event_get_code(e);
	if (event_code == LV_EVENT_CLICKED) {
		_ui_screen_change(ui_Appfield, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
		callApplication(e);
	}
}

void shutdownConfirmed(lv_event_t *e) {
	Power_Standby();
}

void shutdownBack(lv_event_t *e) {
	lv_event_code_t event_code = lv_event_get_code(e);
	if (event_code == LV_EVENT_CLICKED) {
		if (getUICurrentPage() == NULL) setUICurrentPage(ui_Home);
		_ui_screen_change(getUICurrentPage(), LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
	}
}

void quitFromApplication(lv_event_t *e) {
	Applications_HaltApplication();
}

void callApplication(lv_event_t *e) {
	lv_obj_t* target = lv_event_get_target(e);
	for (int i = 0; i < Applications_GetAppNumber(); i ++) {
		if (target == Application_LVIcons[i]) {
			Applications_ActivateApplication(Applications_GetAppPath(i), Applications_GetAppBuiltIn(i));
			break;
		}
	}
}

void callShutdown() {
	_ui_screen_change(ui_Shutdown, LV_SCR_LOAD_ANIM_FADE_ON, 150, 0);
	dropdownDropping_Animation(ui_shundownPanel, 0);
}

void refreshAppList(lv_event_t *e) {
	extern int SystemScanningEnabled;
	SystemScanningEnabled = 1;
}

//static int getMonthDay(int M) {
//	if (M == )
//}

static int getIntValue(char *str) {
	if (strlen(str) == 1) {
		return str[0] - '0';
	} else {
		return (str[0] - '0') * 10 + (str[1] - '0');
	}
}

static void calcRollerOptions(char *buf, int val, int half, int inval, int modulo) {
	sprintf(buf, "");
	for (int i = val - half; i <= val + half; i ++) {
		int v = (i + modulo) % modulo + inval;
		if (i == val + half) {
			sprintf(buf, "%s%d", buf, v);
		} else {
			sprintf(buf, "%s%d\n", buf, v);
		}
	}
}

static void setRollerOptions(lv_obj_t *target, int val, int half, int modulo) {
	int inval = 0;
	if (modulo == 12) inval = 1;
	if (modulo == 31) {
		inval = 1;
//		lv_roller_get_selected_str();
//		modulo = getMonthDay();
	}
	char list[50];
	calcRollerOptions(list, val, half, inval, modulo);
	lv_roller_set_options(target, list, LV_ROLLER_MODE_NORMAL);
	lv_roller_set_selected(target, half, LV_ANIM_OFF);
}

#define SETTINGS_ROLLERS_HALF 4

void settingsRolValChanged(lv_event_t * e) {
	int *user_data = lv_event_get_user_data(e);
	lv_obj_t *target = lv_event_get_target(e);
	char seltmp[5];
	lv_roller_get_selected_str(target, seltmp, 5);
	setRollerOptions(target, getIntValue(seltmp), SETTINGS_ROLLERS_HALF, user_data[0]);
}

void settingsTimeClicked(lv_event_t * e) {
	char seltmp1[5], seltmp2[5], seltmp3[5];
	lv_roller_get_selected_str(ui_rolHour, seltmp1, 5);
	lv_roller_get_selected_str(ui_rolMin, seltmp2, 5);
	lv_roller_get_selected_str(ui_rolSec, seltmp3, 5);
	RTC_SetTime(getIntValue(seltmp1), getIntValue(seltmp2), getIntValue(seltmp3));
}

void settingsDateClicked(lv_event_t * e) {
	char seltmp1[5], seltmp2[5], seltmp3[5];
	lv_roller_get_selected_str(ui_rolYear, seltmp1, 5);
	lv_roller_get_selected_str(ui_rolMon, seltmp2, 5);
	lv_roller_get_selected_str(ui_rolDay, seltmp3, 5);
	RTC_SetDate(getIntValue(seltmp1), getIntValue(seltmp2), getIntValue(seltmp3));
}

void settingsEnBuValChanged(lv_event_t * e) {
	extern int BuiltInAppsEnabled;
	BuiltInAppsEnabled = lv_obj_has_state(ui_settingsEnBulSwt, LV_STATE_CHECKED);
}

void initSettingsRollers() {
	setRollerOptions(ui_rolHour, RTC_GetHours(), SETTINGS_ROLLERS_HALF, 24);
	setRollerOptions(ui_rolMin, RTC_GetMinutes(), SETTINGS_ROLLERS_HALF, 60);
	setRollerOptions(ui_rolSec, RTC_GetSeconds(), SETTINGS_ROLLERS_HALF, 60);
	setRollerOptions(ui_rolYear, RTC_GetYear(), SETTINGS_ROLLERS_HALF, 100);
	setRollerOptions(ui_rolMon, RTC_GetMonth(), SETTINGS_ROLLERS_HALF, 12);
	setRollerOptions(ui_rolDay, RTC_GetDay(), SETTINGS_ROLLERS_HALF, 31);
}
