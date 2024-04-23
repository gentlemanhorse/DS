#ifndef PILHA_VETOR_H
#define PILHA_VETOR_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
    int n;
    float vetor[MAX];
} PilhaFloat;

typedef struct {
    int n;
    char vetor[MAX];
} PilhaChar;

PilhaFloat *cria_pilha_float();

PilhaChar *cria_pilha_char();

void push_float(PilhaFloat *p, float v);

void push_char(PilhaChar *p, char v);

float pop_float(PilhaFloat *p);

char pop_char(PilhaChar *p);

int float_is_empty(PilhaFloat *p);

int char_is_empty(PilhaChar *p);

void free_pilha_float(PilhaFloat *p);

void free_pilha_char(PilhaChar *p);

void print_pilha(PilhaFloat *p); 

#endif