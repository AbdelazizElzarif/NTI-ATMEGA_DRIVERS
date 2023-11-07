#include "StdTupes.h"
#include "NVM.h"
#include "NVM_Servise.h"
#include "KeyPad_Interface.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "Utils.h"
u8 pass_on[5]="12345";
u8 Enter_pass[5]="14567";
static u8 f_pass=0;
void NVM_Pass(void)
{
	static u8 c=0;
	LCD_GoTo(0,0);
	LCD_WriteString((u8*)"Change pass Pass");
	LCD_GoTo(1,0);
	while(c!=5)
	{
		u8 k=KEYPAD_GetKey();
		if(k>='0'&&k<='9')
		{
			pass_on[c++]=k;
			_delay_ms(300);
			LCD_WriteChar(k);
			
		}
		
	}
	NVM_Inter_Enable();
	NVM_Write_Data(0,pass_on[0]);
	NVM_Write_Data(20,0);
	
} 


void Passowrd_Check(void)
{
	LCD_GoTo(0,0);
	LCD_WriteString((u8*)"Enter Pass");
	LCD_GoTo(1,0);
	static u8 c=0;
	f_pass=1;
	while(c!=5)
	{
		u8 k=KEYPAD_GetKey();
		if(k!=NO_KEY)
		{
			Enter_pass[c++]=k;
			LCD_WriteChar(k);
			_delay_ms(250);
		}
	}
	c=0;
	
	for(u8 i=0;i<5;i++)
	{
		if(Enter_pass[i]!=pass_on[i])
		{
			f_pass=0;
			
		}
	}
	if(f_pass)
	{
		LCD_Clear();
		LCD_WriteString((u8*)"Welcome");
	}
	
	
}
u8 Getter_on(void)
{
	return f_pass;
}

