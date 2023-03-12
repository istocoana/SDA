#include <stdlib.h>
#include <stdio.h>
#include "rb.c"

void read_node(int *x) {
    printf_s("x = ");
    scanf_s("%d", x);
    printf_s("\n");
}

int main(int argc, char *argv[]) {

    t_rb_arbore T;
    t_rb_node *r, *n;
    int x;

    printf("ROOT = ");
    scanf("%d", &x);
    printf("\n");
    r = MAKE_ROOT(&T, x);

    printf("Introduceti x pana la citirea lui 0 \n");
    read_node(&x);

    while( x != 0 ) {
        n = CREATE_NOD(x);
        RB_INSERT(&T, n);
        read_node(&x);
    }

    printf("Adresa pointer left [%p] cu valoarea [%d]\n", r->left, r->left->key);
    printf("Adresa pointer left [%p] cu valoarea [%d]\n", r->right, r->right->key);

    printf("In-order walk: \n");
    INORDER_WALK(r);
    printf("\n");

    printf("Cautare nod cu cheia ");
    read_node(&x);
    n = TREE_SEARCH(r, x);
    if( n != NULL ) {
        printf("Nodul cu cheia %d a fost gasit", n->key);
    } else {
        printf("Nodul nu a fost gasit");
    }

    return EXIT_SUCCESS;
}
