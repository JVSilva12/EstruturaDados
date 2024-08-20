#include <stdio.h>
#include <stdlib.h>

float* ordena(int n, float *vetor) {
    float temp;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
        
    }
    
}

int main() {
    int n;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &n);
    printf("OK!\n\n");
    
    float *vetor = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        vetor[i] = rand()%10;
        printf(" %.1f", vetor[i]);
    }
    printf("\n\n");

    ordena(n, vetor);
    
    printf("\n\n");
    for (int i = 0; i < n; i++) {
        printf(" %.1f", vetor[i]);
    }
    
    printf("\n\n");
    free(vetor);
    return 0;
}