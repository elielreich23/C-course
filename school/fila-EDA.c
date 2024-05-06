#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cpf[12];
} Pessoa;

typedef struct {
    int max;
    int total;
    Pessoa *item;
} FilaStruct;

typedef FilaStruct* Fila;

Fila fila(int m) {
    Fila F = malloc(sizeof(FilaStruct));
    if (F == NULL) {
        perror("Erro ao alocar memória para a fila.");
        exit(EXIT_FAILURE);
    }
    F->max = m;
    F->total = 0;
    F->item = malloc(m * sizeof(Pessoa));
    if (F->item == NULL) {
        perror("Erro ao alocar memória para os itens da fila.");
        free(F);
        exit(EXIT_FAILURE);
    }
    return F;
}

int vaziaf(Fila F) {
    return (F->total == 0);
}

int cheia(Fila F) {
    return (F->total == F->max);
}

void enfileira(char nome[], char cpf[], Fila F) {
    if (cheia(F)) {
        printf("A fila está cheia. Não é possível adicionar mais pessoas.\n");
    } else {
        strcpy(F->item[F->total].nome, nome);
        strcpy(F->item[F->total].cpf, cpf);
        F->total++;
    }
}

Pessoa desenfileira(Fila F) {
    if (vaziaf(F)) {
        perror("A fila está vazia.");
        exit(EXIT_FAILURE);
    }
    Pessoa p = F->item[0];
    for (int i = 1; i < F->total; i++) {
        strcpy(F->item[i - 1].nome, F->item[i].nome);
        strcpy(F->item[i - 1].cpf, F->item[i].cpf);
    }
    F->total--;
    return p;
}

Pessoa desenfileiraPorIndice(int indice, Fila F) {
    if (vaziaf(F)) {
        perror("A fila está vazia.");
        exit(EXIT_FAILURE);
    }
    if (indice < 0 || indice >= F->total) {
        printf("Índice inválido. Escolha um índice válido.\n");
        exit(EXIT_FAILURE);
    }
    Pessoa p = F->item[indice];
    for (int i = indice; i < F->total - 1; i++) {
        strcpy(F->item[i].nome, F->item[i + 1].nome);
        strcpy(F->item[i].cpf, F->item[i + 1].cpf);
    }
    F->total--;
    return p;
}

void destruirfila(Fila *G) {
    free((*G)->item);
    free(*G);
    *G = NULL;
}

void mostrarFila(Fila F) {
    if (vaziaf(F)) {
        puts("A fila está vazia.");
        return;
    }

    printf("Pessoas na fila:\n");
    for (int i = 0; i < F->total; i++) {
        printf("%d. Nome: %s, CPF: %s\n", i + 1, F->item[i].nome, F->item[i].cpf);
    }
}

int main() {
    int tamanho_fila;
    printf("Digite o tamanho máximo da fila: ");
    scanf("%d", &tamanho_fila);

    Fila f = fila(tamanho_fila);
    char nome[50];
    char cpf[12];
    int opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir pessoa\n");
        printf("2. Deletar pessoa por índice\n");
        printf("3. Visualizar fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome da pessoa: ");
                scanf("%s", nome);
                printf("CPF da pessoa: ");
                scanf("%s", cpf);
                enfileira(nome, cpf, f);
                break;
            case 2:
                if (!vaziaf(f)) {
                    mostrarFila(f);
                    int indice;
                    printf("Digite o índice da pessoa que deseja remover: ");
                    scanf("%d", &indice);
                    Pessoa removida = desenfileiraPorIndice(indice - 1, f);
                    printf("Pessoa removida: Nome: %s, CPF: %s\n", removida.nome, removida.cpf);
                } else {
                    printf("A fila está vazia. Nenhuma pessoa para remover.\n");
                }
                break;
            case 3:
                mostrarFila(f);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                destruirfila(&f);
                return 0;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    }

    return 0;
}