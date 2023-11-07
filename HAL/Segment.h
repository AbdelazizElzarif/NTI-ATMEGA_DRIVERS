
#ifndef SEGMENT_H_
#define SEGMENT_H_
#include "MemMap.h"
void segment_display_bcd_mpx(u16 num);

void segment_display(u8 num);
void segment_display2(u8 num);
void segment_display_same_port(u8 num);
void segment_display_bcd(u8 num);
void segment_4511(u8 num);
void segment_display_bcd_hex(u8 num);
void segment_display_same_bord_hex(u8 num);
void segment_display_same_bord_incr_decr(u8 num);

#endif /* SEGMENT_H_ */