#ifndef __APP_LOADER_H
#define __APP_LOADER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char * appName;
} APP_Info_Structure;

APP_Info_Structure * Get_App_Info();

#ifdef __cplusplus
}
#endif

#endif
