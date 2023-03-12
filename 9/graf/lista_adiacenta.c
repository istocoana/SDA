#include "lista_adiacenta.h"
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


void LIST_PRINT( t_lista *lista) {
    for(t_nod_lista *nod = lista->head; nod != NULL; nod = nod->next) {
        printf("%d ", nod->cheie);
    };
    printf("\n");
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
        printf("%d ", v->cheie);
    }
}


void INIT_LISTA_AD(t_lista* G[]) {
    for(int i=1; i<DM; ++i) {
        MAKENULL(&G[i]);
    }
}

void INSERT_VECINI(t_lista* G[], int s) {

    printf("Nod sursa %d:\n", s);
    G[s]->head = INIT_NODE();
    G[s]->head->cheie = s;

    printf("Dati vecinii nodului sursa: \n");

    int v;
    do {
        //printf("Vecin cu %d: \n", s);
        scanf("%d", &v);
        if(v > 0 && v<=n && v!=s) {
            t_nod_lista *nod = INIT_NODE();
            nod->cheie = v;
            LIST_INSERT(G[s], nod);
        }
    } while( v > 0 );
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
    for(int i=1;i<=n;++i) {
        for(t_nod_lista *u = G[i]->head; u != NULL; u = u->next) {
            if(u -> cheie == key) {
                u->color = gray;
            }
        }
    }
}


void DFS_VISIT(t_lista* G[], t_nod_lista *u) {
    timp++;
    u->d = timp;
    u->color = gray;
    printf("%d ", u->cheie);
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

void visit_topological_sort(t_lista G[], t_nod_lista *u, t_lista *topology)
{
	t_nod_lista *nv;
	timp++;
	u->d=timp;
	u->color=gray;
	MARK_VISITED(G,u->cheie);
	printf("Nod vizitat u=%d la timp d=%d\n", u->cheie, u->d);
	nv=G[u->cheie].head->next;
	printf("\tNod vecin v=%d de culoare %d\n", nv->cheie, nv->color);
	while(nv!=NULL) //visit vecini
	{
		if (nv->color==white)
		{
			nv->prev=u;
			printf("Vizitez pe v=%d\n", nv->cheie);
			visit_topological_sort(G,nv,topology);
		}
		nv=nv->next;
	}
	u->color=black;
	timp++;
	u->f=timp; //u.f in pseudocod
	printf("u=%d vizitat complet la timp f=%d\n", u->cheie, u->f);
	//se adauga la lista de sortare topologica
	LIST_INSERT(topology,u);
    printf("!! Nod inserat u=%d cu %d/%d\n", u->cheie, u->d, u->f);
}

t_lista topological_sort(t_lista *G[])
{
	int i;
	t_nod_lista *u;
    t_lista topology;
	for (i=1; i<=n; i++)
	{
		u=G[i]->head;
		while (u!=NULL)
		{
			u->color=white; //white
			u->prev=NULL;
			u=u->next;
		}
	}
	timp=0;
	MAKENULL(&topology);

	for (i=1; i<=n; i++)
	{
		u=G[i]->head;
		if (u->color==white)
			visit_topological_sort(G,u,&topology);
	}
	return topology;
}
