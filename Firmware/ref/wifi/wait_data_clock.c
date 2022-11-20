/*-------------------------------------------------*/
/*            ��γ����STM32ϵ�п�����              */
/*-------------------------------------------------*/
/*                                                 */
/*            ʵ�ֶ�ʱ��4���ܵ�Դ�ļ�              */
/*                                                 */
/*-------------------------------------------------*/
#include "wait_data_clock.h"
#include "stm32f10x.h"  //������Ҫ��ͷ�ļ�
#include "wifi.h"	       //������Ҫ��ͷ�ļ�
#include "usart2.h"

#define  WiFi_DATA_TIME_OK   30


char is_wifi_data_start=0;  //�Ƿ�ʼ��������

unsigned char wifi_time_cnt=0;


//���������ڶ�ʱ���ж���
void wifi_wait_data_hander(void)
{
	if(is_wifi_data_start)
	{
		wifi_time_cnt++;
		if(wifi_time_cnt > WiFi_DATA_TIME_OK)
		{
			Usart2_RxCompleted = 1;                                       //����2������ɱ�־λ��λ
			memcpy(&Data_buff[2],Usart2_RxBuff,Usart2_RxCounter);         //��������
			Data_buff[0] = WiFi_RxCounter/256;                            //��¼���յ�������		
			Data_buff[1] = WiFi_RxCounter%256;                            //��¼���յ�������
			Data_buff[WiFi_RxCounter+2] = '\0';                           //���������
			WiFi_RxCounter=0;                                             //�������ֵ
			is_wifi_data_start=0;                        				  //�رս�����
			wifi_time_cnt=0;
		}
	}

}



