#include "pilha_vetor.h"

PilhaFloat *cria_pilha_float() {
    PilhaFloat *p = (PilhaFloat *) malloc(sizeof(PilhaFloat));
    p->n = 0;
    return p; 
}

PilhaChar *cria_pilha_char() {
    PilhaChar *p = (PilhaChar *) malloc(sizeof(PilhaChar));
    p->n = 0;
    return p;
}

void push_float(PilhaFloat *p, float v) {
    if (p->n == MAX) { 
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
 
    p->vetor[p->n] = v;
    p->n++;
}

void push_char(PilhaChar *p, char v) {
    if (p->n == MAX) { 
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
 
    p->vetor[p->n] = v;
    p->n++;
}

float pop_float(PilhaFloat *p) {
    if (float_is_empty(p)) {
        printf("Pilha vazia");
        exit(1);
    }
    float v = p->vetor[p->n - 1];
    p->n--;
    return v;
}

char pop_char(PilhaChar *p) {
    if (char_is_empty(p)) {
        printf("Pilha vazia");
        exit(1);
    }
    char v = p->vetor[p->n - 1];
    p->n--;
    return v;
}

int float_is_empty(PilhaFloat *p) {
    return (p->n == 0);
}

int char_is_empty(PilhaChar *p) {
    return (p->n == 0);
}

void free_pilha_float(PilhaFloat *p) {
    free(p);
}

void free_pilha_char(PilhaChar *p) {
    free(p);
}

void print_pilha(PilhaFloat *p) {
    int i;
    for (i=p->n-1; i>=0; i--)
        printf("%f\n",p->vetor[i]);
}

