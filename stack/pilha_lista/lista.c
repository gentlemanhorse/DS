#include "lista.h"

Lista *insere(Lista *l, int valor){
    	Lista *novo = (Lista *) malloc(sizeof(Lista));
    	novo->prox = l;
	novo->valor = valor;

   	return novo;	
}

void print_lista(Lista *l){
	Lista *t = l;
	if (t == NULL) 
		printf("Lista vazia\n");
	for (int i = 0; t != NULL; i++) {
		printf("%dth valor: %d\n", (i + 1), t->valor);
		t = t->prox;
	}
}

Lista *separa(Lista *l, int n){
	Lista *temp = l;
	Lista *ant = NULL;
	while (temp->prox != NULL && temp->valor != n) {
		ant = temp;
		temp = temp->prox;
	}

	if (temp->prox == NULL) 
		return NULL;

	if (temp->valor == n || ant == NULL) {
		ant = temp;
		temp = temp->prox;
		ant->prox = NULL;
		return temp;
	}
}

Lista *concatena(Lista *l1, Lista *l2) {
	Lista *temp = l1;
	while(temp->prox != NULL)
		temp = temp->prox;
	
	temp->prox = l2;

	return l1;
}

Lista *constroi(int n, int *v) {
	Lista *l = NULL;
	if (n == 0) 
		return NULL;
	for (int i = 0; i < n; i++) {
		l = insere(l, v[n - i - 1]);
	}
	return l;
}

Lista *retira_prefixo(Lista *l, int n) {
	Lista *t = l;
	Lista *ant = NULL;

	for(int i = 0; i < n && t != NULL; i++) {
		ant = t;
		t = t->prox;
		free(ant);
	}
	
	return t;
} 

