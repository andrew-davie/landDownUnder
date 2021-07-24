
struct AudioTable {
    const unsigned char *sample;
    const int priority;
};

enum AudioCommand {
    CMD_LOOP = 254,
    CMD_STOP = 255,
};

enum AudioID {

    SFX_AMOEBA,
    SFX_PUSH,
    SFX_SPACE,
    SFX_DIRT,
    SFX_ROCK,
    SFX_ROCK2,
    SFX_DOGE,
    SFX_EXTRA,
    SFX_BLIP,
    SFX_EXPLODE,
    SFX_DEADBEAT,
    SFX_COUNTDOWN2,     // time expiring
    SFX_TICK,
    SFX_EXIT,
    SFX_BIRTH,
    SFX_DEADBEAT2,
    SFX_WHOOSH,
    SFX_SPIN,
    SFX_SHAKE,
    SFX_DRIP,
    SFX_LAVA,
};




struct Audio {
    signed char id;
    unsigned char delay;
    bool handled;
    unsigned int index;
};

#define MAX_TRACKS 8


void playAudio();
void AddAudio(enum AudioID id);
void KillAudio(enum AudioID id);
void KillRepeatingAudio();
void InitAudio();

