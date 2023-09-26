#include "item.h"
//#if defined VERSAO_3 || VERSAO_4
#include <stdlib.h>
//#endif

int partition(Item *a, int lo, int hi){
    int i = lo, j = hi+1;
    Item v = a[lo];
    while(1){
        while(less(a[++i], v)) //vai ate encontrar um item pra trocar
            if(i == hi) break;
        while(less(v, a[--j])) //vai ate encontrar um item pra trocar
            if(j == lo) break;
        if(i >= j) break; // checa se os indices cruzaram
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); //salatiel magic
    return j; // retorna o idx do nucleo que COM CERTEZA ta no lugar certo
}

#if defined VERSAO_2 || defined VERSAO_4

void insertion_sort(Item *a, int lo, int hi){
    for(int i = lo; i <= hi; i++){
        for(int j = i-1; j >= lo; j--){
            if(less(a[j+1], a[j]))
                exch(a[j], a[j+1]);
        }
    }
}

#endif

//#if defined VERSAO_3 || defined VERSAO_4
    
int median_of_3(Item *a, int lo, int hi){

}

//#endif

void quick_sort(Item *a, int lo, int hi){
    #ifdef CUTOFF
    if(hi <= lo + CUTOFF - 1){
        insertion_sort(a, lo, hi);
    #else
    if(hi <= lo){
    #endif
        return;
    }
    #if defined VERSAO_3 || defined VERSAO_4
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    #endif
    int mid = partition(a, lo, hi);
    quick_sort(a, lo, mid-1);
    quick_sort(a, mid+1, hi);
}

void sort(Item *a, int lo, int hi){
    quick_sort(a, lo, hi);
}