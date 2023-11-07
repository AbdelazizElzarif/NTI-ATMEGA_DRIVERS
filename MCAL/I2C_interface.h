#ifndef		I2C_INTERFACE_H
#define		I2C_INTERFACE_H
#define START_ACK				  0x08  // Start has been sent
#define REP_START_ACK			  0x10  // Repeated Start
#define SLAVE_ADD_AND_WR_ACK	  0x18  // Master Transmitted (slave address + write request) ACK
#define SLAVE_ADD_AND_RD_ACK	  0x40  // Master Transmitted (slave address + read request) ACK
#define WR_BYTE_ACK				  0x28  // Master Transmit Data ACK
#define RD_BYTE_WITH_NACK         0x58  // Master Received Data with not ACK
#define RD_BYTE_WITH_ACK          0x50  // Master Received Data with ACK
#define SLAVE_ADD_RCVD_RD_RQST    0xA8  // Means that slave address is received with Write REQ
#define SLAVE_ADD_RCVD_WR_RQST    0x60  // Means that slave address is received with Read REQ
#define SLAVE_DATA_RECEIVED		  0xB0  // Means that Read BYTE REQ is received
#define SLAVE_BYTE_TRANSMITTED    0xC0  // Means that Write BYTE REQ is received

typedef enum
{
  I2C_OK = 0,
  I2C_SC_ERROR,
  I2C_RSC_ERROR,
  I2C_MT_SLA_R_ERROR,
  I2C_MT_SLA_W_ERROR,
  I2C_MT_DATA_ERROR,
  I2C_MR_DATA_ERROR,
  I2C_SR_DATA_ERROR
}I2C_Error_State;

void		I2C_Master_voidInit(void);                                        //M init for master CLK
I2C_Error_State   I2C_Master_enuSendStartCond(void);                          //M start if bus is idle
I2C_Error_State   I2C_Master_enuSendSlaveAddressWithRead(u8 I2C_Address);     //M Send slave address With R/W bit Read
I2C_Error_State   I2C_Master_enuSendSlaveAddressWithWrite(u8 I2C_Address);    //M Send slave address With R/W bit Write
I2C_Error_State   I2C_Master_enuSendu8Data(u8 I2C_Data);                      //M master Sets Data given in argument
I2C_Error_State   I2C_Master_enuReadu8Data(u8* I2C_Data);                     //M master Gets Data and saves it in given argument
void   I2C_Master_enuSendStopCond(void);                                      //M send stop bit
void		I2C_Slave_voidInit(u8 I2C_Address);                               //S init fo slave REGISTER ID
I2C_Error_State   I2C_slave_avilable(void);
u8  I2C_Slave_enuReadu8Data(void);                      //Slave Reads Data saves it in given argument

I2C_Error_State   I2C_Master_enuSendRepeatedStartCond(void);                  //M repeated start if bus is busy





#endif
