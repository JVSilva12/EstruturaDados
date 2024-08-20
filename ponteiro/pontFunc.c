#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 5, y = 10;

    printf("Antes de mudar: %d %d\n", x, y);
    swap(&x, &y);
    printf("Depois de mudar: %d %d\n\n", x, y);

    return 0;
}