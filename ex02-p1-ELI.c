#include <stdio.h>
#include <stdlib.h>

int main() {
    int tam;
    
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tam);

    double *vet1 = (double *)malloc(tam * sizeof(double));
    double *vet2 = (double *)malloc(tam * sizeof(double));

    if (vet1 == NULL || vet2 == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os elementos do primeiro vetor:\n");
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%lf", &vet1[i]);
    }

    printf("Digite os elementos do segundo vetor:\n");
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%lf", &vet2[i]);
    }

    double *result = (double *)malloc(tam * sizeof(double));

    if (result == NULL) {
        printf("Erro na alocação de memória para o result.\n");
        free(vet1);
        free(vet2);
        return 1;
    }

    for (int i = 0; i < tam; i++) {
        result[i] = vet1[i] + vet2[i];
    }


    printf("Resultado da soma dos vetores:\n");
    for (int i = 0; i < tam; i++) {
        printf("%.2lf, ", result[i]);
    }
    printf("\n");

    free(vet1);
    free(vet2);
    free(result);

    return 0;
}