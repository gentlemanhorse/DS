#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* separa(Lista* l, int n){
	Lista* temp = l;
	Lista* ant = NULL;
	while(temp->prox != NULL && temp->valor != n){
		ant = temp;
		temp = temp->prox;
	}
	if(temp->valor == n){
		
	}
	
}

Lista* concatena(Lista* l1, Lista* l2);

Lista* constroi(int n, int *v);

Lista* retira_prefixo(Lista* l, int n); 

Lista* insere(Lista* l, int valor){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->prox = l;
    novo->valor = valor;

    return novo;	
}

int main(int argc, char* argv[]){
	
}
