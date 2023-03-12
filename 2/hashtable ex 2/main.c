#include <stdio.h>
#include <stdlib.h>
#include "hash.c"
#define MAX 100

int main()
{
    t_lista T[MAX];
    int m, k;

    printf("Functia de dispersie h(k) = k mod m\n");
    printf("Introduceti dimensiuea tabelei: ");
    scanf("%d", &m);

    INIT_HASHTABLE(T, m);

    //introducerea numerelor in hash
    printf("Dati numere pana la citirea lui 0: \n");
    scanf("%d", &k);
    while(k){
        //inserare cheie k la slotul j
        int j = CHAINED_HASH_INSERT(T, k, m);
        printf("Am adaugat elementul %d\n", k);
        printf("Tabela acualizata: \n");
        PRINT_HASHTABLE(T, m);
        scanf("%d", &k);
    }

    printf("\nInserati cheie de cautat: \n");
    scanf("%d", &k);
    int j = CHAINED_HASH_SEARCH(T, k, m);
    if(j > -1){
        printf("Cheia gasita la locatia %d \n", j);
    }
    else printf("Cheia nu a fost gasita!\n");

    printf("\nCheie pentru stergere: ");
    scanf("%d", &k);
    j = CHAINDED_HASH_DELETE(T, k, m);
    if(j > -1){
        printf("Cheia stearsa de la locatia %d\n", j);
        PRINT_HASHTABLE(T, m);
    }
    else printf("Cheia nu a fost gasita!");

    return 0;
}
