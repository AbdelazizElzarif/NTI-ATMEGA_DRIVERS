#include "StdTupes.h"
#include "ADC_Interface.h"
#include "Sensors_Cfg.h"
#include "Sensors_Interface.h"
/* return temp *10 POLLING */
/* return temp *10 RUNNING */
u16 TEMP_Read(void)
{
	
	u16 volt=ADC_ReadVolt(LM35_CH);
	u16 temp;
	temp=volt;
	return temp;
}

/* return temp *10 FREE RUNNINF */



/****** presure *10 ***********/

u16  PRESURE_Read(void)
{
	u16 adc=ADC_Read(MPX_CH);
	
	u16 press= ((((u32)1000*(adc-55))+460)/921)+150;
	
	return press;
	
}
u16 INTER_Polation(u16 x1,u16 y1,u16 x2,u16 y2,u16 xc)
{
	u16 r=0;
	r=(((y2-y1)*(xc-x1))/(x2-x1))+y1;
	return r;
}
u16 POT_Read(void)
{
	u16 adc=ADC_ReadVolt(MPX_CH);
	return adc;
	
	
	
}
