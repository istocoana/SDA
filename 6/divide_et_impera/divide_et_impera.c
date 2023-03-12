#include "divide_et_impera.h"

void INSERTION_SORT(int *v, int n){
    int i, key, j;
    for(j=1; j<n; ++j){
        key = v[j];
        i = j-1;
        while(i >=0 && v[i] > key){
            v[i+1]= v[i];
            i--;
        }
        v[++i] = key;
    }
}

void MERGE_SORT(int *v, int p, int r){
    int q = 0;
    if(p < r){
        q = (p + r)/2;
        MERGE_SORT(v, p, q-1);
        MERGE_SORT(v, q+1, r);
        MERGE(v, p, q, r);
    }
}

void MERGE(int *v, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int *left = (int*)malloc(sizeof(int*));
    int *right = (int*)malloc(sizeof(int*));

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
        if(left[i] <= right[j]){
            v[k] = left[i++];
        } else v[k] = right[j++];
    }

    free(left);
    free(right);
}

void QUICK_SORT(int *v, int p, int r){
    int q = 0;
    if(p < r){
        q = PARTITION(v, p, r);
        QUICK_SORT(v, p, q-1);
        QUICK_SORT(v, q+1, r);
    }
}

int PARTITION(int *v, int p, int r){
    int x = v[r];
    int i = p-1;

    for(int j=p; j<r; j++){
        if(v[j] <= x){
            i++;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
         }
    }
    v[r] = v[i+1];
    v[i+1] = x;
    return i+1;

}

void HEAP_SORT(int *v, int n, int *HEAP_SIZE){
    BUILD_MAX_HEAP(v, n, HEAP_SIZE);
    for(int i = n-1; i>0; --i){
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        (*HEAP_SIZE)--;
        MAX_HEAPIFY(v, 0, HEAP_SIZE);
    }
}

void BUILD_MAX_HEAP(int *v, int n, int *HEAP_SIZE){
    *HEAP_SIZE = n-1;
    for(int i=n/2; i>=0; --i){
        MAX_HEAPIFY(v, i, HEAP_SIZE);
    }
}

void MAX_HEAPIFY(int *v, int x, int *HEAP_SIZE){
    int l = left(x);
    int r = right(x);
    int largest;

    if(l <= *HEAP_SIZE && v[l] > v[x]){
        largest = l;
    } else largest = x;

    if(r <= *HEAP_SIZE && v[r] > v[largest]){
        largest = r;
    }

    if(largest != x){
        int aux = v[x];
        v[x] = v[largest];
        v[largest] = aux;
        MAX_HEAPIFY(v, largest, HEAP_SIZE);
    }
}

int left(int x){
    return 2*x;
     }
int right(int x) {
    return 2*x+1;
    }
