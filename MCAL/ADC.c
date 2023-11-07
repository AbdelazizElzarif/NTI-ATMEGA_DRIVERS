#include "MemMap.h"
#include "StdTupes.h"
#include "Utils.h"
#include "ADC_Interface.h"
static u8 f=0;
#include "LCD_Interface.h"
extern volatile u32 c;
static void (*ADC_Fptr) (void)=NULL_PTR;

void ADC_Init(ADC_VoltRef_Type vref,ADC_Prescaler_type scaler )
{
	switch(vref)
	{
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLRAR_BIT(ADMUX,REFS1);
		break;
		case VREF_AREF:
		CLRAR_BIT(ADMUX,REFS0);
		CLRAR_BIT(ADMUX,REFS1);
		break;
		
	}
	#if ADC_State==FREE_RUNNING
	SET_BIT(ADCSRA,ADATE);
	SET_BIT(ADCSRA,ADIE);
	#endif
	/*PRESCALLER*/
	ADCSRA&=0xf8;//1111111000
	scaler&=0x07;
	ADCSRA|=scaler;
	
	/*ENABLE EDC*/
	SET_BIT( ADCSRA,ADEN);

}

u16 ADC_Read(ADC_Channel_type CH)
{
	u16 r=0;
	/* set channel mux*/
	ADMUX=ADMUX&0XE0;
	ADMUX=ADMUX+CH;
	

	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	/* w8 ADC finish**/
	while(READ_BIT(ADCSRA,ADSC));//blocking busy wait
	
	
	
	/*get read*/
	r=ADCL;
	r=r|(ADCH<<8);
	/*
    if(READ_BIT(ADCH,0))
	{
		SET_BIT(r,8);
	}
	 if(READ_BIT(ADCH,1))
	 {
		 SET_BIT(r,9);
	 }
	 */
	
   /*if adcl==1
   r=ADCL>>6;
   r|=ADCH<<2;
   */
	return r;
}
void ADC_StartConversion(ADC_Channel_type CH)
{
	/* set channel mux*/
	/*
	if(f==0)
	{
		ADMUX=ADMUX&0XE0;
		ADMUX=ADMUX+CH;
		
		/*start conversion*/
		/*SET_BIT(ADCSRA,ADSC);
		f=1;
		 */
	/*}*/
	ADMUX=ADMUX&0XE0;
	ADMUX=ADMUX+CH;
	

	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	
}
u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC));//blocking busy wait
	u16 r=ADCL;
	r=r|(ADCH<<8);
	/*
    if(READ_BIT(ADCH,0))
	{
		SET_BIT(r,8);
	}
	 if(READ_BIT(ADCH,1))
	 {
		 SET_BIT(r,9);
	 }
	 */
	
   /*if adcl==1
   r=ADCL>>6;
   r|=ADCH<<2;
   */
	return r;
}
u8 ADC_GetReadPerodic(u16*pdata)
{
	// perodic check pooling
	if(!(READ_BIT(ADCSRA,ADSC)))
	{
		u16 r=ADCL;
		r=r|(ADCH<<8);
		f=0;
		*pdata=r;
		return 1;
	}
	return 0;
}
u16 ADC_GetReadNoLock(void)
{
	u16 r=ADCL;
	r=r|(ADCH<<8);
	return r;
}
u16 ADC_ReadVolt(ADC_Channel_type CH)
{
	u16 volt;
	u16 adc;
	#if ADC_State==FREE_RUNNING
	adc=ADC_GetReadNoLock();
	#elif ADC_State==SINGLE_CONVERSION
	adc=ADC_Read(CH);
	#endif
	
	volt=(adc*(u32)5000)/1023;//high resolution 
	return volt;
}
/*
u16 ADC_ReadVolt_RUNNING(ADC_Channel_type CH)
{
	u16 volt;
	u16 adc;
	adc=ADC_GetReadNoLock();
	volt=(adc*(u32)5000)/1023;//high resolution
	return volt;
}
*/
/********* **************/
void ADC_SetCallBack(void(*LocalFptr)(void))
{
	ADC_Fptr=LocalFptr;
}

ISR(ADC_vect)
{
	if(ADC_Fptr!=NULL_PTR)
	{
		ADC_Fptr();
	

	}
}