
#include "main.h"
#include "cavedata.h"
#include "attribute.h"
#include "charRuntime.h"

#define LINE 0b01000000
#define FILLRECT 0b10000000
#define RECT 0b11000000

/*#define DIRT 1
#define DOGE 0x14
#define WALL 2
#define STEEL 7
#define BOULDER 0x10
#define INBOX 0x25
#define OUTBOX 4
#define AMOEBA 0x3A
*/

#define UP 0
#define UPRIGHT 1
#define RIGHT 2
#define DOWNRIGHT 3
#define DOWN 4
#define DOWNLEFT 5
#define LEFT 6
//#define UPLEFT 7


// UBYTE cave1[]= {

// #define SHIFTY_1 -2

// /*
// 0x01,0x14,0x0A,0x0F,0x0A,0x0B,0x0C,0x0D,0x0E,0x0C,0x0C,0x0C,0x0C,0x0C,0x96,0x6E,
// 0x46,0x28,0x1E,0x08,0x0B,0x09,0xD4,0x20,0x00,0x14,0x10,0x00,0x3C,0x32,0x09,0x00,
// 0x42,0x01,0x09,0x1E,0x02,0x42,0x09,0x10,0x1E,0x02,0x25,0x03,0x04,0x04,0x26,0x12,
// 0xFF,
// 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
// */

// 0x01,       // cave
// 0x14,       // milling
// 0x0A,0x0F,  // diamond $

// 0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
// 0x0C,0x0C,0x0C,0x0C,0x0C,
// 0x96,0x6E,0x46,0x28,0x1E,

// 0,0,DEF_PARALLAX, //15,0x09,

// CH_STEEL,CH_DIRT,


// CH_DOGE,CH_BLANK,CH_ROCK0,CH_EGG,
// 0x68, 0x60,0x10,0x2,

// //0x42,0x01,0x09+SHIFTY_1,0x1E,0x02,
// //0x42,0x09,0x10+SHIFTY_1,0x1E,0x02,

// 0,CH_DOORCLOSED,0x03,0x04+SHIFTY_1,     // entry
// 0,CH_DOOROPEN_0,0x26,0x12+SHIFTY_1,     // exit

// 0,CH_EGG, 0x20, 0x10 + SHIFTY_1,

// LINE,CH_ZZAP, 30,13+SHIFTY_1,6, DOWN,

// LINE,CH_BRICKWALL, 20,10+SHIFTY_1,4, DOWN,
// LINE,CH_BRICKWALL, 21,10+SHIFTY_1,4, DOWN,



// // LINE+CH_ZZAP,30,13+SHIFTY_1,6,DOWN,
// // LINE+0x32,30,3+SHIFTY_1,4,DOWN,

// // LINE+0,5,10+SHIFTY_1,7,DOWN,
// // LINE+0x32,5,10+SHIFTY_1,4,DOWN,


// // LINE+0,30,17+SHIFTY_1,5,DOWN,
// // LINE+0x32,30,17+SHIFTY_1,4,DOWN,



// 0xFF,

//  };


// UBYTE cave12[]= {

// #define SHIFTY_12 -2


// /*
// 0x01,0x14,0x0A,0x0F,0x0A,0x0B,0x0C,0x0D,0x0E,0x0C,0x0C,0x0C,0x0C,0x0C,0x96,0x6E,
// 0x46,0x28,0x1E,0x08,0x0B,0x09,0xD4,0x20,0x00,0x14,0x10,0x00,0x3C,0x32,0x09,0x00,
// 0x42,0x01,0x09,0x1E,0x02,0x42,0x09,0x10,0x1E,0x02,0x25,0x03,0x04,0x04,0x26,0x12,
// 0xFF,
// 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
// */

// 0x01,       // cave
// 0x14,       // milling
// 0x0A,0x0F,  // diamond $

// 0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
// 0x0C,0x0C,0x0C,0x0C,0x0C,
// 0x96,0x6E,0x46,0x28,0x1E,

// 0,23,DEF_PARALLAX, //15,0x09,

// CH_STEEL,CH_DIRT,


// CH_DOGE,CH_BLANK,CH_ROCK0,CH_EGG,
// 0x68, 0x60,0x60,0x2,

// //0x42,0x01,0x09+SHIFTY_1,0x1E,0x02,
// //0x42,0x09,0x10+SHIFTY_1,0x1E,0x02,

// 0,CH_DOORCLOSED,0x03,0x04+SHIFTY_12,     // entry
// 0,CH_DOOROPEN_0,0x26,0x12+SHIFTY_12,     // exit

// 0,CH_EGG, 0x20, 0x10 + SHIFTY_12,

// LINE, CH_BELT, 2, 20+SHIFTY_12, 15, RIGHT,
// LINE, CH_BELT1, 2, 18+SHIFTY_12, 5, RIGHT,

// LINE,CH_ZZAP, 20,2+SHIFTY_12,20, DOWN,
// LINE,CH_ZZAP1, 21,2+SHIFTY_12,20, DOWN,

// //LINE,CH_DRILL, 18,2+SHIFTY_1,20, DOWN,

// 0, CH_DRILLBODY, 10, 12,
// 0, CH_DRILLBODY1, 10, 11,



// 0xFF,

// };


UBYTE cave12b[]= {
#define CAVE12b_DEPTH 22


0x01,       // cave

40,CAVE12b_DEPTH,1,      // size x,y + gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PARALLAX|DEF_DRIP, //15,0x09,

CH_STEEL,CH_DIRT,


CH_DIRT,CH_DOGE,CH_ROCK0,CH_EGG,
0xB0, 0x8, 0x60,0xA,

0,CH_DOORCLOSED,0x03,0x04,     // entry
LINE,CH_ZZAP, 20,2,19, DOWN,
LINE,CH_ZZAP1, 21,2,19, DOWN,


0, CH_DRILLBODY, 6, 10,
0, CH_DRILLBODY1, 6, 9,


0xFF,

};


#define BLOT(x,y)\
0, CH_BLANK, x+10,y+5,\
0, CH_ROCK0, x+9,y+5,\
0, CH_ROCK0, x+10,y+4,\
0, CH_ROCK0, x+10,y+6,\
0, CH_ROCK0, x+11,y+5,\
0, CH_AMOEBA0, x+9,y+4,\
0, CH_AMOEBA0, x+9,y+3,\
0, CH_AMOEBA0, x+10,y+3,\
0, CH_AMOEBA0, x+11,y+3,\
0, CH_AMOEBA0, x+11,y+4,\
0, CH_AMOEBA0, x+12,y+4,\
0, CH_AMOEBA0, x+12,y+5,\
0, CH_AMOEBA0, x+12,y+6,\
0, CH_AMOEBA0, x+11,y+6,\
0, CH_AMOEBA0, x+11,y+7,\
0, CH_AMOEBA0, x+10,y+7,\
0, CH_AMOEBA0, x+9,y+7,\
0, CH_AMOEBA0, x+9,y+6,\
0, CH_AMOEBA0, x+8,y+6,\
0, CH_AMOEBA0, x+8,y+5,\
0, CH_AMOEBA0, x+8,y+4,


static const unsigned char planet0[]= {
#define PLANET0_DEPTH 20

0x01,       // cave

40,PLANET0_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_DIRT,


CH_ROCK0,CH_DIRT,CH_DOGE,0,
160, 10, 0, 0,

LINE, CH_STEEL, 0,0, 40, RIGHT,
LINE, CH_STEEL, 0,PLANET0_DEPTH-1, 40, RIGHT,



LINE, CH_STEEL, 0,0, 19, DOWNRIGHT,
LINE, CH_STEEL, 1,0, 19, DOWNRIGHT,
LINE, CH_DOGE, 3,0, 19, DOWNRIGHT,
LINE, CH_DOGE, 4,0, 19, DOWNRIGHT,
LINE, CH_DOGE, 5,0, 19, DOWNRIGHT,
LINE, CH_STEEL, 8,0, 19, DOWNRIGHT,
LINE, CH_STEEL, 9,0, 19, DOWNRIGHT,
LINE, CH_DIRT, 12,0, 19, DOWNRIGHT,
LINE, CH_DIRT, 13,0, 19, DOWNRIGHT,
LINE, CH_STEEL, 16,0, 19, DOWNRIGHT,
LINE, CH_STEEL, 17,0, 19, DOWNRIGHT,
LINE, CH_DIRT, 20,0, 19, DOWNRIGHT,
LINE, CH_DIRT, 21,0, 18, DOWNRIGHT,


BLOT(0,0)
BLOT(10,4)
BLOT(15,12)
BLOT(-4,8)


0xFF,

};


static const unsigned char usa[]= {
#define USA_DEPTH 20

0x01,       // cave

40,USA_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_DIRT,


0,0,0,0,
0,0,0,0,


0, CH_MYSTERY0, 0, 8,
0, CH_MYSTERY1, 1, 8,

0, CH_MYSTERY1_0, 0, 9,
0, CH_MYSTERY1_1, 1, 9,

0, CH_MYSTERY2_0, 0, 10,
0, CH_MYSTERY2_1, 1, 10,

0, CH_MYSTERY3_0, 0, 11,
0, CH_MYSTERY3_1, 1, 11,

0xFF,

};


static const unsigned char zph[]= {
#define ZPH_DEPTH 20

0x01,       // cave

40,ZPH_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_DIRT,


CH_ROCK0,CH_EGG,CH_DOGE,CH_AMOEBA0,
40, 0, 40, 10,


BLOT(11,2 )

LINE, CH_STEEL, 0,0, 40, RIGHT,
LINE, CH_STEEL, 0,PLANET0_DEPTH-1, 40, RIGHT,


LINE, CH_FLAT_2, 0,8-2, 5, RIGHT,
LINE, CH_FLAT_2, 4,9-2, 5, DOWNLEFT,
LINE, CH_FLAT_2, 0,14-2, 5, UPRIGHT,
LINE, CH_FLAT_2, 0,15-2, 5, RIGHT,

LINE, CH_FLAT_2, 6,8-2, 4, RIGHT,
LINE, CH_FLAT_2, 10,9-2, 3, DOWN,
LINE, CH_FLAT_2, 6,12-2, 4, RIGHT,
LINE, CH_FLAT_2, 6,8-2, 8, DOWN,

LINE, CH_FLAT_2, 12,8-2, 7, DOWN,
LINE, CH_FLAT_2, 16,8-2, 7, DOWN,
LINE, CH_FLAT_2, 12,11-2, 5, RIGHT,


BLOT(15,8)


0xFF,

};

static const unsigned char planetEarth[]= {
#define PLANETEARTH_DEPTH 20
#define SHIFT_EARTH 1

0x01,       // cave

40,PLANETEARTH_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_FLAT_1BLANK,


0,0,0,0,
0,0,0, 0,



LINE, CH_STEEL, 0,0,30, RIGHT,
LINE, CH_STEEL, 0,1,30, RIGHT,
LINE, CH_STEEL, 0,2,30, RIGHT,


LINE, CH_STEEL, 0,18,30, RIGHT,
LINE, CH_STEEL, 0,17,30, RIGHT,
LINE, CH_STEEL, 0,16,3, RIGHT,



LINE, CH_LATITUDE2, 0, 0, 19, DOWN,
//LINE, CH_LATITUDE, 2, 0, 19, DOWN,
LINE, CH_LATITUDE2, 5, 0, 19, DOWN,
//LINE, CH_LATITUDE, 6, 0, 19, DOWN,
LINE, CH_LATITUDE2, 10, 0, 19, DOWN,
//LINE, CH_LATITUDE, 10, 0, 19, DOWN,
LINE, CH_LATITUDE2, 15, 0, 19, DOWN,
//LINE, CH_LATITUDE, 14, 0, 19, DOWN,
LINE, CH_LATITUDE2, 20, 0, 19, DOWN,
//LINE, CH_LATITUDE, 18, 0, 19, DOWN,
LINE, CH_LATITUDE2, 25, 0, 19, DOWN,
//LINE, CH_LATITUDE, 22, 0, 19, DOWN,
//LINE, CH_LATITUDE, 24, 0, 19, DOWN,
//LINE, CH_LATITUDE, 26, 0, 19, DOWN,
//LINE, CH_LATITUDE, 28, 0, 19, DOWN,
// LINE, CH_LATITUDE, 30, 0, 19, DOWN,
// LINE, CH_LATITUDE, 12, 0, 19, DOWN,
// LINE, CH_LATITUDE, 14, 0, 19, DOWN,
// LINE, CH_LATITUDE, 16, 0, 19, DOWN,
// LINE, CH_LATITUDE, 18, 0, 19, DOWN,

// LINE, CH_ROCK0, 22,1, 5, RIGHT,
// 0, CH_ROCK0, 1, 2,
// LINE, CH_ROCK0, 4,2, 3, RIGHT,
// LINE, CH_ROCK0, 17,2, 10, RIGHT,
// LINE, CH_ROCK0, 5,3, 5, RIGHT,
// LINE, CH_ROCK0, 15,3, 11, RIGHT,
// LINE, CH_ROCK0, 5,4, 4, RIGHT,
// 0, CH_ROCK0, 18, 4,
// 0, CH_ROCK0, 20, 4,
// LINE, CH_ROCK0, 23,4, 4, RIGHT,
// 0, CH_ROCK0, 6, 5,
// LINE, CH_ROCK0, 21,5, 4, RIGHT,
// LINE, CH_ROCK0, 14,6, 5, RIGHT,
// 0, CH_ROCK0, 21, 6,
// LINE, CH_ROCK0, 8,7, 3, RIGHT,
// LINE, CH_ROCK0, 16,7, 3, RIGHT,



//LINE, CH_DIRT, 0,0+SHIFT_EARTH,30, RIGHT,

0, CH_DIRT, 8, 0+SHIFT_EARTH,
LINE, CH_DIRT, 10,0+SHIFT_EARTH, 3, RIGHT,
LINE, CH_ROCK0, 22,0+SHIFT_EARTH, 4, RIGHT,

LINE, CH_ROCK0, 1,1+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 5, 1+SHIFT_EARTH,
LINE, CH_DIRT, 11,1+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 17, 1+SHIFT_EARTH,
LINE, CH_ROCK0, 21,1+SHIFT_EARTH, 9, RIGHT,
//todo vert strip 3 yellow

LINE, CH_ROCK0, 0,2+SHIFT_EARTH, 8, RIGHT,
0, CH_AMOEBA0, 3, 2+SHIFT_EARTH,
0, CH_DIRT, 8, 2+SHIFT_EARTH,
LINE, CH_ROCK0, 16,2+SHIFT_EARTH, 14, RIGHT,
0,CH_AMOEBA0, 28,2+SHIFT_EARTH,

0, CH_DIRT, 3, 3+SHIFT_EARTH,
LINE, CH_AMOEBA0, 4,3+SHIFT_EARTH, 2, DOWN,
LINE, CH_ROCK0, 5,3+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 17,3+SHIFT_EARTH, 9, RIGHT,
LINE, CH_AMOEBA0, 26, 1+SHIFT_EARTH, 3, DOWN,
0, CH_ROCK0, 28, 3+SHIFT_EARTH,

LINE, CH_AMOEBA0, 4,4+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 6,4+SHIFT_EARTH, 4, RIGHT,
LINE, CH_ROCK0, 15,4+SHIFT_EARTH, 12, RIGHT,
0, CH_AMOEBA0, 22, 4+SHIFT_EARTH,
0, CH_AMOEBA0, 24, 4+SHIFT_EARTH,
LINE, CH_AMOEBA0, 5,5+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 7,5+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 15, 5+SHIFT_EARTH,
0, CH_AMOEBA0, 17, 5+SHIFT_EARTH,
LINE, CH_ROCK0, 18,5+SHIFT_EARTH, 3, RIGHT,
LINE, CH_AMOEBA0, 21,5+SHIFT_EARTH, 4, RIGHT,
0, CH_ROCK0, 25,5+SHIFT_EARTH,
LINE, CH_AMOEBA0, 5,6+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 7,6+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 15, 6+SHIFT_EARTH,
0, CH_ROCK0, 18, 6+SHIFT_EARTH,
LINE, CH_AMOEBA0, 19,6+SHIFT_EARTH, 2, RIGHT,
LINE, CH_DIRT, 21,6+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 23, 6+SHIFT_EARTH,
0, CH_ROCK0, 24, 6+SHIFT_EARTH,
0, CH_AMOEBA0, 26, 6+SHIFT_EARTH,

0, CH_AMOEBA0, 6, 7+SHIFT_EARTH,
LINE, CH_ROCK0, 14,7+SHIFT_EARTH, 11, RIGHT,
0, CH_AMOEBA0, 15, 7+SHIFT_EARTH,
0, CH_AMOEBA0, 18, 7+SHIFT_EARTH,
0, CH_AMOEBA0, 19, 7+SHIFT_EARTH,
0, CH_AMOEBA0, 23, 7+SHIFT_EARTH,

0, CH_AMOEBA0, 7, 8+SHIFT_EARTH,
LINE, CH_ROCK0, 14,8+SHIFT_EARTH, 4, RIGHT,
0, CH_ROCK0, 21, 8+SHIFT_EARTH,
0, CH_ROCK0, 23, 8+SHIFT_EARTH,

0, CH_AMOEBA0, 9, 9+SHIFT_EARTH,
0, CH_ROCK0, 10, 9+SHIFT_EARTH,
LINE, CH_ROCK0, 16,9+SHIFT_EARTH, 3, RIGHT,
0, CH_AMOEBA0, 17, 9+SHIFT_EARTH,
LINE, CH_ROCK0, 23,9+SHIFT_EARTH, 2, RIGHT,


LINE, CH_ROCK0, 8,10+SHIFT_EARTH, 4, RIGHT,
LINE, CH_AMOEBA0, 16,10+SHIFT_EARTH, 2, RIGHT,

LINE, CH_ROCK0, 9,11+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 11, 11+SHIFT_EARTH, 
LINE, CH_AMOEBA0, 16,11+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 25, 11+SHIFT_EARTH, 2, RIGHT,


LINE, CH_ROCK0, 9,12+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 16, 12+SHIFT_EARTH,
LINE, CH_ROCK0, 25,12+SHIFT_EARTH, 3, RIGHT,

0, CH_ROCK0, 25, 13+SHIFT_EARTH,






//LINE, CH_STEEL, 0, 0, 19, DOWN,


//0,CH_DOORCLOSED,0x03,0x04,     // entry

0xFF,

};


static const unsigned char planetEarth2[]= {
#define PLANETEARTH_DEPTH 20
#define SHIFT_EARTH 1

0x01,       // cave

40,PLANETEARTH_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_FLAT_1BLANK,


0,0,0,0,
0,0,0, 0,



LINE, CH_STEEL, 0,0,30, RIGHT,
LINE, CH_STEEL, 0,1,30, RIGHT,
LINE, CH_STEEL, 0,2,30, RIGHT,


LINE, CH_STEEL, 0,18,30, RIGHT,
LINE, CH_STEEL, 0,17,30, RIGHT,
LINE, CH_STEEL, 0,16,3, RIGHT,



LINE, CH_LATITUDE2, 0, 0, 19, DOWN,
//LINE, CH_LATITUDE, 2, 0, 19, DOWN,
LINE, CH_LATITUDE2, 5, 0, 19, DOWN,
//LINE, CH_LATITUDE, 6, 0, 19, DOWN,
LINE, CH_LATITUDE2, 10, 0, 19, DOWN,
//LINE, CH_LATITUDE, 10, 0, 19, DOWN,
LINE, CH_LATITUDE2, 15, 0, 19, DOWN,
//LINE, CH_LATITUDE, 14, 0, 19, DOWN,
LINE, CH_LATITUDE2, 20, 0, 19, DOWN,
//LINE, CH_LATITUDE, 18, 0, 19, DOWN,
LINE, CH_LATITUDE2, 25, 0, 19, DOWN,
//LINE, CH_LATITUDE, 22, 0, 19, DOWN,
//LINE, CH_LATITUDE, 24, 0, 19, DOWN,
//LINE, CH_LATITUDE, 26, 0, 19, DOWN,
//LINE, CH_LATITUDE, 28, 0, 19, DOWN,
// LINE, CH_LATITUDE, 30, 0, 19, DOWN,
// LINE, CH_LATITUDE, 12, 0, 19, DOWN,
// LINE, CH_LATITUDE, 14, 0, 19, DOWN,
// LINE, CH_LATITUDE, 16, 0, 19, DOWN,
// LINE, CH_LATITUDE, 18, 0, 19, DOWN,

// LINE, CH_ROCK0, 22,1, 5, RIGHT,
// 0, CH_ROCK0, 1, 2,
// LINE, CH_ROCK0, 4,2, 3, RIGHT,
// LINE, CH_ROCK0, 17,2, 10, RIGHT,
// LINE, CH_ROCK0, 5,3, 5, RIGHT,
// LINE, CH_ROCK0, 15,3, 11, RIGHT,
// LINE, CH_ROCK0, 5,4, 4, RIGHT,
// 0, CH_ROCK0, 18, 4,
// 0, CH_ROCK0, 20, 4,
// LINE, CH_ROCK0, 23,4, 4, RIGHT,
// 0, CH_ROCK0, 6, 5,
// LINE, CH_ROCK0, 21,5, 4, RIGHT,
// LINE, CH_ROCK0, 14,6, 5, RIGHT,
// 0, CH_ROCK0, 21, 6,
// LINE, CH_ROCK0, 8,7, 3, RIGHT,
// LINE, CH_ROCK0, 16,7, 3, RIGHT,



//LINE, CH_DIRT, 0,0+SHIFT_EARTH,30, RIGHT,

0, CH_DIRT, 8, 0+SHIFT_EARTH,
LINE, CH_DIRT, 10,0+SHIFT_EARTH, 3, RIGHT,
LINE, CH_ROCK0, 22,0+SHIFT_EARTH, 4, RIGHT,

LINE, CH_ROCK0, 1,1+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 5, 1+SHIFT_EARTH,
LINE, CH_DIRT, 11,1+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 17, 1+SHIFT_EARTH,
LINE, CH_ROCK0, 21,1+SHIFT_EARTH, 9, RIGHT,
//todo vert strip 3 yellow

LINE, CH_ROCK0, 0,2+SHIFT_EARTH, 8, RIGHT,
0, CH_AMOEBA0, 3, 2+SHIFT_EARTH,
0, CH_DIRT, 8, 2+SHIFT_EARTH,
LINE, CH_ROCK0, 16,2+SHIFT_EARTH, 14, RIGHT,
0,CH_AMOEBA0, 28,2+SHIFT_EARTH,

0, CH_DIRT, 3, 3+SHIFT_EARTH,
LINE, CH_AMOEBA0, 4,3+SHIFT_EARTH, 2, DOWN,
LINE, CH_ROCK0, 5,3+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 17,3+SHIFT_EARTH, 9, RIGHT,
LINE, CH_AMOEBA0, 26, 1+SHIFT_EARTH, 3, DOWN,
0, CH_ROCK0, 28, 3+SHIFT_EARTH,

LINE, CH_AMOEBA0, 4,4+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 6,4+SHIFT_EARTH, 4, RIGHT,
LINE, CH_ROCK0, 15,4+SHIFT_EARTH, 12, RIGHT,
0, CH_AMOEBA0, 22, 4+SHIFT_EARTH,
0, CH_AMOEBA0, 24, 4+SHIFT_EARTH,
LINE, CH_AMOEBA0, 5,5+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 7,5+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 15, 5+SHIFT_EARTH,
0, CH_AMOEBA0, 17, 5+SHIFT_EARTH,
LINE, CH_ROCK0, 18,5+SHIFT_EARTH, 3, RIGHT,
LINE, CH_AMOEBA0, 21,5+SHIFT_EARTH, 4, RIGHT,
0, CH_ROCK0, 25,5+SHIFT_EARTH,
LINE, CH_AMOEBA0, 5,6+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 7,6+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 15, 6+SHIFT_EARTH,
0, CH_ROCK0, 18, 6+SHIFT_EARTH,
LINE, CH_AMOEBA0, 19,6+SHIFT_EARTH, 2, RIGHT,
LINE, CH_DIRT, 21,6+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 23, 6+SHIFT_EARTH,
0, CH_ROCK0, 24, 6+SHIFT_EARTH,
0, CH_AMOEBA0, 26, 6+SHIFT_EARTH,

0, CH_AMOEBA0, 6, 7+SHIFT_EARTH,
LINE, CH_ROCK0, 14,7+SHIFT_EARTH, 11, RIGHT,
0, CH_AMOEBA0, 15, 7+SHIFT_EARTH,
0, CH_AMOEBA0, 18, 7+SHIFT_EARTH,
0, CH_AMOEBA0, 19, 7+SHIFT_EARTH,
0, CH_AMOEBA0, 23, 7+SHIFT_EARTH,

0, CH_AMOEBA0, 7, 8+SHIFT_EARTH,
LINE, CH_ROCK0, 14,8+SHIFT_EARTH, 4, RIGHT,
0, CH_ROCK0, 21, 8+SHIFT_EARTH,
0, CH_ROCK0, 23, 8+SHIFT_EARTH,

0, CH_AMOEBA0, 9, 9+SHIFT_EARTH,
0, CH_ROCK0, 10, 9+SHIFT_EARTH,
LINE, CH_ROCK0, 16,9+SHIFT_EARTH, 3, RIGHT,
0, CH_AMOEBA0, 17, 9+SHIFT_EARTH,
LINE, CH_ROCK0, 23,9+SHIFT_EARTH, 2, RIGHT,


LINE, CH_ROCK0, 8,10+SHIFT_EARTH, 4, RIGHT,
LINE, CH_AMOEBA0, 16,10+SHIFT_EARTH, 2, RIGHT,

LINE, CH_ROCK0, 9,11+SHIFT_EARTH, 2, RIGHT,
0, CH_AMOEBA0, 11, 11+SHIFT_EARTH, 
LINE, CH_AMOEBA0, 16,11+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 25, 11+SHIFT_EARTH, 2, RIGHT,


LINE, CH_ROCK0, 9,12+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 16, 12+SHIFT_EARTH,
LINE, CH_ROCK0, 25,12+SHIFT_EARTH, 3, RIGHT,

0, CH_ROCK0, 25, 13+SHIFT_EARTH,






//LINE, CH_STEEL, 0, 0, 19, DOWN,


//0,CH_DOORCLOSED,0x03,0x04,     // entry

0xFF,

};

static const unsigned char planet1[]= {
#define PLANET1_DEPTH 20

0x01,       // cave

40,PLANET1_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_AMOEBA0,


CH_DIRT,CH_ROCK0,0,0,
180, 80, 0, 0,

// 0,0,0,0,
// 0,0,0,0,

// LINE, CH_AMOEBA0, 0,0, 30, RIGHT,
// LINE, CH_FLAT_1, 0,1, 30, RIGHT,
// LINE, CH_AMOEBA0, 0,2, 30, RIGHT,
// LINE, CH_FLAT_1, 0,3, 30, RIGHT,
// LINE, CH_AMOEBA0, 0,4, 30, RIGHT,
// LINE, CH_FLAT_1, 0,5, 30, RIGHT,

0, CH_CRATER_BIG, 0, 4,
0, CH_CRATER_BIG1, 1, 4,
0, CH_CRATER_BIG2, 0, 5,
0, CH_CRATER_BIG3, 1, 5,

LINE, CH_STEEL, 0, 0, 30, RIGHT,
LINE, CH_STEEL, 0, 1, 30, RIGHT,
LINE, CH_STEEL, 0, 19, 30, RIGHT,
LINE, CH_STEEL, 0, 18, 30, RIGHT,
//LINE, CH_STEEL, 0, 0, 16, DOWN,


LINE, CH_STEEL, 10,0,19, DOWNRIGHT,
LINE, CH_STEEL, 26,0,19, DOWNLEFT,



//0,CH_DOORCLOSED,0x03,0x04,     // entry

0xFF,

};



static const unsigned char moon0[]= {
#define MOON0_DEPTH 20

0x01,       // cave

40,MOON0_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_FLAT_1,


CH_CRATER_SMALL,CH_CRATER_TINY,CH_CRATER_BIG,CH_CRATER_MID,
30, 20, 10, 10,

0,CH_DOORCLOSED,0x03,0x04,     // entry

0xFF,

};



static const unsigned char uranus[]= {
#define URANUS_DEPTH 20

0x01,       // cave

40,URANUS_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_FLAT_1,


CH_EGG,0,0,0,
0,0,0,0,


LINE, CH_LATITUDE, 0, 0, 20, DOWN,
LINE, CH_LATITUDE, 5, 0, 20, DOWN,
LINE, CH_LATITUDE, 10, 0, 20, DOWN,
LINE, CH_LATITUDE, 15, 0, 20, DOWN,
LINE, CH_LATITUDE, 20, 0, 20, DOWN,
LINE, CH_LATITUDE, 25, 0, 20, DOWN,


// // LINE, CH_DOGE, 0,19,20,UPRIGHT,
// LINE, CH_DOGE, 10,19,20,UPRIGHT,

LINE, CH_FLAT_2, 0, 10, 30,RIGHT,

0, CH_CRATER_BIG, 7,7,
0, CH_CRATER_BIG1, 8,7,
0, CH_CRATER_BIG2, 7,8,
0, CH_CRATER_BIG3, 8,8,


BLOT(8,7)
BLOT(13,-2)

0xFF,

};


static const unsigned char mars[]= {
#define MARS_DEPTH 20

0x01,       // cave

40,MARS_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_FLAT_1,


CH_CRATER_SMALL,CH_CRATER_TINY,CH_CRATER_MID,CH_CRATER_BIG,
30, 20, 10, 20,

//0,CH_DOORCLOSED,0x03,0x04,     // entry


LINE, CH_DOGE, 0, 0, 20, DOWNRIGHT,
LINE, CH_DOGE, 1, 0, 20, DOWNRIGHT,
LINE, CH_DOGE, 2, 0, 19, DOWNRIGHT,

LINE, CH_EGG, 10, 6, 3, RIGHT,
LINE, CH_EGG, 10, 7, 3, RIGHT,
LINE, CH_EGG, 10, 8, 3, RIGHT,


LINE, CH_STEEL, 0,12, 7, UP,
LINE, CH_STEEL, 0,6,3, DOWNRIGHT,
LINE, CH_STEEL, 2,8, 3, UPRIGHT,
LINE, CH_STEEL, 4,6,7, DOWN,

LINE, CH_STEEL, 6, 7, 5, DOWN,
LINE, CH_STEEL, 9, 7, 5, DOWN,
LINE, CH_STEEL, 7, 6, 2, RIGHT,
LINE, CH_STEEL, 7, 12, 2, RIGHT,

LINE, CH_STEEL, 11, 7, 5, DOWN,
LINE, CH_STEEL, 14, 7, 5, DOWN,
LINE, CH_STEEL, 12, 6, 2, RIGHT,
LINE, CH_STEEL, 12, 12, 2, RIGHT,

LINE, CH_STEEL, 16, 6, 7, DOWN,
LINE, CH_STEEL, 19, 6, 7, DOWN,
LINE, CH_STEEL, 17, 8, 2, DOWN,
LINE, CH_STEEL, 18, 9, 2, DOWN,





0xFF,

};


const unsigned char moon0BGColours[MOON0_DEPTH] = {

    0xF0,
    0xF2,   // 01
    0xF4,   // 02
    0xF6,   // 03
    0xF8,   // 04
    0xF8,   // 05
    0xF6,   // 06
    0xF4,   // 07
    0xF2,   // 08
    0xF0,   // 09
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
};

const unsigned char marsBGColours[MARS_DEPTH] = {

    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
//    0xB6,   // 08
//    0xC6,   // 09
};
const unsigned char planet0BGColours[PLANET0_DEPTH] = {
    0x20,   // 00
    0x32,   // 01
    0x44,   // 02
    0x56,   // 03
    0x56,   // 04
    0x44,   // 05
    0x32,   // 06
    0x20,   // 07
    0x10,   // 00
    0x42,   // 01
    0x44,   // 02
    0x46,   // 03
    0x46,   // 04
    0x44,   // 05
    0x42,   // 06
    0x40,   // 07
    0x40,   // 00
    0x42,   // 01
    0x44,   // 02
    0x46,   // 03
    0x46,   // 04
    0x44,   // 05
    0x42,   // 06
    0x40,   // 07
};



const unsigned char planetEarthBGColours[PLANET0_DEPTH] = {
    0x90,   // 00
    0x92,   // 01
    0x94,   // 02
    0x96,   // 03
    0x96,   // 04
    0x94,   // 05
    0x92,   // 06
    0x90,   // 07
    0x92,   // 00
    0x92,   // 01
    0x94,   // 02
    0x96,   // 03
    0x96,   // 04
    0x94,   // 05
    0x92,   // 06
    0x90,   // 07
    0x90,   // 00
    0x92,   // 01
    0x94,   // 02
    0x96,   // 03
    0x96,   // 04
    0x94,   // 05
    0x92,   // 06
    0x90,   // 07
};


const unsigned char uranusColours[PLANET0_DEPTH] = {
    0xF0,   // 00
    0xF2,   // 01
    0xF4,   // 02
    0xF6,   // 03
    0xF6,   // 04
    0xF4,   // 05
    0xF2,   // 06
    0xF0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
};

const unsigned char planet1BGColours[PLANET1_DEPTH] = {
    0x68,   // 00
    0x88,   // 02
    0xA8,   // 04
    0xC8,   // 06
    0xE8,   // 07
    0xC8,   // 00
    0xA8,   // 02
    0x88,   // 04
    0x68,   // 06
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
    0x30,   // 00
    0x42,   // 01
    0x54,   // 02
    0x66,   // 03
    0x76,   // 04
    0x84,   // 05
    0x92,   // 06
    0xA0,   // 07
};

const unsigned char zphBGColours[PLANET1_DEPTH] = {
    0x20,   // 00
    0x22,   // 02
    0x24,   // 04
    0x28,   // 06
    0x28,   // 07
    0x24,   // 00
    0x22,   // 02
    0x20,   // 04
    0x20,   // 06
    0x24,   // 00
    0x24,   // 01
    0x24,   // 02
    0x24,   // 03
    0x24,   // 04
    0x24,   // 05
    0x24,   // 06
    0x24,   // 07
    0x24,   // 00
    0x24,   // 01
    0x24,   // 02
    0x24,   // 03
    0x24,   // 04
    0x24,   // 05
    0x24,   // 06
    0x24,   // 07
};

const unsigned char usaBGColours[PLANET1_DEPTH] = {
    0x80,   // 00
    0x82,   // 02
    0x84,   // 04
    0x88,   // 06
    0x88,   // 07
    0x84,   // 00
    0x82,   // 02
    0x80,   // 04
    0x80,   // 06
    0x84,   // 00
    0x84,   // 01
    0x84,   // 02
    0x84,   // 03
    0x84,   // 04
    0x84,   // 05
    0x84,   // 06
    0x84,   // 07
    0x84,   // 00
    0x84,   // 01
    0x84,   // 02
    0x84,   // 03
    0x84,   // 04
    0x84,   // 05
    0x84,   // 06
    0x84,   // 07
};


const unsigned char cave12bBGColours[CAVE12b_DEPTH] = {

    0x74,   // 00
    0x74,   // 01
    0x74,   // 02
    0x74,   // 03
    0x86,   // 04
    0x86,   // 05
    0x86,   // 06
    0x94,   // 07
    0x94,   // 08
    0x94,   // 09
    0xA4,   // 10
    0xA4,   // 11
    0xA4,   // 12
    0xB4,   // 13
    0xB4,   // 14
    0xB4,   // 15
    0xC4,   // 16
    0xC4,   // 17
    0xC4,   // 18
    0xD4,   // 19
    0xD4,   // 20
    0xD4,   // 21
};

const struct caveInfo caveList[] = {
    { cave12b,          { 0x86, 0x24, 0xC8, },  cave12bBGColours, },

    // { planetEarth2,          { 0x86, 0xC8, 0x28, },  planetEarthBGColours, },
    // { usa,          { 0x86, 0xD6, 0x46, },  usaBGColours, },
    // { zph,          { 0x86, 0xD6, 0x86, },  zphBGColours, },
    // { uranus,          { 0x86, 0x12, 0x16, },  uranusColours, },
    // { planetEarth,          { 0x86, 0xC8, 0x28, },  planetEarthBGColours, },
    // { planet1,            { 0x02, 0x26, 0x74, },  planet1BGColours, },
    // { mars,            { 0x3A, 0x74, 0xC8, },  marsBGColours, },
    // { moon0,            { 0x04, 0x06, 0x08, },  moon0BGColours, },
    // { planet0,          { 0x86, 0xD6, 0x86, },  planet0BGColours, },
};

const int caveCount = sizeof(caveList) / sizeof(caveList[0]);






