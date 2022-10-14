#ifndef __CST816_H
#define __CST816_H

#include "stdint.h"

/*
 * TP_RST -> PC2
 * TP_SCL -> PB10
 * TP_SDA -> PB11
 */

#define I2C_WR 0 /* 写控制bit */
#define I2C_RD 1 /* 读控制bit */

#define __HAL_RCC_TP_I2C_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define TP_I2C_PORT GPIOB
#define TP_SCL_PIN GPIO_PIN_10
#define TP_SDA_PIN GPIO_PIN_11

#define __HAL_RCC_TP_RST_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define TP_RST_PORT GPIOC
#define TP_RST_PIN GPIO_PIN_2

//#define __HAL_RCC_TP_INT_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
//#define TP_INT_PORT GPIOA
//#define TP_INT_PIN GPIO_PIN_4

#define TP_SCL_SET_0 HAL_GPIO_WritePin(TP_I2C_PORT, TP_SCL_PIN, GPIO_PIN_RESET)
#define TP_SCL_SET_1 HAL_GPIO_WritePin(TP_I2C_PORT, TP_SCL_PIN, GPIO_PIN_SET)

#define TP_SDA_SET_0 HAL_GPIO_WritePin(TP_I2C_PORT, TP_SDA_PIN, GPIO_PIN_RESET)
#define TP_SDA_SET_1 HAL_GPIO_WritePin(TP_I2C_PORT, TP_SDA_PIN, GPIO_PIN_SET)
#define TP_SDA_GET() HAL_GPIO_ReadPin(TP_I2C_PORT, TP_SDA_PIN)

#define TP_RST_SET_0 HAL_GPIO_WritePin(TP_RST_PORT, TP_RST_PIN, GPIO_PIN_RESET)
#define TP_RST_SET_1 HAL_GPIO_WritePin(TP_RST_PORT, TP_RST_PIN, GPIO_PIN_SET)

//#define TP_INT_GET() HAL_GPIO_ReadPin(TP_INT_PORT, TP_INT_PIN)

/* 设备地址 */
#define CST816_Device_Write_Addr 0x2A
#define CST816_Device_Read_Addr 0x2B

/* 触摸屏寄存器 */
#define GestureID 			0x01
#define FingerNum 			0x02
#define XposH 				0x03
#define XposL 				0x04
#define YposH 				0x05
#define YposL 				0x06
#define ChipID 				0xA7
#define MotionMask 			0xEC
#define IrqPluseWidth 		0xED
#define NorScanPer 			0xEE
#define MotionSlAngle 		0xEF
#define LpAutoWakeTime 		0xF4
#define LpScanTH 			0xF5
#define LpScanWin 			0xF6
#define LpScanFreq 			0xF7
#define LpScanIdac 			0xF8
#define AutoSleepTime 		0xF9
#define IrqCtl 				0xFA
#define AutoReset 			0xFB
#define LongPressTime 		0xFC
#define IOCtl 				0xFD
#define DisAutoSleep 		0xFE

/* 触摸屏坐标结构体 */
typedef struct {
	unsigned int X_Pos;
	unsigned int Y_Pos;
	uint8_t state;
	uint8_t DOWN;
} CST816_Info;

#define TP_PRES_DOWN 0x80
#define TP_CATH_PRES 0x40

extern CST816_Info CST816_Instance;
extern uint8_t CST816_Pen_Flag;

/* 手势ID识别选项 */
typedef enum {
	NOGESTURE = 	0x00,
	DOWNGLIDE = 	0x01,
	UPGLIDE = 		0x02,
	LEFTGLIDE = 	0x03,
	RIGHTGLIDE = 	0x04,
	CLICK = 		0x05,
	DOUBLECLICK = 	0x0B,
	LONGPRESS = 	0x0C,
} CST816_GestureID_TypeDef;

/* 连续动作配置选项 */
typedef enum {
	M_DISABLE = 	0x00,
	EnConLR = 		0x01,
	EnConUD = 		0x02,
	EnDClick = 		0x03,
	M_ALLENABLE = 	0x07,
} CST816_MotionMask_TypeDef;

/* 中断低脉冲发射方式选项 */
typedef enum {
	OnceWLP = 		0x00,
	EnMotion = 		0x10,
	EnChange = 		0x20,
	EnTouch = 		0x40,
	EnTest = 		0x80,
} CST816_IrqCtl_TypeDef;

/* IIC相关函数 */
void CST816_I2C_Start(void);
void CST816_I2C_Stop(void);
void CST816_I2C_Ack(void);
void CST816_I2C_NAck(void);
uint8_t CST816_I2C_WaitAck(void);
void CST816_I2C_SendByte(uint8_t _ucByte);
uint8_t CST816_I2C_ReadByte(void);

/* 触摸屏初始化相关函数 */
void CST816_GPIO_Init(void);
void CST816_Reset(void);

/* 触摸屏操作函数 */
void CST816_Get_Axis(void);
uint8_t CST816_Get_ChipID(void);

/* 触摸屏读写函数 */
void CST816_I2C_WriteReg(uint8_t addr, uint8_t dat);
uint8_t CST816_I2C_ReadReg(unsigned char addr);

/* 触摸屏有关参数配置函数 */
void CST816_Config_MotionMask(uint8_t mode);
void CST816_Config_AutoSleepTime(uint8_t time);
void CST816_Config_MotionSlAngle(uint8_t x_right_y_up_angle);
void CST816_Config_NorScanPer(uint8_t Period);
void CST816_Config_IrqPluseWidth(uint8_t Width);
void CST816_Config_LpScanTH(uint8_t TH);

#endif
