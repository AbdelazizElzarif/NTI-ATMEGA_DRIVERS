#include "StdTupes.h"
#include "DIO_interface.h"
#include "Utils.h"
#define  KEYPAD_PRG 1
#include "KeyPad_Interface.h"
#include "KeyPad_Cfg.h"

void KEYPAD_Init(void)
{
	u8 r;
	for(r=0;r<ROWS;r++)
	{
		DIO_WritPin(FIRST_OUTPUT-r,HIGH);
	}
}
u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	for(r=0;r<ROWS;r++)
	{
		DIO_WritPin(FIRST_OUTPUT-r,LOW);
		for(c=0;c<COLS+1;c++)
		{
			if(c==3)
			{
				c=4;
			}
			if(DIO_ReadPin(FIRST_INPUT-c)==0)
			{
				if(c==4)
				{
					c=3;
				}
				key=KeysArr[r][c];
				if(c==3)
				{
					c=4;
				}
				_delay_ms(10);
				while(DIO_ReadPin(FIRST_INPUT-c)==0);
				_delay_ms(10);
				break;
			}
		}
		DIO_WritPin(FIRST_OUTPUT-r,HIGH);
	}
	return key;
}