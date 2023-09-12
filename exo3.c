#include <stdio.h>

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n]; // Declaração de um vetor com n elementos

    // Leitura dos valores do vetor usando aritmética de ponteiros
    int *ptr = vetor; // Inicializa um ponteiro apontando para o início do vetor
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i); // Lê valores diretamente nas posições do vetor usando aritmética de ponteiros
    }

    // Cálculo do dobro de cada valor e impressão dos resultados
    ptr = vetor; // Reinicializa o ponteiro para o início do vetor
    printf("O dobro dos valores lidos é:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", 2 * *(ptr + i)); 
    }
    printf("\n");

    return 0;
}
