#include "pilha_lista.h"

void transferir_elementos(PilhaFloat *p1, PilhaFloat *p2, int *flagErro) {
    *flagErro = 1;
    while (!vazia_float(p1)) {  // insere na pilha 2 os elementos da pilha 1
        push_float(p2, pop_float(p1));
    }
    flagErro = 0;
}

int main(int argc, char *argv[]) {
    PilhaFloat *p1 = cria_pilha_float();    
    PilhaFloat *p2 = cria_pilha_float();
    printf("Pilha 1: ");
    for(int i = 0; i < 10; i++) {
        push_float(p1, (float) i);
        printf("%.0f ", (float) i);
    }
    int err = 0;
    transferir_elementos(p1, p2, &err);
    printf("\nPilha 2: ");
    while(!vazia_float(p2)) {
        float v = pop_float(p2);
        printf("%.0f ", v);
    }

    libera_float(p1);
    libera_float(p2);
}