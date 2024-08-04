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

int ocorrencias(Arv* a, int x) {
    if (vazia(a)) 
        return 0;

    int n = 0;
    if(x == a->inf) 
        n++;
    
    n = n + ocorrencias(a->sae, x);
    n = n + ocorrencias(a->sad, x);
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
    printf("\nContendo %d ocorrencias do numero 1\n", ocorrencias(a, 1));
    printf("\nContendo %d ocorrencias do numero 2\n", ocorrencias(a, 2));
    printf("\nContendo %d ocorrencias do numero 3\n", ocorrencias(a, 3));
    libera(a);
    return 0;
}