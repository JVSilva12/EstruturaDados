#include <stdio.h>
#include <stdlib.h>

void ola();
float pi();
void soma(int A, int B);
float mult(int A, int B);
int fatorial(int n);

int main() {
    ola();  
    printf("Pi: %.4f\n\n", pi());
    soma((int)pi(), 4);
    printf("Multiplicacao de %d por %d: %.0f\n\n",4 , 5, mult(4, 5));
    printf("Fatorial de %d: %d\n\n", 5, fatorial(5));

    return 0;
}

void ola() {
    printf("Helo world!!\n\n");
}

float pi() {
    return 3.1415;
}

void soma(int A, int B) {
    printf("Soma de %d + %d = %d\n\n", A, B, A + B);
}

float mult(int A, int B) {
    return A * B;
}

int fatorial(int i) {
    int fat = 1;
    if (i <= 0) 
        return 1;
    return i * fatorial(i - 1);
}