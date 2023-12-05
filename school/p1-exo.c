#include <stdio.h>
#include <stdlib.h>

// Função para ler um vetor de tamanho n
double* lerVetor(int n) {
    double* vetor = (double*)malloc(n * sizeof(double));
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    printf("Digite os elementos do vetor (%d elementos):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }

    return vetor;
}

// Função para somar dois vetores e retornar o resultado
double* somarVetores(double* vetor1, double* vetor2, int n) {
    double* resultado = (double*)malloc(n * sizeof(double));
    if (resultado == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        resultado[i] = vetor1[i] + vetor2[i];
    }

    return resultado;
}

int main() {
    int n;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    double* vetor1 = lerVetor(n);
    double* vetor2 = lerVetor(n);

    double* resultado = somarVetores(vetor1, vetor2, n);

    printf("Resultado da soma dos vetores:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", resultado[i]);
    }
    printf("\n");

    // Liberar a memória alocada
    free(vetor1);
    free(vetor2);
    free(resultado);

    return 0;
