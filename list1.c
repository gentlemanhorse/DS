#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

typedef struct list Lista;

Lista *insert(Lista *l, int value){
    Lista *new = (Lista *) malloc(sizeof(Lista));
    new->value = value;
    new->next = l;

    return new;
}

void printList(Lista *l){
    Lista *t;
    int i = 0;
    for(t = l; t != NULL; t = t->next){
        printf("num %d value == %d\n", i++ + 1,  t->value);
    }
    
}

int isVoid(Lista *l){
    return (l == NULL);
} 

Lista *separa(Lista *l, int n) {
    Lista *ret = l;
    Lista *ant = NULL;

    while(ret != NULL && ret->value != n) {
        ant = ret;
        ret = ret->next;
    }

    if(ret == NULL)
        return NULL;

    if(ant == NULL)
        l = NULL;
        return ret; 

    ant->next = NULL;
    return ret;
}


Lista *removeL(Lista *l, int value){
    Lista* prev = NULL;
    Lista* t = l;

    while(t != NULL && t->value != value){
        prev = t;
        t = t->next;
    }

    if(t == NULL)
        return l;
    
    if(prev == NULL)
        l = t->next;

    else
        prev->next = t->next;
    
    free(t);
    return l;
}



int main(int argc, char* argv[]){
    Lista *list = NULL;
    int len = 10;
    for(int i = 0; i < len ; i++){
        list = insert(list, rand() % 100);
    }
    printList(list);
    printf("\n\n\n");
    Lista* newList = separa(list, 24);
    printf("\n\n\nPrimeira Metade: \n");
    printList(list);
    printf("\n\n\nSegunda Metade:\n");
    printList(newList);

    free(list);
    free(newList);
}