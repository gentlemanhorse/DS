#include "lista.h"

Lista *insere(Lista *l, int valor) {
	Lista *nova = (Lista *) malloc(sizeof(Lista));
	nova->valor = valor;
	nova->prox = l;
	
	return nova;
}

void print_lista(Lista *l) {
	int idx = 0;
	Lista *t = l;
	do {
		t = t->prox;
		printf("item n %d valor = %d\n", idx++, l->valor);
	} while (t != NULL);
}

Lista *separa(Lista *l, int valor) {
	Lista *t = l;
	Lista *ant = NULL;
	while (t->prox != NULL && t->valor != valor) {
		ant = t;
		t = t->prox;
	}
	if (t->prox == NULL) 
		return NULL;
	if (t->valor == valor) {
		ant->prox = NULL;
		return t;
	
	}
}
