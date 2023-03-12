#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "greedy.c"
#define RANDMAX 5000
#define DM 1000

void PRINT_ARRAY(int *v, int n, int *s, int *f){
    for(int i=0; i<n; ++i){
        printf("%d: (%d, %d)\n", v[i], s[v[i]], f[v[i]]);
    }
    printf("\n");
}

void READ_ARRAY(int *v, int n){
    for(int i=1; i<=n; ++i){
        printf("Activitatea cu numarul %d: ", i);
        scanf("%d", &v[i]);
    }
}

void INIT_ARRAY(int **v, int n){
    *v = (int*)malloc(sizeof(int)*(n+1));
}


int main()
{
    int s[DM] = {0}, f[DM] = {0};
    int SOLUTIE_RECURSIVA[DM] = {0}, SOLUTIE_ITERATIVA[DM] ={0};
    int n;

    printf("Introduceti numarul de activitati: ");
    scanf("%d", &n);

    INIT_ARRAY(&SOLUTIE_RECURSIVA, n);
    INIT_ARRAY(&SOLUTIE_ITERATIVA, n);
    INIT_ARRAY(&s, n);
    INIT_ARRAY(&f, n);

    printf("Introduceti momentele de start ale activitatilor: \n");
    READ_ARRAY(s, n);
    printf("\n");

    printf("Introduceti momentele de finish ale activitatilor: \n");
    READ_ARRAY(f, n);
    printf("\n");



    f[0] = 0;

    int length_sol_rec = RECUSRIVE_ACTIVITY_SELECTOR(s, f, 0, n, SOLUTIE_RECURSIVA);
    printf("Activitatile optime alese prin metoda recursiva: \n");
    PRINT_ARRAY(SOLUTIE_RECURSIVA, length_sol_rec, s, f);

    int length_sol_it = GREEDY_ACTIVITY_SELECTOR(s, f, n, SOLUTIE_ITERATIVA);
    printf("Activitatile optime alese prin metoda iterativa: \n");
    PRINT_ARRAY(SOLUTIE_ITERATIVA, length_sol_it, s, f);



    free(SOLUTIE_ITERATIVA);
    free(SOLUTIE_RECURSIVA);
    free(s);
    free(f);

    return 0;

}
