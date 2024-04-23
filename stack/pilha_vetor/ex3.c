#include "pilha_vetor.h"

void inverter(PilhaFloat **p) {
    PilhaFloat *t = cria_pilha_float();
    while (!float_is_empty(*p)) {
        push_float(t, pop_float(*p));
    }
    free_pilha_float(*p);
    *p = t;
}

int main(int arg, char *argv[]) {
    PilhaFloat *p = cria_pilha_float();
    for(int i = 0; i < 10; i++) {
        push_float(p, i);
    }
    printf("Pilha:\n");
    print_pilha(p);
    inverter(&p);
    printf("Pilha invertida:\n");
    print_pilha(p);

    return 0;
}