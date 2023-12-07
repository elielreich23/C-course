#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED   "\x1B[31m"
#define BLUE  "\x1B[36m"
#define RESET "\x1B[0m"

struct Data{
    int dia, mes;
};

struct Horario{
    int hora1, min1, hora2, min2;
};

struct evento{
    struct Data data;
    struct Horario horario;
    char descricao[20];
    char sala[20];
};

struct Sala{
	int comp, proj, mesas, cadeiras, micro, quadros;
	char local[20];
};

void leitura(struct evento *x, int contador){
    do{

	printf("Digite a data(dia, mes):\n");
    scanf("%d%d", &x->data.dia, &x->data.mes);
	if(x->data.dia < 1 || x->data.dia > 31 || x->data.mes < 1 || x->data.mes > 12){
		printf("Data invalida!\n");
		continue;
	}
	if(x->data.mes == 2 && x->data.dia > 28){
		printf("Data invalida!\n");
		continue;
	}
	break;

	}while(1);

	do{
		printf("Digite o horario de inicio(hora e minuto):\n");
    	scanf("%d%d", &x->horario.hora1, &x->horario.min1);

		if(x->horario.hora1 < 0 || x->horario.hora1 > 23 || x->horario.min1 < 0 || x->horario.min1 > 59){
    		printf("Horario invalido!\n");
    		continue;
		}

		printf("Digite o horario de fim(hora e minuto):\n");
   		scanf("%d%d", &x->horario.hora2, &x->horario.min2);

		if(x->horario.hora2 < 0 || x->horario.hora2 > 23 || x->horario.min2 < 0 || x->horario.min2 > 59){
			printf("Horario invalido!\n");
			continue;
		}

		if(x->horario.hora2 < x->horario.hora1 || ( x->horario.hora2 == x->horario.hora1 && x->horario.min2 <= x->horario.min1)){
			printf("Horario de fim deve ser posterior ao horario de inicio!\n");
			continue;
		}

		break;

	}while(1);

		printf("Digite a descricao:\n");
    	scanf(" %[^\n]", x->descricao);
}

void mostrar_um(struct evento x){
    printf(RED "");
    printf("Sala: %s\nData: %d/%d\nInicio: %02d:%02d\nFim: %02d:%02d\nDescricao: %s\n", x.sala, x.data.dia, x.data.mes, x.horario.hora1, x.horario.min1, x.horario.hora2, x.horario.min2, x.descricao);
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

void mostrar_amb(struct Sala z){
	printf(RED"");
	printf("Sala: %s\nComputadores: %d\nProjetores: %d\nMesas: %d\nCadeiras: %d\nMicrofones: %d\nQuadros: %d\n", z.local, z.comp, z.proj, z.mesas, z.cadeiras, z.micro, z.quadros);
	printf(RESET);
}

void mostrar_ambs(struct Sala *z, int contador){

	if(contador == 0){
		printf("Nao ha ambientes!\n");
	}else{
		for(int i = 0; i < contador; i++){
			mostrar_amb(z[i]);
			printf("\n");
		}
	}
}

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

int remover_amb(struct Sala *z, int contador){
	char ex[20];
	int achou = -1;

	for(int i = 0; i < contador; i++){
		printf("Sala %d: %s\n", i + 1, z[i].local);
	}

	printf("Digite o nome do ambiente que deseja remover:\n");
	scanf(" %[^\n]", ex);

	for(int i = 0; i < contador; i++){
		if(strcmp(ex, z[i].local) == 0){
			achou = i;
			break;
		}
	}

	if(achou == -1){
		printf("Ambiente nao existente!\n");
	}
	else{
		for(int i = achou; i < contador - 1; i++){
				z[i].comp = z[i + 1].comp;
				z[i].proj = z[i + 1].proj;
				z[i].mesas = z[i + 1].mesas;
				z[i].cadeiras = z[i + 1].cadeiras;
				z[i].micro = z[i + 1].micro;
				z[i].quadros = z[i + 1].quadros;
				strcpy(z[i].local, z[i + 1].local);
			}
				contador--;
				z = realloc(z, sizeof(struct Sala) * contador);
				printf("Ambiente removido!\n");
		}
			return contador;

}

void ler_recursos(struct Sala *z){

	printf("Digite o numero de computadores:\n");
	scanf("%d", &z->comp);
	printf("Digite o numero de projetores:\n");
	scanf("%d", &z->proj);
	printf("Digite o numero de mesas:\n");
	scanf("%d", &z->mesas);
	printf("Digite o numero de cadeiras:\n");
	scanf("%d", &z->cadeiras);
	printf("Digite o numero de microfones:\n");
	scanf("%d", &z->micro);
	printf("Digite o numero de quadros:\n");
	scanf("%d", &z->quadros);

}

int main()
{
	struct Sala *z = NULL;
	struct evento *x = NULL;
    int opcao, usuario, cont = 0, amb = 0;


	x = malloc(sizeof(struct evento) * cont);
    z = malloc(sizeof(struct Sala) * amb);

	do{

	system("CLS");
	printf(BLUE "MENU USUARIO\n" RESET);
	printf(RED "1)Adm\n2)Professor\n3)Aluno\n4)Sair\nDigite a opcao de usuario: \n" RESET);
	scanf("%d", &usuario);

	if(usuario < 1 || usuario > 4){
    	printf("Opcao invalida!\n");
    	system("PAUSE");
	}

	if(usuario == 1){
    	do{

		system("CLS");
		printf(BLUE "MENU ADM\n" RESET);
		printf(RED "1)Adicionar ambientes e recursos\n2)Remover ambientes(por nome)\n3)Cadastro de um novo evento\n4)Mostrar todos os ambientes/recursos\n5)Mostrar ambientes e recursos especificos\n6)Mostrar eventos(data especifica)\n7)Mostrar eventos(por descricao)\n8)Remover evento(por data e hora de inicio)\n9)Sair\nDigite uma opcao:\n" RESET);
		scanf("%d", &opcao);

		if(opcao < 1 || opcao > 9){
			printf("Opcao invalida!\n");
			system("PAUSE");
		}

		if(opcao == 1){
			int achou;
			if(amb == 0){
				amb++;
				z = realloc(z, sizeof(struct Sala) * amb);
				printf("Digite o nome do novo ambiente: \n");
				scanf(" %[^\n]", z[amb - 1].local);
				ler_recursos(&z[amb - 1]);
			}

			else{

				do{
					achou = 0;
					amb++;
					z = realloc(z, sizeof(struct Sala) * amb);
					printf("Digite o nome do novo ambiente: \n");
					scanf(" %[^\n]", z[amb - 1].local);

				for(int i = 0; i < amb - 1; i++){
					if(strcmp(z[amb - 1].local, z[i].local) == 0){
						achou = 1;
						printf("Ambiente ja existente!\n");
						amb--;
						z = realloc(z, sizeof(struct Sala) * amb);
						break;
					}
				}

				}while(achou == 1);

				if(achou == 0){
					ler_recursos(&z[amb - 1]);
				}
		}

		}else if(opcao == 2){
			if(amb == 0){
				printf("Nao ha ambientes para remover!\n");
			}
			else{
				amb = remover_amb(z, amb);
			}

			system("PAUSE");

		}else if(opcao == 3){

			if(amb == 0){
				printf("Nao ha ambientes para cadastrar eventos!\n");
			}
			else{
				int achou = 0;
				char ex[20];

					for(int i = 0; i < amb; i++){
						printf("Sala %d: %s\n", i + 1, z[i].local);
					}
				do{
					printf("Digite o nome da sala em que deseja cadastrar o evento: \n");
					scanf(" %[^\n]", ex);

				for(int i = 0; i < amb; i++){
					if(strcmp(ex, z[i].local) == 0){
						achou = 1;
						cont++;
						x = realloc(x, sizeof(struct evento) * cont);
						leitura(&x[cont - 1], cont);
						strcpy(x[cont - 1].sala, ex);
						printf("\nCadastro executado!\n");
						break;
					}
				}

				if(achou == 0){
						printf("Ambiente nao encontrado!\n");
					}

			}while(achou == 0);

			}
			 system("PAUSE");

		}else if(opcao == 4){

			mostrar_ambs(z, amb);
			system("PAUSE");

		}else if(opcao == 5){

			if(amb == 0){
				printf("Nao ha ambientes para consultar!\n");
			}
			else{

			char ex[20];
			int achou = 0;

			for(int i = 0; i < amb; i++){
				printf("Sala %d: %s\n", i + 1, z[i].local);
			}

			do{

				printf("Escolha o ambiente que deseja consultar: \n");
				scanf(" %[^\n]", ex);

				for(int i = 0; i < amb; i++){
					if(strcmp(ex, z[i].local) == 0){
						achou = 1;
						printf("Ambiente %d: \n", i + 1);
						mostrar_amb(z[i]);
					}
				}
				if(achou == 0){
					printf("Ambiente nao encontrado!\n");
				}

			}while(achou == 0);

			}
				system("PAUSE");

		}else if(opcao == 6){

			if(cont == 0){
                printf("Nao ha eventos!\n");

            }else{
                int a, b, achou = 0;
                printf("Digite a data que deseja consultar:\n");
                scanf("%d%d", &a, &b);
                for(int i = 0; i < cont; i++){
                    if(a == x[i].data.dia && b == x[i].data.mes){
                        achou = 1;
						printf("Evento %d\n", i + 1);
                        mostrar_um(x[i]);
                        printf("\n");
                    }
                }
                if(achou == 0){
                	printf("Evento nao encontrado!\n");
				}
            }
            system("PAUSE");

		}else if(opcao == 7){

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

		}else if(opcao == 8){

			if(cont == 0){
                printf("Nao ha eventos!\n");
            }else{
                cont = remover(x, cont);
                }
				system("PAUSE");

		}else if(opcao == 9){
			printf(RED "Fim do programa!\n" RESET);
		}

		}while(opcao != 9);

	}else if(usuario == 2){

		do{

		system("CLS");
		x = realloc(x, sizeof(struct evento) * cont);

		printf(BLUE "MENU PROFESSOR\n" RESET);
		printf(RED "1)Cadastro de um novo evento\n2)Mostrar todos os ambientes/recursos\n3)Mostrar ambientes e recursos especificos\n4)Mostrar eventos(data especifica)\n5)Mostrar eventos(por descricao)\n6)Remover evento(por data e hora de inicio)\n7)Sair\nDigite uma opcao:\n" RESET);
		scanf("%d", &opcao);

			if(opcao < 1 || opcao > 7){
                printf("Opcao invalida!\n");
                system("PAUSE");

        }else if(opcao == 1){
            if(amb == 0){
				printf("Nao ha ambientes para cadastrar eventos!\n");
			}
			else{
				int achou = 0;
				char ex[20];

					for(int i = 0; i < amb; i++){
						printf("Sala %d: %s\n", i + 1, z[i].local);
					}
				do{
					printf("Digite o nome da sala em que deseja cadastrar o evento: \n");
					scanf(" %[^\n]", ex);

				for(int i = 0; i < amb; i++){
					if(strcmp(ex, z[i].local) == 0){
						achou = 1;
						cont++;
						x = realloc(x, sizeof(struct evento) * cont);
						leitura(&x[cont - 1], cont);
						strcpy(x[cont - 1].sala, ex);
						printf("\nCadastro executado!\n");
						break;
					}
				}

				if(achou == 0){
						printf("Ambiente nao encontrado!\n");
					}

			}while(achou == 0);

			}
			 system("PAUSE");

        }else if(opcao == 2){

            mostrar_ambs(z, amb);
			system("PAUSE");

        }else if(opcao == 3){

            if(amb == 0){
                printf("Nao ha ambientes!\n");

            }else{

            }

        }else if(opcao == 4){
            if(cont == 0){
                printf("Nao ha eventos!\n");

            }else{
                int a, b, achou = 0;
                printf("Digite a data que deseja consultar:\n");
                scanf("%d%d", &a, &b);
                for(int i = 0; i < cont; i++){
                    if(a == x[i].data.dia && b == x[i].data.mes){
                        achou = 1;
						printf("Evento %d\n", i + 1);
                        mostrar_um(x[i]);
                        printf("\n");
                    }
                }
                if(achou == 0){
                	printf("Evento nao encontrado!\n");
				}
            }
            system("PAUSE");

        }else if(opcao == 5){

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

        }else if(opcao == 6){

            if(cont == 0){
                printf("Nao ha eventos!\n");
            }else{
                cont = remover(x, cont);
                }

				system("PAUSE");

		}

	}while(opcao != 7);
	}


	else if(usuario == 3){
		do{

		system("CLS");
		printf(BLUE "MENU ALUNO\n" RESET);
		printf(RED "1)Mostrar todos os ambientes/recursos\n2)Mostrar ambientes e recursos especificos\n3)Mostrar eventos(data especifica)\n4)Mostrar eventos(por descricao)\n5)Sair\nDigite uma opcao:\n" RESET);
		scanf("%d", &opcao);

		if(opcao < 1 || opcao > 5){
                printf("Opcao invalida!\n");
                system("PAUSE");

		}else if(opcao == 1){

			mostrar_ambs(z, amb);
			system("PAUSE");

		}else if(opcao == 2){

		}else if(opcao == 3){

			if(cont == 0){
                printf("Nao ha eventos!\n");

            }else{
                int a, b, achou = 0;
                printf("Digite a data que deseja consultar:\n");
                scanf("%d%d", &a, &b);
                for(int i = 0; i < cont; i++){
                    if(a == x[i].data.dia && b == x[i].data.mes){
                        achou = 1;
						printf("Evento %d\n", i + 1);
                        mostrar_um(x[i]);
                        printf("\n");
                    }
                }
                if(achou == 0){
                	printf("Evento nao encontrado!\n");
				}
            }
            	system("PAUSE");

		}else if(opcao == 4){

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

		}

	}while(opcao != 5);

	}
	else if(usuario == 4){
		printf(BLUE "Fim do programa!\n" RESET);
	}

}while(usuario != 4);

	free(x);
    free(z);

	return 0;
}
