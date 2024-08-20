#include <stdio.h>
#include <stdlib.h>

float** mult_matriz(float** A, int n, int m, float** B) {
    float **matProduto = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < m; i++) {
        matProduto[i] = (float*)malloc(m * sizeof(float));
    }

    //Produto de matA com matB
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                matProduto[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return matProduto;
}

int main() {
    int n, m;
    
    printf("Numero de linhas: ");
    scanf("%d", &n);
    printf("Numero de colunas: ");
    scanf("%d", &m);

    //Cria MatA
    float **matA = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < m; i++) {
        matA[i] = (float*)malloc(m * sizeof(float));
    }
    
    //Cria MatB
    float **matB  = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < m; i++) {
        matB[i] = (float*)malloc(m * sizeof(float));
    }

    //Atribuir valores a MatA e MatB
    //Imprime matA
    printf("Matriz A\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matA[i][j] = rand()%10;
            matB[i][j] = rand()%10;

            printf("%.1f ", matA[i][j]);
        }
        printf("\n");
    }

    //Imprime matB
    printf("\nmatriz B\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.1f ", matB[i][j]);
        }
        printf("\n");
    }


    float **matMult = mult_matriz(matA, n, m, matB);

    //Imprime matMult
    printf("\nMatriz produto\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.1f ", matMult[i][j]);
        }
        printf("\n");
    }

    //Limpa matA
    for (int i = 0; i < n; i++) {
        free(matA[i]);
    }
    free(matA);

    //Limpa matB
    for (int i = 0; i < n; i++) {
        free(matB[i]);
    }
    free(matB);

    //Limpa matMult
    for (int i = 0; i < n; i++) {
        free(matMult[i]);
    }
    free(matMult);

    printf("\n\n");
    return 0;
}