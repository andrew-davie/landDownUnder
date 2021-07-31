// Object attributes

    #include "attribute.h"
    #include "characterset.h"
    #include "main.h"




const int Attribute[] = {

// index via ObjectType value

#define _ 0

#define RKF ATT_ROCKFORDYBLANK
#define PSH ATT_PUSH
#define SSP ATT_SEMIBLANK
#define WTR ATT_WATER
#define LAV ATT_LAVA
#define QUI ATT_NOROCKNOISE
#define XIT ATT_EXIT
#define HRD ATT_HARD
#define SQB ATT_SQUASHABLE_TO_BLANKS
#define ACT ATT_ACTIVE
#define BNG ATT_EXPLODES
#define GRB ATT_GRAB
#define SQD ATT_SQUASHABLE_TO_DOGES
#define SPC ATT_BLANK
#define PER ATT_PERMEABLE
#define XPD ATT_EXPLODABLE
#define FLY ATT_KILLS_FLY
#define ROL ATT_ROLL
#define DRP ATT_DRIP
#define RND ATT_ROUNDDIRT

//                                         e           k
//                                        s           n               m           e
//           t       y       k           i           a               a       e   l
//          r       d       n           o           l       s       i       l   b   y
//         i       r       a           n           B       e       D       b   a   l
//        D       o       l           k           h   e   d       h       a   d   F
//       d       f       b   r       c           s   v   o       s   k   e   o   s
//      n   p   k   h   i   e   a   o   t   d   a   i   l   b   a   n   m   l   l   1
//     u   i   c   s   m   t   v   R   i   r   u   t   p   a   u   a   r   p   l   l
//    o   r   o   u   e   a   a   o   x   a   q   c   x   r   q   l   e   x   i   o
//   R   D   R   P   S   W   L   N   E   H   S   A   E   G   S   B   P   E   K   R
//   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
//  RND DRP RKF PSH SSP WTR LAV QUI XIT HRD SQB ACT BNG GRB SQD SPC PER XPD FLY ROL

    RND| _ |RKF| _ | _ |WTR|LAV|QUI| _ | _ | _ | _ | _ | _ | _ |SPC|PER|XPD| _ | _  , // 00 BLANK (parallax)
    RND| _ |RKF| _ | _ |WTR|LAV|QUI| _ | _ | _ | _ | _ | _ | _ |SPC|PER|XPD| _ | _  , // 01 BLANK_SKY
     _ |DRP| _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 02 DIRT
     _ |DRP| _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ |BNG| _ | _ | _ | _ |XPD| _ |ROL , // 03 BRICKWALL  
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 04 OUTBOX_PRE 
     _ | _ | _ | _ | _ | _ | _ | _ |XIT| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 05 OUTBOX  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 06 BOULDER_FALLING  
     _ | _ | _ | _ | _ | _ | _ | _ | _ |HRD| _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 07 STEEL  
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT|BNG| _ | _ | _ | _ |XPD| _ |ROL , // 08 BOULDER 
    RND| _ | _ | _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ |GRB| _ | _ | _ |XPD| _ | _  , // 09 DOGE  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 10 EXPLODE_SPACE_0  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 11 EXPLODE_SPACE_1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 12 EXPLODE_SPACE_2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 13 EXPLODE_SPACE_3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 14 EXPLODE_SPACE_4  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 15 EXPLODE_DOGE_0
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 16 EXPLODE_DOGE_1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 17 EXPLODE_DOGE_2
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 18 EXPLODE_DOGE_3
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 19 EXPLODE_DOGE_4
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 20 ROCKFORD_PRE  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ |SQB|ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 21 ROCKFORD
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD|FLY| _  , // 22 AMOEBA  
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 23 DRIP 
    RND| _ |RKF| _ | _ | _ |LAV| _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER| _ | _ | _  , // 24 DRIP_SPLASH
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 25 __NOTHING  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 26 EXPLODE_THIS  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 27 BLANK_THIS 
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 28 RUBBLE
    RND| _ | _ | _ | _ |WTR|LAV| _ | _ | _ | _ | _ | _ | _ | _ | _ |PER|XPD| _ | _  , // 29 RUBBLE1
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 30 EXPLODE_BLANK_0  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 31 EXPLODE_BLANK_1  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 32 EXPLODE_BLANK_2  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 33 EXPLODE_BLANK_3  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 34 EXPLODE_BLANK_4  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC| _ |XPD| _ | _  , // 35 DOGE_GRAB  
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ |XPD| _ | _  , // 36 DIRT_GRAB  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 37 DUST 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 38 DUST2
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 39 DUST3
    RND| _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT| _ | _ | _ | _ | _ |XPD| _ |ROL , // 40 BOULDER_SHAKE 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 41 DUST_LEFT  
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 42 DUST2_LEFT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 43 DUST3_LEFT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 44 DUST_RIGHT 
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 45 DUST2_RIGHT
    RND| _ |RKF| _ | _ | _ | _ |QUI| _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 46 DUST3_RIGHT
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 47 LAVA 
    RND| _ |RKF| _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ |SPC|PER|XPD| _ | _  , // 48 WATER
    RND| _ | _ | _ | _ | _ | _ | _ | _ | _ |SQB|ACT| _ | _ | _ | _ |PER| _ | _ | _  , // 49 EGG  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 50 ZZAP 
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 51 ZZAP1
     _ | _ | _ |PSH| _ | _ | _ | _ | _ |HRD| _ |ACT|BNG| _ | _ | _ | _ |XPD| _ |ROL , // 52 ROCK  
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 53 DRILL
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |ACT| _ | _ | _ | _ | _ | _ | _ | _  , // 54 DRILLBODY
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 55 BELT
     _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _  , // 56 BELT2

//  RND|DRP RKF PSH SSP WTR LAV QUI XIT HRD SQB ACT BNG GRB SQD SPC PER XPD FLY ROL
//   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
//   R   D   R   P   S   W   L   N   E   H   S   A   E   G   S   B   P   E   K   R
//    o   r   o   u   e   a   a   o   x   a   q   c   x   r   q   l   e   x   i   o
//     u   i   c   s   m   t   v   R   i   r   u   t   p   a   u   a   r   p   l   l
//      n   p   k   h   i   e   a   o   t   d   a   i   l   b   a   n   m   l   l   1
//       d       f       b   r       c           s   v   o       s   k   e   o   s
//        D       o       l           k           h   e   d       h       a   d   F
//         i       r       a           n           B       e       D       b   a   l
//          r       d       n           o           l       s       i       l   b   y
//           t       y       k           i           a               a       e   l
//                                        s           n               m           e
//                                         e           k

};

