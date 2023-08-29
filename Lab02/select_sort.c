#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        int MIN = lo;
        for(int j = lo + i; j < hi; j++){
            if(less(a[j], a[MIN]))
                MIN = j;
        }
        exch(a[i], a[MIN]);
    }
}