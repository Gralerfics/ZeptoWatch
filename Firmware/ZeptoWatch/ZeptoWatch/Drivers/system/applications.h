#ifndef __APPLICATIONS_H
#define __APPLICATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

#include "ui_user.h"
#include "ui_helpers_user.h"

#define APPLICATION_SCAN_HEADER

#define APPLICATION_MAX 24
#define APPLICATION_PATH_MAXLEN 30
#define APPLICATION_NAME_MAXLEN 30

extern lv_obj_t* Application_LVIcons[APPLICATION_MAX];
extern lv_obj_t* Application_LVLabels[APPLICATION_MAX];

typedef struct {
	char path[APPLICATION_PATH_MAXLEN];
	char name[APPLICATION_NAME_MAXLEN];
	lv_img_dsc_t *icon;
	uint32_t color;
	int isBuiltIn;
} Application_Info_Type;

void Applications_Scan();
void Applications_ScanBuiltIns();
int Applications_GetAppNumber();
char* Applications_GetAppName(int index);
char* Applications_GetAppPath(int index);
lv_img_dsc_t* Applications_GetAppIcon(int index);
uint32_t Applications_GetAppColor(int index);
int Applications_GetAppBuiltIn(int index);

int Applications_IsRunning();
int Applications_IsBuiltIn();
char* Applications_GetApplicationPath();

void Applications_ActivateApplication(const char *filepath, int isBuiltIn);
void Applications_HaltApplication();

void Application_ExecuteFromFS(const char *filepath);
void Application_ExecuteFromBuiltins(const char *appPath);

#ifdef __cplusplus
}
#endif

#endif
