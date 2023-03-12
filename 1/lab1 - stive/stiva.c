#include "sitva.h"
#include <stdbool.h>

void INIT_STACK(t_stiva *s, int init_size){
    s->data = (int*)malloc(init_size*sizeof(int));
    s->top = NULL;
}

void FREE_STACK(t_stiva *s){
    free(s->data);
    s->data = NULL;
    s->top = -1;
}

bool STACK_EMPTY(t_stiva *s){
    if(s->top == 0){
        return 1;
    }
    else return 0;
}

void PUSH(t_stiva *s, int element){
    s->top = s->top + 1;
    s->data[s->top] = element;
}

void PRINT_STACK(t_stiva s){
    printf("%d\n", s.top);
    for(int i=1; i<= s.top; ++i){
        printf("%d", s.data[i]);
    }
    printf("\n");
}

int POP(t_stiva *s){
        if(STACK_EMPTY(s)){
        printf("Stiva este goala.\n");
        return -1;
    }

    int element = s->data[s->top];
    s->data[s->top--] = 0;
    return element;
}
