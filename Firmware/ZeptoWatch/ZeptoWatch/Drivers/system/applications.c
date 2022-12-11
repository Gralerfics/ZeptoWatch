#include "applications.h"

#include "pikaScript.h"
#include "PikaVM.h"

extern PikaObj *MainPikaObj;

int Application_RunningExisted = 0;
char Application_RunningFilePath[30];

int Applications_IsRunningApplicationExisted() {
	return Application_RunningExisted;
}

char* Applications_GetRunningApplicationPath() {
	return Application_RunningFilePath;
}

void Applications_SetRunningApplicationExisted(int val) {
	Application_RunningExisted = val;
}

void Applications_SetRunningApplicationPath(const char *filepath) {
	sprintf(Application_RunningFilePath, "%s", filepath);
}

void Applications_ActivateApplication(const char *filepath) {
	Applications_SetRunningApplicationPath(filepath);
	Applications_SetRunningApplicationExisted(1);
}

void Applications_HaltCurrentApplication() {
	Applications_SetRunningApplicationExisted(0);
	pks_vm_exit();
	Debug_Printf("PKS_VM_EXIT() Called.\n");
}

void Application_ExecuteFromFS(const char *filepath) {
	BYTE ReadBuffer[1024];
	UINT fnum;
	retUSER = f_open(&USERFile, filepath,FA_OPEN_EXISTING | FA_READ);
	if (retUSER == FR_OK) {
		retUSER = f_read(&USERFile, ReadBuffer, sizeof(ReadBuffer), &fnum);
		if (retUSER == FR_OK) {
			Debug_Printf("Contents:\n%s\n", (char *) ReadBuffer);
		} else {
			Debug_Printf("Read File: %d\n", retUSER);
		}
	} else {
		Debug_Printf("Open File: %d\n", retUSER);
	}
	osDelay(500);
	f_close(&USERFile);
	Debug_Printf("File Closed.\n");

	obj_run(MainPikaObj, (char *) ReadBuffer);
}
