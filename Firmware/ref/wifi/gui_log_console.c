#include "gui_log_console.h"
#include "usart2.h"
#include "UserApp/Drivers/delay/delay.h"
#include "common.h"
#include "lcd.h"

//֧�ֻ���
#define SUPORT_HUANGHANG    1

//�����ж���
#define SUPORT_NEW_LINE_AMI 1

#define LINE_BUF_MAX  50
#define LINE_SHOW_CNT 8 
#define LINE_CHAR_CNT 17
#define CHAR_HEIGHT   8

#define LINE(n)              ((n-1)*8)

STRBUFF string_buff[LINE_BUF_MAX];
char firststr_buff[1024];

char now_line=1;
char new_line_flag=0;
char LOOP_SHOW_MD=0;
char NEW_LINE_AMI=0;

static char index=0;
static unsigned char last_str_length=0;
char now_str_length;


void gui_print_s(int x, int y,char *str)
{
	draw_string(str, false, x, y);
}



//��ʾ���ؼ�ƫ��64-160
short pix_show_idx=CHAR_HEIGHT*LINE_SHOW_CNT;



//���ؼ��İ����ص�����
bool up_line(void)
{
	pix_show_idx++;
	pix_show_idx++;
	if(pix_show_idx>=CHAR_HEIGHT*LINE_BUF_MAX) 
	{
		pix_show_idx =CHAR_HEIGHT*LINE_BUF_MAX;
	}
	return false;
}
//���ؼ��İ����ص�����
bool down_line(void)
{
	pix_show_idx--;
	pix_show_idx--;
	if(pix_show_idx<=CHAR_HEIGHT*LINE_SHOW_CNT)
	{
		pix_show_idx=CHAR_HEIGHT*LINE_SHOW_CNT;
	}
	return false;
}

char is_loging(void)
{
	return (NEW_LINE_AMI==true&&pix_show_idx!=CHAR_HEIGHT*LINE_SHOW_CNT);
}

//�ӵ�line�п�ʼ������ʣ��������ɱ������Ӷ����ٶȣ��ٶ����Ϊ (�ַ��߶�CHAR_HEIGHT/2-line+1) = 4 Pixels
short Generate_Dynamic_Aim_Speed(short line)
{
	if (line > CHAR_HEIGHT/2)
		return 0;
	return pix_show_idx-(CHAR_HEIGHT*LINE_SHOW_CNT)<=line*CHAR_HEIGHT ? 1:1+Generate_Dynamic_Aim_Speed(line+1);
}


//�˺����滻����ǰ�Ĺ��������������ؼ������������Ҫ��ǰ�ķ�ʽ��ע����������������ǰ��
char console_loop_show(void)
{
	static char deal_ok=true;
	
	char show_index=(LINE_BUF_MAX+index-LINE_SHOW_CNT)%LINE_BUF_MAX;  //��һ������ֵ
	
#if SUPORT_NEW_LINE_AMI
	
	
	if(NEW_LINE_AMI==true&&pix_show_idx!=CHAR_HEIGHT*LINE_SHOW_CNT)
	{
		deal_ok=false;
		pix_show_idx-=Generate_Dynamic_Aim_Speed(1);
		if(pix_show_idx<=CHAR_HEIGHT*LINE_SHOW_CNT)
		{
			deal_ok=true;
			pix_show_idx=CHAR_HEIGHT*LINE_SHOW_CNT;
			NEW_LINE_AMI=false;
		}
		
	}
	
	
#endif
	
	//�õ������show_index���ϵ�ƫ������
	short pix_offset_line=(pix_show_idx-CHAR_HEIGHT*LINE_SHOW_CNT)/CHAR_HEIGHT+1;   
	
	show_index=(LINE_BUF_MAX+show_index-pix_offset_line)%LINE_BUF_MAX;
	
	
	
	for(char c=0;c<=LINE_SHOW_CNT;c++)  
	{
		gui_print_s(0,LINE(c)+(pix_show_idx-CHAR_HEIGHT*LINE_SHOW_CNT)%CHAR_HEIGHT,string_buff[show_index].str_buff);  //���δӵ�һ����ʾ���ڰ���
		show_index++;
		if(show_index>=LINE_BUF_MAX)show_index=0;
	}
	return deal_ok;
}


//copycnt-1���ַ�
void strcopy_cnt(char* buf, char* src ,char cnt)
{
	char i=0;
	for(i=0;i<cnt;i++)
	{
		buf[i]=src[i];
	}
	buf[i]='\0';
}


//���\nǰ���\r
char r_off_set=0;
char r_kee=0;



short find_huanhang_str_idx(char* src,unsigned short cnt)
{
	r_off_set=0;	
	for(short i=0;i<cnt;i++)
	{
		if(src[i]=='\0')
		{
			break;
		}
		if(src[i]=='\n')
		{
			
			if(src[i-1]=='\r')
			{
				r_off_set=1;
			}

			return i;//ָ��ǰ�ַ�
		}
		//���\r�պ������һ���ַ�����ʱ��������\n
		//ֻ���������ģ����е�����\r��ֱ����ʾ����
		if(src[cnt-1]=='\r'&&src[cnt]=='\n')
		{
			r_kee=1;
			r_off_set=1;
		}
	}
	return -1;
}



void console_log(unsigned short time_delay ,char* fmt,...)
{
	
	char div_flag=0;  //������ʾ��־λ
	va_list ap;
	va_start(ap,fmt);
	vsprintf(firststr_buff,fmt,ap);
	va_end(ap);	
	
	
	
	unsigned short All_str_length=strlen((const char*)firststr_buff);	//������ʾ���ַ�����
	
	if(All_str_length==0)
	{
		return;
	}
	
#if SUPORT_HUANGHANG  //֧�ֻ���
	
	//�����ַ�deλ��,����LINE_CHAR_CNT���ַ�
	short this_line_char_cnt=find_huanhang_str_idx(firststr_buff,LINE_CHAR_CNT);
	
	//LINE_CHAR_CNT���ַ�����\n
	if(this_line_char_cnt!=-1) 
	{

		{
			div_flag=1;
			strcopy_cnt(string_buff[index].str_buff,firststr_buff,this_line_char_cnt-r_off_set); 
			this_line_char_cnt++; //���������в���ʾ
		}

	}
	//LINE_CHAR_CNT���ַ���û��\n
	else
	{
		div_flag=All_str_length/LINE_CHAR_CNT;
		
		if(r_kee)
		{
			r_kee=0;
			//����\r�����\n
			this_line_char_cnt = LINE_CHAR_CNT;
			strcopy_cnt(string_buff[index].str_buff,firststr_buff,this_line_char_cnt-r_off_set); 
			this_line_char_cnt = LINE_CHAR_CNT+1;
		}
		else
		{
			this_line_char_cnt = LINE_CHAR_CNT;
			strcopy_cnt(string_buff[index].str_buff,firststr_buff,this_line_char_cnt-r_off_set); 
		}
	}
	

	
	
	
#else

	div_flag=All_str_length/LINE_CHAR_CNT;  //��ʾ���б�־
	
	//���浱ǰ�ַ���
	strcopy_cnt(string_buff[index].str_buff,firststr_buff,LINE_CHAR_CNT);
#endif
	
	now_str_length = strlen((const char*)string_buff[index].str_buff);
	
	if(now_str_length<last_str_length)
	{
		for(char i=0;i<last_str_length-now_str_length;i++)
		{
			strcat(string_buff[index].str_buff," ");  //����ո������һ�е��Դ�
		}
	}
	last_str_length=now_str_length;
	
	
	if(index>=LINE_SHOW_CNT)  //����Ҫ��ʾ����������Ҫ��ʾ����
	{
		new_line_flag=true;
	}

	index++;
	
	if(index>=LINE_BUF_MAX)  //ѭ�������ַ�
	{
		index=0;
	}
	
	//show
	if(new_line_flag==false) //ֱ������һ�д�ӡ����
	{
		gui_print_s(0,LINE(index),string_buff[index-1].str_buff);
		oled_flush();
		
		//��loop showģʽʹ��������ʱ
		delay_ms(time_delay);
	}
	else
	{
		//�ײ��������б�־λ
		NEW_LINE_AMI=true;
		//ÿ����Ҫ����ƫ���γɶ���
		
#if SUPORT_NEW_LINE_AMI
		
		pix_show_idx+=CHAR_HEIGHT;
		
#else
		pix_show_idx=CHAR_HEIGHT*LINE_SHOW_CNT;
		
#endif
		
		if(LOOP_SHOW_MD==false)
		{
			
			char sta;
			do{
				memset(&oledBuffer, 0x00, FRAME_BUFFER_SIZE);
				sta = !console_loop_show();
				oled_flush();
			}while(sta);
			//��loop showģʽʹ��������ʱ
			delay_ms(time_delay);
		}
		
	}
	
	
	
	
	
#if SUPORT_HUANGHANG  //֧�ֻ���
	
	if(div_flag)
	{
		console_log(300,"%s",&firststr_buff[this_line_char_cnt]);
	}
	
#else
	
	
	if(div_flag)
	{
		console_log(300,"%s",&firststr_buff[LINE_CHAR_CNT]);
	}
	
#endif
	
}






