#include "coada.h"
#include <stdbool.h>
#include <stdlib.h>

void INIT_QUEUE(t_queue* Q, int init_size) {
    Q->data = (int*)malloc(sizeof(int) * init_size);
    Q->head = 0;
    Q->tail = 0;
    Q->length = 0;
    Q->capacity = init_size;
}

void FREE_QUEUE(t_queue* Q) {
    Q->head = -1;
    Q->tail = -1;
    Q->length = -1;
    Q->capacity = -1;
    free(Q->data);
    Q->data = NULL;
}

void ENQUEUE(t_queue* Q, int elem) {
    Q->data[Q->tail] = elem;
    Q->length ++;
    if(Q->tail == Q->capacity) {
        Q->tail = 1;
    } else {
        Q->tail++;
    }
}

int DEQUEUE(t_queue* Q) {
    int elem = Q->data[Q->head];
    Q->length--;
    if( Q->head == Q->capacity ) {
        Q->head = 0;
    } else {
        Q->head ++;
    }
    return elem;
}

void PRINT_QUEUE(t_queue* Q) {
    for(int i=Q->head; i< Q->head + Q->length; ++i ) {
        printf_s("%d ", Q->data[i]);
    }
    printf_s("\n");
}

bool QUEUE_EMPTY(t_queue* Q) {
    return ( Q == NULL || !Q->length );
}
