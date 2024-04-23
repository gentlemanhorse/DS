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

    return 0;
}