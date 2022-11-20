/*-------------------------------------------------*/
/*            ��γ����STM32ϵ�п�����              */
/*-------------------------------------------------*/
/*                                                 */
/*            ����602Wifi���ܵ�Դ�ļ�              */
/*                                                 */
/*-------------------------------------------------*/

#include "stm32f10x.h"  //������Ҫ��ͷ�ļ�
#include "wifi.h"	    //������Ҫ��ͷ�ļ�
#include "UserApp/Drivers/delay/delay.h"        //������Ҫ��ͷ�ļ�
#include "usart2.h"
#include "draw_api.h"
#include "UserApp/Drivers/delay/delay.h"
#include "stdbool.h"
#include "common.h"
/*-----------------------------------------------------------------------------*/
/*                              �����Լ������绷���޸�                         */
/*-----------------------------------------------------------------------------*/
char *ServerIP = "api.k780.com";           //��ŷ�����IP��������
char *ServerIP2 = "api.seniverse.com";           //��ŷ�����IP��������
int  ServerPort = 80;                      //��ŷ������Ķ˿ں���
/*-----------------------------------------------------------------------------*/

char  Data_buff[1024];     //���ݻ�����



/*-------------------------------------------------*/
/*����������ʼ��WiFi�ĸ�λIO                       */
/*��  ������                                       */
/*����ֵ����                                       */
/*-------------------------------------------------*/
void WiFi_ResetIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;                      //����һ������IO�˿ڲ����Ľṹ��
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA , ENABLE);   //ʹ��PA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;                 //׼������PA4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;         //����50Mhz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   		  //���������ʽ
	GPIO_Init(GPIOA, &GPIO_InitStructure);            		  //����PA4
	RESET_IO(1);                                              //��λIO���ߵ�ƽ
}


extern unsigned char cmd_finish;

void deep_sleep(void)
{
	console_log(1,"deep sleep:");
	WiFi_send("AT+GSLP=3600000\r\n"); 
	cmd_finish=1;
}


void light_sleep(void)
{
	console_log(1,"light sleep:");
	WiFi_send("AT+SLEEP=1\r\n"); 
	cmd_finish=2;
}



#define CMD_MAXNUM  10
char CMD_S[10]={2,0,0,0,0,0,0,0,0,0};
//���ָ��ִ�й��������
char cmd_state(unsigned char time,unsigned char n,char* str)
{
	unsigned char _next=n+1;
	unsigned char _last=n-1;
	static unsigned char time_cnt=0;
	

	
	if(CMD_S[n]==0&&(CMD_S[_last]==2||CMD_S[_last]=='o'))  //����ָ��û��ִ���겢����һ��ָ��ִ�гɹ�
	{
		time_cnt=0;
		WiFi_RxCounter=0;                           //WiFi������������������    
		Usart2_RxCompleted=0;		
		memset(WiFi_RX_BUF,0,WiFi_RXBUFF_SIZE);     //���WiFi���ջ����� 
		CMD_S[n]|=1;
		return 0;
	}
	else if(CMD_S[n]==1&&CMD_S[_next]==0)  //����ָ��ִ���겢����һ��ָ��û��ִ�вſ���
	{
		if(Usart2_RxCompleted==1)    //���Usart2_RxCompleted����1����ʾ�����������
		{
			Usart2_RxCompleted=0;
			if(strstr(WiFi_RX_BUF,str)) //�ȶ��ַ�
			{
				time_cnt=0;
				CMD_S[n]=2;
				console_log(1,"%s",&Data_buff[2]);
				return 2; //��ȷ
			}
			else
			{
				time_cnt=0;
				//CMD_S[n]=3;
				CMD_S[n]=1;  //��Ϊ�ͷ�����ͨ�Ų������̷�����Ϣ������Ҫһֱ�ȴ�������
				console_log(1,"%s",&Data_buff[2]);
				return 3; //����
			}
		}
		//��ʱ��ʱ����
		time_cnt++;
		if(time_cnt>time)
		{
			time_cnt=0;
			CMD_S[n]=3;
			console_log(1,"time out");
			//reset
			return 3; //����
		}
	}
	
	return 1;
}

int Find_string(char *pcBuf,char *left,char*right, char *pcRes)
{
        char*pcBegin = NULL;
        char*pcEnd = NULL;
        pcBegin= strstr(pcBuf, left);//�ҵ���һ�γ��ֵ�λ��
        pcEnd= strstr(pcBegin+strlen(left), right);//�ҵ��ұ߱�ʶ
        if(pcBegin== NULL || pcEnd == NULL || pcBegin > pcEnd)
        {
                 //printf("stringname not found!\n");
                 return 0;
        }
        else
        {
                 pcBegin+= strlen(left);
                 memcpy(pcRes,pcBegin, pcEnd-pcBegin);
                 return pcEnd-pcBegin;
        }
}

void show_time_data(void)
{
	char str_buf[20];
	
	console_log(1,"time_date:");
	console_log(1,"-----------------");
	str_buf[Find_string(&Data_buff[2],"time_1\":\"", "\"",str_buf)]='\0';
	console_log(1,"%s",&str_buf[0]);
	console_log(500," ");
	
	console_log(1,"week:");
	str_buf[Find_string(&Data_buff[2],"week_1\":\"","\"",str_buf)]='\0';
	console_log(1,"%s",&str_buf[0]);
}

void updata_time_data(void)
{
	char str_buf[20];
	timeDate_s timeDate_Set;
	
	console_log(1,"time&date:");
	console_log(1,"-----------------\n");
	str_buf[Find_string(&Data_buff[2],"time_1\":\"", "\"",str_buf)]='\0';
	console_log(1,"%s",&str_buf[0]);
	console_log(500," ");
	
	timeDate_Set.date.date = (str_buf[8]-'0')*10+ (str_buf[9]-'0');
	timeDate_Set.date.month = (month_t)((str_buf[5]-'0')*10+ (str_buf[6]-'0')-1); //ע����Ҫ��ȥ1
	timeDate_Set.date.year = (str_buf[2]-'0')*10+ (str_buf[3]-'0');
	
	
	timeDate_Set.time.hour = (str_buf[11]-'0')*10+ (str_buf[12]-'0');
	timeDate_Set.time.mins = (str_buf[14]-'0')*10+ (str_buf[15]-'0');
	
	
	console_log(1,"week:");
	str_buf[Find_string(&Data_buff[2],"week_1\":\"","\"",str_buf)]='\0';
	console_log(1,"%s",&str_buf[0]);
	
	//timeDate_Set.date.day = (day_t)(str_buf[0]-'0'-1);
	timeDate_Set.date.day = time_dow(timeDate_Set.date.year, timeDate_Set.date.month, timeDate_Set.date.date);
	time_set(&timeDate_Set);
}

void connect_my_phone(void)
{
	
	if(cmd_state(10,1,"OK")==0)
	{
		console_log(500,"connect tcp:");
		console_log(500,"AT+CIPMODE=1");
		WiFi_send("AT+CIPMODE=1\r\n");
	}
	
	
	if(cmd_state(10,2,"OK")==0)
	{
		console_log(500,"AT+CIPMUX=0");
		WiFi_send("AT+CIPMUX=0\r\n");
	}
	
	if(cmd_state(10,3,"OK")==0)  //��Ϊ�ͷ�������������
	{
		console_log(500,"connecting TCP...");
		WiFi_send("AT+CIPSTART=\"TCP\",\"%s\",%d\r\n",ServerIP,ServerPort);//�������ӷ�����ָ��
	}
	
	if(cmd_state(10,4,"OK")==0)
	{
		console_log(500,"AT+CIPSEND");
		WiFi_send("AT+CIPSEND\r\n");                  //���ͽ���͸��ָ��
	}
	
	if(cmd_state(10,5,"success")==0)
	{
		console_log(500,"updata time");
		WiFi_send("GET http://api.k780.com:88/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json&HTTP/1.1\r\n");
	}
	else if(CMD_S[5]==2)
	{
		CMD_S[5]='o';
		console_log(500,"press down");
		updata_time_data();
		cmd_finish=3;
	}
	
}

void show_wather_data(void)
{
	char str_buf[20];
	
	console_log(1,"-----------------");
	
	str_buf[Find_string(&Data_buff[2],"name\":\"","\"",str_buf)]='\0';
	console_log(1,"city: %s",&str_buf[0]);
	
	
	str_buf[Find_string(&Data_buff[2],"text\":\"","\"",str_buf)]='\0';
	console_log(1,"weather: %s",&str_buf[0]);
	
	
	str_buf[Find_string(&Data_buff[2],"ature\":\"","\"",str_buf)]='\0';
	console_log(1,"tempterature: %s",&str_buf[0]);
}

void get_weather_cmd(void)
{
	
	if(cmd_state(10,1,"OK")==0)
	{
		console_log(500,"connect tcp:");
		console_log(500,"AT+CIPMODE=1");
		WiFi_send("AT+CIPMODE=1\r\n");
	}

	
	
	if(cmd_state(10,2,"OK")==0)
	{
		console_log(500,"AT+CIPMUX=0");
		WiFi_send("AT+CIPMUX=0\r\n");
	}
	
	if(cmd_state(10,3,"OK")==0)  //��Ϊ�ͷ�������������
	{
		console_log(500,"connecting TCP...");
		WiFi_send("AT+CIPSTART=\"TCP\",\"%s\",%d\r\n",ServerIP2,ServerPort);//�������ӷ�����ָ��
	}
	
	if(cmd_state(10,4,"OK")==0)
	{
		console_log(500,"AT+CIPSEND");
		WiFi_send("AT+CIPSEND\r\n");                  //���ͽ���͸��ָ��
	}
	
	if(cmd_state(10,5,"CN")==0)
	{
		console_log(500,"wather:");
		WiFi_send("GET https://api.seniverse.com/v3/weather/now.json?key=SIN2EqCTJrkaqqOpk&location=jiaozuo&language=en&unit=c\r\n");
	}
	else if(CMD_S[5]==2)
	{
		CMD_S[5]='o';
		console_log(500,"press down");
		show_wather_data();
		cmd_finish=4;
	}
	
}


void reset_wifi_cmd(void)
{
	if(cmd_state(10,1,"ready")==0)
	{
		console_log(1,"reset wifi:");
		RESET_IO(0);                                    //��λIO���͵�ƽ
		delay_ms(500);                                  //��ʱ500ms
		RESET_IO(1);  
	}
	else if(CMD_S[1]==2)
	{
		CMD_S[1]='o';
		cmd_finish=5;
	}
}

