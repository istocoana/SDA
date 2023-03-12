#include "hash.h"


int INIT_HASHTABLE(t_lista T[], int m){
    for(int j=0; j<m; ++j){
        MAKENULL(&T[j]);
    }
}

int HASH_FUNCTION(int k, int m){
    return k%m;
}

int CHAINED_HASH_INSERT(t_lista T[], int k, int m){
    t_nod_lista *x = NULL;
    int j = HASH_FUNCTION(k, m);
    x = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    x->cheie = k;
    x->next = NULL;
    x->prev = NULL;
    LIST_INSERT(&T[j], x);
    return j;
}

void PRINT_HASHTABLE(t_lista T[], int m){
    for(int j=0; j<m; ++j){
        if(T[j].head != NULL){
           printf("T[%d]: ", j);
           LIST_PRINT(&T[j]);
        }
    }
}

int CHAINED_HASH_SEARCH(t_lista T[], int k, int m){
    t_nod_lista *x;
    int j = HASH_FUNCTION(k, m);
    LIST_SEARCH(&T[j], k, &x);
    if(x){
        return j;
    }
    else return -1;
}

int CHAINDED_HASH_DELETE(t_lista T[], int k, int m){
    t_nod_lista *x;
    int j = HASH_FUNCTION(k, m);
    LIST_SEARCH(&T[j], k, &x);
    if(x){
        LIST_DELETE(&T[j], x);
        return j;
    }
    else return -1;
}

