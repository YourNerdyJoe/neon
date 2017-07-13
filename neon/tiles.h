#ifndef _TILES_H_
#define _TILES_H_
#include "gba.h"

typedef struct __attribute__ ((__packed__)){
	int initial_color;
	u8 initial_color_brightness[4];
	u8 color_brightness[4];
	u8 color_fade[4];
}Tile;

/* Colors */
#define BLACK 0

#define WHITE 0
#define PINK 1
#define GREEN 2
#define BLUE 3

extern Tile tile[1024];

void InitializeTilePalette();
void InitializeTiles();
void InitializeCharacterBaseBlock();
void LoadTileData();
void ClearLightTiles();
void WriteLightTiles();

#endif
