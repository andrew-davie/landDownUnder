

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

#define NDEBUG /* Uncomment if you don't want assertion */
#include <assert.h>
#include "defines_from_dasm_for_c.h"
#include "main.h"
//#include "defines_cdfj.h"
#include "attribute.h"
#include "characterset.h"

extern void* DDR;
#define RAM ((unsigned char*)DDR)

#define DEF_XSIZE 1
#define DEF_YSIZE 2
#define DEF_GRAVITY 3
#define DEF_MILL 4
#define DEF_DOGEVALUE 5
#define DEF_DOGEEXTRAVALUE 6
#define DEF_SEED 7
#define DEF_DOGE 12
#define DEF_TIME 17
#define DEF_LAVA 22
#define DEF_WATER 23
#define DEF_FLAGS 24
#define DEF_BORDER 25
#define DEF_FILL 26
#define DEF_RNDSEED 31
#define DEF_RNDOBJECT 27
#define DEF_CAVEDATA 35

/* **************************************** */
/* Types */
typedef const unsigned char UBYTE;
typedef unsigned char objectType;



/* **************************************** */
/* Global data */


/* DrawLine data */
/* When drawing lines, you can draw in all eight directions. This table gives
   the offsets needed to move in each of the 8 directions. */
const int ldx[8]={ 0,  1, 1, 1, 0, -1, -1, -1};
const int ldy[8]={-1, -1, 0, 1, 1,  1,  0, -1};



//unsigned char *caveData = (unsigned char *)_BUFFERS;


/* **************************************** */
/* Prototypes */
void DecodeCave(UBYTE *acaveData);
void StoreObject(int x, int y, objectType anObject);
void DrawLine(objectType anObject, int x, int y, int aLength, int aDirection);
void DrawFilledRect(objectType anObject, int x, int y, int aWidth, int aHeight, objectType aFillObject);
void DrawRect(objectType anObject, int x, int y, int aWidth, int aHeight);
void NextRandom(int *RandSeed1, int *RandSeed2);



int RandSeed1, RandSeed2;
UBYTE *decodingCave;
int caveDataIndex;

int caveFlags;


/* **************************************** */
void DecodeCave(UBYTE *acaveData)
{
    decodingCave = acaveData;


extern int level;
extern int diamondValue;
extern int extraDogeCoinValue;
extern int doge;
extern int time;
extern int millingTime;

    RandSeed1 = 0;
    RandSeed2 = acaveData[DEF_SEED+level]; //todo:level

    boardWidth = acaveData[DEF_XSIZE];
    boardHeight = acaveData[DEF_YSIZE];
    planetGravity = acaveData[DEF_GRAVITY];


    diamondValue = acaveData[DEF_DOGEVALUE];
    extraDogeCoinValue = acaveData[DEF_DOGEEXTRAVALUE];

    extern int lava;
    extern int water;
    extern int parallax;

    lava = acaveData[DEF_LAVA] * PIECE_DEPTH;
    water = acaveData[DEF_WATER] * PIECE_DEPTH;
    caveFlags = acaveData[DEF_FLAGS];

    displayMode = caveFlags & DEF_OVERVIEW ? DISPLAY_OVERVIEW : DISPLAY_NORMAL;
    if (caveFlags & DEF_PLANET)
        displayMode = DISPLAY_PLANET;



    parallax = caveFlags & 0x40;

    doge = acaveData[DEF_DOGE+level]; 
    
    time = (acaveData[DEF_TIME+level]<<8)+60;

    millingTime = (acaveData[DEF_MILL] * 60);

    DrawFilledRect(acaveData[DEF_FILL], 0, 0, boardWidth, boardHeight, acaveData[DEF_FILL]); 

    // Decode the random cave data
    for(int y = 0; y < boardHeight; y++) {
        for(int x = 0; x < boardWidth; x++) {
            NextRandom(&RandSeed1, &RandSeed2);

            for (caveDataIndex = 0; caveDataIndex < 4; caveDataIndex++)
                if ((getRandom32() & 0xFF) < acaveData[DEF_RNDSEED + caveDataIndex]) {
                    objectType theObject = acaveData[DEF_RNDOBJECT + caveDataIndex];


                    if (theObject == CH_CRATER_BIG) {

                        int x2 = x + 1;
                        if (x2 >= 30)
                            x2 -= 30;

                        int y2 = y + 1;
                        if (y2 >= boardHeight)
                            y2 = 0;

                        StoreObject(x, y, theObject);
                        StoreObject(x2, y, theObject+1);
                        StoreObject(x, y2, theObject+2);
                        StoreObject(x2, y2, theObject+3);
                    }

                    else
                        StoreObject(x, y, theObject);


                }
        }     
    }  

    if (acaveData[DEF_BORDER])
        DrawRect(acaveData[DEF_BORDER], 0, 0, boardWidth, boardHeight);

    caveDataIndex = DEF_CAVEDATA;

}


int caveDataIndex;



bool DecodeExplicitData() {

    // Decode the explicit cave data */

    int theWidth, theHeight, theFill, theLength, theDirection;
    int theCommand = decodingCave[caveDataIndex];
    int theObject = decodingCave[++caveDataIndex];
    int x,y;

    switch(theCommand) {
    case 0b00000000: /* PLOT */
        x = decodingCave[++caveDataIndex];
        y = decodingCave[++caveDataIndex];
        StoreObject(x, y, theObject);
        break;

    case 0b01000000: /* LINE */

        x = decodingCave[++caveDataIndex];
        y = decodingCave[++caveDataIndex];
        theLength = decodingCave[++caveDataIndex];
        theDirection = decodingCave[++caveDataIndex];
        DrawLine(theObject, x, y, theLength, theDirection);
        break;

    case 0b10000000: /* FILLED RECTANGLE */
        x = decodingCave[++caveDataIndex];
        y = decodingCave[++caveDataIndex];
        theWidth = decodingCave[++caveDataIndex];
        theHeight = decodingCave[++caveDataIndex];
        theFill = decodingCave[++caveDataIndex];
        DrawFilledRect(theObject, x, y, theWidth, theHeight, theFill);
        break;

    case 0b11000000: /* OPEN RECTANGLE */
        x = decodingCave[++caveDataIndex];
        y = decodingCave[++caveDataIndex];
        theWidth = decodingCave[++caveDataIndex];
        theHeight = decodingCave[++caveDataIndex];
        DrawRect(theObject, x, y, theWidth, theHeight);
        break;
    }


    caveDataIndex++;

    if (decodingCave[caveDataIndex] == 0xFF) {
        //DrawRect(CH_STEEL, 0, 2, 40, 22);
        return true;
    }

    else
        return false;

}


/* **************************************** */
void StoreObject(int x, int y, objectType anObject) {

//    if (anObject == CH_DIRT && (getRandom32() & 0xFF) < 10)
//        anObject = CH_DIRT + (getRandom32() & 0xF);
        
    if (x >=0 && x < boardWidth && y >= 0 && y < boardHeight)
        RAM[_BOARD + x + y * boardWidth] = anObject;
}



/* **************************************** */
void DrawLine(objectType anObject, int x, int y, int aLength, int aDirection) {

    for (int counter = 0; counter < aLength; counter++) {
        StoreObject(x, y, anObject);
        x += ldx[aDirection];
        y += ldy[aDirection];
    }
}

/* **************************************** */
void DrawRect(objectType anObject, int x, int y, int aWidth, int aHeight) {

    DrawLine(anObject, x, y, aWidth, 2);
    DrawLine(anObject, x, y + aHeight - 1, aWidth, 2);
    DrawLine(anObject, x, y, aHeight, 4);
    DrawLine(anObject, x + aWidth - 1, y, aHeight, 4);
}

/* **************************************** */
void DrawFilledRect(objectType anObject, int x, int y, int aWidth, int aHeight, objectType aFillObject) {

    for (int counter1 = aHeight - 2; counter1 > 0; counter1--)
        DrawLine(aFillObject, x, y+counter1, aWidth-1, 2);
    DrawRect(anObject, x, y, aWidth, aHeight);
}


/* **************************************** */
void NextRandom(int *RandSeed1, int *RandSeed2) {

    int rnd = getRandom32();
    *RandSeed1 = rnd & 0xFF;
    *RandSeed2 = (rnd >> 8) & 0xFF;
}



/* **************************************** */
