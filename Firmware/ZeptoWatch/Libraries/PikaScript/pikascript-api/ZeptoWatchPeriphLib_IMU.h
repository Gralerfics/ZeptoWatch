/*
 * [Warning!] This file is auto-generated by pika compiler.
 * Do not edit it manually.
 * The source code is *.pyi file.
 * More details: 
 * English Doc:
 * https://pikadoc.readthedocs.io/en/latest/PikaScript%20%E6%A8%A1%E5%9D%97%E6%A6%82%E8%BF%B0.html
 * Chinese Doc:
 * https://pikadoc.readthedocs.io/zh/latest/PikaScript%20%E6%A8%A1%E5%9D%97%E6%A6%82%E8%BF%B0.html
 */

#ifndef __ZeptoWatchPeriphLib_IMU__H
#define __ZeptoWatchPeriphLib_IMU__H
#include <stdio.h>
#include <stdlib.h>
#include "PikaObj.h"

PikaObj *New_ZeptoWatchPeriphLib_IMU(Args *args);

PikaObj* ZeptoWatchPeriphLib_IMU_getAccelerometer(PikaObj *self);
PikaObj* ZeptoWatchPeriphLib_IMU_getGyroscope(PikaObj *self);
int ZeptoWatchPeriphLib_IMU_getTemperature(PikaObj *self);
void ZeptoWatchPeriphLib_IMU_initialize(PikaObj *self);

#endif
