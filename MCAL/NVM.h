

#ifndef NVM_H_
#define NVM_H_
void NVM_Write_Data(u16 adress,u8 data);
u8 NVM_Read_Data(u16 adress);
void NVM_Inter_Enable(void);
void NVM_Inter_Disable(void);
void NVM_Write_SetCallBack(void(*LocalFptr)(void));

#endif /* NVM_H_ */