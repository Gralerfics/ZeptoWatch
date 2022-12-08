#include "kalman.h"

#include <cmath>
#include <cstdio>

#include "mpu6050.h"
#include "delay.h"

#define PI 3.14159f

static AngleGyro_TypeDef  __attribute__((aligned(4))) ag_t;		//包含原始数据、角速度、角度

static Kalman_TypeDef K_pitch;
static Kalman_TypeDef K_roll;
static Kalman_TypeDef K_yaw;

static short gx_err;	//零点漂移值
static short gy_err;
static short gz_err;

static const float Q_angle=0.001f;  		//角度过程噪声协方差
static const float Q_gyro=0.003f;				//角速度过程噪声协方差
static const float R_angle=0.5f;				//预测模型噪声协方差
static const float dt=0.005f;	          //kalman滤波器采样时间
static const char  C_0 = 1;

//初始化卡尔曼滤波器参数
void Kalman_Init(void)
{
	K_pitch.Pdot[0] = 0;
	K_pitch.Pdot[1] = 0;
	K_pitch.Pdot[2] = 0;
	K_pitch.Pdot[3] = 0;

	K_pitch.PP[0][0] = 1;
	K_pitch.PP[0][1] = 0;
	K_pitch.PP[1][0] = 0;
	K_pitch.PP[1][1] = 1;

	K_roll.Pdot[0] = 0;
	K_roll.Pdot[1] = 0;
	K_roll.Pdot[2] = 0;
	K_roll.Pdot[3] = 0;

	K_roll.PP[0][0] = 1;
	K_roll.PP[0][1] = 0;
	K_roll.PP[1][0] = 0;
	K_roll.PP[1][1] = 1;
}

static float Kalman_Filter(Kalman_TypeDef *k_p, float angle_a, float gyro)
{
	Kalman_TypeDef *k_t = k_p;

	k_t->Gyro = gyro / 16.384f;

	k_t->Angle += (k_t->Gyro - k_t->Q_bias) * dt; //先验估计

	k_t->Pdot[0] = Q_angle - k_t->PP[0][1] - k_t->PP[1][0];  // Pk-先验估计误差协方差的微分

	k_t->Pdot[1] = -(k_t->PP[1][1]);
	k_t->Pdot[2] = -(k_t->PP[1][1]);
	k_t->Pdot[3] = Q_gyro;

	k_t->PP[0][0] += k_t->Pdot[0] * dt;   // Pk-先验估计误差协方差微分的积分
	k_t->PP[0][1] += k_t->Pdot[1] * dt;   // =先验估计误差协方差
	k_t->PP[1][0] += k_t->Pdot[2] * dt;
	k_t->PP[1][1] += k_t->Pdot[3] * dt;

	k_t->Angle_err = angle_a - k_t->Angle;

//zk-先验估计

	k_t->PCt_0 = C_0 * k_t->PP[0][0];
	k_t->PCt_1 = C_0 * k_t->PP[1][0];

	k_t->E = R_angle + C_0 * k_t->PCt_0;

	k_t->K_0 = k_t->PCt_0 / k_t->E;
	k_t->K_1 = k_t->PCt_1 / k_t->E;

	k_t->t_0 = k_t->PCt_0;
	k_t->t_1 = C_0 * k_t->PP[0][1];

	k_t->PP[0][0] -= k_t->K_0 * k_t->t_0;

	//后验估计误差协方差
	k_t->PP[0][1] -= k_t->K_0 * k_t->t_1;
	k_t->PP[1][0] -= k_t->K_1 * k_t->t_0;
	k_t->PP[1][1] -= k_t->K_1 * k_t->t_1;

	k_t->Angle += k_t->K_0 * k_t->Angle_err;
	//后验估计
	k_t->Q_bias  += k_t->K_1 * k_t->Angle_err; //后验估计
	k_t->Gyro   = k_t->Gyro - k_t->Q_bias;
	//输出值(后验估计)角
	return  k_t->Angle;
}

//测试陀螺仪零点漂移
void GyroErr_Test(void)
{
	int32_t t_gx = 0;
	int32_t t_gy = 0;
	int32_t t_gz = 0;
	uint32_t i;

	for(i=0; i<500; i++)
	{
		MPU_Get_Gyroscope(&ag_t.imu_d.gx, &ag_t.imu_d.gy, &ag_t.imu_d.gz);
		t_gx += ag_t.imu_d.gx;
		t_gy += ag_t.imu_d.gy;
		t_gz += ag_t.imu_d.gz;
		Delay_ms(4);
	}
	gx_err = t_gx / 500;
	gy_err = t_gy / 500;
	gz_err = t_gz / 500;
}

void Update_Angle_Gyrox(void)
{
	MPU_Get_Accelerometer(&ag_t.imu_d.ax, &ag_t.imu_d.ay, &ag_t.imu_d.az);	//获取加速度原始数据
	//计算y轴角度
	ag_t.pitch = atan2(ag_t.imu_d.ay, ag_t.imu_d.az) * 180 / PI;
	ag_t.roll = atan2(ag_t.imu_d.ax, ag_t.imu_d.az) * 180 / PI;

//	MPU_Get_Magnetometer(&ag_t.imu_d.mx, &ag_t.imu_d.my, &ag_t.imu_d.mz);	//获取磁力计数据

//	ag_t.yaw = atan2(ag_t.imu_d.my - 50, -(ag_t.imu_d.mx + 32)) * 180 / PI;		//计算角度,减去了圆心硬铁漂移50和-30

//	if(ag_t.yaw < 0)		//将-180到180转换成0到360
//		ag_t.yaw = (int16_t)ag_t.yaw + 360;
//	ag_t.yaw = 360 -(int16_t)ag_t.yaw;

	 MPU_Get_Gyroscope(&ag_t.imu_d.gx, &ag_t.imu_d.gy, &ag_t.imu_d.gz);	//获取角速度原始数据

	 ag_t.pitch = Kalman_Filter(&K_pitch, ag_t.pitch, -ag_t.imu_d.gx);		//卡尔曼滤波计算倾角
	 ag_t.roll = Kalman_Filter(&K_roll, ag_t.roll, ag_t.imu_d.gy);		//卡尔曼滤波计算倾角
}

//获取姿态数据结构体
AngleGyro_TypeDef* Get_Angle_GyroxStructure(void)
{
	return &ag_t;
}
