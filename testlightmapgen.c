#include <stdio.h>

unsigned char lightmap[1024][4];

int main(int argc,char* argv)
{
	int x,y;
	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
			lightmap[y*32+x][0] = ((y*16+x) & 0x3) + 1;
			lightmap[y*32+x][1] = ((y*16+x) & 0xC)>>2 + 1;
			lightmap[y*32+x][2] = ((y*16+x) & 0x30)>>4 + 1;
			lightmap[y*32+x][3] = ((y*16+x) & 0xC0)>>6 + 1;
		}
	}
	
	FILE* f = fopen("testlightmap.h","w");
	fprintf(f,"//Demo Light Map\n\n");
	fprintf(f,"extern const unsigned long test_lightmap[1024];\n");
	fclose(f);
	
	f = fopen("testlightmap.c","w");
	fprintf(f,"#include \"testlightmap.h\"\n\n");
	fprintf(f,"extern const unsigned long test_lightmap[1024] = {\n");
	int i;
	for(i=0;i<1024;i++)
	{
		if(i%8 == 0)
			fprintf(f,"\n\t");
		
		fprintf(f,"0x%08X, ",*(unsigned long*)lightmap[i]);
	}
	fprintf(f,"\n};\n");
	fclose(f);
	
	return 0;
}

