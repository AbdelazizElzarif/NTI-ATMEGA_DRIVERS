
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "StdTupes.h"
#define FREE_RUNNING      1
#define SINGLE_CONVERSION 0
#define ADC_State FREE_RUNNING

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256V,
	}ADC_VoltRef_Type;
	
	typedef enum{
		ADC_SCALER_2=1,
		ADC_SCALER_4,
		ADC_SCALER_8,
		ADC_SCALER_16,
		ADC_SCALER_32,
		ADC_SCALER_64,
		ADC_SCALER_128,
	}ADC_Prescaler_type;
	typedef enum{
		CH_0=0,
		CH_1,
		CH_2,
		CH_3,
		CH_4,
		CH_5,
		CH_6,
		CH_7
	}ADC_Channel_type;

void ADC_Init(ADC_VoltRef_Type vref,ADC_Prescaler_type scaler );
u16 ADC_Read(ADC_Channel_type CH);
u16 ADC_ReadVolt(ADC_Channel_type CH);
void ADC_SetCallBack(void(*LocalFptr)(void));
void ADC_StartConversion(ADC_Channel_type CH);
u16 ADC_GetReadNoLock(void);
u16 ADC_ReadVolt_RUNNING(ADC_Channel_type CH);




#endif /* ADC_INTERFACE_H_ */