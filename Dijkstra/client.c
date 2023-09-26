int main(){
    #include <stdio.h>
    #include <stdlib.h>
    #include "stack.h"

    int qtd, scan;

    scanf("%d", &qtd);

    Stack *stack = stack_construct();

    for(int i = 0; i < qtd; i++){
        scanf("%d", &scan);
        int *aux = malloc(sizeof(int));
        *aux = scan;
        stack_push(stack, &scan);
    }

    return 0;
}