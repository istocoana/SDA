#include <stdio.h>
#include <stdlib.h>
#include "arbori.c"


void READ_NODE(int *x){
    printf("x= "); scanf("%d", x);
    printf("\n");
}


int main(){

    t_arbore T;
    t_nod_arb *nod = NULL;
    t_nod_arb *r = NULL;
    t_nod_arb *s = NULL;

    int x;

    //creare radacina
    printf("Nodul sau radacina cu cheia x = ");
    scanf("%d", &x);
    printf("\n");
    r = MAKEROOT(&T, x);

    //inserare noduri
    printf("Introduceti x pana la citirea lui 0\n");
    READ_NODE(&x);
    while(x){
        nod = CREATE_NODE(x);
        TREE_INSERT(&T, nod);
        READ_NODE(&x);
    }

    printf("IN-order walk: \n");
    INORDER_WALK(r);
    printf("\n");

    printf("PRE-order walk: \n");
    PREORDER_WALK(r);
    printf("\n");

    printf("POST-order walk: \n");
    POSTORDER_Walk(r);
    printf("\n");

    //cautare nod iterativ
    printf("Regasire nod cu cheia x= ");
    scanf("%d", &x);
    nod = IT_TREE_SEARCH(r, x);
    if(nod){
        printf("Nodul cu cheia %d gasit intertiv \n la adresa %p\n", nod->key, nod);
    }
    else printf("Nodul nu a fost gasit interativ!\n");

    nod = TREE_SEARCH(r, x);
    if(nod){
        printf("Nodul cu cheia %d gasit recursiv \n la adresa %p\n", nod->key, nod);
    }
    else printf("Nodul nu a fost gasit recursiv!\n");

    //gasire minim
    nod = TREE_MIN(r);
    printf("Minim arbore: %d \n", nod->key);

    //gasire maxim;
    nod = TREE_MAX(r);
    printf("Maxim arbore: %d\n", nod->key);

    //afisare succesor
    printf("Succesoru lui ");
    READ_NODE(&x);
    nod = IT_TREE_SEARCH(r, x);
    s = TREE_SUCCESOR(nod);
    if(s){
        printf("Nod succesor: %d\n", s->key);
    }
    else printf("NULL \n");

    //stergere nod
    printf("Stergerea unui nod cu cheia ");
    READ_NODE(&x);
    nod = TREE_SEARCH(r, x);
    if(nod){
        TREE_DELETE(&T, nod);
        printf("Nodul a fost sters!\n");
        INORDER_WALK(r);
    }
    else printf("Nod negasit!\n");

    return 0;
}
