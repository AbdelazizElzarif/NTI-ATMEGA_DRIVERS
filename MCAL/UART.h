


#ifndef UART_H_
#define UART_H_

void  UART_Init(void);
void UART_SendData(u8 data);
u8 UART_RecieveData(void);
u8 UART_RecievePerodic(u8*data);
void UART_SendNoBlock(u8 data);
u8 UART_RecieveNoBlock(void);
void UART_RX_InterruptEnaple(void);
void UART_RX_InterruptDisaple(void);
void UART_TX_InterruptEnaple(void);
void UART_TX_InterruptDisaple(void);
void UART_RX_SetCallBack(void(*localfptr)(void));
void UART_TX_SetCallBack(void(*localfptr)(void));



#endif /* UART_H_ */