#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int inf;
    struct arv *sad;
    struct arv *sae;
} Arv;

Arv* inicializa(void) {
    return NULL;
}

Arv* cria(int inf, Arv *sae, Arv *sad) {
    Arv *a = (Arv *)malloc(sizeof(Arv));
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
    } else {
        printf("<%d", a->inf);
        imprime(a->sae);
        imprime(a->sad);
        printf(">");
    }
}

Arv* libera(Arv *a) {
    if (!vazia(a)) {
        libera(a->sae);
        libera(a->sad);
        free(a);
    }
    return NULL;
}

char raiz_post_ordem(const char* post_order) {

    int i = 0;
    while (post_order[i] != '\0') {
        i++;
    }
    return post_order[i - 1];
}

char raiz_pre_ordem(const char* pre_order) {

    return pre_order[0];
}

char raiz_in_ordem(const char* in_order, char pre_order_root) {

    for (int i = 0; in_order[i] != '\0'; i++) {
        if (in_order[i] == pre_order_root) {
            return in_order[i];
        }
    }
    return '\0';
}

int main() {
    const char* post_order = "FCBDG";
    const char* pre_order = "IBCDFEN";
    const char* in_order = "CBIDFGE";


    char raiz_post = raiz_post_ordem(post_order);
    char raiz_pre = raiz_pre_ordem(pre_order);
    char raiz_in = raiz_in_ordem(in_order, raiz_pre);


    printf("Raiz da árvore com percurso pós-ordem (%s): %c\n", post_order, raiz_post);
    printf("Raiz da árvore com percurso pré-ordem (%s): %c\n", pre_order, raiz_pre);
    printf("Raiz da árvore com percurso in-ordem (%s): %c\n", in_order, raiz_in);

    return 0;
}
