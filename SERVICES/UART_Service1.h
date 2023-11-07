

#ifndef UART_SERVICE1_H_
#define UART_SERVICE1_H_

void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
u32 UART_ReceiveNumber(u32 num);
u32 endian_convert(u32 num);
u16 endian_convert_16(u16 num);

void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);


void UART_SendStringAshync(u8*str);
/* periodic check*/
void BCM_Init(void);
void BCM_Send(u8*str);
void BCM_Runaable(void);


u8 UART_BufferGetter(u8*str);
typedef enum{
	BIG_ENDIAN,
	LITTLE_ENDIAN,
}Endian_t;

Endian_t endian_check(void);



#endif /* UART_SERVICE1_H_ */