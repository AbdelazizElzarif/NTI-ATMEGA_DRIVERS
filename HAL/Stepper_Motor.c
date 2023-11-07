#include "Stepper_Motor_Inerface.h"
#include "Utils.h"
void STEPPER_UNIBOLAR_CCW(void)
{
	
	DIO_WritPin(COIL1A,HIGH);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,HIGH);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,HIGH);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,HIGH);
	_delay_ms(DELAY);
}
void STEPPER_UNIBOLAR_CW(void)
{

	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,HIGH);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,HIGH);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,HIGH);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,HIGH);
	_delay_ms(DELAY);
}

void STEPPER_BIBOLAR_CCW(void)
{
	DIO_WritPin(COIL1A,HIGH);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,HIGH);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,HIGH);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,HIGH);
	_delay_ms(DELAY);
	
}
void Stepper_Step_Angle(u16 angle)
{
	angle=(angle/.72)+.5;
	for(u16 i=0;i<angle;i++)
	{
		 STEPPER_UNIBOLAR_CW();
	}
}
void Stepper_Step_Rotate(u32 rotata)
{
	rotata=rotata*500;
	for(u32 i=0;i<rotata;i++)
	{
		 STEPPER_UNIBOLAR_CW();
	}
}
void STEPPER_BIBOLAR_CW(void)
{
	
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,HIGH);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,HIGH);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,LOW);
	DIO_WritPin(COIL2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritPin(COIL1A,LOW);
	DIO_WritPin(COIL2A,LOW);
	DIO_WritPin(COIL1B,HIGH);
	DIO_WritPin(COIL2B,LOW);
	_delay_ms(DELAY);
}