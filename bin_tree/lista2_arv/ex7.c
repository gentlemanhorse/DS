#include <stdio.h>
#include <stdlib.h>


typedef struct arv {
    int inf;
    struct arv *sad;
    struct arv *sae;
} Arv;


Arv* cria(int inf, Arv* sae, Arv* sad) {
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->inf = inf;
    a->sae = sae;
    a->sad = sad;
    return a;
}


int vazia(Arv* a) {
    return a == NULL;
}


Arv* espelha(Arv* a) {
    if (vazia(a)) {
        return NULL;
    }

    
    Arv* sae_espelho = espelha(a->sae);
    Arv* sad_espelho = espelha(a->sad);

    
    a->sae = sad_espelho;
    a->sad = sae_espelho;

    return a;
}


void imprime_pre_ordem(Arv* a) {
    if (!vazia(a)) {
        printf("%d ", a->inf);
        imprime_pre_ordem(a->sae);
        imprime_pre_ordem(a->sad);
    }
}


int main() {
    Arv* a = cria(1,
                  cria(2, cria(4, NULL, NULL), cria(5, NULL, NULL)),
                  cria(3, cria(6, NULL, NULL), cria(7, NULL, NULL)));

    
    printf("Árvore original (pre-ordem): ");
    imprime_pre_ordem(a);
    printf("\n");

    
    espelha(a);

    
    printf("Árvore espelhada (pre-ordem): ");
    imprime_pre_ordem(a);
    printf("\n");

    
    free(a);

    return 0;
}
