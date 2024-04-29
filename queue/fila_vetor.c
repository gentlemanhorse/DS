#include "fila_vetor.h"

int incr(int i) {
 return (i+1)%N;
}

FilaVetor* cria_fila_v(void) {
    FilaVetor *f = (FilaVetor *) malloc(sizeof(FilaVetor));
    f->fim = f->ini = 0;
    return f;
}

void insere_fila_v(FilaVetor* f, float v) {
    if (incr(f->fim) == f->ini) {
        printf("Capacidade da fila estourou.\n");   
        exit(1);    
    }
    // Insere elemento
    f->vet[f->fim] = v;
    f->fim = incr(f->fim);

}

float retira_fila_v(FilaVetor* f) {
    float v;
    if (vazia_fila_v(f)) {
        printf("Fila vazia\n");
        exxit(1);
    }
    
}

int vazia_fila_v(FilaVetor* f);

void libera_fila_v(FilaVetor* f);