#include "StdTupes.h"
#include "SPI_Interface.h"
#include "SPI_Service.h"
#include "LCD_Interface.h"
#include "Utils.h"
static u8 REC_Str[20];

void SPI_SendString(u8*str)
{
	u8 i=0;
	for(i=0;str[i];i++)
	{
		/* SEND AND RECIEVE FROM MASTER*/
		REC_Str[i]=SPI_SendRecieve(str[i]);
		_delay_us(10);
	
	}
	_delay_us(10);
	/* END OF THE STRING*/
	REC_Str[i]=SPI_SendRecieve(0x55);
	LCD_GoTo(1,5);
	REC_Str[i]=0;
	/* SHOW THE SLAVE STRING */
	LCD_WriteString(REC_Str);

	
}