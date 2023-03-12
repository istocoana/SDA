#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "lista.c"
#define MAX 100


typedef struct{
    int cheie;
    int valoare;
}t_pereche;

typedef struct{
    t_lista tabela[MAX];
}t_hashtable;

int INIT_HASHTABLE(t_lista T[], int m);
int HASH_FUNCTION(int k, int m);
int CHAINED_HASH_INSERT(t_lista T[], int k, int m);
void PRINT_HASHTABLE(t_lista T[], int m);
int CHAINED_HASH_SEARCH(t_lista T[], int k, int m);
int CHAINDED_HASH_DELETE(t_lista T[], int k, int m);



#endif // HASH_H_INCLUDED
