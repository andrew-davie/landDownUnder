
#include "main.h"
#include "cavedata.h"
#include "attribute.h"
#include "charRuntime.h"

#define LINE 0b01000000
#define FILLRECT 0b10000000
#define RECT 0b11000000

#define DIRT 1
#define DIAMOND 0x14
#define WALL 2
#define MAGIC 3
#define STEEL 7
#define FIREFLY 8
#define BOULDER 0x10
#define INBOX 0x25
#define OUTBOX 4
#define AMOEBA 0x3A


//#define UP 0
//#define UPRIGHT 1
#define RIGHT 2
//#define DOWNRIGHT 3
#define DOWN 4
//#define DOWNLEFT 5
#define LEFT 6
//#define UPLEFT 7


    /*

$00 Space
$01 Dirt
$02 Brick wall
$03 Magic wall
$04 Pre outbox (ie before it starts flashing)
$05 Flashing outbox
$06 *
$07 Steel wall
$08 Firefly position 1
$09 Firefly position 2
$0A Firefly position 3
$0B Firefly position 4
$0C Firefly position 1, scanned this frame
$0D Firefly position 2, scanned this frame
$0E Firefly position 3, scanned this frame
$0F Firefly position 4, scanned this frame
$10 Boulder, stationary
$11 Boulder, stationary, scanned this frame
$12 Boulder, falling
$13 Boulder, falling, scanned this frame
$14 Diamond, stationary
$15 Diamond, stationary, scanned this frame
$16 Diamond, falling
$17 Diamond, falling, scanned this frame
$18 Fireflyx
$19 fireflyx
$1A
$1B Explode to Space stage 0
$1C Explode to Space stage 1
$1D Explode to Space stage 2
$1E Explode to Space stage 3
$1F Explode to Space stage 4
$20 Explode to Diamond stage 0
$21 Explode to Diamond stage 1
$22 Explode to Diamond stage 2
$23 Explode to Diamond stage 3
$24 Explode to Diamond stage 4
$25 Pre Rockford stage 1 (ie when inbox morphs into Rockford)
$26 Pre Rockford stage 2
$27 Pre Rockford stage 3
$28 Pre Rockford stage 4
$29 Boulder2 x
$2A Boulder3 x
$2B Boulder4 x
$2C magic1 x
$2D magic2 x
$2E magic3 x
$2F
$30 Butterfly position 1
$31 Butterfly position 2
$32 Butterfly position 3
$33 Butterfly position 4
$34 Butterfly position 1, scanned this frame
$35 Butterfly position 2, scanned this frame
$36 Butterfly position 3, scanned this frame
$37 Butterfly position 4, scanned this frame
$38 Rockford
$39 Rockford, scanned this frame
$3A Amoeba
$3B Amoeba, scanned this frame
$3C Amoeba x
$3D Amoeba x
$3E *
$3F *
 */


/*
Offset  Description 
------  ----------- 
$00     Cave number 
$01     Magic wall milling time, also max amoeba time at 3% growth. 
$02     Initial diamond value 
$03     Extra diamond value 
$04     Initial randomiser seed value for difficulty level 1 
$05     Initial randomiser seed value for difficulty level 2 
$06     Initial randomiser seed value for difficulty level 3 
$07     Initial randomiser seed value for difficulty level 4 
$08     Initial randomiser seed value for difficulty level 5 
$09     Diamonds needed on difficulty level 1 
$0A     Diamonds needed on difficulty level 2 
$0B     Diamonds needed on difficulty level 3 
$0C     Diamonds needed on difficulty level 4 
$0D     Diamonds needed on difficulty level 5 
$0E     Cave time for difficulty level 1 
$0F     Cave time for difficulty level 2 
$10     Cave time for difficulty level 3 
$11     Cave time for difficulty level 4 
$12     Cave time for difficulty level 5 
$13     Background colour 1 
$14     Background colour 2 
$15     Foreground colour 
$16     unused                  <-- NOW BORDER FOR ENTIRE SCREEN (e.g, STEEL)
$17     unused                  <-- NOW FILL CHAR (e.g., DIRT) FOR ENTIRE BG
$18     Random object number 1 
$19     Random object number 2 
$1A     Random object number 3 
$1B     Random object number 4 
$1C     Probability of object 1 
$1D     Probability of object 2 
$1E     Probability of object 3 
$1F     Probability of object 4 
*/



UBYTE BD2_caveA[] = {


/*
[cave]
Name=Cave A
DiamondValue=15
DiamondsRequired=10 10 10 20 20
CaveTime=240 160 120 100 100
Colors=Orange Gray1 White
MagicWallTime=25
*/

0x00,       // cave
25,         // milling
15,15,      // diamond $

11,12,13,14,15,         // randomiser[level]

10,       // diamonds needed
10,
10,
20,
20,

240,           // cave times
160,
120,
100,
100,

0,0,DEF_PARALLAX,
STEEL,DIRT,

/*
RandomFill=BOULDER 50 DIAMOND 5
*/

0x10,0x14,0,0,
50,5,0x0,0x0,        // probability



/*
[objects]
Line=19 1 19 11 WALL
Line=1 11 19 11 WALL
Line=3 6 16 6 DIRT
Line=3 7 16 7 MAGICWALL
Line=3 10 16 10 DIRT
Line=33 1 33 16 STEELWALL
Point=20 5 BOULDER
FillRect=21 1 32 16 DIRT
Line=33 16 14 16 STEELWALL
FillRect=15 17 38 20 SPACE
Raster=16 17 4 1 6 1 FIREFLYr
Raster=18 17 4 4 6 1 DIRT
Raster=22 1 6 3 2 2 MAGICWALL
Raster=23 1 3 3 4 2 MAGICWALL
Raster=22 2 3 1 4 1 MAGICWALL
Point=28 4 MAGICWALL
Point=32 4 MAGICWALL
Point=22 4 MAGICWALL
Line=23 5 24 5 DIRT
Point=37 3 INBOX
Point=5 18 OUTBOX
[/objects]
*/


#define OFF 0


//Line=19 1 19 11 WALL
LINE+WALL,19,OFF+1,11,DOWN,

//Line=1 11 19 11 WALL
LINE+WALL,1,OFF+11,19,RIGHT,

//Line=3 6 16 6 DIRT
LINE+DIRT,3,OFF+6,14,RIGHT,

//Line=3 7 16 7 MAGICWALL
LINE+MAGIC,3,OFF+7,14,RIGHT,

//Line=3 10 16 10 DIRT
LINE+DIRT,3,OFF+10,14,RIGHT,

//Line=33 1 33 16 STEELWALL
LINE+STEEL,33,OFF+1,16,DOWN,

//FillRect=21 1 32 16 DIRT
FILLRECT+DIRT,21,OFF+1,12,16,DIRT,

//Line=33 16 14 16 STEELWALL
LINE+STEEL,33,OFF+16,20,LEFT,

//FillRect=15 17 38 20 SPACE
FILLRECT,15,OFF+17,24,4,0,


//Raster=x y numberx numbery stepx stepy element

// Raster=18 17 4 4 6 1 DIRT
LINE+DIRT,18,OFF+17,4,DOWN,
LINE+DIRT,24,OFF+17,4,DOWN,
LINE+DIRT,30,OFF+17,4,DOWN,
LINE+DIRT,36,OFF+17,4,DOWN,


//Raster=16 17 4 1 6 1 FIREFLYr
FIREFLY,16,OFF+17,
FIREFLY,22,OFF+17,
FIREFLY,28,OFF+17,
FIREFLY,34,OFF+17,



//Raster=22 1 6 3 2 2 MAGICWALL
MAGIC,22,OFF+1,
MAGIC,22,OFF+2,
MAGIC,22,OFF+3,
MAGIC,22,OFF+4,
MAGIC,22,OFF+5,

MAGIC,23,OFF+1,
MAGIC,23,OFF+3,
MAGIC,24,OFF+1,
MAGIC,24,OFF+3,

MAGIC,26,OFF+1,
MAGIC,26,OFF+2,
MAGIC,26,OFF+3,
MAGIC,26,OFF+5,
MAGIC,27,OFF+1,
MAGIC,27,OFF+3,
MAGIC,27,OFF+5,
MAGIC,28,OFF+1,
MAGIC,28,OFF+3,
MAGIC,28,OFF+4,
MAGIC,28,OFF+5,

MAGIC,30,OFF+1,
MAGIC,30,OFF+2,
MAGIC,30,OFF+3,
MAGIC,30,OFF+5,
MAGIC,31,OFF+1,
MAGIC,31,OFF+3,
MAGIC,31,OFF+5,
MAGIC,32,OFF+1,
MAGIC,32,OFF+3,
MAGIC,32,OFF+4,
MAGIC,32,OFF+5,



/*
[objects]
Raster=22 1 6 3 2 2 MAGICWALL
Raster=23 1 3 3 4 2 MAGICWALL
Raster=22 2 3 1 4 1 MAGICWALL
[/objects]
*/


//Line=23 5 24 5 DIRT
LINE+DIRT, 23,5,1,RIGHT,
/*
Point=20 5 BOULDER
*/

0x10, 20,OFF+5,           // boulder

/*
Point=28 4 MAGICWALL
Point=32 4 MAGICWALL
Point=22 4 MAGICWALL
*/
MAGIC, 28,OFF+4,         // magic wall
MAGIC,32,OFF+4,          // magic wall
MAGIC, 22,OFF+4,            // magic wall

/*
Point=37 3 INBOX
Point=5 18 OUTBOX
*/

0x25,37,OFF+3,         // player/inbox
4, 5,OFF+18,             // outbox



0xFF,

};


UBYTE BD2_caveB[] = { //tetris

#define SHIFTY_BD2_caveB -2

0x00,       // cave
25,         // milling
3,10,       // diamond $

100,137,140,251,51,             // randomiser[level]
75,80,85,90,95,                 // diamonds[level]
200, 190, 180, 170, 160,        // time[level]

0,0,DEF_PARALLAX,
STEEL,DIRT,                     // wall/fill

// RandomFill

BOULDER,AMOEBA,0,0,              // boulder, amoeba
254,127,0x0,0x0,        // probability

//FillRect=1 16 38 20 SPACE
FILLRECT+0,1,OFF+16,38,5,0,


//Line=1 15 30 15 STEELWALL
LINE+STEEL,1,OFF+15,30,RIGHT,

//FillRect=1 0 7 15 STEELWALL
FILLRECT+STEEL,1,OFF+0, 7,16, STEEL,

//FillRect=11 0 17 15 STEELWALL
FILLRECT+STEEL,11,OFF+0, 7,16, STEEL,

//FillRect=21 0 27 15 STEELWALL
FILLRECT+STEEL,21,OFF+0,7,16,STEEL,

//FillRect=31 0 38 15 STEELWALL
FILLRECT+STEEL,31,OFF+0,8,16,STEEL,


//
//Raster=x y numberx numbery stepx stepy element[objects]
//Raster=9 14 3 1 10 1 BOULDER
//Raster=9 15 3 1 10 1 DIRT
//
LINE+BOULDER,9,OFF+14,1,RIGHT,
LINE+BOULDER,19,OFF+14,1,RIGHT,
LINE+BOULDER,29,OFF+14,1,RIGHT,

LINE+DIRT,9,OFF+15,1,RIGHT,
LINE+DIRT,19,OFF+15,1,RIGHT,
LINE+DIRT,29,OFF+15,1,RIGHT,


//Line=1 1 38 1 BOULDER
LINE+BOULDER,1,OFF+1,38,RIGHT,

//Line=1 2 38 2 DIRT
LINE+DIRT,1,OFF+2,38,RIGHT,

//Line=1 3 38 3 DIRT
LINE+DIRT,1,OFF+3,38,RIGHT,

//Rectangle=2 1 3 15 SPACE
RECT+0,2,OFF+1,2,15,

//Rectangle=36 1 37 15 SPACE
RECT+0,36,OFF+1,2,15,

//
//Point=3 16 INBOX
//Point=38 16 OUTBOX
//[/objects]
//
//[/cave]
//

INBOX,3,16+SHIFTY_BD2_caveB,
OUTBOX,38,16+SHIFTY_BD2_caveB,

//20,4,16, test diamond


0xFF,

};




UBYTE BD4_caveD[] = {


0x04,       // cave
0x14,       // milling
0x05,20,    // diamond $

0x0,0x0,0x0,0x0,0x0,        // randomiser[level]

75,       // diamonds needed
80,
85,
90,
95,
255,           // cave times
210,
170,
140,
50,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x10,0,0x0,0x0,        // random objects
76,0,0,0x0,        // probability

/*[objects]
Point=1 1 INBOX
Point=38 20 OUTBOX
FillRect=8 6 37 11 BUTTERFLYd
[/objects]
*/


INBOX,1,OFF+1,
OUTBOX,38,OFF+20,1,



//FillRect=8 6 37 11 BUTTERFLYd
//FILLRECT+0x32,8,OFF+6,30,6,0x32,
LINE+0x32,8,OFF-1+6,30,RIGHT,
LINE+0x32,8,OFF-1+7,30,RIGHT,
LINE+0x32,8,OFF-1+8,30,RIGHT,
LINE+0x32,8,OFF-1+9,30,RIGHT,
LINE+0x32,8,OFF-1+10,30,RIGHT,
LINE+0x32,8,OFF-1+11,30,RIGHT,


//20,4,OFF+1, //test diamond


0xFF,

};

UBYTE caveCat[] = {

0x00,       // cave
0x14,       // milling
0x0A,0x0F,  // diamond $

0xFA,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,       // diamonds[level]
0x96,0x6E,0x46,0x28,0x1E,       // time[level]

24,0,DEF_PARALLAX,
STEEL,DIRT,

0,0x20,0x10,0x0,        // random objects
0,0,0,0x0,        // probability

LINE+7,2,18-2,36,RIGHT,
LINE+0x10,16,18-2,8,RIGHT,

// left cat

FILLRECT+CH_BRICKWALL, 6, 8-2, 9, 10, CH_BRICKWALL,
LINE+CH_DIRTY, 6, 9-2, 5, DOWN,
CH_DIRTY, 6, 17-2,
LINE+CH_DIRTY, 8, 8-2, 8, DOWN,
LINE+CH_DIRTY, 9, 8-2, 4, DOWN,
CH_DIRTY, 11, 8-2,
LINE+CH_DIRTY, 13, 8-2, 2, DOWN,
LINE+CH_DIRTY, 13, 12-2, 2, DOWN,
LINE+CH_DIRTY, 14, 8-2, 9, DOWN,
CH_FIREFLY_0, 12, 10-2,


// right cat

FILLRECT+CH_BOULDER, 25, 8-2, 9, 10, CH_BOULDER,
LINE+CH_DIRTY, 25+(14-6), 9-2, 5, DOWN,
CH_DIRTY, 25+(14-6), 17-2,
LINE+CH_DIRTY, 25+(14-8), 8-2, 8, DOWN,
LINE+CH_DIRTY, 25+(14-9), 8-2, 4, DOWN,
CH_DIRTY, 25+(14-11), 8-2,
LINE+CH_DIRTY, 25+(14-13), 8-2, 2, DOWN,
LINE+CH_DIRTY, 25+(14-13), 12-2, 2, DOWN,
LINE+CH_DIRTY, 25+(14-14), 8-2, 9, DOWN,



#define BUTTERFLY 0x32


LINE+0x10,22-7,5-2,10,RIGHT,
FILLRECT, 22-7,7-2,10,10,0,
FILLRECT+BUTTERFLY,22-7,10-2,6,2,0x32,


0x25,0xB,0x14-2,              // player/inbox
0x04,27,10-2,             // pre-outbox
//0x32,0xD,0x14,

LINE+CH_AMOEBA0, 17, OFF+4-2, 6, RIGHT,

0xFF,
};



UBYTE cave1[]= {

#define SHIFTY_1 -2

/*
0x01,0x14,0x0A,0x0F,0x0A,0x0B,0x0C,0x0D,0x0E,0x0C,0x0C,0x0C,0x0C,0x0C,0x96,0x6E,
0x46,0x28,0x1E,0x08,0x0B,0x09,0xD4,0x20,0x00,0x14,0x10,0x00,0x3C,0x32,0x09,0x00,
0x42,0x01,0x09,0x1E,0x02,0x42,0x09,0x10,0x1E,0x02,0x25,0x03,0x04,0x04,0x26,0x12,
0xFF,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
*/

0x01,       // cave
0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PARALLAX, //15,0x09,

STEEL,CH_DIRT,


CH_BLANK,CH_DIAMOND,CH_BOULDER,0,
0x70,0x12,0x06,0x00,

0x42,0x01,0x09+SHIFTY_1,0x1E,0x02,
0x42,0x09,0x10+SHIFTY_1,0x1E,0x02,

0x25,0x03,0x04+SHIFTY_1,     // entry
0x04,0x26,0x12+SHIFTY_1,     // exit

LINE+0,30,3+SHIFTY_1,6,DOWN,
LINE+0x32,30,3+SHIFTY_1,4,DOWN,

LINE+0,5,10+SHIFTY_1,7,DOWN,
LINE+0x32,5,10+SHIFTY_1,4,DOWN,


LINE+0,30,17+SHIFTY_1,5,DOWN,
LINE+0x32,30,17+SHIFTY_1,4,DOWN,



0xFF,

 };


UBYTE cave2[]= {

#define SHIFTY_2 -2

0x02,       // cave
0x14,       // milling
0x14,0x32,  // diamond $

0x03,0x00,0x01,0x57,0x58,       // randomiser[level]
0x0A,0x0C,0x09,0x0D,0x0A,
0x96,0x6E,0x46,0x46,0x46,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x00,0x10,0x14,0x08,
0x3C,0x32,0x09,0x02,

0x42,0x01,0x08+SHIFTY_2,0x26,0x02,
0x42,0x01,0x0F+SHIFTY_2,0x26,0x02,
0x42,0x08,0x03+SHIFTY_2,0x14,0x04,
0x42,0x10,0x03+SHIFTY_2,0x14,0x04,
0x42,0x18,0x03+SHIFTY_2,0x14,0x04,
0x42,0x20,0x03+SHIFTY_2,0x14,0x04,
0x40,0x01,0x05+SHIFTY_2,0x26,0x02,
0x40,0x01,0x0B+SHIFTY_2,0x26,0x02,
0x40,0x01,0x12+SHIFTY_2,0x26,0x02,
0x40,0x14,0x03+SHIFTY_2,0x14,0x04,

0x25,0x12,0x15+SHIFTY_2,     // entry
0x04,0x12,0x16+SHIFTY_2,     // exit

0xFF,
};

UBYTE cave3[]= {

#define SHIFTY_3 -2

0x03,       // cave
0x00,       // milling
0x0F,0x00,  // diamond $

0x00,0x32,0x36,0x34,0x37,       // randomiser[level]
0x18,0x17,0x18,0x17,0x15,
0x96,0x64,0x5A,0x50,0x46,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x02,0x10,0x14,0x00,
0x64,0x32,0x09,0x00,

0x25,0x03,0x04+SHIFTY_3,
0x04,0x27,0x14+SHIFTY_3,

0xFF,
};

UBYTE cave4[]= {

#define SHIFTY_4 -2

0x04,       // cave
0x14,       // milling
0x05,0x14,  // diamond $

0x00,0x6E,0x70,0x73,0x77,       // randomiser[level]
0x24,0x24,0x24,0x24,0x24,
0x78,0x64,0x50,0x3C,0x32,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x10,0x00,0x00,0x00,
0x14,0x00,0x00,0x00,

0x25,0x01,0x03+SHIFTY_4,
0x04,0x26,0x16+SHIFTY_4,

0x81,0x08,0x0A+SHIFTY_4,0x04,0x04,0x00,
0x30,0x0A,0x0B+SHIFTY_4,
0x81,0x10,0x0A+SHIFTY_4,0x04,0x04,0x00,
0x30,0x12,0x0B+SHIFTY_4,
0x81,0x18,0x0A+SHIFTY_4,0x04,0x04,0x00,
0x30,0x1A,0x0B+SHIFTY_4,
0x81,0x20,0x0A+SHIFTY_4,0x04,0x04,0x00,
0x30,0x22,0x0B+SHIFTY_4,

0xFF,
};

UBYTE cave5[]= {

#define SHIFTY_5 -2

0x05,       // cave
0x14,       // milling
0x32,0x5A,  // diamond $

0x00,0x00,0x00,0x00,0x00,       // randomiser[level]
0x04,0x05,0x06,0x07,0x08,
0x96,0x78,0x5A,0x3C,0x1E,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x25,0x01,0x03+SHIFTY_5, //entry
0x04,0x27,0x16+SHIFTY_5, //exit

0x80,0x08,0x0A+SHIFTY_5,0x03,0x03,0x00,
0x80,0x10,0x0A+SHIFTY_5,0x03,0x03,0x00,
0x80,0x18,0x0A+SHIFTY_5,0x03,0x03,0x00,
0x80,0x20,0x0A+SHIFTY_5,0x03,0x03,0x00,

0x14,0x09,0x0C+SHIFTY_5,
0x08,0x0A,0x0A+SHIFTY_5,
0x14,0x11,0x0C+SHIFTY_5,
0x08,0x12,0x0A+SHIFTY_5,
0x14,0x19,0x0C+SHIFTY_5,
0x08,0x1A,0x0A+SHIFTY_5,
0x14,0x21,0x0C+SHIFTY_5,
0x08,0x22,0x0A+SHIFTY_5,
0x80,0x08,0x10+SHIFTY_5,0x03,0x03,0x00,
0x80,0x10,0x10+SHIFTY_5,0x03,0x03,0x00,
0x80,0x18,0x10+SHIFTY_5,0x03,0x03,0x00,
0x80,0x20,0x10+SHIFTY_5,0x03,0x03,0x00,

0x14,0x09,0x12+SHIFTY_5,
0x08,0x0A,0x10+SHIFTY_5,
0x14,0x11,0x12+SHIFTY_5,
0x08,0x12,0x10+SHIFTY_5,
0x14,0x19,0x12+SHIFTY_5,
0x08,0x1A,0x10+SHIFTY_5,
0x14,0x21,0x12+SHIFTY_5,
0x08,0x22,0x10+SHIFTY_5,

0xFF,
};

UBYTE cave6[]= {

#define SHIFTY_6 -2

0x06,       // cave
0x14,       // mililng
0x28,0x3C,  // diamond $

0x00,0x14,0x15,0x16,0x17,       // randomiser[level]
0x04,0x06,0x07,0x08,0x08,
0x96,0x78,0x64,0x5A,0x50,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x10,0x00,0x00,0x00,
0x32,0x00,0x00,0x00,

0x82,0x01,0x03+SHIFTY_6,0x0A,0x04,0x00,
0x82,0x01,0x06+SHIFTY_6,0x0A,0x04,0x00,
0x82,0x01,0x09+SHIFTY_6,0x0A,0x04,0x00,
0x82,0x01,0x0C+SHIFTY_6,0x0A,0x04,0x00,

0x41,0x0A,0x03+SHIFTY_6,0x0D,0x04,
0x14,0x03,0x05+SHIFTY_6,
0x08,0x04,0x05+SHIFTY_6,
0x14,0x03,0x08+SHIFTY_6,
0x08,0x04,0x08+SHIFTY_6,
0x14,0x03,0x0B+SHIFTY_6,
0x08,0x04,0x0B+SHIFTY_6,
0x14,0x03,14+SHIFTY_6,
0x08,0x04,14+SHIFTY_6,
0x82,0x1D,0x03+SHIFTY_6,0x0A,0x04,0x00,
0x82,0x1D,0x06+SHIFTY_6,0x0A,0x04,0x00,
0x82,0x1D,0x09+SHIFTY_6,0x0A,0x04,0x00,
0x82,0x1D,0x0C+SHIFTY_6,0x0A,0x04,0x00,
0x41,0x1D,0x03+SHIFTY_6,0x0D,0x04,
0x14,0x24,0x05+SHIFTY_6,
0x08,0x23,0x05+SHIFTY_6,
0x14,0x24,0x08+SHIFTY_6,
0x08,0x23,0x08+SHIFTY_6,
0x14,0x24,0x0B+SHIFTY_6,
0x08,0x23,0x0B+SHIFTY_6,
0x14,0x24,14+SHIFTY_6,
0x08,0x23,14+SHIFTY_6,

0x25,0x03,0x14+SHIFTY_6, // entry
0x04,0x26,0x14+SHIFTY_6, // exit

0xFF,};

UBYTE cave7[]= {

#define SHIFTY_7 -2

0x07,       // cave
0x4B,       // milling
0x0A,0x14,  // diamond $

0x02,0x07,0x08,0x0A,0x09,       // randomiser[level]
0x0F,0x14,0x19,0x19,0x19,
0x78,0x78,0x78,0x78,0x78,

0,0,DEF_PARALLAX,          // water, ?, ?
STEEL,DIRT,

0x00,0x10,0x08,0x00,
0x64,0x28,0x02,0x00,

0x42,0x01,0x07+SHIFTY_7,0x0C,0x02,
0x42,0x1C,0x05+SHIFTY_7,0x0B,0x02,
0x7A,0x13,0x15+SHIFTY_7,0x02,0x02,

0x14,0x04,0x06+SHIFTY_7,
0x14,0x04,14+SHIFTY_7,
0x14,0x04,0x16+SHIFTY_7,
0x14,0x22,0x04+SHIFTY_7,
0x14,0x22,0x0C+SHIFTY_7,
0x14,0x22,0x16+SHIFTY_7,

0x25,0x14,0x03+SHIFTY_7,     // entry
0x04,0x27,0x07+SHIFTY_7,     // exit

0xFF,
};



UBYTE cave8[]= {

0x08,       // cave
0x14,       // milling
0x0A,0x14,  // diamond $

0x01,0x03,0x04,0x05,0x06,       // randomiser[level]
0x0A,0x0F,0x14,0x14,0x14,       // diamonds[level]
0x78,0x6E,0x64,0x5A,0x50,       // time[level]

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x00,0x10,0x08,0x00,            // random objects
0x5A,0x32,0x02,0x00,            // probability


0x14,0x04,0x06,
0x14,0x22,0x04,
0x14,0x22,0x0C,


0x04,0x00,0x05,                 // outbox
0x25,0x14,0x03,                 // inbox

0x42,0x01,0x07,0x0C,0x02,
0x42,0x01,0x0F,0x0C,0x02,
0x42,0x1C,0x05,0x0B,0x02,
0x42,0x1C,0x0D,0x0B,0x02,
0x43,0x0E,0x11,0x08,0x02,

0x14,0x0C,0x10,
0x00,0x0E,0x12,
0x14,0x13,0x12,

0x41,0x0E,0x0F,0x08,0x02,

0xFF,


};





UBYTE cave9[]= {

#define SHIFTY_9 -2

0x09,       // cave
0x14,       // milling
0x05,0x0A,  // diamond $

0x64,0x89,0x8C,0xFB,0x33,       // randomiser[level]
0x4B,0x4B,0x50,0x55,0x5A,            // diamonds
0x96,0x96,0x82,0x82,0x78,

0,20,0,  // NO PARALLAX
STEEL,DIRT,

0x10,0x14,0x00,0x00,
0xF0,0x78,0x00,0x00,

0x82,0x05,0x0A+SHIFTY_9,0x0D,0x0D,0x00,
0x01,0x0C,0x0A+SHIFTY_9,
0x82,0x19,0x0A+SHIFTY_9,0x0D,0x0D,0x00,
0x01,0x1F,0x0A+SHIFTY_9,
0x42,0x11,0x12+SHIFTY_9,0x09,0x02,
0x40,0x11,0x13+SHIFTY_9,0x09,0x02,

0x25,0x07,0x0C+SHIFTY_9,     // entry
0x04,0x08,0x0C+SHIFTY_9,     // exit

0xFF,
 };

UBYTE cave10[]= {

#define SHIFTY_10 -2

0x0A,       // cave
0x14,       // mililng
0x19,0x3C,  // diamond $

0x00,0x00,0x00,0x00,0x00,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x82,0x78,0x6E,0x64,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,

0x25,0x0D,0x03+SHIFTY_10,     // entry
0x04,0x27,0x16+SHIFTY_10,     // exit

0x54,0x05,0x04+SHIFTY_10,0x11,0x03,
0x54,0x15,0x04+SHIFTY_10,0x11,0x05,
FILLRECT+0,0x05,0x0B+SHIFTY_10,0x11,0x03,FIREFLY,
0xC2,0x01,0x04+SHIFTY_10,0x15,0x11,

0x00,0x0D,0x04+SHIFTY_10,
0xC2,0x07,0x06+SHIFTY_10,0x0D,0x0D,

0x00,0x0D,0x06+SHIFTY_10,
0xC2,0x09,0x08+SHIFTY_10,0x09,0x09,
0x00,0x0D,0x08+SHIFTY_10,
0xC2,0x0B,0x0A+SHIFTY_10,0x05,0x05,
0x00,0x0D,0x0A+SHIFTY_10,
FILLRECT+WALL,0x03,0x06+SHIFTY_10,0x03,0x0F,FIREFLY,
0x00,0x04,0x06+SHIFTY_10,
0x54,0x04,0x10+SHIFTY_10,0x04,0x04,

0xFF,
};



UBYTE cave11[]= {

#define SHIFTY_11 -2

0x0B,       // cave
0x14,       // milling
0x32,0x00,  // diamond $

0x00,0x04,0x66,0x97,0x64,       // randomiser[level]
0x06,0x06,0x06,0x06,0x06,
0x78,0x78,0x96,0x96,0xF0,

0,21,DEF_PARALLAX,
STEEL,DIRT,

0x00,0x10,0x08,0x00,
0x64,0x50,0x02,0x00,

0x42,0x0A,0x03+SHIFTY_11,0x09,0x04,
0x42,0x14,0x03+SHIFTY_11,0x09,0x04,
0x42,0x1E,0x03+SHIFTY_11,0x09,0x04,
0x42,0x09,0x16+SHIFTY_11,0x09,0x00,
0x42,0x0C,0x0F+SHIFTY_11,0x11,0x02,
0x42,0x05,0x0B+SHIFTY_11,0x09,0x02,
0x42,0x0F,0x0B+SHIFTY_11,0x09,0x02,
0x42,0x19,0x0B+SHIFTY_11,0x09,0x02,
0x42,0x1C,0x13+SHIFTY_11,0x0B,0x01,

0x14,0x04,0x03+SHIFTY_11,
0x14,0x0E,0x03+SHIFTY_11,
0x14,0x18,0x03+SHIFTY_11,
0x14,0x22,0x03+SHIFTY_11,
0x14,0x04,0x16+SHIFTY_11,
0x14,0x23,0x15+SHIFTY_11,

0x25,0x14,0x14+SHIFTY_11,     // entry
0x04,0x26,0x11+SHIFTY_11,     // exit

0xFF,
};

UBYTE cave12[]= {

#define SHIFTY_12 -2

0x0C,       // cave
0x14,       // milling
0x14,0x00,  // diamond $

0x00,0x3C,0x02,0x3B,0x66,       // randomiser[level]
0x13,0x13,0x0E,0x10,0x15,
0xB4,0xAA,0xA0,0xA0,0xA0,

23,0,DEF_PARALLAX,
STEEL,DIRT,

0x00,0x10,0x14,0x00,
0x3C,0x32,0x09,0x00,

0x42,0x0A,0x05+SHIFTY_12,0x12,0x04,
0x42,0x0E,0x05+SHIFTY_12,0x12,0x04,
0x42,0x12,0x05+SHIFTY_12,0x12,0x04,
0x42,0x16,0x05+SHIFTY_12,0x12,0x04,
0x42,0x02,0x06+SHIFTY_12,0x0B,0x02,
0x42,0x02,0x0A+SHIFTY_12,0x0B,0x02,
0x42,0x02,14+SHIFTY_12,0x0F,0x02,
0x42,0x02,0x12+SHIFTY_12,0x0B,0x02,

0x81,0x1E,0x04+SHIFTY_12,0x04,0x04,0x00,


0x08,0x20,0x05+SHIFTY_12,
0x81,0x1E,0x09+SHIFTY_12,0x04,0x04,0x00,
0x08,0x20,0x0A+SHIFTY_12,
0x81,0x1E,14+SHIFTY_12,0x04,0x04,0x00,
0x08,0x20,0x0F+SHIFTY_12,

0x25,0x03,0x14+SHIFTY_12,     // entry
0x04,0x27,0x16+SHIFTY_12,     // exit

0xFF,
};


UBYTE cave13[]= {

#define SHIFTY_13 -2

0x0D,       // cave
0x80,       // milling
0x05,0x08,  // diamond $

0x00,0x01,0x02,0x03,0x04,       // randomiser[level]
0x32,0x37,0x3C,0x46,0x50,
0xA0,0x9B,0x96,0x91,0x8C,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x10,0x00,0x00,0x00,    // random
0x28,0x00,0x00,0x00,    // probability

0x25,0x12,0x03+SHIFTY_13,         // entry
0x04,0x0A,0x03+SHIFTY_13,         // exit


AMOEBA,0x14,0x03+SHIFTY_13,

0x42,0x05,0x12+SHIFTY_13,0x1E,0x02,
0x70,0x05,0x13+SHIFTY_13,0x1E,0x02,
0x50,0x05,0x14+SHIFTY_13,0x1E,0x02,
0xC1,0x05,0x15+SHIFTY_13,0x1E,0x02,

0xFF,
};

UBYTE cave14[]= {

#define SHIFTY_14 -2

0x0E,       // cave
0x14,       // milling
0x0A,0x14,  // diamond $

0x00,0x00,0x00,0x00,0x00,       // randomiser[level]
0x1E,0x23,0x28,0x2A,0x2D,
0x96,0x91,0x8C,0x87,0x82,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x10,0x00,0x00,0x00,        // object
0x00,0x00,0x00,0x00,        // probability


FILLRECT+DIRT,0x0A,0x0A+SHIFTY_14,0x0D,0x0D,0x00,
LINE+0x30,0x0B,0x0B+SHIFTY_14,0x0C,0x03,
0xC1,0x0C,0x0A+SHIFTY_14,0x03,0x0D,
0xC1,0x10,0x0A+SHIFTY_14,0x03,0x0D,
0xC1,0x14,0x0A+SHIFTY_14,0x03,0x0D,
LINE+BOULDER,0x16,0x08+SHIFTY_14,0x0C,0x02,
LINE+8,0x16,0x07+SHIFTY_14,0x0C,0x02,
0xC1,0x17,0x06+SHIFTY_14,0x03,0x04,
0xC1,0x1B,0x06+SHIFTY_14,0x03,0x04,
0xC1,0x1F,0x06+SHIFTY_14,0x03,0x04,

0x25,0x03,0x03+SHIFTY_14,             // entry
0x04,0x27,0x14+SHIFTY_14,             // exit

0xFF,
};

UBYTE cave15[]= {

#define SHIFTY_15  -2

0x0F,       // cave
0x08,       // milling
0x0A,0x14,  // diamond $

0x01,0x1D,0x1E,0x1F,0x20,       // randomiser[level]
0x0F,0x14,0x14,0x19,0x1E,
0x78,0x78,0x78,0x78,0x8C,

0,0,DEF_PARALLAX,
STEEL,DIRT,


0x00,0x10,0x08,0x00,
0x64,0x50,0x02,0x00,

0x42,0x02,0x04+SHIFTY_15,0x0A,0x03,
0x42,0x0F,0x0D+SHIFTY_15,0x0A,0x01,
0x41,0x0C,14+SHIFTY_15,0x03,0x02,
0x43,0x0C,0x0F+SHIFTY_15,0x03,0x02,

0x04,0x14,0x16+SHIFTY_15,     // exit
0x25,0x14,0x03+SHIFTY_15,     // entry

0xFF,
 };

UBYTE cave16[]= {

#define SHIFTY_16 -2

0x10,       // cave
0x14,       // milling
0x0A,0x14,  // diamond $

0x01,0x78,0x81,0x7E,0x7B,       // randomiser[level]
0x0C,0x0F,0x0F,0x0F,0x0C,
0x96,0x96,0x96,0x96,0x96,

0,0,DEF_PARALLAX,
STEEL,DIRT,

0x10,0x00,0x00,0x00,
0x32,0x00,0x00,0x00,

0x25,0x01,0x03+SHIFTY_16,     // entry
0x04,0x27,0x04+SHIFTY_16,     // exit

0x81,0x08,0x13+SHIFTY_16,0x04,0x04,0x00,

0x08,0x0A,0x14+SHIFTY_16,
0xC2,0x07,0x0A+SHIFTY_16,0x06,0x08,
0x43,0x07,0x0A+SHIFTY_16,0x06,0x02,
0x81,0x10,0x13+SHIFTY_16,0x04,0x04,0x00,
0x08,0x12,0x14+SHIFTY_16,
0xC2,0x0F,0x0A+SHIFTY_16,0x06,0x08,
0x43,0x0F,0x0A+SHIFTY_16,0x06,0x02,
0x81,0x18,0x13+SHIFTY_16,0x04,0x04,0x00,
0x08,0x1A,0x14+SHIFTY_16,
0x81,0x20,0x13+SHIFTY_16,0x04,0x04,0x00,
0x08,0x22,0x14+SHIFTY_16,


0xFF,
};

UBYTE cave17[]= {

#define SHIFTX_17 10
#define SHIFTY_17 3

0x11,       // cave
0x10,       // milling
0x1E,0x00,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x06,0x06,0x06,0x06,0x06,       // diamonds[level]
0x14,0x14,0x14,0x14,0x14,       // time[level]

0,0,DEF_PARALLAX,
STEEL,DIRT,                      // border, fill


BOULDER,DIAMOND,0x00,0x00,            // random objects
0x04,0x08,0x00,0x00,            // probability

//FILLRECT+DIRT,0x00,0x02,0x28,0x16,DIRT,       // was STEEL
FILLRECT+AMOEBA,0x00+SHIFTX_17-1,0x02+SHIFTY_17-1,0x14+2,0x0C+2,AMOEBA,
FILLRECT+STEEL,0x00+SHIFTX_17,0x02+SHIFTY_17,0x14,0x0C,0x00,
BUTTERFLY,0x0A+SHIFTX_17,0x0C+SHIFTY_17,
BOULDER,0x0A+SHIFTX_17,0x04+SHIFTY_17,
DIRT,0x0A+SHIFTX_17,0x05+SHIFTY_17,

INBOX,0x03+SHIFTX_17,0x05+SHIFTY_17,                 // entry
0x04,0x12+SHIFTX_17,0x0C+SHIFTY_17,                 // exit




0xFF,
};

UBYTE cave18[]= {

#define SHIFTX_18 10
#define SHIFTY_18 3

0x12,       // cave
0x10,       // milling
0x0A,0x00,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x10,0x10,0x10,0x10,0x10,       // diamonds[level]
0x0F,0x0F,0x0F,0x0F,0x0F,       // time[level]

0,0,0,
0, 0,                    // border, fill

0,0,0x00,0x00,            // random objects
0,0,0x00,0x00,            // probability

//FILLRECT+DIRT,0x00,0x00,0x28,0x18,DIRT,
FILLRECT+STEEL,0x00+SHIFTX_18,0x02+SHIFTY_18,0x14,0x0C,DIRT,

0x50,0x01+SHIFTX_18,0x03+SHIFTY_18,0x09,0x03,
0x48,0x02+SHIFTX_18,0x03+SHIFTY_18,0x08,0x03,
0x54,0x01+SHIFTX_18,0x05+SHIFTY_18,0x08,0x03,
0x50,0x01+SHIFTX_18,0x06+SHIFTY_18,0x07,0x03,
0x50,0x12+SHIFTX_18,0x03+SHIFTY_18,0x09,0x05,
0x54,0x12+SHIFTX_18,0x05+SHIFTY_18,0x08,0x05,
0x50,0x12+SHIFTX_18,0x06+SHIFTY_18,0x07,0x05,

0x25,0x01+SHIFTX_18,0x04+SHIFTY_18,                 // entry
0x04,0x12+SHIFTX_18,0x04+SHIFTY_18,                 // exit

0xFF,
};


UBYTE cave19[]= {

#define SHIFTX_19 0
#define SHIFTY_19 -2


0x13,       // cave
0xA0,       // milling
0x0A,0x00,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
50,50,50,50,50,
0xE4,0x14,0x14,0x14,0x14,

0,0,DEF_OVERVIEW|DEF_PARALLAX,
STEEL,DIRT,

0,0,CH_BOULDER,0x00,
0xA0,0xE0,0x20,0x00,



FILLRECT+STEEL,20-2,10-1+SHIFTY_19,5,5,CH_FIREFLY_0,
CH_BOULDER,20,11,
DIRT,20,12,

//LINE+8,38,0x0A+SHIFTY_19,0x06,0x0,




0x04,39+SHIFTX_19,3+SHIFTY_19,     // exit
0x25,28,0x03,                 // entry

CH_BUTTERFLY1, 16,8+SHIFTY_19,           // butterfly breeds on egg
CH_BUTTERFLY1, 17,8+SHIFTY_19,           // butterfly breeds on egg
CH_BUTTERFLY1, 18,8+SHIFTY_19,           // butterfly breeds on egg

CH_AMOEBA0, 30, 18+SHIFTY_19,

0xFF,
};

UBYTE cave20[]= {

#define SHIFTX_20 10
#define SHIFTY_20 3

    
0x14,       // cave
0x10,       // milling
0x1E,0x00,  // diamond $

0x00,0x00,0x00,0x00,0x00,       // randomiser[level]
0x06,0x06,0x06,0x06,0x06,
0x2C,0x2C,0x2C,0x2C,0x2C,

0,0,0,
STEEL,0,

AMOEBA,0,0,0,        // random
6,0,0,0,        // probability

//FILLRECT+0,0x00,0x00,0x28,0x16,0,
FILLRECT+STEEL,0x00+SHIFTX_20,0x02+SHIFTY_20,0x14,0x0C,DIRT,

0xD0,0x0B+SHIFTX_20,0x03+SHIFTY_20,0x03,0x02,

FILLRECT+0,0x0B+SHIFTX_20,0x07+SHIFTY_20,0x03,0x06,0x00,
LINE+3,0x0B+SHIFTX_20,0x06+SHIFTY_20,0x03,0x02,
LINE+3,0x0B+SHIFTX_20,0x0A+SHIFTY_20,0x03,0x02,

LINE+0x10,0x08+SHIFTX_20,0x07+SHIFTY_20,0x03,0x03,

0x25,0x03+SHIFTX_20,0x03+SHIFTY_20,     // entry
0x04,0x09+SHIFTX_20,0x0A+SHIFTY_20,     // exit

0xFF,
};


const struct caveInfo caveList[] = {




    // 1
   { cave1,        {   { 0x24, 0x96, 0xC6,
               0x26, 0x26, 0x26, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
    },
    },

    { cave12,       {   { 0xC4, 0x24, 0xF6,
                0xC8, 0xC8, 0xC8, 0xC8, 0xC8, 0xC8, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6,
            0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2
            },
                },
    },



    {
        // amoeba at bottom needs to be enclosed
        // lava

    // 2
        cave7,      {   { 0x46, 0x76, 0xC8,
            0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD6, 0xD4, 0xD4, 0xD4,
            0xD4, 0xD4, 0xD4, 0xD4, 0xD2, 0xD2, 0xD2, 0xD2, 0xD2, 0xD2,
         0xC6, 0xC2,
            },
        },
    },

    // 3
    {
        cave3,      {   { 0x24, 0x24, 0xD6,
                    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x86, 0x86, 0x86, 0x86, 0x86,
            0x86, 0x86, 0x86, 0x86, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94
            },
            },
    },






/*    { caveCat,    {   { 0x26, 0x7A, 0xC6,
            0x14,0x14,
            0x14,0x14,
            0x24, 0x24,0x24,
            0x24,0x24,
            0x34,0x34,
            0x34,0x34,
            0x34,0x44,0x44,0x42,0x42,0x42,0x54,0x54,0x54,
            0x26, 0x26
            },
            },
    },
*/

    // 4
        { caveCat,      {   { 0x46, 0x96, 0xC4,
            0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34,
            0x34, 0x34, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
         0x34, 0x30,
            },
        },
        },


    // 5
    { cave9,        {   { 0x46, 0x26, 0xC6,
                0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0x94, 0x94, 0x94, 0x94, 0x94,
                0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x86, 0x74, 0x74, 0x74, 0x74,
            0x94, 0x94
            },
                },
    },


    // 6
    {
        BD4_caveD,  {   { 0x76, 0x46, 0xE8,
            0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0x94, 0x94, 0x94, 0x94, 0x94,
            0x94, 0x94, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4, 0xA4,
         0x96, 0x96,
            },
            },
},


    // 7
    {
        // tetris

        BD2_caveB,  {   { 0x82, 0x26, 0xC6,
            0x84,0x84,
            0x94,0x94,
            0xA4, 0xA4,0xB4,
            0xC4,0xD4,
            0xE4,0xF4,
            0x24,0x34,
            0x44,0x54,0x64,0x74,0x84,0x94,0xA4,0xB4,0xC4,
            0x26, 0x26
            },
            },
    },


    




    // 8
    { cave15,     { 
                    { 0x76, 0x34, 0xC6,
            0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
            0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
             0xC2, 0xC2
            },
    },
    },


    // 9
    { cave19,       {   { 0x32, 0x24, 0xC8,
                0x26, 0x26, 0x26, 0x36, 0x36, 0x36, 0x46, 0x46, 0x46, 0x56, 0x56, 0x56,
            0x66, 0x66, 0x66, 0x76, 0x76, 0x76, 0x88, 0x88, 0x88, 0x98,
             0x96, 0x96
            },
                },
    },

    // 10
    { cave17,       {   { 0x84, 0x24, 0xE8,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },


    // 11
    { cave18,       {   { 0x76, 0x44, 0xD6,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },



    // 12
    { cave20,       {   { 0xB4, 0x44, 0x66,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },





    { cave16,
        { { 0x44, 0x24, 0xB6,
            0x64, 0x64, 0x64, 0x64, 0x54, 0x54, 0x54, 0x54, 0x44, 0x44, 0x44, 0x44,
            0x34, 0x34, 0x34, 0x34, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
            0x94, 0x94  // not seen
        },},
    },



    { cave13,       {   { 0xA4, 0x24, 0xD8,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },

    { cave10,       {   { 0x76, 0x64, 0xE8,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },



    { cave11,       {   { 0x24, 0x76, 0xD8,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },



    {    // vertical butterflies in columns at left

        cave14,     {   { 0x24, 0x24, 0xC6,
                    0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
            },
    },

    {   // 8 fireflies in boxes guarding diamonds

        cave5,      {   { 0xE4, 0x44, 0xA8,
                    0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
            },
    },

    {
        // 4 enclosed butterflies in boxes at bottom

        cave4,      {   { 0xB4, 0x44, 0x28,
                    0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
            },
    },



    {
        cave6,      {   { 0x36, 0xA4, 0xC8,
                    0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
            },
    },


/*    {
        cave2,      {   { 0xC4, 0x26, 0x78 },
//                        { 0xC4, 0x26, 0x78 },
//                        { 0xC4, 0x26, 0x78 },
//                        { 0xC4, 0x26, 0x78 },
//                        { 0xC4, 0x26, 0x78 },
                    },
    },
*/

    { cave8,        {   { 0x76, 0x44, 0xD6,
                0x24, 0x24, 0x24, 0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54,
            0x64, 0x64, 0x64, 0x74, 0x74, 0x74, 0x84, 0x84, 0x84, 0x94, 0x94, 0x94
            },
                },
    },



};

const int caveCount = sizeof(caveList) / sizeof(caveList[0]);






