#include "applications.h"

#include "pikaScript.h"
#include "PikaVM.h"

#include "fshelper.h"

extern PikaObj *MainPikaObj;

int Application_RunningExisted __attribute__((section(".ccmram"))) = 0;
char Application_RunningFilePath[APPLICATION_PATH_MAXLEN] __attribute__((section(".ccmram"))) = {0};

int Application_Number __attribute__((section(".ccmram"))) = 0;
Application_Info_Type Application_Info[APPLICATION_MAX] __attribute__((section(".ccmram")));

lv_obj_t* Application_LVIcons[APPLICATION_MAX] __attribute__((section(".ccmram")));
lv_obj_t* Application_LVLabels[APPLICATION_MAX] __attribute__((section(".ccmram")));

void Applications_Scan() {
	FS_ScanFolder("0:", &Application_Number, (Application_Info_Type *) Application_Info);
	if (Application_Number < 0) {
		Application_Number = 0;
		Debug_Printf("Scan failed.");
	}

	for (int i = 0; i < Application_Number; i ++) {
		// Defaults
		sprintf(Application_Info[i].name, "%s", Application_Info[i].path);
		Application_Info[i].icon = &ui_img_scripts_png;
		Application_Info[i].color = 0xFF9B37;

#ifdef APPLICATION_SCAN_HEADER
		char txt[45] = {0};
		sprintf(txt, "Loading %s ...", Application_Info[i].path);
		lv_label_set_text(ui_applicationsLabel, txt);

		FS_ReadFile(Application_Info[i].path);
		char *Program = (char *) ReadBuffer;

		if (Program[0] == '#' && Program[1] == '#' && Program[2] == '#') {
			int ptr = 3, curPtr = 0, inAttr = 1;
			char curAttr[8] = {0}, curVal[APPLICATION_NAME_MAXLEN] = {0};

			while (Program[ptr] != '#' && Program[ptr] != '\n') {
				if (ptr >= 115) break;
				if (Program[ptr] == '=') {
					curPtr = 0;
					inAttr = 0;
				}
				if (Program[ptr] == ';') {
					if (curAttr[0] == 'I') {
						if (curPtr == 7 && curVal[0] == 's' && curVal[1] == 'c' && curVal[2] == 'r' && curVal[3] == 'i' && curVal[4] == 'p' && curVal[5] == 't' && curVal[6] == 's') {
							Application_Info[i].icon = &ui_img_scripts_png;
						} else if (curPtr == 5 && curVal[0] == 't' && curVal[1] == 'i' && curVal[2] == 'm' && curVal[3] == 'e' && curVal[4] == 'r') {
							Application_Info[i].icon = &ui_img_timer_png;
						} else if (curPtr == 4 && curVal[0] == 'c' && curVal[1] == 'a' && curVal[2] == 'l' && curVal[3] == 'c') {
							Application_Info[i].icon = &ui_img_calc_png;
						} else if (curPtr == 9 && curVal[0] == 'c' && curVal[1] == 'a' && curVal[2] == 'n' && curVal[3] == 'l' && curVal[4] == 'e' && curVal[5] == 'n' && curVal[6] == 'd' && curVal[7] == 'a' && curVal[8] == 'r') {
							Application_Info[i].icon = &ui_img_canlendar_png;
						} else if (curPtr == 8 && curVal[0] == 's' && curVal[1] == 'e' && curVal[2] == 't' && curVal[3] == 't' && curVal[4] == 'i' && curVal[5] == 'n' && curVal[6] == 'g' && curVal[7] == 's') {
							Application_Info[i].icon = &ui_img_settings_png;
						} else if (curPtr == 4 && curVal[0] == 'i' && curVal[1] == 'n' && curVal[2] == 'f' && curVal[3] == 'o') {
							Application_Info[i].icon = &ui_img_info_png;
						} else if (curPtr == 5 && curVal[0] == 'c' && curVal[1] == 'l' && curVal[2] == 'o' && curVal[3] == 'c' && curVal[4] == 'k') {
							Application_Info[i].icon = &ui_img_clock_png;
						} else if (curPtr == 5 && curVal[0] == 'c' && curVal[1] == 'h' && curVal[2] == 'e' && curVal[3] == 'c' && curVal[4] == 'k') {
							Application_Info[i].icon = &ui_img_check_png;
						} else if (curPtr == 5 && curVal[0] == 'n' && curVal[1] == 'o' && curVal[2] == 't' && curVal[3] == 'e' && curVal[4] == 's') {
							Application_Info[i].icon = &ui_img_notes_png;
						}
					} else if (curAttr[0] == 'N') {
						sprintf(Application_Info[i].name, "");
						for (int p = 0; p < curPtr; p ++) {
							sprintf(Application_Info[i].name, "%s%c", Application_Info[i].name, curVal[p]);
						}
					} else if (curAttr[0] == 'C') {
						Application_Info[i].color = 0;
						for (int p = 0; p < curPtr; p ++) {
							Application_Info[i].color = Application_Info[i].color * 10 + curVal[p] - '0';
						}
					}
					curPtr = 0;
					inAttr = 1;
				}
				if (Program[ptr] >= 'A' && Program[ptr] <= 'Z' || Program[ptr] >= 'a' && Program[ptr] <= 'z' || Program[ptr] >= '0' && Program[ptr] <= '9' || Program[ptr] == '_') {
					if (inAttr) {
						curAttr[curPtr ++] = Program[ptr];
					} else {
						curVal[curPtr ++] = Program[ptr];
					}
				}
				ptr ++;
			}
		}
#endif

		osDelay(5);
	}
}

int Applications_GetAppNumber() {
	return Application_Number;
}

char* Applications_GetAppName(int index) {
	if (index >= Application_Number) return 0;
	return Application_Info[index].name;
}

char* Applications_GetAppPath(int index) {
	if (index >= Application_Number) return 0;
	return Application_Info[index].path;
}

lv_img_dsc_t* Applications_GetAppIcon(int index) {
	// index starts from zero.
	if (index >= Application_Number) return 0;
	return Application_Info[index].icon;
}

uint32_t Applications_GetAppColor(int index) {
	if (index >= Application_Number) return 0;
	return Application_Info[index].color;
}

int Applications_IsRunning() {
	return Application_RunningExisted;
}

char* Applications_GetApplicationPath() {
	return Application_RunningFilePath;
}

void Applications_SetExisted(int val) {
	Application_RunningExisted = val;
}

void Applications_SetApplicationPath(const char *filepath) {
	sprintf(Application_RunningFilePath, "%s", filepath);
}

void Applications_ActivateApplication(const char *filepath) {
	Applications_SetApplicationPath(filepath);
	Applications_SetExisted(1);
}

void Applications_HaltApplication() {
	Applications_SetExisted(0);
	pks_vm_exit();
	Debug_Printf("PKS_VM_EXIT() Called.\n");
}

void Application_ExecuteFromFS(const char *filepath) {
	FS_ReadFile(filepath);
	obj_run(MainPikaObj, (char *) ReadBuffer);
}
