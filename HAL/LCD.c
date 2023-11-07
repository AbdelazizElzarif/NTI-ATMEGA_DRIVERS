#include "StdTupes.h"
#include "MemMap.h"
#include "DIO_interface.h"
#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include "Utils.h"
#if LCD_MODE==_8_bit
{
	static void WriteIns(u8 ins)
	{

		DIO_WritPin(RS,LOW);
		DIO_WritePort(PA,ins);//8bit 16
		DIO_WritPin(EN,HIGH);
		_delay_ms(1);
		DIO_WritPin(EN,LOW);
		_delay_ms(1);
	}
	static void WriteData(u8 data)
	{
		
		DIO_WritPin(RS,HIGH);
		DIO_WritePort(PA,data);
		DIO_WritPin(EN,HIGH);
		_delay_ms(1);
		DIO_WritPin(EN,LOW);
		_delay_ms(1);
	}
	void LCD_Init(void)
	{
		
		_delay_ms(50);
		WriteIns(0x38);//(SEND DATA 8OR4 BIT,FONT,LINES 16 OR 8)
		WriteIns(0X0E);//OXOE,0X0F (DISPLAY ,CURSOR)
		WriteIns(0X01);//CLEAR LCD
		_delay_ms(1);
		WriteIns(0X06);//INCREASE STOP SHIFT
	}
}
#else

	static void WriteIns(u8 ins)
	{
		

		DIO_WritPin(RS,LOW);
		DIO_WritPin(D7,READ_BIT(ins,7));
		DIO_WritPin(D6,READ_BIT(ins,6));
		DIO_WritPin(D5,READ_BIT(ins,5));
		DIO_WritPin(D4,READ_BIT(ins,4));
		DIO_WritPin(EN,HIGH);
		_delay_ms(1);
		DIO_WritPin(EN,LOW);
		_delay_ms(1);
		
		DIO_WritPin(D7,READ_BIT(ins,3));
		DIO_WritPin(D6,READ_BIT(ins,2));
		DIO_WritPin(D5,READ_BIT(ins,1));
		DIO_WritPin(D4,READ_BIT(ins,0));
		DIO_WritPin(EN,HIGH);
		_delay_ms(1);
		DIO_WritPin(EN,LOW);
		_delay_ms(1);
	}
	static void WriteData(u8 data)
	{
		DIO_WritPin(RS,HIGH);
		DIO_WritPin(D7,READ_BIT(data,7));
		DIO_WritPin(D6,READ_BIT(data,6));
		DIO_WritPin(D5,READ_BIT(data,5));
		DIO_WritPin(D4,READ_BIT(data,4));
		DIO_WritPin(EN,HIGH);
		_delay_ms(1);
		DIO_WritPin(EN,LOW);
		_delay_ms(1);
		
		DIO_WritPin(D7,READ_BIT(data,3));
		DIO_WritPin(D6,READ_BIT(data,2));
		DIO_WritPin(D5,READ_BIT(data,1));
		DIO_WritPin(D4,READ_BIT(data,0));
		DIO_WritPin(EN,HIGH);
		_delay_ms(1);
		DIO_WritPin(EN,LOW);
		_delay_ms(1);
	}
	void LCD_Init(void)
	{
		
		_delay_ms(50);
		WriteIns(0X02);
		WriteIns(0x28);//(SEND DATA 8OR4 BIT,FONT,LINES 16 OR 8)
		WriteIns(0X0c);//OXOE,0X0F (DISPLAY ,CURSOR)
		WriteIns(0X01);//CLEAR LCD
		_delay_ms(1);
		WriteIns(0X06);//INCREASE STOP SHIFT
	}

#endif

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}
void LCD_GoTo(u8 line,u8 cell)
{
	if(line==0)
	{
		WriteIns((cell+0x80));
	}
	else if(line==1)
	{
		WriteIns(cell+0x80+0x40);
	}
	else if(line==2)
	{
		WriteIns(cell+0x94);
		
	}
	else if(line==3)
	{
		WriteIns(cell+0xD4);
	}
	
}
void LCD_WriteString(u8*str)
{
	u8 i;
	for(i=0;i<16&&str[i];i++)
	{
		WriteData(str[i]);
		
	}
	
}
void LCD_WriteNum(s32 num)
{
	u8 str[20];
	u8 i=0,j;
	if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num)
	{
		str[i]=(num%10)+'0';
		i++;
		num/=10;
	}
	for(j=i;j>0;j--)
	{
		LCD_WriteChar(str[j-1]);
		
	}
}
void LCD_WriteBinary(s32 num)
{
	s8 i=0;
	
	for(i=7;i>=0;i--)
	{
			LCD_WriteChar(READ_BIT(num,i)+'0');
	}
}
void LCD_WriteHex(u8 num)
{
	u8 b0=0,b1=0;
	b1=num>>4;
	b0=num&0x0f;
	if(b1<10)
	{
		LCD_WriteChar(b1+'0');
	}
	else
	{
		LCD_WriteChar(b1-10+'A');
	}
	if(b0<10)
	{
		LCD_WriteChar(b0+'0');
	}
	else
	{
		LCD_WriteChar(b0-10+'A');
	}
}
void LCD_WriteNum_4D(s16 num)
{
	/*u8 str[4];
	u8 i=0;
	for(i=0;i<4;i++)
	{
		str[i]=num%10;
		num=num/10;
	}
	for(i=4;i>0;i--)
	{
		LCD_WriteChar(str[i-1]+'0');
	}
	*/
	LCD_WriteChar((num%10000)/1000+'0');
	LCD_WriteChar((num%1000)/100+'0');
	LCD_WriteChar((num%100)/10+'0');
	LCD_WriteChar((num%10)/1+'0');
}
void LCD_MoveOn(u8*str)
{
	u8 l,i,j,m;
	for(l=0;str[l];l++);
	for(m=0;m<2;m++)
	{
		LCD_GoTo(m,0);
		for(i=0;i<l;i++)
		{
			for(j=l-i-1;j<l;j++)
			{
				LCD_WriteChar(str[j]);
				
			}
			LCD_GoTo(m,0);
			_delay_ms(500);
		}
		for(i=0;i<20;i++)
		{
			LCD_GoTo(m,i);
			LCD_WriteChar(' ');
			for(j=0;j<l;j++)
			{
				LCD_WriteChar(str[j]);
			}
			_delay_ms(500);
		}
	}
	
}
void LCD_Clear(void)
{
	WriteIns(1);
	_delay_ms(10);
}
void LCD_CustomChar(u8 adress,u8*pattern)
{
	
	WriteIns(0x40+adress*8);
	u8 i;
	for(i=0;i<8;i++)
	{
		LCD_WriteChar(pattern[i]);
		
	}
	WriteIns(0X80);
	
}
void LCD_Kill(void)
{
	u8 i;
	for(i=2;i<16;i++)
	{
		LCD_GoTo(0,i-1);
		LCD_WriteChar(' ');
		LCD_WriteChar(1);
		_delay_ms(300);
	}
	LCD_GoTo(0,i-1);
	LCD_WriteChar(3);
	_delay_ms(500);
	LCD_GoTo(0,i-1);
	LCD_WriteChar(2);
	
}
void LCD_WriteStringGoto(u8 line,u8 cell,u8*str)
{
	LCD_GoTo(line,cell);
	LCD_WriteString(str);
}
void LCD_ClearPositions(u8 line,u8 cell,u8 NoCells)
{
	LCD_GoTo(line,cell);
	u8 i;
	for(i=0;i<NoCells;i++)
	{
		LCD_WriteChar(' ');
	}
}




