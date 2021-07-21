
#define SMALL_SPRITE_OFFSET 94


enum FRAME {
    FRAME_STAND,            // 0
    FRAME_HOLD_BOULDER_0,   // 1
    FRAME_HOLD_BOULDER_1,   // 2
    FRAME_WIPE_HAIR,        // 3
    FRAME_JUMP,             // 4
    FRAME_HAIR,             // 5
    FRAME_PUSH,             // 6
    FRAME_PUSH2,            // 7
    FRAME_HAIR2,            // 8
    FRAME_IMPATIENT,        // 9
    FRAME_IMPATIENT2,       // 10
    FRAME_LOOK1,            // 11
    FRAME_LOOK2,            // 12
    FRAME_SHADES,           // 13
    FRAME_SHADES_ARM,       // 14
    FRAME_BLINK,            // 15
    FRAME_WALK1,            // 16
    FRAME_WALK2,            // 17
    FRAME_WALK3,            // 18
    FRAME_WALK4,            // 19
    FRAME_SNATCH_DOWN,      // 20

    FRAME_SKELETON,         // 21
    FRAME_SKELETON2,        // 22
    FRAME_BLANK,            // 23
    FRAME_SKELETON3,        // 24
    FRAME_SKELETON4,        // 25
    FRAME_SKELETON5,        // 26

    FRAME_ARMSCROSSED,      // 27
    FRAME_SHAKE,            // 28
    FRAME_SHAKE2,           // 29
    FRAME_SHAKE3,           // 30

    FRAME_ADJUST = -4, //252,             // ,x,y
    FRAME_FLIP = -3, //253,
    FRAME_LOOP = -2, //254,
    FRAME_STOP = -1, //255,
    
};

enum ANIMATION_ID {
    ID_STAND,               // 0
    ID_HOLD_BOULDER,        // 1
    ID_WIPE_HAIR,           // 2
    ID_JUMP,                // 3
    ID_PUSH,                // 4
    ID_IMPATIENT,           // 5
    ID_LOOK,                // 6
    ID_BLINK,               // 7
    ID_SHADES,              // 8
    ID_WALK,                // 9
    ID_DIE,                 // 10
    ID_WALK_VERT,           // 11
    ID_TURN,                // 12
    ID_WALK_VERT_DOWN,      // 13
    ID_SNATCH,              // 14
    ID_SNATCH_DOWN,         // 15
    ID_SNATCH_UP,           // 16
    ID_SKELETON,            // 17
    ID_BLANK,               // 18
    ID_STARTUP,             // 19
    ID_ARMSCROSSED,         // 20
    ID_DRIP,                // 21
    ID_DRIP2,               // 22
    ID_SHAKE,               // 23
};


extern const signed char animJames[];
extern const signed char *animIndex[];

extern int playerAnimationID;
extern const signed char *playerAnimation;
extern const signed char *playerAnimationLoop;
extern unsigned int playerAnimationCount;

extern const signed char playerBigSprite[][2 + 23 * 4 + 2+ 18];

