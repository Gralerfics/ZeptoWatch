#include "mpuiic.h"
#include "UserApp/Drivers/delay/delay.h"

 //MPU IIC ��ʱ����
void MPU_IIC_Delay(void)
{
    delay_us(2);
}

//��ʼ��IIC
void MPU_IIC_Init(void)
{
     GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //ʹ��PB�˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;	//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
}
//����IIC��ʼ�ź�
void MPU_IIC_Start(void)
{
	MPU_SDA_OUT();     //sda�����
	MPU_IIC_SDA_H;
	MPU_IIC_SCL_H;
	MPU_IIC_Delay();
 	MPU_IIC_SDA_L;//START:when CLK is high,DATA change form high to low
	MPU_IIC_Delay();
	MPU_IIC_SCL_L;//ǯסI2C���ߣ�׼�����ͻ��������
}	  
//����IICֹͣ�ź�
void MPU_IIC_Stop(void)
{
	MPU_SDA_OUT();//sda�����
	MPU_IIC_SCL_L;
	MPU_IIC_SDA_L;//STOP:when CLK is high DATA change form low to high
 	MPU_IIC_Delay();
	MPU_IIC_SCL_H;
	MPU_IIC_SDA_H;//����I2C���߽����ź�
	MPU_IIC_Delay();							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 MPU_IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	MPU_SDA_IN();      //SDA����Ϊ����  
	MPU_IIC_SDA_H;
	MPU_IIC_Delay();
	MPU_IIC_SCL_H;
	MPU_IIC_Delay();
	while(MPU_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			MPU_IIC_Stop();
			return 1;
		}
	}
	MPU_IIC_SCL_L;//ʱ�����0
	return 0;  
} 
//����ACKӦ��
void MPU_IIC_Ack(void)
{
	MPU_IIC_SCL_L;
	MPU_SDA_OUT();
	MPU_IIC_Delay();
	MPU_IIC_SDA_L;
	MPU_IIC_Delay();
	MPU_IIC_SCL_H;
	MPU_IIC_Delay();
	MPU_IIC_SCL_L;
}
//������ACKӦ��		    
void MPU_IIC_NAck(void)
{
	MPU_IIC_SCL_L;
	MPU_SDA_OUT();
	MPU_IIC_SDA_H;
	MPU_IIC_Delay();
	MPU_IIC_SCL_H;
	MPU_IIC_Delay();
	MPU_IIC_SCL_L;
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void MPU_IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	MPU_SDA_OUT(); 	    
    MPU_IIC_SCL_L;//����ʱ�ӿ�ʼ���ݴ���
    for(t=0;t<8;t++)
    {              
        //MPU_IIC_SDA=(txd&0x80)>>7;
        if((txd&0x80)>>7 == 1)
        {
            MPU_IIC_SDA_H;
        }
        else
        {
            MPU_IIC_SDA_L;
        }
            txd<<=1;
		    MPU_IIC_SCL_H;
		    MPU_IIC_Delay(); 
		    MPU_IIC_SCL_L;
		    MPU_IIC_Delay();
    }	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 MPU_IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	MPU_SDA_IN();//SDA����Ϊ����
    for(i=0;i<8;i++ )
	{
        MPU_IIC_SCL_L;
        MPU_IIC_Delay();
		MPU_IIC_SCL_H;
        receive<<=1;
        if(MPU_READ_SDA)receive++;   
		MPU_IIC_Delay(); 
    }					 
    if (!ack)
        MPU_IIC_NAck();//����nACK
    else
        MPU_IIC_Ack(); //����ACK   
    return receive;
}













