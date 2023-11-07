#include "StdTupes.h"
#include "MemMap.h"
#include "NVM.h"
#include "Utils.h"

static void (*NVM_WRITE_Fptr) (void)=NULL_PTR;

void NVM_Write_Data(u16 adress,u8 data)
{
	while(EECR & (1<<EEWE));
	EEAR = adress;
	EEDR = data;
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);
}
/*u8 NVM_Write_Data(u16 adress,u8 data)
{
	u8 r=0;
	while(EECR & (1<<EEWE));
	if(READ_BIT(EECR,EEWE)==0)
	{
		EEAR = adress;
		EEDR = data;
		EECR|=(1<<EEMWE);
		EECR|=(1<<EEWE);
		r=1;
	}
	return r;
	
}
*/
u8 NVM_Read_Data(u16 adress)
{
	while(EECR & (1<<EEWE));
	EEAR = adress;
	EECR |= (1<<EERE);
	return EEDR;
}
void NVM_Inter_Enable(void)
{
	SET_BIT(EECR,EERIE);
}
void NVM_Inter_Disable(void)
{
	CLRAR_BIT(EECR,EERIE);
}
void NVM_Write_SetCallBack(void(*LocalFptr)(void))
{
	NVM_WRITE_Fptr=LocalFptr;
}
ISR(EE_RDY_vect)
{
	if(NVM_WRITE_Fptr!=NULL_PTR)
	{
		NVM_WRITE_Fptr();
	}
}