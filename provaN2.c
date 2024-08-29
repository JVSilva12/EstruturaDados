#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int id_produto;
    char nome[1000];
    char descricao[1000];
    float valor;
} *Lista;

Lista* cria_lista(int tamanho);
void inserir_prod(Lista* lista, int* tamanho, Lista novo_prod);
Lista buscar_produto(Lista* lista, int tamanho, int id_produto);
void deletar_produto(Lista* lista, int* tamanho, Lista produto);
void deletar_produtoID(Lista* lista, int* tamanho, int id_produto);
void libera_lista(Lista* lista, int* tamanho);
void exibe_prod(Lista* lista, int *tamanho);

int main() {
    int tamanho = 0;
    int capacidade_inicial = 10;

    Lista* lista = cria_lista(capacidade_inicial);

    Lista p1 = (Lista)malloc(sizeof(Lista));
    p1->id_produto = 1;
    snprintf(p1->nome, sizeof(p1->nome), "Produto 1");
    snprintf(p1->descricao, sizeof(p1->descricao), "Descricao do Produto 1");
    p1->valor = 10.0;
    inserir_prod(lista, &tamanho, p1);

    Lista p2 = (Lista)malloc(sizeof(lista));
    p2->id_produto = 2;
    snprintf(p2->nome, sizeof(p2->nome), "Produto 2");
    snprintf(p2->descricao, sizeof(p2->descricao), "Descricao do Produto 2");
    p2->valor = 20.0;
    inserir_prod(lista, &tamanho, p2);

    Lista p3 = (Lista)malloc(sizeof(Lista));
    p3->id_produto = 1;
    snprintf(p3->nome, sizeof(p3->nome), "Produto 3");
    snprintf(p3->descricao, sizeof(p3->descricao), "Descricao do Produto 3");
    p3->valor = 10.0;
    inserir_prod(lista, &tamanho, p3);

    Lista p4 = (Lista)malloc(sizeof(lista));
    p4->id_produto = 2;
    snprintf(p4->nome, sizeof(p4->nome), "Produto 4");
    snprintf(p4->descricao, sizeof(p4->descricao), "Descricao do Produto 4");
    p4->valor = 20.0;
    inserir_prod(lista, &tamanho, p4);

    //Exibe lista
    exibe_prod(lista, &tamanho);

    // Buscar um produto
    Lista produto_encontrado = buscar_produto(lista, tamanho, 2);
    if (produto_encontrado != NULL) {
        printf("\n\nProduto encontrado: %s\n", produto_encontrado->nome);
        printf("Descricao: %s\n", produto_encontrado->descricao);
        printf("Valor: R$%.2f\n\n", produto_encontrado->valor);
    }

    //Deleta produto
    deletar_produto(lista, &tamanho, p1);

    // Deletar um produto pelo id
    deletar_produtoID(lista, &tamanho, 2);

    //Exibe lista
    exibe_prod(lista, &tamanho);

    // Limpar a lista
    libera_lista(lista, &tamanho);

    return 0;
}



Lista* cria_lista(int tamanho) {
    Lista* lista_prod = (Lista*)malloc(tamanho*sizeof(Lista));

    return lista_prod;
}

void inserir_prod(Lista* lista, int* tamanho, Lista novo_produto) {
    lista[*tamanho] = novo_produto;
    (*tamanho)++;
}

Lista buscar_produto(Lista* lista, int tamanho, int id_produto) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i]->id_produto == id_produto) {
            return lista[i];
        }
    }
    return NULL;
}

void exibe_prod(Lista* lista, int *tamanho) {
    printf("\nLISTA\n");
    for(int i = 0; i < *tamanho; i++) {
        printf("%s\n", lista[i]->nome);  
    }
}

void deletar_produto(Lista* lista, int* tamanho, Lista produto) {
    for (int i = 0; i < *tamanho; i++) {
        if (lista[i] == produto) {
            free(lista[i]);
            for (int j = i; j < *tamanho - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*tamanho)--;
        }
    }
}

void deletar_produtoID(Lista* lista, int* tamanho, int id_produto) {
    Lista produto = buscar_produto(lista, *tamanho, id_produto);
    if (produto != NULL) {
        deletar_produto(lista, tamanho, produto);
    }
}


void libera_lista(Lista* lista, int* tamanho) {
    for (int i = 0; i < *tamanho; i++) {
        free(lista[i]);
    }
    free(lista);
    *tamanho = 0;
}
