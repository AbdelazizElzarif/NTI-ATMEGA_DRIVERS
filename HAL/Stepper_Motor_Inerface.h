
#ifndef STEPPER_MOTOR_INERFACE_H_
#define STEPPER_MOTOR_INERFACE_H_
#include "StdTupes.h"
#include "DIO_interface.h"
#define COIL1A PINC0
#define COIL1B PINC1
#define COIL2A PINC2
#define COIL2B PINC3
#define DELAY 250
void STEPPER_BIBOLAR_CCW(void);
void STEPPER_BIBOLAR_CW(void);
void STEPPER_UNIBOLAR_CCW(void);
void STEPPER_UNIBOLAR_CW(void);
void Stepper_Step_Angle(u16 angle);
void Stepper_Step_Rotate(u32 rotata);






#endif /* STEPPER_MOTOR_INERFACE_H_ */