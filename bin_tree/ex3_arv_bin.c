#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int inf;
    struct arv * sad;
    struct arv * sae;
}Arv;

Arv *inicializa(void) {
    return NULL;
}

Arv *cria(int inf, Arv  *sae, Arv *sad) {
    Arv *a = (Arv *) malloc(sizeof(Arv));
    a->inf = inf;
    a->sae = sae;
    a->sad = sad;
    return a;
}

int vazia(Arv *a) {
    return a == NULL;
}

void imprime(Arv *a) {
    if (vazia(a)) {
        printf("<>");
    }
    else {
        printf("<%d", a->inf);
        imprime(a->sae);
        imprime(a->sad);
        printf(">");
    }
}

Arv *libera(Arv *a) {
    if (!vazia(a)) {
        libera(a->sae);
        libera(a->sad);
        free(a);
    }
    return NULL;
}

int folhas(Arv *a) {
    if (vazia(a)) {
        return 0;
    }
    int n = 1;
    n = n + folhas(a->sae);
    n = n + folhas(a->sad);
    return n;
}

int igual(Arv *a, Arv *b) {
    if (vazia(a) && vazia(b)) {
        return 1;
    }
    if (vazia(a) || vazia(b)) {
        return 0;
    }
    if (a->inf != b->inf) {
        return 0;
    }
    return igual(a->sae, b->sae) && igual(a->sad, b->sad);
}

int main() {
    Arv* a = cria(1,
                    cria(2, inicializa(),
                    cria(5, inicializa(), inicializa())
                    ),
                    cria(2,
                    cria(2, inicializa(), inicializa()),
                    cria(1, inicializa(), inicializa())
            )
        );

    Arv* b = cria(1,
                    cria(2, inicializa(),
                    cria(4, inicializa(), inicializa()) 
                    ),
                    cria(2,
                    cria(2, inicializa(), inicializa()),
                    cria(1, inicializa(), inicializa())
            )
        );

    // Impressão das árvores
    imprime(a);
    printf("\n");
    imprime(b);
    printf("\n");

    if (igual(a, b)) {
        printf("As arvores a e b sao iguais\n");
    } else {
        printf("As arvores a e b nao sao iguais\n");
    }
    libera(a);
    libera(b);

    return 0;
}