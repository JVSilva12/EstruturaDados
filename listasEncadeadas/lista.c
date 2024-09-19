#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria() {
    return NULL;
}

Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    
    return novo;
}

/* Lista* lst_insere_final(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    Lista* passado = l;

    novo->info = i;
    novo->prox = NULL;

    if (l == NULL) {
        l = novo;
        return;
    }

    while (passado->next != NULL) {
        passado = passado->prox;
    }
    passado->prox = novo;
}
*/

void lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
}

int lst_vazia(Lista* l) { 
    return (l == NULL);
}

Lista* lst_retira(Lista* l, int v) {
    Lista* p = l;
    Lista* ant = NULL;

    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) {
        printf("Elemento não encontrado\n");
        return l;
    }
    
    if (ant == NULL) {
        l = l->prox;
    }else {
        ant->prox = p->prox;
    }
    
    free(p);
    return l;
}

void lst_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}
