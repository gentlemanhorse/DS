#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
    int n;
    float array[MAX];
} Stack;

typedef struct {
    int n;
    char array[MAX];
} CharStack;

Stack *create_stack();

CharStack *create_char_stack();

void push(Stack *s, float v);

void push_char(CharStack *s, char v);

float pop(Stack *s);

char pop_char(Stack *s);

int is_empty(Stack *s);

int char_is_empty(CharStack *s);

void free_stack(Stack *s);

void free_char_stack(CharStack *s);

int testa_mais_elementos(Stack *s1, Stack *s2);

void transferir_elementos(Stack *s1, Stack *s2, int *flagErro);

void inverter(Stack *s);

int iguais(Stack *s1, Stack *s2);



#endif