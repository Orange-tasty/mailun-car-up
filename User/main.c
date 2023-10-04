#include "stm32f10x.h"                  // Device header
#include "Delay.H"
#include "OLED.H"
#include "LED.H"
#include "Servo.H"
#include "Key.H"
#include "StepMotor.H"

uint8_t KeyNum;
float Angle = 85;

int main()
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	LED_Init();
	StepMotor_Init();
	OLED_ShowString(1,1,"Angle:");
	
	while(1)
	{
		uint8_t i;
		KeyNum=Key_GetNum();
		
		Table_SetAngle(10);
		Delay_ms(1000);
		
		Table_SetAngle(90);
		Delay_ms(1000);
		
		Table_SetAngle(10);
		Delay_ms(1000);
//		if(KeyNum == 1)
//		{
//			Table_Turn(1);
//			Servo_Back();
//			Claw_Loose();			
//			StepMotor_Run(1, 200);
//			StepMotor_Run(1, 200);
//			StepMotor_Run(1, 200);
////			StepMotor_Run(1, 200);
////			StepMotor_Run(1, 120);
//					
//			Delay_ms(1000);
//			
//			Claw_Catch();
//			
//			Delay_ms(2000);
//			
//			StepMotor_Run(0, 200);
//			StepMotor_Run(0, 200);
//			StepMotor_Run(0, 200);
////			StepMotor_Run(0, 200);
////			StepMotor_Run(0, 120);
//			
//			Delay_ms(2000);
//			Servo_Go();
			
//		}		
	}
}
