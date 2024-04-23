#include "pilha_lista.h"

PilhaL *cria_PilhaL(void) {
	PilhaL *p = (PilhaL *) malloc(sizeof(PilhaL));
	p->topo = NULL;
	return p;
}

Lista *insere_PilhaL(Lista *l, int v) {
	l = insere(l, v);
	return l;
}

Lista *retira_ini(Lista *l) {
	Lista *r = l->prox;
	free(l);
	return r;
}

void push(PilhaL *p, int v) {
	p->topo = insere_PilhaL(p->topo, v);
}

int pop(PilhaL *p) {
	int v;
	if (vazia(p)) {
		printf("Pilha vazia \n");
		exit(1);
	}
	v = p->topo->valor;
	p->topo = retira_ini(p->topo);
	return v;
}

int vazia(PilhaL *p) {
	return (p->topo == NULL);
}

void libera(PilhaL *p) {
	Lista *q = p->topo;
	while (q != NULL) {
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}
