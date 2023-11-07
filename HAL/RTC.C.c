/* function for clock */
#include "StdTupes.h"
#include "TWI.h"
#include "RTC.h"
u32 second,minute,hour,day,date,month,year;
void RTC_Clock_Write(char _hour, char _minute, char _second, char AMPM)
{
_hour |= AMPM;
TWI_Start();/* Start I2C communication with RTC */
TWI_Write(Device_Write_address);
TWI_Write(0);			/* Write 0 address for second */
TWI_Write(_second);		/* Write second on 00 location */
TWI_Write(_minute);		/* Write minute on 01(auto increment) location */
TWI_Write(_hour);		/* Write hour on 02 location */
TWI_Stop();			/* Stop I2C communication */
}

/* function for calendar */
void RTC_Calendar_Write(char _day, char _date, char _month, char _year)
{
TWI_Start();/* Start I2C communication with RTC */
TWI_Write(Device_Write_address);
TWI_Write(3);			/* Write 3 address for day */
TWI_Write(_day);		/* Write day on 03 location */
TWI_Write(_date);		/* Write date on 04 location */
TWI_Write(_month);		/* Write month on 05 location */
TWI_Write(_year);		/* Write year on 06 location */
TWI_Stop();			/* Stop I2C communication */
}
void RTC_Read_Clock(char read_clock_address)
{
	
	TWI_Start();/* Start I2C communication with RTC */
	TWI_Write(Device_Write_address);
	TWI_Write(read_clock_address);	/* Write address to read */
	TWI_Start();/* Repeated start with device read address */
    TWI_Write(Device_Read_address);
	second =  TWI_Read_With_ACK();	/* Read second */
	minute =  TWI_Read_With_ACK();	/* Read minute */
	hour = TWI_Read_With_NACK();		/* Read hour with Nack */
	TWI_Stop();			/* Stop i2C communication */
}

void RTC_Read_Calendar(char read_calendar_address)
{
	TWI_Start();
	TWI_Write(Device_Write_address);
	TWI_Write(read_calendar_address);
	TWI_Start();
	TWI_Write(Device_Read_address);

	day = TWI_Read_With_ACK();		/* Read day */
	date = TWI_Read_With_ACK();		/* Read date */
	month = TWI_Read_With_ACK();		/* Read month */
	year = TWI_Read_With_NACK();		/* Read the year with Nack */
	TWI_Stop();			/* Stop i2C communication */
}