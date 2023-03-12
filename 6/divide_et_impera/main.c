#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "divide_et_impera.c"
#define DM 1000


void READ_ARRAY(int *v, int n ) {
    for(int i=0; i<n; ++i) {
        printf("Introduceti elementul cu index-ul %d: ", i);
        scanf("%d", &v[i]);
    }
}

void PRINT_ARRAY(int v[DM], int n) {
    for(int i=0; i<n; ++i){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int a[DM] = {0}, n, option, HEAP_SIZE = 0;

    printf("Introduceti dimensiunea sirului: "); scanf("%d", &n);
    READ_ARRAY(a, n);
    printf("Sirul initial: ");
    PRINT_ARRAY(a, n);

    printf("\n Introduceti metoda de sortare: \n");
    printf("1 - QuickSort \n");
    printf("2 - HeapSort\n");
    printf("3 - MergeSort\n");
    printf("4 - InsertionSort\n");

    scanf("%d", &option);

    switch(option){
        case 1:
            QUICK_SORT(a, 0, n-1);
            break;
        case 2:
            HEAP_SORT(a, n, &HEAP_SIZE);
            break;
        case 3:
            MERGE_SORT(a, 0, n-1);
            break;
        case 4:
            INSERTION_SORT(a, n);
            break;
        default:
            printf("Nu ati introdus o optiune valida!\n");
    }

    PRINT_ARRAY(a, n);
    return 0;
}
