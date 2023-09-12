#include <stdio.h>

int main (void) {
int n1, n2, aux, fatorial = 1, i;

printf("Digite o primeiro valor: ");
scanf("%d", &n1);

printf("Digite o segundo valor: ");
scanf("%d", &n2);

if (n1>n2) {
    aux = n1;
    n1 = n2;
    n2 = aux;
} 
 printf ("Os valores são n1: %d e n2: %d", n1, n2);

for(i=1; i>=n1 && i<=n2; i++) {
fatorial = fatorial * n;
printf("\nO fatorial de %d é %d", n, fatorial);
}

return 0;
}