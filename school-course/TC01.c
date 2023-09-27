// exo 1
/*#include <stdio.h>
int main() {
    int n;

    do
    {
    printf("Digite um numero positivo:\n");
    scanf("%d", &n);
        if (n<=0){
            printf("digite um numero positivo");
        } 
    } while (n<=0);
    printf(">> %d", n);

    for ( int i = n - 1; i>= 1 ; i--)
    {
        if (i % 4 == 0)
        {
            printf(" [%d]", i);
        }
        // else if (i % 2 == 0){
            //printf(" [%d]", i);
       // }
        
        else
        {
            printf("d", i);
        }
    }
    
    return 0;
}*/

//exo 2
#include <stdio.h>

int calcularFatorial(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * calcularFatorial(num - 1);
}

int main() {
    int n1, n2;

    // Solicita ao usuário n1 e n2 até que n2 seja maior que n1
    do {
        printf("Digite um valor inteiro positivo para n1: ");
        scanf("%d", &n1);

        printf("Digite um valor inteiro positivo maior que n1 para n2: ");
        scanf("%d", &n2);

        if (n2 <= n1) {
            printf("n2 deve ser maior que n1. Tente novamente.\n");
        }
    } while (n2 <= n1);

    printf("Fatoriais no intervalo de %d a %d:\n", n1, n2);

    for (int i = n1; i <= n2; i++) {
        int fatorial = calcularFatorial(i);
        printf("%d! = %d\n", i, fatorial);
    }

    return 0;
}


// exo 3
/**#include <stdio.h>
int main(){
    int n, valor, positivo = 0, negativo = 0, somaPos = 0, somaNeg = 0;
    printf("Digite o tamanho de valor que deseja inserir: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("digite o valor %d", i + 1);
        scanf("%d", &valor);
    if (valor > 0){
        positivo ++;
        somaPos += valor;
    }else if (valor < 0){
        negativo ++;
        somaNeg += valor;
    }
    }
printf("Quantidade de valores positivos: %d\n", positivos);
    printf("Quantidade de valores negativos: %d\n", negativos);
    printf("Soma dos valores positivos: %d\n", somaPositivos);
    printf("Soma dos valores negativos: %d\n", somaNegativos);

    return 0;


}**/
