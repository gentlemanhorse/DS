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
    printf("%d valor = %f\n", s->n, v);
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
    free(s);
}

int testa_mais_elementos(Stack *s1, Stack *s2) {
    return (s1->n > s2->n);
}

void transferir_elementos(Stack *s1, Stack *s2);

void inverter(Stack *s) {
    Stack *t = create_stack();
    while(!is_empty(s)) {
        push(t, pop(s));
    }
    free_stack(s);
    s = t;

}

int iguais(Stack *s1, Stack *s2);