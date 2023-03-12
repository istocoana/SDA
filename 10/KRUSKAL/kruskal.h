#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED
#define DM 101
#define INF 0x3f3f3f3f

typedef struct nod_lista {
    enum { white, gray, black } color;
    int d, f;
    int cheie;
    struct nod_lista *next, *prev;
} t_nod_lista;

typedef struct {
    t_nod_lista *head;
} t_lista;

typedef struct{
    t_nod_lista *src, *dest;
    int weight;
}t_edge;

t_nod_lista* FIND_NODE(t_lista* G[], int v);
void ENQUEUE(t_nod_lista* Q[], int *q, t_nod_lista* nod);
t_nod_lista* DEQUEUE(t_nod_lista* Q[],int *q);

void INIT_LISTA_AD(t_lista* G[]);
void INSERT_VECINI(t_lista* G[], int ns, int n, t_edge *edges[], int *k);

void BFS(t_lista* G[], t_nod_lista *s);
void MARK_VISITED(t_lista* G[], int key);


void PRINT_PATH(t_lista* G[], t_nod_lista* s, t_nod_lista *v);
void DFS_VISIT(t_lista* G[], t_nod_lista* u);
void DFS(t_lista* G[]);

void DFS_VISIT_TOP(t_lista *G[], int u, t_lista *topo);
t_lista* TOP_SORT(t_lista* G[]);

t_nod_lista *FIND_SET(t_nod_lista *x);
void MAKE_SET(t_nod_lista *x);
void LINK(t_nod_lista *x, t_nod_lista *y);
void UNION(t_nod_lista *x, t_nod_lista *y);
int _partition(t_edge *a[], int p, int r);
void quick_sort(t_edge *a[], int p, int r);
void mst_kruskal(t_lista *G[], t_edge *edges[], int n, int k);

void EXACTRACT_MIN(t_edge *edges[]);
void mst_prim(t_lista* G[], t_edge *edges, int r);

#endif // KRUSKAL_H_INCLUDED
