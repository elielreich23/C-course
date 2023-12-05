#include <stdio.h>

int main() {
    int dias;
    float distanciaDiaria, custoCombustivel, mediaKmPorLitro, custoEstacionamento, gastosPedagio;

    printf("Calculadora de Despesa Diária de Transporte\n");

    // Solicita informações do usuário
    printf("Informe o total de quilômetros dirigidos por dia: ");
    scanf("%f", &distanciaDiaria);

    printf("Informe o custo por litro de combustível: ");
    scanf("%f", &custoCombustivel);

    printf("Informe a média de quilômetros por litro: ");
    scanf("%f", &mediaKmPorLitro);

    printf("Informe o preço de estacionamento por dia: ");
    scanf("%f", &custoEstacionamento);

    printf("Informe os gastos diários com pedágios: ");
    scanf("%f", &gastosPedagio);

    printf("Informe o número de dias para calcular os custos: ");
    scanf("%d", &dias);

    // Calcula e exibe os custos para cada dia
    printf("\nCustos Diários:\n");

    for (int dia = 1; dia <= dias; dia++) {
        float custoDiario = (distanciaDiaria / mediaKmPorLitro) * custoCombustivel + custoEstacionamento + gastosPedagio;

        printf("Dia %d: R$ %.2f\n", dia, custoDiario);
    }

    return 0;
}
