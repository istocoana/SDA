#include <stdio.h>
#include "lista.c"

int main(int argc, char *argv[]) {

    t_lista lista;
    t_nod_lista *nod = NULL;
    MAKENULL(&lista);
    int k = 0, s = -1;


    while( s != 0 ) {
        printf("0 -> exit\n");
        printf("1 -> insert\n");
        printf("2 -> search\n");
        printf("3 -> delete\n");
        printf("4 -> print\n");

        t_nod_lista *nod;
        scanf_s("%d", &s);
        switch ( s ) {
            case 1:
                printf("Ai ales optiunea insert! \n");
                scanf_s("%d", &k);
                t_nod_lista *toAdd = INIT_NODE();
                toAdd->cheie = k;
                LIST_INSERT(&lista,toAdd);
                LIST_PRINT(&lista);
                break;
            case 2:
                printf("Ai ales optiunea search \n");
                scanf_s("%d", &k);
                LIST_SEARCH(&lista, k, &nod);
                if( nod != NULL ) {
                    printf_s("Cheie gasita \n");
                } else {
                    printf_s("Cheie negasita \n");
                }
                break;
            case 3:
                printf("Ai ales optiunea delete!\n");
                scanf_s("%d", &k);
                LIST_SEARCH(&lista, k, &nod);
                if( nod != NULL ) {
                    LIST_DELETE( &lista, nod);
                    printf_s("Cheie stearsa \n");
                } else {
                    printf_s("Cheie negasita\n");
                }
                break;
            case 4:
                LIST_PRINT(&lista);
        }

    }

    LIST_FREE(&lista);

    return EXIT_SUCCESS;
}
