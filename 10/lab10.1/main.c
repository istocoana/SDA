#include <stdio.h>
#include <stdlib.h>
#include "lab10.1.c"
#include <time.h>

void main(void)
{
    t_lista G[DM];
    int n, i, k=0, nd;
    t_edge edges[DM];
    t_edge arc;

    printf("Introduceti numarul de noduri: ");
    scanf("%d", &n);

    init_lista(G, n);

    for(i=1; i<=n; i++){
        insert_vecini(G, i, n, edges, &k);
    }
    printf("\nLista adiacenta: \n");
    print_lista(G, n);


    printf("\nNod de pornire: ");
    scanf("%d", &nd);

    printf("Bellman-Ford: ");
    bellman_ford(G, edges, nd, n, k);
    print_path(G, G[nd].head, G[n].head);

    dijkstra(G, edges, nd, n , k);
    printf("\n");

    printf("Kruskal: ");
    mst_kruskal(G, edges, n, k);


}

