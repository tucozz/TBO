#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = 0; i < (hi - lo)/2 + 1; i++){
        int feztroca = 0;
        for(int j = lo + i; j < hi - i; j++){
            if(!less(a[j], a[j + 1])){
                exch(a[j], a[j+1]);
                feztroca = 1;
            }
        }
        for(int j = hi - i - 2; j >= lo + i; j--){
            if(!less(a[j], a[j + 1])){
                exch(a[j], a[j+1]);
                feztroca = 1;
            }
        }
        if(!feztroca) break;
    }
}