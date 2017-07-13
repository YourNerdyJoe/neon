#ifndef _LUA_LIGHT_H_
#define _LUA_LIGHT_H_
#include "light.h"
#include "script.h"

LUA_DECLARE_CLASS(LightSource);
LUA_DECLARE_CLASS_METHOD(LightSource,CastLight);
LUA_DECLARE_CLASS_METHOD(LightSource,CastStaticLight);
LUA_DECLARE_CLASS_METHOD(LightSource,SetLightColor);

#endif
