#include "StdTupes.h"
#include "DIO_interface.h"
#include "MOTORInterface.h"
#include "MOTOR_Cfg.h"
#include "Utils.h"
MOTOR_Init_type arr[4]={{M1_IN1,M1_IN2},{M2_IN1,M2_IN2},{M3_IN1,M3_IN2},{M4_IN1,M4_IN2}};
void MOTOR_Stop(MOTOR_type m)
{
	DIO_WritPin(arr[m].n1,LOW);
	DIO_WritPin(arr[m].n2,LOW);
	/*
	switch(m)
	{
		case M1:
		DIO_WritPin(M1_IN1,LOW);
		DIO_WritPin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritPin(M2_IN1,LOW);
		DIO_WritPin(M2_IN2,LOW);
		break;
		case M3:
		DIO_WritPin(M3_IN1,LOW);
		DIO_WritPin(M3_IN2,LOW);
		break;
		case M4:
		DIO_WritPin(M4_IN1,LOW);
		DIO_WritPin(M4_IN2,LOW);
		break;
		
	}
	*/
}
void MOTOR_CW(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		DIO_WritPin(M1_IN1,LOW);
		DIO_WritPin(M1_IN2,HIGH);
		break;
		case M2:
		DIO_WritPin(M2_IN1,LOW);
		DIO_WritPin(M2_IN2,HIGH);
		break;
		case M3:
		DIO_WritPin(M3_IN1,LOW);
		DIO_WritPin(M3_IN2,HIGH);
		break;
		case M4:
		DIO_WritPin(M4_IN1,LOW);
		DIO_WritPin(M4_IN2,HIGH);
		break;
		
	}
}
void MOTOR_CCW(MOTOR_type m)
{
	switch(m)
	{
		case M1:
		DIO_WritPin(M1_IN1,HIGH);
		DIO_WritPin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritPin(M2_IN1,HIGH);
		DIO_WritPin(M2_IN2,LOW);
		break;
		case M3:
		DIO_WritPin(M3_IN1,HIGH);
		DIO_WritPin(M3_IN2,LOW);
		break;
		case M4:
		DIO_WritPin(M4_IN1,HIGH);
		DIO_WritPin(M4_IN2,LOW);
		break;
		
	}
}
