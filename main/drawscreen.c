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


extern int scrollX;
extern int scrollY;
extern int scrollSpeed;
extern int scrollYSpeed;
extern int targetScrollSpeed;
extern int targetYScrollSpeed;

int accel = 1536, accelY = 160*256;
int decel = 300, decelY =200*16;


// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)

extern int getRandom32();


#define SCROLLSPEED_MAXIMUM_X (30 << 8)
#define SCROLL_MAXIMUM_X (30 << 16)
//#define SCROLL_MAXIMUM_Y (160 << 8)
//#define SCROLL_MAXIMUM_Y (((24 * PIECE_DEPTH/3) - _ARENA_SCANLINES/3) << 16)

//(14*PIECE_DEPTH/3-2)<<16

#define SCROLLSPEED_MAXIMUM_Y (300 << 8)
#define SCROLL_MAXIMUM_Y (95 << 16)
//^^^ this will change to calc based on boardHeight

#define SCROLL_MINIMUM 0

#define SCROLLEDGER 6
#define SCROLLEDGERY 11


void Scroll() {

    int rocky = rockfordX * PIXELS_PER_CHAR + (PIXELS_PER_CHAR >> 1);
    int halfway = (scrollX >> 14) + HALFWAYX;

    if ((halfway - SCROLLEDGER)- rocky > 0)
        targetScrollSpeed = -SCROLLSPEED_MAXIMUM_X;
    else if (rocky - (halfway + SCROLLEDGER) > 0)
        targetScrollSpeed = SCROLLSPEED_MAXIMUM_X;

    rocky = rockfordY * TRILINES /*+ (TRILINES >> 1)*/;
    halfway = (scrollY >> 16) + (_ARENA_SCANLINES - SCORE_SCANLINES) / 6; // + HALFWAYY;

    if ((halfway - SCROLLEDGERY) - rocky > 0)
        targetYScrollSpeed = -SCROLLSPEED_MAXIMUM_Y;
    else if (rocky - (halfway + SCROLLEDGERY) > 0)
        targetYScrollSpeed = SCROLLSPEED_MAXIMUM_Y;



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

    int maxX = (boardWidth - 10) << 16;


    scrollX += scrollSpeed;
    if (scrollX > maxX) {
        scrollX = maxX;
        targetScrollSpeed = 0;
        scrollSpeed = 0;
    }

    if (scrollX < SCROLL_MINIMUM) {
        scrollX = SCROLL_MINIMUM;
        scrollSpeed = 0;
        targetScrollSpeed = 0;
    }


    scrollY += scrollYSpeed;
    if (scrollY > SCROLL_MAXIMUM_Y) {
        scrollY = SCROLL_MAXIMUM_Y;
        scrollYSpeed = 0;
        targetYScrollSpeed = 0;
    }


    if (scrollY < SCROLL_MINIMUM) {
        scrollY = SCROLL_MINIMUM;
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
    
    p0 = RAM + buf[0][VIDBUF_PF0_LEFT]; //&RAM[_BUF_PF0_LEFT];
    p1 = RAM + buf[0][VIDBUF_PF1_LEFT]; //&RAM[_BUF_PF1_LEFT];
    p2 = RAM + buf[0][VIDBUF_PF2_LEFT]; //&RAM[_BUF_PF2_LEFT];
    p3 = RAM + buf[0][VIDBUF_PF0_RIGHT]; //&RAM[_BUF_PF0_RIGHT];
    p4 = RAM + buf[0][VIDBUF_PF1_RIGHT]; //&RAM[_BUF_PF1_RIGHT];
    p5 = RAM + buf[0][VIDBUF_PF2_RIGHT]; //&RAM[_BUF_PF2_RIGHT];

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
        rinc += 75; // = (((rinc << 4) + (rinc << 1)) >> 4) + 1;

        circle(centerX-1, centerX, (radius>>5) * (radius>>5));
    }

    if (!audUnc && (radius>>5) >= desiredRadius) {
        audUnc = true;
        //AddAudio(SFX_UNCOVER);
    }


}


int ascrollX;
int ascrollY;

// unsigned int bgDriftX, bgDriftY;

const unsigned char blankRow[] = {
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
    CH_BLANK,
};



void drawScreen(){


#if ENABLE_PARALLAX

    extern unsigned char parallaxBlank[];
    extern unsigned char charDust2[];
    extern unsigned char charDust3[];
    extern unsigned char charDrip[];
    extern unsigned char charDrip1[];
    extern unsigned char charDrip2[];
    extern unsigned char charDrip3[];
    extern unsigned char charDripX[];

    const unsigned char dirtBG[] = {

        0b00000000, // 00 <
        0b00000000, // 01  
        0b00000000, // 02  
        0b00000000, // 03 <
        0b00000000, // 04  
        0b00010001, // 05  
        0b00000000, // 06 <
        0b00000000, // 07  
        0b00100010, // 08  
        0b00000000, // 09 <
        0b00000000, // 10  
        0b00000000, // 11  
        0b00000000, // 12 <
        0b00000000, // 13  
        0b10001000, // 14  
        0b00000000, // 15 <
        0b00000000, // 16  
        0b00000000, // 17  
        0b00000000, // 18 <
        0b00000000, // 19  
        0b01000100, // 20  
    };

    extern int parallax;

    for (int i = 0; i < PIECE_DEPTH; i++)
        parallaxBlank[i] = 0;


    if (parallax) {


#if ENABLE_SHAKE
    extern int shakeX, shakeY;
        int yOffset = ((scrollY + shakeY/* + bgDriftY*/) >> 17) * 3;        // 1/2 for parallax
        int offset = ((scrollX + shakeX/* + bgDriftX*/) >> 15) & 3;
#else
        int yOffset = ((scrollY/* + bgDriftY*/) >> 17) * 3;                 // 1/2 for parallax
        int offset = ((scrollX /* + bgDriftX*/) >> 15) & 3;
#endif

        while (yOffset >= PIECE_DEPTH)
            yOffset -= PIECE_DEPTH;
        yOffset = PIECE_DEPTH - yOffset + 1;

        for (int i = 0; i < PIECE_DEPTH; i++) {
            int cidx = yOffset + i;
            while (cidx >= PIECE_DEPTH)
                cidx -= PIECE_DEPTH;
            parallaxBlank[i] = (dirtBG[cidx] >> offset) & 0b1111;
        }


#if ENABLE_EXTRA_SHIMMER
// not implemented: overview part
#define DOTS 5
        
        static int shift[DOTS], ppos[DOTS];

        if ((frameToggler & 1) == 0) {



            for (int i = 0; i < DOTS; i++) {
                ppos[i] = (((getRandom32() & 0xFF) * PIECE_DEPTH) >> 8);
                shift[i] = getRandom32() & 3;
            }
        }

        for (int i = 0; i < DOTS; i++) {
            unsigned char colr = 0b0001 << shift[i];
            unsigned char npos = ppos[i];
            for (int j = 0; j < 3; j++) {
                parallaxBlank[npos++] |= colr;
                if (npos >= PIECE_DEPTH)
                    npos -= PIECE_DEPTH;
            }
        }
#endif

    }


extern const unsigned char CHAR_DRIP[];
extern const unsigned char CHAR_DRIP1[];
extern const unsigned char CHAR_DRIP2[];
extern const unsigned char CHAR_DRIP3[];
extern const unsigned char CHAR_DRIPX[];
extern const unsigned char DOGEA[];
extern const unsigned char DOGEx1[];
extern const unsigned char DOGEx2[];
extern const unsigned char DOGEx3[];
extern const unsigned char DOGEx4[];
extern const unsigned char DOGEx5[];

//extern const unsigned char DUST2[];
extern const unsigned char DUST3[];

    for (int i=0; i < PIECE_DEPTH; i++) {

         charDrip[i] = CHAR_DRIP[i] | parallaxBlank[i];
         charDrip1[i] = CHAR_DRIP1[i] | parallaxBlank[i];
         charDrip2[i] = CHAR_DRIP2[i] | parallaxBlank[i];
         charDrip3[i] = CHAR_DRIP3[i] | parallaxBlank[i];
         charDripX[i] = CHAR_DRIPX[i] | parallaxBlank[i];
        // charDogeCoin[i] = DOGEA[i] | parallaxBlank[i];
        // charDogeCoin1[i] = DOGEx1[i] | parallaxBlank[i];
        // charDogeCoin2[i] = DOGEx2[i] | parallaxBlank[i];
        // charDogeCoin3[i] = DOGEx3[i] | parallaxBlank[i];
        // charDogeCoin4[i] = DOGEx4[i] | parallaxBlank[i];
        // charDogeCoin5[i] = DOGEx5[i] | parallaxBlank[i];

//        charDust2[i] = DUST2[i] | parallaxBlank[i];
        charDust3[i] = DUST3[i] | parallaxBlank[i];

    }



#endif


    // The following draws the screen!

#if ENABLE_SHAKE

    extern int shakeX, shakeY;

    int lcount = -((scrollY + shakeY)>>16) * 3;
    int shift = ((scrollX + shakeX) >> 14 ) & 3;

#else

    int lcount = -(scrollY >>16) * 3;
    int shift = (scrollX >> 14 ) & 3;

#endif





    int startRow = 0;
    while (lcount <= -PIECE_DEPTH) {
        lcount += PIECE_DEPTH;
        startRow++;
    }


#if ENABLE_SHAKE
    int frac = (scrollX + shakeX) >> 16;
#else
    int frac = scrollX >> 16;
#endif

    int lct = lcount;

    for (int half = 0; half < 2; half++) { 

        int scanline = 0;
        lcount = lct;

        int base = half ? VIDBUF_PF0_RIGHT : VIDBUF_PF0_LEFT;

        unsigned char *pf0 = RAM + buf[0][base] + SCORE_SCANLINES;
        unsigned char *pf1 = RAM + buf[0][base + 1] + SCORE_SCANLINES;
        unsigned char *pf2 = RAM + buf[0][base + 2] + SCORE_SCANLINES;


        int rnd = 0;

        for (int row = startRow; scanline < SCANLINES; row++) {

            int xOffset = (half * 5) + frac;
            unsigned char *xchar = RAM + _BOARD + row * boardWidth + xOffset;

            if (row >= boardHeight)
                xchar = blankRow;

            const unsigned char *image[6];


            for (int ch = 0; ch < 6; ch++) {

                unsigned char piece = *xchar;
                unsigned char type = CharToType[piece];

                switch (type) {
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
                case TYPE_DIRT:
                    break;

                default:

                    if (Animate[type])
                        piece = (*Animate[type])[AnimIdx[type].index];
                }

                image[ch] = *charSet[piece];
                xchar++;
            }


            for (int y = 0; scanline < SCANLINES && y < PIECE_DEPTH; y++) {

                int p = (*image[0]++ & 0b1111) << 20
                      | (*image[1]++ & 0b1111) << 16
                      | (*image[2]++ & 0b1111) << 12
                      | (*image[3]++ & 0b1111) << 8
                      | (*image[4]++ & 0b1111) << 4
                      | (*image[5]++ & 0b1111);

                p >>= 4 - shift;

                if (lcount++ >= 0 ) {
                    *pf0++ = BitRev[(p >> 16) & 0b1111];
                    *pf1++ = p >> 8;
                    *pf2++ = BitRev[p & 0b1111] | (BitRev[(p >> 4) & 0b1111] >> 4);
                    scanline++;
                }
            }

        }
    }


}


void drawOverviewScreen() {

    static const unsigned char partStart[] = { 0, 11, 22 };
    static signed char part = 0;

    if (--part < 0)
        part = 1;


    unsigned char *ppf = RAM + buf[0][VIDBUF_PF0_LEFT] + /*RAM + _BUF_PF0_LEFT +*/ partStart[part] * 9;


    // The following draws the screen!

    const unsigned char *img[40];
    for (int i = 0; i < 40; i++)
        img[i] = &CHAR_BLANK;

    int scanline = 0;
    for (int row = partStart[part]; /*scanline < _ARENA_SCANLINES &&*/ row < partStart[part+1]; row++) {


        unsigned char *p = RAM + _BOARD + row * boardWidth;

        for (int i = 0; i < 40; i++) {

            unsigned char p2 = *p;
            unsigned char type = CharToType[p2];

            if (row >= boardHeight)
                type = TYPE_BLANK;


            if (i < boardWidth)
                switch (type) {
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

                    if (Animate[type])
                        p2 = (*Animate[type])[AnimIdx[type].index];
                    break;
                }
            else
                p2 = CH_BLANK;

            img[i] = *charSet[p2];
            p++;
        }

        int shift = 7 - ((row + 1) & 1);
        int shift2 = shift - 1;

        for (int iccLine=0; iccLine < 9 /*&& scanline < _ARENA_SCANLINES;*/; scanline++, iccLine++) {

            *ppf = (((*img[0]++ >> 6) & 1) << 4)
                | (((*img[1]++ >> 7) & 1) << 5)
                | (((*img[2]++ >> 6) & 1) << 6)
                | (((*img[3]++ >> 7) & 1) << 7);

            *(ppf + _ARENA_SCANLINES) = (((*img[4]++ >> 6) & 1) << 7)
                | (((*img[5]++ >> 7) & 1) << 6)
                | (((*img[6]++ >> 6) & 1) << 5)
                | (((*img[7]++ >> 7) & 1) << 4)
                | (((*img[8]++ >> 6) & 1) << 3)
                | (((*img[9]++ >> 7) & 1) << 2)
                | (((*img[10]++ >> 6) & 1) << 1)
                | (((*img[11]++ >> 7) & 1));

            *(ppf + 2 * _ARENA_SCANLINES) = (((*img[12]++ >> 6) & 1))
                | (((*img[13]++ >> 7) & 1) << 1)
                | (((*img[14]++ >> 6) & 1) << 2)
                | (((*img[15]++ >> 7) & 1) << 3)
                | (((*img[16]++ >> 6) & 1) << 4)
                | (((*img[17]++ >> 7) & 1) << 5)
                | (((*img[18]++ >> 6) & 1) << 6)
                | (((*img[19]++ >> 7) & 1) << 7);

            *(ppf + 3 * _ARENA_SCANLINES) = (((*img[20+0]++ >> 6) & 1) << 4)
                | (((*img[20+1]++ >> 7) & 1) << 5)
                | (((*img[20+2]++ >> 6) & 1) << 6)
                | (((*img[20+3]++ >> 7) & 1) << 7);

            *(ppf + 4 * _ARENA_SCANLINES) = (((*img[20+4]++ >> 6) & 1) << 7)
                | (((*img[20+5]++ >> 7) & 1) << 6)
                | (((*img[20+6]++ >> 6) & 1) << 5)
                | (((*img[20+7]++ >> 7) & 1) << 4)
                | (((*img[20+8]++ >> 6) & 1) << 3)
                | (((*img[20+9]++ >> 7) & 1) << 2)
                | (((*img[20+10]++ >> 6) & 1) << 1)
                | (((*img[20+11]++ >> 7) & 1));

            *(ppf++ + 5 * _ARENA_SCANLINES) = ((*img[20+12]++ >> 6) & 1)
                | (((*img[20+13]++ >> 7) & 1) << 1)
                | (((*img[20+14]++ >> 6) & 1) << 2)
                | (((*img[20+15]++ >> 7) & 1) << 3)
                | (((*img[20+16]++ >> 6) & 1) << 4)
                | (((*img[20+17]++ >> 7) & 1) << 5)
                | (((*img[20+18]++ >> 6) & 1) << 6)
                | (((*img[20+19]++ >> 7) & 1) << 7);

        }
    }  
}



void drawPlanet() {

    // unsigned char *const arenas[] = {
    //     RAM + _BUF_PF0_LEFT + SCORE_SCANLINES,
    //     RAM + _BUF_PF0_RIGHT + SCORE_SCANLINES,
    // };


    int lcount = -(scrollY >>16) * 3;
    int shift = (scrollX >> 14 ) & 3;


    int startRow = 0;
    while (lcount <= -PIECE_DEPTH) {
        lcount += PIECE_DEPTH;
        startRow++;
    }


    for (int row = startRow, scanline = 0; scanline < SCANLINES; row++) {


        int slc = lcount;
        int scn = scanline;
        int frac = scrollX >> 16;
        int rnd = 0;

        for (int half = 0; half < 2; half++) { 


            scanline = scn;
            lcount = slc;

            int xOffset = (half * 5) + frac;
            unsigned char *xchar = RAM + _BOARD + ((row +1 )* 40) + xOffset;
            const unsigned char *image[6];


            for (int ch = 0; ch < 6; ch++) {

                unsigned char piece = *xchar;
                unsigned char type = CharToType[piece];

                switch (type) {
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
                case TYPE_DIRT:
                    break;

                default:

                    if (Animate[type])
                        piece = (*Animate[type])[AnimIdx[type].index];
                }

                image[ch] = *charSet[piece];
                xchar++;
            }

            int base = half ? VIDBUF_PF0_RIGHT : VIDBUF_PF0_LEFT;
            unsigned char *pf0 = RAM + buf[0][base] /*arenas[half]*/ + scanline;


            for (int y = 0; scanline < SCANLINES && y < PIECE_DEPTH; y++) {

                int p = 0;
                for (int pix = 0, pshift=20; pix < 6; pix++, pshift -= 4)
                    p |= ((*(image[pix])++) & 0b1111) << pshift;
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


