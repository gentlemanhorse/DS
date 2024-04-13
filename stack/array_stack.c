#include "array_stack.h"

Stack *create_stack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->n = 0;
    return s; 
}

void push(Stack *s, float v) {
    if (s->n == MAX) {
        printf("Pilha atingiu a capacidade máxima\n");
        exit(1);
    }
    s->array[s->n++] = v;
}

float pop(Stack *s) {
    if (is_empty(s)) {
        printf("Pilha vazia");
        exit(1);
    }
    float v = s->array[s->n - 1];
    s->n--;
    return v;
}

int is_empty(Stack *s) {
    return (s->n == 0);
}

void free_stack(Stack *s) {
    free(p);
}

int testa_mais_elementos(Stack *s1, Stack *s2) {

}

void transferir_elementos(Stack *s1, Stack *s2);

void inverter(Stack *s);

int iguais(Stack *s1, Stack *s2);