#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[]){
    
    //Receber como um parametro o numero N de itens a serem ordenados.
    int qtd;
    if(argc != 2)
        exit(printf("Definir quantidade de entradas\n"));
    sscanf(argv[1],"%d", &qtd);

    //Alocar dinamicamente um array para guardar os N itens na memoria.
    Item *array = calloc(qtd, sizeof(Item));

    //Ler os N itens (no caso aqui, inteiros) de stdin para o array.
    for(int i = 0; i < qtd; i++){
        scanf("%d", &array[i]);
    }

    //Executar um algoritmo de ordenacao e medir o seu tempo, como ja feito em laboratorios anteriores.
    clock_t t;
    t = clock();
    sort(array, 0, qtd-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    #ifdef PRINT

    //Exibir o array ordenado em stdout.
    for(int i = 0; i < qtd; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    #endif

    printf("O algoritmo levou %f segundos para executar\n", time_taken);
    
    //Liberar a memoria do array.
    free(array);

    return 0;
}