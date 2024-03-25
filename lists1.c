
#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

typedef struct list List;

List *insert(List *l, int value){
    List *new = (List *) malloc(sizeof(List));
    new->value = value;
    new->next = l;

    return new;
}

void printList(List *l){
    List *t;
    int i = 0;
    for(t = l; t->next != NULL; t = t->next){
        printf("%d value == %d\n", i++ + 1,  t->value);
    }
    
}

int isVoid(List *l){
    return (l == NULL);
}

List *searchByValue(List *l, int value){
    List *t;
    for(t = l; t->next != NULL; t = t->next){
        if(t->value == value)
            return t;
    }
    return NULL;

}

List *removeL(List *l, int value){
    List* prev = NULL;
    List* t = l;

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

List *separa(List* l, int n){
    List *t = searchByValue(l, n);

    
}


int main(int argc, char* argv[]){
    List *list = NULL;
    int len = 100;
    for(int i = 0; i < len ; i++){
        list = insert(list, rand() % 100);
    }
    printList(list);

    List* newList = searchByValue(list, 34);
    printList(newList);
    newList = removeL(list, 34);
    printList(newList);

    free(list);
    free(newList);
}
