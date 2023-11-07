#include "StdTupes.h"
#include "MemMap.h"
#include "UART.h"
#include "Utils.h"
static void (*UART_RX_fptr)(void)=NULL_PTR;
static void (*UART_TX_fptr)(void)=NULL_PTR;
void  UART_Init(void)
{
	/* baud rate 9600 53 clock 8 MH*/
	UBRRL=53;
	//UBRRL 16 f=103;
	CLRAR_BIT(UCSRA,U2X);
	/* FRAME 8BIT DATA ISTOP NO PARITY*/
	/* transimeter enable*/
	SET_BIT(UCSRB,TXEN);
	/*recieve enable*/
	SET_BIT(UCSRB,RXEN);
	
}
/* send synch*/
void UART_SendData(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}
/* resieve synch*/
u8 UART_RecieveData(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}
/* uart recieve periodic*/
u8 UART_RecievePerodic(u8 *data)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*data=UDR;
		return 1;
	}
	return 0;
	
}

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}

u8 UART_RecieveNoBlock(void)
{
	return UDR;
}
void UART_RX_InterruptEnaple(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_InterruptDisaple(void)
{
	CLRAR_BIT(UCSRB,RXCIE);
}
void UART_TX_InterruptEnaple(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_InterruptDisaple(void)
{
	CLRAR_BIT(UCSRB,TXCIE);
}
void UART_RX_SetCallBack(void(*localfptr)(void))
{
	UART_RX_fptr=localfptr;
}
void UART_TX_SetCallBack(void(*localfptr)(void))
{
	UART_TX_fptr=localfptr;
}
ISR(UART_RX_vect)
{
	if(UART_RX_fptr!=NULL_PTR)
	{
		UART_RX_fptr();
	}
}
ISR(UART_TX_vect)
{
	if(UART_TX_fptr!=NULL_PTR)
	{
		UART_TX_fptr();
	}
}
