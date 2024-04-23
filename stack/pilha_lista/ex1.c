/****
gcc ex(n).c pilha_lista.c lista.c  
****/
#include "pilha_lista.h"

int testa_mais_elementos(PilhaL *p1, PilhaL *p2) {
    Lista *t1 = p1->topo;
    Lista *t2 = p2->topo;
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
    PilhaL *p1 = cria_PilhaL();
    PilhaL *p2 = cria_PilhaL();
    PilhaL *p3 = cria_PilhaL();

    for (int i = 0; i < 12; i++) {
        push(p1, i * i / 2.0);
        push(p2, i);
        if (i < 5)
            push(p3, i * 2);
    }
    if (testa_mais_elementos(p1, p2))
        printf("Pilha p1 tem mais elementos que a pilha p2\n");
    else 
        printf("Pilha p1 nao tem mais elementos que a pilha p2\n");

    if (testa_mais_elementos(p1, p3))
        printf("Pilha p1 tem mais elementos que a pilha p3\n");
    else    
        printf("Pilha p1 nao tem mais elementos que a pilha p3\n");
    return 0;
}

