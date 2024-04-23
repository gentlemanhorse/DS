#include "pilha_vetor.h"

void transferir_elementos(PilhaFloat *p1, PilhaFloat *p2, int *flagErro) {
    if((p1->n + p2->n) > MAX) {     // verifica se a quantidade de elementos nas duas pilhas vai atingiar a capicade maxima 
        *flagErro = 1;
        exit(1);
    }
    while (!float_is_empty(p1)) {    // transferi os elementos de uma pilha a outra
        push_float(p2, pop_float(p1));
    }
    *flagErro = 0;
}



int main(int argc, char *argv[]) {
    PilhaFloat *p1 = cria_pilha_float();
    PilhaFloat *p2 = cria_pilha_float();

    for(int i = 0; i < 10; i++) {
        push_float(p1, i);
    }
    printf("Pilha 1:\n");
    print_pilha(p1);
    printf("\n\nPilha 2:\n");
    print_pilha(p2);

    int flag = 0;
    transferir_elementos(p1, p2, &flag);

    if (flag == 0) { 
        printf("Pilha 2 com os elementos da pilha 1:\n");
        print_pilha(p2);
    }
    else {
        printf("Erro\n");
    }
    free_pilha_float(p1);
    free_pilha_float(p2);
    return 0;
}