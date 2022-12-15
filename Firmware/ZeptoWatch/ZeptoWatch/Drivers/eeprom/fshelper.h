#ifndef __FSHELPER_H
#define __FSHELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "m24512.h"
#include "applications.h"

#define FSHELPER_READBUFFER_SIZE 4096

extern BYTE ReadBuffer[FSHELPER_READBUFFER_SIZE];

void FS_Mount();
void FS_ScanFolder(const char *dirpath, int *num, Application_Info_Type *fileInfos);
void FS_ReadFile(const char *filepath);

void FS_Clear();
void FS_Make();
void FS_WriteTestFile();

#ifdef __cplusplus
}
#endif

#endif
