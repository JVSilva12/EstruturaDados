#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int linhas, int colunas);
void imprime_matriz(float **mat, int linhas, int colunas);
void libera_matriz(float **mat, int linhas, int colunas);
float **soma_matrizes(float **matA, float **matB, int linhas, int colunas);
float **multiplica_matriz(float **matA, float **matB, int linhas, int colunas);

int main()
{
    int linhas, colunas;

    printf("Informe tamanho:\n");
    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);

    float **mat = cria_matriz(linhas, colunas);

    printf("\n");
    preenche_matriz(mat, linhas, colunas);
    imprime_matriz(mat, linhas, colunas);

    libera_matriz(mat, linhas, colunas);
    printf("\n\n");
    return 0;
}

float **cria_matriz(int linhas, int colunas)
{
    float **matriz = (float **)malloc(linhas * sizeof(float *));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (float *)malloc(colunas * sizeof(float));
    }

    return matriz;
}

void preenche_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("P - %d %d: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
    printf("Concluido!\n\n");
}

void libera_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void imprime_matriz(float **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%.f ", matriz[i][j]);
        }
        printf("\n");
    }
}
