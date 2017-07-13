#include "debug.h"
#include <stdio.h>
#include <stdarg.h>

static unsigned int position = 0;

void InitializeDebug()
{
	//clear sram
	int i;
	for(i=0;i<64*1024;i++)
	{
		*(char*)(0xE000000+i) = 0;
	}
}

void DebugPrint(const char* fmt,...)
{
	va_list argptr;
	char buffer[256];
	va_start(argptr,fmt);
	vsprintf(buffer,fmt,argptr);
	va_end(argptr);

	char* p = buffer;
	while(*p != 0)
	{
		((char*)(0xE000000))[position++] = *p++;
	}
}
