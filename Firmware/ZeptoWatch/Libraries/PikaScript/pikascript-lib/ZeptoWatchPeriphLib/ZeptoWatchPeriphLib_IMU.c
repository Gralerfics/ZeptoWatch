#include "pikaScript.h"

#include "mpu6050.h"

int ZeptoWatchPeriphLib_IMU_getTemperature(PikaObj *self) {
	return (int) MPU_Get_Temperature();
}
