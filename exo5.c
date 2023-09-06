#include <stdio.h>

void maiorOccorencias(const int vetor[], int n) {
    if (n <= 0) {
        printf("O vetor está vazio ou possui tamanho inválido.\n");
        return;
    }

    int maior = vetor[0]; // Assumimos que o primeiro elemento é o maior.
    int ocorrencias = 1; // Inicializamos o contador com 1 para contar a primeira ocorrência.

    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            ocorrencias = 1; // Resetamos o contador para contar o novo maior elemento.
        } else if (vetor[i] == maior) {
            ocorrencias++;
        }
    }

    printf("Maior elemento: %d => %d vezes\n", maior, ocorrencias);
}

int main() {
    int vetor[] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    maiorOccorencias(vetor, tamanho);

    return 0;
}
