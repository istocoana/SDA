#include "matrix.h"

int s[20][20];

void PRINT_OPTIMAL_PARENS(int i, int j){
    if(i == j){
        printf("A[%d]", i);
    } else {
        printf(" (");
        PRINT_OPTIMAL_PARENS(i, s[i][j]);
        PRINT_OPTIMAL_PARENS(s[i][j]+1, j);
        printf(") ");
    }
}

void MATRIX_CHAIN_ORDER(int p[], int n){
    n = n-1;
    int m[20][20], i, t, j, k, q;
    for(i=1; i<=n; i++){
        m[i][i] = 0;
    }

    for(t=2; t<=n; t++){
        for(i=1; i<=n-t+1; i++){
            j = i + t - 1;
            m[i][j] = INF;
            for(k=i; k<j; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
