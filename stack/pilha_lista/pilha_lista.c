#include "pilha_lista.h"

PilhaFloat *cria_pilha_float(void) {
	PilhaFloat *p = (PilhaFloat *) malloc(sizeof(PilhaFloat));
	p->topo = NULL;
	return p;
}

PilhaChar *cria_pilha_char(void) {
	PilhaChar *p = (PilhaChar *) malloc(sizeof(PilhaChar));
	p->topo = NULL;
	return p;
}

NoFloat *insere_float(NoFloat *no, float v) {
	NoFloat *p = (NoFloat *) malloc(sizeof(NoFloat));
	p->valor = v;
	p->prox = no;
	return p;
}

NoChar *insere_char(NoChar *no, char v) {
	NoChar *p = (NoChar *) malloc(sizeof(NoChar));
	p->valor = v;
	p->prox = no;
	return p;
}

NoFloat *retira_float(NoFloat *no) {
	NoFloat *r = no->prox;
	free(no);
	return r;
}

NoChar *retira_char(NoChar *no) {
	NoChar *r = no->prox;
	free(no);
	return r; 
}

void push_float(PilhaFloat *p, float v) {
	p->topo = insere_float(p->topo, v);
}

void push_char(PilhaChar *p, char v) {
	p->topo = insere_char(p->topo, v);
}

float pop_float(PilhaFloat *p) {
	float v;
	if (vazia_float(p)) {
		printf("Pilha vazia \n");
		exit(1);
	}
	v = p->topo->valor;
	p->topo = retira_float(p->topo);
	return v;
}

char pop_char(PilhaChar *p) {
	char v;
	if (vazia_char(p)) {
		printf("Pilha vazia\n");
		exit(1);
	}
	v = p->topo->valor;
	p->topo = retira_char(p->topo);
	return v;
}

int vazia_float(PilhaFloat *p) {
	return (p->topo == NULL);
}

int vazia_char(PilhaChar *p) {
	return (p->topo == NULL);
}

void libera_float(PilhaFloat *p) {
	NoFloat *q = p->topo;
	while (q != NULL) {
		NoFloat *t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

void libera_char(PilhaChar *p) {
	NoChar *q = p->topo;
	while (q != NULL) {
		NoChar *t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}
