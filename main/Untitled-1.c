    
#include "drawBitmap.h"
#include "main.h"
#include "bitpatterns.h"
#include "defines_from_dasm_for_c.h"

// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#define RAM ((unsigned char*)DDR)


#define BMP_WIDTH 0
#define BMP_HEIGHT 1
#define BMP_CENTER_X 2
#define BMP_CENTER_Y 3
#define BMP_HEADER_BYTES 4

const unsigned char rocketShip[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    105,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,105,               // center point (PIXELS) from 0,0 top left

    ________    // colour 0
    ________    // colour 1
    ________    // colour 2 etc...
    ___X____ 
    ________ 
    ________ 
    ________ 
    ___X____ 
    ________ 
    ___X____ 
    ___X____ 
    ________ 
    __XXX___ 
    __XXX___ 
    ___XX___ 
    __XXX___ 
    __XXX___ 
    ___XX___ 
    ___X____
    __X_X___ 
    ___XX___ 
    ___X____  // 00
    __XXX___  // 01
    ___X____  // 02
    __XXX___  // 03
    _XXXXX__  // 04
    __XXX___  // 05
    _XXXXX__  // 06
    _XXXXX__  // 07
    __XXXX__  // 08
    _XXXXX__  // 09
    _XXXXX__  // 10
    __XX_X__  // 11
    _XXX_X__  // 12
    _XX_____  // 13
    __X_____  // 14
    _XXX_X__  // 15
    _XXX_X__  // 16
    __XXXX__  // 17
    XXXX_XX_  // 18
    XXXX_XX_  // 19
    _XXXXXX_  // 20
    XXX___X_  // 00
    XXX___X_  // 01
    _XXXXXX_  // 02
    XXX___X_  // 03
    XXX___X_  // 04
    _XXXXXX_  // 05
    XXXX_XX_  // 06
    XXXX_XX_  // 07
    _XXXXXX_  // 08
    XXXXXXX_  // 09
    XXXXXXX_  // 10
    _XXXXXX_  // 11
    XXXX__X_  // 12
    XXXXXXX_  // 13
    _XXXXXX_  // 14
    XXXX__X_  // 15
    XXXXXXX_  // 16
    _XXXXXX_  // 17
    XXXX__X_  // 18
    XXXXXXX_  // 19
    _XXXXXX_  // 20
    XXXXXXX_  // 00
    XXXXXXX_  // 01
    _XXXXXX_  // 02
    XXXXXXX_  // 03
    XXXXXXX_  // 04
    _XXXXXX_  // 05
    XXXXXXX_  // 06
    XXXXXXX_  // 07
    _XXXXXX_  // 08
    XXXXXXX_  // 09
    XXXXXXX_  // 10
    _XXXXXX_  // 11
    XXXXXXX_  // 12
    XXXXXXX_  // 13
    ________  // 14
    _XXXXX__  // 15
    __XXXX__  // 16
    __XXXX__  // 17
    __XXX___  // 18
    _____X__  // 19
    __XXXX__  // 20
    __XXX___ 
    __XXX___ 
    __XXX___ 
    __XXX___ 
    _XX_XX__ 
    _XXXXX__ 
    __XXX___ 
    XXXXXXX_ 
    XXXXXXX_ 
    __XXX___ 
    __XXX___ 
    X_XXX_X_ 
    __XXX___ 
    ________ 
    X_XXX_X_ 
    ___X____ 
    ________ 
    X__X__X_ 
    ________ 
    ________ 
    X_____X_ 
};

const unsigned char rocketShipFlame[] = {

    1,                  // width in BYTES (=8 pix/byte) (MAX =4)
    21,                 // height in SCANLINES (pref multiples of 3 -- TRIPIXs)
    3,0,               // center point (PIXELS) from 0,0 top left

    ________ 
    ________ 
    __XX____ 
    ____X___ 
    __X_X___ 
    __XXX___ 
    __X_X___ 
    ____X___ 
    __XXX___ 
    __X_X___ 
    __X_____ 
    __XXX___ 
    ___X____ 
    ___X____ 
    ___X____ 
    ___X____ 
    ___X____ 
    ___X____ 
    ___X____ 
    ___X____ 
    ___X____ 
};




void drawBitmap(const unsigned char *bmp, int x, int y, bool relativeToScreen) {

    unsigned char pix[40];
    unsigned char pf[3][6];
    unsigned char masker[6];


    int screenStart = relativeToScreen ? 0 : SCORE_SCANLINES;

    for (int i = 0; i < 40; i++)
        pix[i] = 0;

    for (int line = 0; line < bmp[BMP_HEIGHT]; line += 3) {
        int scanline = y + line + screenStart - bmp[BMP_CENTER_Y];
        if (scanline >= screenStart && scanline < _ARENA_SCANLINES - screenStart) {

            for (int ssl = 0; ssl < 3; ssl++) {

                int adjustedIndex = (line + ssl) * bmp[BMP_WIDTH] + BMP_HEADER_BYTES;
                unsigned int bits = 0;
                for (int i = 0; i < bmp[BMP_WIDTH]; i++)
                    bits = (bits << 8) | bmp[adjustedIndex++];
                
                int bitRange = (bmp[BMP_WIDTH] << 3) - 1;
                for (int bit = 0; bit <= bitRange; bit++) {
                    int absBit = x - bmp[BMP_CENTER_X] + bit;
                    if (absBit >= 0 && absBit < 40)
                        pix[absBit] = (bits >> (bitRange - bit)) & 1;
                }

                // convert to PF format

                pf[ssl][0] = (pix[ 0] << 4)          // mirrored
                           | (pix[ 1] << 5)
                           | (pix[ 2] << 6)
                           | (pix[ 3] << 7);
                    
                pf[ssl][1] = (pix[ 4] << 7)          // normal
                           | (pix[ 5] << 6)
                           | (pix[ 6] << 5)
                           | (pix[ 7] << 4)
                           | (pix[ 8] << 3)
                           | (pix[ 9] << 2)
                           | (pix[10] << 1)
                           | (pix[11] << 0);

                pf[ssl][2] = (pix[12] << 0)          // mirrored
                           | (pix[13] << 1)
                           | (pix[14] << 2)
                           | (pix[15] << 3)
                           | (pix[16] << 4)
                           | (pix[17] << 5)
                           | (pix[18] << 6)
                           | (pix[19] << 7);

                pf[ssl][3] = (pix[20] << 4)          // mirrored
                           | (pix[21] << 5)
                           | (pix[22] << 6)
                           | (pix[23] << 7);
                    
                pf[ssl][4] = (pix[24] << 7)          // normal
                           | (pix[25] << 6)
                           | (pix[26] << 5)
                           | (pix[27] << 4)
                           | (pix[28] << 3)
                           | (pix[29] << 2)
                           | (pix[30] << 1)
                           | (pix[31] << 0);

                pf[ssl][5] = (pix[32] << 0)          // mirrored
                           | (pix[33] << 1)
                           | (pix[34] << 2)
                           | (pix[35] << 3)
                           | (pix[36] << 4)
                           | (pix[37] << 5)
                           | (pix[38] << 6)
                           | (pix[39] << 7);
            }

            for (int i = 0; i < 6; i++)
                masker[i] = ~(pf[0][i] | pf[1][i] | pf[2][i]);

            for (int ssl = 0; ssl < 3; ssl++)
                for (int i = 0; i < 6; i++) {
                    unsigned char *screen = _BUF_PF0_LEFT;// + i * _ARENA_SCANLINES + scanline + ssl;
                    *screen = *screen /*& masker[idx]*/ | pf[ssl][i];
                }

        }
    }


}



// EOF
