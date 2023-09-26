#include <stdio.h>

int main () {
    int imc = 0, peso = 0, altura = 0;

    do{
        printf("Digite seu peso em quilogramas:\n");
        scanf("%d", &peso);
        if (peso<= 0)
        {
            printf("Digite um numero a cima de 0. Digite de novo");
        }
    }while(peso<=0)
    do
    {
        printf("Digite sua altura em metros:\n");
        scanf("%d", &altura);
        if (altura<= 0)
        {
            printf("Digite um numero a cima de 0. Digite de novo");
        }
    } while (altura<=0);
    
}