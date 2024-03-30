#include <lista.h>

Lista *insere(Lista *l, int valor) {
	Lista *nova = (Lista *) malloc(sizeof(Lista));
	nova->prox = l;
	nova->valor = valor;
	
	return nova;
}

void print_lista(Lista *l) {
	int idx = 0;
	Lista *t = l;
	do {
		printf("item n %d valor = %d\n", idx++, l->valor);
	} while (t->prox != NULL);
}

Lista *separa(Lista *l, int valor) {
	Lista *t = l;
	Lista *ant = NULL;
	while (t->prox != && t->valor != valor) {
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
