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
#define XX ((unsigned char)(0b10000000))|

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

    CH_BLANK,                       // 000
    CH_BRICKWALL,                   // 001
    CH_DOORCLOSED,                  // 002
    CH_DOOROPEN_0,                  // 003
    CH_DOOROPEN_1,                  // 004
    CH_STEEL,                       // 005
    CH_EGG,                         // 006
    CH_ZZAP1,                       // 007
    CH_BOULDER_FALLING,             // 008
    CH_DOGE,                        // 009
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
    CH_STEELWALL_1,                 // 029 ??
    CH_DOGE_PULSE_0,                // 030
    CH_DOGE_PULSE_1,                // 031
    CH_DOGE_PULSE_2,                // 032
    CH_DOGE_PULSE_3,                // 033
    CH_DOGE_PULSE_4,                // 034
    CH_DOGE_PULSE_5,                // 035
    CH_DOGE_PULSE_6,                // 036
    CH_DOGE_PULSE_7,                // 037
    CH_DOGE_PULSE_8,                // 038
    CH_DOGE_PULSE_9,                // 039
    CH_DOGE_STATIC,                 // 040
    CH_AMOEBA_BLANK,                // 041
    CH_EXPLODE_THIS,                // 042
    CH_BLANK_EXTRA1,                // 043
    CH_BLANK_EXTRA2,                // 044
    CH_BLANK_EXTRA3,                // 045
    CH_BLANK_EXTRA4,                // 046
    CH_BLANK_EXTRA5,                // 047
    CH_BLANK_EXTRA6,                // 048
    CH_BLANK_EXTRA7,                // 049
    CH_BLANK_EXTRA8,                // 050
    CH_EXPLODETOBLANK0,             // 051
    CH_EXPLODETOBLANK1,             // 052
    CH_EXPLODETOBLANK2,             // 053
    CH_EXPLODETOBLANK3,             // 054
    CH_EXPLODETOBLANK4,             // 055
    CH_DOGE_GRAB,                   // 056
    CH_DIRT_GRAB,                   // 057
    CH_DUST,                        // 058
    CH_DUST2,                       // 059
    CH_DUST3,                       // 060
    CH_BOULDER_SHAKE,               // 061
    CH_DUST_LEFT,                   // 062
    CH_DUST2_LEFT,                  // 063
    CH_DUST3_LEFT,                  // 064
    CH_DUST_RIGHT,                  // 065
    CH_DUST2_RIGHT,                 // 066
    CH_DUST3_RIGHT,                 // 067
    CH_LAVA,                        // 068
    CH_LAVA1,                       // 069
    CH_LAVA2,                       // 070
    CH_LAVA3,                       // 071
    CH_WATER,                       // 072
    CH_WATER1,                      // 073
    CH_WATER2,                      // 074
    CH_WATER3,                      // 075
    CH_EGG2,                        // 076
    CH_ROCKFORD,                    // 077
    CH_ROCKFORD_THIS,               // 078
    CH_DRIP,                        // 079
    CH_DRIP1,                       // 080
    CH_DRIP2,                       // 081
    CH_DRIP3,                       // 082
    CH_DRIPX,                       // 083
    CH_DIRT,                        // 084
    CH_DIRT1,                       // 085
    CH_DIRT2,                       // 086
    CH_DIRT3,                       // 087
    CH_DIRT4,                       // 088
    CH_DIRT5,                       // 089
    CH_DIRT6,                       // 090
    CH_DIRT7,                       // 091
    CH_DIRT8,                       // 092
    CH_DIRT9,                       // 093
    CH_DIRTA,                       // 094
    CH_DIRTB,                       // 095
    CH_DIRTC,                       // 096
    CH_DIRTD,                       // 097
    CH_DIRTE,                       // 098
    CH_DIRTF,                       // 099
    CH_RUBBLE,                      // 100
    CH_RUBBLE1,                     // 101
    CH_ZZAP2,                       // 102
    CH_ROCK0,                       // 103
    CH_ROCK1,                       // 104
    CH_ROCK2,                       // 105
    CH_ROCK3,                       // 106
    CH_ROCK4,                       // 107
    CH_ROCK5,                       // 108
    CH_ROCK6,                       // 109
    CH_ROCK7,                       // 110
    CH_ROCK8,                       // 111
    CH_ROCK9,                       // 112
    CH_ROCKA,                       // 113
    CH_ROCKB,                       // 114
    CH_ROCKC,                       // 115
    CH_ROCKD,                       // 116
    CH_ROCKE,                       // 117
    CH_ROCKF,                       // 118
    CH_DRILL,                       // 119
    CH_DRILL1,                      // 120
    CH_DRILL2,                      // 121
    CH_DRILLBODY,                   // 122
    CH_DRILLBODY1,                  // 123
    CH_BELT,                        // 124
    CH_BELT1,                       // 125
    CH_BELT2,                       // 126
    CH_BELT3,                       // 127

    CH_MAX,
};

static const unsigned char CharToType[CH_MAX]= {

    // see ChName for corresponding character name/number

    TYPE_SPACE,                     // 000 CH_BLANK  
    TYPE_BRICKWALL,                 // 001 CH_BRICKWALL  
    TYPE_OUTBOX_PRE,                // 002 CH_DOORCLOSED  
    TYPE_OUTBOX,                    // 003 CH_DOOROPEN_0  
    TYPE_OUTBOX,                    // 004 CH_DOOROPEN_1  
    TYPE_STEEL,                     // 005 CH_STEEL  
    TYPE_EGG,                       // 006 CH_EGG 
    TYPE_ZZAP1,                     // 007 CH_ZZAP1 
    TYPE_BOULDER_FALLING,           // 008 CH_BOULDER_FALLING 
    TYPE_DOGE,                      // 009 CH_DOGE 
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
    TYPE___NOTHING,                 // 029 CH_STEELWALL_1  ??
    TYPE_DOGE,                      // 030 CH_DOGE_PULSE_0 
    TYPE_DOGE,                      // 031 CH_DOGE_PULSE_1 
    TYPE_DOGE,                      // 032 CH_DOGE_PULSE_2 
    TYPE_DOGE,                      // 033 CH_DOGE_PULSE_3 
    TYPE_DOGE,                      // 034 CH_DOGE_PULSE_4 
    TYPE_DOGE,                      // 035 CH_DOGE_PULSE_5 
    TYPE_DOGE,                      // 036 CH_DOGE_PULSE_6 
    TYPE_DOGE,                      // 037 CH_DOGE_PULSE_7 
    TYPE_DOGE,                      // 038 CH_DOGE_PULSE_8 
    TYPE_DOGE,                      // 039 CH_DOGE_PULSE_9 
    TYPE_DOGE,                      // 040 CH_DOGE_STATIC 
    TYPE_AMOEBA,                    // 041 CH_AMOEBA_BLANK 
    TYPE_EXPLODE_THIS,              // 042 CH_EXPLODE_THIS 
    TYPE_SPACE,                     // 043 CH_BLANK_EXTRA1 
    TYPE_SPACE,                     // 044 CH_BLANK_EXTRA2 
    TYPE_SPACE,                     // 045 CH_BLANK_EXTRA3 
    TYPE_SPACE,                     // 046 CH_BLANK_EXTRA4 
    TYPE_SPACE,                     // 047 CH_BLANK_EXTRA5 
    TYPE_SPACE,                     // 048 CH_BLANK_EXTRA6 
    TYPE_SPACE,                     // 049 CH_BLANK_EXTRA7 
    TYPE_SPACE,                     // 050 CH_BLANK_EXTRA8 
    TYPE_EXPLODE_BLANK_0,           // 051 CH_EXPLODETOBLANK0 
    TYPE_EXPLODE_BLANK_1,           // 052 CH_EXPLODETOBLANK1 
    TYPE_EXPLODE_BLANK_2,           // 053 CH_EXPLODETOBLANK2 
    TYPE_EXPLODE_BLANK_3,           // 054 CH_EXPLODETOBLANK3 
    TYPE_EXPLODE_BLANK_4,           // 055 CH_EXPLODETOBLANK4 
    TYPE_DOGE_GRAB,                 // 056 CH_DOGE_GRAB 
    TYPE_DIRT_GRAB,                 // 057 CH_DIRT_GRAB 
    TYPE_DUST,                      // 058 CH_DUST 
    TYPE_DUST2,                     // 059 CH_DUST2 
    TYPE_DUST3,                     // 060 CH_DUST3 
    TYPE_BOULDER_SHAKE,             // 061 CH_BOULDER_SHAKE 
    TYPE_DUST_LEFT,                 // 062 CH_DUST_LEFT 
    TYPE_DUST2_LEFT,                // 063 CH_DUST2_LEFT 
    TYPE_DUST3_LEFT,                // 064 CH_DUST3_LEFT 
    TYPE_DUST_RIGHT,                // 065 CH_DUST_RIGHT 
    TYPE_DUST2_RIGHT,               // 066 CH_DUST2_RIGHT 
    TYPE_DUST3_RIGHT,               // 067 CH_DUST3_RIGHT 
    TYPE_LAVA,                      // 068 CH_LAVA 
    TYPE_LAVA,                      // 069 CH_LAVA1 
    TYPE_LAVA,                      // 070 CH_LAVA2 
    TYPE_LAVA,                      // 071 CH_LAVA3 
    TYPE_WATER,                     // 072 CH_WATER 
    TYPE_WATER,                     // 073 CH_WATER1 
    TYPE_WATER,                     // 074 CH_WATER2 
    TYPE_WATER,                     // 075 CH_WATER3 
    TYPE_EGG,                       // 076 CH_EGG2 
    TYPE_ROCKFORD,                  // 077 CH_ROCKFORD 
    TYPE_ROCKFORD,                  // 078 CH_ROCKFORD_THIS 
    TYPE_DRIP,                      // 079 CH_DRIP 
    TYPE_DRIP,                      // 080 CH_DRIP1 
    TYPE_DRIP,                      // 081 CH_DRIP2 
    TYPE_DRIP,                      // 082 CH_DRIP3 
    TYPE_DRIP_SPLASH,               // 083 CH_DRIPX 
    TYPE_DIRT,                      // 084 CH_DIRT 
    TYPE_DIRT,                      // 085 CH_DIRT1 
    TYPE_DIRT,                      // 086 CH_DIRT2 
    TYPE_DIRT,                      // 087 CH_DIRT3 
    TYPE_DIRT,                      // 088 CH_DIRT4 
    TYPE_DIRT,                      // 089 CH_DIRT5 
    TYPE_DIRT,                      // 090 CH_DIRT6 
    TYPE_DIRT,                      // 091 CH_DIRT7 
    TYPE_DIRT,                      // 092 CH_DIRT8 
    TYPE_DIRT,                      // 093 CH_DIRT9 
    TYPE_DIRT,                      // 094 CH_DIRTA 
    TYPE_DIRT,                      // 095 CH_DIRTB 
    TYPE_DIRT,                      // 096 CH_DIRTC 
    TYPE_DIRT,                      // 097 CH_DIRTD 
    TYPE_DIRT,                      // 098 CH_DIRTE 
    TYPE_DIRT,                      // 099 CH_DIRTF
    TYPE_RUBBLE,                    // 100 CH_RUBBLE
    TYPE_RUBBLE1,                   // 101 CH_RUBBLE1 
    TYPE_ZZAP,                      // 102 CH_ZZAP2 
    TYPE_ROCK,                      // 103 CH_ROCK0 
    TYPE_ROCK,                      // 104 CH_ROCK1 
    TYPE_ROCK,                      // 105 CH_ROCK2 
    TYPE_ROCK,                      // 106 CH_ROCK3 
    TYPE_ROCK,                      // 107 CH_ROCK4 
    TYPE_ROCK,                      // 108 CH_ROCK5 
    TYPE_ROCK,                      // 109 CH_ROCK6 
    TYPE_ROCK,                      // 110 CH_ROCK7 
    TYPE_ROCK,                      // 111 CH_ROCK8 
    TYPE_ROCK,                      // 112 CH_ROCK9 
    TYPE_ROCK,                      // 113 CH_ROCKA 
    TYPE_ROCK,                      // 114 CH_ROCKB 
    TYPE_ROCK,                      // 115 CH_ROCKC 
    TYPE_ROCK,                      // 116 CH_ROCKD 
    TYPE_ROCK,                      // 117 CH_ROCKE 
    TYPE_ROCK,                      // 118 CH_ROCKF 
    TYPE_DRILL,                     // 119 CH_DRILL 
    TYPE_DRILL,                     // 120 CH_DRILL1 
    TYPE_DRILL,                     // 121 CH_DRILL2
    TYPE_DRILLBODY,                 // 122 CH_DRILLBODY
    TYPE_DRILLBODY,                 // 123 CH_DRILLBODY1
    TYPE_BELT,                      // 124 CG_BELT
    TYPE_BELT2,                     // 125 CH_BELT1
    TYPE_BELT,                      // 126 CH_BELT2
    TYPE_BELT,                      // 127 CH_BELT3

};

#endif

