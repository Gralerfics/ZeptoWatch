#ifndef __MPUIIC_H
#define __MPUIIC_H

#include "stdint.h"

// IO ��������
#define MPU_SDA_IN()   {GPIOB->CRH&=0XFFFFFFF0;GPIOB->CRH|=8;}
#define MPU_SDA_OUT()  {GPIOB->CRH&=0XFFFFFFF0;GPIOB->CRH|=3;}

//IO��������	 
#define MPU_IIC_SCL_H    PBout(9)=1;		//SCL
#define MPU_IIC_SDA_H    PBout(8)=1;		//SDA

#define MPU_IIC_SCL_L    PBout(9)=0;         //SCL
#define MPU_IIC_SDA_L    PBout(8)=0;        //SDA


#define MPU_READ_SDA     PBin(8)		//����SDA

//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void MPU_IIC_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(uint8_t txd);			//IIC����һ���ֽ�
uint8_t MPU_IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
uint8_t MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�

void IMPU_IC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t MPU_IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	  
#endif
