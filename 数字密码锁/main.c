#include"REGX52.h"
#include"Delay.h"
#include"LCD1602.h"
#include"maxk.h"

unsigned char keynum;
unsigned int password,count;

void main()
{

	LCD_Init();
	LCD_ShowString(1, 1, "Password");
	while (1)
	{
		keynum=maxk();
		if (keynum)
		{
			if (keynum <= 10)//���s1��s10�������¡���������
			{
				if (count < 4)//����������С��4
				{
					password *= 10;//��������һλ
					password += keynum % 10;//��ȡһλ����
					count++;//������һ
				}
			}
			LCD_ShowNum(2, 1, password, 4);//������ʾ
			if (keynum == 11)//���s11�������£�ȷ��
			{
				if (password == 2345)
				{
					LCD_ShowString(1,14,"ok ");//���������ȷ
					password = 0;
					count = 0;
					LCD_ShowNum(2, 1, password, 4);
				}
				else  //����
				{
					LCD_ShowString(1,14,"err");//��ʾ����
					password = 0;
					count = 0;
					LCD_ShowNum(2, 1, password, 4);
				}
			}
			if (keynum==12)//���s11�������£�ȡ��
			{
				password = 0;
				count = 0;
				LCD_ShowNum(2, 1, password, 4);
			}
		}
	}
}









