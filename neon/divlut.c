//
// Divide LUT; 128 entries, 12 fixeds
//
#include "divlut.h"

const short div_lut[128] = {

	0x0000, 0x1000, 0x0800, 0x0555, 0x0400, 0x0333, 0x02AA, 0x0249, 
	0x0200, 0x01C7, 0x0199, 0x0174, 0x0155, 0x013B, 0x0124, 0x0111, 
	0x0100, 0x00F0, 0x00E3, 0x00D7, 0x00CC, 0x00C3, 0x00BA, 0x00B2, 
	0x00AA, 0x00A3, 0x009D, 0x0097, 0x0092, 0x008D, 0x0088, 0x0084, 
	0x0080, 0x007C, 0x0078, 0x0075, 0x0071, 0x006E, 0x006B, 0x0069, 
	0x0066, 0x0063, 0x0061, 0x005F, 0x005D, 0x005B, 0x0059, 0x0057, 
	0x0055, 0x0053, 0x0051, 0x0050, 0x004E, 0x004D, 0x004B, 0x004A, 
	0x0049, 0x0047, 0x0046, 0x0045, 0x0044, 0x0043, 0x0042, 0x0041, 
	0x0040, 0x003F, 0x003E, 0x003D, 0x003C, 0x003B, 0x003A, 0x0039, 
	0x0038, 0x0038, 0x0037, 0x0036, 0x0035, 0x0035, 0x0034, 0x0033, 
	0x0033, 0x0032, 0x0031, 0x0031, 0x0030, 0x0030, 0x002F, 0x002F, 
	0x002E, 0x002E, 0x002D, 0x002D, 0x002C, 0x002C, 0x002B, 0x002B, 
	0x002A, 0x002A, 0x0029, 0x0029, 0x0028, 0x0028, 0x0028, 0x0027, 
	0x0027, 0x0027, 0x0026, 0x0026, 0x0025, 0x0025, 0x0025, 0x0024, 
	0x0024, 0x0024, 0x0023, 0x0023, 0x0023, 0x0023, 0x0022, 0x0022, 
	0x0022, 0x0021, 0x0021, 0x0021, 0x0021, 0x0020, 0x0020, 0x0020, 
};