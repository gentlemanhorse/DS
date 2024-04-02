#include "lista.h"

Lista *insere(Lista *l, int valor){
    	Lista *novo = (Lista *) malloc(sizeof(Lista));
    	novo->prox = l;
	novo->valor = valor;

   	return novo;	
}

void print_lista(Lista *l){
	Lista *t = l;
	for (int i = 0; t != NULL; i++) {
		printf("%dth valor: %d\n", (i + 1), t->valor);
		t = t->prox;
	}
}

Lista *separa(Lista *l, int n){
	Lista *temp = l;
	Lista *ant = NULL;
	while (temp->prox != NULL && temp->valor != n) {
		ant = temp;
		temp = temp->prox;
	}

	if (temp->prox == NULL) 
		return NULL;

	if (temp->valor == n || ant == NULL) {
		ant = temp;
		temp = temp->prox;
		ant->prox = NULL;
		return temp;
	}
}

Lista *concatena(Lista *l1, Lista *l2) {
	Lista *temp = l1;
	while(temp->prox != NULL)
		temp = temp->prox;
	
	temp->prox = l2;

	return l1;
}

Lista *constroi(int n, int *v) {
	Lista *l = NULL;
	printf("%d\n", v[n-1]);	
	if (n == 0) 
		return NULL;
	for (int i = 0; i < n; i++) {
		printf("%d valor == %d\n", n - i, v[n - i - 1]);
		l = insere(l, v[n - i - 1]);
	}
	printf("\n\n\n");
	return l;
}

Lista *retira_prefixo(Lista *l, int n) {
	Lista *t = l;
	Lista *ant = NULL;

	for(int i = 0; i < n && t != NULL; i++) {
		ant = t;
		t = t->prox;
		free(ant);
	}
	
	return t;
} 
/*
int main(int argc, char *argv[]){
	Lista *l1 = NULL;
	Lista *l2 = NULL;
	int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	l1 = constroi(10, vetor);

	//print_lista(l1);
	
	//for (int i = 0; i < 10; i++){
	//	l1 = insere(l1, i);
	//	printf("%i\n", l1->valor);
	//}

	print_lista(l1);
	l1 = retira_prefixo(l1, 1);
	printf("\n\nlista\n");
	print_lista(l1);
	
		
	l2 = separa(l1, 5);

	printf("lista 1\n");
	print_lista(l1);
	printf("\nlista 2\n");
	print_lista(l2);
	printf("\nConcatena\n");
	l1 = concatena(l1, l2);
	print_lista(l1);
	
	return 0;
}*/
