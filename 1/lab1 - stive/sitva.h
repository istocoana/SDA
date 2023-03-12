#ifndef SITVA_H_INCLUDED
#define SITVA_H_INCLUDED
#include <stdbool.h>

typedef struct stiva{
    int top;
    int *data;
}t_stiva;

void INIT_STACK(t_stiva *s, int init_size);
void FREE_STACK(t_stiva *s);
bool STACK_EMPTY(t_stiva *s);
void PUSH(t_stiva *s, int element);
void PRINT_STACK(t_stiva s);
int POP(t_stiva *s);




#endif // SITVA_H_INCLUDED
