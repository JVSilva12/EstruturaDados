#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaPaciente {
    int id_paciente;
    char nome[51];
    int idade;
    int prioridade;
} ListaPaciente;

typedef ListaPaciente * PLista;

PLista* cria_lista(int tam);
void inserir_paciente(PLista* lista, int tam);
void exibe_lista(PLista* lista, int tam);
PLista buscar_paciente(PLista* lista, int tam, int id);
void exibe_paciente(PLista paciente);
void deletar_paciente_prioridade(PLista* lista, int tam, int prioridade);
void deletar_paciente(PLista* lista, int tam, int id);
void libera_lista(PLista* lista, int tam);

int main() {
    int tam = 10;

    PLista* lista = cria_lista(tam);
    inserir_paciente(lista, tam);
    exibe_lista(lista, tam);

    //BUSCAR PACIENTE POR ID
    int aux;
    printf("\nINFORME ID DO PACIENTE A SER BUSCADO: ");
    scanf("%d", &aux);
    PLista paciente_busca = buscar_paciente(lista, tam, aux);
    if (paciente_busca != NULL) {
        exibe_paciente(paciente_busca);
    } else {
        printf("Paciente com ID %d não encontrado.\n", aux);
    }

    //DELETAR PACIENTE POR PRIORIDADE
    printf("\nINFORME PRIORIDADE DO PACIENTE A SER DELETADO: ");
    scanf("%d", &aux);
    deletar_paciente_prioridade(lista, tam, aux);

    //DELETAR PACIENTE POR ID
    printf("\nINFORME ID DO PACIENTE A SER DELETADO: ");
    scanf("%d", &aux);
    deletar_paciente(lista, tam, aux);

    exibe_lista(lista, tam);

    libera_lista(lista, tam);

    return 0;
}

PLista* cria_lista(int tam) {
    PLista* lista = (PLista*)malloc(tam * sizeof(PLista));
    for (int i = 0; i < tam; i++) {
        lista[i] = NULL;
    }
    
    return lista;
}

void exibe_lista(PLista* lista, int tam) {
    for (int i = 0; i < tam && lista[i] != NULL; i++) {
        printf("\nPACIENTE %d\n", i + 1);
        printf("ID: %d\n", lista[i]->id_paciente);
        printf("NOME: %s\n", lista[i]->nome);
        printf("IDADE: %d\n", lista[i]->idade);
        printf("PRIORIDADE: %d\n", lista[i]->prioridade);
    }
}

void exibe_paciente(PLista paciente) {
    if (paciente != NULL) {
        printf("\nNOME: %s", paciente->nome);
        printf("\nIDADE: %d", paciente->idade);
        printf("\nPRIORIDADE: %d\n", paciente->prioridade);
    } else {
        printf("Paciente não encontrado.\n");
    }
}

void inserir_paciente(PLista* lista, int tam) {
    for (int i = 0; i < tam; i++) {
        if (lista[i] == NULL) {
            lista[i] = (PLista)malloc(sizeof(ListaPaciente));  // Corrigido para alocar a estrutura completa
            lista[i]->id_paciente = i + 1;
            sprintf(lista[i]->nome, "pessoa (%d)", i + 1);
            lista[i]->idade = (rand()%100) + 1;
            lista[i]->prioridade = (rand()%5) + 1;
        }
    }
}

void libera_lista(PLista* lista, int tam) {
    for (int i = 0; i < tam; i++) {
        if (lista[i] != NULL) {
            free(lista[i]);
        }
    }
    free(lista);
}

void deletar_paciente_prioridade(PLista* lista, int tam, int prioridade) {
    for (int i = 0; i < tam; i++) {
        if (lista[i] != NULL && lista[i]->prioridade == prioridade) {
            free(lista[i]);
            // Desloca os elementos subsequentes para manter a lista consistente
            for (int j = i; j < tam - 1; j++) {
                lista[j] = lista[j + 1];
            }
            lista[tam - 1] = NULL;  // Define o último como NULL após o deslocamento
            i--;  // Verifica o novo elemento na posição atual
        }
    }
}

void deletar_paciente(PLista* lista, int tam, int id) {
    for (int i = 0; i < tam; i++) {
        if (lista[i] != NULL && lista[i]->id_paciente == id) {
            free(lista[i]);
            // Desloca os elementos subsequentes para manter a lista consistente
            for (int j = i; j < tam - 1; j++) {
                lista[j] = lista[j + 1];
            }
            lista[tam - 1] = NULL;  // Define o último como NULL após o deslocamento
            break;  // Sai do loop após deletar o paciente
        }
    }
}

PLista buscar_paciente(PLista* lista, int tam, int id) {
    for (int i = 0; i < tam; i++) {
        if (lista[i] != NULL && lista[i]->id_paciente == id) {
            return lista[i];
        }
    }
    return NULL;
}
