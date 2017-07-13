#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

typedef void(*fnptr)(void);
#define REG_ISR_MAIN *(fnptr*)(0x3007FFC)

#define IRQ_VBLANK	0x1
#define IRQ_HBLANK	0x2
#define IRQ_VCOUNT	0x4
#define IRQ_TIMER0	0x8
#define IRQ_TIMER1	0x10
#define IRQ_TIMER2	0x20
#define IRQ_TIMER3	0x40
#define IRQ_COM		0x80
#define IRQ_DMA0	0x100
#define IRQ_DMA1	0x200
#define IRQ_DMA2	0x400
#define IRQ_DMA3	0x800
#define IRQ_KEYPAD	0x1000
#define IRQ_GAMEPAK	0x2000

#define VID_VBL_IRQ	0x8
#define VID_HBL_IRQ	0x10

__attribute__((section(".iwram"), long_call)) void intr_handle();

#endif
