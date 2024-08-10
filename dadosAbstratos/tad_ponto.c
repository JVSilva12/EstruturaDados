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

float distancia_ponto(Ponto* p1, Ponto* p2) {
    if(p1 == NULL || p2 == NULL)
     return -1.0;
    
    float dx = p2 -> x - p1 -> x;
    float dy = p2 -> y - p1 -> y;

    return sqrt(dx * dx + dy * dy);
}