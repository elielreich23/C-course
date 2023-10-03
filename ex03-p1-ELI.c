#include <stdio.h>
#include <stdlib.h>

int* lerVetor(int n) {
    int* vetor = (int*)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    printf("Digite os elementos do vetor (%d elementos):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    return vetor;
}

int* somarPares(int* vetor1, int* vetor2, int n, int m, int* tamResult) {
    int tamanhoMin = n < m ? n : m; 
    *tamResult = tamanhoMin / 2; 
    int* result = (int*)malloc(*tamResult * sizeof(int));
    if (result == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    for (int i = 0; i < *tamResult; i++) {
        result[i] = vetor1[2 * i] + vetor2[2 * i];
    }

    return result;
}

int main() {
    int n, m;
    int tamResult;

    printf("Digite o tamanho do vetor R: ");
    scanf("%d", &n);

    int* vetorR = lerVetor(n);

    printf("Digite o tamanho do vetor S: ");
    scanf("%d", &m);

    int* vetorS = lerVetor(m);

    int* vetorX = somarPares(vetorR, vetorS, n, m, &tamResult);

    printf("Resultado da soma dos elementos pares:\n");
    for (int i = 0; i < tamResult; i++) {
        printf("%d ", vetorX[i]);
    }
    printf("\n");

    free(vetorR);
    free(vetorS);
    free(vetorX);

    return 0;
}
