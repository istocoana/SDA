#include "rb.h"

t_rb_node* MAKE_ROOT(t_rb_arbore* A, int key) {
    A->root = (t_rb_node*)malloc(sizeof(t_rb_node));
    A->root->key = key;
    A->root->left = NULL;
    A->root->right = NULL;
    A->root->parent = NULL;
    A->root->color = black;
    return A->root;
}

t_rb_node* CREATE_NOD(int key) {
    t_rb_node* nod = (t_rb_node*)malloc(sizeof(t_rb_node));
    nod->key = key;
    nod->left = NULL;
    nod->right = NULL;
    nod->parent = NULL;
    nod->color = black;
    return nod;
}

void INORDER_WALK(t_rb_node* root) {
    if( root != NULL ) {
        INORDER_WALK(root->left);
        printf("%d", root->key);
        if(root->color == black){
            printf("[b]\n");
        } else {
            printf("[r]\n");
        }
        INORDER_WALK(root->right);
    }
}

t_rb_node* TREE_SEARCH(t_rb_node* n, int key ) {
    if( n == NULL || key == n->key) return n;
    if( key < n->key ) return TREE_SEARCH(n->left, key);
    return TREE_SEARCH(n->right, key);
}

void RB_INSERT(t_rb_arbore* A, t_rb_node* z) {
    t_rb_node *y = NULL;
    t_rb_node *x = A->root;
    while ( x != NULL ) {
        y = x;
        if ( z->key < x->key ) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if( y == NULL ){
        A->root = z;
    }else if( z->key < y->key ){
        y->left = z;
    }else y->right = z;

    z->left = NULL;
    z->right = NULL;
    z->color = red;
    RB_INSERT_FIXUP(A, z);
}

void RB_INSERT_FIXUP(t_rb_arbore *A, t_rb_node *z) {

    t_rb_node* y = NULL;
    while( z->parent != NULL && z->parent->color == red) {
        if( z->parent == NULL || z->parent->parent == NULL) {
            printf("Am ajuns in nod null \n");
            return;
        }
        if( z->parent == z->parent->parent->left ) {
            y = z->parent->parent->right;
            if( y != NULL && y->color == red ) {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            } else {
                if( z == z->parent->right) {
                    z = z->parent;
                    LEFT_ROTATE( A, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                RIGHT_ROTATE(A, z->parent->parent);
            }
        } else {
            y = z->parent->parent->left;
            if( y != NULL && y->color == red) {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    RIGHT_ROTATE(A, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                LEFT_ROTATE(A, z->parent->parent);
            }
        }
    }
    A->root->color = black;
}

void LEFT_ROTATE( t_rb_arbore* A, t_rb_node* x) {
    t_rb_node* y = x->right;
    x->right = y->left;

    if( y->left != NULL ){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if( x->parent == NULL ) {
        A->root = y;
    } else if( x == x->parent->left ) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RIGHT_ROTATE( t_rb_arbore* A, t_rb_node* x) {
    t_rb_node* y = x->left;
    x->left = y->right;

    if( y->right != NULL ) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if( x->parent == NULL ) {
        A->root = y;
    } else if( x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}
