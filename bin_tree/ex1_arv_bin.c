#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    char inf;
    struct arv * sad;
    struct arv * sae;
}Arv;

Arv *inicializa(void) {
    return NULL;
}

Arv *cria(char inf, Arv  *sae, Arv *sad) {
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
        printf("<%c", a->inf);
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

int main(int argc, char *argv[]) {
    Arv* a = cria('a',
                cria('b',inicializa(),
                cria('d', inicializa(), inicializa())
                ),
                cria('c',
                cria('e', inicializa(), inicializa()),
                cria('f', inicializa(), inicializa())
        )
    );
    imprime(a);
    printf("\nArvore tem %d folhas\n", folhas(a));
    libera(a);

    a = cria('a',
                cria('b',inicializa(),
                cria('d', inicializa(), inicializa())
                ),
                cria('c',
                inicializa(),
                cria('f', inicializa(), inicializa())
        )
    );
    
    imprime(a);
    printf("\nArvore tem %d folhas\n", folhas(a));
    libera(a);
    return 0;
}