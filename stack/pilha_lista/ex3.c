#include "pilha_lista.h"

void inverter(PilhaFloat **p) {
    PilhaFloat *t = cria_pilha_float();
    while(!vazia_float(*p)) {   // insere o elemento do topo na nova pilha
        push_float(t, pop_float(*p));
    }
    libera_float(*p);
    *p = t; // atribui a pilha a nova pilha
}

int main(int argc, char *argv[]) {
    PilhaFloat *p = cria_pilha_float();

    for(int i = 0; i < 10; i++) 
        push_float(p, (float) i);
    inverter(&p);
    printf("Pilha invertida: ");
    while(!vazia_float(p)) {
        printf("%.0f ", pop_float(p));
    }
    libera_float(p);

}