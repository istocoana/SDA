#include <stdio.h>
#include <stdlib.h>
#include "insertion+merge_sort.c"
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

int main(int argc, char *argv[]) {

    int a[DM] = {0}, n;

    //citeste dimensiunea sirului
    printf("Introduceti dimensiunea sirului: ");
    scanf("%d", &n);


    READ_ARRAY(a, n);
    INSERTION_SORT(a, n);
    printf("\nInsertion sort: \n");
    PRINT_ARRAY(a, n);

    READ_ARRAY(a, n);
    MERGE_SORT(a, 0, n-1);
    printf("\nMerge sort: \n");
    PRINT_ARRAY(a, n);
    return 0;
}
