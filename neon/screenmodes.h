//screenmodes.h

#ifndef __SCREENMODES__

#define __SCREENMODES__

 

#define SCREENMODE0    0x0                  //Enable screen mode 0

#define SCREENMODE1    0x1                  //Enable screen mode 1

#define SCREENMODE2    0x2                  //Enable screen mode 2

#define SCREENMODE3    0x3                  //Enable screen mode 3

#define SCREENMODE4    0x4                  //Enable screen mode 4

#define SCREENMODE5    0x5                  //Enable screen mode 5

#define BACKBUFFER        0x10                //Determine backbuffer

#define HBLANKOAM        0x20                //Update OAM during HBlank?

#define OBJMAP2D             0x0                  //2D object (sprite) mapping

#define OBJMAP1D             0x40                //1D object(sprite) mapping

#define FORCEBLANK       0x80                //Force a blank

#define BG0ENABLE           0x100              //Enable background 0

#define BG1ENABLE           0x200              //Enable background 1

#define BG2ENABLE           0x400              //Enable background 2

#define BG3ENABLE           0x800              //Enable background 3

#define OBJENABLE           0x1000            //Enable sprites

#define WIN1ENABLE         0x2000            //Enable window 1

#define WIN2ENABLE         0x4000            //Enable window 2

#define WINOBJENABLE   0x8000            //Enable object window

 

#define SetMode(mode)        (REG_DISPCNT = mode)

 

#endif

 

