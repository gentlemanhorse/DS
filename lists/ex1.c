#include "lista.h"

int main(int argc, char *argv[]) {
	Lista *lista = NULL;
	for (int i = 0; i < 10; i++) {
		lista = insere(lista, i + 1);
	}
	print_lista(lista);
	Lista *nova_lista = separa(lista, 6);
	printf("Primeira metade\n");
	print_lista(lista);
	printf("\n\nSegunda metade\n");
	print_lista(nova_lista);
	return 0;
}
