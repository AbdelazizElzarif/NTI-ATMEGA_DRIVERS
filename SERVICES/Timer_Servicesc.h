
#ifndef TIMER_SERVICESC_H_
#define TIMER_SERVICESC_H_
/* TIMER0 NORMAL MODE ***** */
void Timer0_NM_Duty_25(void);
void Timer0_NM_Duty_20(void);
void Timer0_NM_Duty_50(void);
void Timer0_NM_CALA_TIME(void);
u8 TIMER0_GET_C0UNT(void);
void TIMER0_SET_C0UNT(u8 num);

/* TIMER1 */
void TIMER1_GET_INTERRUPT_AFTER_US(u16 us);
void TIMER1_TOGGLE_PIN(void);
/*  p w m */
void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_s (u16 time,void(*LocalFptr)(void));
//void PWM_Measure(u32* Pfreq,u8* Pduty);
void PWM_Measure(u32* Pfreq,u8* Pduty,u32 timeout);
void PWM_Measure2(u32* Pfreq,u8* Pduty);



#endif /* TIMER_SERVICESC_H_ */