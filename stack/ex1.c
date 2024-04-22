#include "array_stack.h"

int main(int argc, char *argv[]) {
    Stack *s1 = create_stack();
    Stack *s2 = create_stack();
    printf("Stack 1\n");
    for(int i = 0; i < 10; i++) 
	    push(s1, 1.9 * i);
    
    printf("\n\nStack 2\n");
    for(int i = 0; i < 20; i++)
	    push(s2, 12.2 * i);
 
    printf("\n\n");
    if(testa_mais_elementos(s1, s2)) 
        printf("Stack 1 contem mais elementos que a stack 2.\n");

    else 
        printf("Stack 2 contem mais elementos que a stack 1.\n");
    
    printf("Stack invertida:\n");
    inverter(s1);

    if (iguais(s1, s2)) {
        printf("Stacks são iguais\n");
    }
    else 
        printf("Nao sao iguais\n");

    free_stack(s1);
    free_stack(s2);
    return 0;
}
