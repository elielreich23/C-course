#include <stdio.h>

// Função para ler um valor maior que zero
float lerValorMaiorQueZero(const char *mensagem) {
    float valor;
    do {
        printf("%s", mensagem);
        scanf("%f", &valor);
    } while (valor <= 0);
    return valor;
}

// Função para calcular o IMC
float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

int main() {
    float peso, altura, imc;

    peso = lerValorMaiorQueZero("Digite o seu peso em quilogramas (deve ser maior que zero): ");
    altura = lerValorMaiorQueZero("Digite a sua altura em metros (deve ser maior que zero): ");

    imc = calcularIMC(peso, altura);

    printf("Valor do IMC: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Abaixo do peso: menor que 18.5\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Normal: entre 18.5 e 24.9\n");
    } else if (imc >= 25 && imc <= 29.9) {
        printf("Acima do peso: entre 25 e 29.9\n");
    } else {
        printf("Obeso: 30 ou mais\n");
    }

    return 0;
}
