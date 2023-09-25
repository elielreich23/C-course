#include <stdio.h>

    int negativos (float *vet, int n){
        int count = 0;


    for(int i = 0; i<n; i++){
            if(vet[i]<0){
            count++;
        }
    }
    return count;
}
int main (){

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    float vetor[n];
    printf("Digite os elementos do vetor: \n");
    for(int i = 0; i<n; i ++){
        scanf("%f", &vetor[i]);
    }

    int qtyNegativo = negativos(vetor, n);
    printf("numeros de numero negativo no vetor: %d\n", qtyNegativo);
   
    return 0;
}