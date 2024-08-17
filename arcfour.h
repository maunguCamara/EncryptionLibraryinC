// arcfour.h
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>

#define MS                     500
#define export                 __attribute__((visibility("default")))
#define rc4decrypt(x,y,z)      rc4encrypt(x,y,z)
#define rc4unint(x)              free(x)
#define rc4whitewash(x,y)          for (x=0; x<(MS*1000000); x++) \
                                    (volatile int8)rc4byte(y);

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct s_Arcfour{
    int16, i, j, k;
    int8 s[256];

};

typedef struct s_Arcfour Arcfour;


export Arcfour *rc4init(int8*, int16);
int8 rcbyte(Arcfour *);
export int8 *rc4encrypt(Arcfour*,int8*, int16); 