#ifndef FILA_LISTA_H
#define FILA_LISTA_H
#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no* prox;
};
typedef struct no No;

struct fila_lista {
    No *ini;
    No *fim;
};
typedef struct fila_lista FilaLista;

FilaLista *cria_fila_l(void);

No *insere_fim(No* n, int v);

void insere_fila_l(FilaLista *f, int v);

No *retira_ini(No *n);

int retira_fila_l(FilaLista *f);

int vazia_fila_l(FilaLista *f);

void libera_lista_l(FilaLista *f);

#endif