#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "coada.c"

int main(int argc, char *argv[]) {

    t_queue Q;
    int e = -1;
    INIT_QUEUE(&Q, 20);

    while( true ) {
        printf("Scrieti elementul pe care vreti sa il adaugati pana la tastarea lui 0 \n");
        scanf("%d", &e);
        if( !e ) break;
        ENQUEUE(&Q, e);
        PRINT_QUEUE(&Q);
    }

    while( !QUEUE_EMPTY(&Q) ) {
        DEQUEUE(&Q);
        PRINT_QUEUE(&Q);
    }

    FREE_QUEUE(&Q);


    return 0;
}
