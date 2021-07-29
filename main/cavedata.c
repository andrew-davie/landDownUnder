
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
//#define DOWNRIGHT 3
#define DOWN 4
//#define DOWNLEFT 5
#define LEFT 6
//#define UPLEFT 7


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

CH_STEEL,CH_DIRT,


CH_DOGE,CH_BLANK,CH_ROCK0,CH_EGG,
0x68, 0x60,0x10,0x2,

//0x42,0x01,0x09+SHIFTY_1,0x1E,0x02,
//0x42,0x09,0x10+SHIFTY_1,0x1E,0x02,

0,CH_DOORCLOSED,0x03,0x04+SHIFTY_1,     // entry
0,CH_DOOROPEN_0,0x26,0x12+SHIFTY_1,     // exit

0,CH_EGG, 0x20, 0x10 + SHIFTY_1,

LINE,CH_ZZAP, 30,13+SHIFTY_1,6, DOWN,

LINE,CH_BRICKWALL, 20,10+SHIFTY_1,4, DOWN,
LINE,CH_BRICKWALL, 21,10+SHIFTY_1,4, DOWN,



// LINE+CH_ZZAP,30,13+SHIFTY_1,6,DOWN,
// LINE+0x32,30,3+SHIFTY_1,4,DOWN,

// LINE+0,5,10+SHIFTY_1,7,DOWN,
// LINE+0x32,5,10+SHIFTY_1,4,DOWN,


// LINE+0,30,17+SHIFTY_1,5,DOWN,
// LINE+0x32,30,17+SHIFTY_1,4,DOWN,



0xFF,

 };


UBYTE cave12[]= {

#define SHIFTY_12 -2


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

0,23,DEF_PARALLAX, //15,0x09,

CH_STEEL,CH_DIRT,


CH_DOGE,CH_BLANK,CH_ROCK0,CH_EGG,
0x68, 0x60,0x60,0x2,

//0x42,0x01,0x09+SHIFTY_1,0x1E,0x02,
//0x42,0x09,0x10+SHIFTY_1,0x1E,0x02,

0,CH_DOORCLOSED,0x03,0x04+SHIFTY_12,     // entry
0,CH_DOOROPEN_0,0x26,0x12+SHIFTY_12,     // exit

0,CH_EGG, 0x20, 0x10 + SHIFTY_12,

LINE, CH_BELT, 2, 20+SHIFTY_12, 15, RIGHT,
LINE, CH_BELT1, 2, 18+SHIFTY_12, 5, RIGHT,

LINE,CH_ZZAP, 20,2+SHIFTY_12,20, DOWN,
LINE,CH_ZZAP1, 21,2+SHIFTY_12,20, DOWN,

//LINE,CH_DRILL, 18,2+SHIFTY_1,20, DOWN,

0, CH_DRILLBODY, 10, 12,
0, CH_DRILLBODY1, 10, 11,



0xFF,

};


UBYTE cave12b[]= {

#define SHIFTY_12 -2


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

CH_STEEL,CH_DIRT,


CH_DIRT,CH_DOGE,CH_ROCK0,CH_EGG,
0xB0, 0x68, 0x60,0xA,

//0x42,0x01,0x09+SHIFTY_1,0x1E,0x02,
//0x42,0x09,0x10+SHIFTY_1,0x1E,0x02,

0,CH_DOORCLOSED,0x03,0x04+SHIFTY_12,     // entry
//0,CH_DOOROPEN_0,0x26,0x12+SHIFTY_12,     // exit

//0,CH_EGG, 0x20, 0x10 + SHIFTY_12,


// LINE+0,30,3+SHIFTY_1,6,DOWN,
// LINE+0x32,30,3+SHIFTY_1,4,DOWN,

// LINE+0,5,10+SHIFTY_1,7,DOWN,
// LINE+0x32,5,10+SHIFTY_1,4,DOWN,


// LINE+0,30,17+SHIFTY_1,5,DOWN,
// LINE+0x32,30,17+SHIFTY_1,4,DOWN,

LINE,CH_ZZAP, 20,2+SHIFTY_1,20, DOWN,
LINE,CH_ZZAP1, 21,2+SHIFTY_1,20, DOWN,

//LINE,CH_DRILL, 18,2+SHIFTY_1,20, DOWN,

// 0, CH_DRILLBODY, 10, 12,
// 0, CH_DRILLBODY1, 10, 11,

0, CH_DRILLBODY, 6, 10,
0, CH_DRILLBODY1, 6, 9,


0xFF,

};



const struct caveInfo caveList[] = {




//     // 1
//    { cave1,        {   { 0x24, 0x96, 0xC6,
//                0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x24, 0x24, 0x24, 0x24, 0x34,
//             0x34, 0x34, 0x34, 0x44, 0x44, 0x44, 0x54, 0x54, 0x54, 0x54, 0x94, 0x94
//             },
//     },
//     },

    // { cave12,       {   { 0x82, 0x26, 0xC6,

    //         0xE4, 0xE4,
    //         0xF4,0xF4,
    //         0x24,0x24,
    //         0x24,0x24,
    //         0x34, 0x34,0x34,
    //         0x44,0x44,
    //         0x44,0x54,
    //         0x54,0x54,
    //         0x66,0x66,
    //         0x66,0x66,
    //         0x26, 0x26
    //         },
    //             },
    // },

    { cave12b,       {   { 0x82, 0x26, 0xD6,
            0x74,0x74,
            0x74,0x74,0x86,0x86,0x86,0x94,0x94,0x94,0xA4,
            0xA4, 0xA4,
            0xB4,0xB4,
            0xB4,0xC4,
            0xC4, 0xC4,0xD4,
            0xD4,0xD4,
            0xD4,0xD4,

            },
                },
    },



};

const int caveCount = sizeof(caveList) / sizeof(caveList[0]);






