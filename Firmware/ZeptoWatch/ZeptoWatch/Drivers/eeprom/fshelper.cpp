#include "fshelper.h"

#include "fatfs.h"

void FS_Mount() {
	retUSER = f_mount(&USERFatFS, "0:", 1);
	if (retUSER != FR_OK) {
		Debug_Printf("Mount: %d\n", retUSER);
	} else {
		Debug_Printf("Mounted.\n");
	}
}

void FS_ScanFolder(const char *path, char *names) {
	DIR dir;
	FILINFO fileInfo;
	int is_first_file = 1;
	Debug_Printf("Dir Opening.\n");
	retUSER = f_opendir(&dir, path);
	if (retUSER == FR_OK) {
		Debug_Printf("Dir Scanning.\n");
		for (;;) {
			retUSER = f_readdir(&dir, &fileInfo);
			if (retUSER != FR_OK || fileInfo.fname[0] == 0) break;
			if (!(fileInfo.fattrib & AM_DIR)) {
				if (is_first_file) {
					Debug_Printf("Find %s.\n", fileInfo.fname);
					sprintf(names, "%s", fileInfo.fname);
					is_first_file = 0;
				} else {
					sprintf(names, "%s\n%s", names, fileInfo.fname);
				}
			}
		}
	} else {
		char errCode[2];
		Debug_Printf(errCode, "Open Dir: %d\n", retUSER);
	}
	f_closedir(&dir);
	Debug_Printf("Dir Closed.\n");
}

void FS_ClearAll() {
	Debug_Printf("Clear.\n");
	uint8_t buf[1024] = {0};
	ROM_Write_Bytes(buf, 0x0000, 1024);
	Debug_Printf("Cleared.\n");
}

void FS_Make() {
	FS_Mount();

	BYTE ReadBuffer[2048];
	if (retUSER == FR_NO_FILESYSTEM) {
		Debug_Printf("No FS. Making FS.\n");
		retUSER = f_mkfs("0:", FM_FAT, 512, ReadBuffer, 2048);
		if (retUSER == FR_OK) {
			Debug_Printf("FS Made.\n");
			retUSER = f_mount(NULL, "0:", 1);
			retUSER = f_mount(&USERFatFS, "0:", 1);
			Debug_Printf("Remounted.\n");
		} else {
			Debug_Printf("Make FS: %d\n", retUSER);
		}
	}
}

void FS_WriteFile() {
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

	retUSER = f_open(&USERFile, "0:test.py", FA_CREATE_ALWAYS | FA_WRITE);
	if (retUSER == FR_OK) {
		retUSER = f_write(&USERFile, WriteBuffer, sizeof(WriteBuffer), &fnum);
		if (retUSER == FR_OK) {
			Debug_Printf("File Created.\n");
		} else {
			Debug_Printf("Create File: %d\n", retUSER);
		}
	} else {
		Debug_Printf("Open File: %d\n", retUSER);
	}
	f_close(&USERFile);
}
