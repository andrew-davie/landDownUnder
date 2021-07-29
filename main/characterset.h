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

struct offset {
    unsigned char x;
    unsigned char y;
};

extern const struct offset charOffset[];

enum ChName {

    // +---> charSet[] @ characterset.c
    // +---> CharToType[] (below)

    CH_BLANK_PARALLAX,              // 000
    CH_BLANK,                       // 001
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
    CH_BLANK_ALTERNATE_3,           // 012
    CH_EXPLODETODOGE0,              // 013
    CH_EXPLODETODOGE1,              // 014
    CH_EXPLODETODOGE2,              // 015
    CH_EXPLODETODOGE3,              // 016
    CH_EXPLODETODOGE4,              // 017
    CH_ROCKYa,                      // 018
    CH_ROCKYb,                      // 019
    CH_ROCKYc,                      // 020
    CH_ROCKYd,                      // 021
    CH_xxROCKFORD,                  // 022
    CH_xxROCKFORD_THIS,             // 023
    CH_AMOEBA0,                     // 024
    CH_AMOEBA1,                     // 025
    CH_AMOEBA2,                     // 026
    CH_AMOEBA3,                     // 027
    CH_ZZAP,                        // 028
    CH_DOGE,                        // 029
    CH_DOGE_PULSE_1,                // 030
    CH_DOGE_PULSE_2,                // 031
    CH_DOGE_PULSE_3,                // 032
    CH_DOGE_PULSE_4,                // 033
    CH_DOGE_PULSE_5,                // 034
    CH_EXPLODETOBLANK0,             // 035
    CH_EXPLODETOBLANK1,             // 036
    CH_EXPLODETOBLANK2,             // 037
    CH_EXPLODETOBLANK3,             // 038
    CH_EXPLODETOBLANK4,             // 039
    CH_DOGE_GRAB,                   // 040
    CH_DIRT_GRAB,                   // 041
    CH_DUST,                        // 042
    CH_DUST2,                       // 043
    CH_DUST3,                       // 044
    CH_BOULDER_SHAKE,               // 045
    CH_DUST_LEFT,                   // 046
    CH_DUST2_LEFT,                  // 047
    CH_DUST3_LEFT,                  // 048
    CH_DUST_RIGHT,                  // 049
    CH_DUST2_RIGHT,                 // 050
    CH_DUST3_RIGHT,                 // 051
    CH_LAVA,                        // 052
    CH_LAVA1,                       // 053
    CH_LAVA2,                       // 054
    CH_LAVA3,                       // 055
    CH_WATER,                       // 056
    CH_WATER1,                      // 057
    CH_WATER2,                      // 058
    CH_WATER3,                      // 059
    CH_EGG2,                        // 060
    CH_ROCKFORD,                    // 061
    CH_ROCKFORD_THIS,               // 062
    CH_DRIP,                        // 063
    CH_DRIP1,                       // 064
    CH_DRIP2,                       // 065
    CH_DRIP3,                       // 066
    CH_DRIPX,                       // 067
    CH_DIRT,                        // 068
    CH_DIRT1,                       // 069
    CH_DIRT2,                       // 070
    CH_DIRT3,                       // 071
    CH_DIRT4,                       // 072
    CH_DIRT5,                       // 073
    CH_DIRT6,                       // 074
    CH_DIRT7,                       // 075
    CH_DIRT8,                       // 076
    CH_DIRT9,                       // 077
    CH_DIRTA,                       // 078
    CH_DIRTB,                       // 079
    CH_DIRTC,                       // 080
    CH_DIRTD,                       // 081
    CH_DIRTE,                       // 082
    CH_DIRTF,                       // 083
    CH_RUBBLE,                      // 084
    CH_RUBBLE1,                     // 085
    CH_ZZAP2,                       // 086
    CH_ROCK0,                       // 087
    CH_ROCK1,                       // 088
    CH_ROCK2,                       // 089
    CH_ROCK3,                       // 090
    CH_ROCK4,                       // 091
    CH_ROCK5,                       // 092
    CH_ROCK6,                       // 093
    CH_ROCK7,                       // 094
    CH_ROCK8,                       // 095
    CH_ROCK9,                       // 096
    CH_ROCKA,                       // 097
    CH_ROCKB,                       // 098
    CH_ROCKC,                       // 099
    CH_ROCKD,                       // 100
    CH_ROCKE,                       // 101
    CH_ROCKF,                       // 102
    CH_DRILL,                       // 103
    CH_DRILL1,                      // 104
    CH_DRILL2,                      // 105
    CH_DRILLBODY,                   // 106
    CH_DRILLBODY1,                  // 107
    CH_BELT,                        // 108
    CH_BELT1,                       // 109
    CH_BELT2,                       // 110
    CH_BELT3,                       // 111

    CH_MAX,
};

static const unsigned char CharToType[CH_MAX]= {

    // see ChName for corresponding character name/number

    TYPE_BLANK_PARALLAX,            // 000 CH_BLANK_PARALLAX  
    TYPE_BLANK,                     // 001 CH_BLANK  
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
    TYPE___NOTHING,                 // 012 CH_BLANK_ALTERNATE_3 
    TYPE_EXPLODE_DOGE_0,            // 013 CH_EXPLODETODOGE0 
    TYPE_EXPLODE_DOGE_1,            // 014 CH_EXPLODETODOGE1 
    TYPE_EXPLODE_DOGE_2,            // 015 CH_EXPLODETODOGE2 
    TYPE_EXPLODE_DOGE_3,            // 016 CH_EXPLODETODOGE3 
    TYPE_EXPLODE_DOGE_4,            // 017 CH_EXPLODETODOGE4 
    TYPE_ROCKFORD_PRE,              // 018 CH_ROCKYa 
    TYPE_ROCKFORD_PRE,              // 019 CH_ROCKYb 
    TYPE_ROCKFORD_PRE,              // 020 CH_ROCKYc 
    TYPE_ROCKFORD_PRE,              // 021 CH_ROCKYd 
    TYPE___NOTHING,                 // 022 CH_xxROCKFORD 
    TYPE___NOTHING,                 // 023 CH_xxROCKFORD_THIS 
    TYPE_AMOEBA,                    // 024 CH_AMOEBA0 
    TYPE_AMOEBA,                    // 025 CH_AMOEBA1 
    TYPE_AMOEBA,                    // 026 CH_AMOEBA2 
    TYPE_AMOEBA,                    // 027 CH_AMOEBA3 
    TYPE_ZZAP,                      // 028 CH_ZZAP 
    TYPE_DOGE,                      // 029 CH_DOGE
    TYPE_DOGE,                      // 030 CH_DOGE_PULSE_1 
    TYPE_DOGE,                      // 031 CH_DOGE_PULSE_2 
    TYPE_DOGE,                      // 032 CH_DOGE_PULSE_3 
    TYPE_DOGE,                      // 033 CH_DOGE_PULSE_4 
    TYPE_DOGE,                      // 034 CH_DOGE_PULSE_5 
    TYPE_EXPLODE_BLANK_0,           // 035 CH_EXPLODETOBLANK0 
    TYPE_EXPLODE_BLANK_1,           // 036 CH_EXPLODETOBLANK1 
    TYPE_EXPLODE_BLANK_2,           // 037 CH_EXPLODETOBLANK2 
    TYPE_EXPLODE_BLANK_3,           // 038 CH_EXPLODETOBLANK3 
    TYPE_EXPLODE_BLANK_4,           // 039 CH_EXPLODETOBLANK4 
    TYPE_DOGE_GRAB,                 // 040 CH_DOGE_GRAB 
    TYPE_DIRT_GRAB,                 // 041 CH_DIRT_GRAB 
    TYPE_DUST,                      // 042 CH_DUST 
    TYPE_DUST2,                     // 043 CH_DUST2 
    TYPE_DUST3,                     // 044 CH_DUST3 
    TYPE_BOULDER_SHAKE,             // 045 CH_BOULDER_SHAKE 
    TYPE_DUST_LEFT,                 // 046 CH_DUST_LEFT 
    TYPE_DUST2_LEFT,                // 047 CH_DUST2_LEFT 
    TYPE_DUST3_LEFT,                // 048 CH_DUST3_LEFT 
    TYPE_DUST_RIGHT,                // 049 CH_DUST_RIGHT 
    TYPE_DUST2_RIGHT,               // 050 CH_DUST2_RIGHT 
    TYPE_DUST3_RIGHT,               // 051 CH_DUST3_RIGHT 
    TYPE_LAVA,                      // 052 CH_LAVA 
    TYPE_LAVA,                      // 053 CH_LAVA1 
    TYPE_LAVA,                      // 054 CH_LAVA2 
    TYPE_LAVA,                      // 055 CH_LAVA3 
    TYPE_WATER,                     // 056 CH_WATER 
    TYPE_WATER,                     // 057 CH_WATER1 
    TYPE_WATER,                     // 058 CH_WATER2 
    TYPE_WATER,                     // 059 CH_WATER3 
    TYPE_EGG,                       // 060 CH_EGG2 
    TYPE_ROCKFORD,                  // 061 CH_ROCKFORD 
    TYPE_ROCKFORD,                  // 062 CH_ROCKFORD_THIS 
    TYPE_DRIP,                      // 063 CH_DRIP 
    TYPE_DRIP,                      // 064 CH_DRIP1 
    TYPE_DRIP,                      // 065 CH_DRIP2 
    TYPE_DRIP,                      // 066 CH_DRIP3 
    TYPE_DRIP_SPLASH,               // 067 CH_DRIPX 
    TYPE_DIRT,                      // 068 CH_DIRT 
    TYPE_DIRT,                      // 069 CH_DIRT1 
    TYPE_DIRT,                      // 070 CH_DIRT2 
    TYPE_DIRT,                      // 071 CH_DIRT3 
    TYPE_DIRT,                      // 072 CH_DIRT4 
    TYPE_DIRT,                      // 073 CH_DIRT5 
    TYPE_DIRT,                      // 074 CH_DIRT6 
    TYPE_DIRT,                      // 075 CH_DIRT7 
    TYPE_DIRT,                      // 076 CH_DIRT8 
    TYPE_DIRT,                      // 077 CH_DIRT9 
    TYPE_DIRT,                      // 078 CH_DIRTA 
    TYPE_DIRT,                      // 079 CH_DIRTB 
    TYPE_DIRT,                      // 080 CH_DIRTC 
    TYPE_DIRT,                      // 081 CH_DIRTD 
    TYPE_DIRT,                      // 082 CH_DIRTE 
    TYPE_DIRT,                      // 083 CH_DIRTF
    TYPE_RUBBLE,                    // 084 CH_RUBBLE
    TYPE_RUBBLE1,                   // 085 CH_RUBBLE1 
    TYPE_ZZAP,                      // 086 CH_ZZAP2 
    TYPE_ROCK,                      // 087 CH_ROCK0 
    TYPE_ROCK,                      // 088 CH_ROCK1 
    TYPE_ROCK,                      // 089 CH_ROCK2 
    TYPE_ROCK,                      // 090 CH_ROCK3 
    TYPE_ROCK,                      // 091 CH_ROCK4 
    TYPE_ROCK,                      // 092 CH_ROCK5 
    TYPE_ROCK,                      // 093 CH_ROCK6 
    TYPE_ROCK,                      // 094 CH_ROCK7 
    TYPE_ROCK,                      // 095 CH_ROCK8 
    TYPE_ROCK,                      // 096 CH_ROCK9 
    TYPE_ROCK,                      // 097 CH_ROCKA 
    TYPE_ROCK,                      // 098 CH_ROCKB 
    TYPE_ROCK,                      // 099 CH_ROCKC 
    TYPE_ROCK,                      // 100 CH_ROCKD 
    TYPE_ROCK,                      // 101 CH_ROCKE 
    TYPE_ROCK,                      // 102 CH_ROCKF 
    TYPE_DRILL,                     // 103 CH_DRILL 
    TYPE_DRILL,                     // 104 CH_DRILL1 
    TYPE_DRILL,                     // 105 CH_DRILL2
    TYPE_DRILLBODY,                 // 106 CH_DRILLBODY
    TYPE_DRILLBODY,                 // 107 CH_DRILLBODY1
    TYPE_BELT,                      // 108 CG_BELT
    TYPE_BELT2,                     // 109 CH_BELT1
    TYPE_BELT,                      // 110 CH_BELT2
    TYPE_BELT,                      // 111 CH_BELT3

};

#endif

