#include "pikaScript.h"
#include "PikaStdData_List.h"

#include "mpu6050.h"

void ZeptoWatchPeriphLib_IMU_initialize(PikaObj *self) {
	MPU_Initialize();
}

int ZeptoWatchPeriphLib_IMU_getTemperature(PikaObj *self) {
	return (int) MPU_Get_Temperature();
}

PikaObj* ZeptoWatchPeriphLib_IMU_getAccelerometer(PikaObj *self) {
	PikaObj *list = newNormalObj(New_PikaStdData_List);
	PikaStdData_List___init__(list);

	short ax, ay, az;
	MPU_Get_Accelerometer(&ax, &ay, &az);
	Arg *str_arg_ax = arg_newInt(ax);
	Arg *str_arg_ay = arg_newInt(ay);
	Arg *str_arg_az = arg_newInt(az);
	PikaStdData_List_append(list, str_arg_ax);
	PikaStdData_List_append(list, str_arg_ay);
	PikaStdData_List_append(list, str_arg_az);
	arg_deinit(str_arg_ax);
	arg_deinit(str_arg_ay);
	arg_deinit(str_arg_az);

	return list;
}

PikaObj* ZeptoWatchPeriphLib_IMU_getGyroscope(PikaObj *self) {
	PikaObj *list = newNormalObj(New_PikaStdData_List);
	PikaStdData_List___init__(list);

	short gx, gy, gz;
	MPU_Get_Gyroscope(&gx, &gy, &gz);
	Arg *str_arg_gx = arg_newInt(gx);
	Arg *str_arg_gy = arg_newInt(gy);
	Arg *str_arg_gz = arg_newInt(gz);
	PikaStdData_List_append(list, str_arg_gx);
	PikaStdData_List_append(list, str_arg_gy);
	PikaStdData_List_append(list, str_arg_gz);
	arg_deinit(str_arg_gx);
	arg_deinit(str_arg_gy);
	arg_deinit(str_arg_gz);

	return list;
}
