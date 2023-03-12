#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

//m - dimensiunea tabelului
//k - cheia

void HASH_INIT(int T[], int m);
int HASH_PRIM(int k, int m);
int HASH_PROBEF(int k, int i, int m); //functia de probare liniara
int HASH_INSERT(int T[], int k, int m);
int HASH_SEARCH(int T[], int k, int m);
int HASH_DELETE( int T[], int k, int m);
void HASH_PRINT( int T[], int m);


#endif // HASH_H_INCLUDED
