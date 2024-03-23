// #include <stdio.h>
// #include <stdlib.h>

// struct Node{
//     int data;
//     struct Node *prox;
// };

// int main()
// {
//     struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    
//     if (node == NULL){
//         printf("error ao alloca memoria\n");
//         return 1;
//     }
    
//     node ->data = 1; 
// node -> prox = NULL;
// printf("valor de data : %d\n", node ->data);
// printf("valor do proximo ponteiro: %p\n", node->prox);

// free(node);

// return 0;
// }

#include <stdio.h>
#include <malloc.h>
#define alturaMax 225

typedef struct{
    int peso;
    int altura;
}PesoAltura;

int main(){
  PesoAltura* pessoa1= (PesoAltura*) malloc(sizeof(PesoAltura));
  pessoa1->peso = 80;
  pessoa1->altura  = 175;

  printf("peso: %i, altura:%i. ", pessoa1->peso, pessoa1->altura);
  if (pessoa1->altura >alturaMax){

    printf("altura acima do maximo");
  }
  else{
    printf("altura acaixo do maximo");
  }
  return 0;
}