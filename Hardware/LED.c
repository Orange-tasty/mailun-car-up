#include "stm32f10x.h"                  // Device header

void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_13);
}

void LED_ON()
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}

void LED_OFF()
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}

void LED_Turn()
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_13) == 0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	}
}

//void LED2_ON()
//{
//	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
//}

//void LED2_OFF()
//{
//	GPIO_SetBits(GPIOA,GPIO_Pin_2);
//}

//void LED2_Turn()
//{
//	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2) == 0)
//	{
//		GPIO_SetBits(GPIOA,GPIO_Pin_2);
//	}
//	else
//	{
//		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
//	}
//}

