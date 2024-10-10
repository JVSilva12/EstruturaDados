#include <stdio.h>
#include <stdlib.h>

typedef struct nopilha
{
    int info;
    struct nopilha *prox;
} pilha;
typedef pilha *PPilha; 


PPilha pilhaPush(PPilha p, int n)
{
    PPilha novo = (PPilha)malloc(sizeof(pilha));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria!\n");
        return NULL;
    }
    novo->info = n;
    novo->prox = p;
    p = novo;
    return p;
}
PPilha pilhaPop(PPilha p)
{
    if (p == NULL)
    {
        printf("pilha estah vazia!\n");
        return NULL;
    }
    PPilha temp = p;
    p = p->prox;
    free(temp);
    return p;
}

/*02*/
/*a)*/
int pilhaVazia(PPilha p)
{
    return (p == NULL ? 1 : 0);
}
/*b)*/
int pilhaTopo(PPilha p) {
    if (pilhaVazia(p)) {
        printf("pilha estah vazia!");
        return -1;
    }

    return p->info;
}
/*
c)
*/
int pilhaQuant(PPilha p)
{
    int count = 0;
    while (p != NULL)
    {
        p = p->prox;
        count++;
    }
    return count;
} /*
 03
 */
PPilha pilhaLimpa(PPilha p)
{
    while (p != NULL)
    {
        PPilha temp = p;
        p = p->prox;
        free(temp);
    }
    return NULL;
}
/*
04
*/PPilha pilhaRemoveValor(PPilha p, int n) {
    PPilha pilhaAuxiliar = NULL;

    // Transfere elementos para a pilha auxiliar, exceto o valor a ser removido
    while (p != NULL) {
        if (p->info != n) {
            pilhaAuxiliar = pilhaPush(pilhaAuxiliar, p->info);
        }
        p = pilhaPop(p);
    }

    // Transfere os elementos da pilha auxiliar de volta para a pilha original
    while (pilhaAuxiliar != NULL) {
        p = pilhaPush(p, pilhaAuxiliar->info);
        pilhaAuxiliar = pilhaPop(pilhaAuxiliar);
    }

    return p;
}
 /*
 05
 */
void pilhaInverteString(char *string)
{
    PPilha pilha = NULL;
    for (int i = 0; string[i] != '\0'; i++)
        pilha = pilhaPush(pilha, (int)string[i]);
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = (char)pilhaTopo(pilha);
        pilha = pilhaPop(pilha);
    }
}

/* 06 */
int pilhaCalculaExpressao(char *string)
{
    PPilha pilha1 = NULL;
    PPilha pilha2 = NULL;
    PPilha pilhaAux = NULL;
    int aux = 0;
    int i;
    i = 0;
    do
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            aux *= 10;
            aux += string[i] - '0';
        }
        else
        {
            pilhaAux = pilhaPush(pilhaAux, aux);
            aux = 0;
        }
    } while (string[i++] != '\0');

    /* Cotinua na próxima página - Cotinuação da questão 06 i = 0;*/
    while (pilhaAux != NULL)
    {
        pilha1 = pilhaPush(pilha1, pilhaTopo(pilhaAux));
        pilhaAux = pilhaPop(pilhaAux);
    }
    do
    {
        if (string[i] == '+' || string[i] == '-')
            pilhaAux = pilhaPush(pilhaAux, (int)string[i]);
    } while (string[i++] != '\0');
    while (pilhaAux != NULL)
    {
        pilha2 = pilhaPush(pilha2, pilhaTopo(pilhaAux));
        pilhaAux = pilhaPop(pilhaAux);
    }
    if (pilha1 == NULL)
        return -1;
    // expressao vazia
    int total = pilhaTopo(pilha1);
    pilha1 = pilhaPop(pilha1);
    while (pilha1 != NULL)
    {
        if ((char)pilhaTopo(pilha2) == '+')
            total += pilhaTopo(pilha1);
        else
            total -= pilhaTopo(pilha1);
        pilha1 = pilhaPop(pilha1);
        pilha2 = pilhaPop(pilha2);
    }
    return total;
}

void imprime(PPilha p) {
    PPilha aux = p;
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

void libera(PPilha p) {
    PPilha temp;
    while (p != NULL) {
        temp = p;
        p = p->prox;
        free(temp);
    }
}

int main() {
    PPilha pilha1 = NULL;
    PPilha pilha2 = NULL;
    
    pilha1 = pilhaPush(pilha1, 10);
    pilha1 = pilhaPush(pilha1, 20);
    pilha1 = pilhaPush(pilha1, 30);
    pilha1 = pilhaPush(pilha1, 40);
    pilha1 = pilhaPush(pilha1, 50);
    pilha2 = pilhaPush(pilha2, 60);
    pilha2 = pilhaPush(pilha2, 70);
    pilha2 = pilhaPush(pilha2, 80);
    pilha2 = pilhaPush(pilha2, 90);
    pilha2 = pilhaPush(pilha2, 99);
    printf("Pilha1:\n");
    imprime(pilha1);
    printf("\nPilha2:\n");
    imprime(pilha2);
    printf("\n");

    printf("\n\n");
    libera(pilha1);
    libera(pilha2);
    return 0;
}