#include "fila_vetor.h"
#include "fila_lista.h"

int lista_v_size(FilaVetor *f) { 
    if (f->fim < f->ini) // retorna os a quantidade de valores na lista
        return f->fim - f->ini + N;
    return f->fim - f->ini;
}

int lista_l_size(FilaLista *f) {
    int i = 0;
    No *t = f->ini;
    while (t != NULL) { // Incrementa o contador enquanto a lista não está vazia
        i++;
        t = t->prox;
    }
    return i;
}

int main(int argc, char *argv[]) {
    FilaVetor *f = cria_fila_v();
    FilaLista *fl = cria_fila_l();
    for (int i = 0; i < 99; i++) { 
        insere_fila_v(f, i);
        insere_fila_l(fl, i);
    }

    
    printf("\nTamanho da fila com vetor= %d\n", lista_v_size(f));
    printf("\nTamanho da fila com lista = %d\n", lista_l_size(fl));
    for (int i = 0; i < 10; i++) {
        retira_fila_v(f);
        retira_fila_l(fl);   
    }

    
    printf("\nTamanho da fila com vetor= %d\n", lista_v_size(f));
    printf("\nTamanho da fila com lista = %d\n", lista_l_size(fl));

    for (int i = 0; i < 5; i++) {
        insere_fila_v(f, i);
        insere_fila_l(fl, i);
    }
    printf("\nTamanho da fila com vetor= %d\n", lista_v_size(f));
    printf("\nTamanho da fila com lista = %d\n", lista_l_size(fl));
    return 0;
}