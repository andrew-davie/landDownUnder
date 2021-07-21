#include <stdbool.h>
#include "main.h"
#include "defines_from_dasm_for_c.h"
#include "defines.h"
#include "main.h"
#include "attribute.h"
#include "characterset.h"
#include "drawplayer.h"
#include "bitpatterns.h"
#include "sound.h"

#include "drawscreen.h"

extern int sparkleTimer;

extern int shiftFrac;
extern int shiftYFrac;
extern int scrollSpeed;
extern int scrollYSpeed;
extern int targetScrollSpeed;
extern int targetYScrollSpeed;

int accel = 1024, accelY = 200*256;
int decel = 160, decelY =200*16;


// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)

extern int getRandom32();


#define SCROLLSPEED_MAXIMUM_X (25 << 8)
#define SCROLL_MAXIMUM_X (30 << 16)
#define SCROLL_MAXIMUM_Y (200 << 8)
#define SCROLL_MINIMUM 0

#define SCROLLEDGER 6
#define SCROLLEDGERY 11


void Scroll() {

    int rocky = rockfordX * PIXELS_PER_CHAR + (PIXELS_PER_CHAR >> 1);
    int halfway = (shiftFrac >> 14) + HALFWAYX;

    if ((halfway - SCROLLEDGER)- rocky > 0)
        targetScrollSpeed = -SCROLLSPEED_MAXIMUM_X;
    else if (rocky - (halfway + SCROLLEDGER) > 0)
        targetScrollSpeed = SCROLLSPEED_MAXIMUM_X;

    rocky = rockfordY * TRILINES + (TRILINES >> 1);
    halfway = (shiftYFrac >> 16) + HALFWAYY;

    if ((halfway - SCROLLEDGERY) - rocky > 0)
        targetYScrollSpeed = -SCROLL_MAXIMUM_Y;
    else if (rocky - (halfway + SCROLLEDGERY) > 0)
        targetYScrollSpeed = SCROLL_MAXIMUM_Y;


    if (scrollSpeed < targetScrollSpeed) {
        scrollSpeed += accel;
        if (scrollSpeed > targetScrollSpeed)
            scrollSpeed = targetScrollSpeed;
    }

    if (scrollSpeed > targetScrollSpeed) {
        scrollSpeed -= accel;
        if (scrollSpeed < targetScrollSpeed)
            scrollSpeed = targetScrollSpeed;
    }
    if (scrollYSpeed < targetYScrollSpeed) {
        scrollYSpeed += accelY;
        if (scrollYSpeed > targetYScrollSpeed)
            scrollYSpeed = targetYScrollSpeed;
    }

    if (scrollYSpeed > targetYScrollSpeed) {
        scrollYSpeed -= accelY;
        if (scrollYSpeed < targetYScrollSpeed)
            scrollYSpeed = targetYScrollSpeed;
    }


    shiftFrac += scrollSpeed;
    if (shiftFrac > SCROLL_MAXIMUM_X) {
        shiftFrac = SCROLL_MAXIMUM_X;
        targetScrollSpeed = 0;
        scrollSpeed = 0;
    }

    if (shiftFrac < SCROLL_MINIMUM) {
        shiftFrac = SCROLL_MINIMUM;
        scrollSpeed = 0;
        targetScrollSpeed = 0;
    }


    shiftYFrac += scrollYSpeed;
    if (shiftYFrac > (14*PIECE_DEPTH/3-2)<<16) {
        shiftYFrac = ((14*PIECE_DEPTH/3-2)<<16);
        scrollYSpeed = 0;
        targetYScrollSpeed = 0;
    }

    if (shiftYFrac < SCROLL_MINIMUM) {
        shiftYFrac = SCROLL_MINIMUM;
        scrollYSpeed = 0;
        targetYScrollSpeed = 0;
    }


    if (targetScrollSpeed < 0) {
        targetScrollSpeed += decel;
        if (targetScrollSpeed > 0)
            targetScrollSpeed = 0;
    }

    if (targetScrollSpeed > 0) {
        targetScrollSpeed -= decel;
        if (targetScrollSpeed < 0)
            targetScrollSpeed = 0;
    }

    if (targetYScrollSpeed < 0) {
        targetYScrollSpeed += decelY;
        if (targetYScrollSpeed > 0)
            targetYScrollSpeed = 0;
    }

    if (targetYScrollSpeed > 0) {
        targetYScrollSpeed -= decelY;
        if (targetYScrollSpeed < 0)
            targetYScrollSpeed = 0;
    }

}


unsigned char screenMask[6];


//extern int uncoverCount;

unsigned int mindex = 0;








int looneyIndex = 0;
int looneyY = 0x400;

int radius = 0;
int rinc = 10;



unsigned char *p0;
unsigned char *p1;
unsigned char *p2;
unsigned char *p3;
unsigned char *p4;
unsigned char *p5;

unsigned char bit[40];

void writeMask() {

    *p0++ &= (bit[0] << 4)
        | (bit[1] <<5 )
        | (bit[2] << 6)
        | (bit[3] << 7);

    *p1++  &= (bit[4] << 7)
        | (bit[5] << 6)
        | (bit[6] << 5)
        | (bit[7] << 4)
        | (bit[8] << 3)
        | (bit[9] << 2)
        | (bit[10] << 1)
        | (bit[11]);

    *p2++ &= (bit[12])
        | (bit[13] << 1)
        | (bit[14] << 2)
        | (bit[15] << 3)
        | (bit[16] << 4)
        | (bit[17] << 5)
        | (bit[18] << 6)
        | (bit[19] << 7);

    *p3++ &= (bit[20+0] << 4)
        | (bit[20+1] <<5 )
        | (bit[20+2] << 6)
        | (bit[20+3] << 7);

    *p4++  &= (bit[20+4] << 7)
        | (bit[20+5] << 6)
        | (bit[20+6] << 5)
        | (bit[20+7] << 4)
        | (bit[20+8] << 3)
        | (bit[20+9] << 2)
        | (bit[20+10] << 1)
        | (bit[20+11]);

    *p5++ &= (bit[20+12])
        | (bit[20+13] << 1)
        | (bit[20+14] << 2)
        | (bit[20+15] << 3)
        | (bit[20+16] << 4)
        | (bit[20+17] << 5)
        | (bit[20+18] << 6)
        | (bit[20+19] << 7);
}


int centerX = 19;
int centerY = 100;
int desiredRadius = 175;


void circle(int leftX, int rightX, int r2) {
    
    p0 = &RAM[_BUF_PF0_LEFT];
    p1 = &RAM[_BUF_PF1_LEFT];
    p2 = &RAM[_BUF_PF2_LEFT];
    p3 = &RAM[_BUF_PF0_RIGHT];
    p4 = &RAM[_BUF_PF1_RIGHT];
    p5 = &RAM[_BUF_PF2_RIGHT];

    for (int y = 0; y <= centerY; y++) {

        int distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y)) * ((centerY - y));

        while (distance < r2 && leftX >= 0 && leftX <= centerX) {
            bit[leftX] = 1;
            leftX--;
            distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y) ) * ((centerY - y) );
        }

        int distanceR = (centerX - rightX) * 7 * (centerX - rightX) * 7 + ((centerY - y) ) * ((centerY - y) );

        while (distanceR < r2 && rightX < 40 && rightX >= centerX) {
            bit[rightX] = 1;
            rightX++;
            distanceR = (centerX - rightX) * 7 * (centerX -rightX) * 7  + ((centerY - y) ) * ((centerY - y) );
        }

        writeMask();

    }

    for (int y = centerY+1; y <_ARENA_SCANLINES; y++) {

        int distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y)) * ((centerY - y));

        while (distance > r2 && leftX >= -1 && leftX <= centerX) {
    
            if (leftX >= 0)
                bit[leftX] = 0;
    
            leftX++;
            distance = (centerX - leftX) * 7 * (centerX - leftX) * 7 + ((centerY - y) ) * ((centerY - y) );
        }

        int distanceR = (centerX - rightX) * 7 * (centerX - rightX) * 7 + ((centerY - y) ) * ((centerY - y) );

        while (distanceR > r2 && rightX <= 40 && rightX >= centerX) {

            if (rightX < 40)
                bit[rightX] = 0;
            rightX--;
            distanceR = (centerX - rightX) * 7 * (centerX -rightX) * 7  + ((centerY - y) ) * ((centerY - y) );
        }

        writeMask();

    }

}



void looneyTuneFade() {

    static bool audUnc = false;

    if (!radius) {
        AddAudio(SFX_WHOOSH);
        audUnc = false;
    }

    if (radius >= 0 && (radius>>5) < desiredRadius) {

        for (int i=0; i < 40; i++)
            bit[i] = 0;

        radius += (rinc >> 4);
        rinc = (((rinc << 4) + (rinc << 1)) >> 4) + 1;

        circle(centerX-1, centerX, (radius>>5) * (radius>>5));
    }

    if (!audUnc && (radius>>5) >= desiredRadius) {
        audUnc = true;
        //AddAudio(SFX_UNCOVER);
    }


}



// unsigned int bgDriftX, bgDriftY;


void drawScreen(){

    unsigned char *const arenas[] = {
        RAM + _BUF_PF0_LEFT + SCORE_SCANLINES,
        RAM + _BUF_PF0_RIGHT + SCORE_SCANLINES,
    };

        for (int c = 0; c < 6; c++)
            screenMask[c] = 0;


    Scroll();

#if ENABLE_PARALLAX


    // bgDriftX += 8192/4;
    // bgDriftY += 8192;

    extern unsigned char parallaxBlank[];
    extern unsigned char charDrip[];
    extern unsigned char charDrip1[];
    extern unsigned char charDrip2[];
    extern unsigned char charDrip3[];
    extern unsigned char charDripSplash[];
    extern unsigned char charDiamond[];
    extern unsigned char charDiamond1[];
    extern unsigned char charDiamond2[];
    extern unsigned char charDiamond3[];
    extern unsigned char charDiamond4[];
    extern unsigned char charDiamond5[];

    extern unsigned char charDust2[];
    extern unsigned char charDust3[];



    unsigned char dirtBG[] = {
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00010001,
        0b00000000,
        0b00000000,
        0b00100010,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b10001000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b01000100,
    };

    extern int parallax;

    for (int i = 0; i < PIECE_DEPTH + 9 + 9; i++) {
        parallaxBlank[i] = 0;
    }


    if (parallax) {

#if ENABLE_SHAKE
    extern int shakeX, shakeY;
        int yOffset = ((shiftYFrac + shakeY/* + bgDriftY*/) >> 17) * 3;
        int offset = ((shiftFrac + shakeX/* + bgDriftX*/) >> 15) & 3;
#else
        int yOffset = ((shiftYFrac/* + bgDriftY*/) >> 17) * 3;
        int offset = ((shiftFrac /* + bgDriftX*/) >> 15) & 3;
#endif
        while (yOffset >= PIECE_DEPTH)
            yOffset -= PIECE_DEPTH;
        yOffset = PIECE_DEPTH - yOffset + 1;

        for (int i = 0; i < PIECE_DEPTH; i++) {
            int cidx = yOffset + i;
            while (cidx >= PIECE_DEPTH)
                cidx -= PIECE_DEPTH;
            parallaxBlank[i] = (dirtBG[cidx] >> offset) & 0b1111; //getRandom32(); //0
        }
    }


extern const unsigned char CHAR_DRIP[];
extern const unsigned char CHAR_DRIP1[];
extern const unsigned char CHAR_DRIP2[];
extern const unsigned char CHAR_DRIP3[];
extern const unsigned char CHAR_DRIPX[];
extern const unsigned char DIAMONDA[];
extern const unsigned char DIAMONDx1[];
extern const unsigned char DIAMONDx2[];
extern const unsigned char DIAMONDx3[];
extern const unsigned char DIAMONDx4[];
extern const unsigned char DIAMONDx5[];

//extern const unsigned char DUST2[];
extern const unsigned char DUST3[];

    for (int i=0; i < PIECE_DEPTH; i++) {

        charDrip[i] = CHAR_DRIP[i] | parallaxBlank[i];
        charDrip1[i] = CHAR_DRIP1[i] | parallaxBlank[i];
        charDrip2[i] = CHAR_DRIP2[i] | parallaxBlank[i];
        charDrip3[i] = CHAR_DRIP3[i] | parallaxBlank[i];
        charDripSplash[i] = CHAR_DRIPX[i] | parallaxBlank[i];
        charDiamond[i] = DIAMONDA[i] | parallaxBlank[i];
        charDiamond1[i] = DIAMONDx1[i] | parallaxBlank[i];
        charDiamond2[i] = DIAMONDx2[i] | parallaxBlank[i];
        charDiamond3[i] = DIAMONDx3[i] | parallaxBlank[i];
        charDiamond4[i] = DIAMONDx4[i] | parallaxBlank[i];
        charDiamond5[i] = DIAMONDx5[i] | parallaxBlank[i];

//        charDust2[i] = DUST2[i] | parallaxBlank[i];
        charDust3[i] = DUST3[i] | parallaxBlank[i];

    }



#endif


    // The following draws the screen!

#if ENABLE_SHAKE

    extern int shakeX, shakeY;

    int lcount = -((shiftYFrac + shakeY)>>16) * 3;
    int shift = ((shiftFrac + shakeX) >> 14 ) & 3;

#else

    int lcount = -(shiftYFrac >>16) * 3;
    int shift = (shiftFrac >> 14 ) & 3;

#endif





    int startRow = 0;
    while (lcount <= -PIECE_DEPTH) {
        lcount += PIECE_DEPTH;
        startRow++;
    }


    for (int row = startRow, scanline = 0; scanline < SCANLINES; row++) {


        int slc = lcount;
        int scn = scanline;

#if ENABLE_SHAKE
        int frac = (shiftFrac + shakeX) >> 16;
#else
        int frac = shiftFrac >> 16;
#endif


        int rnd = 0;

        for (int half = 0; half < 2; half++) { 


            scanline = scn;
            lcount = slc;

            unsigned char *xchar = RAM + _BOARD + ((row +1 )* 40) + (half * 5) + frac;
            const unsigned char *image[6];
            // int base = row * 5 + _UNCOVER;

            for (int ch = 0; ch < 6; ch++) {

                unsigned char piece = *xchar;

                // if (uncoverCount) {
                //     if (RAM[base + ((half * 5 + ch + frac) >> 3)] & (1 << ((half * 5 + ch + frac) & 7)))
                //         piece =  (*Animate[TYPE_UNCOVER])[AnimIdx[TYPE_UNCOVER].index];
                // }

                // else {

                    unsigned char type = CharToType[piece];

                    switch (type) {
                    case TYPE_SPACE:
                        if (sparkleTimer) {
                            if (rnd < 8)
                                rnd = getRandom32();
                            piece = ( 7 & (rnd >>= 3)) + CH_BLANK_EXTRA1;
                        }
                        else {
                            piece = (*Animate[type])[AnimIdx[type].index];
                        }
                        break;
                    case TYPE_AMOEBA:
                        if (rnd < 256)
                            rnd = getRandom32();
                        if (((rnd >>= 8) & 0xFF) > 255-BUBBLE_SPEED)
                            piece = *xchar = (rnd & 3) + CH_AMOEBA0;
                        break;
                    case TYPE_LAVA:
                        if (rnd < 256)
                            rnd = getRandom32();
                        if (((rnd >>= 8) & 0xFF) > 255 - LAVA_SPEED)
                            piece = *xchar = (rnd & 3) + CH_LAVA;
                        break;
                    case TYPE_WATER:
 //                       if (rnd < 256)
 //                           rnd = getRandom32();
 //                       if (((rnd >>= 8) & 0xFF) > 252) //5 - WATER_SPEED)
 //                           piece = *xchar = (rnd & 3) + CH_WATER;
                        break;
                        
                    default:
                        piece = (*Animate[type])[AnimIdx[type].index];
                    }
                // }

                image[ch] = *charSet[piece];
                xchar++;
            }

            unsigned char *pf0 = arenas[half] + scanline;


            for (int y = 0; scanline < SCANLINES && y < PIECE_DEPTH; y++) {

                int p = 0;
                for (int pix = 0, pshift=20; pix < 6; pix++, pshift -= 4)
                    p |= *(image[pix])++ << pshift;
                p >>= 4-shift;

                if (lcount >= 0 ) {
                    *pf0 = ((BitRev[(p >> 16) & 0b1111]));
                    *(pf0 + _ARENA_SCANLINES) = ((((p >> 12) & 0b1111) << 4) | (((p >> 8) & 0b1111)));
                    *(pf0 + (_ARENA_SCANLINES << 1)) = ((
                            BitRev[p & 0b1111] | (BitRev[(p >> 4) & 0b1111] >> 4)
                          ));

                    pf0++;

                    scanline++;
                }

                lcount++;
            }

        }
    }


}



void drawOverviewScreen() {

    static const unsigned char partStart[] = { 0, 11, 22 };
    static signed char part = 0;

    if (--part < 0)
        part = 1;


    unsigned char *ppf = RAM + _BUF_PF0_LEFT + partStart[part] * 9;


    // The following draws the screen!

    const unsigned char *img[40];
    unsigned char *p = RAM + _BOARD + partStart[part] * 40 + 40;

    for (int row = partStart[part]; row < partStart[part+1]; row++) {
        for (int i=0; i< 40; i++) {

            unsigned char p2;
            
            // if (uncoverCount && RAM[_UNCOVER + row * 5 + (i >> 3)] & (1 << (7- (i & 7))))
            //     p2 = CH_UNCOVER0;

            // else {

                p2 = *p;

                unsigned char type = CharToType[p2];

                switch (type) {
                case TYPE_SPACE:
                    if (sparkleTimer)
                        p2 = (getRandom32() & 7) + CH_BLANK_EXTRA1;
                    break;

                case TYPE_AMOEBA: {
                        unsigned int rnd = getRandom32();
                        if ((rnd & 0xFF) > (255-BUBBLE_SPEED))
                            p2 = *p = (rnd & 3) + CH_AMOEBA0;
                    }
                    break;

                case TYPE_LAVA: {
                        unsigned int rnd = getRandom32();
                        if ((rnd & 0xFF) > (255-LAVA_SPEED))
                            p2 = *p = (rnd & 3) + CH_LAVA;
                    }
                    break;

                case TYPE_WATER: {
//                    unsigned int rnd = getRandom32();
//                    if (((rnd >>= 8) & 0xFF) > 252) //5 - WATER_SPEED)
//                        p2 = *p = (rnd & 3) + CH_WATER;
                }
                    break;

                default:
                    p2 = (*Animate[type])[AnimIdx[type].index];
                    break;
                }
            // }

            int offset = PIECE_DEPTH + 9 * ((row + i) & 1);
            img[i] = *charSet[p2] + offset;

            p++;
        }

        for (int iccLine=0; iccLine < 9; iccLine++) {

            *ppf = (*img[0]++ << 4)
                | (*img[1]++ << 5)
                | (*img[2]++ << 6)
                | (*img[3]++ << 7);

            *(ppf + _ARENA_SCANLINES) = (*img[4]++ << 7)
                | (*img[5]++ << 6)
                | (*img[6]++ << 5)
                | (*img[7]++ << 4)
                | (*img[8]++ << 3)
                | (*img[9]++ << 2)
                | (*img[10]++ << 1)
                | (*img[11]++);

            *(ppf + 2 * _ARENA_SCANLINES) = (*img[12]++)
                | (*img[13]++ << 1)
                | (*img[14]++ << 2)
                | (*img[15]++ << 3)
                | (*img[16]++ << 4)
                | (*img[17]++ << 5)
                | (*img[18]++ << 6)
                | (*img[19]++ << 7);

            *(ppf + 3 * _ARENA_SCANLINES) = (*img[20+0]++ << 4)
                | (*img[20+1]++ << 5)
                | (*img[20+2]++ << 6)
                | (*img[20+3]++ << 7);

            *(ppf + 4 * _ARENA_SCANLINES) = (*img[20+4]++ << 7)
                | (*img[20+5]++ << 6)
                | (*img[20+6]++ << 5)
                | (*img[20+7]++ << 4)
                | (*img[20+8]++ << 3)
                | (*img[20+9]++ << 2)
                | (*img[20+10]++ << 1)
                | (*img[20+11]++);

            *(ppf++ + 5 * _ARENA_SCANLINES) = (*img[20+12]++)
                | (*img[20+13]++ << 1)
                | (*img[20+14]++ << 2)
                | (*img[20+15]++ << 3)
                | (*img[20+16]++ << 4)
                | (*img[20+17]++ << 5)
                | (*img[20+18]++ << 6)
                | (*img[20+19]++ << 7);

        }
    }  
}

