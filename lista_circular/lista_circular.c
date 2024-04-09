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
	novo = cria(valor);
	if (tamanho_lista(l) == 0) {
		novo->ant = novo->prox = novo;
	}
	else {
		ListaC *ult = l->ant;
		novo->prox = l;
		l->ant = novo;
		novo->ant = ult;
		ult->prox = novo;
	} 
	return novo;
}

ListaC *remover(ListaC *l, int valor) {

	return l;
}

void print_lista(ListaC *l) {
	ListaC *t = l;
	int i = 1;
	do {
		printf("elemento n %d == %d\n", i++, t->valor);
		t = t->prox;
	} while (t != l);
}

ListaC *separa(ListaC *l, int v) {
	ListaC *ret = l;
	ListaC *ult = l->ant;
	while (ret->valor != v) {
		ret = ret->prox;
	}
	l->ant = ret->ant;
	l->ant->prox = l;
	ret->ant = ult;
	ult->prox = ret;

	return ret;
}

ListaC *concatena(ListaC *l1, ListaC *l2) {
	ListaC *ult = l2->ant;
	l1->ant->prox = l2;
	l2->ant = l1->ant;
	l1->ant = ult;
	ult->prox = l1;
	return l1;
}

ListaC *constroi(int n, int *v) {
	ListaC *l = NULL;
	for(int i = 0; i < n; i++) {
		l = insere(l, v[n - i - 1]);
	}
	return l;
}

ListaC *retira_prefixo(ListaC *l, int n) {
	ListaC *t = l;
	do {
		t = t->prox;	
	} while (t != l && t->valor != n);
	if (t != l) {
		printf("Entered the if\n");
		t->ant = l->ant;
		t->ant->prox = t;
		l = t;
	}
	return l;
}

