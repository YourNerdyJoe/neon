#ifndef _SPRITE_H_
#define _SPRITE_H_
#include "gba.h"

extern OAMEntry sprite[128];

//Attribute 0
#define ATTR0_REG	0x0
#define ATTR0_AFF	0x100
#define ATTR0_HIDE	0x200
#define ATTR0_AFF_DBL	0x300
#define ATTR0_BLEND	0x400
#define ATTR0_WIN	0x800
#define ATTR0_MOSAIC	0x1000
#define ATTR0_4BPP	0x0
#define ATTR0_8BPP	0x2000
#define ATTR0_SQUARE	0x0
#define ATTR0_WIDE	0x4000
#define ATTR0_TALL	0x8000

//Attribute 1
#define ATTR1_AFF(x)	(x<<9)
#define ATTR1_HFLIP	0x1000
#define ATTR1_VFLIP	0x2000
#define ATTR1_SIZE8		0x0
#define ATTR1_SIZE16	0x4000
#define ATTR1_SIZE32	0x8000
#define ATTR1_SIZE64	0xC000

//Attribute 2
#define ATTR2_PRIO(x)	(x<<0xA)
#define ATTR2_PALBANK(x)	(x<<0xC)

void HideAllSprites();
void CopySpritesToOAM();

#endif
