
#ifndef SENSORS_INTERFACE_H_
#define SENSORS_INTERFACE_H_

u16 TEMP_Read(void);

u16 PRESURE_Read(void);
u16 INTER_Polation(u16 x1,u16 y1,u16 x2,u16 y2,u16 xc);

u16 POT_Read(void);


#endif /* SENSORS_INTERFACE_H_ */