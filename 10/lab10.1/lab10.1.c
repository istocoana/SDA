#include <stdlib.h>
#include "lab10.1.h"
#include <stdio.h>
#include <limits.h>

void makenull(t_lista *lista){
    lista->head = (t_nod_lista *)malloc(sizeof(t_nod_lista));
    lista->head->next = lista->head->prev = NULL;
}

void init_lista(t_lista G[], int n){
    for(int i=1; i<=DM; i++)
        makenull(&G[i]);
}

void print_lista(t_lista G[], int n){
    t_nod_lista *nod;
    for(int i=1; i<=n; i++)
    {
        nod = G[i].head->next;
        printf("%d: ", i);
        while(nod != NULL)
        {
            printf("%d ", nod->cheie);
            nod = nod->next;
        }
        printf("\n");
    }
}

void list_print(t_lista lista){
    t_nod_lista *x = lista.head->next;
    if(x == NULL){
        printf("Lista vida.\n");
    }else
        while(x){
            printf("%d ", x->cheie);
            x = x->next;
        }
}
void list_insert(t_lista *lista, t_nod_lista *x){
    if(x == NULL){
        return;
    }
    x->next = lista->head->next;
    if(lista->head->next != NULL){
        lista->head->next->prev = x;
    }
    lista->head->next = x;
    x->prev = lista->head;
}

void print_path(t_lista G[], t_nod_lista *s, t_nod_lista *v){
    if(v == s)
        printf("%d ", s->cheie);
    else
    {
        if(v->prev == NULL)
            printf("Nu exista cale.");
        else
        {
            print_path(G, s, v->prev);
            printf("%d ", v->cheie);
        }
    }
}


void insert_vecini(t_lista G[], int ns, int n, t_edge edges[], int *r){
    t_nod_lista *nod;
    t_edge e;
    int w, nv;
    printf("Nod sursa %d: ", ns);
    G[ns].head->cheie = ns;
    printf("\nDati vecinii nodului sursa: \n");
    do
    {
        printf("Vecin cu %d: ", ns);
        scanf("%d", &nv);
        if((nv > 0) && (nv <= n) && (nv != ns))
        {
            nod = (t_nod_lista*)malloc(sizeof(t_nod_lista));
            nod->cheie = nv;
            list_insert(&G[ns], nod);
            printf("Introduceti weight pentru arcul %d-%d: ", ns, nv);
            scanf("%d",&w);

            e.weight = w;
            e.src = G[ns].head;
            e.dest = nod;
            (*r)++;
            edges[*r] = e;
        }
    }while(nv > 0);
}


void initialize_single_source(t_lista G[], t_nod_lista *s, int n){
    t_nod_lista *u;
    for(int i=1; i<=n; i++){
        u = G[i].head;
        u->d = INT_MAX;
        u->prev = NULL;
    }
    s->d = 0;
}

void relax_d(t_nod_lista *u, t_nod_lista *v, int w, t_nod_lista *q[], int n){
    int i;
    if(v->d > (u->d + w)){
        v->d = u->d + w;
        for(i=1; i<=n; i++){
            if(q[i]->cheie == v->cheie)
                q[i]->d = u->d + w;
        }
        v->prev = u;
    }
}

void relax(t_nod_lista *u, t_nod_lista *v, int w)
{
    if(v->d > (u->d + w)){
           v->d = u->d + w;
           v->prev = u;
       }
}

int bellman_ford(t_lista G[], t_edge w[], int s, int n, int k)
{
    int i;
    t_nod_lista *ns;
    ns = G[s].head;
    initialize_single_source(G, ns, n);
    for(i=1; i<=n-1; i++)
        relax(G[w[i].src->cheie].head, G[w[i].dest->cheie].head, w[i].weight);
    for(i=1; i<=k; i++)
        if(G[w[i].dest->cheie].head->d > (G[w[i].src->cheie].head->d + w[i].weight))
            return 0;
    return 1;
}


t_nod_lista* extract_min(t_nod_lista *q[], int n) //pt PRIM
{
    int i, j, min = INT_MAX;
    t_nod_lista *u;
    for(i=1; i<=n; i++)
        if(q[i]->d < min)
        {
            min = q[i]->d;
            u = q[i];
            j = i;
        }
    for(i=j; i<n; i++)
        q[i] = q[i+1];
    return u;
}

int get_weight(t_edge w[], t_nod_lista *u, t_nod_lista *v, int nrarce)
{
    int i;
    for(i=1; i<=nrarce; i++)
        if((w[i].src->cheie == u->cheie) && (w[i].dest->cheie == v->cheie))
            return w[i].weight;

}

void dijkstra(t_lista G[], t_edge w[], int s, int n, int nrarce)
{
    t_nod_lista *ss[100], *q[100], *u, *ns, *v;
    int i, l=0, weight=0;
    ns = G[s].head;
    initialize_single_source(G, ns, n);
    for(i=1; i<=n; i++)
        q[i] = G[i].head;
    while(n > 0)
    {
        u = extract_min(q, n);
        n--;
        l++;
        ss[l] = u;
        v = G[u->cheie].head;
        while(v != NULL)
        {
            weight = get_weight(w, u, v, nrarce);
            relax_d(G[u->cheie].head, G[v->cheie].head, weight, q, n);
            v = v->next;
        }
    }

    printf("\nl= %d", l);
    printf("\nDijkstra: ");
    for(i=1; i<=l; i++)
        printf("%d ", ss[i]->cheie);
}

t_nod_lista *find_set(t_nod_lista *x)
{
    if(x!=x->prev)
        x->prev=find_set(x->prev);
    return x->prev;
}

void make_set(t_nod_lista *x)
{
    x->prev=x;
    x->d=0;
}

void link(t_nod_lista *x, t_nod_lista *y)
{
    if(x->d>y->d)
        y->prev=x;
    else
    {
        x->prev=y;
        if(x->d==y->d)
            y->d=y->d+1;
    }
}

void uniune(t_nod_lista *x, t_nod_lista *y)
{
    link(find_set(x),find_set(y));
}

int _partition(t_edge a[], int p, int r)
{
    int x=a[r].weight;
    t_edge aux;
    int i=p-1;
    int j;
    for(j=p;j<r;j++)
        if(a[j].weight<x)
        {
            i++;
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }
    aux=a[r];
    a[r]=a[i+1];
    a[i+1]=aux;
    return i+1;
}

void quick_sort(t_edge a[], int p, int r)
{
    int q=0;
    if(p<r)
    {
        q=_partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

void mst_kruskal(t_lista G[], t_edge edges[], int n, int k){
    t_edge A[DM];
    int ne=1;
    t_nod_lista *u, *us, *vd;
    int i;
    for(i=1; i<=n; i++){
        u = G[i].head;
        make_set(u);
    }
    quick_sort(edges, 1, n);

    for(i=1; i<=k; i++){
            us = find_set(edges[i].src);
            vd = find_set(edges[i].dest);

        if(us != vd){
            A[ne] = edges[i];
            ne++;
            printf("\nArcul %d - %d cu ponderea %d\n", A[ne].src->cheie, A[ne].dest->cheie, A[ne].weight);
            uniune(edges[i].src, edges[i].dest);
        }
    }

    for(i=1; i<=k; i++){
        printf("\nArcul %d - %d cu ponderea %d\n", A[i].src->cheie, A[i].dest->cheie, A[i].weight);
    }

}
