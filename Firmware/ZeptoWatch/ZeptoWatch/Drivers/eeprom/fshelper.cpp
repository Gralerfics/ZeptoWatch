#include "fshelper.h"

#include "fatfs.h"

BYTE ReadBuffer[FSHELPER_READBUFFER_SIZE] __attribute__((section(".ccmram"))) = {0};

void FS_Mount() {
	retUSER = f_mount(&USERFatFS, "0:", 1);
	if (retUSER != FR_OK) {
		Debug_Printf("Mount Error: %d\n", retUSER);
	} else {
		Debug_Printf("Mounted.\n");
	}
}

void FS_ScanFolder(const char *dirpath, int *num, Application_Info_Type *fileInfos) {
	DIR dir;
	FILINFO fileInfo;

	Debug_Printf("Dir Opening.\n");
	retUSER = f_opendir(&dir, dirpath);
	if (retUSER == FR_OK) {
		Debug_Printf("Dir Scanning:\n");
		(*num) = 0;
		for (;;) {
			retUSER = f_readdir(&dir, &fileInfo);
			if (retUSER != FR_OK || fileInfo.fname[0] == 0) break;
			if (!(fileInfo.fattrib & AM_DIR)) {
				Debug_Printf("\tFind %s.\n", fileInfo.fname);
				sprintf(fileInfos[(*num) ++].path, "%s%s", dirpath, fileInfo.fname);
			}
			osDelay(5);
		}
	} else {
		(*num) = -1;
		char errCode[2];
		Debug_Printf(errCode, "Open Dir Error: %d\n", retUSER);
	}
	f_closedir(&dir);
	Debug_Printf("Dir Closed.\n");
}

void FS_ReadFile(const char *filepath) {
	Debug_Printf("Read File.\n");
	UINT fnum;
	osDelay(500);
	retUSER = f_open(&USERFile, filepath,FA_OPEN_EXISTING | FA_READ);
	if (retUSER == FR_OK) {
		retUSER = f_read(&USERFile, ReadBuffer, FSHELPER_READBUFFER_SIZE, &fnum);
		if (retUSER == FR_OK) {
			Debug_Printf("Contents:\n====================\n%s\n====================\n", (char *) ReadBuffer);
		} else {
			Debug_Printf("Read File Error: %d\n", retUSER);
		}
	} else {
		Debug_Printf("Open File Error: %d\n", retUSER);
	}
	f_close(&USERFile);
	Debug_Printf("File Closed.\n");
}

void FS_Clear() {
	Debug_Printf("Clear.\n");
	uint8_t buf[1024] = {0};
	ROM_Write_Bytes(buf, 0x0000, 1024);
	Debug_Printf("Cleared.\n");
}

void FS_Make() {
	// 创建文件系统时记得去 ff.c 注释掉 "< 128" 所在处的某两行，否则无法对如此小的空间建立文件系统。
	FS_Mount();

	if (retUSER == FR_NO_FILESYSTEM) {
		Debug_Printf("No FS. Making FS.\n");
		retUSER = f_mkfs("0:", FM_FAT, 512, ReadBuffer, 8192);
		if (retUSER == FR_OK) {
			Debug_Printf("FS Made.\n");
			retUSER = f_mount(NULL, "0:", 1);
			retUSER = f_mount(&USERFatFS, "0:", 1);
			Debug_Printf("Remounted.\n");
		} else {
			Debug_Printf("Make FS Error: %d\n", retUSER);
		}
	}
}

void FS_WriteTestFile() {
	UINT fnum;
	BYTE WriteBuffer[] = "###ICON=check;NAME=UITest;COLOR=23751314###\n"
						 "import PikaStdLib as std\n"
						 "import pika_lvgl as lv\n"
						 "import ZeptoWatchStdLib as zws\n"
						 "import ZeptoWatchPeriphLib as zwp\n"
						 "\n"
						 "lb1 = lv.label(lv.scr_act())\n"
						 "btn1 = lv.btn(lv.scr_act())\n"
						 "\n"
						 "def event_cb_1(evt):\n"
						 "    lb1.set_text('EVT 1.')\n"
						 "    print('EVT 1.')\n"
						 "\n"
						 "btn1.align(lv.ALIGN.CENTER, 0, 10)\n"
						 "btn1.set_width(50)\n"
						 "btn1.set_height(50)\n"
						 "btn1.add_event_cb(event_cb_1, lv.EVENT.CLICKED, 0)\n"
						 "lb1.set_width(150)\n"
						 "lb1.align(lv.ALIGN.TOP_MID, 0, 40)\n"
						 "lb1.set_text('Test.')\n"
						 "\n"
						 "while 1 == 1:\n"
						 "    zws.System.delayMs(5)\n"
						 "\n"
						 "###END###";

	retUSER = f_open(&USERFile, "0:lvtest.py", FA_CREATE_ALWAYS | FA_WRITE);
	if (retUSER == FR_OK) {
		retUSER = f_write(&USERFile, WriteBuffer, sizeof(WriteBuffer), &fnum);
		if (retUSER == FR_OK) {
			Debug_Printf("File Created.\n");
		} else {
			Debug_Printf("Create File Error: %d\n", retUSER);
		}
	} else {
		Debug_Printf("Open File Error: %d\n", retUSER);
	}
	f_close(&USERFile);
}
