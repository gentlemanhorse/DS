#ifndef lISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct lista *prox;
};

typedef struct lista Lista;

Lista *insere(Lista *l, int valor);

void print_lista(Lista *l);

Lista *separa(Lista *l, int n);

Lista *concatena(Lista *l1, Lista *l2);

Lista *constroi(int n, int *v);

Lista *retira_prefixo(Lista *l, int n);

#endif
