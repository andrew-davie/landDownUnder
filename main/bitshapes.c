#include <stdbool.h>
#include "main.h"
#include "bitshapes.h"
#include "bitpatterns.h"


const signed char animDefault[] = {
    FRAME_ADJUST, 0,0, 0,0,
    FRAME_STAND, 255,
};

const signed char animShake[] = {
    FRAME_ADJUST, 0,0,0,0,
    FRAME_SHAKE,10,
    FRAME_SHAKE2,10,
    FRAME_SHAKE3,10,
//    FRAME_LOOP,
    FRAME_STOP,
};

const signed char animWipeHair[] = {
    FRAME_HAIR2, 4,
    FRAME_HAIR, 4,
    FRAME_HAIR2, 4,
    FRAME_HAIR, 4,
    FRAME_STOP,
};

const signed char animHoldBoulder[] = {
    FRAME_HOLD_BOULDER_0, 10,
    FRAME_LOOP,
    FRAME_HOLD_BOULDER_1, 7,
    FRAME_STOP,
};

const signed char animJump[] = {
    FRAME_ADJUST, 0,0, 0,0,
    FRAME_JUMP, 5,
    FRAME_LOOP,
    FRAME_STOP,
};

const signed char animPush[] = {
    FRAME_PUSH, 14,
    FRAME_PUSH2, 14,
    FRAME_LOOP,
    FRAME_STOP,
};

const signed char animImpatient[] = {
    FRAME_ARMSCROSSED, 50,
    FRAME_IMPATIENT, 10,
    FRAME_IMPATIENT2, 10,
    FRAME_IMPATIENT, 10,
    FRAME_IMPATIENT2, 10,
    FRAME_IMPATIENT, 10,
    FRAME_IMPATIENT2, 10,
    FRAME_IMPATIENT, 10,
    FRAME_IMPATIENT2, 10,
    FRAME_STOP,
};

const signed char animLook[] = {    
    FRAME_ADJUST, -1,0, 0,0,
    FRAME_LOOK1, 5,
    FRAME_ADJUST, -1,0, 0,0,
    FRAME_LOOK2, 20,
    FRAME_ADJUST, -1,0, 0,0,
    FRAME_LOOK1, 5,
    FRAME_STOP,
};

const signed char animTurn[] = {
    FRAME_LOOK1, 8,
    FRAME_LOOK2, 8,
    FRAME_FLIP,
    FRAME_STOP,
};


const signed char animBlink[] = {    
    FRAME_BLINK, 6,
    FRAME_STOP,
};


const signed char animShades[] = {
    FRAME_SHADES_ARM, 20,
    FRAME_SHADES, 125,
    FRAME_SHADES_ARM, 25,
    FRAME_STOP,
};


const signed char animWalk[] = {
    FRAME_ADJUST, -13,1, -5,0,
    FRAME_WALK1, 1,
    FRAME_ADJUST, -12,2, -5,1,
    FRAME_WALK1, 1,
    FRAME_ADJUST, -11,2, -4,1,
    FRAME_WALK2, 1,
    FRAME_ADJUST, -10,1, -4,0,
    FRAME_WALK2, 1,
    FRAME_ADJUST, -9,1, -3,0,
    FRAME_WALK2, 1,
    FRAME_ADJUST, -8,1, -3,0,
    FRAME_WALK3, 1,
    FRAME_ADJUST, -7,1, -2,0,
    FRAME_WALK3, 1,
    FRAME_ADJUST, -4,0, -2,0,
    FRAME_WALK4, 1,
    FRAME_ADJUST, -3,0, -1,0,
    FRAME_WALK4, 1,
    FRAME_ADJUST, -1,0, -1,0,
    FRAME_WALK4, 1,
    FRAME_STOP,
};

const signed char animDie[] = {
    FRAME_SHAKE,8,
    FRAME_HOLD_BOULDER_1,40,
    FRAME_STOP,
};


#define YSPAN (PIECE_DEPTH)

const signed char animWalkVertical[] = {
    FRAME_ADJUST, 0,-YSPAN*10/GAMESPEED, -1,-9*10/GAMESPEED,
    FRAME_WALK1, 1,
    FRAME_ADJUST, 0,-YSPAN*9/GAMESPEED, -1,-9*9/GAMESPEED,
    FRAME_WALK1, 1,
    FRAME_ADJUST, 0,-YSPAN*8/GAMESPEED, -1,-9*8/GAMESPEED,
    FRAME_WALK2, 1,
    FRAME_ADJUST, 0,-YSPAN*7/GAMESPEED, -1,-9*7/GAMESPEED,
    FRAME_WALK2, 1,
    FRAME_ADJUST, 0,-YSPAN*6/GAMESPEED, -1,-9*6/GAMESPEED,
    FRAME_WALK2, 1,
    FRAME_ADJUST, 0,-YSPAN*5/GAMESPEED, -1,-9*5/GAMESPEED,
    FRAME_WALK3, 1,
    FRAME_ADJUST, 0,-YSPAN*4/GAMESPEED, -1,-9*4/GAMESPEED,
    FRAME_WALK3, 1,
    FRAME_ADJUST, 2,-YSPAN*3/GAMESPEED, -2,-9*3/GAMESPEED,
    FRAME_WALK4, 1,
    FRAME_ADJUST, 2,-YSPAN*2/GAMESPEED, -1,-9*2/GAMESPEED,
    FRAME_WALK4, 1,
    FRAME_ADJUST, 2,-YSPAN*1/GAMESPEED, -1,-9*1/GAMESPEED,
    FRAME_WALK4, 1,
    FRAME_STOP,
};

const signed char animWalkVerticalDown[] = {
    FRAME_ADJUST, 0,YSPAN*10/GAMESPEED, -1,+9*10/GAMESPEED,
    FRAME_WALK1, 1,
    FRAME_ADJUST, 0,YSPAN*9/GAMESPEED, -1,+9*9/GAMESPEED,
    FRAME_WALK1, 1,
    FRAME_ADJUST, 0,YSPAN*8/GAMESPEED, -1,+9*8/GAMESPEED,
    FRAME_WALK2, 1,
    FRAME_ADJUST, 0,YSPAN*7/GAMESPEED, -1,+9*7/GAMESPEED,
    FRAME_WALK2, 1,
    FRAME_ADJUST, 0,YSPAN*6/GAMESPEED, -1,+9*6/GAMESPEED,
    FRAME_WALK2, 1,
    FRAME_ADJUST, 0,YSPAN*5/GAMESPEED, -1,+9*5/GAMESPEED,
    FRAME_WALK3, 1,
    FRAME_ADJUST, 0,YSPAN*4/GAMESPEED, -1,+9*4/GAMESPEED,
    FRAME_WALK3, 1,
    FRAME_ADJUST, 2,YSPAN*3/GAMESPEED, -2,+9*3/GAMESPEED,
    FRAME_WALK4, 1,
    FRAME_ADJUST, 2,YSPAN*2/GAMESPEED, -1,+9*2/GAMESPEED,
    FRAME_WALK4, 1,
    FRAME_ADJUST, 2,YSPAN*1/GAMESPEED, -1,-9*1/GAMESPEED,
    FRAME_WALK4, 1,
    FRAME_STOP,
};

const signed char animSnatch[] = {
    FRAME_ADJUST, 7,0, 2,0,
    FRAME_PUSH, 10,
    FRAME_ADJUST, 0,0, 0,0,
    FRAME_STOP,
};

const signed char animSnatchDown[] = {
    FRAME_ADJUST, 0,-4, 0,-1,
    FRAME_SNATCH_DOWN, 10,
    FRAME_ADJUST, 0,0, 0,0,
    FRAME_STOP,
};


const signed char animSnatchUp[] = {
    FRAME_ADJUST, 0,4, 0,2,
    FRAME_HOLD_BOULDER_0, 10,
    FRAME_ADJUST, 0,0, 0,0,
    FRAME_STOP,
};


const signed char animSkeleton[] = {
    FRAME_SKELETON, 3,
    FRAME_STAND, 3,
    FRAME_SKELETON, 3,
    FRAME_STAND, 3,
    FRAME_SKELETON, 3,
    FRAME_STAND, 3,
    FRAME_SKELETON, 3,
    FRAME_STAND, 3,
    FRAME_SKELETON, 3,
    FRAME_STAND, 3,
    FRAME_SKELETON, 3,
    FRAME_STAND, 3,

    FRAME_SKELETON4, 8,
    FRAME_SKELETON, 8,
    FRAME_SKELETON4, 8,
    FRAME_SKELETON, 8,
    FRAME_SKELETON4, 8,
    FRAME_SKELETON, 8,

    FRAME_SKELETON3, 5,
    FRAME_SKELETON2, 5,
    FRAME_SKELETON5, 5,

    FRAME_BLANK, 255,
    // FRAME_LOOP,         // <?
};


const signed char animBlank[] = {
    FRAME_BLANK, 255,
    // FRAME_LOOP,         // <?
};


#define DX 6

const signed char animStartup[] = {
    FRAME_SKELETON5, 8,
    FRAME_SKELETON2, 8,
    FRAME_SKELETON3, 8,
    FRAME_SKELETON, 15,


    FRAME_STAND,DX,
    FRAME_SKELETON, DX,
    FRAME_STAND,DX,
    FRAME_SKELETON, DX,
    FRAME_STAND,DX,
    FRAME_SKELETON, DX,
    FRAME_STAND,DX,
    FRAME_SKELETON, DX,
    // FRAME_STAND, 255,
    FRAME_STOP,         // <?
};

const signed char animArmsCrossed[] = {
    FRAME_ARMSCROSSED, 80,
    FRAME_STOP,
};


const signed char animDrip[] = {
    FRAME_IMPATIENT,25,
    FRAME_STAND,10,
    FRAME_HAIR2, 6,
    FRAME_HAIR, 6,
    FRAME_HAIR2, 6,
    FRAME_HAIR, 6,
    FRAME_STOP,
};

const signed char animDrip2[] = {
    FRAME_IMPATIENT,25,
    FRAME_STAND,10,
    FRAME_ADJUST, -1,0, 0,0,
    FRAME_LOOK1, 5,
    FRAME_ADJUST, -1,0, 0,0,
    FRAME_LOOK2, 15,
    FRAME_ADJUST, -1,0, 0,0,
    FRAME_LOOK1, 5,
    FRAME_ADJUST, 0,0, 0,0,
    FRAME_ARMSCROSSED, 90,
    FRAME_STOP,
};




const signed char *animIndex[] = {
    &animDefault[0],              // 0
    &animHoldBoulder[0],          // 1
    &animWipeHair[0],             // 2
    &animJump[0],                 // 3
    &animPush[0],                 // 4
    &animImpatient[0],            // 5
    &animLook[0],                 // 6
    &animBlink[0],                // 7
    &animShades[0],               // 8
    &animWalk[0],                 // 9
    &animDie[0],                  // 10
    &animWalkVertical[0],         // 11
    &animTurn[0],                 // 12
    &animWalkVerticalDown[0],     // 13
    &animSnatch[0],               // 14
    &animSnatchDown[0],           // 15
    &animSnatchUp[0],             // 16
    &animSkeleton[0],             // 17
    &animBlank[0],                // 18
    &animStartup[0],              // 19
    &animArmsCrossed[0],          // 20
    &animDrip[0],                 // 21
    &animDrip2[0],                // 22
    &animShake[0],                // 23
};




int playerAnimationID = ID_STAND;
const signed char *playerAnimation = &animDefault[0];
const signed char *playerAnimationLoop = &animDefault[0];
unsigned int playerAnimationCount = 0;




#define HAIR 0x28
#define SKIN 0x48
#define TOP1 0xA6
#define TOP2 0xA4
#define BOOT 0x24
#define PANT 0x04 /*B8*/
#define BELT 0x08
#define SOLE 0x08
#define ____ 0,
#define BONE 0x08

#define PNT2 0x04

const signed char playerBigSprite[][2 + 23 * 4 + 2+ 18] = {

// Format
// X, Y offsets
// [GRP0, GRP1, COLUP0, COLUP1,]      * (PIECE_DEPTH+0)

{   // FRAME_STAND= 0

    2+0, 0,



    ____XXXX ________  HAIR, ____      //00
    ___XXXXX ________  HAIR, ____      //00
    __XXXXXX X_______  HAIR, HAIR,     //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX XX______  SKIN, HAIR,     //03
    __XX_X_X _X______  SKIN, HAIR,     //04
    __XXXXXX _X______  SKIN, HAIR,     //05
    __XXXXX_ ________  SKIN, ____      //06
    ___XX_X_ ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX ________  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX X_______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ XX______  TOP1, TOP1,     //13
    ___XXXX_ ________  TOP2, ____      //14
    XX_XXXX_ XX______  BELT, BELT,     //15
    XX_XXXXX XX______  PANT, PANT,     //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21

    -4,0,    // x,y

    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ___X____  TOP2,    // 2
    __XXX___  TOP1,    // 3
    _XXXX___  TOP2,    // 4
    __XX_X__  TOP1,    // 5
    __XX____  TOP2,    // 6
    __X_X___  PNT2,    // 7
    __X_X___  BOOT,    // 8

    },



{   // FRAME_HOLD_BOULDER_0 = 1

    -3+0, 0,

    ______XX _XXX__XX  HAIR, SKIN,     //00
    ______XX _XXXX_XX  HAIR, SKIN,     //00
    ________ XXXXXX__  HAIR, HAIR,     //01
    _____XX_ XXXXXXXX  TOP1, SKIN,      //02
    _____XX_ XXXXX_XX  TOP1, SKIN,      //03
    _____XX_ X_X_X_XX  TOP1, SKIN,      //04
    _____XX_ XXXXX_XX  TOP1, SKIN,      //05
    _____XX_ XX_XX_XX  TOP1, SKIN,      //06
    _____XX_ XX_X__XX  TOP1, SKIN,      //07
    _____XXX _XXX_XX_  TOP1, SKIN,      //08
    ______XX XXXXXXX_  TOP1, TOP1,     //09
    _______X XXXXXXX_  TOP2, TOP2,     //10
    _______X XXXXXX__  TOP1, TOP1,     //11
    ________ XXXXX___  TOP2, ____      //12
    ________ XXXX____  TOP1, ____      //13
    ________ XXXX____  TOP2, ____      //14
    ________ XXXX____  BELT, ____      //15
    _______X XXXXX___  PANT, ____      //16
    _______X XXXXX___  PANT, ____      //17
    _______X X__XX___  PANT, ____      //18
    ______XX X__XXX__  BOOT, BOOT,     //19
    ______XX X___XX__  BOOT, BOOT,     //20
    ______XX X___XXX_  SOLE, SOLE,     //21


    -4,0,    // x,y

    _X_XX_X_  HAIR,    // 0
    _X_X_X__  SKIN,    // 1
    _X___X__  TOP2,    // 2
    _XXXX___  TOP1,    // 3
    __XXX___  TOP2,    // 4
    __XX____  TOP1,    // 5
    __XX____  TOP2,    // 6
    __X_X___  PNT2,    // 7
    _XX_X___  BOOT,    // 8

},


{   // FRAME_HOLD_BOULDER_1 = 2

    2+0, 0,   // X,Y OFFSET

    _XX_XXXX _XX_____  HAIR, BELT,     //00
    _XX_XXXX _XX_____  HAIR, BELT,     //00
    ___XXXXX ________  HAIR, HAIR,     //01
    XX_XXXXX _XX_____  SKIN, SKIN,     //02
    XX_X_X_X _XX_____  SKIN, SKIN,     //03
    XX_XXXXX _XX_____  SKIN, SKIN,     //04
    XX_XX_XX _XX_____  SKIN, SKIN,     //05
    XX_XXXXX _XX_____  SKIN, SKIN,     //06
    XXX_XXX_ _XX_____  SKIN, SKIN,     //07
    _XXXXXXX XX______  SKIN, SKIN,     //08
    __XXXXXX XX______  TOP1, TOP1,     //09
    __XXXXXX X_______  TOP2, TOP2,     //10
    ___XXXXX ________  TOP1, ____      //11
    ___XXXX_ ________  TOP2, ____      //12
    ___XXXX_ ________  TOP1, ____      //13
    ___XXXX_ ________  TOP2, ____      //14
    ___XXXX_ ________  BELT, ____      //15
    ___XXXX_ ________  PANT, ____      //16
    ___XXXXX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XXX_XX X_______  BOOT, BOOT,     //19
    __XXX__X X_______  BOOT, BOOT,     //20
    __XXX__X XX______  SOLE, SOLE,     //21

    -4,0,    // x,y

    _X_XX_X_  HAIR,    // 0
    _X_X_X__  SKIN,    // 1
    _X___X__  TOP2,    // 2
    _XXXX___  TOP1,    // 3
    __XXX___  TOP2,    // 4
    __XX____  TOP1,    // 5
    __XX____  TOP2,    // 6
    __X_X___  PNT2,    // 7
    _XX_X___  BOOT,    // 8

},


{   // FRAME_WIPE_HAIR = 3

    2+0, 0,

    ____XXX_ ________  HAIR, ____      //00
    ___XXXX_ ________  HAIR, ____      //00
    __XXXXXX ________  HAIR, ____      //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX XX______  SKIN, HAIR,     //03
    __X_X_X_ XX______  SKIN, SKIN,     //04
    __XXXXX_ XX______  SKIN, TOP1,     //05
    __XXXXX_ XX______  SKIN, TOP2,     //06
    ___X_XX_ XX______  SKIN, TOP1,     //07
    ___XXXX_ XX______  SKIN, TOP2,     //08
    __XXXXXX XX______  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX ________  TOP1, ____      //11
    XX_XXXX_ ________  TOP2, ____      //12
    XX_XXXX_ ________  TOP1, ____      //13
    ___XXXX_ ________  TOP2, ____      //14
    XX_XXXX_ ________  BELT, ____      //15
    XX_XXXXX ________  PANT, ____      //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, BOOT,     //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21

    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XXX_  SKIN,    // 1
    ____X_X_  TOP2,    // 2
    __XXXXX_  TOP1,    // 3
    _X_XXX__  TOP2,    // 4
    _X_XX___  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

},

{   // FRAME_JUMP = 4

    2+0, 0,

    ________ ________  HAIR, ____      //08
    _____XXX X_______  HAIR, ____      //08
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XXX_____  HAIR, HAIR,     //01
    ___XXXXX X_______  HAIR, SKIN,     //02
    ___XXXXX X_______  SKIN, SKIN,     //03
    ___XX_X_ X_______  SKIN, SKIN,     //04
    ___XXXXX X_______  SKIN, SKIN,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    ___XXXXX ________  TOP1, ____      //09
    __XXXXXX ________  TOP2, ____      //10
    _XXXXXXX X_______  TOP1, TOP1,     //11
    _XXXXXXX XX______  TOP2, TOP2,     //12
    _XXX_XXX XX______  TOP1, TOP1,     //13
    _XXX_XX_ ________  TOP2, TOP2,     //14
    __XXXXX_ XX______  BELT, BELT,     //15
    ___XXXXX ________  PANT, PANT,     //16
    __XXX_XX ________  PANT, PANT,     //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21


    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    ___XXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    _X_XXX__  TOP1,    // 5
    ___XX___  TOP2,    // 6
    __X__X__  PNT2,    // 7
    __X__X__  BOOT,    // 8

},


{   // FRAME_HAIR = 5

    2+0, 0,

    ____XXX_ ________  HAIR, ____      //00
    ___XXXXX ________  HAIR, ____      //00
    __XXXXXX X_______  HAIR, ____      //01
    __XXXXXX X_______  HAIR, ____      //02
    __XXXXXX ________  SKIN, ____      //03
    __XX_X_X ________  SKIN, ____      //04
    __XXXXXX ________  SKIN, ____      //05
    __XXXXXX ________  SKIN, ____      //06
    ___XX_X_ ________  SKIN, ____      //07
    ____XXX_ ________  SKIN, ____      //08
    __XXXXXX X_______  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX XX______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ XX______  TOP1, TOP1,     //13
    ___XXXX_ ________  TOP2, ____      //14
    XX_XXXX_ XX______  BELT, BELT,     //15
    XX_XXXXX XX______  PANT, PANT,     //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21


    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    ___XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

},

{   // FRAME_PUSH = 6

    1, 0,

    ________ XXXX____  HAIR, HAIR,     //00
    _______X XXXXX___  HAIR, HAIR,     //00
    ______XX XXXXXX__  HAIR, HAIR,     //01
    ______XX XXXXXXX_  HAIR, HAIR,     //02
    ______XX XXXX__X_ HAIR, SKIN,     //03
    ______XX XX_X____  SKIN, SKIN,     //04
    ______XX XXXX____  SKIN, SKIN,     //05
    ______XX XX______  SKIN, SKIN,     //06
    _______X XXX_____  SKIN, SKIN,     //07
    _____XXX XXXXXXXX  TOP2, TOP2,     //08
    _____XXX XXX____X TOP1, TOP1,     //09
    ____XXXX XXXXXXXX  TOP2, TOP2,     //10
    ____XXXX XXXXXXX_  TOP1, TOP1,     //11
    ____XXXX XX______  TOP2, TOP2,     //12
    ___XXXXX ________  TOP1, ____      //13
    ___XXXXX ________  TOP2, ____      //14
    ___XXXXX ________  BELT, ____      //15
    __XXXXXX ________  PANT, ____      //16
    __XXX_XX X_______  PANT, PANT,     //17
    _XXX___X XX______  PANT, PANT,     //18
    XXX_____ XX______  BOOT, BOOT,     //19
    XX______ XX______  BOOT, BOOT,     //20
    XXX_____ XXX_____  SOLE, SOLE,     //21

    -5,0,    // x,y

    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ___X__XX  TOP2,    // 2
    __XXXXXX  TOP1,    // 3
    __XXX___  TOP2,    // 4
    __XX____  TOP1,    // 5
    _XXX____  TOP2,    // 6
    X___X___  PNT2,    // 7
    XX__XX__  BOOT,    // 8


},


{   // FRAME_PUSH2 = 7

    2, 0,

    ________ XXXX____  HAIR, HAIR,     //00
    _______X XXXXX___  HAIR, HAIR,     //00
    ______XX XXXXXX__  HAIR, HAIR,     //01
    ______XX XXXXXXX_  HAIR, HAIR,     //02
    ______XX XXXX__X_ HAIR, SKIN,     //03
    ______XX XX_X____  SKIN, SKIN,     //04
    ______XX XXXX____  SKIN, SKIN,     //05
    ______XX XX______  SKIN, SKIN,     //06
    _______X XXX_____  SKIN, SKIN,     //07
    _____XXX XXXXXXXX  TOP2, TOP2,     //08
    _____XXX XXX____X TOP1, TOP1,     //09
    ____XXXX XXXXXXXX  TOP2, TOP2,     //10
    ____XXXX XXXXXXX_  TOP1, TOP1,     //11
    ____XXXX XX______  TOP2, TOP2,     //12
    ___XXXXX ________  TOP1, ____      //13
    ___XXXXX ________  TOP2, ____      //14
    ___XXXXX ________  BELT, ____      //15
    ____XXXX ________  PANT, ____      //16
    ____XXXX ________  PANT, ____      //17
    _____XXX ________  PANT, ____      //18
    ____XXXX ________  BOOT, ____      //19
    _____XX_ ________  BOOT, ____      //20
    _____XXX ________  SOLE, ____      //21

    -4,0,    // x,y

    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ___X__XX  TOP2,    // 2
    __XXXXXX  TOP1,    // 3
    __XXX___  TOP2,    // 4
    __XX____  TOP1,    // 5
    __XX____  TOP2,    // 6
    _XX_____  PNT2,    // 7
    _XXX____  BOOT,    // 8

},

{   // FRAME_HAIR2 = 8

    2+0, 0,

    ____XXX_ ________  HAIR, HAIR,     //00
    ___XXXXX ________  HAIR, HAIR,     //00
    __XXXXXX ________  HAIR, HAIR,     //01
    __XXXXXX ________  HAIR, HAIR,     //02
    __XXXXXX ________  SKIN, HAIR,     //03
    __X_X_XX ________  SKIN, HAIR,     //04
    __XXXXXX ________  SKIN, ____      //05
    ___XXXXX ________  SKIN, ____      //06
    ___X_XX_ ________  SKIN, ____      //07
    ____XXX_ ________  SKIN, ____      //08
    __XXXXXX X_______  TOP1, TOP1,     //09
    _XXXXXXX XX______  TOP2, TOP2,     //10
    _XXXXXXX XX______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ XX______  TOP1, TOP1,     //13
    ___XXXX_ ________  TOP2, TOP2,     //14
    XX_XXXX_ XX______  BELT, BELT,     //15
    XX_XXXXX XX______  PANT, PANT,     //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21

    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    _X_XXX__  TOP2,    // 4
    _X_XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8


},


{   // FRAME_IMPATIENT = 9

    0+0, 0,

    _____XXX X_______  HAIR, HAIR,     //00
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XXX_____  HAIR, HAIR,     //01
    ___XXXXX X_X_____  HAIR, HAIR,     //02
    ___XXXXX X_______  SKIN, SKIN,     //03
    ___XX_X_ X_______  SKIN, SKIN,     //04
    ___XXXXX X_______  SKIN, SKIN,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    _____XXX X_______  SKIN, ____      //08
    ____XXXX XX______  TOP1, TOP1,     //09
    ____XXXX XX______  TOP2, TOP2,     //10
    ___XXXXX XXX_____  TOP1, TOP1,     //11
    __XXXXXX XXX_____  TOP2, TOP2,     //12
    __XX_XXX X_X_____  TOP1, TOP1,     //13
    __XX_XXX XX______  TOP2, TOP2,     //14
    _____XXX XX_X____  BELT, BELT,     //15
    __XX_XXX XX_X____  PANT, PANT,     //16
    __XX_XX_ XX______  PANT, PANT,     //17
    ____XXX_ _XX_____  PANT, BOOT,     //18
    ____XX__ _XX_____  BOOT, BOOT,     //19
    ____XXX_ _XXX____  BOOT, SOLE,     //20
    ____XXX_ ________  SOLE, ____      //21


    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    _X_XXX__  TOP2,    // 4
    _X_XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_XX_  PNT2,    // 7
    ___X____  BOOT,    // 8

    },


{   // FRAME_IMPATIENT2 = 10

    0+0, 0,

    _____XXX X_______  HAIR, HAIR,     //00
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XXX_____  HAIR, HAIR,     //01
    ___XXXXX X_X_____  HAIR, HAIR,     //02
    ___XXXXX X_______  SKIN, SKIN,     //03
    ___XX_X_ X_______  SKIN, SKIN,     //04
    ___XXXXX X_______  SKIN, SKIN,     //05
    ___XXXXX ________  SKIN, SKIN,     //06
    ____XX_X ________  SKIN, ____      //07
    _____XXX X_______  SKIN, ____      //08
    ____XXXX XX______  TOP1, TOP1,     //09
    ____XXXX XX______  TOP2, TOP2,     //10
    ___XXXXX XXX_____  TOP1, TOP1,     //11
    __XXXXXX XXX_____  TOP2, TOP2,     //12
    __XX_XXX X_X_____  TOP1, TOP1,     //13
    __XX_XXX X_______  TOP2, TOP2,     //14
    _____XXX XX_X____  BELT, BELT,     //15
    __XX_XXX XX_X____  PANT, PANT,     //16
    __XX_XX_ _XX_____  PANT, BOOT,     //17
    ____XXX_ _XX_____  PANT, BOOT,     //18
    ____XX__ _XXX____  BOOT, SOLE,     //19
    ____XXX_ ________  BOOT, ____      //20
    ____XXX_ ________  SOLE, ____      //21

    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    _X_XXX__  TOP2,    // 4
    _X_XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_XX_  BOOT,    // 8

    },

{   // FRAME_LOOK1 = 11

    3,0,

    ____XXX_ ________  HAIR, HAIR,     //00
    ___XXXX_ ________  HAIR, HAIR,     //00
    __XXXXXX ________  HAIR, HAIR,     //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX XX______  SKIN, HAIR,     //03
    __X_X_XX _X______  SKIN, HAIR,     //04
    __XXXXXX ________  SKIN, ____      //05
    __XXXXXX ________  SKIN, ____      //06
    ___X_XX_ ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX ________  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX XX______  TOP1, TOP1,     //11
    _XX_XXXX XX______  TOP2, TOP2,     //12
    _XXXXXX_ XX______  TOP1, TOP1,     //13
    ___XXXX_ ________  TOP2, ____      //14
    _XXXXXX_ XX______  BELT, BELT,     //15
    ___XXXX_ XX______  PANT, PANT,     //16
    ___XXXX_ ________  PANT, ____      //17
    ___XXXXX ________  PANT, ____      //18
    ___XX_XX ________  BOOT, ____      //19
    ___XX_XX X_______  BOOT, BOOT,     //20
    ___XX_XX X_______  SOLE, SOLE,     //21


    -5,0,    // x,y

    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    _X_XXX__  TOP2,    // 4
    _X_XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

    },

{   // FRAME_LOOK2 = 12

    2,0,

    ___XXXXX ________  HAIR, HAIR,     //00
    __XXXXXX X_______  HAIR, HAIR,     //00
    _XXXXXXX X_______  HAIR, HAIR,     //01
    _X_XXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX X_______  SKIN, HAIR,     //03
    __X_X_XX X_______  SKIN, HAIR,     //04
    __XXXXXX X_______  SKIN, HAIR,     //05
    ___XXXXX ________  SKIN, ____      //06
    _____XXX ________  SKIN, ____      //07
    ____XXXX ________  SKIN, ____      //08
    ___XXXXX XX______  TOP1, TOP1,     //09
    __XXXXXX XXX_____  TOP2, TOP2,     //10
    __XXXXXX XXX_____  TOP1, TOP1,     //11
    __XX_XXX _XX_____  TOP2, TOP2,     //12
    __XXXXXX __XX____  TOP1, TOP1,     //13
    ____XXXX ________  TOP2, TOP2,     //14
    __XXXXXX __XX____  BELT, BELT,     //15
    ____XXXX __XX____  PANT, PANT,     //16
    ____XXXX ________  PANT, PANT,     //17
    ____XXXX ________  PANT, PANT,     //18
    ____XX_X X_______  BOOT, BOOT,     //19
    ____XX_X X_______  BOOT, BOOT,     //20
    ___XXX_X X_______  SOLE, SOLE,     //21

    -5,0,    // x,y

    __XXX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    _X_XXX__  TOP2,    // 4
    _X_XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

    },

{   // FRAME_SHADES = 13

    2+0,0,
    
    ____XXXX ________  HAIR, HAIR,     //00
    ___XXXXX X_______  HAIR, HAIR,     //00
    __XXXXXX X_______  HAIR, HAIR,     //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX XX______  SKIN, HAIR,     //03
    ________ _X______  SKIN, HAIR,     //04
    __XX_X_X _X______  SKIN, HAIR,     //05
    __XXXXX_ ________  SKIN, ____      //06
    ___XX_X_ ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX X_______  TOP1, TOP1,     //09
    _XXXXXXX XX______  TOP2, TOP2,     //10
    _XXXXXXX XX______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ _XX_____  TOP1, TOP1,     //13
    ___XXXX_ ________  TOP2, TOP2,     //14
    XX_XXXX_ _XX_____  BELT, BELT,     //15
    XX_XXXXX _XX_____  PANT, PANT,     //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21

    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    ___XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

    },

{   // FRAME_SHADES_ARM = 14

    2+0, 0,

    ____XXX_ ________  HAIR, ____      //00
    ___XXXXX ________  HAIR, ____      //00
    __XXXXXX ________  HAIR, ____      //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX X_______  SKIN, HAIR,     //03
    ________ XX______  SKIN, SKIN,     //04
    __XX_X_X XX______  SKIN, SKIN,     //05
    __XXXXX_ XX______  SKIN, TOP2,     //06
    ___XX_X_ XX______  SKIN, TOP1,     //07
    ___XXXX_ XX______  SKIN, TOP2,     //08
    __XXXXXX XX______  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX ________  TOP1, ____      //11
    XX_XXXX_ ________  TOP2, ____      //12
    XX_XXXX_ ________  TOP1, ____      //13
    ___XXXX_ ________  TOP2, ____      //14
    XX_XXXX_ ________  BELT, ____      //15
    XX_XXXXX ________  PANT, ____      //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21


    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XXX_  SKIN,    // 1
    ____X__X  TOP2,    // 2
    __XXXXX_  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    ___XX___  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

},


{   // FRAME_BLINK= 15

    2+0, 0,

    ____XXXX ________  HAIR, HAIR,     //00
    ___XXXXX ________  HAIR, HAIR,     //00
    __XXXXXX X_______  HAIR, HAIR,     //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX XX______  SKIN, HAIR,     //03
    __XXXXXX _X______  SKIN, HAIR,     //04
    __XXXXXX _X______  SKIN, HAIR,     //05
    __XXXXX_ ________  SKIN, ____      //06
    ___XX_X_ ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX ________  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX X_______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ XX______  TOP1, TOP1,     //13
    ___XXXX_ ________  TOP2, ____      //14
    XX_XXXX_ XX______  BELT, BELT,     //15
    XX_XXXXX XX______  PANT, PANT,     //16
    ___XX_XX ________  PANT, ____      //17
    __XXX_XX ________  PANT, ____      //18
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21

    -5,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    ___XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    ___X_X__  PNT2,    // 7
    ___X_X__  BOOT,    // 8

    },

{   // FRAME_WALK1 = 16

    2+0, 0,

    _____XXX X_______  HAIR, HAIR,     //00
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XX______  HAIR, HAIR,     //01
    ___XXXXX XX______  HAIR, HAIR,     //02
    ___XXXXX XXX_____  SKIN, HAIR,     //03
    ___XX_X_ X_X_____  SKIN, HAIR,     //04
    ___XXXXX X_X_____  SKIN, HAIR,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX X_______  TOP1, TOP1,     //09
    _XXXXXXX XX______  TOP2, TOP2,     //10
    XXXXXXXX XX______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ _XX_____  TOP1, TOP1,     //13
    ___XXXXX ________  TOP2, ____      //14
    XX_XXXXX _XX_____  BELT, BELT,     //15
    __XXXXXX ________  PANT, ____      //16
    __XXX_XX X_______  PANT, PANT,     //17
    _XXX___X XX______  PANT, PANT,     //18
    XXX_____ XX______  BOOT, BOOT,     //19
    XX______ XX______  BOOT, BOOT,     //20
    XXX_____ XXX_____  SOLE, SOLE,     //21

    -4,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    ___XXX__  TOP1,    // 3
    __XXXXXX  TOP2,    // 4
    _X_XX___  TOP1,    // 5
    __XXX___  TOP2,    // 6
    __X__X__  PNT2,    // 7
    _XX__XX_  BOOT,    // 8

},



{   // FRAME_WALK2 = 17

    2+0, 0,

    _____XXX X_______  HAIR, HAIR,     //00
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XX______  HAIR, HAIR,     //01
    ___XXXXX XX______  HAIR, HAIR,     //02
    ___XXXXX XXX_____  SKIN, HAIR,     //03
    ___XX_X_ X_X_____  SKIN, HAIR,     //04
    ___XXXXX X_X_____  SKIN, HAIR,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX ________  TOP1, ____      //09
    __XXXXXX ________  TOP2, TOP2,     //10
    _XXXXXXX X_______  TOP2, TOP2,     //12
    __XXXXXX X_______  TOP1, TOP1,     //13
    ___XXXXX ________  TOP2, ____      //14
    __X_XXX_ X_______  BELT, BELT,     //15
    __XXXXXX ________  PANT, ____      //16
    __XXXXXX ________  PANT, ____      //16
    __XXX_XX X_______  PANT, PANT,     //17
    _XXX___X XX______  BOOT, PANT,     //18
    XX______ XX______  BOOT, BOOT,     //19
    XXX_____ XX______  SOLE, BOOT,     //20
    ________ XXX_____  SOLE, SOLE,     //21

    -4,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    ___XXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    _X_XX_X_  TOP1,    // 5
    ___XX___  TOP2,    // 6
    __XX_X__  PNT2,    // 7
    __X__X__  BOOT,    // 8

    },


{   // FRAME_WALK3 = 18

    2+0, 0,

    _____XXX X_______  HAIR, HAIR,     //00
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XX______  HAIR, HAIR,     //01
    ___XXXXX XX______  HAIR, HAIR,     //02
    ___XXXXX XXX_____  SKIN, HAIR,     //03
    ___XX_X_ X_X_____  SKIN, HAIR,     //04
    ___XXXXX X_X_____  SKIN, HAIR,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX ________  TOP1, TOP1,     //09
    __XXXXXX X_______  TOP2, TOP2,     //10
    _XXXXXXX X_______  TOP1, TOP1,     //11
    _XX_XXX_ X_______  TOP2, TOP1,     //12
    _XX_XXX_ X_______  TOP1, TOP1,     //13
    ____XXXX ________  TOP2, ____      //14
    __XX_XX_ X_______  BELT, BELT,     //15
    ____XXXX ________  PANT, ____      //16
    ____XXXX ________  PANT, ____      //17
    __XX_XXX ________  PANT, ____      //18
    __XX_XXX ________  BOOT, ____      //19
    _____XX_ ________  BOOT, ____      //20
    _____XXX ________  SOLE, ____      //21

    -4,0,    // x,y

    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ___X____  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    ___XXX__  TOP1,    // 5
    ___XX___  TOP2,    // 6
    __XX____  PNT2,    // 7
    ___XX___  BOOT,    // 8

},



{   // FRAME_WALK4 = 19

    0+0, 0,

    _____XXX X_______  HAIR, HAIR,     //00
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XX______  HAIR, HAIR,     //01
    ___XXXXX XX______  HAIR, HAIR,     //02
    ___XXXXX XXX_____  SKIN, HAIR,     //03
    ___XX_X_ X_X_____  SKIN, HAIR,     //04
    ___XXXXX X_X_____  SKIN, HAIR,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX X_______  TOP1, TOP1,     //09
    _XXXXXXX XX______  TOP2, TOP2,     //10
    XXXXXXXX XX______  TOP1, TOP1,     //11
    XX_XXXX_ XX______  TOP2, TOP2,     //12
    XX_XXXX_ _XX_____  TOP1, TOP1,     //13
    ___XXXXX ________  TOP2, ____      //14
    XX_XXXXX _XX_____  BELT, BELT,     //15
    ____XXXX ________  PANT, ____      //16
    ____XXXX ________  PANT, ____      //17
    _____XXX X_______  PANT, BOOT,     //18
    ____XXXX X_______  BOOT, BOOT,     //19
    _____XX_ ________  BOOT, ____      //20
    _____XXX ________  SOLE, ____      //21

    -4,0,    // x,y

    ____XX__  HAIR,    // 0
    ____XX__  SKIN,    // 1
    ____X___  TOP2,    // 2
    __XXXX__  TOP1,    // 3
    __XXXX__  TOP2,    // 4
    ___XX_X_  TOP1,    // 5
    ___XXX__  TOP2,    // 6
    ___XX___  PNT2,    // 7
    ___XX___  BOOT,    // 8

    },

{   // FRAME_SNATCH_DOWN = 20

    2+0, 0,

    ________ ________  HAIR, ____      //08
    ________ ________  HAIR, ____      //08
    ________ ________  HAIR, ____      //08
    ________ ________  HAIR, ____      //08
    ________ ________  HAIR, ____      //08
    ________ ________  HAIR, ____      //08
    ________ ________  HAIR, ____      //08
    ____XXXX XX______  HAIR, HAIR,     //00
    ___XXXXX XXX_____  HAIR, HAIR,     //01
    ___XXXXX X_______  HAIR, SKIN,     //02
    ___XXXXX X_______  SKIN, SKIN,     //03
    ___XX_X_ X_______  SKIN, SKIN,     //04
    ___XXXXX X_______  SKIN, SKIN,     //05
    ___XXXXX ________  SKIN, ____      //06
    ____XX_X ________  SKIN, ____      //07
    __XXXXXX X_______  TOP1, TOP1,     //11
    __XXXXXX X_______  TOP2, TOP2,     //12
    __XXXXXX X_______  TOP1, TOP1,     //13
    __XX_XXX X_______  TOP2, TOP2,     //14
    ___XX_XX X_______  TOP1, BELT,     //15
    ___XXXXX ________  TOP2, TOP2,     //16
    __XXX_XX X_______  BELT, BELT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21


    -5,0,    // x,y

    ________  HAIR,    // 0
    ________  HAIR,    // 1
    ________  HAIR,    // 2
    ________  HAIR,    // 3
    ____XX__  HAIR,    // 4
    ____XX__  SKIN,    // 5
    __XXXX__  TOP2,    // 6
    _X_XXX__  TOP1,    // 7
    __X__X__  BOOT,    // 8

},

{   // FRAME_SKELETON = 21

    1,0,

    ________ ________  BONE, ____      //08
    ________ ________  BONE, BONE,     //00
    ____XXXX ________  BONE, BONE,     //01
    ___XXXXX X_______  BONE, BONE,     //02
    ___X__X_ _X______  BONE, BONE,     //03
    ___X__X_ _X______  BONE, BONE,     //04
    ___XXXXX X_______  BONE, BONE,     //05
    ____X_X_ X_______  BONE, BONE,     //06
    _____X_X ________  BONE, BONE,     //07
    ______X_ ________  BONE, BONE,     //09
    ___XXXXX X_______  BONE, BONE,     //10
    __X___X_ _X______  BONE, BONE,     //11
    _XX_XXXX _XX_____  BONE, BONE,     //12
    _X____X_ __X_____  BONE, BONE,     //13
    ____XXXX X_______  BONE, BONE,     //14
    _XX__XXX _XX_____  BONE, BONE,     //15
    X___X_X_ X__X____  BONE, BONE,     //16
    ____X___ X_______  BONE, BONE,     //17
    ___XX___ XX______  BONE, BONE,     //18
    ____X___ X_______  BONE, BONE,     //19
    ________ ________  BONE, BONE,     //20
    ___XXX_X XX______  BONE, BONE,     //21
    ________ ________  BONE, BONE,     //00

    -5,0,    // x,y

    ____XX__  BONE,    // 0
    ____XX__  BONE,    // 1
    ________  BONE,    // 2
    ___XXX__  BONE,    // 3
    __X_X_X_  BONE,    // 4
    ___XXX__  BONE,    // 5
    ____X___  BONE,    // 6
    ___X_X__  BONE,    // 7
    ___X_X__  BONE,    // 8

    },

{   // FRAME_SKELETON2 = 22

    -1,0,

    ________ ________  BONE, ____      //08
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //01
    ________ ________  BONE, BONE,     //02
    ________ ________  BONE, BONE,     //03
    ________ ________  BONE, BONE,     //04
    ________ ________  BONE, BONE,     //05
    ________ ________  BONE, ____      //06
    ________ ________  BONE, ____      //07
    ________ ________  BONE, BONE,     //11
    ________ XXXX____  BONE, BONE,     //01
    _______X XXXXX___  BONE, BONE,     //02
    _______X __X__X__  BONE, BONE,     //03
    _______X __X__X__  BONE, BONE,     //04
    _______X XXXXX___  BONE, BONE,     //05
    ________ X_X_X___  BONE, BONE,     //06
    ________ _X_X____  BONE, BONE,     //07
    _____X__ XXXX____  BONE, BONE,     //10
    ___X___X ________  BONE, BONE,     //12
    _______X XX______  BONE, BONE,     //09
    ___X__X_ ______X_ BONE, BONE,     //20
    __XX__XX X_XXX__X  BONE, BONE,     //21

    -4,0,    // x,y

    ________  HAIR,    // 0
    ________  SKIN,    // 1
    ________  SKIN,    // 2
    ________  TOP1,    // 3
    ________  BONE,    // 6
    __XX____  BONE,    // 7
    __XX____  BONE,    // 8
    _X_X_X__  BONE,    // 4
    ________  BONE,    // 5

    },


{   // FRAME_BLANK = 23

    1,0,

    ________ ________  BONE, ____      //08
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00

    -4,0,    // x,y

    ________  HAIR,    // 0
    ________  SKIN,    // 1
    ________  SKIN,    // 1
    ________  SKIN,    // 1
    ________  SKIN,    // 1
    ________  SKIN,    // 1
    ________  SKIN,    // 1
    ________  SKIN,    // 1
    ________  HAIR,    // 0

    },


{   // FRAME_SKELETON3 = 24

    0,0,

    ________ ________  BONE, ____      //08
    ________ ________  BONE, ____      //08
    ________ ________  BONE, ____      //08
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //01
    _______X XXX_____  BONE, BONE,     //02
    ______XX XXXX____  BONE, BONE,     //03
    ______X_ _X__X___  BONE, BONE,     //04
    ______X_ _X__X___  BONE, BONE,     //05
    ______XX XXXX____  BONE, BONE,     //06
    _______X _X_X____  BONE, BONE,     //07
    ________ X_X_____  BONE, BONE,     //11
    __X_XXX_ XXX_____  BONE, BONE,     //12
    _X____X_ ________  BONE, BONE,     //13
    _X__XXXX ___X____  BONE, BONE,     //14
    ______XX __XX____  BONE, BONE,     //15
    _X__X_X_ X_______  BONE, BONE,     //16
    _X__X___ X___XX__  BONE, BONE,     //17
    _X__X___ X___X___  BONE, BONE,     //19
    X_______ ________  BONE, BONE,     //20
    ___XXX_X XX______  BONE, BONE,     //21
    ________ ________  BONE, BONE,     //00

    -5,0,    // x,y

    ________  BONE,    // 2
    ________  BONE,    // 2
    ____XX__  BONE,    // 0
    ____XX__  BONE,    // 1
    ____X___  BONE,    // 4
    ___XXX__  BONE,    // 5
    ____X___  BONE,    // 6
    ___X_X__  BONE,    // 7
    ___X_X__  BONE,    // 8

    },


{   // FRAME_SKELETON4 = 25

    1,0,

    ________ ________  BONE, ____      //08
    ________ ________  BONE, BONE,     //00
    ____XXXX ________  BONE, BONE,     //01
    ___XXXXX X_______  BONE, BONE,     //02
    __X__X__ X_______  BONE, BONE,     //03
    __X__X__ X_______  BONE, BONE,     //04
    __XXXXXX X_______  BONE, BONE,     //05
    ___X_X_X ________  BONE, BONE,     //06
    ____X_X_ ________  BONE, BONE,     //07
    _______X ________  BONE, BONE,     //09
    ___XXXXX X_______  BONE, BONE,     //10
    __X___X_ _X______  BONE, BONE,     //11
    _XX_XXXX _XX_____  BONE, BONE,     //12
    _X____X_ __X_____  BONE, BONE,     //13
    ____XXXX X_______  BONE, BONE,     //14
    _XX__XXX _XX_____  BONE, BONE,     //15
    X___X_X_ X__X____  BONE, BONE,     //16
    ____X___ X_______  BONE, BONE,     //17
    ___XX___ XX______  BONE, BONE,     //18
    ____X___ X_______  BONE, BONE,     //19
    ________ ________  BONE, BONE,     //20
    ___XXX_X XX______  BONE, BONE,     //21
    ________ ________  BONE, BONE,     //00

    -5,0,    // x,y

    ____XX__  BONE,    // 0
    ____XX__  BONE,    // 1
    ________  BONE,    // 2
    ___XXX__  BONE,    // 3
    __X_X_X_  BONE,    // 4
    ___XXX__  BONE,    // 5
    ____X___  BONE,    // 6
    ___X_X__  BONE,    // 7
    ___X_X__  BONE,    // 8

    },


{   // FRAME_SKELETON5 = 26

    0,0,

    ________ ________  BONE, ____      //08
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //00
    ________ ________  BONE, BONE,     //01
    ________ ________  BONE, BONE,     //02
    ________ ________  BONE, BONE,     //03
    ________ ________  BONE, BONE,     //04
    ________ ________  BONE, BONE,     //05
    ________ ________  BONE, ____      //06
    ________ ________  BONE, ____      //07
    ________ ________  BONE, BONE,     //11
    ________ ________  BONE, BONE,     //12
    ________ ________  BONE, BONE,     //09
    ________ ________  BONE, BONE,     //12
    ________ ________  BONE, BONE,     //09
    ________ ________  BONE, BONE,     //09
    ________ ________  BONE, BONE,     //09
    ________ ________  BONE, BONE,     //01
    ________ ________  BONE, BONE,     //01
    ________ ________  BONE, BONE,     //01
    _______X XXXXX___  BONE, BONE,     //02
    ______X_ _X__XX__  BONE, BONE,     //03
    ______XX _XX__X__  BONE, BONE,     //04

    -4,0,    // x,y

    ________  HAIR,    // 0
    ________  SKIN,    // 1
    ________  SKIN,    // 2
    ________  TOP1,    // 3
    ________  BONE,    // 6
    __XX____  BONE,    // 7
    __XX____  BONE,    // 8
    _X_X_X__  BONE,    // 4
    ________  BONE,    // 5

    },


{   // FRAME_ARMSCROSSED = 27

    2+0, 0,



    ____XXXX ________  HAIR, ____      //00
    ___XXXXX ________  HAIR, ____      //00
    __XXXXXX X_______  HAIR, HAIR,     //01
    __XXXXXX X_______  HAIR, HAIR,     //02
    __XXXXXX XX______  SKIN, HAIR,     //03
    __XX_X_X _X______  SKIN, HAIR,     //04
    __XXXXXX _X______  SKIN, HAIR,     //05
    __XXXXX_ ________  SKIN, ____      //06
    ___XX_X_ ________  SKIN, ____      //07
    ___XXXX_ ________  SKIN, ____      //08
    __XXXXXX ________  TOP1, TOP1,     //09
    _XXXXXXX X_______  TOP2, TOP2,     //10
    _XXX__XX X_______  TOP1, TOP1,     //11
    _XXXXXXX X_______  TOP2, BELT,     //12
    __XXXX_X X_______  PANT, TOP1,     //13
    ______XX ________  TOP2, ____      //14
    ___XXXX_ ________  BELT, BELT,     //15
    ___XXXXX ________  PANT, PANT,     //16
    ___XXXXX ________  PANT, PANT,     //16
    ___XX_XX ________  PANT, ____      //17
    __XX__XX ________  BOOT, ____      //19
    __XXX_XX X_______  BOOT, BOOT,     //20
    __XXX_XX X_______  SOLE, SOLE,     //21

    -4,0,    // x,y

    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ___X____  SKIN,    // 2
    __XXX___  TOP1,    // 3
    __XXX___  TOP2,    // 4
    __XX____  TOP1,    // 5
    __XX____  TOP2,    // 6
    __X_X___  PNT2,    // 7
    __X_X___  BOOT,    // 8

    },

{   // FRAME_SHAKE= 28

    -1+0, 0,

    ________ ________  ____  ____      //00
    ________ ________  ____  ____      //00
    ________ ________  ____  ____      //00
    _______X XXX_____  HAIR, HAIR,     //00
    ______XX XXX_____  HAIR, HAIR,     //00
    _____XXX XXXX____  HAIR, HAIR,     //01
    _____XXX XXXXXX__  HAIR, HAIR,     //02
    _____XXX XXXX____  SKIN, SKIN,     //03
    _____XX_ X_X_____  SKIN, SKIN,     //04
    _____XXX XXX_____  SKIN, SKIN,     //05
    _____XXX XX______  SKIN, SKIN,     //06
    __XX__XX _X__XX__  SKIN, SKIN,     //07
    __XX__XX _X__XX__  SKIN, SKIN,     //08
    ____XXXX XXXXX___  TOP1, TOP1,     //09
    ___XXXXX XXXXX___  TOP2, TOP2,     //10
    ____XXXX XXXX____  TOP1, TOP1,     //11
    ______XX XX______  TOP2, TOP2,     //12
    ______XX XX______  BELT, BELT,     //15
    ______XX _XXX____  PANT, PANT,     //16
    _______X X_XX____  PANT, BOOT,     //17
    ______XX __XX____  BOOT, BOOT,     //19
    _____XXX __XXX___  BOOT, SOLE,     //20
    _____XXX ________  SOLE, SOLE,
    
    //2
    
    -4,0,    // x,y

    ________  ____ 
    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    X__X__X_ TOP2,    // 2
    _XXXXX__  TOP1,    // 3
    ___XX___  TOP2,    // 4
    __XX____  TOP2,    // 6
    __XXX___  PNT2,    // 7
    __X_X___  BOOT,    // 8

    },


{   // FRAME_SHAKE = 29

    0+0, 0,

    ________ ________  ____  ____      //00
    ________ XXXX____  HAIR, HAIR,     //00
    _______X XXXX____  HAIR, HAIR,     //00
    ______XX XXXXX___  HAIR, HAIR,     //01
    ______XX XXXXXXX_  HAIR, HAIR,     //02
    ______XX XXXXX___  SKIN, SKIN,     //03
    ______XX _X_X____  SKIN, SKIN,     //04
    ______XX XXXX____  SKIN, SKIN,     //05
    ______XX XXX_____  SKIN, SKIN,     //06
    _______X X_X___XX  SKIN, SKIN,     //07
    _______X X_X___XX  SKIN, SKIN,     //08
    ____XXXX XXXXXX__  TOP1, TOP1,     //09
    ___XXXXX XXXXXX__  TOP2, TOP2,     //10
    __XXX_XX XXXXX___  TOP1, TOP1,     //11
    __XX__XX XXX_____  TOP2, TOP2,     //12
    __XX__XX XX______  TOP1, TOP1,     //13
    ______XX XX______  TOP2, TOP2,     //14
    __XX__XX XX______  BELT, BELT,     //15
    ______XX XXX_____  PANT, PANT,     //16
    ______XX _XX_____  PANT, BOOT,     //17
    _____XX_ _XX_____  BOOT, BOOT,     //19
    _____XXX _XXX____  BOOT, BOOT,     //20
    _____XXX ________  SOLE, SOLE,
    
    //2
    
    -4,0,    // x,y

    ________  ____ 
    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    ___X__X_ TOP2,    // 2
    _XXXXX__  TOP1,    // 3
    X__XX___  TOP2,    // 4
    __XX____  TOP2,    // 6
    __XXX___  PNT2,    // 7
    __X_X___  BOOT,    // 8

    },

{   // FRAME_SHAKE= 30

    -1+0, 0,

    ________ ________  ____  ____      //00
    ________ XXXX____  HAIR, HAIR,     //00
    _______X XXXX____  HAIR, HAIR,     //00
    ______XX XXXXX___  HAIR, HAIR,     //01
    ______XX XXXXXXX_  HAIR, HAIR,     //02
    ______XX XXXXX___  SKIN, SKIN,     //03
    ______XX _X_X____  SKIN, SKIN,     //04
    ______XX XXXX____  SKIN, SKIN,     //05
    ______XX XXX_____  SKIN, SKIN,     //06
    _XX____X X_X_____  SKIN, SKIN,     //07
    _XX____X X_X_____  SKIN, SKIN,     //08
    __XXXXXX XXX_____  TOP1, TOP1,     //09
    __XXXXXX XXXX____  TOP2, TOP2,     //10
    ___XXXXX XXXXX___  TOP1, TOP1,     //11
    ______XX XXXXX___  TOP2, TOP2,     //12
    ______XX XX__XX__  TOP1, TOP1,     //13
    ______XX XX______  TOP2, TOP2,     //14
    ______XX XX__XX__  BELT, BELT,     //15
    ______XX XXX_____  PANT, PANT,     //16
    ______XX _XX_____  PANT, BOOT,     //17
    _____XX_ _XX_____  BOOT, BOOT,     //19
    _____XXX _XXX____  BOOT, SOLE,     //20
    _____XXX ________  SOLE, SOLE,
    
    //2
    
    -4,0,    // x,y

    ________  ____ 
    ___XX___  HAIR,    // 0
    ___XX___  SKIN,    // 1
    X__X____  TOP2,    // 2
    _XXXXX__  TOP1,    // 3
    ___XX_X_  TOP2,    // 4
    __XX____  TOP2,    // 6
    __XXX___  PNT2,    // 7
    __X_X___  BOOT,    // 8

    },



};

