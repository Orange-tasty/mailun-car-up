#include "stm32f10x.h"                  // Device header
#include "Delay.H"

void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t Key_GetNum()
{
	uint8_t KeyNum = 0;
	
	int a = 0, b = 0, c = 0;
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
	{
		Delay_ms(20);
		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
		{
			while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0 && c < 100)
			{
				c ++;
				Delay_ms(10);
			}
			if(c >= 100)
			{
				while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0);
				KeyNum = 3;
			}
			else 
			{
				for(b = 0; b < 10; b ++)
				{
					Delay_ms(20);
					if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0)
					{
						a=1;
						while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == 0);
						KeyNum = 2;
					}
				}
				if(a == 0)
				{
					KeyNum = 1;
				}
			}
		}
		a=0;
		c=0;
	}

	return KeyNum;
}
