#include "pilha_vetor.h"

void inverter(PilhaFloat **p) {
    PilhaFloat *t = cria_pilha_float();
    while (!float_is_empty(*p)) {   // enquanto a pilha nao eh vaiza, transferi os elementos para o a nova pilha
        push_float(t, pop_float(*p));
    }
    free_pilha_float(*p);   
    *p = t; // atribui a nova pilha para a antiga
}

int main(int argc, char *argv[]) {
    PilhaFloat *p = cria_pilha_float();
    for(int i = 0; i < 10; i++) {
        push_float(p, i);
    }
    printf("Pilha:\n");
    print_pilha(p);
    inverter(&p);
    printf("Pilha invertida:\n");
    print_pilha(p);
    free_pilha_float(p);

    return 0;
}