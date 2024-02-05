#include <stdio.h>
#include <stdlib.h>

int main(void) {

  /*
  char A = 0b00001111;
  char B = 0b11110000;
  char C = 0b11111111;

  C = A | B;
  A = !C;
  
  printf("%d\n", (unsigned char)C);
  printf("%d\n", (unsigned char)A);

  //printf("%d %g\n", 33, 5.3);
  printf("%d %e\n", 33, 5.3E0);
  */

  //Programa para converter altura para pés e polegadas:
  int pes;
  float polegadas;
  float altura;

  printf("Digite a sua altura (metros):");
  scanf("%f", &altura);

  //converter para cm:
  altura = 100*altura;

  //converter altura para pes:
  pes = (int) (altura/30.48);

  //converter o restante para polegadas:
  polegadas = (altura - pes*30.48) / 2.54;

  printf("Sua altura: %dft e %.1fpol\n", pes, polegadas);

  
  return 0;
}