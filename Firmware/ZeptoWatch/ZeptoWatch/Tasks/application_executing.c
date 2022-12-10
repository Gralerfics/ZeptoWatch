#include "cmsis_os.h"

#include "stdio.h"

#include "fatfs.h"

#include "lvgl.h"
#include "pikaScript.h"

#include "ui.h"

#ifdef __cplusplus
extern "C" {
#endif

extern PikaObj *MainPikaObj;

int RunningApplicationExisted = 0;
char RunningApplicationName[20];

void ExecuteProgram(char *fileName) {
	BYTE ReadBuffer[1024];
	UINT fnum;
	char filePath[20];
	sprintf(filePath, "0:%s", fileName);

	retUSER = f_open(&USERFile, filePath,FA_OPEN_EXISTING | FA_READ);
	if (retUSER == FR_OK) {
		retUSER = f_read(&USERFile, ReadBuffer, sizeof(ReadBuffer), &fnum);
		if (retUSER == FR_OK) {
			lv_label_set_text(ui_Screen1_Label1, (char *) ReadBuffer);
			printf((char *) ReadBuffer);
		} else {
			char txt[2];
			sprintf(txt, "Read File: %d", retUSER);
			lv_label_set_text(ui_Screen1_Label1, txt);
			while (1) { osDelay(1); }
		}
	} else {
		char txt[2];
		sprintf(txt, "Open File: %d", retUSER);
		lv_label_set_text(ui_Screen1_Label1, txt);
		while (1) { osDelay(1); }
	}
	osDelay(500);
	f_close(&USERFile);

	obj_run(MainPikaObj, (char *) ReadBuffer);
}

void StartApplicationExecuting(void const * argument) {
	for (;;) {
		if (RunningApplicationExisted) {
			ExecuteProgram(RunningApplicationName);
		}

		osDelay(10);
	}
}

#ifdef __cplusplus
}
#endif
