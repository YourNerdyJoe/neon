#include "tiles.h"
#include "gba.h"
#include "background.h"
#include "tilepalette.h"
#include "bgtiles.h"

Tile tile[1024] __attribute__ ((aligned(4)));

void InitializeTilePalette()
{
	//replace w/ dma later
	int i;
	for(i = 0; i < 256; i++)
	{
		BGPaletteMem[i] = tile_palette[i];
	}
}

void InitializeTiles()
{
	int i;
	for(i=0;i<1024;i++)
	{
		tile[i].initial_color = 0;
		*(u32*)(&tile[i].initial_color_brightness) = 0;
		*(u32*)(&tile[i].color_brightness) = 0;
	}
}

void InitializeCharacterBaseBlock()
{
	int i;
	for(i = 0; i < 256; i++)
	{
		u32 color_data = (i<<8)|i;					//16bits
		color_data = (color_data<<16)|color_data;	//32bits
		int j;
		for(j = 0; j < 16; j++) //16 * 32bit = 64bytes/tile
		{
			tile_mem[LIGHT_CBB][i*16+j] = color_data;
		}
	}
}

void LoadTileData()
{
	int i;
	for(i = 0; i < 16384; i++)
	{
		tile_mem[TILES_CBB][i] = bgtilesTiles[i];
	}
}

void ClearLightTiles()
{
	int i,j;
	for(i = 0; i < 1024; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(tile[i].color_fade[j] > 0)
				tile[i].color_fade[j]--;
		}
		//why do 4 8bit additions when you can do 1 32bit addition :)
		*(u32*)tile[i].color_brightness = *(u32*)tile[i].initial_color_brightness + (*(u32*)tile[i].color_fade);
		for(j = 0; j < 4; j++)
		{
			if(tile[i].color_brightness[j] > 4)
				tile[i].color_brightness[j] = 4;
		}
	}
}

/*won't work b/c color 0 of each palette is transparent*/
//OPTIMIZE:
//use 4bpp, store 16 tiles in CBB
//4bpp * 64pixels/tile = 32Bytes/tile
//32B/tile * 16 tiles(colors) = 512B
//vs
//8bpp * 64pixels/tile = 64Bytes/tile
//64B/tile * 256 tiles(colors) = 16kB!!!
//then put palette in screen entry

void WriteLightTiles()
{
	int i;
	for(i = 0; i < 1024; i++)
	{
		int color = 0;

		int j;
		int offset=1;
		for(j = 1; j < 4; j++)
		{
			color += (tile[i].color_brightness[j])*offset;
			offset*=5;
		}
		if(color!=BLACK)
		{
			if(tile[i].color_brightness[0] > 2)
			{
				color += 124;	//5pink*5green*5blue - 1
			}
			color+=4;
		}
		else if(tile[i].color_brightness[0] != 0)
		{
			color = tile[i].color_brightness[0];
		}
		else	//set to non-transparent black tile for alpha blending
		{
			color = 255;
		}

		/*
		int palette = color>>4;	//256 colors, palette is upper 4 bits
		color = (color & 0xF)|(palette<<12);
		*/

		se_mem[LIGHT_SBB][i] = color;//tile[i].initial_color;
	}
}
