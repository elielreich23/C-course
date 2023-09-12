#include <stdio.h>

void MinEMax(int *V, int n, int *min, int *max) {
    if (n <= 0) {
        printf("O vetor está vazio ou possui tamanho inválido.\n");
        return;
    }

    *min = *max = V[0]; // Inicializa min e max com o primeiro elemento do vetor.

    for (int i = 1; i < n; i++) {
        if (V[i] < *min) {
            *min = V[i]; // Atualiza o valor mínimo.
        }
        if (V[i] > *max) {
            *max = V[i]; // Atualiza o valor máximo.
        }
    }
}

int main() {
    int vetor[] = {5, 2, 15, 3, 7, 8, 6, 12};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int minimo, maximo;

    MinEMax(vetor, tamanho, &minimo, &maximo);

    printf("Valor mínimo: %d\n", minimo);
    printf("Valor máximo: %d\n", maximo);

    return 0;
}
