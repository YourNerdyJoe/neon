#include "light.h"
#include "lutmath.h"
#include "tiles.h"
#include "types.h"
#include "keypad.h"

void InitializeLight(LightSource* l,int x,int y,int color,int radius,int intensity,int fade)
{
	l->x = x;
	l->y = y;

	SetLightColor(l,color);

	l->radius = radius;
	l->intensity = intensity;
	l->fade = fade;
}

void SetLightColor(LightSource* l,int color)
{
	int i;
	for(i=0;i<4;i++)
		l->color_brightness[i] = 0;

	if(color>=0)
		l->color_brightness[color] = 4;
}

#define TILESIZE 2

static void CastLight_base(LightSource* l,int color_offset)
{
	u32 checked_tiles[32];	//bit flags
	int i;
	for(i=0;i<32;i++) checked_tiles[i] = 0;

	int theta,step=4;
	if(l->radius > 86)
		step=2;
	for(theta = 0; theta < 256; theta+=step)
	{
		FIXED x,y;	//20.12f
		x = l->x << 12;
		y = l->y << 12;

		FIXED xincrement,yincrement;
		FIXED increment_distance,distance = 0;

		xincrement = TILESIZE * lu_cos(theta);
		yincrement = -TILESIZE * lu_sin(theta);

		increment_distance = TILESIZE;

		while(distance < l->radius)
		{
			int tilex,tiley;
			tilex = x >> 15;	//div by 8
			tiley = y >> 15;	//and shift 12

			int tilenum = tilex+tiley*32;

			if(tilex>=0 && tilex<32 && tiley>=0 && tiley<32)
			{
				int tilenum_base = tilenum>>5,
					tilenum_bit = tilenum & 0x1F;
				//continue if the light source checked this tile
				if(!(checked_tiles[tilenum_base] & (1<<tilenum_bit)))
				{
					checked_tiles[tilenum_base] |= 1<<tilenum_bit;
					FIXED divider = 1<<12;	//dim when further from the light source
					if(distance > l->intensity)
					{
						int outer_range,outer_distance;
						outer_distance = distance - l->intensity;
						outer_range = l->radius - l->intensity;
						divider = outer_range*lu_div(outer_range-outer_distance);
					}

					FIXED div = lu_lerp(div_lut,divider);

					u8* tile_brightness = &((u32*)(&tile[tilenum]))[color_offset];
					//tile[tilenum].color_brightness[0] += (l->color_brightness[0]*div)>>12;

					u8 light_brightness[4] = {
						(l->color_brightness[0]*div)>>12,
						(l->color_brightness[1]*div)>>12,
						(l->color_brightness[2]*div)>>12,
						(l->color_brightness[3]*div)>>12,
					};

					//tile_brightness[0] += (l->color_brightness[0]*div)>>12;
					//tile_brightness[1] += (l->color_brightness[1]*div)>>12;
					//tile_brightness[2] += (l->color_brightness[2]*div)>>12;
					//tile_brightness[3] += (l->color_brightness[3]*div)>>12;
					*(u32*)tile_brightness += *(u32*)light_brightness;

					for(i = 0; i < 4; i++)
					{
						//if(tile[tilenum].color_brightness[i] > 4)
						//	tile[tilenum].color_brightness[i] = 4;
						if(tile_brightness[i] > 4)
							tile_brightness[i] = 4;
					}

					if(l->fade)
					{
						*(u32*)tile[tilenum].color_fade += (*(u32*)light_brightness);
						int j;
						for(j=0;j<4;j++)
						{
							if(tile[tilenum].color_fade[j] > 4)
								tile[tilenum].color_fade[j] = 4;
						}
					}
				}
			}
			else	//ray is cast off screen
			{
				break;
			}

			x += xincrement;
			y += yincrement;
			distance += increment_distance;
		}
	}
}

void CastLight(LightSource* l)
{
	CastLight_base(l,2);
}

void CastStaticLight(LightSource* l)
{
	/*
	This is when I get lazy and do 'unsafe' hacky shiz
	so it writes to initial_color_brightness instead.
	*/	//goodbye hacky shiz :(
	//Tile* ptile;
	//ptile = (Tile*)(((char*)tile)-4);
	CastLight_base(l,1);
}

void LoadLightMap(const u32* lightmap)
{
	int i;
	for(i = 0; i < 256; i++) // !!!!! 1024 !!!!!!
	{
		*(u32*)tile[i].initial_color_brightness = lightmap[i];
	}
}
