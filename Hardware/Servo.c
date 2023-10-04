#include "stm32f10x.h"                  // Device header
#include "Delay.h"      

void Servo_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//重映射
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM1);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;   //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
//	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	
	TIM_Cmd(TIM1, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}

void Claw_SetAngle(float Angle)
{
	TIM_SetCompare1(TIM1, Angle / 180 * 2000 + 500);
}         

void Claw_Loose()
{
	uint8_t i;
	for(i = 85; i <= 140; i++)
	{
		Claw_SetAngle(i);
		Delay_ms(20);
	}
}

void Claw_Catch()
{
	uint8_t i;
	for(i = 140; i >= 85; i--)
	{
		Claw_SetAngle(i);
		Delay_ms(20);
	}
}

void Servo_SetAngle(float Angle)
{
	TIM_SetCompare4(TIM1, Angle / 180 * 2000 + 500);
} 

void Servo_Back()
{
	uint8_t i;
	for(i = 47; i <= 137; i++)
	{
		Servo_SetAngle(i);
		Delay_ms(20);
	}
}

void Servo_Go()
{
	uint8_t i;
	for(i = 137; i >= 47; i--)
	{
		Servo_SetAngle(i);
		Delay_ms(20);
	}
}

void Table_SetAngle(float Angle)
{
	TIM_SetCompare2(TIM1, Angle / 180 * 2000 + 500);
}

void Table_Turn(uint8_t a)
{
	uint16_t i;
	switch(a)
	{
		case 1:
			for(i = 0; i <= 80; i++)
			{
				Table_SetAngle(i);
				Delay_ms(20);
			}
		break;
		case 2:
			for(i = 80; i <= 160; i++)
			{
				Table_SetAngle(i);
				Delay_ms(20);
			}
		break;
		case 3:
			for(i = 160; i >= 0; i--)
			{
				Table_SetAngle(i);
				Delay_ms(20);
			}
		break;
	}
}
