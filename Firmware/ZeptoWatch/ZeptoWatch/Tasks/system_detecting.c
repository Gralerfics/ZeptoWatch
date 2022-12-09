#include "cmsis_os.h"

#include "stdio.h"
#include "usart.h"
#include "battery.h"
#include "bt11.h"
#include "ui.h"

#include "m24512.h"
#include "fatfs.h"

#include "tim.h"
#include "fatfs.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "pikaScript.h"

#include "ui.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

extern PikaObj *MainPikaObj;

void WaitFor3Seconds() {
	osDelay(1000);
	lv_label_set_text(ui_Screen1_Label1, "3");
	osDelay(1000);
	lv_label_set_text(ui_Screen1_Label1, "2");
	osDelay(1000);
	lv_label_set_text(ui_Screen1_Label1, "1");
	osDelay(1000);
}

void MountFS() {
	FRESULT retUSER;
	FATFS USERFatFS;
	char Path[4] = "0:/";

	lv_label_set_text(ui_Screen1_Label1, "Ready.");
	printf("Ready.");
	osDelay(500);

	retUSER = f_mount(&USERFatFS, Path, 1);
	if (retUSER != FR_OK) {
		char txt[2];
		sprintf(txt, "Mounts: %d", retUSER);
		lv_label_set_text(ui_Screen1_Label1, txt);
		while (1) { osDelay(1); }
	} else {
		lv_label_set_text(ui_Screen1_Label1, "Mounted.");
		printf("Mounted.");
	}
	osDelay(500);
}

void WriteProgram() {
	FRESULT retUSER;
	FATFS USERFatFS;
	UINT fnum;
	BYTE WriteBuffer[] = "import PikaStdLib as std\n"
						 "import ZeptoWatchStdLib as zws\n"
						 "import ZeptoWatchPeriphLib as zwp\n"
						 "\n"
						 "\n"
						 "i = 10\n"
						 "j = 1\n"
						 "while 1 == 1:\n"
						 "    zws.Display.setBrightness(i)\n"
						 "    if i >= 90:\n"
						 "        j = -1\n"
						 "    if i <= 10:\n"
						 "        j = 1\n"
						 "    i = i + j\n"
						 "\n"
						 "    k = zwp.IMU.getTemperature()\n"
						 "    print(k)\n"
						 "\n"
						 "    zws.System.delayMs(30)\n";

	retUSER = f_open(&USERFile, "main.py", FA_CREATE_ALWAYS | FA_WRITE);
	if (retUSER == FR_OK) {
		retUSER = f_write(&USERFile, WriteBuffer, sizeof(WriteBuffer), &fnum);
		if (retUSER == FR_OK) {
			lv_label_set_text(ui_Screen1_Label1, "File Created.");
			printf("File Created.");
		} else {
			char txt[2];
			sprintf(txt, "Create File: %d", retUSER);
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
}

void ExecuteProgram() {
	FRESULT retUSER;
	FATFS USERFatFS;
	BYTE ReadBuffer[1024];
	UINT fnum;
	char Path[4] = "0:/";
	retUSER = f_open(&USERFile, "main.py",FA_OPEN_EXISTING | FA_READ);
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
	lv_label_set_text(ui_Screen1_Label1, "Executed.");
	printf("Executed.");
}

void StartSystemDetecting(void const * argument) {
//  /* 清除引导扇区 */
//	ROM_Init();
//	lv_label_set_text(ui_Screen1_Label1, "Clear.");
//	uint8_t wwbuf[1024] = {0};
//	ROM_Write_Bytes(wwbuf, 0x0000, 1024);
//	lv_label_set_text(ui_Screen1_Label1, "Cleared.");
//	osDelay(1000);

	WaitFor3Seconds();
	MountFS();
//	WriteProgram();
	WaitFor3Seconds();
	ExecuteProgram();

	while (1) {
		osDelay(5);
	}
}

#ifdef __cplusplus
}
#endif
