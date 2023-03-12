#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"

void READ_ARRAY(int *a[], int n){
    for(int i=0; i<n; i++){
        printf("A[%d]= ", i);
        scanf("%d", &a[i]);
    }
}

void PRINT_ARRAY(int *a[], int n){
    for(int i=0; i<n; i++){
        printf("a[%d]= %d \n", i, a[i]);
    }
}



int main(){
    int n, a[20];
    printf("Introduceti dimensiunea matricii: ");
    scanf("%d", &n);
    READ_ARRAY(a, n);
    MATRIX_CHAIN_ORDER(a, n);
    PRINT_OPTIMAL_PARENS(1, n-1);
}
