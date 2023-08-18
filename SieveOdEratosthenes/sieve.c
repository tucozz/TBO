#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

//creates a list between 2 and N filled with 1s;
int *CreateList(int N){
    int *Lista = malloc(sizeof(int)*(N + 1));
    for(int i = 0; i <= N; i++)
        Lista[i] = 1;

    return Lista;
}

//Marks as 0 all numbers that are multiples of X;
void MarkNonPrimes(int *List, int X, int N){
    for(int i = X; i <= N; i++){
        if(i%X == 0)
            List[i] = 0;
    }
}

//find all primes up until N and return the array;
void FindAllPrimes(int N){
    int *Lista = CreateList(N);

    for(int i=2; i <= N; i++){
        if(Lista[i] == 1){
            printf("%d ", i);
            MarkNonPrimes(Lista, i, N);
        }
    }
}