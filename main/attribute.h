    #include "main.h"
    
extern const int Attribute[];
extern const unsigned char CharToType[];

enum ObjectType {

    // +--> modify Attribute[]

    TYPE_SPACE,              // 0
    TYPE_DIRT,               // 1
    TYPE_BRICKWALL,          // 2
    TYPE_MAGICWALL,          // 3
    TYPE_OUTBOX_PRE,         // 4
    TYPE_OUTBOX,             // 5
    TYPE_BOULDER_FALLING,    // 6
    TYPE_STEELWALL,          // 7
    TYPE_FIREFLY,            // 8
    TYPE_BOULDER,            // 9
    TYPE_DIAMOND,            // 10
    TYPE_EXPLODE_SPACE_0,    // 11
    TYPE_EXPLODE_SPACE_1,    // 12
    TYPE_EXPLODE_SPACE_2,    // 13
    TYPE_EXPLODE_SPACE_3,    // 14
    TYPE_EXPLODE_SPACE_4,    // 15
    TYPE_EXPLODE_DIAMOND_0,  // 16
    TYPE_EXPLODE_DIAMOND_1,  // 17
    TYPE_EXPLODE_DIAMOND_2,  // 18
    TYPE_EXPLODE_DIAMOND_3,  // 19
    TYPE_EXPLODE_DIAMOND_4,  // 20
    TYPE_ROCKFORD_PRE,       // 21
    TYPE_BUTTERFLY,          // 22
    TYPE_ROCKFORD,           // 23
    TYPE_AMOEBA,             // 24
    TYPE_DRIP,               // 25
    TYPE_DRIP_SPLASH,        // 26
    TYPE_DIAMOND_PULSE_0,    // 27  /delete
    TYPE_DIAMOND_PULSE_1,    // 28  /delete
    TYPE_DIAMOND_PULSE_2,    // 29  /delete
    TYPE_DIAMOND_PULSE_3,    // 30  /delete
    TYPE_DIAMOND_PULSE_4,    // 31  /delete
    TYPE_DIAMOND_PULSE_5,    // 32  /delete
    TYPE_DIAMOND_PULSE_6,    // 33  /delete
    TYPE_DIAMOND_PULSE_7,    // 34  /delete
    TYPE_DIAMOND_PULSE_8,    // 35  /delete
    TYPE_DIAMOND_PULSE_9,    // 36  /delete
    TYPE_DIAMOND_PULSE_10,   // 37  /delete
    TYPE___NOTHING,          // 38
    TYPE___THISFRAME,        // 39
    TYPE_EXPLODE_THIS,       // 40
    TYPE_BLANK_THIS,         // 41
    TYPE_DIRT3,              // 42
    TYPE_DIRT2,              // 43
    TYPE_EXPLODE_BLANK_0,    // 44
    TYPE_EXPLODE_BLANK_1,    // 45
    TYPE_EXPLODE_BLANK_2,    // 46
    TYPE_EXPLODE_BLANK_3,    // 47
    TYPE_EXPLODE_BLANK_4,    // 48
    TYPE_DIAMOND_GRAB,       // 49
    TYPE_DIRT_GRAB,          // 50
    TYPE_DUST,               // 51
    TYPE_DUST2,              // 52
    TYPE_DUST3,              // 53
    TYPE_BOULDER_SHAKE,      // 54
    TYPE_DUST_LEFT,          // 55
    TYPE_DUST2_LEFT,         // 56
    TYPE_DUST3_LEFT,         // 57
    TYPE_DUST_RIGHT,         // 58
    TYPE_DUST2_RIGHT,        // 59
    TYPE_DUST3_RIGHT,        // 60
    TYPE_LAVA,               // 61
    TYPE_WATER,              // 62
#if ENABLE_EGG
    TYPE_EGG,                // 63
#endif

    TYPE_ZZAP,               // 64          UP SPIRAL
    TYPE_ZZAP1,              // 65          DOWN SPIRAL
    TYPE_ROCK,               // 66          CONGLOMERATE

    TYPE_DRILL,              // 67          DRILL

// +--> modify Attribute[]

    TYPE_MAX
};

enum ChName {

    // see charSet @ characterset.c

    CH_BLANK,                   // 0
    CH_DIRTY,                   // 1
    CH_BRICKWALL,               // 2
    CH_MAGICWALL,               // 3       // magic wall
    CH_DOORCLOSED,              // 4       exit door
    CH_DOOROPEN_0,              // 5
    CH_DOOROPEN_1,              // 6
    CH_STEELWALL_0,             // 7
    CH_FIREFLY_0,               // 8
    CH_FIREFLY_1,               // 9
    CH_FIREFLY_2,               // 10
    CH_FIREFLY_3,               // 11
    CH_DIRTY3,                  // 12
    CH_DIRTY2,                  // 13
#if ENABLE_EGG
    CH_EGG,                     // 14
#else
    CH_____8,
#endif
    CH_FIREFLY_7,               // 15 unused
    CH_BOULDER,                 // 16
    CH_ZZAP1,                   // 17       TYPE_ZZAP1
    CH_BOULDER_FALLING,         // 18       [+2]
    CH_ROCKSEED,                // 19
    CH_DIAMOND,                 // 20
    CH_DIAMOND_FALLING_THIS,    // 21       [+1]    scanned this frame
    CH_DIAMOND_FALLING,         // 22       [+2]
    CH_DIAMOND_THIS,            // 23
    CH_DIAMOND_4,               // 24
    CH_FIREFLY2,                // 25
    CH_FIREFLY3,                // 26
    CH_BUTTERFLY2U,             // 27
    CH_BUTTERFLY3U,             // 28
    CH_BLANK_ALTERNATE_3,       // 29
    CH_____0,                   // 30
    CH_____1, // CH_UNCOVER1,   // 31
    CH_EXPLODETODIAMOND0,       // 32
    CH_EXPLODETODIAMOND1,       // 33
    CH_EXPLODETODIAMOND2,       // 34
    CH_EXPLODETODIAMOND3,       // 35
    CH_EXPLODETODIAMOND4,       // 36
    CH_ROCKYa,                  // 37
    CH_ROCKYb,                  // 38
    CH_ROCKYc,                  // 39
    CH_ROCKYd,                  // 40
    CH_BOULDER2,                // 41
    CH_BOULDER3,                // 42
    CH_BOULDER4,                // 43
    CH_MAGIC1,                  // 44
    CH_MAGIC2,                  // 45
    CH_MAGIC3,                  // 46
    CH_DIAMONDx1U,              // 47 pulse diamond
    CH_BUTTERFLY0,              // 48
    CH_BUTTERFLY1,              // 49
    CH_BUTTERFLY2,              // 50
    CH_BUTTERFLY3,              // 51
    CH_BUTTERFLY_4,             // 52
    CH_BUTTERFLY_5,             // 53
    CH_BUTTERFLY_6,             // 54
    CH_BUTTERFLY_7,             // 55
    CH_xxROCKFORD,                // 56         unused
    CH_xxROCKFORD_THIS,           // 57       unused scanned this frame
    CH_AMOEBA0,                 // 58
    CH_AMOEBA1,                 // 59
    CH_AMOEBA2,                 // 60
    CH_AMOEBA3,                 // 61
    CH_ZZAP,                    // 62
    CH_STEELWALL_1,             // 63
    CH_____2, // CH_UNCOVER0b,  // 64 Objects before this line can be generated via cave data (0-63)
    CH_____3, // CH_UNCOVER1b,  // 65
    CH_____4, // CH_UNCOVER2b,  // 66
    CH_____5, // CH_UNCOVER3b,  // 67
    CH_____6, // CH_UNCOVER4b,  // 68
    CH_____7, // CH_UNCOVER5b,  // 69
    CH_DIAMOND_PULSE_0,         // 70
    CH_DIAMOND_PULSE_1,         // 71
    CH_DIAMOND_PULSE_2,         // 72
    CH_DIAMOND_PULSE_3,         // 73
    CH_DIAMOND_PULSE_4,         // 74
    CH_DIAMOND_PULSE_5,         // 75
    CH_DIAMOND_PULSE_6,         // 76
    CH_DIAMOND_PULSE_7,         // 77     /delete
    CH_DIAMOND_PULSE_8,         // 78     /delete
    CH_DIAMOND_PULSE_9,         // 79     /delete
    CH_DIAMOND_STATIC,          // 80  (CAN SWITCH ANIMATIONS ON THIS!)
    CH_AMOEBA_BLANK,            // 81   ???
    CH_EXPLODE_THIS,            // 82   OBJECT EXPLODES NEXT FRAME
    CH_BLANK_EXTRA1,            // 83
    CH_BLANK_EXTRA2,            // 84
    CH_BLANK_EXTRA3,            // 85
    CH_BLANK_EXTRA4,            // 86
    CH_BLANK_EXTRA5,            // 86
    CH_BLANK_EXTRA6,            // 87
    CH_BLANK_EXTRA7,            // 88
    CH_BLANK_EXTRA8,            // 90
    CH_UNKNOWN23,               // 91   ???
    CH_EXPLODETOBLANK0,         // 92
    CH_EXPLODETOBLANK1,         // 93
    CH_EXPLODETOBLANK2,         // 94
    CH_EXPLODETOBLANK3,         // 95
    CH_EXPLODETOBLANK4,         // 96
    CH_DIAMOND_GRAB,            // 97
    CH_DIRT_GRAB,               // 98
    CH_DUST,                    // 99
    CH_DUST2,                   // 100
    CH_DUST3,                   // 101
    CH_BOULDER_SHAKE,           // 102
    CH_DUST_LEFT,               // 103
    CH_DUST2_LEFT,              // 104
    CH_DUST3_LEFT,              // 105
    CH_DUST_RIGHT,              // 106      (dummy)
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
#if ENABLE_EGG
    CH_EGG2,                    // 117
#else
    CH_____9,
#endif
    
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

    CH_ROCK0,                // 142
    CH_ROCK1,                // 143
    CH_ROCK2,                // 144
    CH_ROCK3,                // 145
    CH_ROCK4,                // 146
    CH_ROCK5,                // 147
    CH_ROCK6,                // 148
    CH_ROCK7,                // 149
    CH_ROCK8,                // 150
    CH_ROCK9,                // 151
    CH_ROCKA,                // 152
    CH_ROCKB,                // 153
    CH_ROCKC,                // 154
    CH_ROCKD,                // 155
    CH_ROCKE,                // 156
    CH_ROCKF,                // 157

    CH_DRILL,                // 158
    CH_DRILL1,               // 159
    CH_DRILL2                // 160

};



#define ATT_ROLL 1                        /*  falling objects roll off this object */
#define ATT_KILLS_FLY 2                   /*  firefly/butterfly object touching this is deadly */
#define ATT_EXPLODABLE 4                 /*  object can be destroyed by explosion */
#define ATT_PERMEABLE 8                  /*  amoeba can grow here */
#define ATT_BLANK 16                     /*  blank square */
#define ATT_SQUASHABLE_TO_DIAMONDS 32                /*  objects can fall on this */
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
