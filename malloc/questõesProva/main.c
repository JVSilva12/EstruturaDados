#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int info;
    struct pilha* prox;
} pilha;
typedef pilha* Pilha;

Pilha push(Pilha p, int v) {
    Pilha novo = (Pilha)malloc(sizeof(pilha));
    novo->info = v;
    novo->prox = p;
    return novo;
}

Pilha pop(Pilha p) {
    Pilha aux = p;
    Pilha temp = NULL;
    if (aux  != NULL) {
        temp = p;
        p = p->prox;
        free(temp);    
    } else {
        printf("Vazio!!!");
        exit(1);
    }
    
    return p;
}

void libera(Pilha p) {
    Pilha aux = p;
    Pilha temp = NULL;
    while (aux != NULL) {  
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
}



int main() {
    
    
    return 0;
}