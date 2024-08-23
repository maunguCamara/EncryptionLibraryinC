#include "arcfour.h"

export Arcfour *rc4init(int8 *key, int16 size) {
    int16 x;
    int8 tmp1, tmp2;
    Arcfour *p;

    if (!(p = malloc(sizeof(struct s_Arcfour)))) {
        assert_perror(errno);
    }

    // Initialize the state array
    for (x = 0; x < 256; x++) {
        p->s[x] = x;
    }
    p->i = p->j = p->k = 0;

    // Key scheduling algorithm (KSA)
    for (p->i = 0, p->j = 0; p->i < 256; p->i++) {
        tmp1 = p->i % size;
        p->j = (p->j + p->s[p->i] + key[tmp1]) % 256;
        
        // Swap p->s[p->i] and p->s[p->j]
        tmp2 = p->s[p->i];
        p->s[p->i] = p->s[p->j];
        p->s[p->j] = tmp2;
    }

    p->i = p->j = 0;
    rc4whitewash(x, p);

    return p;
}

int8 rc4byte(Arcfour *p) {
    int8 tmp1, tmp2;

    p->i = (p->i + 1) % 256;
    p->j = (p->j + p->s[p->i]) % 256;

    // Swap p->s[p->i] and p->s[p->j]
    tmp1 = p->s[p->i];
    p->s[p->i] = p->s[p->j];
    p->s[p->j] = tmp1;

    tmp1 = (p->s[p->i] + p->s[p->j]) % 256;
    p->k = p->s[tmp1];

    return p->k;
}

export int8 *rc4encrypt(Arcfour *p, int8 *cleartext, int16 size) {
    int8 *ciphertext;
    int16 x;

    ciphertext = (int8 *)malloc(size + 1);
    if (!ciphertext) {
        assert_perror(errno);
    }

    for (x = 0; x < size; x++) {
        ciphertext[x] = cleartext[x] ^ rc4byte(p);
    }
    return ciphertext;
}
