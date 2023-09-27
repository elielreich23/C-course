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
