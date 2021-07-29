#include "movePlayer.h"
#include "main.h"
#include "defines_from_dasm_for_c.h"
#include "defines.h"
#include "bitshapes.h"

#define RAM ((unsigned char*)DDR)

int absRockfordX;
int absRockfordY;

void movePlayer() {


#if ENABLE_SHAKE
    extern int shakeX, shakeY;

    int x = scrollX + (shakeX >> 2);
    int y = scrollY + (shakeY >> 2);
#else
    int x = scrollX;
    int y = scrollY;
#endif

    absRockfordY = (((playerY - y) * 3) >> 16) - frameAdjustY + SCORE_SCANLINES - 22 + 4;
    absRockfordX = (playerX - x) >> 14;

    rockfordX = playerX >> 16;

    rockfordY = 0;
    int temp = playerY >> 16;
    while (temp > 0) {
        rockfordY++;
        temp -= 7;
    }


}

typedef struct {
    signed char x;
    signed char y;
    signed char face;
} OFFSET;

const OFFSET movementOffset[] = {

    // X   Y  DIR               RLDU

    {  0,  0,  0 },     // 0    0000
    {  0, -1,  0 },     // 1    0001
    {  0,  1,  0 },     // 2    0010
    {  0,  0,  0 },     // 3    0011
    { -1,  0, -1 },     // 4    0100
    { -1, -1, -1 },     // 5    0101
    { -1,  1, -1 },     // 6    0110
    {  0,  0,  0 },     // 7    0111
    {  1,  0,  1 },     // 8    1000
    {  1, -1,  1 },     // 9    1001
    {  1,  1,  1 },     // 10   1010
    {  0,  0,  0 },     // 11   1011
    {  0,  0,  0 },     // 12   1100
    {  0,  0,  0 },     // 13   1101
    {  0,  0,  0 },     // 14   1110
    {  0,  0,  0 },     // 15   1111
};


int playerX;
int playerY;

int playerSpeedX;
int playerSpeedY;

void doPlayer() {


    unsigned char dir = ((~SWCHA) >> 4) & 0xF;
    OFFSET joy = movementOffset[dir];

    playerX += joy.x * playerSpeedX;
    playerY += joy.y * playerSpeedY;

        if (playerY < 10)
            playerY = 10;
        // if (playerX < (3<<14))
        //     playerX = (3<< 14);

        // // if (playerY > _ARENA_SCANLINES * 3 - 10)
        // //     playerY = _ARENA_SCANLINES * 3- 10;

        // if (playerX > (37<<14))
        //     playerX = (37<<14);


    if (joy.face && rockfordDirection != joy.face)
        rockfordDirection = joy.face;

    setAnimation(ID_SHAKE);

    bufferedSWCHA = 0xFF;



//     for (int dir = 0; dir < 4; dir++ ) {

//         int offset = offsetD[dir];

//         if ((bufferedSWCHA & (direct[dir] << 4)) == 0) {       // direction button?

// //                    setFlash(0x46,1);

//             unsigned char destType = CharToType[*(this+offset) & 0x7F];  // dubious masking of FLAG

//             bufferedSWCHA = 0xFF; //|= (direct[dir] << 4);

//             if (faceDirection[dir]) {
//                 if (rockfordDirection != faceDirection[dir]) {
//                     pushCounter = 0;
//                     rockfordDirection = faceDirection[dir];
//                 }
//             }

//             if (Attribute[destType] & (ATT_BLANK | ATT_PERMEABLE | ATT_GRAB | ATT_EXIT)) {
            
//                 pushCounter = 0;

//                 if (destType == TYPE_DIRT
//                     ||destType == TYPE_DIRT2
//                     ||destType == TYPE_DIRT3) {
//                         AddAudio(SFX_DIRT);
//                         dirtFlag = DIRT_DIRT;
//                         //AnimIdx[TYPE_DUST] = 0;
//                 }

//                 if (destType == TYPE_BLANK)
//                     AddAudio(SFX_SPACE);

//                 if (destType == TYPE_OUTBOX) {
//                     exitMode = true;
//                     setAnimation(ID_SHAKE); //? fail
//                 }

//                 if (Attribute[destType] & ATT_GRAB) {

//                     addScore(doge? diamondValue: extraDogeCoinValue);

//                     if (doge) {
//                         if (!--doge) {
//                             setFlash(0x0F, 4);     //open door
//                             exitTrigger = true;
//                             AddAudio(SFX_EXIT);
//                         }
//                     }


//                     dogeCollected++;
//                     diamondGrabTime = 10;
//                     dirtFlag = DIRT_DOGE;

//                     AddAudio(SFX_DOGE);
//                 }

//                 if (JOY0_FIRE) {

//                     if (Attribute[destType] & (ATT_GRAB | ATT_PERMEABLE)
//                         && !(Attribute[destType] & ATT_BLANK)) {  // snatch?
//                         *(this+offset) = (
//                                (destType == TYPE_DIRT)
//                             || (destType == TYPE_DIRT2)
//                             || (destType == TYPE_DIRT3)
//                             ? CH_DUST : CH_DOGE_GRAB) | FLAG_THISFRAME;
//                         diamondGrabTime = 1;
//                         setAnimation(newSnatch[dir]);
//                     }
//                     else
//                     {
//                         setAnimation(ID_JUMP);
//                     }
                    
//                 }

//                 else {

//                     rockfordX += xInc[direct[dir]];
//                     rockfordY += yInc[direct[dir]];

//                     frameAdjustX = frameAdjustY = 0;

//                     *(this+offsetD[dir]) = CH_ROCKFORD | FLAG_THISFRAME;
//                     *this = (dirtFlag == DIRT_DIRT ? CH_DUST : blanker) | FLAG_THISFRAME;

//                     if (dirtFlag & DIRT_DIRT) {
//                         AnimIdx[TYPE_ROCKFORD].index = -2;
//                         AnimIdx[TYPE_ROCKFORD].count = 0;
//                     }

//                     if (dirtFlag & DIRT_DOGE) {
//                         AnimIdx[TYPE_ROCKFORD].index = 6;
//                         AnimIdx[TYPE_ROCKFORD].count = 0;
//                     }

//                     int anim = newAnim[dir];
//                     //if (anim == ID_WALK && dirtFlag)
//                     //    anim = ID_PUSHWALK;

//                     setAnimation(anim);
//                 }


//             } else {

//                 if (faceDirection[dir] && (Attribute[destType] & ATT_PUSH)) {

//                     pushCounter++;

//                     if (pushCounter > 1)
//                         setAnimation(ID_PUSH);
//                     else
//                         setAnimation(ID_JUMP);


//                     if (pushCounter > 20 || (pushCounter > 5 && (getRandom32() & 7) < 2)) { 
//                         if (Attribute[CharToType[(*(this+ 2 * offset))&0x7F ]] & ATT_BLANK) {

//                             halt = DELAY_AFTER_PUSH;
//                             pushCounter = 0;

//                             *(this + 2 * offset) = CH_BOULDER | FLAG_THISFRAME;
//                             if (JOY0_FIRE)
//                                 *(this+offset) = blanker | FLAG_THISFRAME;
//                             else {
//                                 rockfordX += offset;
//                                 *(this+offset) = CH_ROCKFORD | FLAG_THISFRAME;
//                                 *this = blanker | FLAG_THISFRAME;
//                             }

//                             AddAudio(SFX_PUSH);

//                         }
//                     }
//                 }

//                 else
//                     setAnimation(ID_JUMP);
//             }

//             return;
//         }
//     }

//     // no direction was detected...

//     pushCounter = 0;

//     if (*(this-40) == (CH_DOGE_FALLING | FLAG_THISFRAME)
//         || *(this-40) == (CH_BOULDER_FALLING | FLAG_THISFRAME))
//             setAnimation(ID_DIE);

//     else {

//         playerAnimationLoop = 0;                   // bypass any looping!

// #if 1
//         static const unsigned char animID[] = {
//             ID_BLINK,       200, 
//             ID_WIPE_HAIR,   20,
//             ID_IMPATIENT,   12, 
//             ID_TURN,        17, 
//             ID_LOOK,        30, 
//             ID_SHADES,      25, 
//             ID_ARMSCROSSED, 13,
//         };

//         // choose an idle animation

//         unsigned int rnd = getRandom32();
//         if (playerAnimationID == ID_STAND && (rnd & 0xFF) < 0x60) {
//             rnd = getRandom32();
//             int idle = ((rnd & 0xFF * 7) >> 8) << 1; 
//             rnd = getRandom32();
//             if ((rnd & 0x3FF) < animID[idle + 1])
//                 setAnimation(animID[idle]);
                
//         }
// #endif        
//     }

}