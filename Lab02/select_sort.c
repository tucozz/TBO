#include "item.h"

void sort(Item *a, int lo, int hi){
    //escolhe qual o idx que a gente vai ACERTAR agora
    for(int i = lo; i < hi; i++){
        //fala "0k. a partir de i, qual o menor numero?"
        int MIN = i;
        for(int j = i + 1; j < hi; j++){
            if(less(a[j], a[MIN]))
                MIN = j;
        }
        //decidido o menor numero, troca ele de lugar com o atual
        exch(a[i], a[MIN]);
    }
}