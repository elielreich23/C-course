#include <stdio.h>

int main() {
    int vect[5] = {1, 2, 3, 4, 5}; // Vetor de inteiros
    int *int_pointer = vect;         // Ponteiro associado ao vetor

    printf("Vetor original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vect[i]);
    }
    printf("\n");

    // Usando o int_pointer para incrementar cada elemento do vetor em 1
    for (int i = 0; i < 5; i++) {
        (*int_pointer)++; // Incrementa o valor apontado pelo int_pointer em 1
        int_pointer++;    // Move o int_pointer para a próxima posição do vetor
    }

    printf("Vetor modificado: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vect[i]);
    }
    printf("\n");

    return 0;
}
