#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include <stdbool.h>
#include <stdbool.h>

typedef struct queue {
    int *data;
    int head, tail, length, capacity;
} t_queue;

void INIT_QUEUE(t_queue* Q, int init_size);
void FREE_QUEUE(t_queue* Q);
void ENQUEUE(t_queue* Q, int elem);
int DEQUEUE(t_queue* Q);
void PRINT_QUEUE(t_queue* Q);
bool QUEUE_EMPTY(t_queue* Q);

#endif // COADA_H_INCLUDED
