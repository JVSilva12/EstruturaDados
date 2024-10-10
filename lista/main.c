#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int info;
    struct No *prox;
} No;

typedef No* PLista; // Definindo o ponteiro para o tipo No

PLista lista_insere(PLista lista, int info) {
    // Aloca um novo nó
    PLista novo = (PLista)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    
    // Insere a informação e aponta o próximo nó para a lista atual
    novo->info = info;
    novo->prox = lista;
    
    return novo; // Retorna o novo nó, que agora é o início da lista
}

PLista lista_remove(PLista lista, int info) {
    PLista ant = NULL; // Ponteiro para o anterior
    PLista p = lista;  // Ponteiro para percorrer a lista

    // Busca o elemento a ser removido
    while (p != NULL && p->info != info) {
        ant = p;
        p = p->prox;
    }

    // Caso o elemento não tenha sido encontrado
    if (p == NULL) return lista;

    // Remove o elemento
    if (ant == NULL) {
        // O elemento a ser removido está no início da lista
        lista = p->prox;
    } else {
        // O elemento a ser removido está no meio ou final da lista
        ant->prox = p->prox;
    }
    
    free(p); // Libera a memória do nó removido
    return lista; // Retorna a lista (início atualizado, se necessário)
}

PLista lista_busca(PLista lista, int info) {
    PLista p;
    for (p = lista; p != NULL; p = p->prox) {
        if (p->info == info) {
            return p; // Retorna o ponteiro para o nó encontrado
        }
    }
    return NULL; // Retorna NULL se o elemento não for encontrado
}

PLista concatena(PLista lista1, PLista lista2) {
    if (lista1 == NULL) {
        // Se a primeira lista for vazia, retorna a segunda lista
        return lista2;
    }

    // Percorre até o final da primeira lista
    PLista p = lista1;
    while (p->prox != NULL) {
        p = p->prox;
    }

    // Conecta o último nó da primeira lista ao início da segunda lista
    p->prox = lista2;

    // Retorna a lista concatenada
    return lista1;
}

void lista_libera(PLista lista) {
    PLista p = lista;
    while (p != NULL) {
        PLista temp = p;  // Armazena o nó atual
        p = p->prox;      // Avança para o próximo nó
        free(temp);       // Libera o nó armazenado em temp
    }
    p = NULL;
}

void lista_imprime(PLista lista) {
    PLista p;
    for (p = lista; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
}


int main() {
    PLista lista1 = NULL;
    PLista lista2 = NULL;
    
    // Insere alguns elementos na primeira lista
    lista1 = lista_insere(lista1, 10);
    lista1 = lista_insere(lista1, 20);
    lista1 = lista_insere(lista1, 30);
    
    // Insere alguns elementos na segunda lista
    lista2 = lista_insere(lista2, 40);
    lista2 = lista_insere(lista2, 50);
    lista2 = lista_insere(lista2, 60);
    
    // Concatena as duas listas
    PLista listaConcatenada = concatena(lista1, lista2);
    lista_imprime(listaConcatenada);

    PLista lista = NULL; // Inicializa a lista como vazia
    
    // Insere alguns elementos
    lista = lista_insere(lista, 10);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 30);
    lista_imprime(lista);

    lista_libera(lista);
    lista_libera(lista1);
    lista_libera(lista2);
    
    return 0;
}
