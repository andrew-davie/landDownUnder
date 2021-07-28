#ifndef __ATTRIBUTE_H
#define __ATTRIBUTE_H

    #include "main.h"
    
extern const int Attribute[];

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
    TYPE_RUBBLE,             // 27
    TYPE_RUBBLE1,            // 28
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
    TYPE_BELT,               // 54
    TYPE_BELT2,              // 55

    // +--> modify Attribute[] @ attribute.c
    // +--> modify Animate[] @ main.c

    TYPE_MAX
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


#endif
