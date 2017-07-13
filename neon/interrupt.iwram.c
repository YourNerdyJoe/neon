#include "interrupt.h"
#include "gba.h"

void intr_handle()
{
	REG_IFBIOS |= IRQ_VBLANK;
	REG_IF = IRQ_VBLANK;
}
