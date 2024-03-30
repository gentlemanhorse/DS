#ifndef lISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;;
	struct lista *prox;
};

typedef struct lista Lista;

Lista *insere(Lista *l, int valor);

void print_lista(Lista *l);

Lista *separa(Lista *l, int valor);

#endif
