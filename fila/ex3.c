#include <stdio.h>
#include <stdlib.h>
#define N 100       // Numero maximo de elementos na lista
#define MAX 80      // Tamanho maximo da descricao dos processos
int id = 0;

// Estrutura do processo
struct processo {
    int id;
    char *desc;
};
typedef struct processo Processo;

// No da fila com lista
struct no {
    Processo p;
    struct no *prox;
};
typedef struct no No;

// Estrutura da fila com vetor
struct fila_vetor {
    int ini, fim;
    Processo proc[N];
};
typedef struct fila_vetor FilaVetor;

// Estrutura da fila com lista
struct fila_lista {
    No *ini;
    No *fim;
};
typedef struct fila_lista FilaLista;

FilaLista *cria_fila_l(void);

No *insere_fim(No* n, Processo p);

void insere_fila_l(FilaLista *f, Processo p);

No *retira_ini(No *n);

Processo retira_fila_l(FilaLista *f);

int vazia_fila_l(FilaLista *f);

void libera_fila_l(FilaLista *f);

int incr(int i);

FilaVetor *cria_fila_v(void);

void insere_fila_v(FilaVetor *f, Processo p);

Processo retira_fila_v(FilaVetor *f);

int vazia_fila_v(FilaVetor *f);

void libera_fila_v(FilaVetor *f);

Processo registra_processo(void);

void  clear_buffer(void);

void listar_processos_v(FilaVetor *f);

void listar_processos_l(FilaLista *l);

int main() {
    FilaVetor *fv = cria_fila_v();
    FilaLista *fl = cria_fila_l();

    int op = 0;
    do {
        // Menu de opcoes
        printf("Escolha uma operacao\n");
        printf("0) Encerrar\n1) Incluir novo processo\n2) Retirar processo\n3) Imprimir Processos\n");
        scanf("%d", &op);
        clear_buffer();
        switch (op) {
            case 0:
                printf("\n\nEncerrando...\n");
                break;
            case 1:     // Registra um novo processo
                Processo p = registra_processo();
                insere_fila_l(fl, p);
                insere_fila_v(fv, p);
                break;
            case 2:     // Remove o primeiro processo das filas
                Processo pfl = retira_fila_l(fl);
                Processo pfv = retira_fila_v(fv);
                printf("Processo de id = %d\ndescricao = %s\nremovido com sucesso!\n\n", pfl.id, pfl.desc);
                free(pfl.desc);
                break;
            case 3:     // Lista os processos. Como as duas filas estão armazenando os mesmos processo, o resultado imprimido deve ser o mesmo
                printf("Processos na fila com vetor: \n");
                listar_processos_v(fv);
                printf("Processos na fila com lista: \n");
                listar_processos_l(fl);
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (op != 0);
    libera_fila_v(fv);
    libera_fila_l(fl);
    printf("EoF\n");

    return 0;    
}


// Funcoes basicas da fila com lista
FilaLista *cria_fila_l(void) {
    FilaLista *f = (FilaLista *) malloc(sizeof(FilaLista));
    f->fim = f->ini = NULL;
    return f;
}

// Funcao auxiliar: insere no final
No *insere_fim(No* n, Processo p) {
    No *r = (No*) malloc(sizeof(No));
    r->p = p;
    r->prox = NULL;
    if (n != NULL)  // Verifica se a lista nao eh vazia
        n->prox = r;
    return r;
}

void insere_fila_l(FilaLista *f, Processo p) {
    f->fim = insere_fim(f->fim, p);
    if (vazia_fila_l(f)) {   // Caso a lista estivesse vazia
        f->ini = f->fim;
    }
}

// Funcao auxiliar: retira no inicio
No *retira_ini(No *n) {
    No *r = n->prox;
    free(n);
    return r;
}

Processo retira_fila_l(FilaLista *f) {
    Processo p;
    if(vazia_fila_l(f)) {
        printf("Erro, lista vazia.\n");
        exit(1);
    }
    p = f->ini->p;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL)     // Caso a lista fique vazia
        f->fim = NULL;
    return p;
}

int vazia_fila_l(FilaLista *f) {
    return (f->ini == NULL);
}

void libera_fila_l(FilaLista *f) {
    No *n = f->ini;
    while(n != NULL) {
        No *t = n->prox;
        free(n->p.desc);
        free(n);
        n = t;
    }
    free(f);
}

// Funcoes basicas da fila com vetor
int incr(int i) {
    return (i+1)%N;
}

FilaVetor* cria_fila_v(void) {
    FilaVetor *f = (FilaVetor *) malloc(sizeof(FilaVetor));
    f->fim = f->ini = 0;
    return f;
}

void insere_fila_v(FilaVetor* f, Processo p) {
    if (incr(f->fim) == f->ini) {
        printf("Capacidade da fila estourou.\n");   
        exit(1);    
    }
    // Insere elemento
    f->proc[f->fim] = p;
    f->fim = incr(f->fim);

}

Processo retira_fila_v(FilaVetor* f) {
    Processo p;
    if (vazia_fila_v(f)) {
        printf("Fila vazia\n");
        exit(1);
    }
    // Retira elemento
    p = f->proc[f->ini];
    f->ini = incr(f->ini);
    return p;
}

int vazia_fila_v(FilaVetor* f) {
    return (f->ini == f->fim);
}

void libera_fila_v(FilaVetor* f) {
    free(f);        // Liberando o array
}

// Funcao para registrar processo 
Processo registra_processo(void) {
    Processo p;
    p.id = id++;
    p.desc = (char *) malloc(sizeof(char) * 50);
    printf("Descricao do processo: ");
    fgets(p.desc, MAX, stdin);
    if (p.desc == NULL) 
        printf("Error.");
    printf("\n\nProcesso: %s\n", p.desc);
    return p;
}

// Funcao para limpar o buffer
void clear_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF); //le os chars até um newline ou EOF
}
// Funcao para listar os processos na fila com vetor
void listar_processos_v(FilaVetor *f) {
    if(f->ini < f->fim) 
        for (int i = f->ini; i < f->fim; i++) 
            printf("Processo: %d \nDescricao: %s\n\n", f->proc[i].id, f->proc[i].desc);
    else {
        int n = f->fim + N;
        for (int i = f->ini; i < n; i++) {
            printf("Processo: %d \nDescricao: %s\n\n", f->proc[i].id, f->proc[i].desc);
        }
    }    
}
// Funcao para listar os processos na fila com lista
void listar_processos_l(FilaLista *f) {
    No *n = f->ini;
    while(n != NULL) {
        printf("Processo: %d\nDescricao: %s\n\n", n->p.id, n->p.desc);
        n = n->prox;
    }
}
