#include "pikaScript.h"

#include "mpu6050.h"

void ZeptoWatchPeriphLib_IMU_initialize(PikaObj *self) {
	MPU_Initialize();
}

int ZeptoWatchPeriphLib_IMU_getTemperature(PikaObj *self) {
	return (int) MPU_Get_Temperature();
}
