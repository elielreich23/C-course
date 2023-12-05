#include <stdio.h>

int somaVetores(int *vect1, int *vect2, int *result, int tam1, int tam2) {
  
    if (tam1 != tam2) {
        return 0; 
    }

    for (int i = 0; i < tam1; i++) {
        result[i] = vect1[i] + vect2[i];
    }

    return 1; 
}
int main() {
    int vect1[] = {4, 2, 3, 9, 6};
    int vect2[] = {5, 7, 5, 2, 1};
    int tam1 = sizeof(vect1) / sizeof(int);
    int tam2 = sizeof(vect2) / sizeof(int);

    if (tam1 != tam2) {
        printf("Os tamanhos dos vetores são diferentes. Não é possível realizar a soma.\n");
        return 1;
    }

    int result[tam1];

    int resultOperacao = somaVetores(vect1, vect2, result, tam1, tam2);

    if (resultOperacao == 1) {
        printf("Soma dos vetores: ");
        for (int i = 0; i < tam1; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("Erro desconhecido.\n");
    }

    return 0;
}