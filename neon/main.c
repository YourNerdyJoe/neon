#include "gba.h"
#include "screenmodes.h"
#include "keypad.h"
#include "types.h"
#include "background.h"
#include "tiles.h"
#include "light.h"
#include "blend.h"
#include "interrupt.h"
#include "sprite.h"
#include "testlightmap.h"
#include "script.h"
#include "debug.h"

const char* test_script = "light = LightSource.new(100,80,GREEN,80,32,false)\nlight:CastStaticLight()\nlight = LightSource.new(200,20,PINK,100,50,false)\nlight:CastStaticLight()\n";

int main()
{
	InitializeDebug();

	//Set Video Mode
	SetMode(SCREENMODE0|BG0ENABLE|BG1ENABLE|OBJENABLE|OBJMAP1D);

	//Interrupts
	REG_ISR_MAIN = intr_handle;
	REG_DISPSTAT |= VID_VBL_IRQ;
	REG_IE |= IRQ_VBLANK;
	REG_IME = 1;	//enable interrupts

	//BG0 used for lighting
	REG_BG0CNT = BG_8BPP | BG_CBB(LIGHT_CBB) | BG_SBB(LIGHT_SBB);
	//BG1 used for game tiles
	REG_BG1CNT = BG_8BPP | BG_CBB(TILES_CBB) | BG_SBB(TILES_SBB);

	//Enable Alpha Blending
	REG_BLDMOD = BLD_STD|BLD_TOP(0)|BLD_BOTTOM(1)|BLD_BOTTOM(0);
	REG_COLEV = BLD_EVA(0xD)|BLD_EVB(0x3);	//13/16 3/16

	//Tiles
	InitializeTilePalette();
	InitializeCharacterBaseBlock();
	LoadTileData();

	//LoadLightMap(test_lightmap);

	int i;
	for(i=0;i<1024;i++)
		se_mem[TILES_SBB][i] = i%3+1;

	//Sprites
	HideAllSprites();
	OBJPaletteMem[0] = 0x0000;
	OBJPaletteMem[1] = BGPaletteMem[24];	//green
	for(i=0;i<32;i++)
	{
		((u32*)OAMdata)[8+i] = 0x11111111;
	}

	//Lua
	lua_State* L = InitializeLua();

	if(luaL_dostring(L,test_script))
	{
		DebugPrint(lua_tostring(L,-1));
	}

	//Test
	LightSource p,g,b,w;
	InitializeLight(&g,76,90,GREEN,60,10,0);
	InitializeLight(&p,166,90,PINK,74,32,0);
	InitializeLight(&b,108,30,BLUE,60,5,1);
	InitializeLight(&w,120,80,WHITE,80,30,0);

	//SetLightColor(&g,BLUE);
	//CastStaticLight(&g);
	//CastStaticLight(&p);
	//CastStaticLight(&w);

	/*int i;
	for(i=0;i<30;i++)
		tile[i].initial_color = WHITE;
	for(i=0;i<30;i++)
		tile[i*32+3].initial_color = WHITE;
	for(i=0;i<30;i++)
		tile[i+16*32].initial_color = WHITE;*/

	/*int x,y;
	for(y=0;y<16;y++)
		for(x=0;x<16;x++)
			se_mem[LIGHT_SBB][x+y*32] = x+y*16;*/

	int xspd=24,yspd=4;

	while(1)
	{
		ClearLightTiles();

		if(b.x>200 || b.x<40) xspd*=-1;
		if(b.y>140 || b.y<20) yspd*=-1;
		b.x+=xspd;
		b.y+=yspd;

		//CastLight(&g);

		//if(KEY_DOWN(KEYA))
		//	CastLight(&p);

		CastLight(&b);

		//game[CURRENT_GAME].run();
		//runPong();

		if(KEY_DOWN(KEYB))
			CastLight(&w);

		WriteLightTiles();
		CopySpritesToOAM();

		//VBlankIntrWait
		swi_call(0x5);
	}

	return 0;
}
