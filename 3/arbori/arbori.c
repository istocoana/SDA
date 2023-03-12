#include "arbori.h"

t_nod_arb* MAKEROOT(t_arbore *arb, int key){
    arb->root = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    arb->root->key = key;
    arb->root->left = NULL;
    arb->root->right = NULL;
    arb->root->parent = NULL;
    return arb->root;

}

t_nod_arb* CREATE_NODE(int key){
    t_nod_arb *nod;
    nod = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    nod->key = key;
    nod->left = NULL;
    nod->right = NULL;
    nod->parent = NULL;
    return nod;

}

void INORDER_WALK(t_nod_arb *root){
    if(root != NULL){
        INORDER_WALK(root->left);
        printf("%d", root->key);
        INORDER_WALK(root->right);
    }
}

void PREORDER_WALK(t_nod_arb *root){
        if(root != NULL){
            printf("%d", root->key);
            PREORDER_WALK(root->left);
            PREORDER_WALK(root->right);
        }
}

void POSTORDER_Walk(t_nod_arb *root){
    if(root != NULL){
        POSTORDER_Walk(root->left);
        POSTORDER_Walk(root->right);
        printf("%d", root->key);
    }
}

t_nod_arb* TREE_MIN(t_nod_arb *nod){
    while( nod->left != NULL){
        nod = nod->left;
    }
    return nod;
}

t_nod_arb* TREE_MAX(t_nod_arb *nod){
    while(nod->right != NULL){
        nod = nod->right;
    }
    return nod;
}

t_nod_arb*  TREE_SUCCESOR(t_nod_arb *nod){
    t_nod_arb *y = NULL;
    if(nod->right != NULL){
        return TREE_MIN(nod->right);
    }
    y = nod->parent;
    while(y != NULL && nod == y->right){
        nod = y;
        y = nod->parent;
    }
    return y;
}

t_nod_arb* TREE_SEARCH(t_nod_arb *nod, int key){
    if(nod == NULL || key == nod->key){
        return nod;
    }
    if(key < nod->key){
        return TREE_SEARCH(nod->left, key);
    }
    else return TREE_SEARCH(nod->right, key);
}

t_nod_arb*  IT_TREE_SEARCH(t_nod_arb *nod, int key){
    while(nod != NULL && key != nod->key){
        if(key < nod->key){
            nod = nod->left;
        }
        else nod = nod->right;
    }
    return nod;
}

void TREE_INSERT(t_arbore *arb, t_nod_arb *nod){
    t_nod_arb *x = arb->root;
    t_nod_arb *y = NULL;
    while( x != NULL){
        y = x;
        if(nod->key < x->key){
            x = x->left;
        }
        else x = x->right;
    }
    nod->parent = y;
    if(y == NULL){
        arb->root = nod;
    }
    else if( nod->key < y->key){
        y->left = nod;
    }
    else y->right = nod;
}

void TRANSPLANT(t_arbore *arb, t_nod_arb *u, t_nod_arb *v){
        if(u->parent == NULL){
            arb->root = v;
        }
        else if(u == u->parent->left){
            u->parent->left = v;
        }
        if(v){
            v->parent = u->parent;
        }
}


void TREE_DELETE(t_arbore *arb, t_nod_arb *nod){
    t_nod_arb *y;
    if(nod->left == NULL){
        TRANSPLANT(arb, nod, nod->right);
    }
    else if(nod->right == NULL){
        TRANSPLANT(arb, nod, nod->left);
    }
    else
        y = TREE_MIN(nod->right);
        if(y->parent != nod){
            TRANSPLANT(arb, y, y->right);
            y->right = nod->right;
            y->right->parent = y;
        }
        TRANSPLANT(arb, nod, y);
        y->left = nod->left;
        y->left = y;
}

