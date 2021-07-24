// Object attributes

    #include "attribute.h"
    #include "main.h"

const unsigned char CharToType[CH_MAX]= {

    // see ChName for corresponding character name/number

TYPE_SPACE,                  // 000 CH_BLANK  
TYPE_DIRT,                   // 001 CH_DIRTY  
TYPE_BRICKWALL,              // 002 CH_BRICKWALL  
TYPE_OUTBOX_PRE,             // 003 CH_DOORCLOSED  
TYPE_OUTBOX,                 // 004 CH_DOOROPEN_0  
TYPE_OUTBOX,                 // 005 CH_DOOROPEN_1  
TYPE_STEEL,                  // 006 CH_STEEL  
TYPE_DIRT3,                  // 007 CH_DIRTY3  
TYPE_DIRT2,                  // 008 CH_DIRTY2  
TYPE_EGG,                    // 009 CH_EGG 
TYPE_BOULDER,                // 010 CH_BOULDER 
TYPE_ZZAP1,                  // 011 CH_ZZAP1 
TYPE_BOULDER_FALLING,        // 012 CH_BOULDER_FALLING 
TYPE_ROCK,                   // 013 CH_ROCKSEED 
TYPE_DOGE,                   // 014 CH_DOGE 
TYPE_DOGE,                   // 015 CH_DOGE_FALLING 
TYPE_DOGE,                   // 016 CH_DOGE_4 
TYPE___NOTHING,              // 017 CH_BLANK_ALTERNATE_3 
TYPE___NOTHING,              // 018 CH_____0 
TYPE___NOTHING,              // 019 CH_____1 
TYPE_EXPLODE_DOGE_0,         // 020 CH_EXPLODETODOGE0 
TYPE_EXPLODE_DOGE_1,         // 021 CH_EXPLODETODOGE1 
TYPE_EXPLODE_DOGE_2,         // 022 CH_EXPLODETODOGE2 
TYPE_EXPLODE_DOGE_3,         // 023 CH_EXPLODETODOGE3 
TYPE_EXPLODE_DOGE_4,         // 024 CH_EXPLODETODOGE4 
TYPE_ROCKFORD_PRE,           // 025 CH_ROCKYa 
TYPE_ROCKFORD_PRE,           // 026 CH_ROCKYb 
TYPE_ROCKFORD_PRE,           // 027 CH_ROCKYc 
TYPE_ROCKFORD_PRE,           // 028 CH_ROCKYd 
TYPE_BOULDER,                // 029 CH_BOULDER2 
TYPE_BOULDER,                // 030 CH_BOULDER3 
TYPE_BOULDER,                // 031 CH_BOULDER4 
TYPE_DOGE,                   // 032 CH_DOGEx1U 
TYPE___NOTHING,              // 033 CH_xxROCKFORD 
TYPE___NOTHING,              // 034 CH_xxROCKFORD_THIS 
TYPE_AMOEBA,                 // 035 CH_AMOEBA0 
TYPE_AMOEBA,                 // 036 CH_AMOEBA1 
TYPE_AMOEBA,                 // 037 CH_AMOEBA2 
TYPE_AMOEBA,                 // 038 CH_AMOEBA3 
TYPE_ZZAP,                   // 039 CH_ZZAP 
TYPE___NOTHING,              // 040 CH_STEELWALL_1  ??
TYPE_DOGE,                   // 041 CH_DOGE_PULSE_0 
TYPE_DOGE,                   // 042 CH_DOGE_PULSE_1 
TYPE_DOGE,                   // 043 CH_DOGE_PULSE_2 
TYPE_DOGE,                   // 044 CH_DOGE_PULSE_3 
TYPE_DOGE,                   // 045 CH_DOGE_PULSE_4 
TYPE_DOGE,                   // 046 CH_DOGE_PULSE_5 
TYPE_DOGE,                   // 047 CH_DOGE_PULSE_6 
TYPE_DOGE,                   // 048 CH_DOGE_PULSE_7 
TYPE_DOGE,                   // 049 CH_DOGE_PULSE_8 
TYPE_DOGE,                   // 050 CH_DOGE_PULSE_9 
TYPE_DOGE,                   // 051 CH_DOGE_STATIC 
TYPE_AMOEBA,                 // 052 CH_AMOEBA_BLANK 
TYPE_EXPLODE_THIS,           // 053 CH_EXPLODE_THIS 
TYPE_SPACE,                  // 054 CH_BLANK_EXTRA1 
TYPE_SPACE,                  // 055 CH_BLANK_EXTRA2 
TYPE_SPACE,                  // 056 CH_BLANK_EXTRA3 
TYPE_SPACE,                  // 057 CH_BLANK_EXTRA4 
TYPE_SPACE,                  // 058 CH_BLANK_EXTRA5 
TYPE_SPACE,                  // 059 CH_BLANK_EXTRA6 
TYPE_SPACE,                  // 060 CH_BLANK_EXTRA7 
TYPE_SPACE,                  // 061 CH_BLANK_EXTRA8 
TYPE___NOTHING,              // 062 CH_UNKNOWN23 
TYPE_EXPLODE_BLANK_0,        // 063 CH_EXPLODETOBLANK0 
TYPE_EXPLODE_BLANK_1,        // 064 CH_EXPLODETOBLANK1 
TYPE_EXPLODE_BLANK_2,        // 065 CH_EXPLODETOBLANK2 
TYPE_EXPLODE_BLANK_3,        // 066 CH_EXPLODETOBLANK3 
TYPE_EXPLODE_BLANK_4,        // 067 CH_EXPLODETOBLANK4 
TYPE_DOGE_GRAB,              // 068 CH_DOGE_GRAB 
TYPE_DIRT_GRAB,              // 069 CH_DIRT_GRAB 
TYPE_DUST,                   // 070 CH_DUST 
TYPE_DUST2,                  // 071 CH_DUST2 
TYPE_DUST3,                  // 072 CH_DUST3 
TYPE_BOULDER_SHAKE,          // 073 CH_BOULDER_SHAKE 
TYPE_DUST_LEFT,              // 074 CH_DUST_LEFT 
TYPE_DUST2_LEFT,             // 075 CH_DUST2_LEFT 
TYPE_DUST3_LEFT,             // 076 CH_DUST3_LEFT 
TYPE_DUST_RIGHT,             // 077 CH_DUST_RIGHT 
TYPE_DUST2_RIGHT,            // 078 CH_DUST2_RIGHT 
TYPE_DUST3_RIGHT,            // 079 CH_DUST3_RIGHT 
TYPE_LAVA,                   // 080 CH_LAVA 
TYPE_LAVA,                   // 081 CH_LAVA1 
TYPE_LAVA,                   // 082 CH_LAVA2 
TYPE_LAVA,                   // 083 CH_LAVA3 
TYPE_WATER,                  // 084 CH_WATER 
TYPE_WATER,                  // 085 CH_WATER1 
TYPE_WATER,                  // 086 CH_WATER2 
TYPE_WATER,                  // 087 CH_WATER3 
TYPE_EGG,                    // 088 CH_EGG2 
TYPE_ROCKFORD,               // 089 CH_ROCKFORD 
TYPE_ROCKFORD,               // 090 CH_ROCKFORD_THIS 
TYPE_DRIP,                   // 091 CH_DRIP 
TYPE_DRIP,                   // 092 CH_DRIP1 
TYPE_DRIP,                   // 093 CH_DRIP2 
TYPE_DRIP,                   // 094 CH_DRIP3 
TYPE_DRIP_SPLASH,            // 095 CH_DRIPX 
TYPE_DIRT,                   // 096 CH_DIRT 
TYPE_DIRT,                   // 097 CH_DIRT1 
TYPE_DIRT,                   // 098 CH_DIRT2 
TYPE_DIRT,                   // 099 CH_DIRT3 
TYPE_DIRT,                   // 100 CH_DIRT4 
TYPE_DIRT,                   // 101 CH_DIRT5 
TYPE_DIRT,                   // 102 CH_DIRT6 
TYPE_DIRT,                   // 103 CH_DIRT7 
TYPE_DIRT,                   // 104 CH_DIRT8 
TYPE_DIRT,                   // 105 CH_DIRT9 
TYPE_DIRT,                   // 106 CH_DIRTA 
TYPE_DIRT,                   // 107 CH_DIRTB 
TYPE_DIRT,                   // 108 CH_DIRTC 
TYPE_DIRT,                   // 109 CH_DIRTD 
TYPE_DIRT,                   // 110 CH_DIRTE 
TYPE_DIRT,                   // 111 CH_DIRTF 
TYPE_ZZAP,                   // 112 CH_ZZAP2 
TYPE_ROCK,                   // 113 CH_ROCK0 
TYPE_ROCK,                   // 114 CH_ROCK1 
TYPE_ROCK,                   // 115 CH_ROCK2 
TYPE_ROCK,                   // 116 CH_ROCK3 
TYPE_ROCK,                   // 117 CH_ROCK4 
TYPE_ROCK,                   // 118 CH_ROCK5 
TYPE_ROCK,                   // 119 CH_ROCK6 
TYPE_ROCK,                   // 120 CH_ROCK7 
TYPE_ROCK,                   // 121 CH_ROCK8 
TYPE_ROCK,                   // 122 CH_ROCK9 
TYPE_ROCK,                   // 123 CH_ROCKA 
TYPE_ROCK,                   // 124 CH_ROCKB 
TYPE_ROCK,                   // 125 CH_ROCKC 
TYPE_ROCK,                   // 126 CH_ROCKD 
TYPE_ROCK,                   // 127 CH_ROCKE 
TYPE_ROCK,                   // 128 CH_ROCKF 
TYPE_DRILL,                  // 129 CH_DRILL 
TYPE_DRILL,                  // 130 CH_DRILL1 
TYPE_DRILL,                  // 131 CH_DRILL2
TYPE_DRILLBODY,              // 132 CH_DRILLBODY
TYPE_DRILLBODY,              // 133 CH_DRILLBODY1

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
#define SQD ATT_SQUASHABLE_TO_DOGES
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

    RND| _ |RKF| _ | _ |WTR|LAV|QUI| _ | _ | _ | _ | _ | _ | _ |SPC|PER|XPD| _ | _  , // 00 SPACE
     _ |DRP| _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 01 DIRT
     _ |DRP| _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ |BNG| _ | _ | _ | _ |XPD| _ |ROL , // 02 BRICKWALL  
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 03 OUTBOX_PRE 
     _ | _ | _ | _ | _ | _ | _ | _ |XIT| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 04 OUTBOX  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 05 BOULDER_FALLING  
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 06 STEEL  
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT|BNG| _ | _ | _ | _ |XPD| _ |ROL , // 07 BOULDER 
    RND| _ | _ | _ | _ | _ | _ |QUI| _ | _ |SQB|ACT| _ |GRB| _ | _ | _ |XPD| _ | _  , // 08 DOGE  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 09 EXPLODE_SPACE_0  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 10 EXPLODE_SPACE_1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 11 EXPLODE_SPACE_2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 12 EXPLODE_SPACE_3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 13 EXPLODE_SPACE_4  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 14 EXPLODE_DOGE_0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 15 EXPLODE_DOGE_1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 16 EXPLODE_DOGE_2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 17 EXPLODE_DOGE_3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 18 EXPLODE_DOGE_4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 19 ROCKFORD_PRE  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ |SQB|ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 20 ROCKFORD
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 21 AMOEBA  
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 22 DRIP 
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 23 DRIP_SPLASH
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 24 __NOTHING  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 25 EXPLODE_THIS  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 26 BLANK_THIS 
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 27 DIRT3
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 28 DIRT2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 29 EXPLODE_BLANK_0  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 30 EXPLODE_BLANK_1  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 31 EXPLODE_BLANK_2  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 32 EXPLODE_BLANK_3  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 33 EXPLODE_BLANK_4  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC| _ |XPD| _ | _  , // 34 DOGE_GRAB  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 35 DIRT_GRAB  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 36 DUST 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 37 DUST2
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 38 DUST3
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 39 BOULDER_SHAKE 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 40 DUST_LEFT  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 41 DUST2_LEFT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 42 DUST3_LEFT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 43 DUST_RIGHT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 44 DUST2_RIGHT
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 45 DUST3_RIGHT
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 46 LAVA 
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 47 WATER
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ |SQB|ACT| _ | _ | _ | _ |PER| _ | _ | _  , // 48 EGG  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 49 ZZAP 
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 50 ZZAP1
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT|BNG| _ | _ | _ | _ |XPD| _ |ROL , // 51 ROCK  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 52 DRILL
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 53 DRILLBODY

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

