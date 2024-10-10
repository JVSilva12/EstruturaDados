#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int info;
    struct pilha* prox;
}Pilha;

Pilha* pilha_cria() {
    return NULL;
}

void pilha_push(Pilha** p, int v) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if (novo == NULL) {
        printf("\nPilha vazia!!\n");
        exit(1);
    }
    novo->info = v;
    novo->prox = *p;
    *p = novo;
}

int pilha_pop(Pilha* p) {
    if (p == NULL) {
        printf("\nPilha vazia!!\n");
        exit(1);
    }
    Pilha* aux = p;
    int valor = p->info;
    p = p->prox;
    free(aux);

    return valor;
}

int verifica_balaceamento(char* seq) {
    int i = 0;
    char c;
    Pilha* p = pilha_cria();

    for (i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == '{' || seq[i] == '[' || seq[i] == '(') {
            pilha_push(p, seq[i]);
        } else {
            c = pilha_pop(p);
        }
    }
}

int main() {
    
    
    return 0;
}