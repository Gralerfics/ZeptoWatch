#include "cst816.h"
#include "delay.h"

CST816_Info CST816_Instance;
uint8_t CST816_Pen_Flag;

/* 模拟IIC引脚初始化 */
void CST816_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_TP_I2C_CLK_ENABLE();
//	__HAL_RCC_TP_RST_CLK_ENABLE();
//	__HAL_RCC_TP_INT_CLK_ENABLE();
	
	/* 初始化复位引脚 */
//	GPIO_Init.Pin = TP_RST_PIN;
//	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
//	HAL_GPIO_Init(TP_RST_PORT, &GPIO_Init);
//	HAL_GPIO_WritePin(TP_RST_PORT, TP_RST_PIN, GPIO_PIN_SET);
	
	/* 初始化中断引脚 */
//	GPIO_Init.Pin = TP_INT_PIN;
//	GPIO_Init.Mode = GPIO_MODE_INPUT;
//	GPIO_Init.Pull = GPIO_PULLUP;
//	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
//	HAL_GPIO_Init(TP_INT_PORT,&GPIO_Init);
//	HAL_GPIO_WritePin(TP_INT_PORT,TP_INT_PIN,GPIO_PIN_RESET);
	
	/* 初始化I2C引脚 */
	GPIO_Init.Pin = TP_SCL_PIN | TP_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(TP_I2C_PORT, &GPIO_Init);
	HAL_GPIO_WritePin(TP_I2C_PORT, TP_SCL_PIN | TP_SDA_PIN, GPIO_PIN_SET);

	/* 给一个停止信号, 复位 I2C 总线上的所有设备到待机模式 */
	CST816_I2C_Stop();
}

/* 配置 IIC 的数据线为输入模式 */
void TP_SDA_INPUT() {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_TP_I2C_CLK_ENABLE();
	
	GPIO_Init.Pin = TP_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_INPUT;
	GPIO_Init.Pull = GPIO_PULLUP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(TP_I2C_PORT, &GPIO_Init);
}

/* 配置 IIC 的数据线为输出模式 */
void TP_SDA_OUT() {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_TP_I2C_CLK_ENABLE();

	GPIO_Init.Pin = TP_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(TP_I2C_PORT, &GPIO_Init);
}

/* 延时函数 */
void CST816_I2C_Delay(void) {
	Delay_us(1);
//	for (uint8_t i = 0; i < 15; i++);
}

/* IIC起始信号 */
void CST816_I2C_Start(void) {
	TP_SDA_SET_1;
	TP_SCL_SET_1;
	CST816_I2C_Delay();
	TP_SDA_SET_0;
	CST816_I2C_Delay();
	TP_SCL_SET_0;
	CST816_I2C_Delay();
}

/* IIC结束信号 */
void CST816_I2C_Stop(void) {
	TP_SDA_SET_0;
	TP_SCL_SET_1;
	CST816_I2C_Delay();
	TP_SDA_SET_1;
}

/*
*********************************************************************************************************
*	函 数 名: i2c_Ack
*	功能说明: CPU产生一个ACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_I2C_Ack(void) {
	TP_SDA_SET_0;	/* CPU驱动SDA = 0 */
	CST816_I2C_Delay();
	TP_SCL_SET_1;	/* CPU产生1个时钟 */
	CST816_I2C_Delay();
	TP_SCL_SET_0;
	CST816_I2C_Delay();
	TP_SDA_SET_1;	/* CPU释放SDA总线 */
}

/*
*********************************************************************************************************
*	函 数 名: i2c_NAck
*	功能说明: CPU产生1个NACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_I2C_NAck(void) {
	TP_SDA_SET_1;	/* CPU驱动SDA = 1 */
	CST816_I2C_Delay();
	TP_SCL_SET_1;	/* CPU产生1个时钟 */
	CST816_I2C_Delay();
	TP_SCL_SET_0;
	CST816_I2C_Delay();
}

/*
*********************************************************************************************************
*	函 数 名: i2c_SendByte
*	功能说明: CPU向I2C总线设备发送8bit数据
*	形    参：_ucByte ： 等待发送的字节
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_I2C_SendByte(uint8_t _ucByte) {
	uint8_t i;
	/* 先发送字节的高位bit7 */
	for (i = 0; i < 8; i++) {
		if (_ucByte & 0x80) {	//写数据
			TP_SDA_SET_1;
		} else {
			TP_SDA_SET_0;
		}
		CST816_I2C_Delay();
		TP_SCL_SET_1;
		CST816_I2C_Delay();
		TP_SCL_SET_0;
		if (i == 7) {
			TP_SDA_SET_1; // 释放总线
		}
		_ucByte <<= 1;
		CST816_I2C_Delay();
	}
}

/*
*********************************************************************************************************
*	函 数 名: CST816_I2C_ReadByte
*	功能说明: CPU从I2C总线设备读取8bit数据
*	形    参：无
*	返 回 值: 读到的数据
*********************************************************************************************************
*/
uint8_t CST816_I2C_ReadByte(void) {
	uint8_t i;
	uint8_t value;

	/* 读到第1个bit为数据的bit7,因为1-7才是数据有效位 */
	value = 0;
	for (i = 0; i < 8; i++) { //循环8次
		//一定要先左移再写入数据，不然数据不对齐
		value <<= 1;
		TP_SCL_SET_1;
		CST816_I2C_Delay();
		TP_SDA_INPUT();
		if (TP_SDA_GET())	//读取到高电平则写1
		{
			value = value + 1;	//自加1
		}
		TP_SCL_SET_0;
		TP_SDA_OUT();
		CST816_I2C_Delay();
	}
	return value;
}

/*
*********************************************************************************************************
*	函 数 名: i2c_WaitAck
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参：无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
uint8_t CST816_I2C_WaitAck(void) {
	uint8_t re;
	TP_SDA_SET_1;	/* CPU释放SDA总线 */
	CST816_I2C_Delay();
	TP_SCL_SET_1;	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
	CST816_I2C_Delay();
	TP_SDA_INPUT();
	if (TP_SDA_GET()) { /* CPU读取SDA口线状态 */
		re = 1;
	} else {
		re = 0;
	}
	TP_SCL_SET_0;
	TP_SDA_OUT();
	CST816_I2C_Delay();
	return re;
}

/*
*********************************************************************************************************
*	函 数 名: CST816_I2C_ReadReg
*	功能说明: 读取触摸屏单个寄存器的数据
*	形    参：reg：寄存器地址
*	返 回 值: 返回寄存器存储的数据
*********************************************************************************************************
*/
uint8_t CST816_I2C_ReadReg(uint8_t addr) {
	uint8_t dat;
	CST816_I2C_Start();
	CST816_I2C_SendByte(CST816_Device_Write_Addr);
	CST816_I2C_WaitAck();
	CST816_I2C_SendByte(addr);
	CST816_I2C_WaitAck();
	CST816_I2C_Start();
	CST816_I2C_SendByte(CST816_Device_Read_Addr);
	CST816_I2C_WaitAck();
	dat = CST816_I2C_ReadByte();
	CST816_I2C_NAck();
	CST816_I2C_Stop();
	return dat;
}

uint8_t CST816_Read_EXTI_PEN(uint8_t addr) {
	uint8_t dat;
	CST816_I2C_Start();
	CST816_I2C_SendByte(CST816_Device_Write_Addr);
	CST816_I2C_WaitAck();
}

/*
*********************************************************************************************************
*	函 数 名: CST816_I2C_WriteReg
*	功能说明: 向触摸屏的寄存器写入数据
*	形    参：addr：寄存器地址
*						dat:	写入的数据
*	返 回 值: 返回寄存器存储的数据
*********************************************************************************************************
*/
void CST816_I2C_WriteReg(uint8_t addr, uint8_t dat) {
	CST816_I2C_Start();
	CST816_I2C_SendByte(CST816_Device_Write_Addr);
	CST816_I2C_WaitAck();
	CST816_I2C_SendByte(addr);
	CST816_I2C_WaitAck();
	CST816_I2C_SendByte(dat);
	CST816_I2C_NAck();
	CST816_I2C_Stop();
}

/*
*********************************************************************************************************
*	函 数 名: TOUCH_RESET
*	功能说明: 触摸屏复位
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
//void CST816_Reset(void) {
//	TP_RST_SET_0;
//	Delay_ms(10);
//	TP_RST_SET_1;
//	Delay_ms(100);
//}

/*
*********************************************************************************************************
*	函 数 名: TOUCH_READ_X
*	功能说明: 读取触摸屏在触摸时的坐标值
*	形    参：无
*	返 回 值: 无 （数据存储在CST816_Instance结构体中）
*********************************************************************************************************
*/

void CST816_Get_Axis(void) {
	uint8_t DAT[4];
	CST816_I2C_Start();
	CST816_I2C_SendByte(CST816_Device_Write_Addr);
	CST816_I2C_WaitAck();
	CST816_I2C_SendByte(XposH);
	CST816_I2C_WaitAck();
	CST816_I2C_Start();
	CST816_I2C_SendByte(CST816_Device_Read_Addr);
	CST816_I2C_WaitAck();
	DAT[0] = CST816_I2C_ReadByte();
	CST816_I2C_Ack();
	DAT[1] = CST816_I2C_ReadByte();
	CST816_I2C_Ack();
	DAT[2] = CST816_I2C_ReadByte();
	CST816_I2C_Ack();
	DAT[3] = CST816_I2C_ReadByte();
	CST816_I2C_NAck();
	CST816_I2C_Stop();
	
	CST816_Instance.X_Pos=((DAT[0]&0x0F)<<8)|DAT[1]; // (temp[0]&0X0F)<<4|
	CST816_Instance.Y_Pos=((DAT[2]&0x0F)<<8)|DAT[3]; // (temp[2]&0X0F)<<4|
	// 是否被按下标志位
	// printf("FLAG=%d\r\n",CST816_Instance.state);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Get_ChipID
*	功能说明: 读取触摸屏的芯片ID
*	形    参：无
*	返 回 值: 返回芯片ID
*********************************************************************************************************
*/
uint8_t CST816_Get_ChipID(void) {
	return CST816_I2C_ReadReg(ChipID);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Config_MotionMask
*	功能说明: 使能连续动作（连续左右滑动，连续上下滑动，双击）
*	形    参：mode：模式(5种)
*	返 回 值: 无
*	注    意：使能连续动作会增加响应时间
*********************************************************************************************************
*/
void CST816_Config_MotionMask(uint8_t mode) {
	CST816_I2C_WriteReg(MotionMask, mode);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Config_AutoSleepTime
*	功能说明: 规定time内无触摸，自动进入低功耗模式
*	形    参：time：时间
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_AutoSleepTime(uint8_t time) {
	CST816_I2C_WriteReg(AutoSleepTime, time);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Config_MotionSlAngle
*	功能说明: 手势检测滑动分区角度控制。Angle=tan(c)*10 c为以x轴正方向为基准的角度。
*	形    参：x_right_y_up_angle：角度值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_MotionSlAngle(uint8_t x_right_y_up_angle) {
	CST816_I2C_WriteReg(MotionSlAngle, x_right_y_up_angle);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Config_NorScanPer
*	功能说明: 正常快速检测周期配置函数。
*						此值会影响到LpAutoWakeTime和AutoSleepTime。 
*						单位10ms，可选值：1～30。默认值为1。
*	形    参：Period：周期值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_NorScanPer(uint8_t Period) {
	if(Period >= 30)
		Period = 30;
	CST816_I2C_WriteReg(NorScanPer, Period);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Config_IrqPluseWidth
*	功能说明: 中断低脉冲输出宽度配置函数
*	形    参：Period：周期值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_IrqPluseWidth(uint8_t Width) {
	if(Width >= 200)
		Width = 200;
	CST816_I2C_WriteReg(IrqPluseWidth, Width);
}

/*
*********************************************************************************************************
*	函 数 名: CST816_Config_NorScanPer
*	功能说明: 低功耗扫描唤醒门限配置函数。越小越灵敏。默认值48
*	形    参：TH：门限值
*	返 回 值: 无
*********************************************************************************************************
*/
void CST816_Config_LpScanTH(uint8_t TH) {
	CST816_I2C_WriteReg(LpScanTH, TH);
}
