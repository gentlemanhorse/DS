#include "fila_vetor.h"
#include "fila_lista.h"

void print_fila_l(FilaLista *f) {
    No *n = f->ini;
    int i = 0;
    while(n != NULL) {
        printf("Elemento %d == %d\n", i++, n->info);
        n = n->prox;
    }
}

void print_fila_v(FilaVetor *f) {
    if(f->ini < f->fim) 
        for (int i = f->ini; i < f->fim; i++) 
            printf("Elemento %d == %d\n", i, f->vet[i]);
    else {
        int n = f->fim + N;
        int j = f->ini;
        for (int i = f->ini; i < n; i++) {
            printf("Elemento %d == %d\n", i - f->ini, f->vet[j]);
            j++;
            if (j == N) {
                j = 0;
            }
        }
    } 
}

void fura_fila_l(FilaLista *f, int i) {
    No *n = (No *) malloc(sizeof(No));      // aloca um no
    n->info = i;                            
    if(vazia_fila_l(f))                     // Se a fila esta vazia fim recebe o mesmo valor do inicio
        f->fim = n;
    n->prox = f->ini;
    f->ini = n;                             // Atribui o no criado ao inicio 
}

void fura_fila_v(FilaVetor *f, int i) {
    if (f->ini == 0 && f->fim != N-1)  {
        f->ini = N-1;
        f->vet[f->ini] = i;
    }
    else if (f->ini - 1 != f->fim){
        f->ini = f->ini - 1;
        f->vet[f->ini] = i;
    }
    else {
        printf("Fila estourou a capacidade\n");
    }
}

int main(int argc, char *argv[]) {
    FilaVetor *fv = cria_fila_v();
    FilaLista *fl = cria_fila_l();

    // Inserindo elementos nas listas
    for (int i = 0; i < 32; i++) {
        insere_fila_l(fl, i * i);
        insere_fila_v(fv, i * 2);
    }

    printf("FILA COM LISTA:\n");
    print_fila_l(fl);
    printf("\n\nFILA COM VETOR:\n");
    print_fila_v(fv);


    fura_fila_l(fl, -12);
    fura_fila_v(fv, -14);

    printf("NOVA FILA COM LISTA:\n");
    print_fila_l(fl);
    printf("\n\nNOVA FILA COM VETOR:\n");
    print_fila_v(fv);


    return 0;
}