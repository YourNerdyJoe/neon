#include "lutmath.h"

//thanks to Jasper Vijn (cearn at coranac.com)
FIXED lu_lerp(const short lut[],FIXED x)
{
	int xa, ya, yb;
    xa=x>>12;
    ya= lut[xa]; yb= lut[xa+1];
    return ya + ((yb-ya)*(x-(xa<<12))>>12);
}

FIXED lu_ulerp(const unsigned short lut[],FIXED x)
{
	int xa, ya, yb;
    xa=x>>12;
    ya= lut[xa]; yb= lut[xa+1];
    return ya + ((yb-ya)*(x-(xa<<12))>>12);
}
