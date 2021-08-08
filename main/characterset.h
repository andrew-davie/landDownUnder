#ifndef __CHARACTERSET_H
#define __CHARACTERSET_H

    #include "attribute.h"

#define ____ 0b00000,
#define ___X 0b00001,
#define __X_ 0b00010,
#define __XX 0b00011,
#define _X__ 0b00100,
#define _X_X 0b00101,
#define _XX_ 0b00110,
#define _XXX 0b00111,
#define X___ 0b01000,
#define X__X 0b01001,
#define X_X_ 0b01010,
#define X_XX 0b01011,
#define XX__ 0b01100,
#define XX_X 0b01101,
#define XXX_ 0b01110,
#define XXXX 0b01111,

#define __ (0b000000000)|
#define _X ((unsigned char)(0b01000000))|
#define X_ ((unsigned char)(0b10000000))|
#define XX ((unsigned char)(0b11000000))|

#define CHAR_ALLOC (PIECE_DEPTH + 9 + 9)

extern const unsigned char (*charSet[])[];
extern const unsigned char CHAR_BLANK[];

struct offset {
    unsigned char x;
    unsigned char y;
};

extern const struct offset charOffset[];

enum ChName {

    // +---> charSet[] @ characterset.c
    // +---> CharToType[] (below)

    CH_BLANK,                       // 000
    CH_BLANK_SKY,                   // 001
    CH_BRICKWALL,                   // 002
    CH_DOORCLOSED,                  // 003
    CH_DOOROPEN_0,                  // 004
    CH_DOOROPEN_1,                  // 005
    CH_STEEL,                       // 006
    CH_EGG,                         // 007
    CH_ZZAP1,                       // 008
    CH_BOULDER_FALLING,             // 009
    CH_DOGE_FALLING,                // 010
    CH_DOGE_4,                      // 011

    CH_EXPLODETODOGE0,              // 012 --+ EXPLODE -> DOGE
    CH_EXPLODETODOGE1,              // 013  X|
    CH_EXPLODETODOGE2,              // 014  X|
    CH_EXPLODETODOGE3,              // 015  X|
    CH_EXPLODETODOGE4,              // 016 --+

    CH_ROCKYa,                      // 017
    CH_ROCKYb,                      // 018
    CH_ROCKYc,                      // 019
    CH_ROCKYd,                      // 020
    CH_xxROCKFORD,                  // 021
    CH_xxROCKFORD_THIS,             // 022

    CH_AMOEBA0,                     // 023 --+ AMOEBA
    CH_AMOEBA1,                     // 024  X|
    CH_AMOEBA2,                     // 025  X|
    CH_AMOEBA3,                     // 026 --+

    CH_ZZAP,                        // 027

    CH_DOGE,                        // 028 --+ DOGE COIN
    CH_DOGE_PULSE_1,                // 029  X|
    CH_DOGE_PULSE_2,                // 030  X|
    CH_DOGE_PULSE_3,                // 031  X|
    CH_DOGE_PULSE_4,                // 032  X|
    CH_DOGE_PULSE_5,                // 033 --+

    CH_EXPLODETOBLANK0,             // 034 --+ EXPLODE -> BLANK
    CH_EXPLODETOBLANK1,             // 035  X|
    CH_EXPLODETOBLANK2,             // 036  X|
    CH_EXPLODETOBLANK3,             // 037  X|
    CH_EXPLODETOBLANK4,             // 038 --+

    CH_DOGE_GRAB,                   // 039
    CH_DIRT_GRAB,                   // 040

    CH_DUST,                        // 041 --+ DIG DUST
    CH_DUST2,                       // 042  X|
    CH_DUST3,                       // 043  X|
    CH_BOULDER_SHAKE,               // 044 --+

    CH_DUST_LEFT,                   // 045 --+ ROCKDUST
    CH_DUST2_LEFT,                  // 046  X|
    CH_DUST3_LEFT,                  // 047  X|
    CH_DUST_RIGHT,                  // 048  X|
    CH_DUST2_RIGHT,                 // 049  X|
    CH_DUST3_RIGHT,                 // 050 --+
    
    CH_LAVA,                        // 051 --+ LAVA
    CH_LAVA1,                       // 052  X|
    CH_LAVA2,                       // 053  X|
    CH_LAVA3,                       // 054 --+

    CH_WATER,                       // 055 --+ WATER
    CH_WATER1,                      // 056  X|
    CH_WATER2,                      // 057  X|
    CH_WATER3,                      // 058 --+

    CH_EGG2,                        // 059
    CH_ROCKFORD,                    // 060
    CH_ROCKFORD_THIS,               // 061

    CH_DRIP,                        // 062 --+ DRIP
    CH_DRIP1,                       // 063  X|
    CH_DRIP2,                       // 064  X|
    CH_DRIP3,                       // 065  X|
    CH_DRIPX,                       // 066 --+

    CH_DIRT,                        // 067 --+ DIRT
    CH_DIRT1,                       // 068  X|
    CH_DIRT2,                       // 069  X|
    CH_DIRT3,                       // 070  X|
    CH_DIRT4,                       // 071  X|
    CH_DIRT5,                       // 072  X|
    CH_DIRT6,                       // 073  X|
    CH_DIRT7,                       // 074  X|
    CH_DIRT8,                       // 075  X|
    CH_DIRT9,                       // 076  X|
    CH_DIRTA,                       // 077  X|
    CH_DIRTB,                       // 078  X|
    CH_DIRTC,                       // 079  X|
    CH_DIRTD,                       // 080  X|
    CH_DIRTE,                       // 081  X|
    CH_DIRTF,                       // 082 --+

    CH_RUBBLE,                      // 083
    CH_RUBBLE1,                     // 084
    CH_ZZAP2,                       // 085

    CH_ROCK0,                       // 086 --+ ROCK
    CH_ROCK1,                       // 087  X|
    CH_ROCK2,                       // 088  X|
    CH_ROCK3,                       // 089  X|
    CH_ROCK4,                       // 090  X|
    CH_ROCK5,                       // 091  X|
    CH_ROCK6,                       // 092  X|
    CH_ROCK7,                       // 093  X|
    CH_ROCK8,                       // 094  X|
    CH_ROCK9,                       // 095  X|
    CH_ROCKA,                       // 096  X|
    CH_ROCKB,                       // 097  X|
    CH_ROCKC,                       // 098  X|
    CH_ROCKD,                       // 099  X|
    CH_ROCKE,                       // 100  X|
    CH_ROCKF,                       // 101 --+

    CH_DRILL,                       // 102 --+ DRILL
    CH_DRILL1,                      // 103  X|
    CH_DRILL2,                      // 104  X|
    CH_DRILLBODY,                   // 105  X|
    CH_DRILLBODY1,                  // 106 --+

    CH_BELT,                        // 107 --+ CONVEYOR
    CH_BELT1,                       // 108  X|
    CH_BELT2,                       // 109  X|
    CH_BELT3,                       // 110 --+

    CH_CRATER_SMALL,                // 111
    CH_CRATER_TINY,                 // 112
    CH_CRATER_BIG,                  // 113
    CH_CRATER_BIG1,                 // 114
    CH_CRATER_BIG2,                 // 115
    CH_CRATER_BIG3,                 // 116
    CH_CRATER_MID,                  // 117

    CH_FLAT_1,                      // 118
    CH_SHADOW,                      // 119
    CH_FLAT_2,                      // 120
    CH_LATITUDE,                    // 121
    

    CH_MAX,
};

static const unsigned char CharToType[CH_MAX]= {

    // see ChName for corresponding character name/number

    TYPE_BLANK,                     // 000 CH_BLANK  
    TYPE_BLANK_SKY,                 // 001 CH_BLANK_SKY
    TYPE_BRICKWALL,                 // 002 CH_BRICKWALL  
    TYPE_OUTBOX_PRE,                // 003 CH_DOORCLOSED  
    TYPE_OUTBOX,                    // 004 CH_DOOROPEN_0  
    TYPE_OUTBOX,                    // 005 CH_DOOROPEN_1  
    TYPE_STEEL,                     // 006 CH_STEEL  
    TYPE_EGG,                       // 007 CH_EGG 
    TYPE_ZZAP1,                     // 008 CH_ZZAP1 
    TYPE_BOULDER_FALLING,           // 009 CH_BOULDER_FALLING 
    TYPE_DOGE,                      // 010 CH_DOGE_FALLING 
    TYPE_DOGE,                      // 011 CH_DOGE_4 
    TYPE_EXPLODE_DOGE_0,            // 012 CH_EXPLODETODOGE0 
    TYPE_EXPLODE_DOGE_1,            // 013 CH_EXPLODETODOGE1 
    TYPE_EXPLODE_DOGE_2,            // 014 CH_EXPLODETODOGE2 
    TYPE_EXPLODE_DOGE_3,            // 015 CH_EXPLODETODOGE3 
    TYPE_EXPLODE_DOGE_4,            // 016 CH_EXPLODETODOGE4 
    TYPE_ROCKFORD_PRE,              // 017 CH_ROCKYa 
    TYPE_ROCKFORD_PRE,              // 018 CH_ROCKYb 
    TYPE_ROCKFORD_PRE,              // 019 CH_ROCKYc 
    TYPE_ROCKFORD_PRE,              // 020 CH_ROCKYd 
    TYPE___NOTHING,                 // 021 CH_xxROCKFORD 
    TYPE___NOTHING,                 // 022 CH_xxROCKFORD_THIS 
    TYPE_AMOEBA,                    // 023 CH_AMOEBA0 
    TYPE_AMOEBA,                    // 024 CH_AMOEBA1 
    TYPE_AMOEBA,                    // 025 CH_AMOEBA2 
    TYPE_AMOEBA,                    // 026 CH_AMOEBA3 
    TYPE_ZZAP,                      // 027 CH_ZZAP 
    TYPE_DOGE,                      // 028 CH_DOGE
    TYPE_DOGE,                      // 029 CH_DOGE_PULSE_1 
    TYPE_DOGE,                      // 030 CH_DOGE_PULSE_2 
    TYPE_DOGE,                      // 031 CH_DOGE_PULSE_3 
    TYPE_DOGE,                      // 032 CH_DOGE_PULSE_4 
    TYPE_DOGE,                      // 033 CH_DOGE_PULSE_5 
    TYPE_EXPLODE_BLANK_0,           // 034 CH_EXPLODETOBLANK0 
    TYPE_EXPLODE_BLANK_1,           // 035 CH_EXPLODETOBLANK1 
    TYPE_EXPLODE_BLANK_2,           // 036 CH_EXPLODETOBLANK2 
    TYPE_EXPLODE_BLANK_3,           // 037 CH_EXPLODETOBLANK3 
    TYPE_EXPLODE_BLANK_4,           // 038 CH_EXPLODETOBLANK4 
    TYPE_DOGE_GRAB,                 // 039 CH_DOGE_GRAB 
    TYPE_DIRT_GRAB,                 // 040 CH_DIRT_GRAB 
    TYPE_DUST,                      // 041 CH_DUST 
    TYPE_DUST2,                     // 042 CH_DUST2 
    TYPE_DUST3,                     // 043 CH_DUST3 
    TYPE_BOULDER_SHAKE,             // 044 CH_BOULDER_SHAKE 
    TYPE_DUST_LEFT,                 // 045 CH_DUST_LEFT 
    TYPE_DUST2_LEFT,                // 046 CH_DUST2_LEFT 
    TYPE_DUST3_LEFT,                // 047 CH_DUST3_LEFT 
    TYPE_DUST_RIGHT,                // 048 CH_DUST_RIGHT 
    TYPE_DUST2_RIGHT,               // 049 CH_DUST2_RIGHT 
    TYPE_DUST3_RIGHT,               // 050 CH_DUST3_RIGHT 
    TYPE_LAVA,                      // 051 CH_LAVA 
    TYPE_LAVA,                      // 052 CH_LAVA1 
    TYPE_LAVA,                      // 053 CH_LAVA2 
    TYPE_LAVA,                      // 054 CH_LAVA3 
    TYPE_WATER,                     // 055 CH_WATER 
    TYPE_WATER,                     // 056 CH_WATER1 
    TYPE_WATER,                     // 057 CH_WATER2 
    TYPE_WATER,                     // 058 CH_WATER3 
    TYPE_EGG,                       // 059 CH_EGG2 
    TYPE_ROCKFORD,                  // 060 CH_ROCKFORD 
    TYPE_ROCKFORD,                  // 061 CH_ROCKFORD_THIS 
    TYPE_DRIP,                      // 062 CH_DRIP 
    TYPE_DRIP,                      // 063 CH_DRIP1 
    TYPE_DRIP,                      // 064 CH_DRIP2 
    TYPE_DRIP,                      // 065 CH_DRIP3 
    TYPE_DRIP_SPLASH,               // 066 CH_DRIPX 
    TYPE_DIRT,                      // 067 CH_DIRT 
    TYPE_DIRT,                      // 068 CH_DIRT1 
    TYPE_DIRT,                      // 069 CH_DIRT2 
    TYPE_DIRT,                      // 070 CH_DIRT3 
    TYPE_DIRT,                      // 071 CH_DIRT4 
    TYPE_DIRT,                      // 072 CH_DIRT5 
    TYPE_DIRT,                      // 073 CH_DIRT6 
    TYPE_DIRT,                      // 074 CH_DIRT7 
    TYPE_DIRT,                      // 075 CH_DIRT8 
    TYPE_DIRT,                      // 076 CH_DIRT9 
    TYPE_DIRT,                      // 077 CH_DIRTA 
    TYPE_DIRT,                      // 078 CH_DIRTB 
    TYPE_DIRT,                      // 079 CH_DIRTC 
    TYPE_DIRT,                      // 080 CH_DIRTD 
    TYPE_DIRT,                      // 081 CH_DIRTE 
    TYPE_DIRT,                      // 082 CH_DIRTF
    TYPE_RUBBLE,                    // 083 CH_RUBBLE
    TYPE_RUBBLE1,                   // 084 CH_RUBBLE1 
    TYPE_ZZAP,                      // 085 CH_ZZAP2 
    TYPE_ROCK,                      // 086 CH_ROCK0 
    TYPE_ROCK,                      // 087 CH_ROCK1 
    TYPE_ROCK,                      // 088 CH_ROCK2 
    TYPE_ROCK,                      // 089 CH_ROCK3 
    TYPE_ROCK,                      // 090 CH_ROCK4 
    TYPE_ROCK,                      // 091 CH_ROCK5 
    TYPE_ROCK,                      // 092 CH_ROCK6 
    TYPE_ROCK,                      // 093 CH_ROCK7 
    TYPE_ROCK,                      // 094 CH_ROCK8 
    TYPE_ROCK,                      // 095 CH_ROCK9 
    TYPE_ROCK,                      // 096 CH_ROCKA 
    TYPE_ROCK,                      // 097 CH_ROCKB 
    TYPE_ROCK,                      // 098 CH_ROCKC 
    TYPE_ROCK,                      // 099 CH_ROCKD 
    TYPE_ROCK,                      // 100 CH_ROCKE 
    TYPE_ROCK,                      // 101 CH_ROCKF 
    TYPE_DRILL,                     // 102 CH_DRILL 
    TYPE_DRILL,                     // 103 CH_DRILL1 
    TYPE_DRILL,                     // 104 CH_DRILL2
    TYPE_DRILLBODY,                 // 105 CH_DRILLBODY
    TYPE_DRILLBODY,                 // 106 CH_DRILLBODY1
    TYPE_BELT,                      // 107 CG_BELT
    TYPE_BELT2,                     // 108 CH_BELT1
    TYPE_BELT,                      // 109 CH_BELT2
    TYPE_BELT,                      // 110 CH_BELT3
    TYPE_CRATER,                    // 111 CH_CRATER_SMALL
    TYPE_CRATER,                    // 112 CH_CRATER_TINY
    TYPE_CRATER,                    // 113 CH_CRATER_BIG
    TYPE_CRATER,                    // 114 CH_CRATER_BIG1
    TYPE_CRATER,                    // 115 CH_CRATER_BIG2
    TYPE_CRATER,                    // 116 CH_CRATER_BIG3
    TYPE_CRATER,                    // 117 CH_CRATER_MID
    TYPE_FLAT,                      // 118 CH_FLAT_1
    TYPE_SHADOW,                    // 119 CH_SHADOW
    TYPE_FLAT,                      // 120 CH_FLAT_2
    TYPE_FLAT,                      // 121 CH_LATITUDE
};

#endif

