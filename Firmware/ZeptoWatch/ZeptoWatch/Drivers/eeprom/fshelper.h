#ifndef __FSHELPER_H
#define __FSHELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "m24512.h"

#define FSHELPER_READBUFFER_SIZE 8192

extern BYTE ReadBuffer[FSHELPER_READBUFFER_SIZE];

void FS_Mount();
void FS_ScanFolder(const char *path, char* names);

void FS_ClearAll();
void FS_Make();
void FS_WriteFile();

#ifdef __cplusplus
}
#endif

#endif
