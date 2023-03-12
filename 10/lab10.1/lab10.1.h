#ifndef LAB10_1_H_INCLUDED
#define LAB10_1_H_INCLUDED

#define DM 101
#define INF 0x3f3f3f3f

typedef struct nod_lista{
    enum {white, black, gray} color;
    int d,f;
    int cheie;
    struct nod_lista *next, *prev;
}t_nod_lista;


typedef struct{
    t_nod_lista *head;
}t_lista;

typedef struct{
    t_nod_lista *src, *dest;
    int weight;
}t_edge;

void init_lista(t_lista G[], int n);
void print_lista(t_lista G[], int n);
void print_path(t_lista G[], t_nod_lista *s, t_nod_lista *v);
void insert_vecini(t_lista G[], int ns, int n, t_edge edges[],int *r);
void makenull(t_lista *lista);

void initialize_single_source(t_lista G[], t_nod_lista *s, int n);
void relax(t_nod_lista *u, t_nod_lista *v, int w);
int bellman_ford(t_lista G[], t_edge w[], int s, int n, int k);

t_nod_lista* extract_min(t_nod_lista *q[], int n);

int get_weight(t_edge w[], t_nod_lista *u, t_nod_lista *v, int nrarce);
void dijkstra(t_lista G[], t_edge w[], int s, int n, int nrarce);
void relax_d(t_nod_lista *u, t_nod_lista *v, int w, t_nod_lista *q[], int n);

t_nod_lista *find_set(t_nod_lista *x);
void make_set(t_nod_lista *x);
void link(t_nod_lista *x, t_nod_lista *y);
void uniune(t_nod_lista *x, t_nod_lista *y);
int _partition(t_edge a[], int p, int r);
void quick_sort(t_edge a[], int p, int r);
void mst_kruskal(t_lista G[], t_edge edges[], int n, int k);

#endif // LAB10_1_H_INCLUDED
