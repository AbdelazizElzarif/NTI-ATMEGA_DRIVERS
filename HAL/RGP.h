

#ifndef RGP_H_
#define RGP_H_

typedef struct{
	u8 RED;
	u8 GREEN;
	u8 BLUE;
	}RGP_PWM;
typedef enum
{                         
	  Red,
	  Green,
	  Blue,
	  Orange,
      Pink,
	  Cyan,
	  Magenta,
	  Yellow,
	  Black,
	  White,
	  Gray,
	  Light_Gray,
	  Dark_Gray,
	}RGP_COLORS;
	void RGP_GET_COLOR(RGP_COLORS color);




#endif /* RGP_H_ */