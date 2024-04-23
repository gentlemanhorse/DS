#include "pilha_vetor.h"

void transferir_elementos(PilhaFloat *p1, PilhaFloat *p2, int *flagErro) {
    if((p1->n + p2->n) > MAX) {
        *flagErro = 1;
        exit(1);
    }
    for(int i = 0; i < p1->n; i++) {
        push_float(p2, p1->vetor[i]);
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
    print_lista(p1);
    printf("\n\nPilha 2:\n");
    print_lista(p2);

    int flag = 0;
    transferir_elementos(p1, p2, &flag);

    if (flag == 0) { 
        printf("Pilha 1:\n");
        print_lista(p1);
        printf("\n\nPilha 2 com os elementos da pilha 1:\n");
        print_lista(p2);
    }
    else {
        printf("Erro\n");
    }
    free_pilha_char(p1);
    free_pilha_char(p2);
    return 0;
}