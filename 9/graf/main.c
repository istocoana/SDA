#include <stdio.h>
#include <stdlib.h>
#include "lista_adiacenta.c"
#include <time.h>


int main()
{
    t_lista* G[DM];
    t_lista* topology;
    int s, n1, n2;

    printf("Numarul de noduri: ");
    scanf("%d", &n);

    INIT_LISTA_AD(&G);
    printf("\n");
    for(int i=1; i<=n; ++i){
        INSERT_VECINI(G, i);
    }
    printf("Lista adiacenta: \n");
    PRINT_LISTA(G);

    printf("Parcurgere in latime: \n");
    printf("Nod start: ");
    scanf("%d", &s);
    BFS(G, G[s]->head);
    printf("\n");

    printf("Calea cea mai scurta: \n");
    printf("Nod start: ");
    scanf("%d", &n1);
    printf("Nod finish: ");
    scanf("%d", &n2);
    PRINT_PATH(G, G[n1]->head, G[n2]->head);

    printf("\n");
    printf("Parcurgere in adancime\n");
    DFS(G);


    printf("\nSortare topologica (grafuri aciclice orientate): ");
    printf("\n");
    topological_sort(G);
    //printf("%d", topology);
	LIST_PRINT(topology);
	return 0;
}
