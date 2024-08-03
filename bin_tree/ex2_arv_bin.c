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

int main(int argc, char *argv[]) {
    Arv* a = cria(1,
                cria(2,inicializa(),
                cria(5, inicializa(), inicializa())
                ),
                cria(2,
                cria(2, inicializa(), inicializa()),
                cria(1, inicializa(), inicializa())
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
    if(vazia(a))
        printf("\n---\nvazia\n----\n");
    imprime(a);
    printf("\nArvore tem %d folhas\n", folhas(a));
    return 0;
}