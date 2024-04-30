#include "fila_lista.h"

FilaLista *cria_fila_l(void) {
    FilaLista *f = (FilaLista *) malloc(sizeof(FilaLista));
    f->fim = f->ini = NULL;
    return f;
}

// Funcao auxiliar: insere no final
No *insere_fim(No* n, int v) {
    No *r = (No*) malloc(sizeof(No));
    r->info = v;
    r->prox = NULL;
    if (n != NULL)  // Verifica se a lista nao eh vazia
        n->prox = r;
    return r;
}

void insere_fila_l(FilaLista *f, int v) {
    f->fim = insere_fim(f->fim, v);
    if (vazia_fila_l(f)) {   // Caso a lista estivesse vazia
        f->ini = f->fim;
    }
}

// Funcao auxiliar: retira no inicio
No *retira_ini(No *n) {
    No *r = n->prox;
    free(n);
    return r;
}

int retira_fila_l(FilaLista *f) {
    int v;
    if(vazia_fila_l(f)) {
        printf("Erro, lista vazia.\n");
        exit(1);
    }
    v = f->ini->info;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL)     // Caso a lista fique vazia
        f->fim = NULL;
    return v;
}

int vazia_fila_l(FilaLista *f) {
    return (f->ini == NULL);
}

void libera_lista_l(FilaLista *f) {
    No *n = f->ini;
    while(n != NULL) {
        No *t = n->prox;
        free(n);
        n = t;
    }
    free(f);
}