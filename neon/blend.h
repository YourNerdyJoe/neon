#ifndef _BLEND_H_
#define _BLEND_H_

#define BLD_TOP(x) (1<<x)
#define BLD_BOTTOM(x) (1<<(x+8))

#define BLD_OFF 0x0
#define BLD_STD 0x40
#define BLD_WHITE 0x80
#define BLD_BLACK 0xC0

#define BLD_EVA(x) (x)
#define BLD_EVB(x) (x<<8)

#endif
