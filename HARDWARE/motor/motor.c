#include "all.h"

//TIM2 PWM�������
void TIM2_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef gpio;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInit;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ��
	
  gpio.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;     //TIM2 pwmͨ������
  gpio.GPIO_Mode=GPIO_Mode_AF_PP;
  gpio.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&gpio);
	
	//��ʱ��TIM2��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 	
	TIM_OCInit.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInit.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInit.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC1Init(TIM2,&TIM_OCInit);    //ͨ��1
	TIM_OC2Init(TIM2,&TIM_OCInit);    //ͨ��2
	TIM_OC3Init(TIM2,&TIM_OCInit);    //ͨ��3
	TIM_OC4Init(TIM2,&TIM_OCInit);    //ͨ��4
	
	TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2	
	
	TIM_SetCompare1(TIM2,0);
	TIM_SetCompare2(TIM2,0);
	TIM_SetCompare3(TIM2,0);
	TIM_SetCompare4(TIM2,0);
}

void Moto_Pwm(u16 MOTO1_PWM,u16 MOTO2_PWM,u16 MOTO3_PWM,u16 MOTO4_PWM)
{
  TIM_SetCompare1(TIM2,MOTO1_PWM);
	TIM_SetCompare2(TIM2,MOTO2_PWM);
	TIM_SetCompare3(TIM2,MOTO3_PWM);
	TIM_SetCompare4(TIM2,MOTO4_PWM);
}

