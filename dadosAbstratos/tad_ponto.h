#define tad_ponto.h

typedef struct {
    float x;
    float y;
} Ponto;

Ponto* cria_ponto(float x, float y);

void libera_ponto(Ponto* p);

float distancia_ponto(Ponto* p1, Ponto* p2);