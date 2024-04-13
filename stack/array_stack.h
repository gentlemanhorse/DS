#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
    int n;
    float array[MAX];
} Stack;

Stack *create_stack();

void push(Stack *s, float v);

float pop(Stack *s);

int is_empty(Stack *s);

void free_stack(Stack *s);

int testa_mais_elementos(Stack *s1, Stack *s2);

void transferir_elementos(Stack *s1, Stack *s2);

void inverter(Stack *s);

int iguais(Stack *s1, Stack *s2);



#endif