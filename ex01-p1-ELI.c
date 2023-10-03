#include <stdio.h>

void minMax(int *v, int tam, int *min, int *max) {
    if (tam <= 0) {
        printf("Vetor vazio.\n");
        return;
    }

    *min = v[0]; 
    *max = v[0];

    for (int i = 1; i < tam; i++) {
        if (v[i] < *min) {
            *min = v[i]; 
        } else if (v[i] > *max) {
            *max = v[i];
        }
    }
}

int main() {
    int vetor[] = {8, 9, 10, 10, 3};
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    int minimo, maximo;

    minMax(vetor, tam, &minimo, &maximo);

    printf("Vetor: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("O Valor mínimo do vetor é: %d\n", minimo);
    printf("O Valor maximo do vetor é: %d\n", maximo);

    return 0;
}
