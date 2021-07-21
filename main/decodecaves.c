/* decodeCaves.c */
/* This program decodes the Boulder Dash I cave data from the Commodore 64
   implementation into human-readable instructions (with minimal HTML
   formatting) and an ASCII diagram.
   
   Boulder Dash I by: Peter Liepa
   This program written by:
       Jeff Bevis <bevis@ecn.purdue.edu>
       Peter Broadribb <peterb@perth.dialix.oz.au>
   28 Aug 1995
   
   01 Oct 1995: Fixed bug in NextRandom(); I have now checked the output
   of NextRandom() against the output of the original 6510 code, and they
   appear to be generating the same numbers. However, the cave data,
   although _almost_ correct, doesn't seem exactly right. I'm puzzled. [PB]
   
   */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

#define NDEBUG /* Uncomment if you don't want assertion */
#include <assert.h>
#include "defines_from_dasm_for_c.h"
//#include "defines_cdfj.h"
#include "attribute.h"
#include "characterset.h"

extern void* DDR;
#define RAM ((unsigned char*)DDR)


/* **************************************** */
/* Types */
typedef const unsigned char UBYTE;
typedef unsigned char objectType;



/* **************************************** */
/* Global data */

/* Coded cave data */
//#include "cavedata.h"


/* Creature code conversion table */
/* Converts the C64 BoulderDash codes into the codes used by Jeff Bevis's
   Amiga implementation of BoulderDash. */
/*UBYTE creatureCode[64]=
{
    ' ', '.', 'w', 'm', 'P', 'P', '?', 'W',
    'q', 'o', 'Q', 'O', 'q', 'o', 'Q', 'O',
    'r', 'r', 'r', 'r', 'd', 'd', 'd', 'd',
    '?', '?', '?', '?', '?', '?', '?', '?',
    '?', '?', '?', '?', '3', 'X', '5', '6',
    '?', '?', '?', '?', '?', '?', '?', '?',
    'B', 'c', 'b', 'C', 'B', 'c', 'b', 'C',
    '7', '8', 'a', 'a', '?', '?', '?', '?' 
};*/


/*
const char *objects[]=
{
    "zSpace", "zDirt", "zBrick", "zMagic", "zPreOut", "zOutBox", "*", "zSteel",
    "zFFly1", "zFFly2", "zFFly3", "zFFly4", "zFFly1M", "zFFly2M", "zFFly3M",
    "zFFly4M", "zBouS", "zBouSM", "zBouF", "zBouFM", "zDiaS", "zDiaSM", "zDiaF",
    "zDiaFM", "", "", "", "zExp1S", "zExp2S", "zExp3S", "zExp4S", "zExp5S",
    "zExp1D", "zExp2D", "zExp3D", "zExp4D", "zExp5D", "zPRFd1", "zPRFd2", "zPRFd3",
    "zPRFd4", "", "", "", "", "", "", "", "zBFly1", "zBFly2",
    "zBFly3", "zBFly4", "zBFly1M", "zBFly2M", "zBFly3M", "zBFly4M", "zRFd",
    "zRFdM", "zAmoe", "zAmoeM", "", "", "*", "*"
};
*/

/* DrawLine data */
/* When drawing lines, you can draw in all eight directions. This table gives
   the offsets needed to move in each of the 8 directions. */
const int ldx[8]={ 0,  1, 1, 1, 0, -1, -1, -1};
const int ldy[8]={-1, -1, 0, 1, 1,  1,  0, -1};



unsigned char *caveData = (unsigned char *)_BOARD;


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
extern int extraDiamondValue;
extern int diamonds;
extern int time;
extern int millingTime;

    RandSeed1 = 0;
    RandSeed2 = acaveData[4+level]; //todo:level


    diamondValue = acaveData[2];
    extraDiamondValue = acaveData[3];

    extern int lava;
    extern int water;
    extern int parallax;

    lava = acaveData[19] * 21;
    water = acaveData[20] * 21;



    caveFlags = acaveData[21];


    displayMode = acaveData[21] & 0x80 ? OVERVIEW : NORMAL;
    parallax = acaveData[21] & 0x40;

    diamonds = acaveData[9+level]; 
    
    time = (acaveData[14+level]<<8)+60;

    millingTime = (acaveData[1] * 60);

    
//    if (!acaveData[22] && !acaveData[23])
//        DrawFilledRect(CH_DIRTY,0,0,40,22,CH_DIRTY);         // legacy
//    else

        DrawRect(CH_STEELWALL_0, 0, -1, 40, 24);
        DrawFilledRect(acaveData[22], 0, 0, 40, 22, acaveData[23]); 
//        StoreObject(39,1, 7);

    // Decode the random cave data
    for(int y = 1; y <=21; y++) {
        for(int x = 0; x <= 39; x++) {
            NextRandom(&RandSeed1, &RandSeed2);

            for (caveDataIndex = 0; caveDataIndex <= 3; caveDataIndex++)
                if (RandSeed1 < acaveData[0x1C + caveDataIndex]) {
                    objectType theObject = acaveData[0x18 + caveDataIndex];
                    StoreObject(x, y, theObject);
                }
        }     
    }  

    DrawRect(acaveData[22], 0, 0, 40, 22);


    caveDataIndex = 0x20;

}


int caveDataIndex;



bool DecodeExplicitData() {

    // Decode the explicit cave data */

    int theWidth, theHeight, theFill, theLength, theDirection;
    int theCode = decodingCave[caveDataIndex];
    int theObject = theCode & 0x3F;
    int x,y;

    switch(0b11000000 & theCode) {
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
        //DrawRect(CH_STEELWALL_0, 0, 2, 40, 22);
        return true;
    }

    else
        return false;

}


/* **************************************** */
void StoreObject(int x, int y, objectType anObject) {
    if (x >=0 && x < 40 && y >= -1 && y <= 22)
        RAM[_BOARD + x + (y+1)*40] = anObject;
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
void NextRandom(int *RandSeed1, int *RandSeed2)
/* This is the mathematical random number generator from the Commodore 64
   implementation of Boulder Dash I. The 6510 disassembly is given in
   comments, and the C translation follows. */
{
    short TempRand1;
    short TempRand2;
    short carry;
    short result;

    assert(((*RandSeed1 >= 0x00) && (*RandSeed1 <= 0xFF)));
    assert(((*RandSeed2 >= 0x00) && (*RandSeed2 <= 0xFF)));

/*
            7085 NextRandom.00  LDA RandSeed1
            7087                ROR
            7088                ROR
            7089                AND #$80
            708B                STA TempRand1
        
            Note: ROR on the 6510 works like this:
              7-->6-->5-->4-->3-->2-->1-->0-->C
              ^                               |
              |_______________________________|
            In other words, it's a nine-bit rotate. Thus it takes two RORs to shift
            the low bit (bit zero) into the high bit (bit 7).
*/
    TempRand1 = (*RandSeed1 & 0x0001) * 0x0080;	/* Bugfix! */


        /*
            708E                LDA RandSeed2
            7090                ROR
            7091                AND #$7F
            7093                STA TempRand2
        */
    TempRand2 = (*RandSeed2 >> 1) & 0x007F;


        /*
            7096                LDA RandSeed2
            7098                ROR
            7099                ROR
            709A                AND #$80
            709C                CLC
            709D                ADC RandSeed2
        */
    result = (*RandSeed2) + (*RandSeed2 & 0x0001) * 0x0080;
    carry = (result > 0x00FF);
    result = result & 0x00FF;


        /*
            709F                ADC #$13
            70A1                STA RandSeed2
        */
    result = result + carry + 0x13;
    carry = (result > 0x00FF);
    *RandSeed2 = result & 0x00FF;


        /*
            70A3                LDA RandSeed1
            70A5                ADC TempRand1
        */
    result = *RandSeed1 + carry + TempRand1;
    carry = (result > 0x00FF);
    result = result & 0x00FF;


        /*
            70A8                ADC TempRand2
            70AB                STA RandSeed1
            70AD                RTS
        */
    result = result + carry + TempRand2;
    *RandSeed1 = result & 0x00FF;

    assert(((*RandSeed1 >= 0x00) && (*RandSeed1 <= 0xFF)));
    assert(((*RandSeed2 >= 0x00) && (*RandSeed2 <= 0xFF)));
}



/* **************************************** */
