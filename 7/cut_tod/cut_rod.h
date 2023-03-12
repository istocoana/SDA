#ifndef CUT_ROD_H_INCLUDED
#define CUT_ROD_H_INCLUDED

#define INF 0x3f3f3f3f

void READ_PRICES(int *a, int n);
int MAX(int a, int b);
int CUT_ROD(int *p, int n);
int BOTTOM_UP_CUT_ROD(int *p, int n);
int MEMORIZED_CUT_ROD_AUX(int *p, int n, int *r);
int MEMOIZED_CUT_ROD(int *p, int n);
void PRINT_ARRAY(int *v, int n);

#endif // CUT_ROD_H_INCLUDED
