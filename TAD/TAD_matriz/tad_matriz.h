#ifndef tad_matriz_h
#define tad_matriz_h

typedef struct matriz{
    int lin;
    int col;
    float** v;
} Matriz;

Matriz* mat_cria(int m, int n);
void mat_libera(Matriz* mat);
float mat_acessa(Matriz* mat, int i, int j);
void mat_atribui(Matriz* mat, int i, int j, float v);
int mat_linhas(Matriz* mat);
int mat_colunas(Matriz* mat);
void mat_imprime(Matriz* mat);

#include "tad_matriz.c"
#endif