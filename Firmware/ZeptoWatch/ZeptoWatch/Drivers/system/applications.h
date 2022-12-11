#ifndef __APPLICATIONS_H
#define __APPLICATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

int Applications_IsRunning();
char* Applications_GetApplicationPath();

void Applications_ActivateApplication(const char *filepath);
void Applications_HaltApplication();

void Application_ExecuteFromFS(const char *filepath);

#ifdef __cplusplus
}
#endif

#endif
