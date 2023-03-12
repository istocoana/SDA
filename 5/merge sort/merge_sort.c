#include "merge_sort.h"


void MERGE_SORT(int *v, int p, int r){
    int q = 0;
    if(p < r){
        q = ( p + r )/2;
        MERGE_SORT(v, p, q);
        MERGE_SORT(v, q+1, r);
        MERGE(v, p, q, r);
    }
}

void MERGE(int *v, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int *left = (int*)malloc(sizeof(int)*(n1+2));
    int *right = (int*)malloc(sizeof(int)*(n2+2));

    for(int i=1; i<=n1; ++i){
        left[i] = v[p+i-1];
    }
    for(int i=1; i<=n2; ++i){
        right[i] = v[q+i];
    }

    left[n1+1] = INF;
    right[n2+1] = INF;

    int i=1, j=1;
    for(int k=p; k<=r; ++k){
        if(left[i]  <= right[j]){
            v[k] = left[i++];
        } else v[k] = right[j++];
    }

    free(left);
    free(right);
}
