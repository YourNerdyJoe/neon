#ifndef GBA_HEADER
#define GBA_HEADER

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char byte;
typedef unsigned short hword;
typedef unsigned long word;

#define OAMmem 		((volatile u32*)0x7000000)
#define VideoBuffer 		((volatile u16*)0x6000000)
#define BackBuffer		((volatile u16*)0x600A000)
#define OAMdata 		((u16*)0x6010000)
#define BGPaletteMem 	((volatile u16*)0x5000000)
#define OBJPaletteMem 	((volatile u16*)0x5000200)
#define FIXED 	s32
#define PI 	3.14159
#define RADIAN(n) 	(((float)n)/(float)180*PI)
#define BIT(n)	(1<<(n))
		
#define REG_IFBIOS   	(*(volatile u16*)0x3007FF8)
#define REG_INTERUPT   	(*(volatile u32*)0x3007FFC)
#define REG_DISPCNT    	(*(volatile u32*)0x4000000)
#define REG_DISPCNT_L  	(*(volatile u16*)0x4000000)
#define REG_DISPCNT_H  	(*(volatile u16*)0x4000002)
#define REG_DISPSTAT   	(*(volatile u16*)0x4000004)
#define REG_VCOUNT     	(*(volatile u16*)0x4000006)
#define REG_BG0CNT     	(*(volatile u16*)0x4000008)
#define REG_BG1CNT     	(*(volatile u16*)0x400000A)
#define REG_BG2CNT     	(*(volatile u16*)0x400000C)
#define REG_BG3CNT     	(*(volatile u16*)0x400000E)
#define REG_BG0HOFS    	(*(volatile u16*)0x4000010)
#define REG_BG0VOFS    	(*(volatile u16*)0x4000012)
#define REG_BG1HOFS    	(*(volatile u16*)0x4000014)
#define REG_BG1VOFS    	(*(volatile u16*)0x4000016)
#define REG_BG2HOFS    	(*(volatile u16*)0x4000018)
#define REG_BG2VOFS    	(*(volatile u16*)0x400001A)
#define REG_BG3HOFS    	(*(volatile u16*)0x400001C)
#define REG_BG3VOFS    	(*(volatile u16*)0x400001E)
#define REG_BG2PA      	(*(volatile u16*)0x4000020)
#define REG_BG2PB      	(*(volatile u16*)0x4000022)
#define REG_BG2PC      	(*(volatile u16*)0x4000024)
#define REG_BG2PD      	(*(volatile u16*)0x4000026)
#define REG_BG2X       	(*(volatile u32*)0x4000028)
#define REG_BG2X_L     	(*(volatile u16*)0x4000028)
#define REG_BG2X_H     	(*(volatile u16*)0x400002A)
#define REG_BG2Y       	(*(volatile u32*)0x400002C)
#define REG_BG2Y_L     	(*(volatile u16*)0x400002C)
#define REG_BG2Y_H     	(*(volatile u16*)0x400002E)
#define REG_BG3PA      	(*(volatile u16*)0x4000030)
#define REG_BG3PB      	(*(volatile u16*)0x4000032)
#define REG_BG3PC      	(*(volatile u16*)0x4000034)
#define REG_BG3PD      	(*(volatile u16*)0x4000036)
#define REG_BG3X       	(*(volatile u32*)0x4000038)
#define REG_BG3X_L     	(*(volatile u16*)0x4000038)
#define REG_BG3X_H     	(*(volatile u16*)0x400003A)
#define REG_BG3Y       	(*(volatile u32*)0x400003C)
#define REG_BG3Y_L     	(*(volatile u16*)0x400003C)
#define REG_BG3Y_H     	(*(volatile u16*)0x400003E)
#define REG_WIN0H      	(*(volatile u16*)0x4000040)
#define REG_WIN1H      	(*(volatile u16*)0x4000042)
#define REG_WIN0V      	(*(volatile u16*)0x4000044)
#define REG_WIN1V      	(*(volatile u16*)0x4000046)
#define REG_WININ      	(*(volatile u16*)0x4000048)
#define REG_WINOUT     	(*(volatile u16*)0x400004A)
#define REG_MOSAIC     	(*(volatile u32*)0x400004C)
#define REG_MOSAIC_L   	(*(volatile u32*)0x400004C)
#define REG_MOSAIC_H   	(*(volatile u32*)0x400004E)
#define REG_BLDMOD     	(*(volatile u16*)0x4000050)
#define REG_COLEV      	(*(volatile u16*)0x4000052)
#define REG_COLEY      	(*(volatile u16*)0x4000054)
#define REG_SG10       	(*(volatile u32*)0x4000060)
#define REG_SG10_L     	(*(volatile u16*)0x4000060)
#define REG_SG10_H     	(*(volatile u16*)0x4000062)
#define REG_SG11       	(*(volatile u16*)0x4000064)
#define REG_SG20       	(*(volatile u16*)0x4000068)
#define REG_SG21       	(*(volatile u16*)0x400006C)
#define REG_SG30       	(*(volatile u32*)0x4000070)
#define REG_SG30_L     	(*(volatile u16*)0x4000070)
#define REG_SG30_H     	(*(volatile u16*)0x4000072)
#define REG_SG31       	(*(volatile u16*)0x4000074)
#define REG_SG40       	(*(volatile u16*)0x4000078)
#define REG_SG41       	(*(volatile u16*)0x400007C)
#define REG_SGCNT0     	(*(volatile u32*)0x4000080)
#define REG_SGCNT0_L   	(*(volatile u16*)0x4000080)
#define REG_SGCNT0_H   	(*(volatile u16*)0x4000082)
#define REG_SGCNT1     	(*(volatile u16*)0x4000084)
#define REG_SGBIAS     	(*(volatile u16*)0x4000088)
#define REG_SGWR0      	(*(volatile u32*)0x4000090)
#define REG_SGWR0_L    	(*(volatile u16*)0x4000090)
#define REG_SGWR0_H    	(*(volatile u16*)0x4000092)
#define REG_SGWR1      	(*(volatile u32*)0x4000094)
#define REG_SGWR1_L    	(*(volatile u16*)0x4000094)
#define REG_SGWR1_H    	(*(volatile u16*)0x4000096)
#define REG_SGWR2      	(*(volatile u32*)0x4000098)
#define REG_SGWR2_L    	(*(volatile u16*)0x4000098)
#define REG_SGWR2_H    	(*(volatile u16*)0x400009A)
#define REG_SGWR3      	(*(volatile u32*)0x400009C)
#define REG_SGWR3_L    	(*(volatile u16*)0x400009C)
#define REG_SGWR3_H    	(*(volatile u16*)0x400009E)
#define REG_SGFIF0A    	(*(volatile u32*)0x40000A0)
#define REG_SGFIFOA_L  	(*(volatile u16*)0x40000A0)
#define REG_SGFIFOA_H  	(*(volatile u16*)0x40000A2)
#define REG_SGFIFOB    	(*(volatile u32*)0x40000A4)
#define REG_SGFIFOB_L  	(*(volatile u16*)0x40000A4)
#define REG_SGFIFOB_H  	(*(volatile u16*)0x40000A6)
#define REG_DM0SAD     	(*(volatile u32*)0x40000B0)
#define REG_DM0SAD_L   	(*(volatile u16*)0x40000B0)
#define REG_DM0SAD_H   	(*(volatile u16*)0x40000B2)
#define REG_DM0DAD     	(*(volatile u32*)0x40000B4)
#define REG_DM0DAD_L   	(*(volatile u16*)0x40000B4)
#define REG_DM0DAD_H   	(*(volatile u16*)0x40000B6)
#define REG_DM0CNT     	(*(volatile u32*)0x40000B8)
#define REG_DM0CNT_L   	(*(volatile u16*)0x40000B8)
#define REG_DM0CNT_H   	(*(volatile u16*)0x40000BA)
#define REG_DM1SAD     	(*(volatile u32*)0x40000BC)
#define REG_DM1SAD_L   	(*(volatile u16*)0x40000BC)
#define REG_DM1SAD_H   	(*(volatile u16*)0x40000BE)
#define REG_DM1DAD     	(*(volatile u32*)0x40000C0)
#define REG_DM1DAD_L   	(*(volatile u16*)0x40000C0)
#define REG_DM1DAD_H   	(*(volatile u16*)0x40000C2)
#define REG_DM1CNT     	(*(volatile u32*)0x40000C4)
#define REG_DM1CNT_L   	(*(volatile u16*)0x40000C4)
#define REG_DM1CNT_H   	(*(volatile u16*)0x40000C6)
#define REG_DM2SAD     	(*(volatile u32*)0x40000C8)
#define REG_DM2SAD_L   	(*(volatile u16*)0x40000C8)
#define REG_DM2SAD_H   	(*(volatile u16*)0x40000CA)
#define REG_DM2DAD     	(*(volatile u32*)0x40000CC)
#define REG_DM2DAD_L   	(*(volatile u16*)0x40000CC)
#define REG_DM2DAD_H   	(*(volatile u16*)0x40000CE)
#define REG_DM2CNT     	(*(volatile u32*)0x40000D0)
#define REG_DM2CNT_L   	(*(volatile u16*)0x40000D0)
#define REG_DM2CNT_H   	(*(volatile u16*)0x40000D2)
#define REG_DM3SAD     	(*(volatile u32*)0x40000D4)
#define REG_DM3SAD_L   	(*(volatile u16*)0x40000D4)
#define REG_DM3SAD_H   	(*(volatile u16*)0x40000D6)
#define REG_DM3DAD     	(*(volatile u32*)0x40000D8)
#define REG_DM3DAD_L   	(*(volatile u16*)0x40000D8)
#define REG_DM3DAD_H   	(*(volatile u16*)0x40000DA)
#define REG_DM3CNT     	(*(volatile u32*)0x40000DC)
#define REG_DM3CNT_L   	(*(volatile u16*)0x40000DC)
#define REG_DM3CNT_H   	(*(volatile u16*)0x40000DE)
#define REG_TM0D       	(*(volatile u16*)0x4000100)
#define REG_TM0CNT     	(*(volatile u16*)0x4000102)
#define REG_TM1D       	(*(volatile u16*)0x4000104)
#define REG_TM1CNT     	(*(volatile u16*)0x4000106)
#define REG_TM2D       	(*(volatile u16*)0x4000108)
#define REG_TM2CNT     	(*(volatile u16*)0x400010A)
#define REG_TM3D       	(*(volatile u16*)0x400010C)
#define REG_TM3CNT     	(*(volatile u16*)0x400010E)
#define REG_SCD0       	(*(volatile u16*)0x4000120)
#define REG_SCD1       	(*(volatile u16*)0x4000122)
#define REG_SCD2       	(*(volatile u16*)0x4000124)
#define REG_SCD3       	(*(volatile u16*)0x4000126)
#define REG_SCCNT      	(*(volatile u32*)0x4000128)
#define REG_SCCNT_L    	(*(volatile u16*)0x4000128)
#define REG_SCCNT_H    	(*(volatile u16*)0x400012A)
#define REG_P1         	(*(volatile u16*)0x4000130)
#define REG_P1CNT      	(*(volatile u16*)0x4000132)
#define REG_R          	(*(volatile u16*)0x4000134)
#define REG_HS_CTRL    	(*(volatile u16*)0x4000140)
#define REG_JOYRE      	(*(volatile u32*)0x4000150)
#define REG_JOYRE_L    	(*(volatile u16*)0x4000150)
#define REG_JOYRE_H    	(*(volatile u16*)0x4000152)
#define REG_JOYTR      	(*(volatile u32*)0x4000154)
#define REG_JOYTR_L    	(*(volatile u16*)0x4000154)
#define REG_JOYTR_H    	(*(volatile u16*)0x4000156)
#define REG_JSTAT      	(*(volatile u32*)0x4000158)
#define REG_JSTAT_L    	(*(volatile u16*)0x4000158)
#define REG_JSTAT_H    	(*(volatile u16*)0x400015A)
#define REG_IE         	(*(volatile u16*)0x4000200)
#define REG_IF         	(*(volatile u16*)0x4000202)
#define REG_WSCNT      	(*(volatile u16*)0x4000204)
#define REG_IME        	(*(volatile u16*)0x4000208)
#define REG_PAUSE      	(*(volatile u16*)0x4000300)

typedef struct tagOAMEntry
{
	u16 attribute0;
	u16 attribute1;
	u16 attribute2;
	u16 attribute3;
} OAMEntry, *pOAMEntry;

#define WaitForVsync()  while(REG_VCOUNT != 160);

#define WRAM			((u32*)0x2000000)
#define IRAM			((u32*)0x3000000)
#define PAL_BG			((u16*)0x5000000)
#define PAL_OBJ			((u16*)0x5000200)
#define VRAM			((u16*)0x6000000)
#define OAM_MEM			((u16*)0x6010000)
#define OAM_DATA		((u32*)0x7000000)

#ifndef NULL
#define NULL 0
#endif
#define TRUE 1
#define FALSE 0

#define IN_EWRAM __attribute__ ((section (".ewram")))
#define IN_IWRAM __attribute__ ((section (".iwram")))
#define ALIGN(n)  __attribute__ ((aligned ((n))))

#ifdef __thumb__
#define swi_call(x)   asm volatile("swi\t"#x ::: "r0", "r1", "r2", "r3")
#else
#define swi_call(x)   asm volatile("swi\t"#x"<<16" ::: "r0", "r1", "r2", "r3")
#endif

#endif

