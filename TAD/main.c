#include <stdio.h>

#include "TAD_ponto/tad_ponto.h"
#include "TAD_circulo/tad_circulo.h"
#include "TAD_matriz/tad_matriz.h"

void teste_circulo_ponto();
void teste_matriz();

int main(int argc, char** argv){

    //teste_circulo_ponto();

    teste_matriz();
 
    return 0;
}

void teste_circulo_ponto(){

    float x,y,r;

    printf("Entre com o centro do círculo: ");
    scanf(" %f, %f", &x, &y);
    printf("Entre com o raio: ");
    scanf("%f", &r);

    Circulo* circ = circulo_cria( x, y, r);
    
    printf("\n Círculo de centro (%.2f, %.2f) e raio %.2f\n", circ->c.x, circ->c.y, circ->r);

    printf("Entre com as coordenadas do ponto: ");
    scanf(" %f, %f", &x, &y);

    Ponto* p = criar_ponto(x,y);

    printf("\n O ponto (%.2f, %.2f) está ", p->x, p->y);
 
    if (circulo_interior(circ,p))
        printf("dentro do círculo.");
    else
        printf("na borda ou fora do círculo.");

    circulo_exclui(circ);
    libera_ponto(p);
}

void teste_matriz(){

    Matriz* m = mat_cria(2,2);

    mat_imprime(m);

    int i=0, j=0;  

    // Atribui 1 aos valores da matriz.
    for(i=0; i<m->lin; i++){
        for(j=0; j < m->col; j++){
            m->v[i][j] = 1;
        }
    }
    printf("\n\n");
    mat_imprime(m);

    mat_libera(m);
}