#ifndef LIST_STACK_H
#define LIST_STACK_H
#include "lista.h"

struct pilhaL {
	Lista *topo;
};

typedef struct pilhaL PilhaL;

PilhaL *cria_PilhaL(void);

Lista *insere_PilhaL(Lista *l, int v);

Lista *retira_ini(Lista *l);

void push(PilhaL *p, int v);

int pop(PilhaL *p);

int vazia(PilhaL *p);

void libera(PilhaL *p);
#endif
