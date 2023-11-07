
#ifndef UTILS_H_
#define UTILS_H_
//frequency of crystal
#define  F_CPU 16000000
//include delay function
#include <util/delay.h>
//bitwise operation
#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define SET_BIT(REG,BIT) (REG=REG|(1<<BIT))
#define CLRAR_BIT(REG,BIT) (REG=REG&(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) (REG=REG^(1<<BIT))//frequency of crystal

#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )


#endif /* UTILS_H_ */