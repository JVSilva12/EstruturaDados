/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista {
    int id;
    char nome[100];
    char descricao[100];
    float valor;
} *Lista;

Lista* cria_lista(int tamanho);
void inserir_prod(Lista* lista, int *tamanho, Lista novoProd);
void mostrar_lista(Lista* lista, int *tamanho);
Lista busca_prod(Lista* lista, int *tamanho, char nomeProd);
void deletar_prod(Lista* lista, int *tamanho, Lista produto);
void deletar_prodID(Lista* lista, int *tamanho, int idProd);
void libera_lista(Lista* lista, int *tamanho);

int main() {
    int tamanho = 0;
    int tamanhoInicial = 5;

    Lista* lista = cria_lista(tamanhoInicial);

    Lista p1 = (Lista)malloc(sizeof(Lista));
    p1->id = 1;
    strncpy(p1->nome, sizeof(p1->nome), "Produto 1");
    strncpy(p1->nome, sizeof(p1->nome), "Descricao Produto 1");
    p1->valor = 10.0;
    inserir_prod(lista, &tamanho, p1);
    
    Lista p2 = (Lista)malloc(sizeof(Lista));
    p2->id = 2;
    strncpy(p2->nome, sizeof(p2->nome), "Produto 2");
    strncpy(p2->nome, sizeof(p2->nome), "Descricao Produto 2");
    p2->valor = 20.0;
    inserir_prod(lista, &tamanho, p2);
    
    Lista p3 = (Lista)malloc(sizeof(Lista));
    p3->id = 1;
    strncpy(p3->nome, sizeof(p1->nome), "Produto 3");
    strncpy(p3->nome, sizeof(p1->nome), "Descricao Produto 3");
    p3->valor = 10.0;
    inserir_prod(lista, &tamanho, p3);

    Lista p4 = (Lista)malloc(sizeof(Lista));
    p4->id = 1;
    strncpy(p4->nome, sizeof(p1->nome), "Produto 4");
    strncpy(p4->nome, sizeof(p1->nome), "Descricao Produto 4");
    p4->valor = 10.0;
    inserir_prod(lista, &tamanho, p4);


    mostrar_lista(lista, &tamanho);




    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
    int id;
    char nome[51];
    char descricao[81];
    float valor;
} produto;

produto** cria_lista(int max) {
    produto** lista = (produto **)malloc(max*sizeof(produto*));
    for (int i = 0; i < max; i++) {
            lista[i]=NULL;
    }
    return lista;
}

void insere_lista(produto** lista, int max) {
    for (int i = 0; lista[i] != NULL && i < max; i++) {
        if (i == max) {
            printf("N...\n");
            return;
        }
        lista[i]=(produto*)malloc(sizeof(produto));
        printf("Digite o id do produto %d: ", i+1);
        scanf("%d", &lista[i]->id);
        printf("Digite o nome do produto %d: ", i+1);
        scanf(" %50[^\n]%*c", &lista[i]->nome);
        //strncpy(lista[i]->nome, sizeof(lista[i]->nome), " %s");
        printf("Digite a descricao do produto %d: ", i+1);
        scanf(" %80[^\n]%*c", &lista[i]->descricao);
        printf("Digite o valor do produto %d: ", i+1);
        scanf("%f", &lista[i]->valor);
    }
}

void del_prod_lista(produto** lista, int max, produto* prod) {
    int i = 0;
    for (i = 0; lista[i] != NULL && i < max; i++){
        if (i == max) {
            printf("Elem...\n");
            return;
        }
        free(lista[i]);
        lista[i] = NULL;
    }
}

void del_prod_id_lista(produto** lista, int max, int id_prod) {
    int i = 0;
    for (i = 0; lista[i]->id != id_prod && i < max; i++){
        if (i == max) {
            printf("Elem...\n");
            return;
        }
        free(lista[i]);
        lista[i] = NULL;
    }
}

produto** busca_prod(produto** lista, int max, int id_prod) {
    for(int i = 0; i < max; i++){
        if(lista[i]->id == id_prod) {
            return lista[i];
        }
    }
    return NULL;
}

void libera_lista(produto** lista, int max) {
    for (int i = 0; i < max; i++){
        free(lista[i]);
        lista[i] = NULL;
    }
    free(lista);
    lista = NULL;
}

int main() {
    
    
    return 0;
}
