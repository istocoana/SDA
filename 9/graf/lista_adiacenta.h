#ifndef LISTA_ADIACENTA_H_INCLUDED
#define LISTA_ADIACENTA_H_INCLUDED

#define INF 0x3f3f3f3f
#define DM 101

typedef struct nod_lista {
    enum { white, gray, black } color;
    int d, f;
    int cheie;
    struct nod_lista *next, *prev;
} t_nod_lista;

typedef struct {
    t_nod_lista *head;
} t_lista;


t_nod_lista* FIND_NODE(t_lista* G[], int v);
void ENQUEUE(t_nod_lista* Q[], int *q, t_nod_lista* nod);
t_nod_lista* DEQUEUE(t_nod_lista* Q[],int *q);

void INIT_LISTA_AD(t_lista* G[]);
void INSERT_VECINI(t_lista* G[], int s);

void BFS(t_lista * G[], t_nod_lista *s);
void MARK_VISITED(t_lista* G[], int key);


void PRINT_PATH(t_lista* G[], t_nod_lista* s, t_nod_lista *v);
void DFS_VISIT(t_lista* G[], t_nod_lista* u);
void DFS(t_lista* G[]);

void DFS_VISIT_TOP(t_lista *G[], int u, t_lista *topo);
t_lista topological_sort(t_lista *G[]);




#endif // LISTA_ADIACENTA_H_INCLUDED
