#ifndef __POWER_H
#define __POWER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

int Power_GetState();
void Power_SetState(int state);

#ifdef __cplusplus
}
#endif

#endif
