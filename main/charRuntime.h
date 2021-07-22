#ifndef __CHARRUNTIME_H
#define __CHARRUNTIME_H

    #include "characterset.h"

extern const unsigned char DIRTY[];
extern const unsigned char DIRT1[];
extern const unsigned char DIRT2[];
extern const unsigned char DIRT3[];
extern const unsigned char DIRT4[];
extern const unsigned char DIRT5[];
extern const unsigned char DIRT6[];
extern const unsigned char DIRT7[];
extern const unsigned char DIRT8[];
extern const unsigned char DIRT9[];
extern const unsigned char DIRTA[];
extern const unsigned char DIRTB[];
extern const unsigned char DIRTC[];
extern const unsigned char DIRTD[];
extern const unsigned char DIRTE[];
extern const unsigned char DIRTF[];

void buildRuntimeDirt();
void roundDirtCorner(unsigned char *this);

#endif
