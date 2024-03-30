#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	Lista *lista = NULL;

	for(int i = 0; i < 10; i++){
		lista = insere(lista, i);
	}

	print_lista(lista);
}
