#ifndef ARBORI_H_INCLUDED
#define ARBORI_H_INCLUDED

typedef struct nod_arb{
    int key;
    struct nod_arb *left, *right, *parent;
} t_nod_arb;

typedef struct{
    t_nod_arb *root;
}t_arbore;

t_nod_arb* MAKEROOT(t_arbore *arb, int key);
t_nod_arb* CREATE_NODE(int key);

void INORDER_WALK(t_nod_arb *root);
void PREORDER_WALK(t_nod_arb *root);
void POSTORDER_Walk(t_nod_arb *root);

t_nod_arb* TREE_MIN(t_nod_arb *nod);
t_nod_arb* TREE_MAX(t_nod_arb *nod);
t_nod_arb*  TREE_SUCCESOR(t_nod_arb *nod);
t_nod_arb* TREE_SEARCH(t_nod_arb *nod, int key);
t_nod_arb*  IT_TREE_SEARCH(t_nod_arb *nod, int key);

void TREE_INSERT(t_arbore *arb, t_nod_arb *nod);
void TREE_DELETE(t_arbore *arb, t_nod_arb *nod);
void TRANSPLANT(t_arbore *arb, t_nod_arb *u, t_nod_arb *v);

#endif // ARBORI_H_INCLUDED
