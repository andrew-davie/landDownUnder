// parallax
#ifndef __PARALLAX_H
#define __PARALLAX_H

    #include "piece.h"

#define PARALLAX_SIZE (PIECE_DEPTH + SMALLPIECE_DEPTH + SMALLPIECE_DEPTH)

extern unsigned char parallaxBlank[PARALLAX_SIZE];

void initParallax();

#endif
