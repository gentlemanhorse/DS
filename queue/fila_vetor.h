#ifndef FILA_VETOR_H
#define FILA_VETOR_H
#include <stdio.h>
#include <stdlib.h>
#define N 100

struct fila_vetor {
    int ini, fim;
    int vet[N];
};

typedef struct fila_vetor FilaVetor;

int incr(int i);

FilaVetor* cria_fila_v(void);

void insere_fila_v(FilaVetor* f, int v);

int retira_fila_v(FilaVetor* f);

int vazia_fila_v(FilaVetor* f);

void libera_fila_v(FilaVetor* f);
#endif