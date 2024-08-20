#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas) {
    float **matriz = (float**)malloc(linhas * sizeof(float*));
    for (int i = 0; i < colunas; i++) {
        matriz[i] = (float*)malloc(colunas * sizeof(float));
    }

    //Atribui valores à matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand()%10;
        }
    }
    
    //Mostra valores
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return matriz;
}

float **mult_matriz(float **A, int n, int m, float **B, int o, int p) {
    //Cria matriz produto
    float **resultMatriz = cria_matriz(n, m);
    
    //Matriz o produto
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultMatriz[i][j] = 0.0;
            for (int k = 0; k < m; k++) {
                resultMatriz[i][j] += A[i][k] * B[k][j];     
            }   
        }
    }

    return resultMatriz;   
}

float** soma_matriz(float** A, float** B, int n, int m) {
    float** somaMatriz = cria_matriz(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            somaMatriz[i][j] = A[i][j] + B[i][j];
        }
    }

    return somaMatriz;
}

void libera_matriz(float **A, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    int linhas, colunas;

    printf("Informe linhas: ");
    scanf("%d", &linhas);
    printf("Informe colunas: ");
    scanf("%d", &colunas);

    printf("Matriz 1\n");
    float **matrizA = cria_matriz(linhas, colunas);
    printf("Matriz 2\n");
    float **matrizB = cria_matriz(linhas, colunas);

    float **multMatriz = mult_matriz(matrizA, linhas, colunas, matrizB, linhas, colunas);
    float **somaMatriz = soma_matriz(matrizA, matrizB, linhas, colunas);
    
    //Mostra valores
    printf("Matriz produto\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", multMatriz[i][j]);
        }
        printf("\n");
    }

    //Mostra valores
    printf("\nMatriz Soma\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", somaMatriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    libera_matriz(matrizA, linhas);
    libera_matriz(matrizB, linhas);
    libera_matriz(multMatriz, linhas);
    libera_matriz(somaMatriz, linhas);
    return 0;
}
