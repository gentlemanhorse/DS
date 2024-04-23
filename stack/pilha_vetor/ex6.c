#include "pilha_vetor.h"
#include <string.h>
int verfica_prefixo_sufixo(char *str, char *pref) {
    // verificar se a string eh 
    PilhaChar *p = cria_pilha_char();
    int ip = strlen(pref) - 1;

    // Verifica se o elemento do meio eh o caracter 'C'
    if(str[strlen(pref)] != 'C' || strlen(str) != (strlen(pref) * 2 + 1)) {
        free_pilha_char(p);
        return 0;
    }

    for(int i = 0; i < strlen(pref); i++) {
        // Verifica se os elementos iniciais condizem com o fator
        if(str[i] == pref[i]) 
            push_char(p, str[i]);
        else {
            free_pilha_char(p);
            return 0;
        }  
    
        // Verifica se os elementos finais condizem com o fator 
        if (pop_char(p) != str[strlen(str) - i - 1]) {
            free_pilha_char(p);
            return 0;       
        }
    }
    return 1;
}

int main(int argc, char *arv[]) {
    char *str1 = "ABCxjCjxCBA";
    char *pref1 = "ABCxj";
    char *str2 = "EAEECEEEE";
    char *pref2 = "EAEE";
    char *str3 = "BOBXBOB";
    char *pref3 = "BOB";
    printf("string 1 = %s fator 1 = %s\nstring 2 = %s fator 2 = %s\nstring 3 = %s fator 3 == %s\n", str1, pref1, str2, pref2, str3, pref3);
    if (verfica_prefixo_sufixo(str1, pref1)) 
        printf("String 1 contem os requisitos\n");
    else    
        printf("String 1 nao contem os  requisitos\n");
    if (verfica_prefixo_sufixo(str2, pref2)) 
        printf("String 2 contem os requisitos\n");
    else    
        printf("String 2 nao contem os  requisitos\n");
    if (verfica_prefixo_sufixo(str3, pref3)) 
        printf("String 3 contem os requisitos\n");
    else    
        printf("String 3 nao contem os  requisitos\n");
    


    return 0;
}