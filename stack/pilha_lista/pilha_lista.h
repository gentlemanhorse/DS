#ifndef PILHA_LISTA_H
#define PILHA_LISTA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct no_float {
	float valor;
	struct no_float *prox;
} NoFloat;

typedef struct no_char {
	char valor;
	struct no_char *prox;
} NoChar;


typedef struct pilha_float {
	NoFloat *topo;
} PilhaFloat;

typedef struct pilha_char {
	NoChar *topo;
} PilhaChar;

PilhaFloat *cria_pilha_float(void);

PilhaChar *cria_pilha_char(void);

NoFloat *insere_float(NoFloat *no, float v);

NoChar *insere_char(NoChar *no, char v);

NoFloat *retira_float(NoFloat *no);

NoChar *retira_char(NoChar *no);

void push_float(PilhaFloat *p, float v);

void push_char(PilhaChar *p, char v);

float pop_float(PilhaFloat *p);

char pop_char(PilhaChar *p);

int vazia_float(PilhaFloat *p);

int vazia_char(PilhaChar *p);

void libera_float(PilhaFloat *p);

void libera_char(PilhaChar *p);
#endif
