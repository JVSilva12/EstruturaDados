#include <stdio.h>
#include <stdlib.h>

int main() {
    int var;
    int *pont = &var;

    printf("Valor de var: %d", var);
    printf("\nEndereço de var: %p", &var);
    printf("\nValor de pont: %p", pont);
    printf("\nValor apontado por pont: %d", *pont);
    *pont = 20;
    printf("\nValor apontado por pont: %d", *pont);
    printf("\n\n");

    return 0;
}
