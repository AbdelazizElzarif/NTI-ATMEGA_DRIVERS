
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
void LCD_Init(void);
void LCD_Clear(void);

void LCD_MoveOn(u8*str); 
void LCD_WriteString(u8*str);
void LCD_WriteNum(s32 num);
void LCD_WriteNum_4D(s16 num);
void LCD_WriteBinary(s32 num);
void LCD_WriteHex(u8 num);
void LCD_WriteChar(u8 ch);
void LCD_Clear(void);
void LCD_CustomChar(u8 adress,u8*pattern);
void LCD_GoTo(u8 line,u8 cell);
void LCD_WriteStringGoto(u8 line,u8 cell,u8*str);
void LCD_Kill(void);
void LCD_ClearPositions(u8 line,u8 cell,u8 NoCells);






#endif /* LCD_INTERFACE_H_ */