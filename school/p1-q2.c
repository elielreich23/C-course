#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes para tamanhos máximos de strings
#define MAX_NAME_LENGTH 250
#define MAX_CPF_LENGTH 12
#define MAX_RELATION_LENGTH 50

// Estrutura para representar um dependente
typedef struct {
    char nome[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char relacao[MAX_RELATION_LENGTH];
} Dependente;

// Estrutura para representar um funcionário
typedef struct {
    char nome[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    int numero_dependentes;
    int ano_admissao;
    Dependente* dependentes;
} Funcionario;

// Estrutura para representar uma empresa
typedef struct {
    Funcionario* funcionarios;
    int num_funcionarios;
} Empresa;

// Função para inicializar a empresa
void inicializarEmpresa(Empresa* empresa) {
    empresa->funcionarios = NULL;
    empresa->num_funcionarios = 0;
}

// Função para adicionar um funcionário à empresa
void adicionarFuncionario(Empresa* empresa, Funcionario funcionario) {
    empresa->num_funcionarios++;
    empresa->funcionarios = realloc(empresa->funcionarios, empresa->num_funcionarios * sizeof(Funcionario));
    empresa->funcionarios[empresa->num_funcionarios - 1] = funcionario;
}

// Função para criar um novo funcionário
Funcionario criarFuncionario() {
    Funcionario funcionario;

    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, MAX_NAME_LENGTH, stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o CPF do funcionário: ");
    fgets(funcionario.cpf, MAX_CPF_LENGTH, stdin);
    funcionario.cpf[strcspn(funcionario.cpf, "\n")] = '\0'; // Remove o caractere de nova linha

    // Validação do ano de admissão
    do {
        printf("Digite o ano de admissão (ano deve ser maior que 1900 e menor ou igual ao ano atual): ");
        scanf("%d", &funcionario.ano_admissao);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        if (funcionario.ano_admissao <= 1900 || funcionario.ano_admissao > 2024) {
            printf("Ano inválido. Por favor, tente novamente.\n");
        }
    } while (funcionario.ano_admissao <= 1900 || funcionario.ano_admissao > 2024);

    funcionario.numero_dependentes = 0;
    funcionario.dependentes = NULL;

    return funcionario;
}

// Função para adicionar um dependente a um funcionário da empresa
void adicionarDependente(Empresa* empresa) {
    if (empresa->num_funcionarios == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    int indice, num_dependentes;

    printf("Digite o índice do funcionário (1 a %d): ", empresa->num_funcionarios);
    scanf("%d", &indice);

    while (getchar() != '\n'); // Limpa o buffer de entrada

    if (indice < 1 || indice > empresa->num_funcionarios) {
        printf("Índice inválido.\n");
        return;
    }

    Funcionario* funcionario = &empresa->funcionarios[indice - 1];

    printf("Digite o número de dependentes que deseja registrar: ");
    scanf("%d", &num_dependentes);

    while (getchar() != '\n'); // Limpa o buffer de entrada

    for (int i = 0; i < num_dependentes; i++) {
        Dependente dependente;

        printf("Digite o nome do dependente: ");
        fgets(dependente.nome, MAX_NAME_LENGTH, stdin);
        dependente.nome[strcspn(dependente.nome, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Digite o CPF do dependente: ");
        fgets(dependente.cpf, MAX_CPF_LENGTH, stdin);
        dependente.cpf[strcspn(dependente.cpf, "\n")] = '\0'; // Remove o caractere de nova linha

        int relacao_opcao;
        // Menu para selecionar a relação do dependente com o funcionário
        do {
            printf("Escolha a relação do dependente com o funcionário:\n");
            printf("1. Cônjuge\n");
            printf("2. Filho(a)/Enteado(a)\n");
            printf("3. Mãe\n");
            printf("4. Pai\n");
            printf("Escolha uma opção (1-4): ");
            scanf("%d", &relacao_opcao);
            while (getchar() != '\n'); // Limpa o buffer de entrada

            switch (relacao_opcao) {
                case 1:
                    strcpy(dependente.relacao, "Cônjuge");
                    break;
                case 2:
                    strcpy(dependente.relacao, "Filho(a)/Enteado(a)");
                    break;
                case 3:
                    strcpy(dependente.relacao, "Mãe");
                    break;
                case 4:
                    strcpy(dependente.relacao, "Pai");
                    break;
                default:
                    printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            }
        } while (relacao_opcao < 1 || relacao_opcao > 4);

        funcionario->numero_dependentes++;
        funcionario->dependentes = realloc(funcionario->dependentes, funcionario->numero_dependentes * sizeof(Dependente));
        funcionario->dependentes[funcionario->numero_dependentes - 1] = dependente;
    }
}

// Função para exibir as informações de um funcionário
void exibirFuncionario(Funcionario funcionario) {
    printf("Nome: %s\n", funcionario.nome);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Ano de Admissão: %d\n", funcionario.ano_admissao);
    printf("Número de Dependentes: %d\n", funcionario.numero_dependentes);

    for (int i = 0; i < funcionario.numero_dependentes; i++) {
        printf("  Dependente %d:\n", i + 1);
        printf("    Nome: %s\n", funcionario.dependentes[i].nome);
        printf("    CPF: %s\n", funcionario.dependentes[i].cpf);
        printf("    Relação: %s\n", funcionario.dependentes[i].relacao);
    }
}

// Função para exibir as informações de todos os funcionários da empresa
void exibirEmpresa(Empresa empresa) {
    printf("Número de Funcionários: %d\n", empresa.num_funcionarios);
    for (int i = 0; i < empresa.num_funcionarios; i++) {
        printf("Funcionário %d:\n", i + 1);
        exibirFuncionario(empresa.funcionarios[i]);
        printf("\n");
    }
}

// Função para salvar os dados dos funcionários em um arquivo
void salvarFuncionarios(Empresa empresa) {
    FILE *arquivo = fopen("funcionarios.txt", "a"); // Abrir em modo de append para não perder dados

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return;
    }

    for (int i = 0; i < empresa.num_funcionarios; i++) {
        Funcionario funcionario = empresa.funcionarios[i];
        fprintf(arquivo, "%s,%s,%d,%d\n", funcionario.nome, funcionario.cpf, funcionario.ano_admissao, funcionario.numero_dependentes);
    }

    fclose(arquivo);
}

// Função para salvar os dados dos dependentes em um arquivo
void salvarDependentes(Empresa empresa) {
    FILE *arquivo = fopen("dependentes.txt", "a"); // Abrir em modo de append para não perder dados

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dependentes.\n");
        return;
    }

    for (int i = 0; i < empresa.num_funcionarios; i++) {
        Funcionario funcionario = empresa.funcionarios[i];
        for (int j = 0; j < funcionario.numero_dependentes; j++) {
            Dependente dependente = funcionario.dependentes[j];
            fprintf(arquivo, "%s,%s,%s,%s\n", funcionario.cpf, dependente.nome, dependente.cpf, dependente.relacao);
        }
    }

    fclose(arquivo);
}

// Função principal
int main() {
    Empresa empresa;
    inicializarEmpresa(&empresa);

    int opcao;
    do {
        printf("1. Adicionar Funcionário\n");
        printf("2. Adicionar Dependente a Funcionário\n");
        printf("3. Exibir Funcionários\n");
        printf("4. Salvar Dados\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        while (getchar() != '\n'); // Limpa o buffer de entrada

        if (opcao == 1) {
            Funcionario novo_funcionario = criarFuncionario();
            adicionarFuncionario(&empresa, novo_funcionario);
        } else if (opcao == 2) {
            adicionarDependente(&empresa);
        } else if (opcao == 3) {
            exibirEmpresa(empresa);
        } else if (opcao == 4) {
            salvarFuncionarios(empresa);
            salvarDependentes(empresa);
            printf("Dados salvos com sucesso.\n");
        }
    } while (opcao != 5);

    // Liberar memória alocada
    for (int i = 0; i < empresa.num_funcionarios; i++) {
        free(empresa.funcionarios[i].dependentes);
    }
    free(empresa.funcionarios);

    return 0;
}
