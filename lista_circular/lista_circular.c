#include "lista_circular.h"

ListaC* cria(int v) {
	ListaC* p = (ListaC*) malloc(sizeof(ListaC));
	p->valor = v;
	p->prox = p;
	p->ant = p;
	return p;
}

int tamanho_lista(ListaC* l) {
	if (l == NULL) {
		return 0;
	}
	int len = 1;
	ListaC *temp = l;
	temp = temp->prox;
	while (temp != l) {
		temp = temp->prox;
		len++;
	}
	return len;
}

ListaC *insere(ListaC *l, int valor) {
	ListaC *novo;
	int len = tamanho_lista(l);
	switch (len) {
		case 0:
			break;
		case 1:
			break;
		default:
			break;
	} 
	return novo;
}

//ListaC *remove(ListaC *l, int valor) {

//	return l;
//}

void print_lista(ListaC *l) {}

ListaC *separa(ListaC *l, int v) {

	return l;
}

ListaC *concatena(ListaC *l1, ListaC *l2) {

	return l1;
}

ListaC *constroi(int n, int *v) {

	return cria(n);
}

ListaC *retira_prefixo(ListaC *l, int n) {
	return l;
}

