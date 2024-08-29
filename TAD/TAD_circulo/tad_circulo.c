#include <stdio.h>
#include "../TAD_ponto/tad_ponto.h"

#define PI 3.14159

Circulo* circulo_cria(float x, float y, float r){
    Circulo* aux = (Circulo*)malloc(sizeof(Ponto));
    aux->c.x = x;
    aux->c.y = y;
    aux->r = r;

    return aux;
}
 
void circulo_exclui(Circulo* c) {
    free(c);
}

float circulo_area(Circulo* c) {
    return PI * c->r * c->r;
}

int circulo_interior(Circulo* c, Ponto* p){
    float d = distancia( &c->c, p);
    return (d < c->r);
}  