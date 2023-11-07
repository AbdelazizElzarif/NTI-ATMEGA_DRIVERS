
#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#define _4_BIT 0
#define _8_bit 1
/* LCD MODE 4 BIT OR 8BIT */
#define LCD_MODE _4_BIT

#define RS PINA3
#define EN PINA2

/* LCD 8bit port */
#define  LCD_Port PA
/* LCD 4 BIT BIN */
#define D4 PINB0
#define D5 PINB1
#define D6 PINB2
#define D7 PINB3

#endif /* LCD_CFG_H_ */