#include <REGX52.H>
/**
   *@brief   ��ʱ��0��ʼ����1ms
   *@param    ��
   *@retval   ��
   */
void timer0_init()
{
		TMOD &= 0xF0;			//���ö�ʱ��ģʽ
		TMOD |= 0x01;			//���ö�ʱ��ģʽ
		TL0 = 0x66;				//���ö�ʱ��ʼֵ
		TH0 = 0xFC;				//���ö�ʱ��ʼֵ
		TF0 = 0;				//���TF0��־
		TR0 = 1;
		ET0 = 1;
		EA = 1;
		PT0 = 0;//��ʱ��0 ��ʼ��ʱ
	
}
/*��ʱ���ж�ģ��
void timer0_routine() interrupt 1
{
	static unsigned int count;
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;
	count++;
	if (count>=1000)
	{ 
		count = 0;
	}
	
}
*/