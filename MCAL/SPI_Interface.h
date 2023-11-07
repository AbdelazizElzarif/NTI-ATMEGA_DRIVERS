
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
typedef enum
{
	MATER,
	SLAVE
	}SPIMode_type;
void SPI_Init(SPIMode_type type);
u8 SPI_SendRecieve(u8 data);
/***** SLAVE**********/
void SPI_RX_InterruptEnaple(void);
void SPI_RX_InterruptDisaple(void);

void SPI_RX_SetCallBack(void(*localfptr)(void));





#endif /* SPI_INTERFACE_H_ */