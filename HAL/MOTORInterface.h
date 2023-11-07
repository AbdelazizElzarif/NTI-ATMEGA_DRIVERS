

#ifndef MOTORINTERFACE_H_
#define MOTORINTERFACE_H_

typedef enum{
	M1,
	M2,
	M3,
	M4,
	}MOTOR_type;
	void MOTOR_Init(void);
	void MOTOR_Stop(MOTOR_type m);
	void MOTOR_CW(MOTOR_type m);
	void MOTOR_CCW(MOTOR_type m);
	/* 0:100 */
	void MOTOR_Speed(MOTOR_type m,u8 speed);



#endif /* MOTORINTERFACE_H_ */