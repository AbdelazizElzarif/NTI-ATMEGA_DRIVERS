

#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_
/* PIN CONFG */
/* MOTOR1*/
#define M1_IN1 PINC3
#define M1_IN2 PINC4

#define M2_IN1 PINC2
#define M2_IN2 PINC3

#define M3_IN1 PINC4
#define M3_IN2 PINC5

#define M4_IN1 PINC6
#define M4_IN2 PINC7

typedef struct {
	u8 n1;
	u8 n2;
	}MOTOR_Init_type;





#endif /* MOTOR_CFG_H_ */