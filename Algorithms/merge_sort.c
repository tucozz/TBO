#include "item.h"
#include <stdlib.h>

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

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for(int k = lo; k <= hi; k++){
        aux[k] = a[k];
    }
    int i = lo;
    int j = mid + 1;
    for(int k = lo; k <= hi; k++){
        if      (i > mid)           a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (less(aux[j], aux[i]))  a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi){
    #if defined CUTOFF && (defined VERSAO_2 || defined VERSAO_4) 
    if(hi <= lo + CUTOFF - 1){
        insertion_sort(a, lo, hi);
    #else
    if(hi <= lo){
    #endif
        return;
    }
    int mid = lo + ((hi - lo) / 2);
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    #if defined VERSAO_2 || defined VERSAO_4
    if (!less(a[mid+1], a[mid])) return;
    #endif
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi){
    Item *aux = calloc(hi - lo + 1, sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}