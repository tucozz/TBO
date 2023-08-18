#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

//creates a list between 2 and N filled with xs;
char *CreateList(int N){
    char *Lista = malloc(sizeof(int)*(N + 1));
    for(int i = 0; i <= N; i++)
        Lista[i] = 'x';

    return Lista;
}

//Marks as 0 all numbers that are multiples of X;
void MarkNonPrimes(char *List, int X, int N){
    for(int i = X; i <= N; i++){
        if(i%X == 0)
            List[i] = '-';
    }
}

//find all primes up until N and return the array;
void FindAllPrimes(int N){
    char *Lista = CreateList(N);

    for(int i=2; i <= N; i++){
        if(Lista[i] == 'x'){
            printf("%d ", i);
            MarkNonPrimes(Lista, i, N);
        }
    }
}