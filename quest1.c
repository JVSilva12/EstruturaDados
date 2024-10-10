#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} lista;
typedef struct lista* PLista;

/* 1 - Implemente funções para inserir, remover e buscar elementos na lista.*/

PLista lista_insere(PLista lista, int info) {
    PLista novo = (PLista) malloc(sizeof(struct lista)); // Certifique-se de alocar o tamanho correto
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novo->info = info;
    novo->prox = lista;

    return novo; // Retorna a nova lista, começando pelo novo nó
}

PLista lista_remove (PLista lista, int info){
 PLista ant = NULL;
 PLista aux = lista;
 //busca o elemento com valor desejado
 while(aux != NULL && aux->info != info){
 ant = aux;
 aux = aux->prox;
 }
 //caso não encontre nenhum elemento
 if(aux == NULL)
 return lista;
 //caso o elemento esteja na cabeça
 if(ant == NULL)
 lista = lista->prox;
 else //caso esteja no corpo ou na cauda
 ant->prox = aux->prox;
 free(aux);
 return lista;
}
PLista lista_busca (PLista lista, int info){
 while(lista != NULL && lista->info != info)
 lista = lista->prox;
 return lista;
}
/*
 2 - Crie uma função que retorne o ponteiro para o último nó de uma lista
encadeada.
*/
PLista ultimo (PLista lista){
 //verificação se a lista é vazia
 if(lista == NULL)
 return lista;
 while(lista->prox != NULL)
 lista = lista->prox;
 return lista;
}
/*
 3 - Dadas duas listas encadeadas, crie uma função que una as duas em uma
única lista.
*/
PLista concatena (PLista lista1, PLista lista2){
 //verificaçao de a lista1 é vazia
 if(lista1 == NULL)
 return lista2;
 PLista aux = lista1;
 //encontra a cauda da lista1
 while(aux->prox != NULL)
 aux = aux->prox;
 aux->prox = lista2;

 return lista1;
}
/*
 4 - Crie uma função que retorne quantos elementos existem em uma lista
encadeada.
*/
int comprimento (PLista lista){
 int acc = 0;
 while(lista != NULL){
 acc++;
 lista = lista->prox;
 }
 return acc;
}
/*
 5 - Crie uma função que retorne a quantidade de nós da lista que possuem
o campo info com valores iguais a n.
*/
int quant_n (PLista lista, int n){
 int acc = 0;
 while(lista != NULL){
 //verificação se o info é igual a n
 if(lista->info == n)
 acc++;
 lista = lista->prox;
 }
 return acc;
}
/*
 6 - Implemente funções para encontrar o maior e o menor elemento em uma
lista, os valores serão retornados por referências ao endereço.
*/
void lista_maior_menor (PLista lista, PLista* maior, PLista* menor){
 *maior = *menor = lista;
 while(lista != NULL){
 if( (*maior)->info < lista->info )
 *maior = lista;
 else if( (*menor)->info > lista->info )
 *menor = lista;
 lista = lista->prox;
 }
}
/*
 7 - Escreva uma função que retorne uma lista que seja a inversão de uma
outra passada por parâmetro.
*/
PLista inverte (PLista lista){
 PLista nova_lista = NULL;
 while(lista != NULL){
 PLista novo = (PLista) malloc(sizeof(lista));
 novo->info = lista->info;
 novo->prox = nova_lista;
 nova_lista = novo;
 lista = lista->prox;
 }
 return nova_lista;
}
/*
 8 - Escreva uma função para retornar uma interseção de duas listas de
números inteiros passadas por parâmetro.
*//*
PLista intersecao_lista (PLista lista1, PLista lista2){
 PLista nova_lista = NULL;
 //FOR aninhados para cada elemento da lista1 percorrer todos da lista2
 for( ; lista1 != NULL ; lista1 = lista1->prox)
 for(PLista aux = lista2 ; aux != NULL ; aux = aux->prox)
 /*
 o elemento da lista1 seja igual a algum da lista2
 será inserido na nova_lista
 
 if(lista1->info == lista2->info){
 PLista novo = (PLista) malloc(sizeof(struct lista));
 novo->info = lista1->info;
 novo->prox = nova_lista;
 nova_lista = novo;
 break;
 }
 return nova_lista;
}*/

PLista intersecao_lista(PLista lista1, PLista lista2) {
    PLista nova_lista = NULL;
    
    // Percorre todos os elementos da lista1
    for (; lista1 != NULL; lista1 = lista1->prox) {
        // Para cada elemento de lista1, percorre todos os elementos de lista2
        for (PLista aux = lista2; aux != NULL; aux = aux->prox) {
            // Se encontrar um elemento em lista2 igual ao de lista1
            if (lista1->info == aux->info) {
                // Insere o elemento na nova lista de interseção
                PLista novo = (PLista) malloc(sizeof(struct lista));
                novo->info = lista1->info;
                novo->prox = nova_lista;
                nova_lista = novo;
                break; // Sai do loop interno após encontrar o primeiro match
            }
        }
    }
    
    return nova_lista;
}


/*
 9 - Escreva uma função para retornar uma nova lista ordenada, união de duas
outras listas.
*/
PLista uniao_ordenada_lista (PLista lista1, PLista lista2){
 int tam = 0;
 //contagem de quantos elementos existem nas duas listas
 for(PLista aux = lista1 ; aux != NULL ; aux = aux->prox)
 tam++;
 for(PLista aux = lista2 ; aux != NULL ; aux = aux->prox)
 tam++;
 //vetor criado para receber todos os elementos das listas
 int* vetor = (int*) malloc(tam * sizeof(int));
 int i = 0;
 for(PLista aux = lista1 ; aux != NULL ; aux = aux->prox){
 vetor[i] = aux->info;
 i++;
 }
 for(PLista aux = lista2 ; aux != NULL ; aux = aux->prox){
 vetor[i] = aux->info;
 i++;
 }
 //ordenando o vetor
 i = 0;
 while(i < tam-1){
 if(vetor[i] > vetor[i+1]){
 int temp = vetor[i];
 vetor[i] = vetor[i+1];
 vetor[i+1] = temp;
 if(i > 0)
 i--;
 }
 else
 i++;
 }
 //criando nova lista com os valores do vetor já ordenado
 PLista nova_lista = NULL;
 for(i = tam-1 ; i >= 0 ; i--){
 PLista novo = (PLista) malloc(sizeof(lista));
 novo->info = vetor[i];
 novo->prox = nova_lista;
 nova_lista = novo;
 }
 return nova_lista;
}
/*
 10 - Escreva uma função para retornar uma nova lista contendo a diferença
simétrica de duas outras listas.
*/
PLista dif_sim_lista (PLista lista1, PLista lista2){
 PLista nova_lista = NULL;
 PLista aux1;
 PLista aux2;
 //FOR aninhados para cada elemento da lista1 percorrer todos da lista2
 for(aux1 = lista1 ; aux1 != NULL ; aux1 = aux1->prox){
 for(aux2 = lista2 ; aux2 != NULL ; aux2 = aux2->prox)
 if(aux2->info == aux1->info) break;
 /*
 verificação, caso aux2 seja NULL significa aquele elemento da lista1 não está
contido na lista2, assim inserimos ele na nova lista
 */
 if(aux2 == NULL){
 PLista novo = (PLista) malloc(sizeof(lista));
 novo->info = aux1->info;
 novo->prox = nova_lista;
 nova_lista = novo;
 }
 }
 //mesmo proceso com a lista 2
 //FOR aninhados para cada elemento da lista2 percorrer todos da lista1
 for(aux1 = lista2 ; aux1 != NULL ; aux1 = aux1->prox){
 for(aux2 = lista1 ; aux2 != NULL ; aux2 = aux2->prox)
 if(aux2->info == aux1->info) break;
 /*
 verificação, caso aux2 seja NULL significa aquele elemento da lista2 não
 está contido na lista1, assim inserimos ele na nova lista
 */
 if(aux2 == NULL){
 PLista novo = (PLista) malloc(sizeof(lista));
 novo->info = aux1->info;
 novo->prox = nova_lista;
 nova_lista = novo;
 }
 }
 return nova_lista;
}

void lista_imprime(PLista lista) {
    PLista p;
    printf("Lista: ");
    for (p = lista; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

void lista_libera(PLista lista) {
    PLista p = lista;
    PLista temp;
    while (p != NULL) {
        temp = p;
        p = p->prox;
        free(temp);
    }
    lista = NULL;
}

int main() {
    PLista lista1 = NULL;
    PLista lista2 = NULL;
    PLista lista3 = NULL;

    lista1 = lista_insere(lista1, 10);
    lista1 = lista_insere(lista1, 20);
    lista1 = lista_insere(lista1, 30);
    lista1 = lista_insere(lista1, 40);
    lista1 = lista_insere(lista1, 50);
    lista2 = lista_insere(lista2, 60);
    lista2 = lista_insere(lista2, 20);
    lista2 = lista_insere(lista2, 80);
    lista2 = lista_insere(lista2, 90);
    lista2 = lista_insere(lista2, 99);
    lista_imprime(lista1);
    lista_imprime(lista2);

    // lista1 = concatena(lista1, lista2);
    // printf("\nApos concatenar: ");
    // lista_imprime(lista1);

    lista3 = intersecao_lista(lista1, lista2);
    printf("\nIntersecao: \n");
    lista_imprime(lista3);

    printf("\n\n");
    lista_libera(lista1);
    lista_libera(lista2);
    lista_libera(lista3);
    return 0;
}
