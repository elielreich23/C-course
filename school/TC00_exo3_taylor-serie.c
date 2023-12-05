#include <stdio.h>
#include <math.h>

// Função para calcular o fatorial
int fatorial(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * fatorial(num - 1);
}

// Função para calcular a Série de Taylor para e^x
double calcularTaylor(double x, int n) {
    static int i = 0; // Variável estática para acompanhar o número de termos calculados

    if (i == n) {
        return 1.0; // Condição de parada da recursão
    }

    // Cálculo do termo atual da série
    double termo = (pow(x, i) / fatorial(i));

    // Incrementa o contador de termos calculados
    i++;

    // Chamada recursiva para o próximo termo
    double proximoTermo = calcularTaylor(x, n);

    // Soma do termo atual com o próximo termo
    return termo + proximoTermo;
}

int main() {
    double x;
    int n;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    printf("Digite o número de termos (n): ");
    scanf("%d", &n);

    double resultado = calcularTaylor(x, n);

    printf("e^%.2lf (aproximado) = %.6lf\n", x, resultado);

    return 0;
}
