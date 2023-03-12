#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct nod_lista {
    int cheie;
    struct nod_lista *next, *prev;
} t_nod_lista;

typedef struct {
    t_nod_lista *head;
} t_lista;

t_nod_lista* INIT_NODE();
void MAKENULL ( t_lista *lista);
void LIST_SEARCH( t_lista *lista, int key, t_nod_lista **retval);
void LIST_FREE( t_lista *lista);
void LIST_DELETE( t_lista *lista, t_nod_lista *nod );
void LIST_INSERT( t_lista *lista, t_nod_lista *nod );
void LIST_PRINT( t_lista *lista);
int LIST_SUM( t_lista *lista);
void LIST_DELETE_KEY( t_lista *lista, int key );


#endif // LISTA_H_INCLUDED
