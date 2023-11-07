#include "MemMap.h"
#include "StdTupes.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "DIO_Cfg.h"
#include "DIO_private.h"

void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLRAR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLRAR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLRAR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLRAR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLRAR_BIT(DDRA,pin_num);
			CLRAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLRAR_BIT(DDRB,pin_num);
			CLRAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLRAR_BIT(DDRC,pin_num);
			CLRAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLRAR_BIT(DDRD,pin_num);
			CLRAR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		case INPULL:
		switch(port)
		{
			case PA:
			CLRAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLRAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLRAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLRAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		
	}
	
	
}
void DIO_WritPin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	switch(volt)
	{
		case HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		case LOW:
		switch(port)
		{
			case PA:
			CLRAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLRAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLRAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLRAR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
}
}
DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		volt=READ_BIT(PIND,pin_num);
		break;
		
	}
	return volt;
}
void DIO_PinToggle(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	switch(port)
	{
		case PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		case PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		case PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		case PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;
	}
}
void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		PORTC=data;
		break;
		case PD:
		PORTD=data;
		break;
	}
}
u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 data=0;
	switch(port)
	{
		case PA:
		data=PORTA;
		break;
		case PB:
		data=PORTB;
		break;
		case PC:
		data=PORTC;
		break;
		case PD:
		data=PORTD;
		break;
	}
	return data;
}
void DIO_InintPins(void)
{
	DIO_Pin_type i;
	for(i=PINA0 ;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,DIO_PinsStatusArr[i]);
	}
}


