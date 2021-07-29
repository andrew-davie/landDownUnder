
    #include "main.h"    
    #include "charRuntime.h"
    #include "attribute.h"
    

#define DIRTBLOCK(mask0, mask1, mask2, mask3) \
\
    ( XX  0b1011) & ~(mask0), \
    ( __  0b0000) & ~(mask0), \
    ( __  0b0000) & ~(mask0), \
    ( XX  0b1110) & ~(mask1), \
    ( __  0b0000) & ~(mask1), \
    ( __  0b0000) & ~(mask1), \
    ( XX  0b1011), \
    ( __  0b0000), \
    ( __  0b0000), \
          0b1110, \
          0b0000, \
          0b0000, \
          0b1111, \
          0b0000, \
          0b0000, \
          0b1101 & ~(mask2), \
          0b0000 & ~(mask2), \
          0b0000 & ~(mask2), \
          0b0111 & ~(mask3), \
          0b0000 & ~(mask3), \
          0b0000 & ~(mask3),


const unsigned char CHAR_DIRT[] = {
    DIRTBLOCK(0, 0, 0, 0)
};

const unsigned char CHAR_DIRT1[] = {
    DIRTBLOCK(0b1001, 0, 0, 0)
};


const unsigned char CHAR_DIRT2[] = {
    DIRTBLOCK(0b0001, 0, 0b0001, 0b0001)
};


const unsigned char CHAR_DIRT3[] = {
    DIRTBLOCK(0b1001, 0, 0b0001, 0b0011)
};


const unsigned char CHAR_DIRT4[] = {
    DIRTBLOCK(0, 0, 0b1000, 0b1000)
};


const unsigned char CHAR_DIRT5[] = {
    DIRTBLOCK(0b0001, 0, 0, 0b1000)
};


const unsigned char CHAR_DIRT6[] = {
    DIRTBLOCK(0b1000, 0, 0b1000, 0b1001)
};


const unsigned char CHAR_DIRT7[] = {
    DIRTBLOCK(0b0001, 0, 0, 0b1001)
};


const unsigned char CHAR_DIRT8[] = {
    DIRTBLOCK(0b1000, 0b1000, 0, 0)
};


const unsigned char CHAR_DIRT9[] = {
    DIRTBLOCK(0b1001, 0b1000, 0, 0)
};


const unsigned char CHAR_DIRTA[] = {
    DIRTBLOCK(0b1000, 0b1000, 0, 0b0001)
};


const unsigned char CHAR_DIRTB[] = {
    DIRTBLOCK(0b1001, 0b1000, 0, 0b0001)
};


const unsigned char CHAR_DIRTC[] = {
    DIRTBLOCK(0b1000, 0b1000, 0, 0b1001)
};


const unsigned char CHAR_DIRTD[] = {
    DIRTBLOCK(0b1001, 0b1000, 0, 0b1000)
};

const unsigned char CHAR_DIRTE[] = {
    DIRTBLOCK(0b1000, 0b1000, 0, 0b1001)
};


const unsigned char CHAR_DIRTF[] = {
    DIRTBLOCK(0b1001, 0, 0, 0b1001)
};

extern const int dir[]; // = { -1, 1, -40, 40, -41, 41, -39, 39 };

//                                  ULDR
const unsigned char dirBits[] = { 0b0100, 0b0001, 0b1000, 0b0100, 0b1100, 0b0110, 0b1001, 0b0110, };


void roundDirtCorner(unsigned char *this) {

    unsigned char roundedDirt = 0;

    for (int i = 0; i < 8; i++)
        if (Attribute[CharToType[*(this + dir[i])]] & ATT_ROUNDDIRT)
            *this |= dirBits[i];

    *this = roundedDirt + CH_DIRT;
}

