#include "pilha_vetor.h"

int iguais(PilhaFloat *p1, PilhaFloat *p2) {
    if (p1->n != p2->n) 
        return 0;
    for (int i = 0; i < p1->n; i++) {
        if (p1->vetor[i] != p2->vetor[i])
            return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    PilhaFloat *p1 = cria_pilha_float();
    PilhaFloat *p2 = cria_pilha_float();
    PilhaFloat *p3 = cria_pilha_float();

    for (int i = 0; i < 10; i++) {
        push_float(p1, (float) i);
        push_float(p2, (float) i);
        push_float(p3, 12.4 / (float) i);
    }

    printf("Pilha 1:\n");
    print_pilha(p1);
    printf("Pilha 2:\n");
    print_pilha(p2);
    printf("Pilha 3:\n");
    print_pilha(p3);

    if (iguais(p1, p2)) 
        printf("Pilha 1 e 2 sao iguais\n");
    else    
        printf("Pilha 1 e 2 nao sao iguais\n");

    if (iguais(p1, p3))
        printf("Pilha 1 e 3 sao iguais\n");
    else   
        printf("Pilha 1 e 3 nao sao iguais\n");

    free_pilha_float(p1);
    free_pilha_float(p2);
    free_pilha_float(p3);
    return 0;
}