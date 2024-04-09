#include "lista_circular.h"

int main(int argc, char* argv[]) {
    ListaC *l1 = NULL;
    printf("Inserting values\n");
    for (int i = 0; i < 10; i++) {
        l1 = insere(l1, i+1);
    }
    printf("Lista inicial\n");
    print_lista(l1);
    printf("\nDividindo a lista\n");
    ListaC *l2 = separa(l1, 5);
    printf("Primeira metade\n");
    print_lista(l1);
    printf("\n\nSegunda metade\n");
    print_lista(l2);

    printf("\n\nConcatenando...\n");
    l1 = concatena(l1, l2);
    printf("Lista concatenada\n");
    print_lista(l1);
    printf("\n\ncriando lista a partir do vetor\n");
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l1 = NULL;
    l1 = constroi(10, v);
    printf("Lista construida a partir do vetor\n");
    print_lista(l1);
    printf("\n\nRetirando prefixo\n");
    l1 = retira_prefixo(l1, 5);
    print_lista(l1);
    printf("EoF\n");
    free(l1);
    free(l2);
    return 0;
}