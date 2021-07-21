#ifndef __PIECES_H
#define __PIECES_H

extern const unsigned char (*charSet[])[];

struct offset {
    unsigned char x;
    unsigned char y;
};

extern const struct offset charOffset[];


#endif

