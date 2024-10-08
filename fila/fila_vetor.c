#include "fila_vetor.h"

int incr(int i) {
    return (i+1)%N;
}

FilaVetor* cria_fila_v(void) {
    FilaVetor *f = (FilaVetor *) malloc(sizeof(FilaVetor));
    f->fim = f->ini = 0;
    return f;
}

void insere_fila_v(FilaVetor* f, int v) {
    if (incr(f->fim) == f->ini) {
        printf("Capacidade da fila estourou.\n");   
        exit(1);    
    }
    // Insere elemento
    f->vet[f->fim] = v;
    f->fim = incr(f->fim);

}

int retira_fila_v(FilaVetor* f) {
    int v;
    if (vazia_fila_v(f)) {
        printf("Fila vazia\n");
        exit(1);
    }
    // Retira elemento
    v = f->vet[f->ini];
    f->ini = incr(f->ini);
    return v;
}

int vazia_fila_v(FilaVetor* f) {
    return (f->ini == f->fim);
}

void libera_fila_v(FilaVetor* f) {
    free(f);
}