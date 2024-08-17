// example.c
#include "arcfour.h"

#define F fflush(stdout)
int main(void);

void printbin(int8 *input, int16 size) {
    int32 i;
    int8 *p;

    assert(size > 0);
 
    for (i=size, p=input; i; i--, p++) {    
        if (!((i + 1) % 2)) 
            printf(" ");
        printf("%.02x", *p);
        
    }   
    printf("\n");
    return;
}


int main(){

    Arcfour *rc4;
    int16 skey, stext;
    char *key, *from;
    int8 *encrypted, *decrypted;

    key = "wazazi";
    skey = strlen(key);
    from = "Nitatoa wapi wengine?";
    stext = strlen(from);

    printf("Initializing encryption"); F;
    rc4 = rc4init((int8*)key, skey);
    printf("done\n");

    printf(" -> '%s'\n ->", from);
    encrypted = rc4encrypt(rc4,from, stext);
    printbin(encrypted, stext);
    rc4uninit(rc4); 

    printf("Initializing encryption"); F;
    rc4 = rc4init((int8*)key, skey);
    printf("done\n");
    
    
    decrypted = rc4encrypt(rc4, encrypted, stext);
    printf(" -> '%s'\n ->", decrypted);
    printbin(encrypted, stext);
    rc4uninit(rc4); 
    return 0;


}