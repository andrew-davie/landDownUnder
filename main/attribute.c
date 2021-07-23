// Object attributes

    #include "attribute.h"
    #include "main.h"

const unsigned char CharToType[256]= {

    // see ChName for corresponding character name/number

TYPE_SPACE,                  // CH_BLANK,                   // 0
TYPE_DIRT,                   // CH_DIRTY,                   // 1
TYPE_BRICKWALL,              // CH_BRICKWALL,               // 2
TYPE_MAGICWALL,              // CH_MAGICWALL,               // 3       // magic wall
TYPE_OUTBOX_PRE,             // CH_STEELWALL,               // 4        exit door closed
TYPE_OUTBOX,                 // CH_DOOROPEN_0,              // 5        exit door (open)
TYPE_OUTBOX,                 // CH_DOOROPEN_1               // 6        exit door (open)
TYPE_STEELWALL,              // CH_STEELWALL_0,             // 7
TYPE_FIREFLY,                // CH_FIREFLY_0,               // 8
TYPE_FIREFLY,                // CH_FIREFLY_1,               // 9
TYPE_FIREFLY,                // CH_FIREFLY_2,               // 10
TYPE_FIREFLY,                // CH_FIREFLY_3,               // 11
TYPE_DIRT3,                  // CH_DIRTY3,                  // 12
TYPE_DIRT2,                  // CH_DIRTY2,                  // 13 poss error/overload on firefly 4-7
#if ENABLE_EGG
TYPE_EGG,                                                   // 14
#else
TYPE___NOTHING,
#endif
TYPE_FIREFLY,                // CH_FIREFLY_7,               // 15
TYPE_BOULDER,                // CH_BOULDER,                 // 16
TYPE___THISFRAME,            // CH_BOULDER_FALLING_THIS,    // 17
TYPE_BOULDER_FALLING,        // CH_BOULDER_FALLING,         // 18
TYPE___THISFRAME,            // CH_BOULDER_THIS,            // 19
TYPE_DIAMOND,                // CH_DIAMOND,                 // 20
TYPE___THISFRAME,            // CH_DIAMOND_FALLING_THIS,    // 21
TYPE_DIAMOND,                // CH_DIAMOND_FALLING,         // 22
TYPE___THISFRAME,            // CH_DIAMOND_THIS,            // 23
TYPE_FIREFLY,                // CH_DIAMOND_4,               // 24
TYPE_FIREFLY,                // CH_FIREFLY2,                // 25
TYPE___NOTHING,              // CH_FIREFLY3,                // 26
TYPE_BUTTERFLY,              // CH_BUTTERFLY2U,             // 27
TYPE_BUTTERFLY,              // CH_BUTTERFLY3U,             // 28
TYPE___NOTHING,              // CH_BLANK_ALTERNATE_3,       // 29
TYPE___NOTHING,                // CH_UNCOVER0,                // 30
TYPE___NOTHING,                // CH_UNCOVER1,                // 31
TYPE_EXPLODE_DIAMOND_0,      // CH_EXPLODETODIAMOND0,       // 32
TYPE_EXPLODE_DIAMOND_1,      // CH_EXPLODETODIAMOND1,       // 33
TYPE_EXPLODE_DIAMOND_2,      // CH_EXPLODETODIAMOND2,       // 34
TYPE_EXPLODE_DIAMOND_3,      // CH_EXPLODETODIAMOND3,       // 35
TYPE_EXPLODE_DIAMOND_4,      // CH_EXPLODETODIAMOND4,       // 36
TYPE_ROCKFORD_PRE,           // CH_ROCKYa,                  // 37
TYPE_ROCKFORD_PRE,           // CH_ROCKYb,                  // 38
TYPE_ROCKFORD_PRE,           // CH_ROCKYc,                  // 39
TYPE_ROCKFORD_PRE,           // CH_ROCKYd,                  // 40
TYPE_BOULDER,                // CH_BOULDER2,                // 41
TYPE_BOULDER,                // CH_BOULDER3,                // 42
TYPE_BOULDER,                // CH_BOULDER4,                // 43
TYPE___NOTHING,                // CH_MAGIC1,                  // 44
TYPE___NOTHING,              // CH_MAGIC2,                  // 45
TYPE___NOTHING,              // CH_MAGIC3,                  // 46
TYPE_DIAMOND_PULSE_0,        // CH_DIAMONDx1U,              // 47 pulse diamond
TYPE_BUTTERFLY,              // CH_BUTTERFLY0,              // 48
TYPE_BUTTERFLY,              // CH_BUTTERFLY1,              // 49
TYPE_BUTTERFLY,              // CH_BUTTERFLY2,              // 50
TYPE_BUTTERFLY,              // CH_BUTTERFLY3,              // 51
TYPE_BUTTERFLY,              // CH_BUTTERFLY_4,             // 52
TYPE_BUTTERFLY,              // CH_BUTTERFLY_5,             // 53
TYPE_BUTTERFLY,              // CH_BUTTERFLY_6,             // 54
TYPE_BUTTERFLY,              // CH_BUTTERFLY_7,             // 55
TYPE___NOTHING,                                             // 56
TYPE___NOTHING,                                             // 57
TYPE_AMOEBA,                 // CH_AMOEBA0,                 // 58
TYPE_AMOEBA,                 // CH_AMOEBA1,                 // 59
TYPE_AMOEBA,                 // CH_AMOEBA2,                 // 60
TYPE_AMOEBA,                 // CH_AMOEBA3,                 // 61
TYPE___NOTHING,                   //                // 62 
TYPE___NOTHING,         // CH_STEELWALL_1,             // 63
TYPE___NOTHING,         // CH_UNCOVER0b,               // 64
TYPE___NOTHING,         // CH_UNCOVER1b,               // 65
TYPE___NOTHING,         // CH_UNCOVER2b,               // 66
TYPE___NOTHING,         // CH_UNCOVER3b,               // 67
TYPE___NOTHING,         // CH_UNCOVER4b,               // 68
TYPE___NOTHING,         // CH_UNCOVER5b,               // 69
TYPE_DIAMOND_PULSE_0,        // CH_DIAMOND_PULSE_0,         // 70
TYPE_DIAMOND_PULSE_1,        // CH_DIAMOND_PULSE_1,         // 71
TYPE_DIAMOND_PULSE_2,        // CH_DIAMOND_PULSE_2,         // 72
TYPE_DIAMOND_PULSE_3,        // CH_DIAMOND_PULSE_3,         // 73
TYPE_DIAMOND_PULSE_4,        // CH_DIAMOND_PULSE_4,         // 74
TYPE_DIAMOND_PULSE_5,        // CH_DIAMOND_PULSE_5,         // 75
TYPE_DIAMOND_PULSE_6,        // CH_DIAMOND_PULSE_6,         // 76
TYPE_DIAMOND_PULSE_7,        // CH_DIAMOND_PULSE_7,         // 77
TYPE_DIAMOND_PULSE_8,        // CH_DIAMOND_PULSE_8,         // 78
TYPE_DIAMOND_PULSE_9,       // CH_DIAMOND_PULSE_9,         // 79
TYPE_DIAMOND,                // CH_DIAMOND_STATIC,          // 80  (CAN SWITCH ANIMATIONS ON THIS!)
TYPE_AMOEBA,                 // CH_AMOEBA_BLANK             // 81 ???
TYPE_EXPLODE_THIS,           // CH_EXPLODE_THIS             // 82   NEXT FRAME EXPLODING OBJECT
TYPE_SPACE,                  // CH_BLANK_EXTRA1             // 83
TYPE_SPACE,                  // CH_BLANK_EXTRA2             // 84
TYPE_SPACE,                  // CH_BLANK_EXTRA3             // 85
TYPE_SPACE,                  // CH_BLANK_EXTRA4             // 86
TYPE_SPACE,                  // CH_BLANK_EXTRA5             // 87
TYPE_SPACE,                  // CH_BLANK_EXTRA6             // 88
TYPE_SPACE,                  // CH_BLANK_EXTRA7             // 89
TYPE_SPACE,                  // CH_BLANK_EXTRA8             // 90

TYPE___NOTHING,              // CH_UNKOWN23                 // 91

TYPE_EXPLODE_BLANK_0,        // CH_EXPLODETOBLANK0,         // 92
TYPE_EXPLODE_BLANK_1,        // CH_EXPLODETOBLANK1,         // 93
TYPE_EXPLODE_BLANK_2,        // CH_EXPLODETOBLANK2,         // 94
TYPE_EXPLODE_BLANK_3,        // CH_EXPLODETOBLANK3,         // 95
TYPE_EXPLODE_BLANK_4,        // CH_EXPLODETOBLANK4,         // 96

TYPE_DIAMOND_GRAB,           // CH_DIAMOND_GRAB,            // 97
TYPE_DIRT_GRAB,              // CH_DIRT_GRAB,               // 98

TYPE_DUST,                   // CH_DUST,                    // 99
TYPE_DUST2,                  // CH_DUST2,                   // 100
TYPE_DUST3,                  // CH_DUST3,                   // 101

TYPE_BOULDER_SHAKE,          // CH_BOULDER_SHAKE            // 102

TYPE_DUST_LEFT,              // CH_DUST_LEFT                // 103
TYPE_DUST2_LEFT,             // CH_DUST2_LEFT               // 104
TYPE_DUST3_LEFT,             // CH_DUST2_LEFT               // 105

TYPE_DUST_RIGHT,             // CH_DUST_RIGHT               // 106
TYPE_DUST2_RIGHT,            // CH_DUST2_RIGHT              // 107
TYPE_DUST3_RIGHT,            // CH_DUST3_RIGHT              // 108

TYPE_LAVA,                   // CH_LAVA                     // 109
TYPE_LAVA,                   // CH_LAVA                     // 110
TYPE_LAVA,                   // CH_LAVA                     // 111
TYPE_LAVA,                   // CH_LAVA                     // 112

TYPE_WATER,                  // CH_WATER                    // 113
TYPE_WATER,                  // CH_WATER1                   // 114
TYPE_WATER,                  // CH_WATER2                   // 115
TYPE_WATER,                  // CH_WATER3                   // 116

#if ENABLE_EGG
TYPE_EGG,                    // CH_EGG2                     // 117
#else
TYPE___NOTHING,
#endif

TYPE_ROCKFORD,               // 118     CH_ROCKFORD
TYPE_ROCKFORD,               // 119     CH_ROCKFORD_THIS

TYPE_DRIP,                   // 120     CH_DRIP
TYPE_DRIP,                   // 121     CH_DRIP1
TYPE_DRIP,                   // 122     CH_DRIP2
TYPE_DRIP,                   // 123     CH_DRIP3
TYPE_DRIP_SPLASH,            // 124     CH_DRIPX

TYPE_DIRT,                   // 125     CH_DIRT
TYPE_DIRT,                   // 126     CH_DIRT1
TYPE_DIRT,                   // 127     CH_DIRT2
TYPE_DIRT,                   // 128     CH_DIRT3
TYPE_DIRT,                   // 129     CH_DIRT4
TYPE_DIRT,                   // 130     CH_DIRT5
TYPE_DIRT,                   // 131     CH_DIRT6
TYPE_DIRT,                   // 132     CH_DIRT7
TYPE_DIRT,                   // 133     CH_DIRT8
TYPE_DIRT,                   // 134     CH_DIRT9
TYPE_DIRT,                   // 135     CH_DIRTA
TYPE_DIRT,                   // 136     CH_DIRTB
TYPE_DIRT,                   // 137     CH_DIRTC
TYPE_DIRT,                   // 138     CH_DIRTD
TYPE_DIRT,                   // 139     CH_DIRTE
TYPE_DIRT,                   // 140     CH_DIRTF


// 141...

TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,

TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,
TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME, TYPE___THISFRAME,


};


const int Attribute[] = {

// index via ObjectType value

#define _ 0

#define RKF ATT_ROCKFORDYBLANK
#define PSH ATT_PUSH
#define SSP ATT_SEMIBLANK
#define WTR ATT_WATER
#define LAV ATT_LAVA
#define QUI ATT_NOROCKNOISE
#define XIT ATT_EXIT
#define HRD ATT_HARD
#define SQB ATT_SQUASHABLE_TO_BLANKS
#define ACT ATT_ACTIVE
#define BNG ATT_EXPLODES
#define GRB ATT_GRAB
#define SQD ATT_SQUASHABLE_TO_DIAMONDS
#define SPC ATT_BLANK
#define PER ATT_PERMEABLE
#define XPD ATT_EXPLODABLE
#define FLY ATT_KILLS_FLY
#define ROL ATT_ROLL
#define DRP ATT_DRIP
#define RND ATT_ROUNDDIRT

//                                         e           k
//                                        s           n               m           e
//           t       y       k           i           a               a       e   l
//          r       d       n           o           l       s       i       l   b   y
//         i       r       a           n           B       e       D       b   a   l
//        D       o       l           k           h   e   d       h       a   d   F
//       d       f       b   r       c           s   v   o       s   k   e   o   s
//      n   p   k   h   i   e   a   o   t   d   a   i   l   b   a   n   m   l   l   1
//     u   i   c   s   m   t   v   R   i   r   u   t   p   a   u   a   r   p   l   l
//    o   r   o   u   e   a   a   o   x   a   q   c   x   r   q   l   e   x   i   o
//   R   D   R   P   S   W   L   N   E   H   S   A   E   G   S   B   P   E   K   R
//   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
//  RND DRP RKF PSH SSP WTR LAV QUI XIT HRD SQB ACT BNG GRB SQD SPC PER XPD FLY ROL

    RND| _ |RKF| _ | _ |WTR|LAV|QUI| _ | _ | _ | _ | _ | _ | _ |SPC|PER|XPD| _ | _  , // 0  SPACE
     _ |DRP| _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 1  DIRT
     _ |DRP| _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ | _ | _ | _ | _ | _ |XPD| _ |ROL , // 2  BRICK WALL
     _ |DRP| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |XPD| _ | _  , // 3  MAGIC WALL
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 4  OUTBOX PRE
     _ | _ | _ | _ | _ | _ | _ | _ |XIT| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 5  OUTBOX
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 6  BOULDER FALL
     _ |DRP| _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 7  STEEL WALL
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ |SQB|ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 8  FIREFLY
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 9  BOULDER
    RND| _ | _ | _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 10 DIAMOND
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 11 EXPLODE SPACE 0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 12 EXPLODE SPACE 1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 13 EXPLODE SPACE 2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 14 EXPLODE SPACE 3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 15 EXPLODE SPACE 4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 16 EXPLODE DIAMOND 0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 17 EXPLODE DIAMOND 1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 18 EXPLODE DIAMOND 2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 19 EXPLODE DIAMOND 3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 20 EXPLODE DIAMOND 4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 21 ROCKFORD PRE 
    RND| _ | _ | _ |WTR| _ |LAV| _ | _ | _ | _ |ACT| _ | _ |SQD| _ | _ |XPD| _ | _  , // 22 BUTERFLY
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ |SQB|ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 23 ROCKFORD
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 24 AMOEBA
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 25 DRIP
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 26 DRIP SPLASH
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 27 DIAMOND PULSE 0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 28 DIAMOND PULSE 1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 29 DIAMOND PULSE 2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 30 DIAMOND PULSE 3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 31 DIAMOND PULSE 4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 32 DIAMOND PULSE 5
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 33 DIAMOND PULSE 6
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 34 DIAMOND PULSE 7
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 35 DIAMOND PULSE 8
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 36 DIAMOND PULSE 9
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ |ROL , // 37 DIAMOND PULSE 10
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 38 UNUSED (LIFE)
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 39 "THIS FRAME" CREATURES
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 40 __EXPLODE_THIS ??
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 41 THIS FRAME "BLANK" ??
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 42 DIRT 3
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 43 DIRT 2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 44 EXPLODE BLANK 0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 45 EXPLODE BLANK 1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 46 EXPLODE BLANK 2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 47 EXPLODE BLANK 3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 48 EXPLODE BLANK 4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC| _ |XPD| _ | _  , // 49 DIAMOND GRABBED
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 50 DIRT GRABBED
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 51 DUST
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 52 DUST 2
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 53 DUST 3
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 54 BOULDER SHAKE
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 55 DUST
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 56 DUST
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 57 DUST
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 58 DUST
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 59 DUST
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 60 DUST
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 61 LAVA
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 61 WATER (*)
#if ENABLE_EGG
    RND| _ | _ | _ |SSP| _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ |PER| _ | _ | _  , // 63 EGG
#endif

//  RND|DRP RKF PSH SSP WTR LAV QUI XIT HRD SQB ACT BNG GRB SQD SPC PER XPD FLY ROL
//   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
//   R   D   R   P   S   W   L   N   E   H   S   A   E   G   S   B   P   E   K   R
//    o   r   o   u   e   a   a   o   x   a   q   c   x   r   q   l   e   x   i   o
//     u   i   c   s   m   t   v   R   i   r   u   t   p   a   u   a   r   p   l   l
//      n   p   k   h   i   e   a   o   t   d   a   i   l   b   a   n   m   l   l   1
//       d       f       b   r       c           s   v   o       s   k   e   o   s
//        D       o       l           k           h   e   d       h       a   d   F
//         i       r       a           n           B       e       D       b   a   l
//          r       d       n           o           l       s       i       l   b   y
//           t       y       k           i           a               a       e   l
//                                        s           n               m           e
//                                         e           k

};

