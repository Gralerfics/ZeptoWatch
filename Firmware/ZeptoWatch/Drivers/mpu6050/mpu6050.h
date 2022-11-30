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

/* AD0 ��ַ����
 *     ��� AD0 �� GND, ��ӻ���ַΪ 0X68 (�������λ), ����� VCC, ���ַΪ 0X69.
 *     ��д��ַΪ��ַ��һ�����λ. AD0 Ĭ�Ͻ� GND, �ʶ�д��ַΪ 0XD1 �� 0XD0 (����� VCC, ��Ϊ 0XD3 �� 0XD2).
 * */
#define MPU_ADDR				0X68	// �ӻ���ַ
#define MPU_READ    			0XD1
#define MPU_WRITE   			0XD0

#define MPU_ACCEL_OFFS_REG		0X06	// Accel_offs �Ĵ���, �ɶ�ȡ�汾��, �ֲ�δ�ἰ
#define MPU_PROD_ID_REG			0X0C	// Prod ID �Ĵ���, �ֲ�δ�ἰ
#define MPU_SELF_TESTX_REG		0X0D	// �Լ�Ĵ��� X
#define MPU_SELF_TESTY_REG		0X0E	// �Լ�Ĵ��� Y
#define MPU_SELF_TESTZ_REG		0X0F	// �Լ�Ĵ��� Z
#define MPU_SELF_TESTA_REG		0X10	// �Լ�Ĵ��� A
#define MPU_SAMPLE_RATE_REG		0X19	// ����Ƶ�ʷ�Ƶ��
#define MPU_CFG_REG				0X1A	// ���üĴ���
#define MPU_GYRO_CFG_REG		0X1B	// ���������üĴ���
#define MPU_ACCEL_CFG_REG		0X1C	// ���ٶȼ����üĴ���
#define MPU_MOTION_DET_REG		0X1F	// �˶���ֵⷧ���üĴ���
#define MPU_FIFO_EN_REG			0X23	// FIFO ʹ�ܼĴ���
#define MPU_I2CMST_CTRL_REG		0X24	// IIC �������ƼĴ���
#define MPU_I2CSLV0_ADDR_REG	0X25	// IIC �ӻ� 0 ������ַ�Ĵ���
#define MPU_I2CSLV0_REG			0X26	// IIC �ӻ� 0 ���ݵ�ַ�Ĵ���
#define MPU_I2CSLV0_CTRL_REG	0X27	// IIC �ӻ� 0 ���ƼĴ���
#define MPU_I2CSLV1_ADDR_REG	0X28	// IIC �ӻ� 1 ������ַ�Ĵ���
#define MPU_I2CSLV1_REG			0X29	// IIC �ӻ� 1 ���ݵ�ַ�Ĵ���
#define MPU_I2CSLV1_CTRL_REG	0X2A	// IIC �ӻ� 1 ���ƼĴ���
#define MPU_I2CSLV2_ADDR_REG	0X2B	// IIC �ӻ� 2 ������ַ�Ĵ���
#define MPU_I2CSLV2_REG			0X2C	// IIC �ӻ� 2 ���ݵ�ַ�Ĵ���
#define MPU_I2CSLV2_CTRL_REG	0X2D	// IIC �ӻ� 2 ���ƼĴ���
#define MPU_I2CSLV3_ADDR_REG	0X2E	// IIC �ӻ� 3 ������ַ�Ĵ���
#define MPU_I2CSLV3_REG			0X2F	// IIC �ӻ� 3 ���ݵ�ַ�Ĵ���
#define MPU_I2CSLV3_CTRL_REG	0X30	// IIC �ӻ� 3 ���ƼĴ���
#define MPU_I2CSLV4_ADDR_REG	0X31	// IIC �ӻ� 4 ������ַ�Ĵ���
#define MPU_I2CSLV4_REG			0X32	// IIC �ӻ� 4 ���ݵ�ַ�Ĵ���
#define MPU_I2CSLV4_DO_REG		0X33	// IIC �ӻ� 4 д���ݼĴ���
#define MPU_I2CSLV4_CTRL_REG	0X34	// IIC �ӻ� 4 ���ƼĴ���
#define MPU_I2CSLV4_DI_REG		0X35	// IIC �ӻ� 4 �����ݼĴ���

#define MPU_I2CMST_STA_REG		0X36	// IIC ����״̬�Ĵ���
#define MPU_INTBP_CFG_REG		0X37	// �ж� / ��·���üĴ���
#define MPU_INT_EN_REG			0X38	// �ж�ʹ�ܼĴ���
#define MPU_INT_STA_REG			0X3A	// �ж�״̬�Ĵ���

#define MPU_ACCEL_XOUTH_REG		0X3B	// ���ٶ�ֵ, X ���λ�Ĵ���
#define MPU_ACCEL_XOUTL_REG		0X3C	// ���ٶ�ֵ, X ���λ�Ĵ���
#define MPU_ACCEL_YOUTH_REG		0X3D	// ���ٶ�ֵ, Y ���λ�Ĵ���
#define MPU_ACCEL_YOUTL_REG		0X3E	// ���ٶ�ֵ, Y ���λ�Ĵ���
#define MPU_ACCEL_ZOUTH_REG		0X3F	// ���ٶ�ֵ, Z ���λ�Ĵ���
#define MPU_ACCEL_ZOUTL_REG		0X40	// ���ٶ�ֵ, Z ���λ�Ĵ���

#define MPU_TEMP_OUTH_REG		0X41	// �¶�ֵ��λ�Ĵ���
#define MPU_TEMP_OUTL_REG		0X42	// �¶�ֵ��λ�Ĵ���

#define MPU_GYRO_XOUTH_REG		0X43	// ������ֵ, X ���λ�Ĵ���
#define MPU_GYRO_XOUTL_REG		0X44	// ������ֵ, X ���λ�Ĵ���
#define MPU_GYRO_YOUTH_REG		0X45	// ������ֵ, Y ���λ�Ĵ���
#define MPU_GYRO_YOUTL_REG		0X46	// ������ֵ, Y ���λ�Ĵ���
#define MPU_GYRO_ZOUTH_REG		0X47	// ������ֵ, Z ���λ�Ĵ���
#define MPU_GYRO_ZOUTL_REG		0X48	// ������ֵ, Z ���λ�Ĵ���

#define MPU_I2CSLV0_DO_REG		0X63	// IIC �ӻ� 0 ���ݼĴ���
#define MPU_I2CSLV1_DO_REG		0X64	// IIC �ӻ� 1 ���ݼĴ���
#define MPU_I2CSLV2_DO_REG		0X65	// IIC �ӻ� 2 ���ݼĴ���
#define MPU_I2CSLV3_DO_REG		0X66	// IIC �ӻ� 3 ���ݼĴ���

#define MPU_I2CMST_DELAY_REG	0X67	// IIC ������ʱ����Ĵ���
#define MPU_SIGPATH_RST_REG		0X68	// �ź�ͨ����λ�Ĵ���
#define MPU_MDETECT_CTRL_REG	0X69	// �˶������ƼĴ���
#define MPU_USER_CTRL_REG		0X6A	// �û����ƼĴ���
#define MPU_PWR_MGMT1_REG		0X6B	// ��Դ����Ĵ��� 1
#define MPU_PWR_MGMT2_REG		0X6C	// ��Դ����Ĵ��� 2 
#define MPU_FIFO_CNTH_REG		0X72	// FIFO �����Ĵ����߰�λ
#define MPU_FIFO_CNTL_REG		0X73	// FIFO �����Ĵ����Ͱ�λ
#define MPU_FIFO_RW_REG			0X74	// FIFO ��д�Ĵ���
#define MPU_DEVICE_ID_REG		0X75	// ���� ID �Ĵ���

uint8_t MPU_Initialize(void); 												// ��ʼ�� MPU6050
uint8_t MPU_Write_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);	// IIC ����д
uint8_t MPU_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);	// IIC ������
uint8_t MPU_Write_Byte(uint8_t reg,uint8_t data);							// IIC дһ���ֽ�
uint8_t MPU_Read_Byte(uint8_t reg);											// IIC ��һ���ֽ�

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
