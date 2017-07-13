#ifndef _LUT_MATH_H_
#define _LUT_MATH_H_
#include "gba.h"
#include "sinlut.h"
#include "tanlut.h"
#include "sqrtlut.h"
#include "divlut.h"

static inline FIXED lu_sin(unsigned int theta)		//20.12f
{
	return sin_lut[theta & 0xFF];
}

static inline FIXED lu_cos(unsigned int theta)		//20.12f
{
	return sin_lut[(theta+64) & 0xFF];
}

static inline FIXED lu_tan(unsigned int theta)		//20.12f
{
	return tan_lut[theta & 0xFF];
}

static inline FIXED lu_sqrt(unsigned int radicand)	//20.12f
{
	return sqrt_lut[radicand & 0xFF];	//range 0 - 255
}

static inline FIXED lu_div(unsigned int divisor)
{
	return div_lut[divisor & 0x7F];	//range 0 - 127
}

FIXED lu_lerp(const short lut[],FIXED x);
FIXED lu_ulerp(const unsigned short lut[],FIXED x);

#endif
