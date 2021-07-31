
#include "main.h"



void drawPlanet() {

// use circle fade
// width at each line --> steps into bitmap for 1/2 hemisphere
// rotation --> start pointinto bitmap
// bitmap = 40 x 24 board
// predraw planet surface onto bitmap
// use indexes to charset so we can scale
/// draw step-wise, using distance from centre --> trig adjust for steps
// * width of line
// build 40-pix line from center of rotation to edges
// start with sin(0)--> sin(90) in n steps
// --> a divide
// allow offset for x,y centerpoint, so can move planet around (and zoom in!!)
// DON't use circular mask, and then we can put stars in the background
// effectively sprite-draw into bitmap screen
// use mirrored (vert) draw so we don't have to recalculate the steps
//  --> except when offscreen won't work
// use ICC lines, of course




}