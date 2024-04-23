#include "pilha_vetor.h"

int testa_mais_elementos(PilhaFloat *p1, PilhaFloat *p2) {
    return (p1->n > p2->n);     //retorna se a pilha 1 tem mais elementos
}


int main(int argc, char *argv[]) {
    PilhaFloat *p1 = cria_pilha_float();
    PilhaFloat *p2 = cria_pilha_float();
    PilhaFloat *p3 = cria_pilha_float();

    for (int i = 0; i < 12; i++) {
        push_float(p1, i * i / 2.0);
        push_float(p2, i);
        if (i < 5)
            push_float(p3, i * 2);
    }
    printf("Pilha 1:\n");
    print_pilha(p1);
    printf("\n\npilha 2:\n");
    print_pilha(p2);
    printf("\n\nPilha 3:\n");
    print_pilha(p3);
    if (testa_mais_elementos(p1, p2))
        printf("Pilha p1 tem mais elementos que a pilha p2\n");
    else 
        printf("Pilha p1 nao tem mais elementos que a pilha p2\n");

    if (testa_mais_elementos(p1, p3))
        printf("Pilha p1 tem mais elementos que a pilha p3\n");
    else    
        printf("Pilha p1 nao tem mais elementos que a pilha p3\n");
    return 0;
    free_pilha_float(p1);
    free_pilha_float(p2);
    free_pilha_float(p3);
}
