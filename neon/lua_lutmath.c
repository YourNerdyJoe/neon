#include "lua_lutmath.h"

LUA_BEGIN_FUNCTION_TABLE(lutmath)
	LUA_REGISTER_FUNCTION(lu_sin)
	LUA_REGISTER_FUNCTION(lu_cos)
	LUA_REGISTER_FUNCTION(lu_tan)
	LUA_REGISTER_FUNCTION(lu_sqrt)
	LUA_REGISTER_FUNCTION(lu_div)
LUA_END_FUNCTION_TABLE


#define DEFINE_LUT_LUA_FUNCTION(f)		\
	int lua_##f (lua_State* L)			\
	{									\
		int x = luaL_checkint(L,-1);	\
		FIXED result = f(x);			\
		lua_pushnumber(L,result);		\
		return 1;						\
	}


LUA_DEFINE_FUNCTION_INT(lu_sin,INT_ARG(0))
LUA_DEFINE_FUNCTION_INT(lu_cos,INT_ARG(0))
LUA_DEFINE_FUNCTION_INT(lu_tan,INT_ARG(0))
LUA_DEFINE_FUNCTION_INT(lu_sqrt,INT_ARG(0))
LUA_DEFINE_FUNCTION_INT(lu_div,INT_ARG(0))
