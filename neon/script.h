#ifndef _SCRIPT_H_
#define _SCRIPT_H_
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <string.h>

#define FUNC_ENTRY(f)	{ #f, lua_##f }
#define SENTINEL_ENTRY	{ 0, 0 }

typedef struct {
	const char* name;
	int value;
}luaConst_Reg;

lua_State* InitializeLua();
void RegisterLuaFunctions(const luaL_Reg* table);
void RegisterLuaConstants(const luaConst_Reg* table);

#define LUA_METHOD_NAME(type,f)	lua_##type##f
#define LUA_FUNCTION_NAME(f) lua_##f
#define LUA_INT_CONST_TABLE_NAME(table) lua_int_const_##table
#define LUA_FUNCTION_TABLE_NAME(table) lua_func_##table

#define LUA_DECLARE_CLASS(type)					\
	extern const luaL_Reg lua_m_##type[];		\
	extern const luaL_Reg lua_f_##type[];		\
	extern const luaL_Reg lua_methods_##type[];	\
	int lua_set_##type (lua_State* L);			\
	int lua_get_##type (lua_State* L);			\
	int lua_new_##type (lua_State* L);			\
	int lua_open_##type (lua_State* L);

#define LUA_DEFINE_CLASS(type)													\
	const luaL_Reg lua_m_##type[] = {											\
		{ "__index", lua_get_##type },											\
		{ "__newindex", lua_set_##type },										\
		SENTINEL_ENTRY,															\
	};																			\
	const luaL_Reg lua_f_##type[] = {											\
		{ "new", lua_new_##type },												\
		SENTINEL_ENTRY,															\
	};																			\
	int lua_open_##type (lua_State* L)											\
	{																			\
		luaL_newmetatable(L,"neon."#type);										\
		lua_pushvalue(L,-1);													\
		lua_setfield(L,-2,"__index");											\
		luaL_setfuncs(L,lua_m_##type,0);										\
		luaL_newlib(L,lua_f_##type);											\
		lua_pushvalue(L,-1);													\
		lua_setglobal(L,#type);													\
		return 1;																\
	}																			\
	static int* lua_index_##type (lua_State* L);								\
	int lua_set_##type (lua_State* L)											\
	{																			\
		int value = luaL_checkint(L,3);											\
		int* var = lua_index_##type(L);											\
		*var = value;															\
		return 0;																\
	}																			\
	int lua_get_##type (lua_State* L)											\
	{																			\
		if(!lua_push_class_method(L,luaL_checkstring(L,2),lua_methods_##type))	\
		{																		\
			int value = *lua_index_##type(L);									\
			lua_pushinteger(L,value);											\
		}																		\
		return 1;																\
	}

#define LUA_BEGIN_CLASS_METHODS(type)		\
	const luaL_Reg lua_methods_##type[] = {	\

#define LUA_REGISTER_CLASS_METHOD(type,f)	\
		{ #f, LUA_METHOD_NAME(type,f) },

#define LUA_END_CLASS_METHODS(type)		\
		SENTINEL_ENTRY,					\
	};

#define LUA_DECLARE_CLASS_METHOD(type,f)	\
	int LUA_METHOD_NAME(type,f) (lua_State* L);

#define LUA_BEGIN_CLASS_METHOD_DEFINITION(type,f)	\
	int LUA_METHOD_NAME(type,f) (lua_State* L)		\
	{												\
		type* obj = (type*)luaL_checkudata(L,1,"neon."#type);

#define LUA_END_CLASS_METHOD_DEFINITION(ret)	\
		return ret;								\
	}

#define LUA_DEFINE_CLASS_METHOD_VOID(type,f,...)				\
	LUA_BEGIN_CLASS_METHOD_DEFINITION(type,f)					\
		f(obj,##__VA_ARGS__);									\
	LUA_END_CLASS_METHOD_DEFINITION(0)

#define LUA_DEFINE_CLASS_METHOD_INT(type,f,...)					\
	LUA_BEGIN_CLASS_METHOD_DEFINITION(type,f)					\
		int result = f(obj,##__VA_ARGS__);						\
		lua_pushinteger(L,result);								\
	LUA_END_CLASS_METHOD_DEFINITION(1)

#define LUA_DEFINE_CLASS_METHOD_BOOL(type,f,...)				\
	LUA_BEGIN_CLASS_METHOD_DEFINITION(type,f)					\
		int result = f(obj,##__VA_ARGS__);						\
		lua_pushboolean(L,result);								\
	LUA_END_CLASS_METHOD_DEFINITION(1)

#define INT_ARG(sp)	luaL_checkint(L,sp+1)
#define BOOL_ARG(sp) lua_toboolean(L,sp+1)

#define LUA_BEGIN_CLASS_INT_MEMBERS(type)						\
	static int* lua_index_##type (lua_State* L)					\
	{															\
		type* obj = (type*)luaL_checkudata(L,1,"neon."#type);	\
		const char* key = luaL_checkstring(L,2);

#define LUA_FIRST_CLASS_MEMBER(var)	\
		if(strcmp(key,#var)==0)		\
		{							\
			return &obj->var;		\
		}

#define LUA_CLASS_MEMBER(var)			\
		else if(strcmp(key,#var)==0)	\
		{								\
			return &obj->var;			\
		}

#define LUA_END_CLASS_INT_MEMBERS					\
		luaL_error(L,"Invalid member '%s'\n",key);	\
		return NULL;								\
	}

#define LUA_BEGIN_CLASS_CONSTRUCTOR(type)			\
	int lua_new_##type (lua_State* L)				\
	{												\
		type* obj =									\
			(type*)lua_newuserdata(L,sizeof(type));	\
		luaL_setmetatable(L,"neon."#type);

#define LUA_END_CLASS_CONSTRUCTOR	\
		return 1;					\
	}

#define LUA_CLASS_DEFAULT_CONSTRUCTOR(type)	\
	LUA_BEGIN_CLASS_CONSTRUCTOR(type)		\
	LUA_END_CLASS_CONSTRUCTOR

#define LUA_CLASS_CONSTRUCTOR(type,f,...)	\
	LUA_BEGIN_CLASS_CONSTRUCTOR(type)		\
		f(obj,##__VA_ARGS__);				\
	LUA_END_CLASS_CONSTRUCTOR

#define LUA_REGISTER_CLASS(type)	lua_open_##type (L);

static inline int lua_push_class_method(lua_State* L,const char* name,const luaL_Reg* table)
{
	for(;table->name!=NULL;table++)
	{
		if(strcmp(name,table->name)==0)
		{
			lua_pushcfunction(L,table->func);
			return 1;
		}
	}
	return 0;
}

#define LUA_DECLARE_INT_CONSTANTS(table)	\
	extern const luaConst_Reg LUA_INT_CONST_TABLE_NAME(table)[];

#define LUA_BEGIN_INT_CONSTANTS(table)	\
	const luaConst_Reg LUA_INT_CONST_TABLE_NAME(table)[] = {

#define LUA_INT_CONSTANT(constant)	\
		{ #constant, constant },

#define LUA_END_INT_CONSTANTS	\
		SENTINEL_ENTRY,			\
	};

#define LUA_REGISTER_INT_CONSTANTS(table)	\
	RegisterLuaConstants(LUA_INT_CONST_TABLE_NAME(table));

#define LUA_DECLARE_FUNCTION_TABLE(table)	\
	extern const luaL_Reg LUA_FUNCTION_TABLE_NAME(table)[];

#define LUA_DECLARE_FUNCTION(f)	\
	int LUA_FUNCTION_NAME(f) (lua_State* L);

#define LUA_BEGIN_FUNCTION_TABLE(table)	\
	const luaL_Reg LUA_FUNCTION_TABLE_NAME(table)[] = {

#define LUA_REGISTER_FUNCTION(f)	\
		FUNC_ENTRY(f),

#define LUA_END_FUNCTION_TABLE	\
		SENTINEL_ENTRY,			\
	};

#define LUA_REGISTER_FUNCTION_TABLE(table)	\
	RegisterLuaFunctions(LUA_FUNCTION_TABLE_NAME(table));

#define LUA_BEGIN_FUNCTION_DEFINITION(f)	\
	int LUA_FUNCTION_NAME(f) (lua_State* L)	\
	{

#define LUA_END_FUNCTION_DEFINITION(ret)	\
		return ret;							\
	}

#define LUA_DEFINE_FUNCTION_VOID(f,...)	\
	LUA_BEGIN_FUNCTION_DEFINITION(f)	\
		f(__VA_ARGS__);					\
	LUA_END_FUNCTION_DEFINITION(0)

#define LUA_DEFINE_FUNCTION_INT(f,...)		\
	LUA_BEGIN_FUNCTION_DEFINITION(f)		\
		lua_pushinteger(L,f(__VA_ARGS__));	\
	LUA_END_FUNCTION_DEFINITION(1)

#define LUA_DEFINE_FUNCTION_BOOL(f,...)		\
	LUA_BEGIN_FUNCTION_DEFINITION(f)		\
		lua_pushboolean(L,f(__VA_ARGS__));	\
	LUA_END_FUNCTION_DEFINITION(1)

#endif
