#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = hi; i > lo; i--){
        int feztroca = 0;
        for(int j = lo; j < i; j++){
            if(!less(a[j], a[j + 1])){
                exch(a[j], a[j+1]);
                feztroca = 1;
            }
        }
        if(!feztroca) break;
    }
}