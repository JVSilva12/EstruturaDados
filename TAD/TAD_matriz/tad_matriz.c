#include "tad_matriz.h"
#include <stdlib.h>
#include <stdio.h>

Matriz* mat_cria(int m, int n){
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    mat->lin = m;
    mat->col = n;
    mat->v = (float**)malloc(m*sizeof(float*));
    int i = 0, j = 0;

    for(i=0; i < m; i++){
        mat->v[i] = (float*)malloc(n*sizeof(float));
        for(j=0; j < n; j++)
            mat->v[i][j] = 0.0;
    }

    return mat;
}

void mat_libera(Matriz* mat){
    int i = 0;

    for(i = 0; i < mat->lin; i++)
        free(mat->v[i]);

    free(mat->v);

    free(mat);
}

float mat_acessa(Matriz* mat, int i, int j){
    return mat->v[i][j];
}

void mat_atribui(Matriz* mat, int i, int j, float v){
    mat->v[i][j] = v;
}

int mat_linhas(Matriz* mat){
    return mat->lin;
}

int mat_colunas(Matriz* mat){
    return mat->col;
}

void mat_imprime(Matriz* mat){
    int i = 0,j = 0;
    
    for(i = 0; i < mat->lin; i++){
        for(j = 0; j < mat->col; j++) {
            printf("%10.2f", mat->v[i][j]);
            printf("\n");
        }
    }   
}

//