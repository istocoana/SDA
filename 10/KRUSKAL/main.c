#include <stdio.h>
#include <stdlib.h>
#include "kruskal.c"
#include <time.h>

int main()
{
    t_lista* G[DM];
    int s, n1, n2;
    int n, i, k=0, nd;
    t_edge* edges[DM];
    t_edge* arc;

    printf("Numarul de noduri: ");
    scanf("%d", &n);\

    INIT_LISTA_AD(&G);
    printf("\n");
    for(int i=1; i<=n; ++i){
        INSERT_VECINI(G, i, n, edges, &k);
    }
    printf("Lista adiacenta: \n");
    PRINT_LISTA(G);

    printf("Kruskal: \n");
    printf("Nod start: ");
    scanf("%d", &s);
    mst_kruskal(G, edges, n, &k);

    return 0;
}
