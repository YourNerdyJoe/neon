#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_
#include "gba.h"
#include "types.h"

typedef u32 CharacterBaseBlock[4096];
typedef u16 ScreenBaseBlock[1024];

#define BGSCROLL ((BGScroll*)0x4000010)
#define tile_mem ((CharacterBaseBlock*)VRAM)
#define se_mem ((ScreenBaseBlock*)VRAM)

#define BG_CBB(x) (x<<2)
#define BG_SBB(x) (x<<8)
#define BG_8BPP (1<<7)

#define LIGHT_CBB 0
#define LIGHT_SBB 16
#define TILES_CBB 1
#define TILES_SBB 17

#endif
