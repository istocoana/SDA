#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DM 1000
#include "cut_rod.c"
#define RANDMAX 5000


int main(int argc, char *argv[]) {

    int n, maxValue, v[DM]={0};
    printf("Introduceti lungimea sirului: ");
    scanf("%d", &n);

    int *a = (int*)malloc(sizeof(int)*(n+1));
    printf("Preturile sunt: \n");
    READ_PRICES(a, n);

    maxValue = CUT_ROD(a, n);
    printf("Valoare maxima recursiva: %d\n", maxValue);

    maxValue = MEMOIZED_CUT_ROD_AUX(a, n);
    printf("Valoare maxima top-down: %d\n", maxValue);

    maxValue = BOTTOM_UP_CUT_ROD(a, n);
    printf("Valoare maxima bottom-up: %d\n", maxValue);

    return EXIT_SUCCESS;
}
