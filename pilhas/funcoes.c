/*
#include <stdio.h>
#include <stdlib.h>

//QUANDO O TAMANHO DA PILHA É CONHECIDO!!!
#define N 50

struct pilha {
    int n;
    float vet[N]; 
};
typedef struct pilha Pilha;

Pilha* pilha_cria() {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->n = 0;
    return novo;
}

void push(Pilha* p, float v) {
    if (p->n == N) {
        printf("Capacidade da pilha estourou!\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

float pop(Pilha* p) {
    float v;
    if (pilha_vazia(p)) {
        printf("Pilha vazia!!!\n");
        exit(1);
    }
    v = p->vet[p->n--];
    p->n--;

    return v;
}

int pilha_vazia(Pilha* p) {
    return (p->n == 0);
}

void pilha_libera(Pilha* p) {
    free(p);
}

*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
typedef struct pilha {
    int info;
    struct pilha* prox;
}Pilha;

Pilha* cria_pilha() {
    return NULL;  // Retorna NULL para indicar que a pilha está inicialmente vazia
}

void push(Pilha* p, int v) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));  // Aloca memória para o novo nó
    if (novo == NULL) {
        printf("Erro ao alocar memória!!!\n");
        exit(1);
    }
    novo->info = v;  // Atribui o valor ao novo nó
    novo->prox = p; // O novo nó aponta para o topo atual
    p = novo;       // Atualiza o topo da pilha para o novo nó
}

int pop(Pilha* p) {
    if (p == NULL) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    
    Pilha* temp = p; // Salva o nó do topo para liberá-lo depois
    int valor = temp->info; // Armazena o valor do topo
    p = p->prox;  // Atualiza o topo para o próximo nó
    free(temp);  // Libera a memória do nó removido
    
    return valor;  // Retorna o valor do nó removido
}

void imprime_pilha(Pilha* p) {
    Pilha* atual = p;
    if (p == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("\nElementos da pilha:\n");
    while (atual != NULL) {
        printf("%d\n", atual->info);
        atual = atual->prox;
    }
}


void libera_pilha(Pilha* p) {
    Pilha* atual = p;
    Pilha* temp;
    
    if (atual == NULL) {
        printf("\nPilha vazia!!!\n\n");
        exit(1);
    }

    while (atual != NULL) {
        temp = atual;        // Armazena o nó atual
        atual = atual->prox; // Avança para o próximo nó
        free(temp);          // Libera a memória do nó atual
    }
    
    p = NULL;  // Define o topo como NULL, indicando que a pilha está vazia
}

int pilha_vazia(Pilha* p) {
    return p == NULL;
}

int pilha_topo(Pilha* p) {
    if (p == NULL){
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->info;
}

int quant_elementos(Pilha* p) {
    int aux = 0;
    Pilha* atual = p;
    if (pilha_vazia(atual)) {
        printf("\nVazia!!!\n");
        exit(1);
    }
    
    while (atual != NULL) {
        aux++;
        atual = atual->prox;
    }

    return aux;
}

void remove_valor(Pilha* p, int valor) {
    Pilha* temp = NULL;  // Pilha temporária
    
    // Desempilha todos os elementos da pilha original
    while (p != NULL) {
        int topo = pop(p);  // Pega o valor do topo da pilha original
        if (topo != valor) {
            push(temp, topo);  // Empilha na pilha temporária se for diferente do valor
        }
        p = p->prox;
    }
    
    // Reempilha os elementos da pilha temporária de volta na pilha original
    while (temp != NULL) {
        push(p, pop(temp));
    }
}

int main() {
    // Cria uma pilha vazia
    Pilha* pilha = cria_pilha();

    // Empilhando valores
    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);

    /*
    printf("\nTopo: %d\n", pilha_topo(pilha));
    printf("Quant. de elementos: %d\n", quant_elementos(pilha));

    // Remover todas as ocorrências de '5'
    remove_valor(&pilha, 5);
    printf("\nPilha após remover 5:\n");
    imprime_pilha(pilha);
    */

    remove_valor(pilha, 10);
    printf("\nPilha após remover 10:\n");
    imprime_pilha(pilha);

    printf("\n\n");
    libera_pilha(pilha);
    return 0;
}
