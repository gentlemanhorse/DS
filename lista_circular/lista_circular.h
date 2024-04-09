#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <stdio.h>
#include <stdlib.h>

struct lista_circular {
	int valor;
	struct lista_circular *ant;
	struct lista_circular *prox;
};
typedef struct lista_circular ListaC;

ListaC *insere(ListaC *l, int valor);

ListaC *remover(ListaC *l, int valor);

void print_lista(ListaC *l);

ListaC *separa(ListaC *l, int v);

ListaC *concatena(ListaC *l1, ListaC *l2);

ListaC *constroi(int n, int *v);

ListaC *retira_prefixo(ListaC *l, int n);
#endif
