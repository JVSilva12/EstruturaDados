#include <stdio.h>

int main() {
    // char A = 0b00001111;
    // char B = 0b11110000;
    // char C = 0b11111111;

    // C = A | B;
    // A = !C; 

    // printf("%d\n", (unsigned char)C);
    // printf("%d\n", (unsigned char)A);

    // printf("%d %g\n\n", 5300, 5.3E0);

    float A;
    unsigned char PE = 0, POL = 0;

    printf("Digite altura em metros: ");
    scanf("%f", &A);

    PE = A / 0.3048;
    
    // printf("Você mede %df")
    return 0;
}