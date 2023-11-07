#include "StdTupes.h"
#include "Timers.h"
#include "Servo_Interface.h"
void Servo_Set_Angle(u8 angle)
{
	/*u16 x=(((u32)2000*angle)+90)/(u32)180+999;
	TIMER1_WRITE_COMP_MATCHB(x);*/
	u16 x=(((u32)2500*angle)+90)/(u32)180+499;
	TIMER1_WRITE_COMP_MATCHB(x);
}