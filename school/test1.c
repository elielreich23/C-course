#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Conjuge {
    char nome_conj[200];
};

struct Pessoa {
    char nome[200];
    char cpf[15];
    int idade;
    struct Conjuge conjuge;
};

void menu() {
    printf("Digite uma das opcoes:\n"
           "1 - Cadastrar pessoa\n"
           "2 - Buscar pessoa cadastrada\n"
           "3 - Vincular conjuge\n"
           "4 - Lista de pessoas cadastradas\n"
           "5 - Para sair do programa\n");
}

void dadosPessoa(struct Pessoa *p) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite o cpf:");
    scanf(" %[^\n]", p->cpf);
    printf("Digite a idade:");
    scanf("%d", &p->idade);
    strcpy(p->conjuge.nome_conj, "NULL");
}

int localizarPessoa(struct Pessoa *p, int n, const char *chave) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(p[i].nome, chave) == 0)
            return i;
    }
    return -1;
}

void mostra_Pessoa(struct Pessoa p) {
    printf("Nome: %s\nCPF: %s\nIdade: %d\nConjuge: %s\n",
           p.nome, p.cpf, p.idade, p.conjuge.nome_conj);
}

void imprimeDados(struct Pessoa *p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", i + 1);
        mostra_Pessoa(p[i]);
    }
}

void vincularConjuge(struct Pessoa *p1, struct Pessoa *p2) {
    strcpy(p1->conjuge.nome_conj, p2->nome);
    strcpy(p2->conjuge.nome_conj, p1->nome);
}

int main() {
    int n = 0;
    struct Pessoa *p = NULL;#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Conjuge {
    char nome_conj[200];
};

struct Pessoa {
    char nome[200];
    char cpf[15];
    int idade;
    struct Conjuge conjuge;
};

void menu() {
    printf("Digite uma das opcoes:\n"
           "1 - Cadastrar pessoa\n"
           "2 - Buscar pessoa cadastrada\n"
           "3 - Vincular conjuge\n"
           "4 - Lista de pessoas cadastradas\n"
           "5 - Para sair do programa\n");
}

void dadosPessoa(struct Pessoa *p) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite o cpf:");
    scanf(" %[^\n]", p->cpf);
    printf("Digite a idade:");
    scanf("%d", &p->idade);
    strcpy(p->conjuge.nome_conj, "NULL");
}

int localizarPessoa(struct Pessoa *p, int n, const char *chave) {
    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].nome, chave) == 0)
            return i;
    }
    return -1;
}

void mostra_Pessoa(struct Pessoa p) {
    printf("Nome: %s\nCPF: %s\nIdade: %d\nConjuge: %s\n",
           p.nome, p.cpf, p.idade, p.conjuge.nome_conj);
}

void imprimeDados(struct Pessoa *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", i + 1);
        mostra_Pessoa(p[i]);
    }
}

void vincularConjuge(struct Pessoa *p1, struct Pessoa *p2) {
    strcpy(p1->conjuge.nome_conj, p2->nome);
    strcpy(p2->conjuge.nome_conj, p1->nome);
}

int main() {
    int n = 0;
    struct Pessoa *p = NULL;
    int opcao = 0;
    char chave1[200], chave2[200];
    int aux1, aux2;

    FILE *f = fopen("Cadastro.txt", "rt");
    if (f != NULL) {
        fscanf(f, "%d\n", &n);
        p = malloc(sizeof(struct Pessoa) * n);
        for (int i = 0; i < n; i++) {
            fscanf(f, " %[^\n]", p[i].nome);
            fscanf(f, " %[^\n]", p[i].cpf);
            fscanf(f, "%d\n", &p[i].idade);
            fscanf(f, " %[^\n]", p[i].conjuge.nome_conj);
        }
        fclose(f);
        printf("%d registros carregados do arquivo\n", n);
    } else {
        printf("Arquivo de cadastro nao encontrado!\n");
    }

    do {
        system("CLS");
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                n++;
                p = realloc(p, sizeof(struct Pessoa) * n);
                dadosPessoa(&p[n - 1]);
                break;

            case 2:
                printf("Digite o nome da pessoa: ");
                scanf(" %[^\n]", chave1);
                aux1 = localizarPessoa(p, n, chave1);
                if (aux1 == -1) {
                    printf("Nome nao encontrado!\n");
                } else {
                    printf("Cadastro: %d\n", aux1);
                    mostra_Pessoa(p[aux1]);
                }
                break;

            case 3:
                printf("Digite o nome do conjuge:");
                scanf(" %[^\n]", chave1);
                aux1 = localizarPessoa(p, n, chave1);
                if (aux1 == -1) {
                    printf("Nao foi encontrado nenhum registro com esse nome\n");
                } else {
                    printf("Digite o nome da pessoa que deseja vincular esse conjuge: ");
                    scanf(" %[^\n]", chave2);
                    aux2 = localizarPessoa(p, n, chave2);
                    if (aux2 == -1) {
                        printf("Nao foi encontrado nenhum registro com esse nome\n");
                    } else {
                        printf("Registro vinculado com sucesso!\n");
                        vincularConjuge(&p[aux1], &p[aux2]);
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Nenhum registro cadastrado!");
                } else {
                    imprimeDados(p, n);
                    printf("\n");
                }
                break;

            case 5:
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

        system("PAUSE");

    } while (opcao != 5);

    f = fopen("Cadastro.txt", "wt");
    if (f != NULL) {
        fprintf(f, "%d\n", n);
        for (int i = 0; i < n; i++) {
            fprintf(f, "%s\n", p[i].nome);
            fprintf(f, "%s\n", p[i].cpf);
            fprintf(f, "%d\n", p[i].idade);
            fprintf(f, "%s\n", p[i].conjuge.nome_conj);
        }
        fclose(f);
    } else {
        printf("Erro na gravacao do arquivo!\n");
        return 1;
    }

    free(p);
    return 0;
}

    int opcao = 0;
    char chave1[200], chave2[200];
    int aux1, aux2;

    FILE *f = fopen("Cadastro.txt", "rt");
    if (f != NULL) {
        fscanf(f, "%d\n", &n);
        p = malloc(sizeof(struct Pessoa) * n);
        int i ;
        for ( i = 0; i < n; i++) {
            fscanf(f, " %[^\n]", p[i].nome);
            fscanf(f, " %[^\n]", p[i].cpf);
            fscanf(f, "%d\n", &p[i].idade);
            fscanf(f, " %[^\n]", p[i].conjuge.nome_conj);
        }
        fclose(f);
        printf("%d registros carregados do arquivo\n", n);
    } else {
        printf("Arquivo de cadastro nao encontrado!\n");
    }

    do {
        system("CLS");
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                n++;
                p = realloc(p, sizeof(struct Pessoa) * n);
                dadosPessoa(&p[n - 1]);
                break;

            case 2:
                printf("Digite o nome da pessoa: ");
                scanf(" %[^\n]", chave1);
                aux1 = localizarPessoa(p, n, chave1);
                if (aux1 == -1) {
                    printf("Nome nao encontrado!\n");
                } else {
                    printf("Cadastro: %d\n", aux1);
                    mostra_Pessoa(p[aux1]);
                }
                break;

            case 3:
                printf("Digite o nome do conjuge:");
                scanf(" %[^\n]", chave1);
                aux1 = localizarPessoa(p, n, chave1);
                if (aux1 == -1) {
                    printf("Nao foi encontrado nenhum registro com esse nome\n");
                } else {
                    printf("Digite o nome da pessoa que deseja vincular esse conjuge: ");
                    scanf(" %[^\n]", chave2);
                    aux2 = localizarPessoa(p, n, chave2);
                    if (aux2 == -1) {
                        printf("Nao foi encontrado nenhum registro com esse nome\n");
                    } else {
                        printf("Registro vinculado com sucesso!\n");
                        vincularConjuge(&p[aux1], &p[aux2]);
                    }
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Nenhum registro cadastrado!");
                } else {
                    imprimeDados(p, n);
                    printf("\n");
                }
                break;

            case 5:
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

        system("PAUSE");

    } while (opcao != 5);

    f = fopen("Cadastro.txt", "wt");
    if (f != NULL) {
        fprintf(f, "%d\n", n);
        int i;
        for (i = 0; i < n; i++) {
            fprintf(f, "%s\n", p[i].nome);
            fprintf(f, "%s\n", p[i].cpf);
            fprintf(f, "%d\n", p[i].idade);
            fprintf(f, "%s\n", p[i].conjuge.nome_conj);
        }
        fclose(f);
    } else {
        printf("Erro na gravacao do arquivo!\n");
        return 1;
    }

    free(p);
    return 0;
}
