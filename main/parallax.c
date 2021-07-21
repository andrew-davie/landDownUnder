// parralax.c

    #include "parallax.h"

unsigned char parallaxBlank[PARALLAX_SIZE];


void initParallax() {

    for (int i = 0; i < PARALLAX_SIZE; i++)
        parallaxBlank[i] = 1; //getRandom32(); //0
}
