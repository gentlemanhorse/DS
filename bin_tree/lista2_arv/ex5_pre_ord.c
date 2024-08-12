#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int inf;
    struct arv *sad;
    struct arv *sae;
} Arv;


typedef struct pilha {
    Arv* no;
    struct pilha* prox;
} Pilha;


Arv* cria(int inf, Arv* sae, Arv* sad) {
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->inf = inf;
    a->sae = sae;
    a->sad = sad;
    return a;
}


Pilha* push(Pilha* p, Arv* no) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->no = no;
    novo->prox = p;
    return novo;
}


Pilha* pop(Pilha* p, Arv** no) {
    Pilha* t = p;
    *no = t->no;
    p = t->prox;
    free(t);
    return p;
}


int pilha_vazia(Pilha* p) {
    return p == NULL;
}


void pre_ordem(Arv* a) {
    Pilha* p = NULL;
    Arv* atual = a;

    if (a == NULL) return;

    p = push(p, atual);

    while (!pilha_vazia(p)) {
        p = pop(p, &atual);
        printf("%d ", atual->inf);

        
    
        if (atual->sad != NULL) {
            p = push(p, atual->sad);
        }
        if (atual->sae != NULL) {
            p = push(p, atual->sae);
        }
    }
}
int main() {
    Arv* a = cria(1,
                  cria(2, cria(4, NULL, NULL), cria(5, NULL, NULL)),
                  cria(3, cria(6, NULL, NULL), cria(7, NULL, NULL)));

    

    printf("Percurso em pre-ordem: ");
    pre_ordem(a);
    printf("\n");

    

    free(a);

    return 0;
}
