

#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#define ERROR 0
#define SUCCESS 1

#include "TWI.h"

void EEPROM_Init(void);
u8 EEPROM_Write_Byte(u16 u16addr,u8 u8data);
u8 EEPROM_Read_Byte(u16 u16addr,u8 *u8data);




#endif /* EXTERNAL_EEPROM_H_ */