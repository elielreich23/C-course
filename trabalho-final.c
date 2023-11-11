#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED   "\x1B[31m"
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
};

struct ambiente{
	struct evento x;
	char local[20];
};

void leitura(struct evento *x, int contador){
    printf("Digite a data(dia, mes):\n");
    scanf("%d%d", &x->data.dia, &x->data.mes);
    
    printf("Digite o horario de inicio(hora e minuto):\n");
    scanf("%d%d", &x->horario.hora1, &x->horario.min1);
    
    printf("Digite o horario de fim(hora e minuto):\n");
    scanf("%d%d", &x->horario.hora2, &x->horario.min2);
    
    printf("Digite a descricao:\n");
    scanf(" %[^\n]", x->descricao);
}

void mostrar_um(struct evento x){
    printf(RED "");
    printf("Sala:\nData: %d/%d\nInicio: %d:%d\nFim: %d:%d\nDescricao: %s\n", x.data.dia, x.data.mes, x.horario.hora1, x.horario.min1, x.horario.hora2, x.horario.min2, x.descricao);
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
	struct Ambiente *y = NULL;
	struct evento *x = NULL;
    int opcao, usuario, cont = 0;
    
    
	x = malloc(sizeof(struct evento) * cont);
    system("CLS");
	printf(RED "\nMENU USUARIO\n1)Adm\n2)Professor\n3)Aluno\nDigite a opcao de usuario: \n" RESET);
	scanf("%d", &usuario);
    
	
	if(usuario == 1){
    	do{
		
		system("CLS");
		printf(RED "\nMENU ADM\n1)Adicionar ambientes e recursos\n2)Cadastro de um novo evento\n3)Mostrar todos os ambientes/recursos\n4)Mostrar ambientes e recursos especificos\n5)Mostrar eventos(data especifica)\n6)Mostrar eventos(por descricao)\n7)Remover evento(por data e hora de inicio)\n8)Sair\nDigite uma opcao:\n" RESET);
		scanf("%d", &opcao);
		
		if(opcao == 1){
			
		}else if(opcao == 2){
			
			cont++;
            x = realloc(x, sizeof(struct evento) * cont);
            leitura(&x[cont - 1], cont);
            printf("\nCadastro executado!\n");
			system("PAUSE");
		
		}else if(opcao == 3){
			
		}else if(opcao == 4){
			
		}else if(opcao == 5){
			
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
		
		}else if(opcao == 6){
			
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
                
		}else if(opcao == 7){
			
			if(cont == 0){
                printf("Nao ha eventos!\n");
            }else{
                cont = remover(x, cont);
                }
				system("PAUSE");
	
		}else if(opcao == 8){
			printf(RED "Fim do programa!\n" RESET);
		}
		
		}while(opcao != 8);

	}else if(usuario == 2){
		do{
		system("CLS");
		x = realloc(x, sizeof(struct evento) * cont);
		printf(RED "\nMENU PROFESSOR\n1)Cadastro de um novo evento\n2)Mostrar todos os ambientes/recursos\n3)Mostrar ambientes e recursos especificos\n4)Mostrar eventos(data especifica)\n5)Mostrar eventos(por descricao)\n6)Remover evento(por data e hora de inicio)\n7)Sair\nDigite uma opcao:\n" RESET);
		scanf("%d", &opcao);
            
			if(opcao < 1 || opcao > 7){
                printf("Opcao invalida!\n");
                system("PAUSE");
            
        }else if(opcao == 1){
            cont++;
            x = realloc(x, sizeof(struct evento) * cont);
            leitura(&x[cont - 1], cont);
            printf("\nCadastro executado!\n");
			system("PAUSE");
        
        }else if(opcao == 2){
            
            mostrar_tudo(x, cont);
            system("PAUSE");
            
        }else if(opcao == 3){
            
            if(cont == 0){
                printf("Nao ha eventos!\n");
            
            }else{
                
            }
            
        }else if(opcao == 4){
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
            
		}else if(opcao == 7){
            	printf("Fim do programa!\n");
			}	
	
	
	
	}while(opcao != 7);
	}
	
	
	else if(usuario == 3){
		do{
		
		system("CLS");
		printf(RED "MENU ALUNO\n1)Mostrar todos os ambientes/recursos\n2)Mostrar ambientes e recursos especificos\n3)Mostrar eventos(data especifica)\n4)Mostrar eventos(por descricao)\n5)Sair\nDigite uma opcao:\n" RESET);
		scanf("%d", &opcao);
		
		if(opcao < 1 || opcao > 5){
                printf("Opcao invalida!\n");
                system("PAUSE");
        
		}else if(opcao == 1){
        	
		}else if(opcao == 2){
			
		}else if(opcao == 3){
			
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
                
		}else if(opcao == 5){
			printf("Fim do programa!\n");
		}
	
	}while(opcao != 5);
	}

    free(x);
    
	return 0;
}