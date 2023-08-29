#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

int main(){
    
    //Receber como um parametro o numero N de itens a serem ordenados.
    int qtd;
    scanf("%d", &qtd);

    //Alocar dinamicamente um array para guardar os N itens na memoria.
    Item *array = calloc(qtd, sizeof(Item));

    //Ler os N itens (no caso aqui, inteiros) de stdin para o array.
    for(int i = 0; i < qtd; i++){
        scanf("%d", &array[i]);
    }

    //Executar um algoritmo de ordenacao e medir o seu tempo, como ja feito em laboratorios anteriores.
    clock_t t;
    t = clock();
    sort(array, 0, qtd);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("O algoritmo levou %f segundos para executar\n", time_taken);

    //Exibir o array ordenado em stdout.
    for(int i = 0; i < qtd; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    
    //Liberar a memoria do array.
    free(array);

    return 0;
}