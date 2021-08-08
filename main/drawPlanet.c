#include "main.h"
#include "drawplanet.h"
#include "defines_from_dasm_for_c.h"
#include "characterset.h"
#include "defines.h"

// duplicate from defines_cdfj.h
// Raw queue pointers
extern void* DDR;
#ifndef RAM
#define RAM ((unsigned char*)DDR)
#endif

int planetX = 20 << 16;
int planetY = (_ARENA_SCANLINES << 16) / 3 / 2;

extern unsigned char blankRow[];



const int masker[] = {
0b000000000000100100010000100000, // 3
0b000000000001010100100100010000, // 6
0b000000000001010101010010010000, // 9
0b000000000001101010101010010000, // 12
0b000000000001101101101001001000, // 15
0b000000000001101101101001001000, // 18
0b000000000001110111010101001000, // 21
0b000000000001111101101101001000, // 24
0b000000000001111101101101001000, // 27
0b000000000001111111011010101000, // 30
0b000000000001111111011010101000, // 33
0b000000000011110111111010101000, // 36
0b000000000011110111111010101000, // 39
0b000000000011110111111010101000, // 42
0b000000000011111111110110100100, // 45
0b000000000011111111110110100100, // 48
0b000000000011111111110110100100, // 51
0b000000000011111111110110100100, // 54
0b000000000011111111110110100100, // 57
0b000000000011111111111101100100, // 60
0b000000000011111111111101100100, // 63
0b000000000011111111111101100100, // 66
0b000000000011111111111101100100, // 69
0b000000000011111111111101100100, // 72
0b000000000011111111111101100100, // 75
0b000000000011111111111101100100, // 78
0b000000000011111111111101100100, // 81
0b000000000011111111111101100100, // 84
0b000000000011111111111101100100, // 87
0b000000000011111111111101100100, // 90
0b000000000011111111111101100100, // 93
0b000000000011111111111101100100, // 96
0b000000000011111111111101100100, // 99
0b000000000011111111111101100100, // 102
0b000000000011111111111101100100, // 105
0b000000000011111111111101100100, // 108
0b000000000011111111110110100100, // 111
0b000000000011111111110110100100, // 114
0b000000000011111111110110100100, // 117
0b000000000011111111110110100100, // 120
0b000000000011111111110110100100, // 123
0b000000000011110111111010101000, // 126
0b000000000011110111111010101000, // 129
0b000000000011110111111010101000, // 132
0b000000000001111111011010101000, // 135
0b000000000001111111011010101000, // 138
0b000000000001111101101101001000, // 141
0b000000000001111101101101001000, // 144
0b000000000001110111010101001000, // 147
0b000000000001101101101001001000, // 150
0b000000000001101101101001001000, // 153
0b000000000001101010101010010000, // 156
0b000000000001010101010010010000, // 159
0b000000000001010100100100010000, // 162
0b000000000000100100010000100000, // 165
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
};


const int shadowMask[] = {

    0b11111111111111111111111111111111, // 0
    0b11111111111111111111111111111111, // 1
    0b11111111111111111111111111111111, // 2
    0b11111111111111111111111111111111, // 3
    0b11111111111111111111111111111111, // 4
    0b11111111111111111111111111111111, // 5
    0b11111111111111111111111111111111, // 6
    0b11111111111111111111111111111111, // 7
    0b11111111111111111111111111111111, // 8
    0b11111111111111111111111111111111, // 9
    0b11111111111111111111111111111111, // 10
    0b11111111111111111111111111111111, // 11
    0b11111111111111111111111111111111, // 12
    0b11111111111111111111111111111111, // 13
    0b11111111111111111111111111111111, // 14
    0b11111111111111111111010101010101, // 41
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111010101010101, // 41
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111010101010101, // 41
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111010101010101, // 41
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111010101010101, // 41
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111101010101010, // 42
    0b11111111111111111111010101010101, // 43
    0b11111111111111111111111111111111, // 57
    0b11111111111111111111111111111111, // 58
    0b11111111111111111111111111111111, // 59
    0b11111111111111111111111111111111, // 60
    0b11111111111111111111111111111111, // 61
    0b11111111111111111111111111111111, // 62
    0b11111111111111111111111111111111, // 63
    0b11111111111111111111111111111111, // 64
    0b11111111111111111111111111111111, // 65
    0b11111111111111111111111111111111, // 66
    0b11111111111111111111111111111111, // 67
    0b11111111111111111111111111111111, // 68
    0b11111111111111111111111111111111, // 69
    0b11111111111111111111111111111111, // 70
    0b11111111111111111111111111111111, // 71
    0b11111111111111111111111111111111, // 72
    0b11111111111111111111111111111111, // 73
    0b11111111111111111111111111111111, // 74
    0b11111111111111111111111111111111, // 75
    0b11111111111111111111111111111111, // 76
    0b11111111111111111111111111111111, // 77
    0b11111111111111111111111111111111, // 78
    0b11111111111111111111111111111111, // 79

    0b11111111111111111111111111111111, // 81
    0b11111111111111111111111111111111, // 82
    0b11111111111111111111111111111111, // 83
    0b11111111111111111111111111111111, // 84

};

const int lineOffset[] = {
47 , // 3
73 , // 6
85 , // 9
105 , // 12
114 , // 15
131 , // 18
140 , // 21
149 , // 24
166 , // 27
172 , // 30
178 , // 33
195 , // 36
201 , // 39
207 , // 42
213 , // 45
227 , // 48
233 , // 51
239 , // 54
245 , // 57
259 , // 60
265 , // 63
271 , // 66
274 , // 69
288 , // 72
294 , // 75
300 , // 78
306 , // 81
320 , // 84
323 , // 87
329 , // 90
335 , // 93
341 , // 96
355 , // 99
358 , // 102
364 , // 105
370 , // 108
384 , // 111
390 , // 114
396 , // 117
402 , // 120
416 , // 123
422 , // 126
428 , // 129
434 , // 132
451 , // 135
457 , // 138
463 , // 141
480 , // 144
489 , // 147
498 , // 150
515 , // 153
524 , // 156
544 , // 159
556 , // 162
582 , // 165




-1,
};


int pscrollSpeed = -500;

void drawPlanet() {

 
    if (SWCHA & 0x40)
        pscrollSpeed += 100;
    if (SWCHA & 0x80)
        pscrollSpeed -= 100;

    scrollX += pscrollSpeed;
    if (scrollX >= (30 << 16))
        scrollX -= (30 << 16);
    if (scrollX < 0)
        scrollX += 30 << 16; //+= (20 << 16);



    int shift = 4- ((scrollX >> 14 ) & 3);
    int frac = scrollX >> 16;
    unsigned char *xchar;
    const unsigned char *image[6];

    for (int half = 0; half < 10; half += 5) { 

        int base = half ? VIDBUF_PF0_RIGHT : VIDBUF_PF0_LEFT;

        unsigned char *pf0 = RAM + buf[base];
        unsigned char *pf1 = RAM + buf[base + 1];
        unsigned char *pf2 = RAM + buf[base + 2];


        for (int scanline = 0; lineOffset[scanline] >= 0 && scanline * 3 < SCANLINES; scanline++) {
            
            xchar = RAM + _BOARD + (half + frac) + boardWidth * (lineOffset[scanline] >> 5);
            int charow = lineOffset[scanline] & 31;

            for (int i = 0; i < 6; i++) {
                unsigned char piece = *xchar++;
                unsigned int type = CharToType[piece];
                //if (Animate[type])
                //    piece = (*Animate[type])[AnimIdx[type].index];
                image[i] = *charSet[piece] + charow;
            }


            int p2;

            int mask = masker[scanline];
            int stipMask = shadowMask[scanline];

            for (int icc = 0; icc < 3; icc++) {

                int p = ((*image[0]++ & 0b1111) << 20
                      | (*image[1]++ & 0b1111) << 16
                      | (*image[2]++ & 0b1111) << 12
                      | (*image[3]++ & 0b1111) << 8
                      | (*image[4]++ & 0b1111) << 4
                      | (*image[5]++ & 0b1111)) >> shift;


                p2 = 0;

                if (!half) {

                    for (int i = 0; i <20; i++)
                        if (mask & (1 << i))
                            p2 = (p2 << 1) | ((p >> (19-i)) & 1);

                }
                else {

                    for (int i = 0; i < 20; i++)
                        if (mask & (1 << i))
                            p2 = (p2 >> 1) | (((p >> i) & 1) << 19);

                    //p2 &= stipMask;
                }



                *pf0++ = BitRev[p2 >> 16];
                *pf1++ = p2 >> 8;
                *pf2++ = BitRev[p2 & 0xFF];
            }
        }
    }


}
