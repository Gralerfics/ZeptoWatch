#include "cmsis_os.h"

#include "stdio.h"

#include "fatfs.h"

#include "lvgl.h"
#include "PikaVM.h"

#include "ui.h"
#include "m24512.h"

#ifdef __cplusplus /* 为了在 .cpp 中覆写 .c 中的 __weak 函数需要在 extern "C" 中声明, 方能被 .c 文件索引到. */
extern "C" {
#endif

void WaitFor3Seconds() {
	osDelay(1000);
	lv_label_set_text(ui_Screen1_Label1, "3");
	osDelay(1000);
	lv_label_set_text(ui_Screen1_Label1, "2");
	osDelay(1000);
	lv_label_set_text(ui_Screen1_Label1, "1");
	osDelay(1000);
}

void ClearAll() {
	lv_label_set_text(ui_Screen1_Label1, "Clear.");
	printf("Clear.");
	uint8_t wwbuf[1024] = {0};
	ROM_Write_Bytes(wwbuf, 0x0000, 1024);
	lv_label_set_text(ui_Screen1_Label1, "Cleared.");
	printf("Cleared.");
	osDelay(1000);
}

void MakeFS() {
	BYTE ReadBuffer[2048];

	retUSER = f_mount(&USERFatFS, "0:", 1);
	lv_label_set_text(ui_Screen1_Label1, "Mounted.");
	printf("Mounted.");
	osDelay(200);
	if (retUSER == FR_NO_FILESYSTEM) {
		lv_label_set_text(ui_Screen1_Label1, "No FS. Make FS.");
		printf("No FS. Make FS.");
		retUSER = f_mkfs("0:", FM_FAT, 512, ReadBuffer, 2048);
		if (retUSER == FR_OK) {
			lv_label_set_text(ui_Screen1_Label1, "FS Made.");
			printf("FS Made.");
			retUSER = f_mount(NULL, "0:", 1);
			retUSER = f_mount(&USERFatFS, "0:", 1);
		} else {
			char txt[2];
			sprintf(txt, "Make FS: %d", retUSER);
			lv_label_set_text(ui_Screen1_Label1, txt);
			while (1) { osDelay(1); }
		}
	}
}

void MountFS() {
	lv_label_set_text(ui_Screen1_Label1, "Ready.");
	printf("Ready.");
	osDelay(500);

	retUSER = f_mount(&USERFatFS, "0:", 1);
	if (retUSER != FR_OK) {
		char txt[2];
		sprintf(txt, "Mount: %d", retUSER);
		lv_label_set_text(ui_Screen1_Label1, txt);
		while (1) { osDelay(1); }
	} else {
		lv_label_set_text(ui_Screen1_Label1, "Mounted.");
		printf("Mounted.");
	}
	osDelay(500);
}

void WriteProgram() {
	UINT fnum;
	BYTE WriteBuffer[] = "import PikaStdLib as std\n"
						 "import ZeptoWatchStdLib as zws\n"
						 "import ZeptoWatchPeriphLib as zwp\n"
						 "\n"
						 "zwp.IMU.initialize()\n"
						 "\n"
						 "i = 5\n"
						 "j = 1\n"
						 "while 1 == 1:\n"
						 "    zws.Display.setBrightness(i)\n"
						 "    if i >= 95:\n"
						 "        j = -1\n"
						 "    if i <= 5:\n"
						 "        j = 1\n"
						 "    i = i + j\n"
						 "\n"
						 "    k = zwp.IMU.getTemperature()\n"
						 "    print(k)\n"
						 "\n"
						 "    zws.System.delayMs(30)\n";

	retUSER = f_open(&USERFile, "0:main.py", FA_CREATE_ALWAYS | FA_WRITE);
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

static int btn1ClickedFlag = 0, btn2ClickedFlag = 0;

void btn1Clicked(lv_event_t * e) {
	btn1ClickedFlag = 1;
}

void btn2Clicked(lv_event_t * e) {
	btn2ClickedFlag = 1;
}

void StartSystemDetecting(void const * argument) {
//	WaitFor3Seconds();
//	ClearAll();
//	MakeFS();
//	WaitFor3Seconds();
//	MountFS();
//	WriteProgram();
//	WaitFor3Seconds();
//	ExecuteProgram("main.py");

//	WaitFor3Seconds();
	MountFS();

	DIR dir;
	FILINFO fileInfo;
	char names[200] = {0};
	int first_file = 1;
	lv_label_set_text(ui_Screen1_Label1, "Scanning ...");
	lv_label_set_text(ui_Screen1_Label1, "Scanning ... Open Dir.");
	retUSER = f_opendir(&dir, "0:");
	if (retUSER == FR_OK) {
		for (;;) {
			retUSER = f_readdir(&dir, &fileInfo);
			if (retUSER != FR_OK || fileInfo.fname[0] == 0) break;
			if (!(fileInfo.fattrib & AM_DIR)) {
				if (first_file) {
					sprintf(names, "%s", fileInfo.fname);
					first_file = 0;
				} else {
					sprintf(names, "%s\n%s", names, fileInfo.fname);
				}
			}
		}
	} else {
		char txt[2];
		sprintf(txt, "Open Dir: %d", retUSER);
		lv_label_set_text(ui_Screen1_Label1, txt);
		while (1) { osDelay(1); }
	}
	f_closedir(&dir);
	lv_label_set_text(ui_Screen1_Label1, "Over.");

	lv_roller_set_options(ui_Screen1_Roller1, names, LV_ROLLER_MODE_NORMAL);

	while (1) {
		extern char RunningApplicationName[20];
		extern int RunningApplicationExisted;

		if (btn1ClickedFlag) {
			char name[20] = {0};
			lv_roller_get_selected_str(ui_Screen1_Roller1, name, 20);
			lv_label_set_text(ui_Screen1_Label1, name);

			sprintf(RunningApplicationName, "%s", name);
			RunningApplicationExisted = 1;

			btn1ClickedFlag = 0;
		}

		if (btn2ClickedFlag) {
			RunningApplicationExisted = 0;
			pks_vm_exit();

			lv_label_set_text(ui_Screen1_Label1, "PKS_VM_EXIT().");

			btn2ClickedFlag = 0;
		}

		osDelay(10);
	}
}

#ifdef __cplusplus
}
#endif
