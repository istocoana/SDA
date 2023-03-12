#include "cut_rod.h"

void READ_PRICES(int *a, int n) {
    for(int i=1;i<=n;++i)
        scanf("%d", &a[i]);
}

int MAX(int a, int b) {
    return ( a < b ? b:a );
}

int CUT_ROD(int *p, int n) {
    if( n == 0 )
        return 0;
    int q = -INF;
    for(int i=1; i<=n; ++i) {
        q = MAX(q, p[i] + CUT_ROD(p, n-i));
    }
    return q;
}

int BOTTOM_UP_CUT_ROD(int *p, int n) {
    int *r = (int*)malloc(sizeof(int)*(n+1));
    r[0] = 0;
    for(int j=1;j<=n;++j) {
        int q = -INF;
        for(int i=1;i<=j;++i) {
            q = MAX(q, p[i] + r[j-i]);
        }
        r[j] = q;
    }

    int returnValue = r[n];
    free(r);
    return returnValue;
}

int MEMORIZED_CUT_ROD_AUX(int *p, int n, int *r) {
    int q;

    if(r[n] >= 0)
        return r[n];
    if( n == 0 ) {
        q = 0;
    } else {
        q = -INF;
        for(int i=1;i<=n;++i) {
            q = MAX(q, p[i] + MEMORIZED_CUT_ROD_AUX(p, n-i, r));
        }
    }
    r[n] = q;
    return q;
}

void PRINT_ARRAY(int *v, int n) {
    printf("Segmentele posibile sunt: ");
    for(int i=1;i<=n;++i){
        printf(" %d ", v[i]);
    }
    printf("\n");
}

int MEMOIZED_CUT_ROD_AUX(int *p, int n) {
    int *r = (int*)malloc(sizeof(int)*(n+1));
    for(int i=0; i<=n; ++i) {
        r[i] = -INF;
    }
    int q = MEMORIZED_CUT_ROD_AUX(p, n, r);
    PRINT_ARRAY(r, n);
    return q;
}


