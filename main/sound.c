
#include <stdbool.h>
#include "sound.h"
//#include "defines_cdfj.h"
#include "defines_from_dasm_for_c.h"
#include "main.h"

extern void* DDR;
#define RAM ((unsigned char*)DDR)


extern int time;
extern int tuneIndex;
extern int doge;
extern unsigned int getRandom32();


const unsigned char beat[] = {
    40,40,40,40,80,100,80,40,40,40,20,20,20,30,40,50,60,0
};
 
const unsigned char beat2[] = {
    40,20,40,20,60,60,60,40,40,40,80,60,40,30,40,50,60,0
};

struct Audio Track[MAX_TRACKS];





const unsigned char sampleTick[] = {
    0xF,0x1F,1,2,
    0,0,0,6,
    0xF,0x1F,1,1,
    0,0,0,40,
    CMD_LOOP,
};


const unsigned char sampleDrip[] = {
   8,10,2,   5,
   CMD_STOP,
};


const unsigned char sampleRock[] = {
    8, 18, 4, 5,
    8, 18, 4, 4,
    8, 18, 3, 3,
    8, 18, 2, 2,
    CMD_STOP,
};


const unsigned char sampleRock2[] = {
    8, 18, 3, 5,
    8, 18, 2, 4,
    8, 18, 1, 4,
    CMD_STOP,
};

const unsigned char sampleDirt[] = {
    8, 31, 3, 10,
    CMD_STOP,
};

const unsigned char sampleSpace[] = {
    8, 2, 1, 4,
    CMD_STOP,
};


const unsigned char sampleBlip[] = {
    4, 18, 6, 1,
    4, 18, 4, 2,
    4, 18, 1, 4,
    CMD_STOP,
};

const unsigned char sampleAmoeba[] = {
    12,10,2,4,
    CMD_LOOP,
};

const unsigned char sampleLava[] = {
    3,10,2,2,
    CMD_LOOP,
};


const unsigned char sampleExxtra[] = {
    12, 5, 2, 10,
    12, 7, 2, 10,
    12, 5, 2, 10,
    12, 7, 2, 10,
    12, 5, 2, 10,
    12, 7, 2, 10,
    CMD_STOP,
};



const unsigned char samplePush[] = {
    8, 4, 2, 12, CMD_STOP,
};


const unsigned char sampleExplode[] = {
    8, 7, 9, 2,
    8, 10, 8, 2,
    8, 13, 7, 2,
    8, 16, 7, 3,
    8, 19, 6, 4,
    8, 22, 5, 5,
    8, 25, 4, 6,
    8, 28, 3,10,
    8, 29, 2, 15,
    8, 31, 1, 15,
    CMD_STOP,
};

const unsigned char sampleWhoosh[] = {
    15, 31, 1, 2,
    15, 31, 2, 2,
    15, 28, 3, 2,
    15, 25, 4, 3,
    15, 22, 5, 4,
    15, 19, 6, 5,
    15, 16, 7, 6,
    15, 13, 7,10,
    15, 10, 4, 2,
    15, 7,  2, 2,
    CMD_STOP,
};


const unsigned char sampleSpin[] = {
    15, 31, 1, 1,
    15, 31, 2, 2,
    15, 28, 3, 3,
    15, 25, 4, 5,
    15, 22, 5, 6,
    15, 19, 6, 6,
    15, 16, 5, 6,
    15, 13, 4, 5,
    15, 10, 3, 3,
    15, 7,  2, 2,
    15, 7,  2, 1,
    CMD_STOP,
};




const unsigned char sample10987654321[] = {

    4,10,1,1,
    4,10,3,1,
    4,10,5,1,
    4,10,6,1,
    4,10,5,15,
    4,10,3,3,
    4,10,2,3,
    4,10,1,3,
    CMD_STOP,
};

const unsigned char sampleDeadBeat2[] = {


/*

    // 1 = trombone
    // 5 = pianoish (long)
    // 6 = bass
    // 8 = rock(ish) impacts
    // 9 = low spring
    // 10 = loose (low) trombone
    // 12 = hints of string (needs vibrato)
    // 13 = similar
    // 14 = draggy
*/


    9,15,1,1,
    9,15,2,1,

    9,15,2,2,
    9,15,1,1,
    CMD_LOOP,
};


const unsigned char sampleDeadBeat[] = {


/*

    // 1 = trombone
    // 5 = pianoish (long)
    // 6 = bass
    // 8 = rock(ish) impacts
    // 9 = low spring
    // 10 = loose (low) trombone
    // 12 = hints of string (needs vibrato)
    // 13 = similar
    // 14 = draggy
*/


    9,15,2,1,
    9,15,4,1,

    9,15,3,4,
    9,15,2,1,
    CMD_LOOP,
};




const unsigned char sampleDig[] = {
    8, 2, 2, 3,
    CMD_STOP,
};


#define SHK1 2
#define SHK2 15
#define SHK3 19
#define SHKV 3

const unsigned char sampleShake[] = {
    SHK1, SHK2, SHKV, 2,
    SHK1, SHK3, SHKV, 2,
//    SHK1, SHK2, SHKV, 2+10,
//    0,0,0,5,


/*    SHK1, SHK2, SHKV, 2,
    SHK1, SHK3, SHKV, 2,
    SHK1, SHK2, SHKV, 2+10,
//    0,0,0,5,

    SHK1, SHK2, SHKV, 2,
    SHK1, SHK3, SHKV, 2,
    SHK1, SHK2, SHKV, 2,
//    0,0,0,5+46,
*/
    CMD_STOP,
};




const unsigned char sampleSFX[] = {      // C,F,V,LEN

   4,10,4,   5,
   4,10,2,   1,
   4,10,5,   1,
   4,10,2,   1,
   4,10,1,   2,
//   4,10,1,   2,
//   4,10,0,   2,
   CMD_STOP,

};


const unsigned char sampleExit[] = {

    12,16,1,1,
    12,16,4,1,
    12,16,10,1,
    12,16,8,4,
    12,16,6,1,
    12,16,4,1,
    12,16,2,1,
    CMD_STOP,
};

const unsigned char sampleBirth[] = {

//    8,4,1,1,
//    8,4,4,1,
//    8,4,8,1,
    8,4,14,8,
    8,4,10,4,
    8,4,8,4,
    8,4,6,4,
    8,4,4,4,
    8,4,2,4,
    CMD_STOP,
};


const struct AudioTable AudioSamples[] = {

    // MUST correspond to AudioID enum ordering/number

//    { sampleDummy, 0 },
    { sampleAmoeba, -2 },
    { samplePush, 8 },
    { sampleSpace, 8 },
    { sampleDirt, 9 },
    { sampleRock, 11 },
    { sampleRock2, 10 },
    { sampleSFX, 10 },
    { sampleExxtra, 110 },
//    { sampleUncover, -1 },
    { sampleBlip, 125 },
    { sampleExplode, 126 },
    { sampleDeadBeat, -1 },
    { sample10987654321, -1 },
    { sampleTick, -3 },
    { sampleExit, 127 },
    { sampleBirth, 127 },
    { sampleDeadBeat2, -10 },
    { sampleWhoosh, 127 },
    { sampleSpin, 127 },
    { sampleShake, 10 },
    { sampleDrip, 5},
    { sampleLava, -2 },
};



void InitAudio() {
    for (int i = 0; i < MAX_TRACKS; i++)
        Track[i].id = -1;
}


void KillAudio(enum AudioID id) {
    for (int i= 0; i < MAX_TRACKS; i++)
        if (Track[i].id == id)
            Track[i].id = -1;
}

void KillRepeatingAudio() {
    for (int i = 0; i < MAX_TRACKS; i++)
        if (Track[i].id >= 0 && AudioSamples[Track[i].id].priority < 0)
            Track[i].id = -1;
}

void AddAudio(enum AudioID id) {

    // replace lowest non-negative-priority track
    // BUT NOT those tracks with negative priority ("locked")

    int lowest = -1;
    for (int i = 0; i < MAX_TRACKS; i++) {
        int idx = Track[i].id;
        
        if (idx < 0) {
            lowest = i;
            break;
        }

        else if (AudioSamples[idx].priority > 0 ) {     // CANNOT REPLACE NEG PRIORITY SOUNDS!
            if (lowest < 0 || AudioSamples[Track[lowest].id].priority > AudioSamples[idx].priority)
                lowest = i;
        }
    }

    if (lowest >= 0 &&
        (Track[lowest].id < 0 || 
        AudioSamples[Track[lowest].id].priority < AudioSamples[id].priority)) {

        Track[lowest].index = 0;
        Track[lowest].id = id;
        Track[lowest].delay = AudioSamples[id].sample[3];
    }
}




void playAudio() {

    int active = 0;
    for (int i = 0; i < MAX_TRACKS; i++) {

        struct Audio *track = &Track[i];
        track->handled = false;

        if (track->id >= 0) {
            active++;
            if (!track->delay) {

                track->index += 4;

                switch (AudioSamples[track->id].sample[track->index]) {
                case 255:
                    track->id = -1;
                    break;

                case 254:
                    track->index = 0;
                    __attribute__ ((fallthrough));

                default:
                    track->delay = AudioSamples[track->id].sample[(track->index) + 3];
                    break;
                }
            }

            track->delay--;
        }        
    }

    for (int channel = 0; channel < 2; channel++) {

        unsigned char audC = 0;
        unsigned char audV = 0;
        unsigned char audF = 0;

        struct Audio *best = 0;
        for (int i = 0; i < MAX_TRACKS; i++)
            if (Track[i].id >= 0 &&  !Track[i].handled)
                if (!best
                    || AudioSamples[best->id].sample[best->index+2] < AudioSamples[Track[i].id].sample[Track[i].index+2]
                    || (AudioSamples[best->id].priority < AudioSamples[Track[i].id].priority
                        && AudioSamples[best->id].sample[best->index+2] == AudioSamples[Track[i].id].sample[Track[i].index+2]))
                    best = &Track[i];

        if (best) {

            best->handled = true;

            audC = AudioSamples[best->id].sample[best->index];
            audF = AudioSamples[best->id].sample[(best->index) + 1];
            audV = AudioSamples[best->id].sample[(best->index) + 2];

            switch (best->id) {

            case SFX_COUNTDOWN2:
                audF = ((time & ~0xFF) >> 8) + 16;
                break;

            case SFX_AMOEBA: {
                    static unsigned char amoebaF;
                    if (!best->index && best->delay == AudioSamples[best->id].sample[3] - 1)
                        amoebaF = (unsigned char)((getRandom32() & 0xF) | 8);
                    audF = amoebaF;
                }
                break;

            case SFX_LAVA: {

                    static unsigned char lavaF;
                    static unsigned char lavaV;

                    if (!best->index && best->delay == AudioSamples[best->id].sample[3] - 1) {
                        if ((getRandom32() & 0xFF) < 20) {

                        
    extern void setFlash(int colour, int time);
    extern int flashTime;



                            lavaF = (unsigned char)((getRandom32() & 0x3)+ 12);
                            lavaV = getRandom32() & 3;


                            if (lavaV) {
                                setFlash(0x20,1);
                                flashTime += lavaV;
#if ENABLE_SHAKE
    extern int shakeTime;
                                //shakeTime += 15; //(lavaV * 6);
#endif
                            }

                        }

                        else
                            lavaV = 0;
                    }

                    audV = lavaV;
                    audF = lavaF;
                }
                break;

            case SFX_DEADBEAT: {

                    if (!best->index && best->delay == AudioSamples[best->id].sample[3] - 1) {
                    
                        tuneIndex++;
                        if (beat2[tuneIndex] == 0)
                            tuneIndex = 0;
                    }

                    audF = beat[tuneIndex];     
                }
                break;

            case SFX_DEADBEAT2: {

                    if (!best->index && best->delay == AudioSamples[best->id].sample[3] - 1) {
                    
                        tuneIndex++;
                        if (beat[tuneIndex] == 0)
                            tuneIndex = 0;
                    }

                    audF = beat[tuneIndex];     
                }
                break;
            }

        }

        RAM[_BUF_AUDC + channel] = audC;
        RAM[_BUF_AUDF + channel] = audF;
        RAM[_BUF_AUDV + channel] = audV;
    }

}


