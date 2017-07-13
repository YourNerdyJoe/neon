#include "sprite.h"

OAMEntry sprite[128];

void HideAllSprites()
{
	int i;
	for(i = 0; i < 128; i++)
	{
		sprite[i].attribute0 = ATTR0_HIDE;
	}
}

void CopySpritesToOAM()
{
	//replace w/ dma later

	u32* dst = (u32*)OAMmem; u32* src = (u32*)sprite;
	int i;
	for(i = 0; i < 128; i++)
	{
		*dst++ = *src++;
		*dst++ = *src++;
	}
}
