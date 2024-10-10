#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista* Lista;

// Função para inserir um elemento na lista
Lista* insere(Lista* l, int v) {
    Lista novo = (Lista)malloc(sizeof(struct lista)); // Aloca memória corretamente
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1); // Sai do programa em caso de erro
    }
    novo->info = v;
    novo->prox = *l;  // O próximo elemento é o atual início da lista
    *l = novo;        // O novo elemento agora é o início da lista
    return l;
}

// Função para remover um elemento específico da lista
Lista* remove_elemento(Lista* l, int v) {
    Lista ant = NULL;
    Lista p = *l;
    
    // Procura o elemento na lista
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    
    // Se o elemento não foi encontrado, retorna a lista original
    if (p == NULL) return l;

    // Remove o elemento
    if (ant == NULL) {
        // O elemento está no início
        *l = p->prox;
    } else {
        // O elemento está no meio ou final
        ant->prox = p->prox;
    }
    
    free(p);
    return l;
}

// Função para liberar a lista da memória
void libera(Lista* l) {
    Lista p = *l;
    while (p != NULL) {
        Lista t = p->prox;
        free(p);
        p = t;
    }
    *l = NULL;
}

// Função para remover elementos repetidos da lista
Lista* remove_repetido(Lista* l) {
    Lista p = *l;
    
    while (p != NULL) {
        Lista ant = p;
        Lista aux = p->prox;
        
        // Verifica se há algum elemento repetido mais à frente
        while (aux != NULL) {
            if (aux->info == p->info) {
                ant->prox = aux->prox; // Remove o elemento repetido
                free(aux); // Libera a memória do elemento removido
                aux = ant->prox;
            } else {
                ant = aux;
                aux = aux->prox;
            }
        }
        p = p->prox;
    }
    
    return l;
}

// Função para imprimir a lista
void imprime(Lista* l) {
    Lista p = *l;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

int conta_lista(Lista l) {
    int cont = 0;
    Lista p = l;
    while (p != NULL) {
        cont++;
        p = p->prox;
    }
    return cont;
}

Lista intersecao_lista(Lista lista1, Lista lista2) {
    Lista nova_lista = NULL;
    
    // Percorre todos os elementos da lista1
    for (; lista1 != NULL; lista1 = lista1->prox) {
        // Para cada elemento de lista1, percorre todos os elementos de lista2
        for (Lista aux = lista2; aux != NULL; aux = aux->prox) {
            // Se encontrar um elemento em lista2 igual ao de lista1
            if (lista1->info == aux->info) {
                // Insere o elemento na nova lista de interseção
                nova_lista = insere(nova_lista, lista1->info);
                // Lista novo = (Lista) malloc(sizeof(struct lista));
                // novo->info = lista1->info;
                // novo->prox = nova_lista;
                // nova_lista = novo;
                break; // Sai do loop interno após encontrar o primeiro match
            }
        }
    }
    
    return nova_lista;
}

// Função para verificar está ordenado
int esta_ordenado(Lista* l) {
    Lista p = *l;
    Lista aux = p->prox;

    while(p->prox != NULL){
        if(p->info <= aux->info){
            p = p->prox;
            aux = aux->prox;
        } else {
            return 0;
        }
    }
    
    return 1;
}

// Função principal
int main() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    Lista* l2 = (Lista*)malloc(sizeof(Lista));
    *l = NULL;
    *l2 = NULL;
    
    // Insere os elementos na lista
    l = insere(l, 6);
    l = insere(l, 5);
    l = insere(l, 5);
    l = insere(l, 4);
    l = insere(l, 4);
    l = insere(l, 3);
    l = insere(l, 2);
    l = insere(l, 1);

    l2 = insere(l2, 7);
    l2 = insere(l2, 5);
    l2 = insere(l2, 2);
    l2 = insere(l2, 5);
    l2 = insere(l2, 1);
    l2 = insere(l2, 3);
    l2 = insere(l2, 2);
    l2 = insere(l2, 4);
    
    printf("Lista original: ");
    imprime(l);

    /*
    // Remove os elementos repetidos
    l = remove_repetido(l);
    printf("Lista sem repetidos: ");
    imprime(l);
    */

    /*
    intersecao_lista(l, l2);
    printf("\nLista intersecao: ");
    imprime(l);
    */

    printf("Lista ordenada: %d", esta_ordenado(l));
    
    printf("\n\n");
    // Libera a lista da memória
    libera(l);
    
    return 0;
}
