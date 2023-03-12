#include "lista.h"
#include <stdlib.h>

t_nod_lista* INIT_NODE() {
    t_nod_lista* nod = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    nod->next = NULL;
    nod->prev = NULL;
    return nod;
}

void MAKENULL( t_lista *lista) {
    lista->head = NULL;
}

//returneaza in retval pointer catre elementul gasit in lista
void LIST_SEARCH( t_lista *lista, int key, t_nod_lista **retval) {
    t_nod_lista *nod = lista -> head;
    for(; nod != NULL && nod->cheie != key; nod = nod->next);
    *retval = nod;
}

void LIST_FREE(t_lista *lista) {
    t_nod_lista *nod = lista->head;
    for(;nod != NULL; nod = nod->next) {
        LIST_DELETE(lista, nod);
        free(nod);
    }
    lista->head = NULL;
    free(lista->head);
}

void LIST_DELETE_KEY( t_lista *lista, int key ) {
    t_nod_lista *nod = lista->head;
    while( nod != NULL ) {
        if( nod -> cheie == key )
            LIST_DELETE(lista, nod);
        nod = nod->next;
    }
}

void LIST_DELETE(t_lista *lista, t_nod_lista *nod) {
    if( nod->prev != NULL )
        nod->prev->next = nod->next;
    else
        lista->head->next = nod->next;
    if( nod->next != NULL )
        nod->next->prev = nod->prev;
}

void LIST_INSERT( t_lista *lista, t_nod_lista *nod) {
    if(lista->head == NULL) {
        lista->head = nod;
        return;
    }

    t_nod_lista* tip = lista->head;
    for(;tip->next != NULL; tip = tip->next);
    tip->next = nod;
    nod->prev = tip;
}

void LIST_PRINT( t_lista *lista) {
    for(t_nod_lista *nod = lista->head; nod != NULL; nod = nod->next) {
        printf_s("%d ", nod->cheie);
    };
    printf_s("\n");
}

int LIST_SUM( t_lista *lista) {
    t_nod_lista *nod = lista->head;
    int sum = 0;
    for(;nod != NULL; sum+=nod->cheie, nod = nod->next);
    return sum;
}
