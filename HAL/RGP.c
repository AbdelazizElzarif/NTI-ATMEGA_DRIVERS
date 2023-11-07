#include "StdTupes.h"
#include "RGP.h"
#include"Timers.h"
 static RGP_PWM arr[13]={{255,0,0},{0,255,0},{0,0,255},{255,200,0},{255,175,175},{0,255,255},{255,0,255},{255,255,0},{0,0,0},
	              {255.255,255},{128,128,128},{192,192,192},{64,64,64}};

void RGP_GET_COLOR(RGP_COLORS color)
{
	TIMER0_WRITE_COMP_MATCH(arr[color].RED);
	TIMER1_WRITE_COMP_MATCHA(arr[color].GREEN);
	TIMER1_WRITE_COMP_MATCHB(arr[color].BLUE);
}					  