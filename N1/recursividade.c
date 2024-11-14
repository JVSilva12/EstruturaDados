
/*
#include <stdio.h>
#include <stdlib.h>
int modulo(int n) {
    return (n >= 0) ? n : -(n);
}
int main() {
    int n = 4;
    printf("Modulo de %d: %d\n\n", n, modulo(n));
    return 0;
}*/

/*
#include <stdio.h>
#include <stdlib.h>

 void swap_crescente(int *num1, int *num2) {
    int aux;
    if (*num1 > *num2) {
        aux = *num1;
        *num1 = *num2;
        *num2 = aux;
    }
 }

int main() {
    int num1 = 5, num2 = 4;

    swap_crescente(&num1, &num2);

    printf("num1: %d\n", num1);
    printf("num2: %d\n\n", num2);

    return 0;
}*/

/*#include <stdio.h>

int num=12;

int soma(int idx);

int main() {
    printf("%d", soma(num));
    return 0;
}

int soma(int n){
    if (n == 0)
        return n;
    else
        return n+soma(n-3);
}*/

/*
#include <stdio.h>
int num=6;

int soma(int a, int b);

int main(void){
    printf("%d", soma(num, num-2));
    return 0;
}

int soma(int a, int b){
    if (a <=0 || b<=0)
        return 0;
    else
        return a+b+soma(a/2, b/2);
}*/

/*
#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente) {
    if (expoente == 0)
        return 1;

    return base * potencia(base, expoente - 1);
}

int main() {
    int base = 2, expoente = 2;
    printf("%d", potencia(base, expoente));
    return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int i) {
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;

    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main() {
    int i = 20;

    printf("%d", fibonacci(i));

    return 0;
}*/

/*
#include <stdio.h>
#include <stdlib.h>

int fat(int num) {
    if (num == 0) {
        return 0;
    }

    return num * fat(num - 1);
}

double somaSerie(int num) {
    if (num == 1)
        return 1.0;
    return ((double)fat(num)/num) + somaSerie(num - 1);
}

int main() {
    int num = 2 ;

    printf("%f", somaSerie(num));

    return 0;
}*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
#define polinomio(x) 2 * (x * x * x) + (x * x) + 3

void esfera(float r, float *area, float *volume)
{
    *area = 4 * PI * (r * r);
    *volume = (4.0 / 3.0) * PI * (r * r * r);
}

double pi(int n)
{
    int i = n;
    double valor_pi = 0;

    for (int i = 0; i < n; i++)
    {
        valor_pi += pow(-1, i) / (2.0 * (double)i + 1.0);
    }

    return 4 * valor_pi;
}

float altura_marte(float v_zero, float tempo_decorrido)
{
    return v_zero * tempo_decorrido - 4.9 * (tempo_decorrido * tempo_decorrido);
}

int main()
{
    float r = 5.0;
    int x = 2;
    float area, volume;
    float v_zero, tempo_decorrido;

    esfera(r, &area, &volume);
    printf("Area: %f\n", area);
    printf("Volume: %f\n", volume);

    printf("Polinomio: %d\n\n", polinomio(x));
    printf("Gravidade marte: %f", altura_marte(2.0, 2.0));

    return 0;
}*/

#include <stdio.h>

// Função para determinar o quadrante de um ponto (x, y)
int quadrante(float x, float y)
{
    if (x > 0 && y > 0)
        return 1; // Primeiro quadrante
    if (x < 0 && y > 0)
        return 2; // Segundo quadrante
    if (x < 0 && y < 0)
        return 3; // Terceiro quadrante
    if (x > 0 && y < 0)
        return 4; // Quarto quadrante
    return 0;     // Ponto está na origem ou em um dos eixos
}

int main()
{
    float x, y;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0; // Contadores para cada quadrante

    while (1)
    {
        // Recebe a entrada do usuário
        printf("Entrada: ");
        scanf("%f,%f", &x, &y);

        // Verifica se o ponto é a origem (0,0) para encerrar o programa
        if (x == 0 && y == 0)
            break;

        // Determina o quadrante do ponto e atualiza o contador correspondente
        int quad = quadrante(x, y);
        if (quad == 1)
            q1++;
        else if (quad == 2)
            q2++;
        else if (quad == 3)
            q3++;
        else if (quad == 4)
            q4++;

        // Exibe a quantidade de pontos em cada quadrante
        printf("Saída: %d %d %d %d\n", q1, q2, q3, q4);
    }

    return 0;
}
