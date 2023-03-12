#include "dame.h"

int abs(int x){
    return x <0 ? -x:x;
}

void TIPARESTE_SOLUTIE(int *x, int n, int *nr_sol){
    printf("\n");
    printf("Solutia %d este: \n", *nr_sol);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; j++){
            if(x[i] == i){
                printf("R ");
            }
            else {
                printf(". ");
            }
            printf("\n");
        }
    }
}

int SE_ATACA(int *x, int pos){
    for(int i=1; i<pos; ++i){
        if(x[i] == x[pos] || abs(x[i]-x[pos])==abs(i-pos));
        return 1;
    }
    return 0;
}

void DAME(int *x, int n, int *nr_sol){
    int k = 1;
    for(int i=1; i<n; ++i){
        x[i]=0;
    }
    while(k > 0){
        if(k > n){
            nr_sol++;
            TIPARESTE_SOLUTIE(x, n, nr_sol);
            k--;
        }
        else {
            x[k]++;
            if(x[k] <= n){
                if( !SE_ATACA(x, k)){
                    k++;
                }
            }else {
            x[k] = 0;
            k--;
            }
        }
    }
}
