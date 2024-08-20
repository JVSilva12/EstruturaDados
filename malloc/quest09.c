#include <stdio.h>
#include <stdlib.h>

float** trans_matriz(int n, int m, float** mat) {
    
    float **mat_trans = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < n; i++) {
        mat_trans[i] = (float*)malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat_trans[j][i] = mat[i][j];
        }
        
    }
    
    return mat_trans;
}

int main() {
    int n, m;

    printf("Informe linhas: ");
    scanf("%d", &n);
    printf("Informe colunas: ");
    scanf("%d", &m);

    //Cria Mat1
    float **mat = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        mat[i] = (float*)malloc(m * sizeof(float));
    }

    //Armazena valores em Mat1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = rand()%10;
        }
    }

    //Imprime MatrizOriginal
    printf("\nMatriz Original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %.2f |", mat[i][j]);
        }
        printf("\n");
    }

    float** transposta = trans_matriz(n, m, mat);

    //Imprime Matriz Transposta
    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %.1f |", transposta[i][j]);
        }
        printf("\n");
    }

    
    //Limpa Mat
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    //Limpa mat_trans
    for (int i = 0; i < m; i++) {
        free(transposta[i]);
    }
    free(transposta);

    printf("\n\n");
    return 0;
}
