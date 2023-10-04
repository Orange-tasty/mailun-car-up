#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void StepMotor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
}

void StepMotor_Run(uint8_t dir, uint8_t step)
{
	uint8_t i;
	switch(dir)
	{
		case 0 : GPIO_ResetBits(GPIOB, GPIO_Pin_8); break;
		case 1 : GPIO_SetBits(GPIOB, GPIO_Pin_8); break;
		default : break;
	}
	for(i = 0; i < step; i++)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_9);
		Delay_ms(1);
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
		Delay_ms(1);
	}
}                       
