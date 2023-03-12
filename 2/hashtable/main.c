#include <stdio.h>
#include <stdlib.h>
#include "hash.c"
#define MAX 1000

int main(){
    int T[MAX]= {0}, m, k;

    printf("Functia de dispersie h(k)= (h'(k)+i)mod(m)\n");
    printf("Introduceti dimensiunea tabelului: ");
    scanf("%d", &m); // m - dimensiunea tabelei

    HASH_INIT(T, m);
    printf("Dati numere pana la citirea lui 0 \n");

    scanf("%d", &k); // k - cheia

    while(k){
        int j = HASH_INSERT(T, k, m); //j e locatia(slotul) unde se afla o cheie k
        printf("Cheia inserata la locatia %d \n", j);
        scanf("%d", &k);
    }

    //prinatre continut tabela dispersie:
    HASH_PRINT(T, m);

    //cautare in tabela cheia k
    printf("\n");
    printf("Cautare cheie:");
    scanf("%d", &k);
    int j = HASH_SEARCH(T, k, m);
    if( j > -1){
        printf("Cheia gasita la locatia %d \n", j);
        HASH_PRINT(T, m);
    }
    else printf("Cheia nu a fost gasita");

    //stergere in tabela
    printf("\n");
    printf("Stergere cheie: ");
    scanf("%d", &k);
    j = HASH_DELETE(T, k, m);
    if(j > -1 ){
        printf("Cheia stearsa de la locatia %d \n", j);
        HASH_PRINT(T, m);
    }
    else printf("Cheia nu a fost stearsa!");

    return 0;
}
