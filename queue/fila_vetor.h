#ifndef FILA_VETOR_H
#define FILA_VETOR_H
struct fila_vetor {
    void *primeiro;
};

typedef struct fila_vetor FilaVetor;

FilaVetor* cria_fila_v(void);

void insere_fila_v(FilaVetor* f, float v);

float retira_fila_v(FilaVetor* f);

int vazia_fila_v(FilaVetor* f);

void libera_fila_v(FilaVetor* f);
#endif