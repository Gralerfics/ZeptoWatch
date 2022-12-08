#ifndef __KALMAN_H
#define __KALMAN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"

typedef struct {
	float Angle;         //最优角度
	float Gyro;        //最优角速度

	float Q_bias, Angle_err;
	float PCt_0, PCt_1, E;
	float K_0, K_1, t_0, t_1;
	float Pdot[4];
	float PP[2][2];        //误差协方差矩阵
} Kalman_TypeDef;

typedef struct {
	int16_t gx;        //陀螺仪原始数据
	int16_t gy;
	int16_t gz;

	int16_t ax;        //加速度计原始数据
	int16_t ay;
	int16_t az;

//	int16_t mx;        //磁力计原始数据
//	int16_t my;
//	int16_t mz;
} IMUData_TypeDef;


typedef struct {
	IMUData_TypeDef imu_d __attribute__((aligned(4)));        //原始数据

	float gyrox;    //量程转换后的陀螺仪数据
	float gyroy;
	float gyroz;

	float pitch;    //各轴的倾角
	float roll;
	float yaw;
} AngleGyro_TypeDef;

void Kalman_Init(void);
void GyroErr_Test(void);
void Update_Angle_Gyrox(void);
AngleGyro_TypeDef *Get_Angle_GyroxStructure(void);

#ifdef __cplusplus
}
#endif

#endif
