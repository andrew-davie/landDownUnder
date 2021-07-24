// Object attributes

    #include "attribute.h"
    #include "main.h"

const unsigned char CharToType[CH_MAX]= {

    // see ChName for corresponding character name/number

TYPE_SPACE,                  // 000 CH_BLANK  
TYPE_DIRT,                   // 001 CH_DIRTY  
TYPE_BRICKWALL,              // 002 CH_BRICKWALL  
TYPE_MAGICWALL,              // 003 CH_MAGICWALL  
TYPE_OUTBOX_PRE,             // 004 CH_DOORCLOSED  
TYPE_OUTBOX,                 // 005 CH_DOOROPEN_0  
TYPE_OUTBOX,                 // 006 CH_DOOROPEN_1  
TYPE_STEELWALL,              // 007 CH_STEELWALL_0  
TYPE_FIREFLY,                // 008 CH_FIREFLY_0  
TYPE_FIREFLY,                // 009 CH_FIREFLY_1  
TYPE_FIREFLY,                // 010 CH_FIREFLY_2  
TYPE_FIREFLY,                // 011 CH_FIREFLY_3  
TYPE_DIRT3,                  // 012 CH_DIRTY3  
TYPE_DIRT2,                  // 013 CH_DIRTY2  
TYPE_EGG,                    // 014 CH_EGG 
TYPE_FIREFLY,                // 015 CH_FIREFLY_7 
TYPE_BOULDER,                // 016 CH_BOULDER 
TYPE_ZZAP1,                  // 017 CH_ZZAP1 
TYPE_BOULDER_FALLING,        // 018 CH_BOULDER_FALLING 
TYPE_ROCK,                   // 019 CH_ROCKSEED 
TYPE_DOGE,                   // 020 CH_DOGE 
TYPE___THISFRAME,            // 021 CH_DOGE_FALLING_THIS 
TYPE_DOGE,                   // 022 CH_DOGE_FALLING 
TYPE___THISFRAME,            // 023 CH_DOGE_THIS 
TYPE_FIREFLY,                // 024 CH_DOGE_4 
TYPE_FIREFLY,                // 025 CH_FIREFLY2 
TYPE___NOTHING,              // 026 CH_FIREFLY3 
TYPE_BUTTERFLY,              // 027 CH_BUTTERFLY2U 
TYPE_BUTTERFLY,              // 028 CH_BUTTERFLY3U 
TYPE___NOTHING,              // 029 CH_BLANK_ALTERNATE_3 
TYPE___NOTHING,              // 030 CH_____0 
TYPE___NOTHING,              // 031 CH_____1 
TYPE_EXPLODE_DOGE_0,         // 032 CH_EXPLODETODOGE0 
TYPE_EXPLODE_DOGE_1,         // 033 CH_EXPLODETODOGE1 
TYPE_EXPLODE_DOGE_2,         // 034 CH_EXPLODETODOGE2 
TYPE_EXPLODE_DOGE_3,         // 035 CH_EXPLODETODOGE3 
TYPE_EXPLODE_DOGE_4,         // 036 CH_EXPLODETODOGE4 
TYPE_ROCKFORD_PRE,           // 037 CH_ROCKYa 
TYPE_ROCKFORD_PRE,           // 038 CH_ROCKYb 
TYPE_ROCKFORD_PRE,           // 039 CH_ROCKYc 
TYPE_ROCKFORD_PRE,           // 040 CH_ROCKYd 
TYPE_BOULDER,                // 041 CH_BOULDER2 
TYPE_BOULDER,                // 042 CH_BOULDER3 
TYPE_BOULDER,                // 043 CH_BOULDER4 
TYPE___NOTHING,              // 044 CH_MAGIC1 
TYPE___NOTHING,              // 045 CH_MAGIC2 
TYPE___NOTHING,              // 046 CH_MAGIC3 
TYPE_DOGE,                   // 047 CH_DOGEx1U 
TYPE_BUTTERFLY,              // 048 CH_BUTTERFLY0 
TYPE_BUTTERFLY,              // 049 CH_BUTTERFLY1 
TYPE_BUTTERFLY,              // 050 CH_BUTTERFLY2 
TYPE_BUTTERFLY,              // 051 CH_BUTTERFLY3 
TYPE_BUTTERFLY,              // 052 CH_BUTTERFLY_4 
TYPE_BUTTERFLY,              // 053 CH_BUTTERFLY_5 
TYPE_BUTTERFLY,              // 054 CH_BUTTERFLY_6 
TYPE_BUTTERFLY,              // 055 CH_BUTTERFLY_7 
TYPE___NOTHING,              // 056 CH_xxROCKFORD 
TYPE___NOTHING,              // 057 CH_xxROCKFORD_THIS 
TYPE_AMOEBA,                 // 058 CH_AMOEBA0 
TYPE_AMOEBA,                 // 059 CH_AMOEBA1 
TYPE_AMOEBA,                 // 060 CH_AMOEBA2 
TYPE_AMOEBA,                 // 061 CH_AMOEBA3 
TYPE_ZZAP,                   // 062 CH_ZZAP 
TYPE___NOTHING,              // 063 CH_STEELWALL_1 
TYPE___NOTHING,              // 064 CH_____2 
TYPE___NOTHING,              // 065 CH_____3 
TYPE___NOTHING,              // 066 CH_____4 
TYPE___NOTHING,              // 067 CH_____5 
TYPE___NOTHING,              // 068 CH_____6 
TYPE___NOTHING,              // 069 CH_____7 
TYPE_DOGE,                   // 070 CH_DOGE_PULSE_0 
TYPE_DOGE,                   // 071 CH_DOGE_PULSE_1 
TYPE_DOGE,                   // 072 CH_DOGE_PULSE_2 
TYPE_DOGE,                   // 073 CH_DOGE_PULSE_3 
TYPE_DOGE,                   // 074 CH_DOGE_PULSE_4 
TYPE_DOGE,                   // 075 CH_DOGE_PULSE_5 
TYPE_DOGE,                   // 076 CH_DOGE_PULSE_6 
TYPE_DOGE,                   // 077 CH_DOGE_PULSE_7 
TYPE_DOGE,                   // 078 CH_DOGE_PULSE_8 
TYPE_DOGE,                   // 079 CH_DOGE_PULSE_9 
TYPE_DOGE,                   // 080 CH_DOGE_STATIC 
TYPE_AMOEBA,                 // 081 CH_AMOEBA_BLANK 
TYPE_EXPLODE_THIS,           // 082 CH_EXPLODE_THIS 
TYPE_SPACE,                  // 083 CH_BLANK_EXTRA1 
TYPE_SPACE,                  // 084 CH_BLANK_EXTRA2 
TYPE_SPACE,                  // 085 CH_BLANK_EXTRA3 
TYPE_SPACE,                  // 086 CH_BLANK_EXTRA4 
TYPE_SPACE,                  // 087 CH_BLANK_EXTRA5 
TYPE_SPACE,                  // 088 CH_BLANK_EXTRA6 
TYPE_SPACE,                  // 089 CH_BLANK_EXTRA7 
TYPE_SPACE,                  // 090 CH_BLANK_EXTRA8 
TYPE___NOTHING,              // 091 CH_UNKNOWN23 
TYPE_EXPLODE_BLANK_0,        // 092 CH_EXPLODETOBLANK0 
TYPE_EXPLODE_BLANK_1,        // 093 CH_EXPLODETOBLANK1 
TYPE_EXPLODE_BLANK_2,        // 094 CH_EXPLODETOBLANK2 
TYPE_EXPLODE_BLANK_3,        // 095 CH_EXPLODETOBLANK3 
TYPE_EXPLODE_BLANK_4,        // 096 CH_EXPLODETOBLANK4 
TYPE_DOGE_GRAB,              // 097 CH_DOGE_GRAB 
TYPE_DIRT_GRAB,              // 098 CH_DIRT_GRAB 
TYPE_DUST,                   // 099 CH_DUST 
TYPE_DUST2,                  // 100 CH_DUST2 
TYPE_DUST3,                  // 101 CH_DUST3 
TYPE_BOULDER_SHAKE,          // 102 CH_BOULDER_SHAKE 
TYPE_DUST_LEFT,              // 103 CH_DUST_LEFT 
TYPE_DUST2_LEFT,             // 104 CH_DUST2_LEFT 
TYPE_DUST3_LEFT,             // 105 CH_DUST3_LEFT 
TYPE_DUST_RIGHT,             // 106 CH_DUST_RIGHT 
TYPE_DUST2_RIGHT,            // 107 CH_DUST2_RIGHT 
TYPE_DUST3_RIGHT,            // 108 CH_DUST3_RIGHT 
TYPE_LAVA,                   // 109 CH_LAVA 
TYPE_LAVA,                   // 110 CH_LAVA1 
TYPE_LAVA,                   // 111 CH_LAVA2 
TYPE_LAVA,                   // 112 CH_LAVA3 
TYPE_WATER,                  // 113 CH_WATER 
TYPE_WATER,                  // 114 CH_WATER1 
TYPE_WATER,                  // 115 CH_WATER2 
TYPE_WATER,                  // 116 CH_WATER3 
TYPE_EGG,                    // 117 CH_EGG2 
TYPE_ROCKFORD,               // 118 CH_ROCKFORD 
TYPE_ROCKFORD,               // 119 CH_ROCKFORD_THIS 
TYPE_DRIP,                   // 120 CH_DRIP 
TYPE_DRIP,                   // 121 CH_DRIP1 
TYPE_DRIP,                   // 122 CH_DRIP2 
TYPE_DRIP,                   // 123 CH_DRIP3 
TYPE_DRIP_SPLASH,            // 124 CH_DRIPX 
TYPE_DIRT,                   // 125 CH_DIRT 
TYPE_DIRT,                   // 126 CH_DIRT1 
TYPE_DIRT,                   // 127 CH_DIRT2 
TYPE_DIRT,                   // 128 CH_DIRT3 
TYPE_DIRT,                   // 129 CH_DIRT4 
TYPE_DIRT,                   // 130 CH_DIRT5 
TYPE_DIRT,                   // 131 CH_DIRT6 
TYPE_DIRT,                   // 132 CH_DIRT7 
TYPE_DIRT,                   // 133 CH_DIRT8 
TYPE_DIRT,                   // 134 CH_DIRT9 
TYPE_DIRT,                   // 135 CH_DIRTA 
TYPE_DIRT,                   // 136 CH_DIRTB 
TYPE_DIRT,                   // 137 CH_DIRTC 
TYPE_DIRT,                   // 138 CH_DIRTD 
TYPE_DIRT,                   // 139 CH_DIRTE 
TYPE_DIRT,                   // 140 CH_DIRTF 
TYPE_ZZAP,                   // 141 CH_ZZAP2 
TYPE_ROCK,                   // 142 CH_ROCK0 
TYPE_ROCK,                   // 143 CH_ROCK1 
TYPE_ROCK,                   // 144 CH_ROCK2 
TYPE_ROCK,                   // 145 CH_ROCK3 
TYPE_ROCK,                   // 146 CH_ROCK4 
TYPE_ROCK,                   // 147 CH_ROCK5 
TYPE_ROCK,                   // 148 CH_ROCK6 
TYPE_ROCK,                   // 149 CH_ROCK7 
TYPE_ROCK,                   // 150 CH_ROCK8 
TYPE_ROCK,                   // 151 CH_ROCK9 
TYPE_ROCK,                   // 152 CH_ROCKA 
TYPE_ROCK,                   // 153 CH_ROCKB 
TYPE_ROCK,                   // 154 CH_ROCKC 
TYPE_ROCK,                   // 155 CH_ROCKD 
TYPE_ROCK,                   // 156 CH_ROCKE 
TYPE_ROCK,                   // 157 CH_ROCKF 
TYPE_DRILL,                  // 158 CH_DRILL 
TYPE_DRILL,                  // 159 CH_DRILL1 
TYPE_DRILL,                  // 160 CH_DRILL2 

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
     _ |DRP| _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ | _ | _ | _ | _ | _ |XPD| _ |ROL , // 02 BRICKWALL  
     _ |DRP| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |XPD| _ | _  , // 03 MAGICWALL  
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 04 OUTBOX_PRE 
     _ | _ | _ | _ | _ | _ | _ | _ |XIT| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 05 OUTBOX  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 06 BOULDER_FALLING  
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 07 STEELWALL  
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ |SQB|ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 08 FIREFLY 
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 09 BOULDER 
    RND| _ | _ | _ | _ | _ | _ |QUI| _ | _ |SQB|ACT| _ |GRB| _ | _ | _ |XPD| _ | _  , // 10 DOGE  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 11 EXPLODE_SPACE_0  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 12 EXPLODE_SPACE_1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 13 EXPLODE_SPACE_2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 14 EXPLODE_SPACE_3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 15 EXPLODE_SPACE_4  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 16 EXPLODE_DOGE_0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 17 EXPLODE_DOGE_1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 18 EXPLODE_DOGE_2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 19 EXPLODE_DOGE_3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 20 EXPLODE_DOGE_4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 21 ROCKFORD_PRE  
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ |ACT| _ | _ |SQD| _ | _ |XPD| _ | _  , // 22 BUTTERFLY  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ |SQB|ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 23 ROCKFORD
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 24 AMOEBA  
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 25 DRIP 
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 26 DRIP_SPLASH
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 27 __NOTHING  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 28 __THISFRAME
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 29 EXPLODE_THIS  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 30 BLANK_THIS 
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 31 DIRT3
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 32 DIRT2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 33 EXPLODE_BLANK_0  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 34 EXPLODE_BLANK_1  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 35 EXPLODE_BLANK_2  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 36 EXPLODE_BLANK_3  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 37 EXPLODE_BLANK_4  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC| _ |XPD| _ | _  , // 38 DOGE_GRAB  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 39 DIRT_GRAB  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 40 DUST 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 41 DUST2
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 42 DUST3
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 43 BOULDER_SHAKE 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 44 DUST_LEFT  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 45 DUST2_LEFT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 46 DUST3_LEFT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 47 DUST_RIGHT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 48 DUST2_RIGHT
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 49 DUST3_RIGHT
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 50 LAVA 
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 51 WATER
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ |SQB|ACT| _ | _ | _ | _ |PER| _ | _ | _  , // 52 EGG  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 53 ZZAP 
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 54 ZZAP1
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 55 ROCK  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 56 DRILL

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

