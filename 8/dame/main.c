#include <stdio.h>
#include <stdlib.h>
#include "dame.c"
#define DM 1000

void PRINT_ARRAY(int *v, int n){
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void READ_ARRAY(int *v, int n){
    for(int i=0; i<n; i++){
        printf("Introduceti elementul cu index-ul %d: ", i);
        scanf("%d", &v[i]);
    }
}

void INIT_ARRAY(int **v, int n){
    *v = (int*)malloc(sizeof(int)*(n+1));
}

int main()
{
    int n, nr_sol = 0;
    int x[DM]={0};

    printf("Introduceti numarul de dame: ");
    scanf("%d", &n);

    INIT_ARRAY(&x, n);
    x[3]++;
    DAME(&x, n, &nr_sol);
    printf("Numar solutii: %d", nr_sol);
    return 0;
}
