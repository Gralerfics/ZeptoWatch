#ifndef __MSM261S_H
#define __MSM261S_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

void Microphone_StartSampling();
void Microphone_StopSampling();

int Microphone_GetSampleData();

#ifdef __cplusplus
}
#endif

#endif
