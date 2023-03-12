#ifndef RB_H_INCLUDED
#define RB_H_INCLUDED


typedef struct rb_node {
    enum { red, black } color;
    int key;
    struct rb_node *left, *right, *parent;
} t_rb_node;

typedef struct {
    t_rb_node *root;
} t_rb_arbore;

t_rb_node* MAKE_ROOT(t_rb_arbore* A, int key);

t_rb_node* CREATE_NOD(int key);

void INORDER_WALK(t_rb_node* root);

t_rb_node* TREE_SEARCH(t_rb_node* n, int key );

void RB_INSERT(t_rb_arbore* A, t_rb_node* z);

void RB_INSERT_FIXUP(t_rb_arbore *A, t_rb_node *z);

void LEFT_ROTATE( t_rb_arbore* A, t_rb_node* x);

void RIGHT_ROTATE( t_rb_arbore* A, t_rb_node* x);

#endif // RB_H_INCLUDED
