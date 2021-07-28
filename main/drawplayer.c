
#include <stdbool.h>

#include "main.h"

//#include "defines_cdfj.h"
#include "defines_from_dasm_for_c.h"
#include "defines.h"

#include "drawplayer.h"
#include "main.h"
#include "attribute.h"
#include "bitshapes.h"
#include "movePlayer.h"
#include "bitpatterns.h"

// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)



int lastPlayerSpriteY = -1;

void removeSprite() {

    // remove previous sprite

    unsigned char *p0 = RAM + _BUF_GRP0A + lastPlayerSpriteY;
    unsigned char *p1 = RAM + _BUF_GRP1A + lastPlayerSpriteY;

    if (lastPlayerSpriteY >= 0)
        for (int i=0; i < SPRITE_DEPTH; i++) {
            *p0++ = 0;
            *p1++ = 0;
    }

}

extern int scrollX;
extern int scrollY;
//extern int attractCounter;

// const unsigned char plusOne[] = {
//     _______X
//     __X___XX
//     __X____X
//     XXXXX__X
//     __X____X
//     __X____X
//     _______X
// };




void drawPlayerSprite() {

    removeSprite();

    movePlayer();

    int ypos = absRockfordY; //(rockfordY * PIECE_DEPTH + 17 -PIECE_DEPTH) - (y * 3) - frameAdjustY + SCORE_SCANLINES - 22 + 4;
    // int type = CharToType[RAM[_BOARD + rockfordY * 40 + rockfordX] & 0x7F];
    int xpos = absRockfordX; //(rockfordX * 4 /* -frameAdjustX*/) - x;


    updateAnimation();


    if ( xpos >= 0 && xpos < 160
        && ypos >= 0 && ypos < _ARENA_SCANLINES-PIECE_DEPTH) {


        const signed char *spr = playerBigSprite[*playerAnimation];
        int frameOffset = *spr++;
        int frameYOffset = *spr++;
    
        lastPlayerSpriteY = ypos + frameYOffset - 1;

        unsigned char *p0Colour = RAM + _BUF_COLUP0 + lastPlayerSpriteY-1;
        unsigned char *p1Colour = RAM + _BUF_COLUP1 + lastPlayerSpriteY-1;

        unsigned char *p0 = RAM + _BUF_GRP0A + lastPlayerSpriteY;
        unsigned char *p1 = RAM + _BUF_GRP1A + lastPlayerSpriteY;


        if (rockfordDirection == RIGHT) {
            for (int line = 0; line < SPRITE_DEPTH; line++) {
                *p0++ = *spr++;
                *p1++ = *spr++;
                *p0Colour++ = ColourConvert(*spr++);
                *p1Colour++ = ColourConvert(*spr++);
            }

            // if (true ||sparkleTimer)
            //     for (int line = 0; line < 7; line++) {
            //         *(p0 - SPRITE_DEPTH -10 + line - (20 - sparkleTimer)) = plusOne[line];
            //         *(p0Colour - SPRITE_DEPTH - 30 + line) = 0xA;
            // }

        }
        else {
            for (int line = 0; line < SPRITE_DEPTH; line++) {
                *p0++ = BitRev[(unsigned char)*spr++];
                *p1++ = BitRev[(unsigned char)*spr++];
                *p0Colour++ = ColourConvert(*spr++);
                *p1Colour++ = ColourConvert(*spr++);
            }

            // if (true || sparkleTimer)
            //     for (int line = 0; line < 7; line++) {
            //         *(p0 - SPRITE_DEPTH -30 + line - (20-sparkleTimer)) = BitRev[plusOne[line]];
            //         *(p0Colour - SPRITE_DEPTH - 10 + line) = 0xA;
            // }

        }
        
        P0_X = absRockfordX+ (rockfordDirection * (frameOffset + frameAdjustX));
        if (rockfordDirection == LEFT) {
            P1_X = P0_X;
            P0_X += 8;
        } else
            P1_X = P0_X + 8;
    }
}




int lastSmallPlayerSpriteY = -1;


void removeSmallSprite() {

    unsigned char *p0 = RAM + _BUF_GRP0A + lastSmallPlayerSpriteY;
    if (lastSmallPlayerSpriteY >= 0)
        for (int i=0; i < 9; i++)
            *p0++ = 0;
}

void drawPlayerSmallSprite() {


    removeSmallSprite();


    int ypos = ((rockfordY - 1) << 3) + rockfordY - 1;
    // int type = CharToType[RAM[_BOARD + rockfordY * 40 + rockfordX] & 0x7F];

    if (/*(type == TYPE_ROCKFORD)
        &&*/ ypos > 0 && ypos < _ARENA_SCANLINES-9) {

        updateAnimation();
 
        const signed char *spr = playerBigSprite[*playerAnimation] + SMALL_SPRITE_OFFSET;
        int frameOffset = *spr++;
        int frameYOffset = *spr++;

        lastSmallPlayerSpriteY = ypos + frameYOffset - frameAdjustSmallY;

        unsigned char *p0Colour = RAM + _BUF_COLUP0 + lastSmallPlayerSpriteY;
        unsigned char *p0 = RAM + _BUF_GRP0A + lastSmallPlayerSpriteY;


        for (int line = 0; line < 9; line++) {
            *p0++ = rockfordDirection == RIGHT ? *spr++ : BitRev[(unsigned char)*spr++];
            *p0Colour++ = ColourConvert(*spr++);
        }
        
        P0_X = (rockfordX << 2) + (rockfordDirection * (frameOffset + frameAdjustSmallX)) + 2;
        if (rockfordDirection == LEFT)
            P0_X -= 8;
    }
}

