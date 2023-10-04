#ifndef __SERVO_H__
#define __SERVO_H__

void Servo_Init();
void Claw_SetAngle(float Angle);
void Claw_Catch();
void Claw_Loose();
void Servo_SetAngle(float Angle);
void Servo_Back();
void Servo_Go();
void Table_SetAngle(float Angle);
void Table_Turn(uint8_t a);
	
#endif
