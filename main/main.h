#ifndef __MAIN_H
#define __MAIN_H

    #include <stdbool.h>


#define ENABLE_OVERLAY 0
#define ENABLE_SOUND 1
#define ENABLE_DRIP 0
#define ENABLE_PARALLAX 1
#define ENABLE_TOGGLE_DISPLAY_ON_DEATH 0
#define ENABLE_SHAKE 1
#define ENABLE_EGG 0

#define DEF_OVERVIEW 0x80
#define DEF_PARALLAX 0x40

#define DEBUG_SLOWDOWN 1
#define GAMESPEED 11


#define PIECE_DEPTH 21
#define SPRITE_DEPTH 23

#define DIAMOND_PULSE_EDGE 60


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


extern int rockfordX;
extern int rockfordY;

extern int frameAdjustX;
extern int frameAdjustY;
extern int frameAdjustSmallX;
extern int frameAdjustSmallY;
extern bool rockfordDead;


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


#endif
