#include "pilha_lista.h"

int testa_mais_elementos(PilhaFloat *p1, PilhaFloat *p2) {
    NoFloat *t1 = p1->topo;
    NoFloat *t2 = p2->topo;
    while (t1 != NULL && t2 != NULL) {
        t1 = t1->prox;
        t2 = t2->prox;
    }
    if(t1 == NULL) {
        return 0;
    }
    return 1;
}


int main(int argc, char *argv[]) {
    PilhaFloat *p1 = cria_pilha_float();
    PilhaFloat *p2 = cria_pilha_float();
    PilhaFloat *p3 = cria_pilha_float();

    for (int i = 0; i < 12; i++) {
        push_float(p1, i * i / 2.0);
        push_float(p3, i);
        if (i < 5)
            push_float(p2, i * 2);
    }
    if (testa_mais_elementos(p1, p2))
        printf("Pilha p1 tem mais elementos que a pilha p2\n");
    else 
        printf("Pilha p1 nao tem mais elementos que a pilha p2\n");

    if (testa_mais_elementos(p1, p3))
        printf("Pilha p1 tem mais elementos que a pilha p3\n");
    else    
        printf("Pilha p1 nao tem mais elementos que a pilha p3\n");

    libera_float(p1);
    libera_float(p2);
    libera_float(p3);
    return 0;
}

