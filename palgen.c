#include <stdio.h>

typedef struct {
	unsigned char r,g,b;
}Color;

Color color[4] = {
	{ 0xFF,0xFF,0xFF },
	{ 0xFF,0x82,0xFF },
	{ 0x33,0xFF,0x33 },
	{ 0x00,0xE5,0xFF },
};

#define WHITE 0
#define PINK 1
#define GREEN 2
#define BLUE 3

#define WHITE_SIZE 4
#define PINK_SIZE 4
#define GREEN_SIZE 4
#define BLUE_SIZE 4

#define COLOR_MAX(x) if(x > 255) x = 255;

unsigned short paldata[256];

void color2pal(int palentry,unsigned char r,unsigned char g, unsigned char b)
{
	r = r>>3;
	g = g>>3;
	b = b>>3;
	paldata[palentry] = r + (g<<5) + (b<<10);
}

int main(int argc,char* argv[])
{
	int i;
	
	//reduce brightness
	for(i=1;i<=3;i++)
	{
		color[i].r = (color[i].r>>1) + (color[i].r>>2);
		color[i].g = (color[i].g>>1) + (color[i].g>>2);
		color[i].b = (color[i].b>>1) + (color[i].b>>2);
	}
	
	paldata[0] = 0x0000;	//black
	for(i=1;i<=3;i++)
	{
		unsigned int r,g,b;
		r = color[WHITE].r*i/4;
		g = color[WHITE].g*i/4;
		b = color[WHITE].b*i/4;
		color2pal(i,r,g,b);
	}
	color2pal(4,color[WHITE].r,color[WHITE].g,color[WHITE].b);
	
	int white,pink,green,blue;
	int index = 5;
	for(white=0;white<=2;white+=2)
	{
		for(blue=0;blue<=4;blue++)
		{
			for(green=0;green<=4;green++)
			{
				for(pink=0;pink<=4;pink++)
				{
					unsigned int total = pink+green+blue;
					if(total==0) continue;	//skip what would be another black
					
					//ignore this
					unsigned int colortotal = 0;
					if(pink)	colortotal++;
					if(green)	colortotal++;
					if(blue)	colortotal++;
					if(white)	colortotal++;
					
					colortotal = 1;
					
					unsigned int r,g,b;
					r =((color[WHITE].r*white/2)+
						(color[PINK].r*pink/4)	+
						(color[GREEN].r*green/4)+
						(color[BLUE].r*blue/4)
						)/colortotal;
					g =((color[WHITE].g*white/2)+
						(color[PINK].g*pink/4)	+
						(color[GREEN].g*green/4)+
						(color[BLUE].g*blue/4)
						)/colortotal;
					b =((color[WHITE].b*white/2)+
						(color[PINK].b*pink/4)	+
						(color[GREEN].b*green/4)+
						(color[BLUE].b*blue/4)
						)/colortotal;
					COLOR_MAX(r);
					COLOR_MAX(g);
					COLOR_MAX(b);
					color2pal(index,r,g,b);
					index++;
				}
			}
		}
	}
	
	for(i=index;i<256;i++)
	{
		paldata[i] = 0x0000;
	}
	
	printf("Last index: %d\n",index);
	
	/* Output to C file */
	
	FILE* f = fopen("tilepalette.h","w");
	
	fprintf(f,"//\n// BG Tile Palette\n//\n\n");
	fprintf(f,"extern const unsigned short tile_palette[256];\n");
	
	fclose(f);
	
	f = fopen("tilepalette.c","w");
	
	fprintf(f,"#include \"tilepalette.h\"\n\n");
	fprintf(f,"const unsigned short tile_palette[256] = {\n");
	
	for(i=0;i<256;i++)
	{
		if(i%8 == 0)
			fprintf(f,"\n\t");
		
		fprintf(f,"0x%04X, ",paldata[i]);
	}
	
	fprintf(f,"\n};\n");
	
	fclose(f);
	
	/* Output .pal */
	unsigned int col32;
	f = fopen("neon.pal","w");
	
	fprintf(f,"CLRX 8 256");
	
	for(i=0;i<256;i++)
	{
		col32 = ((paldata[i] & 0x1F)<<3)|((paldata[i] & 0x3E0)<<6)|((paldata[i] & 0x7C00)<<9);
		if(i%4 == 0)
			fprintf(f,"\n");
		
		fprintf(f,"0x%08X ",col32);
	}
	fprintf(f,"\n");
	
	fclose(f);
	
	return 0;
}

