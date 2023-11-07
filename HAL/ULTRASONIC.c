#include "StdTupes.h"
#include "DIO_interface.h"
#include "ULTRASONIC_Cfg.h"
#include "ULTRASONIC_Interface.h"
#include "Timers.h"
#include "Utils.h"
volatile static u8 f;
volatile static u16 t1,t2,t,d;
volatile static u8 c=0;
static void count (void)
{
	c++;
}

 static void ULTRASONIC_Trriger(void)
{
	
	DIO_WritPin(TRIGGER_PIN,HIGH);
	_delay_us(10);
	DIO_WritPin(TRIGGER_PIN,LOW);
}
static void ECHO_Time(void)
{
	
	if(f==0)
	{
		t1=ICR1;
		c=0;
		
		Timer1_InputCaptureEdge(FALLING);
		f=1;
	}
	else if(f==1)
	{
		t2=ICR1;
		f=2;
		Timer1_ICU_InterruptDisable();
	}
}
/******** BLOCKING ************** */
/*
u16 ULTRASONIC_Distance(void)
{
	
    _delay_ms(60);
	ULTRASONIC_Trriger();
	Timer1_ICU_InterruptEnable();
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_SetCallBack(ECHO_Time);
	u32 t5=0;
	f=0;
	t5=0;
	while(f<2)
	{
		t5++;
		_delay_us(1);
	}
	LCD_GoTo(1,8);
	LCD_WriteNum(t5);
	t=t2-t1;
	d=t/58;
	return d;
	
}
*/
/* *************************PERIODIC CHECK *************** */ 
u16 ULTRASONIC_Distance(u16 *d)
{
	if(f==0)
	{
		_delay_ms(60);
		ULTRASONIC_Trriger();
		Timer1_ICU_InterruptEnable();
		Timer1_InputCaptureEdge(RISING);
		Timer1_ICU_SetCallBack(ECHO_Time);
		Timer1_OVF_InterruptEnable();
		Timer1_OVF_SetCallBack(count);
	}
	if(f==2)
	{
		t=(65535*c)+(t2-t1);
		*d=t/58;
		f=0;
		return 1;
	}
	return 0;
	
	
	
}
