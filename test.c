#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define RED   "\x1B[31m"
#define RESET "\x1B[0m"
#define MAX_AMBIENTES 10

struct Data{
    int dia, mes;
};

struct Horario{
    int hora1, min1, hora2, min2;
};

struct evento {
    struct Data data;
    struct Horario horario;
    char nomeEvento[50];
    char salaEvento[20];
    char descricao[20];
};

struct ambiente{
	struct evento x;
	char local[20];
};

int ehDataValida(int dia, int mes) {
    return (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12);
}

int ehHorarioValido(int hora, int minuto) {
    return (hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59);
}

void leitura(struct evento *x, int contador){
    int entradaValida = 0;
     printf("Digite o nome do evento:\n");
    scanf(" %[^\n]", x->nomeEvento);

    do {
        printf("Digite a data (dia, mes):\n");
        if (scanf("%d%d", &x->data.dia, &x->data.mes) == 2 &&
            ehDataValida(x->data.dia, x->data.mes)) {
            entradaValida = 1;
        } else {
            printf("Data inválida. Tente novamente.\n");
            while (getchar() != '\n');
        }
    } while (!entradaValida);

    entradaValida = 0;

   do {
    printf("Digite o horário de início (hora e minuto):\n");
    if (scanf("%d%d", &x->horario.hora1, &x->horario.min1) == 2 &&
        ehHorarioValido(x->horario.hora1, x->horario.min1)) {
        entradaValida = 1;
    } else {
        printf("Horário inválido. Tente novamente.\n");
        while (getchar() != '\n');
    }
} while (!entradaValida);

entradaValida = 0;

do {
    printf("Digite o horário de término (hora e minuto):\n");
    if (scanf("%d%d", &x->horario.hora2, &x->horario.min2) == 2 &&
        ehHorarioValido(x->horario.hora2, x->horario.min2) &&
        (x->horario.hora2 > x->horario.hora1 || (x->horario.hora2 == x->horario.hora1 && x->horario.min2 > x->horario.min1))) {
        entradaValida = 1;
    } else {
        printf("Horário inválido. Tente novamente. Certifique-se de que o horário de término é maior que o horário de início.\n");
        while (getchar() != '\n');
    }
} while (!entradaValida);


    printf("Digite a descrição:\n");
    scanf(" %[^\n]", x->descricao);
    printf("Digite a sala do evento:\n");
    scanf(" %[^\n]", x->salaEvento);
}

//life is goos

void mostrar_um(struct evento x){
    printf(RED "");
    printf("Sala: %s\nData: %d/%d\nInicio: %d:%d\nFim: %d:%d\nDescricao: %s\n", x.salaEvento, x.data.dia, x.data.mes, x.horario.hora1, x.horario.min1, x.horario.hora2, x.horario.min2, x.descricao);
    printf(RESET);
}

void mostrar_tudo(struct evento *x, int contador){

	if(contador == 0){
        printf("Nao ha eventos!\n");
    }else{
        for(int i = 0; i < contador; i++){
            printf( "Evento %d\n", i + 1);
            mostrar_um(x[i]);
            printf("\n");
        }
    }
}

void mostrarAmbientes(struct ambiente *ambientes, int numAmbientes) {
    if (numAmbientes == 0) {
        printf("Nao ha ambientes ou recursos registrados. Por favor, utilize a opcao 1 para adicionar ambientes e recursos.\n");
    } else {
        printf("Lista de ambientes e recursos:\n");
        for (int i = 0; i < numAmbientes; i++) {
            printf("Ambiente %d:\n", i + 1);
            printf("Local: %s\n", ambientes[i].local);

            // Display the associated event details
            printf("Evento associado: %s\n", ambientes[i].x.nomeEvento);
            mostrar_um(ambientes[i].x);
           // printf("Nome do Evento: %s\n");

            printf("\n");
        }
    }
}
void adicionarAmbiente(struct ambiente *ambientes, int *numAmbientes, struct evento *eventos, int numEventos) {
    if (*numAmbientes < MAX_AMBIENTES) {
        // Check if there is space for a new ambiente
        printf("Digite o local do ambiente/recursos:\n");
        scanf(" %[^\n]", ambientes[*numAmbientes].local);

        int numEvento;
        printf("Escolha o evento ao qual deseja associar ambientes e recursos:\n");
        for (int i = 0; i < numEventos; i++) {
            printf("Evento %d - Data: %d/%d\n", i + 1, eventos[i].data.dia, eventos[i].data.mes);
        }

        // Get user input for the chosen event
        printf("Digite o número do evento: ");
        scanf("%d", &numEvento);

        // Validate the chosen event number
        if (numEvento >= 1 && numEvento <= numEventos) {
            // Associate the chosen event with the ambiente
            ambientes[*numAmbientes].x = eventos[numEvento - 1];

            printf("Ambiente/Recursos adicionado e associado ao evento com sucesso!\n");
            (*numAmbientes)++;
        } else {
            printf("Número de evento inválido! O ambiente foi adicionado, mas não associado a nenhum evento.\n");
            (*numAmbientes)++;
        }
    } else {
        printf("Limite de ambientes atingido!\n");
    }
}


/**
void adicionarAmbiente(struct ambiente *ambientes, int *numAmbientes) {
    if (*numAmbientes < MAX_AMBIENTES) {
        // Check if there is space for a new ambiente
        printf("Digite o local do ambiente/recursos:\n");
        scanf(" %[^\n]", ambientes[*numAmbientes].local);

        // You can add more details about the ambiente here if needed
        // For example, you can prompt the user for additional information

        printf("Ambiente/Recursos adicionado com sucesso!\n");
        (*numAmbientes)++;
    } else {
        printf("Limite de ambientes atingido!\n");
    }
}**/

int remover(struct evento *x, int contador){
	int a, b, c, d, indice = -1;

        printf("Digite a data do evento que deseja remover(Dia e mes):\n");
        scanf("%d%d", &a, &b);
        printf("Digite o horario de inicio do evento que deseja remover(hora e minuto):\n");
        scanf("%d%d", &c, &d);

		for(int i = 0; i < contador; i++){
            if(a == x[i].data.dia && b == x[i].data.mes && c == x[i].horario.hora1 && d == x[i].horario.min1){
                indice = i;
                break;
            }
        }

        if(indice == -1){
            printf("Evento nao encontrado!\n");

		}else{
            for(int i = indice; i < contador - 1; i++){
                    x[i].data.dia = x[i + 1].data.dia;
                    x[i].data.mes = x[i + 1].data.mes;
                    x[i].horario.hora1 = x[i + 1].horario.hora1;
                    x[i].horario.min1 = x[i + 1].horario.min1;
                    x[i].horario.hora2 = x[i + 1].horario.hora2;
                    x[i].horario.min2 = x[i + 1].horario.min2;
                    strcpy(x[i].descricao, x[i + 1].descricao);
                }
                    contador--;
                    x = realloc(x, sizeof(struct evento) * contador);
                    printf("Evento removido!\n");
            }
            return contador;
}


int main()
{
    setlocale(LC_ALL,"Portuguese");
	struct Ambiente *y = NULL;
	struct evento *x = NULL;
    int opcao, usuario, cont = 0;
    struct ambiente ambientes[MAX_AMBIENTES];
    int numAmbientes = 0;
    int opcaoCadastroEvento = 0;
    int voltar = 0;

/*
	x = malloc(sizeof(struct evento) * cont);
    system("CLS");
	printf(RED "\nMENU USUARIO\n1)Adm\n2)Professor\n3)Aluno\nDigite a opcao de usuario: \n" RESET);
	scanf("%d", &usuario);*/
    do {
        system("CLS");
        printf(RED "\nMENU USUARIO\n1)Adm\n2)Professor\n3)Aluno\nDigite a opcao de usuario: \n" RESET);
        scanf("%d", &usuario);

        if (usuario == 1) {
            do {
                system("CLS");
                printf(RED "\nMENU ADM\n1)Adicionar ambientes e recursos\n2)Cadastro de um novo evento\n3)Mostrar todos os ambientes/recursos\n4)Mostrar ambientes e recursos especificos\n5)Mostrar eventos(data especifica)\n6)Mostrar eventos(por descricao)\n7)Remover evento(por data e hora de inicio)\n8)Sair\n9)Voltar\nDigite uma opcao:\n" RESET);
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        if (opcaoCadastroEvento) {
                            adicionarAmbiente(ambientes, &numAmbientes, x, cont);
                            system("PAUSE");
                        } else {
                            printf("Por favor, realize o Cadastro de um novo evento primeiro (opcao 2).\n");
                            system("PAUSE");
                        }
                        break;
                    case 2:
                        cont++;
                        x = realloc(x, sizeof(struct evento) * cont);
                        leitura(&x[cont - 1], cont);
                        printf("\nCadastro executado!\n");
                        system("PAUSE");
                        opcaoCadastroEvento = 1;
                        break;
                    case 3:
                        if (numAmbientes == 0) {
                            printf("Nao ha ambientes ou recursos registrados. Por favor, utilize a opcao 1 para adicionar ambientes e recursos.\n");
                        } else {
                            mostrarAmbientes(ambientes, numAmbientes);
                        }
                        system("PAUSE");
                        break;
                    case 4:
                        if (numAmbientes == 0) {
                            printf("Nao ha ambientes ou recursos registrados. Por favor, utilize a opcao 1 para adicionar ambientes e recursos.\n");
                        } else {
                            // pedir noime do ambiente
                            char nomeAmbiente[20];
                            printf("Digite o nome do ambiente/recursos que deseja consultar:\n");
                            scanf(" %[^\n]", nomeAmbiente);

                            // monstrar detahes
                            int encontrados = 0;
                            for (int i = 0; i < numAmbientes; i++) {
                                if (strcmp(nomeAmbiente, ambientes[i].local) == 0) {
                                    encontrados++;
                                    printf("Detalhes do Ambiente/Recursos:\n");
                                    printf("Local: %s\n", ambientes[i].local);
                                    printf("Evento associado: %s\n", ambientes[i].x.nomeEvento);
                                    mostrar_um(ambientes[i].x);

                                    printf("\n");
                                }
                            }

                            if (encontrados == 0) {
                                printf("Ambiente/Recursos nao encontrado!\n");
                            }
                        }
                        system("PAUSE");
                        break;
                    case 5:
                        if(cont == 0){
                                printf("Nao ha eventos!\n");
                            }else{
                                int a, b;
                                printf("Digite a data que deseja consultar:\n");
                                scanf("%d%d", &a, &b);
                                for(int i = 0; i < cont; i++){
                                    if(a == x[i].data.dia && b == x[i].data.mes){
                                        printf("Evento %d\n", i + 1);
                                        mostrar_um(x[i]);
                                        printf("\n");
                                    }
                                }
                            }
                        system("PAUSE");
                        break;
                    case 6:
                        if(cont == 0){
                            printf("Nao ha eventos!\n");
                        }else{
                            int a, b;
                            printf("Digite a data que deseja consultar:\n");
                            scanf("%d%d", &a, &b);
                            for(int i = 0; i < cont; i++){
                                if(a == x[i].data.dia && b == x[i].data.mes){
                                    printf("Evento %d\n", i + 1);
                                    mostrar_um(x[i]);
                                    printf("\n");
                                }
                            }
                        }
                        system("PAUSE");
                        break;
                    case 7:
            			if(cont == 0){
                            printf("Nao ha eventos!\n");
                        }else{
                            cont = remover(x, cont);
                        }
            			system("PAUSE");
                        break;
                    case 8:
                        printf(RED "Fim do programa!\n" RESET);
                        break;
                    case 9:
                        voltar = 1;
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        system("PAUSE");
                }
            } while (opcao != 8 && !voltar);
        } else if (usuario == 2) {
            do {
                system("CLS");
                x = realloc(x, sizeof(struct evento) * cont);
                printf(RED "\nMENU PROFESSOR\n1)Cadastro de um novo evento\n2)Mostrar todos os ambientes/recursos\n3)Mostrar ambientes e recursos especificos\n4)Mostrar eventos(data especifica)\n5)Mostrar eventos(por descricao)\n6)Remover evento(por data e hora de inicio)\n7)Sair\n8)Voltar\nDigite uma opcao:\n" RESET);
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        cont++;
                        x = realloc(x, sizeof(struct evento) * cont);
                        leitura(&x[cont - 1], cont);
                        printf("\nCadastro executado!\n");
                        system("PAUSE");
                        break;
                    case 2:
                        mostrar_tudo(x, cont);
                        system("PAUSE");
                        break;
                    case 3:
                        if(cont == 0){
                            printf("Nao ha eventos!\n");
                        }else{

                        }
                        system("PAUSE");
                        break;
                    case 4:
                        if(cont == 0){
                            printf("Nao ha eventos!\n");
                        }else{
                            int a, b;
                            printf("Digite a data que deseja consultar:\n");
                            scanf("%d%d", &a, &b);
                            for(int i = 0; i < cont; i++){
                                if(a == x[i].data.dia && b == x[i].data.mes){
                                    printf("Evento %d\n", i + 1);
                                    mostrar_um(x[i]);
                                    printf("\n");
                                }
                            }
                        }
                        system("PAUSE");
                        break;
                    case 5:
                        if(cont == 0){
                            printf("Nao ha eventos!\n");
                        }else{
                            char ex[20];
                            int achou = 0;
                            printf("Digite a descricao que deseja consultar: \n");
                            scanf(" %[^\n]", ex);
                            for(int i = 0; i < cont; i++){
                                if(strcmp(ex, x[i].descricao) == 0){
                                    achou = 1;
                                    printf("Evento(s) existente(s):\nEvento %d\n", i + 1);
                                    mostrar_um(x[i]);
                                    printf("\n");
                                }
                            }
                            if(achou == 0){
                                printf("Evento nao encontrado!\n");
                            }
                        }
                        system("PAUSE");
                        break;
                    case 6:
                        if(cont == 0){
                            printf("Nao ha eventos!\n");
                        }else{
                            cont = remover(x, cont);
                        }
				        system("PAUSE");
                        break;
                    case 7:
                        printf("Fim do programa!\n");
                        break;
                    case 8:
                        voltar = 1;
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        system("PAUSE");
                }
            } while (opcao != 7 && !voltar);
        } else if (usuario == 3) {
            do {
                system("CLS");
                printf(RED "MENU ALUNO\n1)Mostrar todos os ambientes/recursos\n2)Mostrar ambientes e recursos especificos\n3)Mostrar eventos(data especifica)\n4)Mostrar eventos(por descricao)\n5)Sair\n6)Voltar\nDigite uma opcao:\n" RESET);
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        if (numAmbientes == 0) {
                            printf("Nao ha ambientes ou recursos registrados. Por favor, utilize a opcao 1 para adicionar ambientes e recursos.\n");
                        } else {
                            mostrarAmbientes(ambientes, numAmbientes);
                        }
                         system("PAUSE");
                        break;
                    case 2:
                        system("PAUSE");
                        break;
                    case 3:
            			if(cont == 0){
                            printf("Nao ha eventos!\n");
            			}else{
                            int a, b;
                            printf("Digite a data que deseja consultar:\n");
                            scanf("%d%d", &a, &b);
                            for(int i = 0; i < cont; i++){
                                if(a == x[i].data.dia && b == x[i].data.mes){
                                    printf("Evento %d\n", i + 1);
                                    mostrar_um(x[i]);
                                    printf("\n");
                                }
                            }
                        }
                        system("PAUSE");
                        break;
                    case 4:
                        if(cont == 0){
                printf("Nao ha eventos!\n");
            }else{
            char ex[20];
            int achou = 0;
            printf("Digite a descricao que deseja consultar: \n");
            scanf(" %[^\n]", ex);

            for(int i = 0; i < cont; i++){
                if(strcmp(ex, x[i].descricao) == 0){
                    achou = 1;
                    printf("Evento(s) existente(s):\nEvento %d\n", i + 1);
                    mostrar_um(x[i]);
                    printf("\n");
                    }
                }
                    if(achou == 0){
                        printf("Evento nao encontrado!\n");
                    }
                }
                system("PAUSE");

                        break;
                    case 5:
                        printf("Fim do programa!\n");
                        break;
                    case 6:
                        voltar = 1;
                        break;
                    default:
                        printf("Opcao invalida!\n");
                        system("PAUSE");
                }

            } while (opcao != 5 && !voltar);
        }

    } while (!voltar);

    free(x);

	return 0;
}
