#include "MemMap.h"
#include "StdTupes.h"
#include "Utils.h"
#include "Segment.h"
#include "DIO_interface.h"

void segment_display_bcd_mpx(u16 num)
{
	
	u8 d0,d1,d2,d3;
	d0=num%10;
	d1=(num/10)%10;
	d2=(num/100)%10;
	d3=(num/1000)%10;
	DIO_WritPin(PINA3,LOW);
	DIO_WritPin(PINA2,HIGH);
	DIO_WritPin(PINB5,HIGH);
	DIO_WritPin(PINB6,HIGH);
	DIO_WritPin(PINB0,READ_BIT(d0,0));
	DIO_WritPin(PINB1,READ_BIT(d0,1));
	DIO_WritPin(PINB2,READ_BIT(d0,2));
	DIO_WritPin(PINB4,READ_BIT(d0,3));
	_delay_ms(5);
	
	DIO_WritPin(PINA3,HIGH);
	DIO_WritPin(PINA2,LOW);
	DIO_WritPin(PINB5,HIGH);
	DIO_WritPin(PINB6,HIGH);
	DIO_WritPin(PINB0,READ_BIT(d1,0));
	DIO_WritPin(PINB1,READ_BIT(d1,1));
	DIO_WritPin(PINB2,READ_BIT(d1,2));
	DIO_WritPin(PINB4,READ_BIT(d1,3));
	_delay_ms(5);
	
	DIO_WritPin(PINA3,HIGH);
	DIO_WritPin(PINA2,HIGH);
	DIO_WritPin(PINB5,LOW);
	DIO_WritPin(PINB6,HIGH);
	DIO_WritPin(PINB0,READ_BIT(d2,0));
	DIO_WritPin(PINB1,READ_BIT(d2,1));
	DIO_WritPin(PINB2,READ_BIT(d2,2));
	DIO_WritPin(PINB4,READ_BIT(d2,3));
	_delay_ms(5);
	
	DIO_WritPin(PINA3,HIGH);
	DIO_WritPin(PINA2,HIGH);
	DIO_WritPin(PINB5,HIGH);
	DIO_WritPin(PINB6,LOW);
	DIO_WritPin(PINB0,READ_BIT(d3,0));
	DIO_WritPin(PINB1,READ_BIT(d3,1));
	DIO_WritPin(PINB2,READ_BIT(d3,2));
	DIO_WritPin(PINB4,READ_BIT(d3,3));
	_delay_ms(5);
	
	
	
	


	
	
}

void segment_display(u8 num)
{
	const u8 arr[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67};
	PORTC=arr[num];
}
void segment_display2(u8 num)
{
	u8 d0,d1;
	const u8 arr[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67};
	d0=num%10;
	d1=num/10;
	PORTC=arr[d1];
	PORTD=arr[d0];
}
void segment_display_same_port(u8 num)
{
	u8 d0,d1;
	const u8 arr[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67};
	d0=num%10;
	d1=num/10;
	PORTC=0b01000000;
	PORTA=arr[d0]<<1;
	_delay_ms(20);
	PORTC=0b10000000;
	PORTA=arr[d1]<<1;
	_delay_ms(20);
	
}

void segment_display_bcd(u8 num)
{
	u8 d0,d1;
	d0=num%10;
	d1=num/10;
	PORTC=(d0<<4)|d1;
	_delay_ms(400);
	
}
void segment_4511(u8 num)
{
	PORTD=num;
	_delay_ms(200);
}
void segment_display_bcd_hex(u8 num)
{
	
	u8 i,j,x=1;
	u8 s_bitd0=0,s_bitd1=0;
	

	for(i=0,j=4;i<4;i++,j++)
	{
		s_bitd0+=x*((num>>i)&1);
		s_bitd1+=x*((num>>j)&1);
		x=x*2;
	}
	PORTC=(s_bitd0<<4)|s_bitd1;
	_delay_ms(500);
	
}
void segment_display_same_bord_hex(u8 num)
{
	const u8 arr_hex[6]={0x77,0X7C,0X39,0X5E,0X79,0X71};
	const u8 arr_num[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67};
	u8 i,j,x=1;
	u8 s_bitd0=0,s_bitd1=0;
	

	for(i=0,j=4;i<4;i++,j++)
	{
		s_bitd0+=x*((num>>i)&1);
		s_bitd1+=x*((num>>j)&1);
		x=x*2;
	}
	if(s_bitd0>=10)
	{
		s_bitd0=arr_hex[s_bitd0-10]<<1;
	}
	else
	{
		s_bitd0=arr_num[s_bitd0]<<1;
	}
	if(s_bitd1>=10)
	{
		s_bitd1=arr_hex[s_bitd1-10]<<1;
	}
	else
	{
		s_bitd1=arr_num[s_bitd1]<<1;
	}
	PORTC=0b01000000;
	PORTA=s_bitd0;
	_delay_ms(20);
	PORTC=0b10000000;
	PORTA=s_bitd1;
	_delay_ms(20);
}
void segment_display_same_bord_incr_decr(u8 num)
{
	u8 d0,d1;
	const char arr[10]={0x3F,0x06,0x5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67};
	d0=num%10;
	d1=num/10;
	
	PORTC=0b01000000;
	PORTA=arr[d0]<<1;
	_delay_ms(20);
	PORTC=0b10000000;
	PORTA=arr[d1]<<1;
	_delay_ms(20);
}
