#ifndef _LUA_SPRITE_H_
#define _LUA_SPRITE_H_
#include "sprite.h"
#include "script.h"

int lua_open_sprite(lua_State* L)
{
	luaL_newmetatable(L,"neon.OAMEntry");

}

int lua_sprite_index(lua_State* L)
{
	int index = luaL_checkint(L,2);
	if(index<0 || index>=128) luaL_error(L,"Sprite index out of bounds (%d)\n",index);
	OAMEntry* spr = &sprite[index];
	OAMEntry** pspr = (OAMEntry**)lua_newuserdata(L,sizeof(OAMEntry**));
	luaL_setmetatable(L,"neon.OAMEntry");
	pspr = &spr;
	return 1;
}

#endif
