#ifndef __CHARACTERSET_H
#define __CHARACTERSET_H


#define ____ 0b00000,
#define ___X 0b00001,
#define __X_ 0b00010,
#define __XX 0b00011,
#define _X__ 0b00100,
#define _X_X 0b00101,
#define _XX_ 0b00110,
#define _XXX 0b00111,
#define X___ 0b01000,
#define X__X 0b01001,
#define X_X_ 0b01010,
#define X_XX 0b01011,
#define XX__ 0b01100,
#define XX_X 0b01101,
#define XXX_ 0b01110,
#define XXXX 0b01111,

#define _ +(0b00000 << 4),
#define X +((unsigned char)(0b10000 << 4)),

#define CHAR_ALLOC (PIECE_DEPTH + 9 + 9)

extern const unsigned char (*charSet[])[];

struct offset {
    unsigned char x;
    unsigned char y;
};

extern const struct offset charOffset[];


#endif

