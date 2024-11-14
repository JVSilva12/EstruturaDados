#include <stdio.h>
#include <stdlib.h>

float media(float * vet, int qtd) {
    float cont = 0;
    for (int i = 0; i < qtd; i++) cont += vet[i];
    return cont/qtd;
}

float var(float *vet, int qtd) {
    float med = media(vet, qtd);
    float variancia = 0.0;

    for (int i = 0; i < qtd; i++) {
        variancia = (vet[i] - med) * (vet[i] - med);
    }

    return variancia/(float)qtd;    
}

int main() {
    float vetor[11];
    int quantidade = 11;
    float cont = 0;

    for (int i = 0; i < 11; i++) {
        printf("Numero %d: ", i+1);
        scanf("%f", &vetor[i]);
        cont += vetor[i];
    }
    
    printf("\nMedia: %.2f\n", media(vetor, quantidade));
    printf("Variancia: %.2f", var(vetor, quantidade));
    printf("\n\n");
    return 0;
}
