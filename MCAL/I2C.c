#include "MemMap.h"
#include "StdTupes.h"
#include "Utils.h"
#include "I2C_interface.h"
/*INIT FREQUENCY*/
void I2C_Master_voidInit(void)
{
	TWBR=12;//400 SCL AND 16 MHZ 
}
/*SEND START CONDITION*/
I2C_Error_State   I2C_Master_enuSendStartCond(void)
{
	I2C_Error_State State=I2C_SC_ERROR;//start is sucess
	//TRANSMIT START CONDITION
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//set enable /zero flag/start condition
	//WAIT FOR END TRANSMISSION
	while(READ_BIT(TWCR,TWINT)==0);
	if((TWSR & 0xF8) == START_ACK)
	{
		State=I2C_OK;//I Cant start now
	}
	return State;
	
}
/* READ FROM SLAVE*/
I2C_Error_State   I2C_Master_enuSendSlaveAddressWithRead(u8 I2C_Address)
{
	I2C_Error_State State=I2C_MT_SLA_R_ERROR;
	TWDR=I2C_Address<<1;
	SET_BIT(TWDR,0);//to 
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	if((TWSR & 0xF8) ==SLAVE_ADD_AND_RD_ACK)
	{
		State=I2C_OK;//I Cant start now
	}
	return State;
	
	
}
/*WRITE TO SLAVE */
I2C_Error_State   I2C_Master_enuSendSlaveAddressWithWrite(u8 I2C_Address)
{
	I2C_Error_State State=I2C_MT_SLA_W_ERROR;
	TWDR=I2C_Address<<1;
	CLRAR_BIT(TWDR,0);//to
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	if((TWSR & 0xF8) == SLAVE_ADD_AND_WR_ACK)
	{
		State=I2C_OK;//I Cant start now
	}
	return State;
}
/* MASTER SEND DATA*/
I2C_Error_State   I2C_Master_enuSendu8Data(u8 I2C_Data)
{
	I2C_Error_State State=I2C_MT_DATA_ERROR;
	TWDR=I2C_Data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	if((TWSR & 0xF8) == WR_BYTE_ACK)
	{
		State=I2C_OK;
	}
	return State;
	
}
void   I2C_Master_enuSendStopCond(void)
{
	//STOP CONDITION
	TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}


void I2C_Slave_voidInit(u8 I2C_Address)
{
	TWAR=I2C_Address<<1;
}

I2C_Error_State I2C_slave_avilable(void)//TO WRITE
{
	I2C_Error_State State=I2C_SR_DATA_ERROR;
	TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);//ACKNOWADG
	while(READ_BIT(TWCR,TWINT)==0);
	if((TWSR & 0xF8) ==  SLAVE_ADD_RCVD_WR_RQST )
	{
		State=I2C_OK;//I Cant start now
	}
	return State;
	
}
u8  I2C_Slave_enuReadu8Data(void)
{
	TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	return TWDR;
}




