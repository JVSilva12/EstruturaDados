#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct lista2 {
    int info;
    struct lista* prox;
};
typedef struct lista2 Lista2;

Lista* lst_cria() {
    return NULL;
}

Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    
    return novo;
}

Lista* lst_busca(Lista* l, int i) {
    Lista* p;
    for(p = l; p != NULL && p->info == i; p = p->prox) {
        return p;
    }
}

Lista* lst_ultimo(Lista* l) {
    Lista* p = l;

    while (p->prox != NULL) {
        p = p->prox;
    }
    return p;
}

void lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
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

Lista* lst_une(Lista* l, Lista* l2) {
    Lista* pl;
    Lista* l3 = lst_cria();

    for (pl = l; pl != NULL; pl = pl->prox) {
        l3 = lst_insere(l3, pl->info);
    }

    for (pl = l2; pl != NULL; pl = pl->prox) {
        l3 = lst_insere(l3, pl->info);
    }

    return l3;
}

int lst_comprimento(Lista* l) {
    Lista* p;
    int i = 0;

    for (p = l; p != NULL; p = p->prox) {
        i++;    
    }

    return i;
}

int lst_quant(Lista* l, int n) {
    Lista* p;
    int i = 0;

    for (p = l; p != NULL; p = p->prox) {
        if(p->info == n) {
            i++;
        }
    }

    if (i == 0) {
        printf("Valor nao consta em l3!");
        return 0;
    }

    return i;
}

void lst_maior_menor(Lista* l, Lista* maior, Lista* menor) {
    *maior = *l;
    *menor = *l;
    Lista* p = l->prox;

    while(p != NULL) {
        if (p->info > maior->info) {
            *maior = *p;
        }
        if (p->info < menor->info) {
            *menor = *p;
        }
        p = p->prox;
    }
}

/*Lista* lst_inverte(Lista* l) {
    Lista* ant = NULL;
    Lista* p = l;
    Lista* proximo;

    while (p != NULL) {
        proximo = p->prox;
        p->prox = ant;
        ant = p;
        p = proximo;
    }

    return ant;
}*/

int lst_estaNaLista (Lista* l, int v) {
    Lista* p = l;
    while (p != NULL) {
        if (p->info == v) {
            return 1;
        }
        p = p->prox;
    }
    return 0;
}
/*
Lista* lst_interseccao(Lista* l, Lista* l2) {
    Lista* p = l;
    Lista* l3 = lst_cria();

    while(p != NULL) {
        if (lst_estaNaLista(l2, p->info)) {
            l3 = lst_insere(l3, p->info);
        }
    }
    p = p->prox;

    return l3;
}*/
/*
Lista* lst_insere_ordenado(Lista* l, int v) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = NULL;

    if (l == NULL || l->info >= v) {
        novo->prox = l;
        return novo;
    }

    Lista* atual = l;
    while (atual->prox != NULL && atual->prox->info < v) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;

    return l;
}*/
/*
Lista* uniao_ordenada_lista(Lista* l1, Lista* l2) {
    Lista* uniao = lst_cria(); // Lista para armazenar a união ordenada
    Lista* p1 = l1;
    Lista* p2 = l2;

    // Inserir todos os elementos de l1 na lista de união
    while (p1 != NULL) {
        uniao = lst_insere_ordenado(uniao, p1->info);
        p1 = p1->prox;
    }

    // Inserir todos os elementos de l2 na lista de união
    while (p2 != NULL) {
        uniao = lst_insere_ordenado(uniao, p2->info);
        p2 = p2->prox;
    }

    return uniao;
}*/

Lista* dif_sim_lista(Lista* l1, Lista* l2) {
    Lista* dif_sim = lst_cria(); // Lista para armazenar a diferença simétrica
    Lista* p1 = l1;
    Lista* p2 = l2;

    // Adicionar elementos que estão em l1 mas não em l2
    while (p1 != NULL) {
        if (lst_estaNaLista(l2, p1->info)) {
            dif_sim = lst_insere(dif_sim, p1->info);
        }
        p1 = p1->prox;
    }

    // Adicionar elementos que estão em l2 mas não em l1
    while (p2 != NULL) {
        if (lst_estaNaLista(l1, p2->info)) {
            dif_sim = lst_insere(dif_sim, p2->info);
        }
        p2 = p2->prox;
    }

    return dif_sim;
}

int main() {
    Lista* l;
    Lista* l2;
    Lista* l3;
    Lista menor, maior;
    //Lista* interseccao = lst_interseccao(l, l2);
    //Lista* invertida = lst_inverte(l3);
    // Lista* uniao = uniao_ordenada_lista(l, l2);
    Lista* diff_sim = dif_sim_lista(l, l2);

    l = lst_cria();
    l2 = lst_cria();
    
    l = lst_insere(l, 23);
    l = lst_insere(l, 45);
    l = lst_insere(l, 56);
    l = lst_insere(l, 78);
    
    //lst_imprime(l);
    //l = lst_retira(l, 78);
    //lst_imprime(l);
    //l = lst_retira(l, 45);
    printf("Lista 1:\n");
    lst_imprime(l);

    l2 = lst_insere(l2, 50);
    l2 = lst_insere(l2, 12);
    l2 = lst_insere(l2, 88);
    l2 = lst_insere(l2, 90);
    printf("\nLista 2:\n");
    lst_imprime(l2);

    l3 = lst_une(l, l2);
    printf("\nLista l3:\n");
    lst_imprime(l3);
    l = lst_ultimo(l);
    printf("\nUltimo: %d\n", l->info);
    printf("Tamanho de l3: %d", lst_comprimento(l3));

    int n;
    printf("\nInforme elemento em l3: ");
    scanf("%d", &n);
    printf("%d ocorrencias!", lst_quant(l3, n));

    lst_maior_menor(l, &maior, &menor);
    printf("\n\nMaior valor: %d\n", maior.info);
    printf("Menor valor: %d\n", menor.info);

    //printf("\nLista invertida: ");
    //lst_imprime(invertida);]

    //printf("\nLista intersecacao:\n");
    //lst_imprime(interseccao);

    // printf("União ordenada: \n");
    // lst_imprime(uniao);

    printf("Diferença simétrica: ");
    lst_imprime(diff_sim);

    lst_libera(l);
    lst_libera(l2);
    lst_libera(l3);
    printf("\n\n");

    return 0;
}
    
    