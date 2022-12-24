#include "applications.h"

#include "pikaScript.h"
#include "PikaVM.h"

#include "fshelper.h"

PikaObj *MainPikaObj = NULL;

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
		Debug_Printf("Scan Error.\n");
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

		Debug_Printf("Parsing:\n");

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
						} else if (curPtr == 6 && curVal[0] == 'm' && curVal[1] == 'e' && curVal[2] == 'r' && curVal[3] == 'i' && curVal[4] == 't' && curVal[5] == 's') {
							Application_Info[i].icon = &ui_img_merits_png;
						}
						Debug_Printf("\tIcon = %s\n", curVal);
					} else if (curAttr[0] == 'N') {
						sprintf(Application_Info[i].name, "");
						for (int p = 0; p < curPtr; p ++) {
							sprintf(Application_Info[i].name, "%s%c", Application_Info[i].name, curVal[p]);
						}
						Debug_Printf("\tName = %s\n", Application_Info[i].name);
					} else if (curAttr[0] == 'C') {
						Application_Info[i].color = 0;
						for (int p = 0; p < curPtr; p ++) {
							Application_Info[i].color = Application_Info[i].color * 10 + curVal[p] - '0';
						}
						Debug_Printf("\tColor = %lu\n", Application_Info[i].color);
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
	Debug_Printf("Application Activated: %s.\n", filepath);
}

void Applications_HaltApplication() {
	if (Application_RunningExisted) {
		Debug_Printf("Halt. Current Mem Used: %lu\n", pikaMemNow());

		// Halt Python VM
		pks_vm_exit();
		if (MainPikaObj != NULL) obj_deinit(MainPikaObj);
		// Clear Flag
		Applications_SetExisted(0);
		// DeInit LVGL Components
		extern SemaphoreHandle_t lvglMutexHandle;
		xSemaphoreTake(lvglMutexHandle, portMAX_DELAY);
		lv_obj_clean(ui_Appfield);
		xSemaphoreGive(lvglMutexHandle);

		Debug_Printf("Halted. Current Mem Used: %lf kB.\n", pikaMemNow() / 1024.0);
	}
}

void Application_ExecuteFromFS(const char *filepath) {
	FS_ReadFile(filepath);
	char* Program = (char *) ReadBuffer;

	// TODO: 读取文件会在文件末尾多读一些奇怪的字符导致脚本编译错误，此处以下策暂时解决
	for (int i = 0; i < FSHELPER_READBUFFER_SIZE - 4; i ++) {
		if (Program[i] == '#' && Program[i + 1] == 'E' && Program[i + 2] == 'N' && Program[i + 3] == 'D' && Program[i + 4] == '#') {
			for (int j = i + 5; j < FSHELPER_READBUFFER_SIZE; j ++) Program[j] = 0;
		}
	}

	MainPikaObj = pikaScriptInit();
	obj_run(MainPikaObj, Program);
}
