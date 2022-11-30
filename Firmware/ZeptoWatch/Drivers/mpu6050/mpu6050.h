#ifndef __MPU6050_H
#define __MPU6050_H

#include "common.h"
//#include "mpuiic.h"

/*
 * IMU_SCL -> PB8
 * IMU_SDA -> PB9
 */

#define __HAL_RCC_IMU_I2C_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define IMU_I2C_PORT GPIOB
#define IMU_SCL_PIN GPIO_PIN_8
#define IMU_SDA_PIN GPIO_PIN_9

#define IMU_SCL_SET_0 HAL_GPIO_WritePin(IMU_I2C_PORT, IMU_SCL_PIN, GPIO_PIN_RESET)
#define IMU_SCL_SET_1 HAL_GPIO_WritePin(IMU_I2C_PORT, IMU_SCL_PIN, GPIO_PIN_SET)

#define IMU_SDA_SET_0 HAL_GPIO_WritePin(IMU_I2C_PORT, IMU_SDA_PIN, GPIO_PIN_RESET)
#define IMU_SDA_SET_1 HAL_GPIO_WritePin(IMU_I2C_PORT, IMU_SDA_PIN, GPIO_PIN_SET)
#define IMU_SDA_GET() HAL_GPIO_ReadPin(IMU_I2C_PORT, IMU_SDA_PIN)

/* AD0 地址控制
 *     如果 AD0 接 GND, 则从机地址为 0X68 (不含最低位), 如果接 VCC, 则地址为 0X69.
 *     读写地址为地址加一个最低位. AD0 默认接 GND, 故读写地址为 0XD1 和 0XD0 (如果接 VCC, 则为 0XD3 和 0XD2).
 * */
#define MPU_ADDR				0X68	// 从机地址
#define MPU_READ    			0XD1
#define MPU_WRITE   			0XD0

#define MPU_ACCEL_OFFS_REG		0X06	// Accel_offs 寄存器, 可读取版本号, 手册未提及
#define MPU_PROD_ID_REG			0X0C	// Prod ID 寄存器, 手册未提及
#define MPU_SELF_TESTX_REG		0X0D	// 自检寄存器 X
#define MPU_SELF_TESTY_REG		0X0E	// 自检寄存器 Y
#define MPU_SELF_TESTZ_REG		0X0F	// 自检寄存器 Z
#define MPU_SELF_TESTA_REG		0X10	// 自检寄存器 A
#define MPU_SAMPLE_RATE_REG		0X19	// 采样频率分频器
#define MPU_CFG_REG				0X1A	// 配置寄存器
#define MPU_GYRO_CFG_REG		0X1B	// 陀螺仪配置寄存器
#define MPU_ACCEL_CFG_REG		0X1C	// 加速度计配置寄存器
#define MPU_MOTION_DET_REG		0X1F	// 运动检测阀值设置寄存器
#define MPU_FIFO_EN_REG			0X23	// FIFO 使能寄存器
#define MPU_I2CMST_CTRL_REG		0X24	// IIC 主机控制寄存器
#define MPU_I2CSLV0_ADDR_REG	0X25	// IIC 从机 0 器件地址寄存器
#define MPU_I2CSLV0_REG			0X26	// IIC 从机 0 数据地址寄存器
#define MPU_I2CSLV0_CTRL_REG	0X27	// IIC 从机 0 控制寄存器
#define MPU_I2CSLV1_ADDR_REG	0X28	// IIC 从机 1 器件地址寄存器
#define MPU_I2CSLV1_REG			0X29	// IIC 从机 1 数据地址寄存器
#define MPU_I2CSLV1_CTRL_REG	0X2A	// IIC 从机 1 控制寄存器
#define MPU_I2CSLV2_ADDR_REG	0X2B	// IIC 从机 2 器件地址寄存器
#define MPU_I2CSLV2_REG			0X2C	// IIC 从机 2 数据地址寄存器
#define MPU_I2CSLV2_CTRL_REG	0X2D	// IIC 从机 2 控制寄存器
#define MPU_I2CSLV3_ADDR_REG	0X2E	// IIC 从机 3 器件地址寄存器
#define MPU_I2CSLV3_REG			0X2F	// IIC 从机 3 数据地址寄存器
#define MPU_I2CSLV3_CTRL_REG	0X30	// IIC 从机 3 控制寄存器
#define MPU_I2CSLV4_ADDR_REG	0X31	// IIC 从机 4 器件地址寄存器
#define MPU_I2CSLV4_REG			0X32	// IIC 从机 4 数据地址寄存器
#define MPU_I2CSLV4_DO_REG		0X33	// IIC 从机 4 写数据寄存器
#define MPU_I2CSLV4_CTRL_REG	0X34	// IIC 从机 4 控制寄存器
#define MPU_I2CSLV4_DI_REG		0X35	// IIC 从机 4 读数据寄存器

#define MPU_I2CMST_STA_REG		0X36	// IIC 主机状态寄存器
#define MPU_INTBP_CFG_REG		0X37	// 中断 / 旁路设置寄存器
#define MPU_INT_EN_REG			0X38	// 中断使能寄存器
#define MPU_INT_STA_REG			0X3A	// 中断状态寄存器

#define MPU_ACCEL_XOUTH_REG		0X3B	// 加速度值, X 轴高位寄存器
#define MPU_ACCEL_XOUTL_REG		0X3C	// 加速度值, X 轴低位寄存器
#define MPU_ACCEL_YOUTH_REG		0X3D	// 加速度值, Y 轴高位寄存器
#define MPU_ACCEL_YOUTL_REG		0X3E	// 加速度值, Y 轴低位寄存器
#define MPU_ACCEL_ZOUTH_REG		0X3F	// 加速度值, Z 轴高位寄存器
#define MPU_ACCEL_ZOUTL_REG		0X40	// 加速度值, Z 轴低位寄存器

#define MPU_TEMP_OUTH_REG		0X41	// 温度值高位寄存器
#define MPU_TEMP_OUTL_REG		0X42	// 温度值低位寄存器

#define MPU_GYRO_XOUTH_REG		0X43	// 陀螺仪值, X 轴高位寄存器
#define MPU_GYRO_XOUTL_REG		0X44	// 陀螺仪值, X 轴低位寄存器
#define MPU_GYRO_YOUTH_REG		0X45	// 陀螺仪值, Y 轴高位寄存器
#define MPU_GYRO_YOUTL_REG		0X46	// 陀螺仪值, Y 轴低位寄存器
#define MPU_GYRO_ZOUTH_REG		0X47	// 陀螺仪值, Z 轴高位寄存器
#define MPU_GYRO_ZOUTL_REG		0X48	// 陀螺仪值, Z 轴低位寄存器

#define MPU_I2CSLV0_DO_REG		0X63	// IIC 从机 0 数据寄存器
#define MPU_I2CSLV1_DO_REG		0X64	// IIC 从机 1 数据寄存器
#define MPU_I2CSLV2_DO_REG		0X65	// IIC 从机 2 数据寄存器
#define MPU_I2CSLV3_DO_REG		0X66	// IIC 从机 3 数据寄存器

#define MPU_I2CMST_DELAY_REG	0X67	// IIC 主机延时管理寄存器
#define MPU_SIGPATH_RST_REG		0X68	// 信号通道复位寄存器
#define MPU_MDETECT_CTRL_REG	0X69	// 运动检测控制寄存器
#define MPU_USER_CTRL_REG		0X6A	// 用户控制寄存器
#define MPU_PWR_MGMT1_REG		0X6B	// 电源管理寄存器 1
#define MPU_PWR_MGMT2_REG		0X6C	// 电源管理寄存器 2 
#define MPU_FIFO_CNTH_REG		0X72	// FIFO 计数寄存器高八位
#define MPU_FIFO_CNTL_REG		0X73	// FIFO 计数寄存器低八位
#define MPU_FIFO_RW_REG			0X74	// FIFO 读写寄存器
#define MPU_DEVICE_ID_REG		0X75	// 器件 ID 寄存器

uint8_t MPU_Initialize(void); 												// 初始化 MPU6050
uint8_t MPU_Write_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);	// IIC 连续写
uint8_t MPU_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);	// IIC 连续读
uint8_t MPU_Write_Byte(uint8_t reg,uint8_t data);							// IIC 写一个字节
uint8_t MPU_Read_Byte(uint8_t reg);											// IIC 读一个字节

uint8_t MPU_Set_Gyro_Fsr(uint8_t fsr);
uint8_t MPU_Set_Accel_Fsr(uint8_t fsr);
uint8_t MPU_Set_LPF(uint16_t lpf);
uint8_t MPU_Set_Rate(uint16_t rate);
uint8_t MPU_Set_Fifo(uint8_t sens);

short MPU_Get_Temperature(void);
uint8_t MPU_Get_Gyroscope(short *gx, short *gy, short *gz);
uint8_t MPU_Get_Accelerometer(short *ax, short *ay, short *az);

// Customized
void MPU_GPIO_Init(void);
void MPU_IIC_Start(void);
void MPU_IIC_Stop(void);
void MPU_IIC_Send_Byte(uint8_t byte);
uint8_t MPU_IIC_Read_Byte(unsigned char ack);
uint8_t MPU_IIC_Wait_Ack(void);
void MPU_IIC_Ack(void);
void MPU_IIC_NAck(void);

#endif
