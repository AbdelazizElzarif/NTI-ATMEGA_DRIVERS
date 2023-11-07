#include "StdTupes.h"
#include "SPI_Interface.h"
#include "MemMap.h"
#include "Utils.h"

static void (*SPI_RX_fptr)(void)=NULL_PTR;
void SPI_Init(SPIMode_type type)
{
	if(type==MATER)
	{
		//CLC 2MH
		SET_BIT(SPCR,MSTR);
	}
	else
	{
		CLRAR_BIT(SPCR,MSTR);
	}
	
	SET_BIT(SPCR,SPE);
}
u8 SPI_SendRecieve(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_RX_InterruptEnaple(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPI_RX_InterruptDisaple(void)
{
	CLRAR_BIT(SPCR,SPIE);
}

void SPI_RX_SetCallBack(void(*localfptr)(void))
{
	SPI_RX_fptr=localfptr;
}
ISR(SPI_STC_vect)
{
	if(SPI_RX_fptr!=NULL_PTR)
	{
		SPI_RX_fptr();
	}
}