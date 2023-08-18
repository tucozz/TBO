#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

//Bruxaria
#define SetBit(A,k)     ( A[(k)/32] |= (1 << ((k)%32)) )
#define ClearBit(A,k)   ( A[(k)/32] &= ~(1 << ((k)%32)) )
#define TestBit(A,k)    ( A[(k)/32] & (1 << ((k)%32)) )

//creates a list between 2 and N filled with 1s;
int *CreateList(int N){
     int *Lista = malloc(sizeof(int) * N/32 + 1);
    for(int i = 0; i <= N; i++)
        SetBit(Lista, i);

    return Lista;
}

//Marks as 0 all numbers that are multiples of X;
void MarkNonPrimes(int *List, int X, int N){
    for(int i = X; i <= N; i++){
        if(i%X == 0)
            ClearBit(List, i);
    }
}

//find all primes up until N and return the array;
void FindAllPrimes(int N){
    int *Lista = CreateList(N);

    for(int i=2; i <= N; i++){
        if(TestBit(Lista, i)){
            printf("%d ", i);
            MarkNonPrimes(Lista, i, N);
        }
    }
}