#include "kruskal.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int timp = 0;
int n = 0;

t_nod_lista* INIT_NODE() {
    t_nod_lista* nod = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    nod->next = NULL;
    nod->prev = NULL;
    return nod;
}

void MAKENULL( t_lista *lista) {
    lista->head = (t_nod_lista*)malloc(sizeof(t_nod_lista));
    lista->head->prev = NULL;
    lista->head->next = NULL;
}

t_nod_lista* FIND_NODE(t_lista* G[], int v) {
    for(int i=1;i<DM;++i) {
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u->cheie == v)
                return u;
        }
    }
    return NULL;
}


void ENQUEUE(t_nod_lista* Q[], int *q, t_nod_lista* nod) {
    Q[++(*q)] = nod;
}

t_nod_lista* DEQUEUE(t_nod_lista *Q[], int *q) {
    t_nod_lista* retr = Q[1];
    for(int i=1; i<=(*q);++i) {
        Q[i] = Q[i+1];
    }
    (*q)--;
    return retr;
}

void BFS( t_lista* G[], t_nod_lista *s) {

    t_nod_lista* Q[100], *u, *v;
    int q = 0;

    for(int i=1;i<=n;++i) {
        if( G[i] == NULL ) {
            continue;
        }
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if (u != s) {
                u->color = white;
                u->d = INF;
                u->prev = NULL;
            }
        }
    }

    s->color = gray;
    s->d = 0;
    s->prev = NULL;

   //printf("%d ", s->cheie);

    MARK_VISITED(G, s->cheie);
    ENQUEUE(Q, &q, s);

    while ( q ) {
        t_nod_lista* u = DEQUEUE (Q, &q);
        for(t_nod_lista *v = G[u->cheie]->head; v != NULL; v = v->next) {
            if( v->color == white ) {
                v->color = gray;
                v->d = u->d + 1;
                v->prev = u;
               // printf("%d\n", v->cheie);

                t_nod_lista* h = G[v->cheie]->head;
                h->prev = u;
                h->d = u->d + 1;
                MARK_VISITED(G, v->cheie);
                ENQUEUE(Q, &q, v);
            }
        }
        u->color = black;
        printf("%d ", u->cheie);
    }
}

void MARK_VISITED(t_lista* G[], int key) {
    for(int i=1; i<=n; ++i) {
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u -> cheie == key) {
                u->color = gray;
            }
        }
    }
}

void INIT_LISTA_AD(t_lista* G[]) {
    for(int i=1; i<DM; ++i) {
        MAKENULL(&G[i]);
    }
}

void LIST_PRINT( t_lista *lista) {
    for(t_nod_lista *nod = lista->head; nod != NULL; nod = nod->next) {
        printf_s("%d ", nod->cheie);
    };
    printf_s("\n");
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

void PRINT_LISTA(t_lista* G[]) {
    t_nod_lista *nod = NULL;
    for(int i=1;i<=n;++i) {
        nod = G[i]->head;
        printf("%d: ",i);
       /* for(;nod != NULL; nod = nod->next) {
            printf("%d ", nod->cheie);
        }*/
        while(nod != NULL){
            printf("%d ", nod->cheie);
            nod = nod->next;
        }
        printf("\n");
    }
}

void PRINT_PATH(t_lista* G[], t_nod_lista *s, t_nod_lista *v) {
    if(v == s) {
        printf("%d ", s->cheie);
    } else if(v->prev == NULL) {
        printf("Nu exista cale\n");
    } else {
        PRINT_PATH(G, s, v->prev);
        printf_s("%d ", v->cheie);
    }
}

void DFS_VISIT(t_lista* G[], t_nod_lista *u) {
    timp++;
    u->d = timp;
    u->color = gray;
    printf_s("%d ", u->cheie);
    MARK_VISITED(G, u->cheie);
    for(t_nod_lista *v = G[u->cheie]->head->next; v != NULL; v = v->next) {
        if(v->color == white) {
            v->prev = u;
            DFS_VISIT(G, v);
        }
    }
    u->color = black;
    timp++;
    u->f = timp;
}

void DFS(t_lista* G[]) {
    for(int i=1; i<=n; ++i) {
        for(t_nod_lista *v = G[i]->head; v!= NULL; v = v->next) {
            v->color = white;
            v->prev = NULL;
        }
    }
    timp = 0;
    for(int i=1; i<=n; ++i) {
        if( G[i]->head->color == white ){
            DFS_VISIT(G, G[i]->head);
        }
    }
}

void DFS_VISIT_TOP(t_lista* G[], int u, t_lista *topo) {
    timp ++;
    G[u]->head->d = timp;
    G[u]->head->color = gray;
    MARK_VISITED(G, u);
    for(t_nod_lista *v = G[u]->head; v != NULL; v = v->next) {
        if(v->color == white) {
            v->prev = G[u]->head;
            DFS_VISIT_TOP(G, v->cheie, topo);
        }
    }
    G[u]->head->color = black;
    timp++;
    G[u]->head->f = timp;
    LIST_INSERT(topo, u);
}

t_lista* TOP_SORT(t_lista* G[]) {
    t_lista* topology;
    MAKENULL(topology);

    for(int i=1;i<=n; ++i) {
    for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next){
            u->color = white;
            u->prev = NULL;
        }
    }

    timp = 0;

    for(int i=1;i<=n; ++i) {
    for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u->color == white) {
                DFS_VISIT_TOP(G, u->cheie, topology);
            }
        }
    }

    return topology;
}

void INSERT_VECINI(t_lista* G[], int ns, int n, t_edge *edges[], int *k){
    t_nod_lista *nod;
    t_edge *e;
    int nv, j;

    printf("Nod sursa %d: \n", ns);
    G[ns]->head->cheie = ns;

    printf("Dati vecinii nodului sursa: \n");
    do{
        scanf("%d", &nv);
        if((nv>0) && (nv<=n) && (nv!=ns)){
            nod = (t_nod_lista*)malloc(sizeof(t_nod_lista));
            nod->cheie = nv;
            LIST_INSERT(&G[ns], nod);
            printf("Introduceti weight pentru arcul %d-%d: ", ns, nv);
            scanf("%d", &nv);
            e->weight = nv;
            e->src = G[ns]->head;
            e->dest = nod;
            j =( *k)++;
            edges[j] = e;
        }
    }while(nv > 0);
}


void MAKE_SET(t_nod_lista *x) {
    x -> prev = x;
    x -> d = 0;
}

t_nod_lista *FIND_SET(t_nod_lista *x) {
    if( x != x->prev )
        x->prev = FIND_SET(x->prev);

    return x->prev;
}

void LINK(t_nod_lista *x, t_nod_lista *y) {
    if( x->d > y->d )
        y->prev = x;
    else {
        y -> prev = x;
        if ( x->d == y->d)
            x->d++;
    }
}

void UNION(t_nod_lista *x, t_nod_lista *y) {
    LINK(FIND_SET(x), FIND_SET(y));
}

int _partition(t_edge *a[], int p, int r){
    int x = a[r]->weight;
    t_edge *aux;
    int i = p-1;
    int j;

    for(j=p; j<r; j++){
        if(a[j]->weight < x){
            i++;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
    aux=a[r];
    a[r]=a[i+1];
    a[i+1]=aux;
    return i+1;
}

void quick_sort(t_edge *a[], int p, int r)
{
    int q = 0;
    if( p < r )
    {
        q = _partition(a, p, r);
        quick_sort(a, p, q-1);
        quick_sort(a, q+1, r);
    }
}

void mst_kruskal(t_lista *G[], t_edge *edges[], int n, int k){
    t_edge *A[DM];
    int ne = 1;
    t_nod_lista *u, *us, *vs;
    int i;

    for(i=1; i<=n; i++){
        u = G[i]->head;
        MAKE_SET(u);
    }
    quick_sort(edges, 1, n);

    for(i=1; i<=k; i++){
        us = FIND_SET(edges[i]->src);
        vs = FIND_SET(edges[i]->dest);

        if(us != vs){
            A[ne] = edges[i];
            ne++;
            printf("\nArcul %d-%d cu ponderea %d\n", A[ne]->src->cheie, A[ne]->dest->cheie, A[ne]->weight);
            UNION(edges[i]->src, edges[i]->dest);
        }
    }
    for(i=1; i<=k; i++){
        printf("\nArcul %d-%d cu ponderea %d\n", A[i]->src->cheie, A[i]->dest->cheie, A[i]->weight);
    }

}
