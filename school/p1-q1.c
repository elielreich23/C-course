#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 250
#define MAX_CPF_LENGTH 12

typedef struct {
    char nome[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    int relacao;  // 0: cônjuge, 1: filho(a)/enteado(a), 2: mãe, 3: pai
} Dependente;

typedef struct {
    char nome[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    int numero_dependentes;
    int ano_admissao;
    int estado_civil;  // 0: solteiro, 1: casado/união estável, 2: divorciado, 3: viúvo
    Dependente* dependentes;
} Funcionario;

typedef struct {
    Funcionario* funcionarios;
    int num_funcionarios;
} Empresa;

void inicializarEmpresa(Empresa* empresa) {
    empresa->funcionarios = NULL;
    empresa->num_funcionarios = 0;
}

void adicionarFuncionario(Empresa* empresa, Funcionario funcionario) {
    empresa->num_funcionarios++;
    empresa->funcionarios = realloc(empresa->funcionarios, empresa->num_funcionarios * sizeof(Funcionario));
    empresa->funcionarios[empresa->num_funcionarios - 1] = funcionario;
}

Funcionario criarFuncionario() {
    Funcionario funcionario;

    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, MAX_NAME_LENGTH, stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0'; // Remove newline character

    printf("Digite o CPF do funcionário: ");
    fgets(funcionario.cpf, MAX_CPF_LENGTH, stdin);
    funcionario.cpf[strcspn(funcionario.cpf, "\n")] = '\0'; // Remove newline character

    printf("Digite o ano de admissão: ");
    scanf("%d", &funcionario.ano_admissao);

    printf("Digite o estado civil (0: solteiro, 1: casado/união estável, 2: divorciado, 3: viúvo): ");
    scanf("%d", &funcionario.estado_civil);

    funcionario.numero_dependentes = 0;
    funcionario.dependentes = NULL;

    // Limpar o buffer do teclado
    getchar();

    return funcionario;
}

void adicionarDependente(Funcionario* funcionario) {
    Dependente dependente;

    printf("Digite o nome do dependente: ");
    fgets(dependente.nome, MAX_NAME_LENGTH, stdin);
    dependente.nome[strcspn(dependente.nome, "\n")] = '\0'; // Remove newline character

    printf("Digite o CPF do dependente: ");
    fgets(dependente.cpf, MAX_CPF_LENGTH, stdin);
    dependente.cpf[strcspn(dependente.cpf, "\n")] = '\0'; // Remove newline character

    printf("Digite a relação (0: cônjuge, 1: filho(a)/enteado(a), 2: mãe, 3: pai): ");
    scanf("%d", &dependente.relacao);

    // Limpar o buffer do teclado
    getchar();

    funcionario->numero_dependentes++;
    funcionario->dependentes = realloc(funcionario->dependentes, funcionario->numero_dependentes * sizeof(Dependente));
    funcionario->dependentes[funcionario->numero_dependentes - 1] = dependente;
}

void exibirFuncionario(Funcionario funcionario) {
    printf("Nome: %s\n", funcionario.nome);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Ano de Admissão: %d\n", funcionario.ano_admissao);
    printf("Estado Civil: %d\n", funcionario.estado_civil);
    printf("Número de Dependentes: %d\n", funcionario.numero_dependentes);

    for (int i = 0; i < funcionario.numero_dependentes; i++) {
        printf("  Dependente %d:\n", i + 1);
        printf("    Nome: %s\n", funcionario.dependentes[i].nome);
        printf("    CPF: %s\n", funcionario.dependentes[i].cpf);
        printf("    Relação: %d\n", funcionario.dependentes[i].relacao);
    }
}

void exibirEmpresa(Empresa empresa) {
    printf("Número de Funcionários: %d\n", empresa.num_funcionarios);
    for (int i = 0; i < empresa.num_funcionarios; i++) {
        printf("Funcionário %d:\n", i + 1);
        exibirFuncionario(empresa.funcionarios[i]);
        printf("\n");
    }
}

int main() {
    Empresa empresa;
    inicializarEmpresa(&empresa);

    int opcao;
    do {
        printf("1. Adicionar Funcionário\n");
        printf("2. Adicionar Dependente a Funcionário\n");
        printf("3. Exibir Funcionários\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar o buffer do teclado
        getchar();

        if (opcao == 1) {
            Funcionario novo_funcionario = criarFuncionario();
            adicionarFuncionario(&empresa, novo_funcionario);
        } else if (opcao == 2) {
            if (empresa.num_funcionarios == 0) {
                printf("Nenhum funcionário cadastrado.\n");
            } else {
                int indice;
                printf("Digite o índice do funcionário (1 a %d): ", empresa.num_funcionarios);
                scanf("%d", &indice);

                // Limpar o buffer do teclado
                getchar();

                if (indice >= 1 && indice <= empresa.num_funcionarios) {
                    adicionarDependente(&empresa.funcionarios[indice - 1]);
                } else {
                    printf("Índice inválido.\n");
                }
            }
        } else if (opcao == 3) {
            exibirEmpresa(empresa);
        }
    } while (opcao != 4);

    // Liberar memória alocada
    for (int i = 0; i < empresa.num_funcionarios; i++) {
        free(empresa.funcionarios[i].dependentes);
    }
    free(empresa.funcionarios);

    return 0;
}
