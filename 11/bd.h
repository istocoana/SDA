#ifndef BD_H_INCLUDED
#define BD_H_INCLUDED
#define DM 100

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


#endif // BD_H_INCLUDED
