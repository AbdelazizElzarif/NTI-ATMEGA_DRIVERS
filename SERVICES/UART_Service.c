#include "StdTupes.h"
#include "UART.h"
#include "UART_Service1.h"
#include "Utils.h"


/* synch function */
void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		 UART_SendData(str[i]);
		
	}
	UART_SendData(0X0D);
	 UART_SendData(0X0A);
}
/*
void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]= UART_RecieveData();
	str[++i]= UART_RecieveData();
	for (;str[i]!=0x0A&&str[i-1]!=0x0d;)
	{
		i++;
		str[i]= UART_RecieveData();
	}
	str[i]=0;
	str[i-1]=0;

}
*/
void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_RecieveData();
	//str[++i]= UART_RecieveData();
	for (;str[i]!=13;)
	{
		i++;
		str[i]=UART_RecieveData();
		_delay_ms(10);
	}
	str[i]=0;
	
}

void UART_SendNumber(u32 num)
{
	 UART_SendData((u8)num);
	 UART_SendData((u8)(num>>8));
	 UART_SendData((u8)(num>>16));
	 UART_SendData((u8)(num>>24));
	/*
	u8*p=&num;
	 UART_SendData(p[0]);
	 UART_SendData(p[1]);
	 UART_SendData(p[2]);
	 UART_SendData(p[3]);*/
	
}

u32 UART_ReceiveNumber(u32 num)
{

	u8 b1= UART_RecieveData();
	u8 b2= UART_RecieveData();
	u8 b3= UART_RecieveData();
	u8 b4= UART_RecieveData();
	num=(u32)b1|(u32)b2<<8|(u32)b3<<16|(u32)b4<<24;
	//u8*p=&num;
	/*p[0]= UART_RecieveData();
	p[1]= UART_RecieveData();
	p[2]= UART_RecieveData();
	p[3]= UART_RecieveData();
	*/
	return num;
}




Endian_t endian_check(void)
{
	u32 x=1;
	u8*p=(u8*)&x;
	if (*p==1)
	{
		return LITTLE_ENDIAN ;
	}
	else
	{
		return BIG_ENDIAN;
	}
}



u32 endian_convert(u32 num)
{
	return  (num<<24)|(num>>24)|((num>>8)&(0x0000ff00))|((num<<8)&(0x00ff0000));
}
u16 endian_convert_16(u16 num)
{
	return  (num<<8)|(num>>8);
}


void diagCallOut(u8*data)
{
	
	
}


void UART_SendStringCheckSum(u8*str)
{
	u8 len=0;
	u16 sum=0;
	for (len=0;str[len];len++);
	UART_SendData(len);
	for (len=0;str[len];len++)
	{
		UART_SendData(str[len]);
		sum+=str[len];
	}
	UART_SendData((u8)sum);
	UART_SendData((u8)(sum>>8));
	
	
}





u8 UART_ReceiveStringCheckSum(u8*str)
{
	u8 i,l;
	u16 sum=0;
	l=UART_RecieveData();
	for(i=0;i<l;i++)
	{
			str[i]=UART_RecieveData();
			sum+=str[i];
	}
	u8 sum0=UART_RecieveData();
	u8 sum1=UART_RecieveData();
	if((u16)sum0|((u16)sum1<<8)==sum)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


/* interrupt */
#define  QUEE_MAX 5 /* MAXIMUM OF BUFFER*/
static u8*TX_Str[QUEE_MAX];/*ARRAY OF STRINGS TO SEND*/
static u8 flag_quee=0,c_quee=0;/* FLAG QUEE TO KNOW Buffer is embty or not*/
                               /*c_quee num of strings in buffer*/  
/* set call back to send by interrupt*/
void func_tx(void)
{
	static u8 j=1;
	static u8 i=0;
	
	if (TX_Str[i][j])/*string not arrive to null*/
	{
		UART_SendNoBlock(TX_Str[i][j]);//send second element
		j++;//to continue sending
	}
	else
	{
		j=1;//to start from second in string
		i++;//the second element in buffer
		c_quee--;//i pop str from buffer
		if(i==QUEE_MAX)
		{
			i=0;//over flow
		}
		if(c_quee>0)
		{
			UART_SendNoBlock(TX_Str[i][0]);//send the first of next str
		}
		else
		{
			flag_quee=0;//buffer embty
		}
	
		
		
		
	}
}

void UART_SendStringAshync(u8*str)
{
	static u8 i=0;
	UART_TX_SetCallBack(func_tx);
	UART_TX_InterruptEnaple();
	if(flag_quee==0)
	{
		UART_SendNoBlock(str[0]);//first string
		flag_quee=1;//buffer not embty
	}
	if(c_quee!=QUEE_MAX)
	{
		TX_Str[i]=str;//but in buffer
		i++;//for buffer index
		c_quee++;//num of strings in buffer
	
	}
		
	if(i==QUEE_MAX)
	{
		i=0;//over flow
	}
	
}

/* periodic check*/
#define  QUEE_MAX2 5//max buffer
static u8*TX_Str2[QUEE_MAX2];//array of two str
static u8 volatile flag_quee2=0,c_quee2=0;//flag send element in str or not//c_quee num of element in byffer
/* set call back*/
void func_tx2(void)
{
	flag_quee2=1;//send element completed
}

void BCM_Init(void)
{
	UART_TX_InterruptEnaple();
	UART_TX_SetCallBack(func_tx2);//to flag=1
	flag_quee2=1;//indication i send element in string
}
/* put in buffer*/
void BCM_Send(u8*str)
{
	static u8 i=0;
	if(c_quee2<QUEE_MAX2)
	{
		TX_Str2[i]=str;
			i++;
			c_quee2++;
	}
	if(i==QUEE_MAX2)
	{
		i=0;
	}
	
}
void BCM_Runaable(void)
{
	static u8 i=0,j=0;
	if(c_quee2>0&&flag_quee2==1)
	{
		flag_quee2=0;
		if(TX_Str2[i][j])
		{
			
			UART_SendNoBlock(TX_Str2[i][j]);
			j++;
		}
		else
		{
			c_quee2--;
			flag_quee2=1;
			i++;
			j=0;
			if(i==QUEE_MAX2)
			{
				i=0;
			}
		}
		
	}
}


static u8 flag=0;
void func_tx3(void)
{
	flag=1;

}

void UART_SendStringInit(void)
{
	UART_TX_SetCallBack(func_tx3);
	UART_TX_InterruptEnaple();
}

void UART_SendStringRunnable(void)
{
	static u8 j=0;
	static u8 i=0;
	if (flag==1)
	{
		if (TX_Str[i][j])
		{
			UART_SendNoBlock(TX_Str[i][j]);
			j++;
		}
		else
		{
			j=0;
			i++;
		}
		flag=0;
	}
	
}

void UART_SendStringSetter(u8*str)
{
	static u8 i=0;
	TX_Str[i]=str;
	i++;
}

/*** SUDO CODE ***** */
/*
u8* RXStr;
u8 changeflag;
static void func_Rx(void)
{
	static u8 i=0;
	if (changeflag==1)
	{
		i=0;
		changeflag=0;
	}
	RXStr[i]=UART_RecieveNoBlock();
	i++;
}
void UART_ReceiveStringAshync(u8*str)
{
	UART_RX_SetCallBack(func_Rx);
	
	UART_RX_InterruptEnaple();
	if (str!=RXStr)
	{
		changeflag=1;
	}
	RXStr=str;
}
*/
/* UART RECIEVE ASCNCRONUS DOUPLE BUFFER ****** */
u8 RX_Buffer1[8];//first buffer
u8 RX_Buffer2[8];//second buffer
static u8 Bufferflag=0;//any buffer ready to recieve*/
u8 readyflag=0;//i can write buffer know
/* set call back*/
static void func_Rx2(void)
{
	static u8 i=0;
	
	if (Bufferflag==0)
	{
		RX_Buffer1[i]=UART_RecieveNoBlock();
	}
	else
	{
		RX_Buffer2[i]=UART_RecieveNoBlock();
	}
	i++;
	if (i==8)
	{
		i=0;
		readyflag=1;
		Bufferflag^=1;
	}
	
}

void UART_BufferInit(void)
{
	UART_RX_SetCallBack(func_Rx2);
	
	UART_RX_InterruptEnaple();
}

u8 UART_BufferGetter(u8*str)
{
	u8 i;
	if (readyflag==0)
	{
		return 0;
	}
	for (i=0;i<8;i++)
	{
		if (Bufferflag==0)
		{
			str[i]=RX_Buffer2[i];
		}
		else
		{
			str[i]=RX_Buffer1[i];
		}
	}
	readyflag=0;
	return 1;
}
