#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char endereco[50];
    char dataNascimento[11]; //DD/MM/AAAA
    float salario;
    char cargo[20];
} Individuo;

void adicionarIndividuo(Individuo **lista, int *numIndividuos) {
    Individuo pessoa;

    printf("Nome: ");
    scanf("%s", pessoa.nome);

    printf("Endereco: ");
    scanf("%s", pessoa.endereco);

    printf("Data de Nascimento (DD/MM/AAAA): ");
    scanf("%s", pessoa.dataNascimento);

    printf("Salario: ");
    scanf("%f", &pessoa.salario);

    printf("Cargo: ");
    scanf("%s", pessoa.cargo);

    *lista = realloc(*lista, (*numIndividuos + 1) * sizeof(Individuo));

    (*lista)[*numIndividuos] = pessoa;
    (*numIndividuos)++;
}

void removerIndividuo(Individuo **lista, int *numIndividuos) {
    int indice;

    printf("Digite o índice da pessoa a ser removida: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < *numIndividuos) {
        for (int i = indice; i < *numIndividuos - 1; i++) {
            (*lista)[i] = (*lista)[i + 1];
        }

        *lista = realloc(*lista, (*numIndividuos - 1) * sizeof(Individuo));

        (*numIndividuos)--;
        printf("Pessoa removida com sucesso.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

void buscarMaioresSalarios(Individuo *lista, int numIndividuos) {
    
}

int main() {
    Individuo *lista = NULL;
    int numIndividuos = 0;
    int escolha;

    do {
        printf("\n1. Adicionar indivíduo\n");
        printf("2. Remover indivíduo\n");
        printf("3. Buscar 3 maiores salários por faixa etária\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarIndividuo(&lista, &numIndividuos);
                break;
            case 2:
                removerIndividuo(&lista, &numIndividuos);
                break;
            case 3:
                buscarMaioresSalarios(lista, numIndividuos);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    free(lista);

    return 0;
}
