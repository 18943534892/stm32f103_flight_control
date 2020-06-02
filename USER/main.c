#include "all.h"

int main(void)
{

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(500000);	 	          //���ڳ�ʼ��Ϊ500000
	delay_init();	                  //��ʱ��ʼ�� 
	LED_Init();		  			          //��ʼ����LED���ӵ�Ӳ���ӿ�
	TIM4_Cap_Init(0xffff,72-1);     //��1Mhz��Ƶ�ʼ���  ң����
	TIM2_PWM_Init(20000,71);        //144��Ƶ��72M/72/20000=50hz
	
//	Moto_Pwm(1880,1880,1880,1880);
//	delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);delay_ms(1000);
	Moto_Pwm(1000,1000,1000,1000);
	LED=0;
	delay_ms(1000);delay_ms(1000);delay_ms(1000);
	while(RC_THROTTLE>YM_Dead-20);                  //�ȴ����Żص���ȫֵ
	LED=1;
	
	PID_controllerInit();  //pid������ʼ��
	
	MPU_Init();					   //��ʼ��MPU6050

	while(mpu_dmp_init())
	{
	delay_ms(20);
	}
	Timer1_Init(9999,71);         //72��Ƶ������Ϊ1M/10000=100HZ -->10ms
	
	while(1)
	{
		delay_ms(10);
		//Moto_Pwm(1110,1110,1110,1110);
		//recode_test();
	}
}
 


