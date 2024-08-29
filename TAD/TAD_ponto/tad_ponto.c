#include <stdlib.h>
#include <math.h>
#include "tad_ponto.h"

Ponto* cria_ponto(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));

    if(p != NULL) {
        p->x = x;
        p->y = y;
    }

    return p;
}

void libera_ponto(Ponto* p) {
    free(p);
}

void acessa_ponto(Ponto* p, float* x, float* y) {
    *x = p->x;
    *y = p->y;
}

void atribui_ponto(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

float distancia(Ponto* p1, Ponto* p2) {
    if(p1 == NULL || p2 == NULL)
     return -1.0;
    
    float dx = p2 -> x - p1 -> x;
    float dy = p2 -> y - p1 -> y;

    return sqrt(pow(p1->x - p2->x,2) + pow(p1->y - p2->y,2));
}