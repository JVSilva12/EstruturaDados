#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct lista{
    int info;
    struct lista *prox;
};

typedef struct lista lista;
typedef lista *plista;

plista lista_cria(void);
plista lista_insere(plista lista, int info);
void lista_imprime(plista lista);
plista lista_busca(plista lista, int info);
void lista_libera(plista lista);
plista lista_retira(plista lista, int info);

//REVISÃO
plista lista_ultimo(plista lista); // quest 2
plista lista_concatena(plista lista1, plista lista2); //quest 3
int comprimento(plista lista); //quest 4
int quant_n(plista lista, int n); //quest 5
void lista_maior_menor(plista lista,plista *maior,plista *menor); //quest 6
plista inverte(plista lista); //quest 7
plista intersecao_lista(plista lista1, plista lista2); //quest 8
plista uniao_ordenada_lista(plista lista1, plista lista2); //quest 9


int main(){

    plista lista=lista_cria();

    lista = lista_insere(lista, 55);

    lista = lista_insere(lista, 101);

    lista = lista_insere(lista, 202);

    lista_imprime(lista);

    return 0;
}


plista lista_cria(void){
    return NULL;
}

plista lista_insere(plista lista, int info){ // Questão 1 da lista
    plista aux=(plista)malloc(sizeof(lista));

    aux -> info = info;
    aux -> prox = lista;

    return aux;
}

void lista_imprime(plista aux){

    while(aux!=NULL){
    printf("%d\n", aux->info);
    aux = aux->prox; //apontando para outro (nº vezes)
    }
}

plista lista_busca(plista lista, int info){ // Questão 1 da lista

    while(lista!=NULL && lista->info != info)
        lista = lista->prox;
    
    return lista;

/* for(plista p= lista;p!=NULL;p=p->prox) //as duas formas funcionam :)
    if(p->info==info)
        return p;
    */    
        
}

void lista_libera(plista lista){
    while(lista!=NULL){
        plista p=lista;
        lista = lista->prox;
        free(p);
    }
}

plista lista_retira(plista lista, int info){ // Questão 1 da lista
    plista ant=NULL;
    plista p=lista;

    /* while(p=!NULL && p->info!=info){
        ant=p;
        p=p->prox;
    }
    if(p==NULL)
        return lista;
    if(ant==NULL){
        lista=p->prox;
        free(p);
    }
    else{
        ant->prox=p->prox;
        free(p);
    }
    */

   
    for(;p!=NULL;p=p->prox){
        if(p->info=info)
        break;
        ant=p;
    }
    //Nao encontramos nada
    if(p==NULL){
        return lista;
    }
    //Encontramos na cabeça da lista
    if(ant==NULL && p!=NULL){
        lista=p->prox;
        free(p);
        return lista;  //lista_retira(lista,info);
    }
    if(ant !=NULL && p!=NULL){
    ant->prox=p->prox;
    free(p);
    return lista; //lista_retira(lista,info);
    }
    // return lista; // para o While habilitado
} 

plista lista_ultimo(plista lista){ //Questão 2
    plista aux = lista;

    for(;lista->prox !=NULL;lista=lista->prox);
    return lista;
}

plista lista_concatena(plista lista1, plista lista2){ //Questão 3
    plista aux = lista1;
    for(;aux->prox !=NULL;aux=aux->prox);
    aux->prox=lista2;
    return lista1;
}

int comprimento(plista lista){ //Questão 4
    int acc=0;
    for(;lista!=NULL;lista=lista->prox, acc++);
    return acc;
}

int quant_n(plista lista, int n){ //Questão 5
    int acc=0;
    for(;lista!=NULL;lista=lista->prox)
        if(lista->info==0)
            acc++;
    return acc;
}

void lista_maior_menor(plista lista,plista *maior,plista *menor){ // Questão 6
    *maior=*menor=lista;
    for(;lista!=NULL;lista=lista->prox){
        if(lista->info > (*maior)->info)
            *maior=lista;
        else if(lista->info < (*menor)->info)
            *menor=lista;
    }
}

plista inverte(plista lista){ //Questão 7
    plista nova_lista=NULL;

    for(;lista!=NULL;lista=lista->prox){
        plista novo=(plista)malloc(sizeof(lista));
        novo->info=lista->info;
        novo->prox=nova_lista;
        nova_lista=novo;
    }
    return nova_lista;
}

plista intersecao_lista(plista lista1, plista lista2){ //Questão 8
    plista l3= NULL;
    for(;lista1!=NULL;lista1=lista1->prox)
        for(;lista2!=NULL;lista2=lista2->prox)
        if(lista1->info==lista2->info){
            l3=lista_insere(l3, lista2->info);
            break;
        }
    return l3;
}

plista uniao_ordenada_lista(plista lista1, plista lista2){ //Questão 9
    int tam=comprimento(lista1) + comprimento(lista2);

    int *vetor=(int*)malloc(tam*sizeof(int));

    int i=0;
    for(;lista1!=NULL;lista1=lista1->prox){
        vetor[i]=lista1->info;
        i++;
    }
    for(;lista2!=NULL;lista2=lista2->prox){
        vetor[i]=lista2->info;
        i++;
    }

    i=0;
    while(i<tam-1){
        if(vetor[i]>vetor[i+1]){
            int temp=vetor[i];
            vetor[i]=vetor[i+1];
            vetor[i+1]=temp;
            i--;
        }
        else
            i++;
        if(i<0)
            i=0;
    }
    plista lista3 = NULL;
    for(i=tam-1;i>=0;i--){
        lista3=lista_insere(lista3,vetor[i]);
    }
    return lista3;
}