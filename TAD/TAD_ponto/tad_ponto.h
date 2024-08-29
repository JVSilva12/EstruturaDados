#ifndef tad_ponto_h
#define tad_ponto_h

typedef struct {
    float x;
    float y;
} Ponto;

Ponto* criar_ponto(float x, float y);
void libera_ponto(Ponto* p);
void acessa_ponto(Ponto* p, float* x, float* y);
void atrribui_ponto(Ponto* p, float* x, float* y);
float distancia_ponto(Ponto* p1, Ponto* p2);

#include "tad_ponto.c"

#endif