#ifndef __CHARRUNTIME_H
#define __CHARRUNTIME_H

    #include "characterset.h"

extern const unsigned char CHAR_DIRT[];
extern const unsigned char CHAR_DIRT1[];
extern const unsigned char CHAR_DIRT2[];
extern const unsigned char CHAR_DIRT3[];
extern const unsigned char CHAR_DIRT4[];
extern const unsigned char CHAR_DIRT5[];
extern const unsigned char CHAR_DIRT6[];
extern const unsigned char CHAR_DIRT7[];
extern const unsigned char CHAR_DIRT8[];
extern const unsigned char CHAR_DIRT9[];
extern const unsigned char CHAR_DIRTA[];
extern const unsigned char CHAR_DIRTB[];
extern const unsigned char CHAR_DIRTC[];
extern const unsigned char CHAR_DIRTD[];
extern const unsigned char CHAR_DIRTE[];
extern const unsigned char CHAR_DIRTF[];

void buildRuntimeDirt();
void roundDirtCorner(unsigned char *this);

#endif
