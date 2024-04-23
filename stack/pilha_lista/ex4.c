#include "pilha_lista.h"

int iguais(PilhaFloat *p1, PilhaFloat *p2) {
    while (!vazia_float(p1) && !vazia_float(p2)) {
        if (pop_float(p1) != pop_float(p2))
            return 0;
    }
    if (!vazia_float(p1) || !vazia_float(p2))
        return 0;

    return 1;
}

int main(int argc, char *argv[]) {
    PilhaFloat *p1 = cria_pilha_float();
    PilhaFloat *p2 = cria_pilha_float();
    PilhaFloat *p3 = cria_pilha_float();

    for(int i = 0; i < 10; i++) { 
        push_float(p1, (float) i);
        push_float(p2, (float) i);
        push_float(p3, 12.4 / (float) i);
    }
    if (iguais(p1, p2)) 
        printf("Pilha 1 e 2 sao iguais\n");
    else    
        printf("Pilha 1 e 2 nao sao iguais\n");

    if (iguais(p1, p3))
        printf("Pilha 1 e 3 sao iguais\n");
    else   
        printf("Pilha 1 e 3 nao sao iguais\n");

    libera_float(p1);
    libera_float(p2);
    libera_float(p3);
    return 0;
}