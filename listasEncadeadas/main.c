#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista.c"

int main() {
    Lista* l;
    l = lst_cria();
    l = lst_insere(l, 23);
    l = lst_insere(l, 45);
    l = lst_insere(l, 56);
    l = lst_insere(l, 78);
    lst_imprime(l);
    l = lst_retira(l, 78);
    lst_imprime(l);
    l = lst_retira(l, 45);
    lst_imprime(l);
    lst_libera(l);
    
    printf("\n\n");
    return 0;
}