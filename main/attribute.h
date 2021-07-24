    #include "main.h"
    
extern const int Attribute[];
extern const unsigned char CharToType[];

enum ObjectType {

    // +--> modify Attribute[] @ attribute.c
    // +--> modify Animate[] @ main.c

    TYPE_SPACE,              // 00
    TYPE_DIRT,               // 01
    TYPE_BRICKWALL,          // 02
    TYPE_OUTBOX_PRE,         // 03
    TYPE_OUTBOX,             // 04
    TYPE_BOULDER_FALLING,    // 05
    TYPE_STEEL,              // 06
    TYPE_BOULDER,            // 07
    TYPE_DOGE,               // 08
    TYPE_EXPLODE_SPACE_0,    // 09
    TYPE_EXPLODE_SPACE_1,    // 10
    TYPE_EXPLODE_SPACE_2,    // 11
    TYPE_EXPLODE_SPACE_3,    // 12
    TYPE_EXPLODE_SPACE_4,    // 13
    TYPE_EXPLODE_DOGE_0,     // 14
    TYPE_EXPLODE_DOGE_1,     // 15
    TYPE_EXPLODE_DOGE_2,     // 16
    TYPE_EXPLODE_DOGE_3,     // 17
    TYPE_EXPLODE_DOGE_4,     // 18
    TYPE_ROCKFORD_PRE,       // 19
    TYPE_ROCKFORD,           // 20
    TYPE_AMOEBA,             // 21
    TYPE_DRIP,               // 22
    TYPE_DRIP_SPLASH,        // 23
    TYPE___NOTHING,          // 24
    TYPE_EXPLODE_THIS,       // 25
    TYPE_BLANK_THIS,         // 26
    TYPE_DIRT3,              // 27
    TYPE_DIRT2,              // 28
    TYPE_EXPLODE_BLANK_0,    // 29
    TYPE_EXPLODE_BLANK_1,    // 30
    TYPE_EXPLODE_BLANK_2,    // 31
    TYPE_EXPLODE_BLANK_3,    // 32
    TYPE_EXPLODE_BLANK_4,    // 33
    TYPE_DOGE_GRAB,          // 34
    TYPE_DIRT_GRAB,          // 35
    TYPE_DUST,               // 36
    TYPE_DUST2,              // 37
    TYPE_DUST3,              // 38
    TYPE_BOULDER_SHAKE,      // 39
    TYPE_DUST_LEFT,          // 40
    TYPE_DUST2_LEFT,         // 41
    TYPE_DUST3_LEFT,         // 42
    TYPE_DUST_RIGHT,         // 43
    TYPE_DUST2_RIGHT,        // 44
    TYPE_DUST3_RIGHT,        // 45
    TYPE_LAVA,               // 46
    TYPE_WATER,              // 47
    TYPE_EGG,                // 48
    TYPE_ZZAP,               // 49
    TYPE_ZZAP1,              // 50
    TYPE_ROCK,               // 51
    TYPE_DRILL,              // 52
    TYPE_DRILLBODY,          // 53

    // +--> modify Attribute[] @ attribute.c
    // +--> modify Animate[] @ main.c

    TYPE_MAX
};

enum ChName {

    // +---> charSet[] @ characterset.c
    // +CharToType[] @ attribute.c

    CH_BLANK,                   // 000
    CH_DIRTY,                   // 001
    CH_BRICKWALL,               // 002
    CH_DOORCLOSED,              // 003
    CH_DOOROPEN_0,              // 004
    CH_DOOROPEN_1,              // 005
    CH_STEEL,                   // 006
    CH_DIRTY3,                  // 007
    CH_DIRTY2,                  // 008
    CH_EGG,                     // 009
    CH_BOULDER,                 // 010
    CH_ZZAP1,                   // 011
    CH_BOULDER_FALLING,         // 012
    CH_ROCKSEED,                // 013
    CH_DOGE,                    // 014
    CH_DOGE_FALLING,            // 015
    CH_DOGE_4,                  // 016
    CH_BLANK_ALTERNATE_3,       // 017
    CH_____0,                   // 018
    CH_____1,                   // 019
    CH_EXPLODETODOGE0,          // 020
    CH_EXPLODETODOGE1,          // 021
    CH_EXPLODETODOGE2,          // 022
    CH_EXPLODETODOGE3,          // 023
    CH_EXPLODETODOGE4,          // 024
    CH_ROCKYa,                  // 025
    CH_ROCKYb,                  // 026
    CH_ROCKYc,                  // 027
    CH_ROCKYd,                  // 028
    CH_BOULDER2,                // 029
    CH_BOULDER3,                // 030
    CH_BOULDER4,                // 031
    CH_DOGEx1U,                 // 032
    CH_xxROCKFORD,              // 033
    CH_xxROCKFORD_THIS,         // 034
    CH_AMOEBA0,                 // 035
    CH_AMOEBA1,                 // 036
    CH_AMOEBA2,                 // 037
    CH_AMOEBA3,                 // 038
    CH_ZZAP,                    // 039
    CH_STEELWALL_1,             // 040 ??
    CH_DOGE_PULSE_0,            // 041
    CH_DOGE_PULSE_1,            // 042
    CH_DOGE_PULSE_2,            // 043
    CH_DOGE_PULSE_3,            // 044
    CH_DOGE_PULSE_4,            // 045
    CH_DOGE_PULSE_5,            // 046
    CH_DOGE_PULSE_6,            // 047
    CH_DOGE_PULSE_7,            // 048
    CH_DOGE_PULSE_8,            // 049
    CH_DOGE_PULSE_9,            // 050
    CH_DOGE_STATIC,             // 051
    CH_AMOEBA_BLANK,            // 052
    CH_EXPLODE_THIS,            // 053
    CH_BLANK_EXTRA1,            // 054
    CH_BLANK_EXTRA2,            // 055
    CH_BLANK_EXTRA3,            // 056
    CH_BLANK_EXTRA4,            // 057
    CH_BLANK_EXTRA5,            // 058
    CH_BLANK_EXTRA6,            // 059
    CH_BLANK_EXTRA7,            // 060
    CH_BLANK_EXTRA8,            // 061
    CH_UNKNOWN23,               // 062
    CH_EXPLODETOBLANK0,         // 063
    CH_EXPLODETOBLANK1,         // 064
    CH_EXPLODETOBLANK2,         // 065
    CH_EXPLODETOBLANK3,         // 066
    CH_EXPLODETOBLANK4,         // 067
    CH_DOGE_GRAB,               // 068
    CH_DIRT_GRAB,               // 069
    CH_DUST,                    // 070
    CH_DUST2,                   // 071
    CH_DUST3,                   // 072
    CH_BOULDER_SHAKE,           // 073
    CH_DUST_LEFT,               // 074
    CH_DUST2_LEFT,              // 075
    CH_DUST3_LEFT,              // 076
    CH_DUST_RIGHT,              // 077
    CH_DUST2_RIGHT,             // 078
    CH_DUST3_RIGHT,             // 079
    CH_LAVA,                    // 080
    CH_LAVA1,                   // 081
    CH_LAVA2,                   // 082
    CH_LAVA3,                   // 083
    CH_WATER,                   // 084
    CH_WATER1,                  // 085
    CH_WATER2,                  // 086
    CH_WATER3,                  // 087
    CH_EGG2,                    // 088
    CH_ROCKFORD,                // 089
    CH_ROCKFORD_THIS,           // 090
    CH_DRIP,                    // 091
    CH_DRIP1,                   // 092
    CH_DRIP2,                   // 093
    CH_DRIP3,                   // 094
    CH_DRIPX,                   // 095
    CH_DIRT,                    // 096
    CH_DIRT1,                   // 097
    CH_DIRT2,                   // 098
    CH_DIRT3,                   // 099
    CH_DIRT4,                   // 100
    CH_DIRT5,                   // 101
    CH_DIRT6,                   // 102
    CH_DIRT7,                   // 103
    CH_DIRT8,                   // 104
    CH_DIRT9,                   // 105
    CH_DIRTA,                   // 106
    CH_DIRTB,                   // 107
    CH_DIRTC,                   // 108
    CH_DIRTD,                   // 109
    CH_DIRTE,                   // 110
    CH_DIRTF,                   // 111
    CH_ZZAP2,                   // 112
    CH_ROCK0,                   // 113
    CH_ROCK1,                   // 114
    CH_ROCK2,                   // 115
    CH_ROCK3,                   // 116
    CH_ROCK4,                   // 117
    CH_ROCK5,                   // 118
    CH_ROCK6,                   // 119
    CH_ROCK7,                   // 120
    CH_ROCK8,                   // 121
    CH_ROCK9,                   // 122
    CH_ROCKA,                   // 123
    CH_ROCKB,                   // 124
    CH_ROCKC,                   // 125
    CH_ROCKD,                   // 126
    CH_ROCKE,                   // 127
    CH_ROCKF,                   // 128
    CH_DRILL,                   // 129
    CH_DRILL1,                  // 130
    CH_DRILL2,                  // 131
    CH_DRILLBODY,               // 132
    CH_DRILLBODY1,              // 133
    CH_MAX,
};



#define ATT_ROLL 1                        /*  falling objects roll off this object */
#define ATT_KILLS_FLY 2                   /*  firefly/butterfly object touching this is deadly */
#define ATT_EXPLODABLE 4                 /*  object can be destroyed by explosion */
#define ATT_PERMEABLE 8                  /*  amoeba can grow here */
#define ATT_BLANK 16                     /*  blank square */
#define ATT_SQUASHABLE_TO_DOGES 32                /*  objects can fall on this */
#define ATT_GRAB 64                      /*  grabbable object */
#define ATT_EXPLODES 128                 /*  object explodes if killed */
#define ATT_ACTIVE 256                   /*  object requires checking/AI DISABLED!!!*/
#define ATT_SQUASHABLE_TO_BLANKS 512
#define ATT_HARD 1024
#define ATT_EXIT 2048
#define ATT_NOROCKNOISE 4096
#define ATT_LAVA 8192
#define ATT_WATER 16384
#define ATT_SEMIBLANK 32768
#define ATT_PUSH (1<<16)
#define ATT_ROCKFORDYBLANK (1<<17)
#define ATT_DRIP (1<<18)
#define ATT_ROUNDDIRT (1 << 19)
