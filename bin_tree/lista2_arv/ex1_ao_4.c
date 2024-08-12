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

int busca (Arv* a, char c){
    if (vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->inf==c || busca(a->sae,c) || busca(a->sad,c);
}

// ex. 1
int altura(Arv *a) {
    if (vazia(a)) {
        return -1;
    } 
    else {
        int altura_sae = altura(a->sae);
        int altura_sad = altura(a->sad);
        if (altura_sae > altura_sad) {
            return altura_sae + 1;
        } else {
            return altura_sad + 1;
        }
    }
}

// ex. 2
int nos (Arv *a) {
    if (vazia(a)) {
        return 0;
    }
    else {
        int ne = nos(a->sae);
        int nd = nos(a->sad);
        return nd + ne + 1;
    }
}

// ex. 3
Arv* excluir_folhas(Arv *a) {
    if (vazia(a)) {
        return NULL;
    }
    
    // Se o nó é uma folha, remove
    if (vazia(a->sae) && vazia(a->sad)) {
        free(a);
        return NULL;
    }

    // Caso contrário, percorre as subárvores esquerda e direita
    a->sae = excluir_folhas(a->sae);
    a->sad = excluir_folhas(a->sad);
    
    return a;
}


// ex. 4
int cheia(Arv *a) {
    // Se a árvore é vazia, ela é considerada cheia
    if (vazia(a)) {
        return 1;
    }

    // Se o nó é uma folha, ele está corretamente preenchido
    if (vazia(a->sae) && vazia(a->sad)) {
        return 1;
    }

    // Se o nó tem exatamente dois filhos, verificamos se as subárvores são cheias
    if (!vazia(a->sae) && !vazia(a->sad)) {
        return cheia(a->sae) && cheia(a->sad);
    }

    // Se o nó tem apenas um filho, a árvore não é cheia
    return 0;
}


// ex .5
void pre_ord_pilha(Arv *a) {

}

// ex. 6
void in_ord_pilha(Arv *a) {

}

// ex. 7


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
    

    Arv* b = cria(1, inicializa(), inicializa());
    
    Arv* c = inicializa();
 

    // Impressão das árvores
    imprime(a);
    printf("\n");
    imprime(b);
    printf("\n");

    printf("------------ EX 1 ---------------\n\n");
    printf("A arvore a tem altura %d\n", altura(a));

    printf("A arvore b tem altura %d\n", altura(b));

    printf("A arvore c tem altura %d\n", altura(c));

    printf("\n------------ EX 2 ---------------\n\n");
    printf("A arvore a tem %d nos\n", nos(a));
    printf("A arvore b tem %d nos\n", nos(b));
    printf("A arvore c tem %d nos\n", nos(c));

    
    printf("\n------------ EX 3 ---------------\n\n");
    a = excluir_folhas(a);
    b = excluir_folhas(b);
    c = excluir_folhas(c);

    // Impressão das árvores
    imprime(a);
    printf("\n");
    imprime(b);
    printf("\n");


    libera(a);
    libera(b);

    return 0;
}