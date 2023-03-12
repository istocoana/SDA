#include <stdio.h>
#include <stdlib.h>
#include "stiva.c"

int main(int argc, int argv[]){
    t_stiva s;
    int k = -1;
    INIT_STACK(&s, 20);
    printf("Stiva a fost initiata!\n");

    while(k != 0){
        printf("Adaugati cheie: ");
        scanf("%d", &k);
        PUSH(&s, k);
        printf("Cheia a fost adaugata!\n");
        PRINT_STACK(s);
    }

    while( !STACK_EMPTY(&s) ){
        POP(&s);
        PRINT_STACK(s);
    }
    FREE_STACK(&s);
    return 0;
}

