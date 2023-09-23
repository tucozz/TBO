#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i <= hi; i++){
        for(int j = i-1; j >= lo; j--){
            if(less(a[j+1], a[j]))
                exch(a[j], a[j+1]);
        }
    }
}