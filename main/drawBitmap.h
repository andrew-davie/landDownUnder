#ifndef __DRAWBITMAP_H
#define __DRAWBITMAP_H

#include <stdbool.h>

extern const unsigned char rocketShip[];
extern const unsigned char rocketShipLeg[];
extern const unsigned char rocketShipFlame[];
extern void drawBitmap(const unsigned char *bmp, int x, int y, bool relativeToScreen);


#endif
