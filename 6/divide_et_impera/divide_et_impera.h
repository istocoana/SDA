#ifndef DIVIDE_ET_IMPERA_H_INCLUDED
#define DIVIDE_ET_IMPERA_H_INCLUDED
#define INF 0x3f3f3f3f

void INSERTION_SORT(int *v, int n);

void MERGE_SORT(int *v, int p, int r);
void MERGE(int *v, int p, int q, int r);

void QUICK_SORT(int *v, int p, int r);
int PARTITION(int *v, int p, int r);

void HEAP_SORT(int *v, int n, int *HEAP_SIZE);
void BUILD_MAX_HEAP(int *v, int n, int *HEAP_SIZE);
void MAX_HEAPIFY(int *v, int x, int *HEAP_SIZE);

int left(int x);
int right(int x);

#endif // DIVIDE_ET_IMPERA_H_INCLUDED
