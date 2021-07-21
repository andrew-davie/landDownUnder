#ifndef __CAVEDATA_H
#define __CAVEDATA_H


extern const unsigned char BD2_caveA[];
extern const unsigned char BD2_caveB[];

extern const unsigned char BD4_caveD[];

extern const unsigned char cave0[];
extern const unsigned char cave1[];
extern const unsigned char cave2[];
extern const unsigned char cave3[];
extern const unsigned char cave4[];
extern const unsigned char cave5[];
extern const unsigned char cave6[];
extern const unsigned char cave7[];
extern const unsigned char cave8[];
extern const unsigned char cave9[];
extern const unsigned char cave10[];
extern const unsigned char cave11[];
extern const unsigned char cave12[];
extern const unsigned char cave13[];
extern const unsigned char cave14[];
extern const unsigned char cave15[];
extern const unsigned char cave16[];
extern const unsigned char cave17[];
extern const unsigned char cave18[];
extern const unsigned char cave19[];

//const unsigned char *cavePtr[];
//const unsigned char caveColour[][3];

struct caveInfo {
    const unsigned char *cavePtr;
    const unsigned char caveColour[1][3+24];
};


extern const struct caveInfo caveList[];
extern const int caveCount;

#define UBYTE const unsigned char


#endif
