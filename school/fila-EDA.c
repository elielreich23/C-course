#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char cpf[12];
} Pessoa;

typedef struct {
    int tamanhoMaximo;
    int total;
    Pessoa *itens;
} FilaEstrutura;

typedef FilaEstrutura* Fila;

Fila criarFila(int tamanhoMaximo) {
    Fila F = malloc(sizeof(FilaEstrutura));
    if (F == NULL) {
        perror("Erro ao alocar memória para a fila.");
        exit(EXIT_FAILURE);
    }
    F->tamanhoMaximo = tamanhoMaximo;
    F->total = 0;
    F->itens = malloc(tamanhoMaximo * sizeof(Pessoa));
    if (F->itens == NULL) {
        perror("Erro ao alocar memória para os itens da fila.");
        free(F);
        exit(EXIT_FAILURE);
    }
    return F;
}

int filaVazia(Fila F) {
    return (F->total == 0);
}

int filaCheia(Fila F) {
    return (F->total == F->tamanhoMaximo);
}

void enfileirarPessoa(char nome[], char cpf[], Fila F) {
    if (filaCheia(F)) {
        printf("A fila está cheia. Não é possível adicionar mais pessoas.\n");
    } else {
        strcpy(F->itens[F->total].nome, nome);
        strcpy(F->itens[F->total].cpf, cpf);
        F->total++;
    }
}

Pessoa desenfileirarPessoa(Fila F) {
    if (filaVazia(F)) {
        perror("A fila está vazia.");
        exit(EXIT_FAILURE);
    }
    Pessoa p = F->itens[0];
    for (int i = 1; i < F->total; i++) {
        strcpy(F->itens[i - 1].nome, F->itens[i].nome);
        strcpy(F->itens[i - 1].cpf, F->itens[i].cpf);
    }
    F->total--;
    return p;
}

Pessoa desenfileirarPessoaPorIndice(int indice, Fila F) {
    if (filaVazia(F)) {
        perror("A fila está vazia.");
        exit(EXIT_FAILURE);
    }
    if (indice < 0 || indice >= F->total) {
        printf("Índice inválido. Escolha um índice válido.\n");
        exit(EXIT_FAILURE);
    }
    Pessoa p = F->itens[indice];
    for (int i = indice; i < F->total - 1; i++) {
        strcpy(F->itens[i].nome, F->itens[i + 1].nome);
        strcpy(F->itens[i].cpf, F->itens[i + 1].cpf);
    }
    F->total--;
    return p;
}

void destruirFila(Fila *F) {
    free((*F)->itens);
    free(*F);
    *F = NULL;
}

void mostrarFila(Fila F) {
    if (filaVazia(F)) {
        puts("A fila está vazia.");
        return;
    }

    printf("Pessoas na fila:\n");
    for (int i = 0; i < F->total; i++) {
        printf("%d. Nome: %s, CPF: %s\n", i + 1, F->itens[i].nome, F->itens[i].cpf);
    }
}

int main() {
    int tamanhoMaximoFila;
    printf("Digite o tamanho máximo da fila: ");
    scanf("%d", &tamanhoMaximoFila);

    Fila filaPessoas = criarFila(tamanhoMaximoFila);
    char nome[50];
    char cpf[12];
    int opcao;

    while (1) {
        printf("\nMenu:\n");
       printf("1. Inserir pessoa\n");
        printf("2. Deletar pessoa\n");
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
                enfileirarPessoa(nome, cpf, filaPessoas);
                break;
            case 2:
                if (!filaVazia(filaPessoas)) {
                    mostrarFila(filaPessoas);
                    int indice;
                    printf("Digite o índice da pessoa que deseja remover: ");
                    scanf("%d", &indice);
                    Pessoa pessoaRemovida = desenfileirarPessoaPorIndice(indice - 1, filaPessoas);
                    printf("Pessoa removida: Nome: %s, CPF: %s\n", pessoaRemovida.nome, pessoaRemovida.cpf);
                } else {
                    printf("A fila está vazia. Nenhuma pessoa para remover.\n");
                }
                break;
            case 3:
                mostrarFila(filaPessoas);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                destruirFila(&filaPessoas);
                return 0;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    }

    return 0;
}
