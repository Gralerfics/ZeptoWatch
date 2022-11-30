#include "cmsis_os.h"

#include <stdio.h>

#include "mpu6050.h"
#include "ui.h"

#ifdef __cplusplus
extern "C" {
#endif

void StartImuTask(void const * argument) {
//	MPU_Initialize();

	int ax = 0; //, ay, az, gx, gy, gz, t;
	for (;;) {

//		MPU_Get_Accelerometer(&ax, &ay, &az);
//		MPU_Get_Gyroscope(&gx, &gy, &gz);
//		t = MPU_Get_Temperature();

//		sprintf(txt, "A (g): %.2f, %.2f, %.2f.\nG (dps): %.2f, %.2f, %.2f.\nT: %.2f.",
//				ax / 32768.0 * 2, ay / 32768.0 * 2, az / 32768.0 * 2,
//				gx / 32768.0 * 2000, gy / 32768.0 * 2000, gz / 32768.0 * 2000,
//				t / 100.0);
//		sprintf(txt, "%d, %d, %d.\n%d, %d, %d.\n%d.", ax, ay, az, gx, gy, gz, t);

		ax ++;
		if (ax > 10000) ax = 0;

		char txt[5];
		txt[4] = ax % 10 + '0';
		txt[3] = ax / 10 % 10 + '0';
		txt[2] = ax / 100 % 10 + '0';
		txt[1] = ax / 1000 % 10 + '0';
		txt[0] = ax / 10000 % 10 + '0';
		lv_label_set_text(ui_label, txt);

		osDelay(100);
	}
}

#ifdef __cplusplus
}
#endif
