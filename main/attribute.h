    #include "main.h"
    
extern const int Attribute[];
extern const unsigned char CharToType[];

enum ObjectType {

    // +--> modify Attribute[]

    TYPE_SPACE,              // 00
    TYPE_DIRT,               // 01
    TYPE_BRICKWALL,          // 02
    TYPE_MAGICWALL,          // 03
    TYPE_OUTBOX_PRE,         // 04
    TYPE_OUTBOX,             // 05
    TYPE_BOULDER_FALLING,    // 06
    TYPE_STEELWALL,          // 07
    TYPE_FIREFLY,            // 08
    TYPE_BOULDER,            // 09
    TYPE_DOGE,               // 10
    TYPE_EXPLODE_SPACE_0,    // 11
    TYPE_EXPLODE_SPACE_1,    // 12
    TYPE_EXPLODE_SPACE_2,    // 13
    TYPE_EXPLODE_SPACE_3,    // 14
    TYPE_EXPLODE_SPACE_4,    // 15
    TYPE_EXPLODE_DOGE_0,     // 16
    TYPE_EXPLODE_DOGE_1,     // 17
    TYPE_EXPLODE_DOGE_2,     // 18
    TYPE_EXPLODE_DOGE_3,     // 19
    TYPE_EXPLODE_DOGE_4,     // 20
    TYPE_ROCKFORD_PRE,       // 21
    TYPE_BUTTERFLY,          // 22
    TYPE_ROCKFORD,           // 23
    TYPE_AMOEBA,             // 24
    TYPE_DRIP,               // 25
    TYPE_DRIP_SPLASH,        // 26
    TYPE___NOTHING,          // 27
    TYPE___THISFRAME,        // 28
    TYPE_EXPLODE_THIS,       // 29
    TYPE_BLANK_THIS,         // 30
    TYPE_DIRT3,              // 31
    TYPE_DIRT2,              // 32
    TYPE_EXPLODE_BLANK_0,    // 33
    TYPE_EXPLODE_BLANK_1,    // 34
    TYPE_EXPLODE_BLANK_2,    // 35
    TYPE_EXPLODE_BLANK_3,    // 36
    TYPE_EXPLODE_BLANK_4,    // 37
    TYPE_DOGE_GRAB,          // 38
    TYPE_DIRT_GRAB,          // 39
    TYPE_DUST,               // 40
    TYPE_DUST2,              // 41
    TYPE_DUST3,              // 42
    TYPE_BOULDER_SHAKE,      // 43
    TYPE_DUST_LEFT,          // 44
    TYPE_DUST2_LEFT,         // 45
    TYPE_DUST3_LEFT,         // 46
    TYPE_DUST_RIGHT,         // 47
    TYPE_DUST2_RIGHT,        // 48
    TYPE_DUST3_RIGHT,        // 49
    TYPE_LAVA,               // 50
    TYPE_WATER,              // 51
    TYPE_EGG,                // 52
    TYPE_ZZAP,               // 53
    TYPE_ZZAP1,              // 54
    TYPE_ROCK,               // 55
    TYPE_DRILL,              // 56

// +--> modify Attribute[]

    TYPE_MAX
};

enum ChName {

    // see charSet @ characterset.c

    CH_BLANK,                   // 000
    CH_DIRTY,                   // 001
    CH_BRICKWALL,               // 002
    CH_MAGICWALL,               // 003
    CH_DOORCLOSED,              // 004
    CH_DOOROPEN_0,              // 005
    CH_DOOROPEN_1,              // 006
    CH_STEELWALL_0,             // 007
    CH_FIREFLY_0,               // 008
    CH_FIREFLY_1,               // 009
    CH_FIREFLY_2,               // 010
    CH_FIREFLY_3,               // 011
    CH_DIRTY3,                  // 012
    CH_DIRTY2,                  // 013
    CH_EGG,                     // 014
    CH_FIREFLY_7,               // 015
    CH_BOULDER,                 // 016
    CH_ZZAP1,                   // 017
    CH_BOULDER_FALLING,         // 018
    CH_ROCKSEED,                // 019
    CH_DOGE,                    // 020
    CH_DOGE_FALLING_THIS,       // 021
    CH_DOGE_FALLING,            // 022
    CH_DOGE_THIS,               // 023
    CH_DOGE_4,                  // 024
    CH_FIREFLY2,                // 025
    CH_FIREFLY3,                // 026
    CH_BUTTERFLY2U,             // 027
    CH_BUTTERFLY3U,             // 028
    CH_BLANK_ALTERNATE_3,       // 029
    CH_____0,                   // 030
    CH_____1,                   // 031
    CH_EXPLODETODOGE0,          // 032
    CH_EXPLODETODOGE1,          // 033
    CH_EXPLODETODOGE2,          // 034
    CH_EXPLODETODOGE3,          // 035
    CH_EXPLODETODOGE4,          // 036
    CH_ROCKYa,                  // 037
    CH_ROCKYb,                  // 038
    CH_ROCKYc,                  // 039
    CH_ROCKYd,                  // 040
    CH_BOULDER2,                // 041
    CH_BOULDER3,                // 042
    CH_BOULDER4,                // 043
    CH_MAGIC1,                  // 044
    CH_MAGIC2,                  // 045
    CH_MAGIC3,                  // 046
    CH_DOGEx1U,                 // 047
    CH_BUTTERFLY0,              // 048
    CH_BUTTERFLY1,              // 049
    CH_BUTTERFLY2,              // 050
    CH_BUTTERFLY3,              // 051
    CH_BUTTERFLY_4,             // 052
    CH_BUTTERFLY_5,             // 053
    CH_BUTTERFLY_6,             // 054
    CH_BUTTERFLY_7,             // 055
    CH_xxROCKFORD,              // 056
    CH_xxROCKFORD_THIS,         // 057
    CH_AMOEBA0,                 // 058
    CH_AMOEBA1,                 // 059
    CH_AMOEBA2,                 // 060
    CH_AMOEBA3,                 // 061
    CH_ZZAP,                    // 062
    CH_STEELWALL_1,             // 063
    CH_____2,                   // 064
    CH_____3,                   // 065
    CH_____4,                   // 066
    CH_____5,                   // 067
    CH_____6,                   // 068
    CH_____7,                   // 069
    CH_DOGE_PULSE_0,            // 070
    CH_DOGE_PULSE_1,            // 071
    CH_DOGE_PULSE_2,            // 072
    CH_DOGE_PULSE_3,            // 073
    CH_DOGE_PULSE_4,            // 074
    CH_DOGE_PULSE_5,            // 075
    CH_DOGE_PULSE_6,            // 076
    CH_DOGE_PULSE_7,            // 077
    CH_DOGE_PULSE_8,            // 078
    CH_DOGE_PULSE_9,            // 079
    CH_DOGE_STATIC,             // 080
    CH_AMOEBA_BLANK,            // 081
    CH_EXPLODE_THIS,            // 082
    CH_BLANK_EXTRA1,            // 083
    CH_BLANK_EXTRA2,            // 084
    CH_BLANK_EXTRA3,            // 085
    CH_BLANK_EXTRA4,            // 086
    CH_BLANK_EXTRA5,            // 087
    CH_BLANK_EXTRA6,            // 088
    CH_BLANK_EXTRA7,            // 089
    CH_BLANK_EXTRA8,            // 090
    CH_UNKNOWN23,               // 091
    CH_EXPLODETOBLANK0,         // 092
    CH_EXPLODETOBLANK1,         // 093
    CH_EXPLODETOBLANK2,         // 094
    CH_EXPLODETOBLANK3,         // 095
    CH_EXPLODETOBLANK4,         // 096
    CH_DOGE_GRAB,               // 097
    CH_DIRT_GRAB,               // 098
    CH_DUST,                    // 099
    CH_DUST2,                   // 100
    CH_DUST3,                   // 101
    CH_BOULDER_SHAKE,           // 102
    CH_DUST_LEFT,               // 103
    CH_DUST2_LEFT,              // 104
    CH_DUST3_LEFT,              // 105
    CH_DUST_RIGHT,              // 106
    CH_DUST2_RIGHT,             // 107
    CH_DUST3_RIGHT,             // 108
    CH_LAVA,                    // 109
    CH_LAVA1,                   // 110
    CH_LAVA2,                   // 111
    CH_LAVA3,                   // 112
    CH_WATER,                   // 113
    CH_WATER1,                  // 114
    CH_WATER2,                  // 115
    CH_WATER3,                  // 116
    CH_EGG2,                    // 117
    CH_ROCKFORD,                // 118
    CH_ROCKFORD_THIS,           // 119
    CH_DRIP,                    // 120
    CH_DRIP1,                   // 121
    CH_DRIP2,                   // 122
    CH_DRIP3,                   // 123
    CH_DRIPX,                   // 124
    CH_DIRT,                    // 125
    CH_DIRT1,                   // 126
    CH_DIRT2,                   // 127
    CH_DIRT3,                   // 128
    CH_DIRT4,                   // 129
    CH_DIRT5,                   // 130
    CH_DIRT6,                   // 131
    CH_DIRT7,                   // 132
    CH_DIRT8,                   // 133
    CH_DIRT9,                   // 134
    CH_DIRTA,                   // 135
    CH_DIRTB,                   // 136
    CH_DIRTC,                   // 137
    CH_DIRTD,                   // 138
    CH_DIRTE,                   // 139
    CH_DIRTF,                   // 140
    CH_ZZAP2,                   // 141
    CH_ROCK0,                   // 142
    CH_ROCK1,                   // 143
    CH_ROCK2,                   // 144
    CH_ROCK3,                   // 145
    CH_ROCK4,                   // 146
    CH_ROCK5,                   // 147
    CH_ROCK6,                   // 148
    CH_ROCK7,                   // 149
    CH_ROCK8,                   // 150
    CH_ROCK9,                   // 151
    CH_ROCKA,                   // 152
    CH_ROCKB,                   // 153
    CH_ROCKC,                   // 154
    CH_ROCKD,                   // 155
    CH_ROCKE,                   // 156
    CH_ROCKF,                   // 157
    CH_DRILL,                   // 158
    CH_DRILL1,                  // 159
    CH_DRILL2,                  // 160

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
