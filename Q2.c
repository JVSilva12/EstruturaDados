#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista {
    char letra;
    struct lista* prox;
} Lista;

typedef struct pilha {
    Lista* prim;
} Pilha;

// Cria a estrutura de uma pilha vazia
Pilha* pilha_cria(void) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

// Insere um elemento na pilha
void pilha_push(Pilha* p, char letra) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->letra = letra;
    novo->prox = p->prim;
    p->prim = novo;
}

// Retira um elemento da pilha
char pilha_pop(Pilha* p) {
    if (p->prim == NULL) {
        return -1; // Pilha vazia
    }
    char letra = p->prim->letra;
    Lista* temp = p->prim;
    p->prim = p->prim->prox;
    free(temp);
    return letra;
}

// Verifica se a sequência de parênteses, colchetes e chaves está balanceada
int verifica_balanceamento(char *sequencia) {
    Pilha* pilha = pilha_cria(); // Cria uma pilha vazia
    char atual;

    for (int i = 0; sequencia[i] != '\0'; i++) {
        atual = sequencia[i];

        if (atual == '(' || atual == '{' || atual == '[') {
            pilha_push(pilha, atual);
        } else if (atual == ')' || atual == '}' || atual == ']') {
            if (pilha->prim == NULL) {
                return false; // Não está balanceado
            }
            char topo = pilha_pop(pilha);
            if ((atual == ')' && topo != '(') || 
                (atual == '}' && topo != '{') || 
                (atual == ']' && topo != '[')) {
                return false; // Não está balanceado
            }
        }
    }

    int resultado = pilha->prim == NULL;
    free(pilha); // Libera a memória da pilha
    return resultado; // Retorna verdadeiro se balanceado, falso caso contrário
}

// Função para testar o balanceamento
void test_balanceamento() {
    char* sequencias[] = {
        "{[()]}",
        "{[(])}",
        "{[()]}{}",
        "({[{}]})",
        "({[})]",
        "[]{}()",
        "[(])"
    };
    
    for (int i = 0; i < 7; i++) {
        printf("Sequência: %s - Balanceada: %s\n", sequencias[i], 
            verifica_balanceamento(sequencias[i]) ? "true" : "false");
    }
}

int main() {
    test_balanceamento();
    return 0;
}
