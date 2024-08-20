#include<stdio.h>
#include <stdlib.h>

void swap(float *a, float *b);
void ordena_vetor(float *vetor, int n, char ordem);


int main() {
    float a, b;

    printf("Informe a: ");
    scanf("%f", &a);
    printf("Informe b: ");
    scanf("%f", &b);

    swap(&a, &b);

    printf("Após swap: a = %.1f, b = %.1f\n", a, b);

    int n;
    printf("Informe n: ");
    scanf("%d", &n);

    //Cria vetor
    float *vetor = (float*)malloc(n * sizeof(float));

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 10;
        printf("%.1f ", vetor[i]);
    }
    printf("\n");

    char ordem;
    printf("Informe ordem crescente('c') ou decrescente('d'): ");
    scanf(" %c", &ordem);

    ordena_vetor(vetor, n, ordem);

    // Mostra vetor modificado0;
    printf("Vetor modificado: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}

void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void ordena_vetor(float *vetor, int n, char ordem){
    //float temp;
    if (ordem == 'c') {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i -1; j++) {
               if (vetor[j] > vetor[j+1]) {
                    swap(&vetor[j], &vetor[j+1]);
                    //temp = vetor[j];
                    //vetor[j] = vetor[j+1];
                    //vetor[j+1] = temp;
               }
            }
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i -1; j++) {
               if (vetor[j] < vetor[j+1]) {
                    swap(&vetor[j], &vetor[j+1]);
                    // temp = vetor[j];
                    // vetor[j] = vetor[j+1];
                    // vetor[j+1] = temp;
               }
            }
        }
    }
}