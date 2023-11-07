#include "StdTupes.h"
#include "DIO_interface.h"
#include "Smart_Home_Service.h"
#include "LCD_Interface.h"
#include "UART.h"
Bool_t Home_sring_num(u8*m_str,u8*str,u8*num)
{
	Bool_t r=TRUE;
	u8 i=0,l_num=0;
	while(m_str[i]!=' '&&i<10)
	{
		if(m_str[i]>='a'&&m_str[i]<='z')
		{
			str[i]=m_str[i];
			i++;
		}
		else
		{
			r=FALSE;
			break;
		}
		
	}
	str[i++]=0;
	if(r==TRUE)
	{
		while(m_str[i]!=0)
		{
			if(m_str[i]-'0'>=0&&m_str[i]-'0'<='9')
			{
				l_num=l_num*10+m_str[i]-'0';
			}
			else
			{
				r=FALSE;
				break;
			}
			i++;
			
		}
		
	}
	*num=l_num;
	return r;
}
Bool_t sring_cmp(u8*str1,u8*str2)
{
	Bool_t r=TRUE;
	u8 i;
	for(i=0;str1[i]||str2[i];i++)
	{
		if(str1[i]!=str2[i])
		{
			r=FALSE;
			break;
		}
	}
	return r;
}
void LedOn(u8 led)
{
	switch(led)
	{
		case 0:
		DIO_WritPin(PINC0,HIGH);
		UART_SendString((u8*)"valid num");
		break;
		case 1:
		DIO_WritPin(PINC1,HIGH);
		UART_SendString((u8*)"valid num");
		break;
		case 2:
		DIO_WritPin(PINC2,HIGH);
		UART_SendString((u8*)"valid num");
		break;
		default:
		//LCD_GoTo(1,0);
		//LCD_WriteString((u8*)"invalid num");
		//CD_WriteString((u8*)"       ");
		UART_SendString((u8*)"invalid num");
		
		break;
	}
}
void LedOff(u8 led)
{
	switch(led)
	{
		case 0:
		DIO_WritPin(PINC0,LOW);
		UART_SendString((u8*)"valid num");
		break;
		case 1:
		DIO_WritPin(PINC1,LOW);
		UART_SendString((u8*)"valid num");
		break;
		case 2:
		DIO_WritPin(PINC2,LOW);
		UART_SendString((u8*)"valid num");
		break;
		default:
		//LCD_GoTo(1,0);
		//LCD_WriteString((u8*)"invalid num");
		//LCD_WriteString((u8*)"       ");
		UART_SendString((u8*)"invalid num");
		break;
		
	}
}