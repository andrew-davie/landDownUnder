#ifndef __MAIN_H
#define __MAIN_H

    #include <stdbool.h>


#define ENABLE_OVERLAY 0
#define ENABLE_SOUND 1
#define ENABLE_DRIP 0
#define ENABLE_PARALLAX 1
#define ENABLE_TOGGLE_DISPLAY_ON_DEATH 0
#define ENABLE_SHAKE 1
#define ENABLE_SHIMMER 0 /* shimmer CH_BLANK on extra life - depecated */

#define DEF_OVERVIEW 0x80
#define DEF_PARALLAX 0x40
#define DEF_DRIP 0x20
#define DEF_PEBBLE 0x10


#define DEBUG_SLOWDOWN 1
#define GAMESPEED 11


#define PIECE_DEPTH 24
#define SPRITE_DEPTH 23

#define DOGE_PULSE_EDGE 60


#define MAXIMUM_AMOEBA_SIZE 200
#define BUBBLE_SPEED 5  /* bigger is faster */
#define LAVA_SPEED 10
#define WATER_SPEED 1


#define PIXELS_PER_CHAR 4
#define HALFWAYX 20
#define HALFWAYY (28+6)
#define TRILINES (PIECE_DEPTH/3)

//#define ATTRACT_TRIGGER 0x200
//#define ATTRACT_PERIOD 0x200

#define SCORE_SCANLINES 21
#define SCANLINES (_ARENA_SCANLINES - SCORE_SCANLINES) 

#define PF0 0
#define PF1 1
#define PF2 2

enum Direction {
    LEFT = -1,
    RIGHT = 1,
};

extern enum Direction rockfordDirection;
extern unsigned char bufferedSWCHA;

extern int rockfordX;
extern int rockfordY;
extern int playerX, playerY;

extern int frameAdjustX;
extern int frameAdjustY;
extern int frameAdjustSmallX;
extern int frameAdjustSmallY;
extern bool rockfordDead;

extern int scrollX;
extern int scrollY;
extern int doge;
extern unsigned int sparkleTimer;

enum DisplayMode {
    NORMAL,
    OVERVIEW,
};

extern enum DisplayMode displayMode;


extern const unsigned char BitRev[];

struct Animation {
    int index;
    int count;
};

extern const char (*Animate[])[];
extern struct Animation AnimIdx[];

void updateAnimation();
void ProcessBoard();

extern void setAnimation(int animID);

extern void* DDR;

#if ENABLE_PARALLAX
extern unsigned char spaceToggle[40];
extern unsigned char spaceToggleDisplayed[40];
#endif

extern void setFlash(int colour, int time);
extern unsigned char ColourConvert(unsigned char color);

#if ENABLE_SHAKE
extern int shakeX;
extern int shakeY;
#endif


extern int doge;
extern unsigned int frameToggler;
extern int boardWidth;
extern int boardHeight;
extern int planetGravity;


#define VIDBUF_COLUPF    0
#define VIDBUF_COLUBK    1
#define VIDBUF_PF0_LEFT  2
#define VIDBUF_PF1_LEFT  3
#define VIDBUF_PF2_LEFT  4
#define VIDBUF_PF0_RIGHT 5
#define VIDBUF_PF1_RIGHT 6
#define VIDBUF_PF2_RIGHT 7
#define VIDBUF_GRP0A     8
#define VIDBUF_GRP1A     9
#define VIDBUF_COLUP0    10
#define VIDBUF_COLUP1    11


extern unsigned int buf[3][12];

#endif
