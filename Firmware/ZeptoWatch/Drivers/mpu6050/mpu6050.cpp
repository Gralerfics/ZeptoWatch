#include "mpu6050.h"

#include <cstdlib>

#include "delay.h"

/* 初始化, 返回 0 成功 */
uint8_t MPU_Initialize(void) {
	MPU_GPIO_Init();										// 初始化 I2C 总线

	MPU_Write_Byte(MPU_PWR_MGMT1_REG, 0x80);		// 复位 MPU6050
	delay_ms(500);
	MPU_Write_Byte(MPU_PWR_MGMT1_REG, 0x00);		// 唤醒 MPU6050
	MPU_Set_Gyro_Fsr(3);								// 设置陀螺仪量程, ±2000dps
	MPU_Set_Accel_Fsr(0);								// 设置加速度量程, ±2g
	MPU_Set_Rate(50);									// 设置采样率 50Hz
	MPU_Write_Byte(MPU_INT_EN_REG, 0x00);			// 关闭所有中断
	MPU_Write_Byte(MPU_USER_CTRL_REG, 0x00);		// I2C 主模式关闭
	MPU_Write_Byte(MPU_FIFO_EN_REG, 0x00);			// 关闭 FIFO
	MPU_Write_Byte(MPU_INTBP_CFG_REG, 0x80);		// INT 引脚低电平有效
	uint8_t res = MPU_Read_Byte(MPU_DEVICE_ID_REG);

	if (res == MPU_ADDR) {
		MPU_Write_Byte(MPU_PWR_MGMT1_REG, 0x01);	// 设置 CLKSEL, PLL X 轴为参考
		MPU_Write_Byte(MPU_PWR_MGMT2_REG, 0x00);	// 加速度与陀螺仪都工作
		MPU_Set_Rate(50);								// 设置采样率为 50Hz
		return 0;
	}
	return 1;
}

/* 设置 MPU6050 陀螺仪传感器满量程范围
 * fsr: 0, ±250dps; 1, ±500dps; 2, ±1000dps; 3, ±2000dps
 * 返回值: 0, 成功; 其他, 错误代码 */
uint8_t MPU_Set_Gyro_Fsr(uint8_t fsr) {
	return MPU_Write_Byte(MPU_GYRO_CFG_REG,fsr<<3);//设置陀螺仪满量程范围  
}

/* 设置 MPU6050 加速度传感器满量程范围
 * fsr: 0, ±2g; 1, ±4g; 2, ±8g; 3, ±16g
 * 返回值: 0, 成功; 其他, 错误代码 */
uint8_t MPU_Set_Accel_Fsr(uint8_t fsr) {
	return MPU_Write_Byte(MPU_ACCEL_CFG_REG,fsr<<3);//设置加速度传感器满量程范围  
}

/* 设置 MPU6050 的数字低通滤波器
 * lpf: 数字低通滤波频率 (Hz)
 * 返回值: 0, 成功; 其他, 错误代码 */
uint8_t MPU_Set_LPF(uint16_t lpf) {
	uint8_t data=0;
	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6; 
	return MPU_Write_Byte(MPU_CFG_REG,data);//设置数字低通滤波器  
}

/* 设置 MPU6050 的采样率 (假定 Fs = 1KHz)
 * rate: 4Hz ~ 1000Hz
 * 返回值: 0, 成功; 其他, 错误代码 */
uint8_t MPU_Set_Rate(uint16_t rate) {
	uint8_t data;
	if(rate>1000)rate=1000;
	if(rate<4)rate=4;
	data=1000/rate-1;
	data=MPU_Write_Byte(MPU_SAMPLE_RATE_REG,data);	//设置数字低通滤波器
 	return MPU_Set_LPF(rate/2);	//自动设置LPF为采样率的一半
}

/* 得到温度值
 * 返回值: 扩大 100 倍的温度值 */
short MPU_Get_Temperature(void) {
    uint8_t buf[2]; 
    short raw;
	float temp;
	MPU_Read_Len(MPU_ADDR,MPU_TEMP_OUTH_REG,2,buf); 
    raw=((uint16_t)buf[0]<<8)|buf[1];  
    temp=36.53+((double)raw)/340;  
    return temp*100;;
}

/* 得到陀螺仪原始值
 * gx, gy, gz: 陀螺仪 x, y, z 轴的原始带符号读数
 * 返回值: 0, 成功; 其他, 错误代码 */
uint8_t MPU_Get_Gyroscope(short *gx,short *gy,short *gz) {
    uint8_t buf[6],res;  
	res=MPU_Read_Len(MPU_ADDR,MPU_GYRO_XOUTH_REG,6,buf);
	if(res==0)
	{
		*gx=((uint16_t)buf[0]<<8)|buf[1];  
		*gy=((uint16_t)buf[2]<<8)|buf[3];  
		*gz=((uint16_t)buf[4]<<8)|buf[5];
	} 	
    return res;
}

/* 得到加速度原始值
 * ax, ay, az: 加速度计 x, y, z 轴的原始带符号读数
 * 返回值: 0, 成功; 其他, 错误代码 */
uint8_t MPU_Get_Accelerometer(short *ax, short *ay, short *az) {
    uint8_t buf[6],res;
	res=MPU_Read_Len(MPU_ADDR,MPU_ACCEL_XOUTH_REG,6,buf);
	if (res==0) {
		*ax=((uint16_t)buf[0]<<8)|buf[1];  
		*ay=((uint16_t)buf[2]<<8)|buf[3];  
		*az=((uint16_t)buf[4]<<8)|buf[5];
	} 	
    return res;
}

/* IIC 连续写
 * addr: 器件地址
 * reg: 寄存器地址
 * len: 写入长度
 * buf: 数据区
 * 返回值: 0, 正常; 其他, 错误代码 */
uint8_t MPU_Write_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf) {
	uint8_t i; 
    MPU_IIC_Start(); 
	MPU_IIC_Send_Byte((addr<<1)|0);//发送器件地址+写命令	
	if(MPU_IIC_Wait_Ack())	//等待应答
	{
		MPU_IIC_Stop();		 
		return 1;		
	}
    MPU_IIC_Send_Byte(reg);	//写寄存器地址
    MPU_IIC_Wait_Ack();		//等待应答
	for(i=0;i<len;i++) {
		MPU_IIC_Send_Byte(buf[i]);    //发送数据
		if (MPU_IIC_Wait_Ack()) {      //等待ACK
			MPU_IIC_Stop();
			return 1;
		}
	}
    MPU_IIC_Stop();
	return 0;
}

/* IIC 连续读
 * addr: 器件地址
 * reg: 要读取的寄存器地址
 * len: 要读取的长度
 * buf: 读取到的数据存储区
 * 返回值: 0, 正常; 其他, 错误代码 */
uint8_t MPU_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf) {
 	MPU_IIC_Start(); 
	MPU_IIC_Send_Byte((addr<<1)|0);//发送器件地址+写命令	
	if(MPU_IIC_Wait_Ack())	//等待应答
	{
		MPU_IIC_Stop();		 
		return 1;		
	}
    MPU_IIC_Send_Byte(reg);	//写寄存器地址
    MPU_IIC_Wait_Ack();		//等待应答
    MPU_IIC_Start();
	MPU_IIC_Send_Byte((addr<<1)|1);//发送器件地址+读命令	
    MPU_IIC_Wait_Ack();		//等待应答 
	while(len)
	{
		if(len==1)*buf=MPU_IIC_Read_Byte(0);//读数据,发送nACK 
		else *buf=MPU_IIC_Read_Byte(1);		//读数据,发送ACK  
		len--;
		buf++; 
	}    
    MPU_IIC_Stop();	//产生一个停止条件 
	return 0;	
}

/* IIC 写一个字节
 * reg: 寄存器地址
 * data: 数据
 * 返回值: 0, 正常; 其他, 错误代码 */
uint8_t MPU_Write_Byte(uint8_t reg, uint8_t data) {
    MPU_IIC_Start();
	MPU_IIC_Send_Byte((MPU_ADDR<<1)|0);//发送器件地址 + 写命令
	if(MPU_IIC_Wait_Ack())	//等待应答
	{
		MPU_IIC_Stop();
		return 1;
	}
    MPU_IIC_Send_Byte(reg);	//写寄存器地址
    MPU_IIC_Wait_Ack();		//等待应答
	MPU_IIC_Send_Byte(data);//发送数据
	if(MPU_IIC_Wait_Ack())	//等待ACK
	{
		MPU_IIC_Stop();
		return 1;
	}
    MPU_IIC_Stop();
	return 0;
}

/* IIC 读一个字节
 * reg: 寄存器地址
 * 返回值: 读到的数据 */
uint8_t MPU_Read_Byte(uint8_t reg) {
	uint8_t res;
    MPU_IIC_Start();
	MPU_IIC_Send_Byte((MPU_ADDR<<1)|0);	// 发送器件地址, 写命令
	MPU_IIC_Wait_Ack();							// 等待应答
    MPU_IIC_Send_Byte(reg);				// 写寄存器地址
    MPU_IIC_Wait_Ack();							// 等待应答
    MPU_IIC_Start();
	MPU_IIC_Send_Byte((MPU_ADDR<<1)|1);	// 发送器件地址, 读命令
    MPU_IIC_Wait_Ack();							// 等待应答
	res = MPU_IIC_Read_Byte(0);				// 读取数据,发送nACK
    MPU_IIC_Stop();								// 产生一个停止条件
	return res;
}

// Customized

/* 初始化 */
void MPU_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_IMU_I2C_CLK_ENABLE();

	GPIO_Init.Pin = IMU_SCL_PIN | IMU_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(IMU_I2C_PORT, &GPIO_Init);
	HAL_GPIO_WritePin(IMU_I2C_PORT, IMU_SCL_PIN | IMU_SDA_PIN, GPIO_PIN_SET);

	MPU_IIC_Stop();
}

void IMU_SDA_INPUT() {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_IMU_I2C_CLK_ENABLE();

	GPIO_Init.Pin = IMU_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_INPUT;
	GPIO_Init.Pull = GPIO_PULLUP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(IMU_I2C_PORT, &GPIO_Init);
}

void IMU_SDA_OUT() {
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_IMU_I2C_CLK_ENABLE();

	GPIO_Init.Pin = IMU_SDA_PIN;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(IMU_I2C_PORT, &GPIO_Init);
}

void MPU_IIC_Delay(void) {
	delay_us(2);
}

void MPU_IIC_Start(void) {
	IMU_SDA_OUT();
	IMU_SDA_SET_1;
	IMU_SCL_SET_1;
	MPU_IIC_Delay();
	IMU_SDA_SET_0;
	MPU_IIC_Delay();
	IMU_SCL_SET_0;
}

void MPU_IIC_Stop(void) {
	IMU_SDA_OUT();
	IMU_SCL_SET_0;
	IMU_SDA_SET_0;
	MPU_IIC_Delay();
	IMU_SCL_SET_1;
	IMU_SDA_SET_1;
	MPU_IIC_Delay();
}

uint8_t MPU_IIC_Wait_Ack(void) {
	uint8_t ucErrTime = 0;
	IMU_SDA_INPUT();
	IMU_SDA_SET_1;
	MPU_IIC_Delay();
	IMU_SCL_SET_1;
	MPU_IIC_Delay();
	while (IMU_SDA_GET()) {
		ucErrTime++;
		if (ucErrTime > 250) {
			MPU_IIC_Stop();
			return 1;
		}
	}
	IMU_SCL_SET_0;
	return 0;
}

void MPU_IIC_Ack(void) {
	IMU_SCL_SET_0;
	IMU_SDA_OUT();
	MPU_IIC_Delay();
	IMU_SDA_SET_0;
	MPU_IIC_Delay();
	IMU_SCL_SET_1;
	MPU_IIC_Delay();
	IMU_SCL_SET_0;
}
//������ACKӦ��		    
void MPU_IIC_NAck(void) {
	IMU_SCL_SET_0;
	IMU_SDA_OUT();
	IMU_SDA_SET_1;
	MPU_IIC_Delay();
	IMU_SCL_SET_1;
	MPU_IIC_Delay();
	IMU_SCL_SET_0;
}

void MPU_IIC_Send_Byte(uint8_t txd) {
	uint8_t t;
	IMU_SDA_OUT();
	IMU_SCL_SET_0;
	for (t = 0; t < 8; t ++) {
		if ((txd & 0x80) >> 7 == 1) {
			IMU_SDA_SET_1;
		} else {
			IMU_SDA_SET_0;
		}
		txd <<= 1;
		IMU_SCL_SET_1;
		MPU_IIC_Delay();
		IMU_SCL_SET_0;
		MPU_IIC_Delay();
	}
}

uint8_t MPU_IIC_Read_Byte(unsigned char ack) {
	unsigned char i, receive = 0;
	IMU_SDA_INPUT();
	for (i = 0; i < 8; i ++) {
		IMU_SCL_SET_0;
		MPU_IIC_Delay();
		IMU_SCL_SET_1;
		receive <<= 1;
		if (IMU_SDA_GET()) receive ++;
		MPU_IIC_Delay();
	}
	if (!ack)
		MPU_IIC_NAck();
	else
		MPU_IIC_Ack(); 
	return receive;
}
