
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

//#define UP 0
//#define UPRIGHT 1
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

0,CH_AMOEBA0,


CH_ROCK0,CH_DIRT,0,0,
130, 40, 0, 0,

LINE, CH_STEEL, 0,0, 40, RIGHT,
LINE, CH_STEEL, 0,PLANET0_DEPTH-1, 40, RIGHT,


0,CH_DOORCLOSED,0x03,0x04,     // entry

0xFF,

};


static const unsigned char planetEarth[]= {
#define PLANETEARTH_DEPTH 20
#define SHIFT_EARTH 2

0x01,       // cave

40,PLANETEARTH_DEPTH,0,      // size, gravity

0x14,       // milling
0x0A,0x0F,  // diamond $

0x0A,0x0B,0x0C,0x0D,0x0E,       // randomiser[level]
0x0C,0x0C,0x0C,0x0C,0x0C,
0x96,0x6E,0x46,0x28,0x1E,

0,0,DEF_PLANET, //15,0x09,

0,CH_FLAT_2,


0,0,0,0,
0,0,0, 0,

LINE, CH_LATITUDE, 0, 0, 19, DOWN,
//LINE, CH_LATITUDE, 2, 0, 19, DOWN,
LINE, CH_LATITUDE, 5, 0, 19, DOWN,
//LINE, CH_LATITUDE, 6, 0, 19, DOWN,
LINE, CH_LATITUDE, 10, 0, 19, DOWN,
//LINE, CH_LATITUDE, 10, 0, 19, DOWN,
LINE, CH_LATITUDE, 15, 0, 19, DOWN,
//LINE, CH_LATITUDE, 14, 0, 19, DOWN,
LINE, CH_LATITUDE, 20, 0, 19, DOWN,
//LINE, CH_LATITUDE, 18, 0, 19, DOWN,
LINE, CH_LATITUDE, 25, 0, 19, DOWN,
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


LINE, CH_STEEL, 0,0+SHIFT_EARTH,30, RIGHT,

0, CH_STEEL, 8, 0+SHIFT_EARTH,
LINE, CH_STEEL, 10,0+SHIFT_EARTH, 3, RIGHT,
LINE, CH_ROCK0, 22,0+SHIFT_EARTH, 4, RIGHT,

LINE, CH_ROCK0, 1,1+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 5, 1+SHIFT_EARTH,
LINE, CH_STEEL, 11,1+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 17, 1+SHIFT_EARTH,
LINE, CH_ROCK0, 21,1+SHIFT_EARTH, 9, RIGHT,
//todo vert strip 3 yellow

LINE, CH_ROCK0, 0,2+SHIFT_EARTH, 8, RIGHT,
0, CH_DIRT, 3, 2+SHIFT_EARTH,
0, CH_STEEL, 8, 2+SHIFT_EARTH,
LINE, CH_ROCK0, 16,2+SHIFT_EARTH, 14, RIGHT,
0,CH_DIRT, 28,2+SHIFT_EARTH,

0, CH_STEEL, 3, 3+SHIFT_EARTH,
LINE, CH_DIRT, 4,3+SHIFT_EARTH, 2, DOWN,
LINE, CH_ROCK0, 5,3+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 17,3+SHIFT_EARTH, 9, RIGHT,
LINE, CH_DIRT, 26, 1+SHIFT_EARTH, 3, DOWN,
0, CH_ROCK0, 28, 3+SHIFT_EARTH,

LINE, CH_DIRT, 4,4+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 6,4+SHIFT_EARTH, 4, RIGHT,
LINE, CH_ROCK0, 15,4+SHIFT_EARTH, 12, RIGHT,
0, CH_DIRT, 22, 4+SHIFT_EARTH,
0, CH_DIRT, 24, 4+SHIFT_EARTH,
LINE, CH_DIRT, 5,5+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 7,5+SHIFT_EARTH, 2, RIGHT,
0, CH_DIRT, 15, 5+SHIFT_EARTH,
0, CH_DIRT, 17, 5+SHIFT_EARTH,
LINE, CH_ROCK0, 18,5+SHIFT_EARTH, 3, RIGHT,
LINE, CH_DIRT, 21,5+SHIFT_EARTH, 4, RIGHT,
0, CH_ROCK0, 25,5+SHIFT_EARTH,
LINE, CH_DIRT, 5,6+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 7,6+SHIFT_EARTH, 2, RIGHT,
0, CH_DIRT, 15, 6+SHIFT_EARTH,
0, CH_ROCK0, 18, 6+SHIFT_EARTH,
LINE, CH_DIRT, 19,6+SHIFT_EARTH, 2, RIGHT,
LINE, CH_STEEL, 21,6+SHIFT_EARTH, 2, RIGHT,
0, CH_DIRT, 23, 6+SHIFT_EARTH,
0, CH_ROCK0, 24, 6+SHIFT_EARTH,
0, CH_DIRT, 26, 6+SHIFT_EARTH,

0, CH_DIRT, 6, 7+SHIFT_EARTH,
LINE, CH_ROCK0, 14,7+SHIFT_EARTH, 11, RIGHT,
0, CH_DIRT, 15, 7+SHIFT_EARTH,
0, CH_DIRT, 18, 7+SHIFT_EARTH,
0, CH_FLAT_2, 19, 7+SHIFT_EARTH,
0, CH_DIRT, 23, 7+SHIFT_EARTH,

0, CH_DIRT, 7, 8+SHIFT_EARTH,
LINE, CH_ROCK0, 14,8+SHIFT_EARTH, 4, RIGHT,
0, CH_ROCK0, 21, 8+SHIFT_EARTH,
0, CH_ROCK0, 23, 8+SHIFT_EARTH,

0, CH_DIRT, 9, 9+SHIFT_EARTH,
0, CH_ROCK0, 10, 9+SHIFT_EARTH,
LINE, CH_ROCK0, 16,9+SHIFT_EARTH, 3, RIGHT,
0, CH_DIRT, 17, 9+SHIFT_EARTH,
LINE, CH_ROCK0, 23,9+SHIFT_EARTH, 2, RIGHT,


LINE, CH_ROCK0, 8,10+SHIFT_EARTH, 4, RIGHT,
LINE, CH_DIRT, 16,10+SHIFT_EARTH, 2, RIGHT,

LINE, CH_ROCK0, 9,11+SHIFT_EARTH, 2, RIGHT,
0, CH_DIRT, 11, 11+SHIFT_EARTH, 
LINE, CH_DIRT, 16,11+SHIFT_EARTH, 2, RIGHT,
LINE, CH_ROCK0, 25, 11+SHIFT_EARTH, 2, RIGHT,


LINE, CH_ROCK0, 9,12+SHIFT_EARTH, 2, RIGHT,
0, CH_ROCK0, 16, 12+SHIFT_EARTH,
LINE, CH_ROCK0, 25,12+SHIFT_EARTH, 3, RIGHT,

0, CH_ROCK0, 25, 13+SHIFT_EARTH,


LINE, CH_STEEL, 0,0,30, RIGHT,

LINE, CH_STEEL, 0,18,30, RIGHT,
LINE, CH_STEEL, 0,17,3, RIGHT,


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

0,CH_FLAT_2,


CH_DIRT,CH_ROCK0,0,0,
180, 80, 0, 0,

// 0,0,0,0,
// 0,0,0,0,

// LINE, CH_FLAT_2, 0,0, 30, RIGHT,
// LINE, CH_FLAT_1, 0,1, 30, RIGHT,
// LINE, CH_FLAT_2, 0,2, 30, RIGHT,
// LINE, CH_FLAT_1, 0,3, 30, RIGHT,
// LINE, CH_FLAT_2, 0,4, 30, RIGHT,
// LINE, CH_FLAT_1, 0,5, 30, RIGHT,

0, CH_CRATER_BIG, 0, 4,
0, CH_CRATER_BIG1, 1, 4,
0, CH_CRATER_BIG2, 0, 5,
0, CH_CRATER_BIG3, 1, 5,

LINE, CH_STEEL, 0, 0, 30, RIGHT,
LINE, CH_STEEL, 0, 15, 30, RIGHT,
//LINE, CH_STEEL, 0, 0, 16, DOWN,


LINE, CH_STEEL, 10,0,16, DOWNRIGHT,
LINE, CH_STEEL, 26,0,16, DOWNLEFT,

0,CH_DOORCLOSED,0x03,0x04,     // entry

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


CH_CRATER_SMALL,CH_CRATER_TINY,CH_CRATER_MID,0,
30, 20, 10, 0,

0,CH_DOORCLOSED,0x03,0x04,     // entry

0xFF,

};


const unsigned char moon0BGColours[MOON0_DEPTH] = {

    0x04,   // 00
    0x04,   // 01
    0x04,   // 02
    0x04,   // 03
    0x04,   // 04
    0x04,   // 05
    0x04,   // 06
    0x04,   // 07
    0x04,   // 08
    0x04,   // 09
};

const unsigned char marsBGColours[MARS_DEPTH] = {

    0x36,   // 00
    0x36,   // 01
    0x36,   // 02
    0x36,   // 03
    0x36,   // 04
    0x36,   // 05
    0x36,   // 06
    0x36,   // 07
    0x36,   // 08
    0x36,   // 09
};
const unsigned char planet0BGColours[PLANET0_DEPTH] = {
    0x24,   // 00
    0x24,   // 01
    0x24,   // 02
    0x24,   // 03
    0x24,   // 04
    0x24,   // 05
    0x24,   // 06
    0x24,   // 07
};

const unsigned char planetEarthBGColours[PLANET0_DEPTH] = {
    0x24,   // 00
    0x24,   // 01
    0x24,   // 02
    0x24,   // 03
    0x24,   // 04
    0x24,   // 05
    0x24,   // 06
    0x24,   // 07
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
    { planetEarth,          { 0x86, 0xD6, 0x94, },  planetEarthBGColours, },
    { planet1,            { 0x02, 0x26, 0x74, },  planet1BGColours, },
    { mars,            { 0x3A, 0x24, 0x42, },  marsBGColours, },
    { moon0,            { 0x04, 0x06, 0x08, },  moon0BGColours, },
    { planet0,          { 0x86, 0xD6, 0x86, },  planet0BGColours, },
//    { cave12b,          { 0x86, 0x24, 0xC8, },  cave12bBGColours, },
};

const int caveCount = sizeof(caveList) / sizeof(caveList[0]);






