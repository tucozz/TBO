#include "item.h"

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

void quick_sort(Item *a, int lo, int hi){
    if(hi <= lo) return;

    int mid = partition(a, lo, hi);
    quick_sort(a, lo, mid-1);
    quick_sort(a, mid+1, hi);
}

void sort(Item *a, int lo, int hi){
    quick_sort(a, lo, hi);
}