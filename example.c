#include "arcfour.h"

#define F fflush(stdout)

void printbin(int8 *input, int16 size) {
    int32 i;
    int8 *p;

    assert(size > 0);
 
    for (i = size, p = input; i; i--, p++) {    
        if (!((i + 1) % 2)) {
            printf(" ");
        }
        printf("%.02x", *p);
    }   
    printf("\n");
}

int main() {
    Arcfour *rc4;
    int16 skey, stext;
    char *key, *from;
    int8 *encrypted, *decrypted;

    key = "wazazi";
    skey = strlen(key);
    from = "Nitatoa wapi wengine?";
    stext = strlen(from);

    // Encryption
    printf("Initializing encryption"); F;
    rc4 = rc4init((int8 *)key, skey);
    printf(" done\n");

    printf(" -> '%s'\n ->", from);
    encrypted = rc4encrypt(rc4, (int8 *)from, stext);
    printbin(encrypted, stext);
    rc4unint(rc4); 

    // Decryption
    printf("Initializing decryption"); F;
    rc4 = rc4init((int8 *)key, skey);
    printf(" done\n");

    decrypted = rc4encrypt(rc4, encrypted, stext); // rc4encrypt works for both encryption and decryption
    printf(" -> '%s'\n ->", decrypted);
    printbin(decrypted, stext);
    
    rc4unint(rc4); 

    // Free allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}
