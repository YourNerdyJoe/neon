#include "script.h"
#include "lua_lutmath.h"
#include "lua_light.h"
#include "lua_tiles.h"

static lua_State* L;

lua_State* InitializeLua()
{
	L = luaL_newstate();
	luaL_openlibs(L);
	LUA_REGISTER_FUNCTION_TABLE(lutmath);
	LUA_REGISTER_INT_CONSTANTS(tiles);
	LUA_REGISTER_CLASS(LightSource);
	return L;
}

void RegisterLuaFunctions(const luaL_Reg* table)
{
	for(;table->name != 0; table++)
	{
		lua_register(L,table->name,table->func);
	}
}

void RegisterLuaConstants(const luaConst_Reg* table)
{
	for(;table->name != 0; table++)
	{
		lua_pushinteger(L,table->value);
		lua_setglobal(L,table->name);
	}
}
