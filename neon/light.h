#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "gba.h"

typedef struct {
	int x,y;	//position
	u8 color_brightness[4];
	int radius;
	int intensity;	//radius for full brightness
	int fade;	//0 or 1
}LightSource;

void InitializeLight(LightSource* l,int x,int y,int color,int radius,int intensity,int fade);
void SetLightColor(LightSource* l,int color);
void CastLight(LightSource* l);
void CastStaticLight(LightSource* l);
void LoadLightMap(const u32* lightmap);

#endif
