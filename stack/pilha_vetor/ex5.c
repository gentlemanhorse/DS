#include "pilha_vetor.h"

int verifica_parenteses(char *e) {
    PilhaChar *p = cria_pilha_char();
    for(int i = 0; e[i] != '\0'; i++) {
        if (e[i] == '(') // se ha um parentese aberto, insere na pilha
            push_char(p, e[i]);
        else if (e[i] == ')') { // se ha um parentese fechado, verifica se nao ha um aberto sobrando (erro)
            if(char_is_empty(p))
                return 0;
            pop_char(p);
        }
    }
    int r = char_is_empty(p); // verifica se ha algum parentese sobrando (erro)
    free_pilha_char(p);
    return r;
}

int main(int argc, char *argv[]) {
    char *expressao1 = "2 * 3)(1 - 3)))";
    char *expressao2 = "(2 - 3) * (5 + 3) * 7";
    printf("expressao 1 %s\n", expressao1);
    if (verifica_parenteses(expressao1)) 
        printf("expressao 1 eh valida\n");
    
    else 
        printf("Expressao 1 nao eh valida\n");
    printf("expressao 2 %s\n", expressao2);
    if (verifica_parenteses(expressao2))
        printf("expressao 2 eh valida\n");
    else
        printf("expressao 2 nao eh valida\n");
    return 0;
}

