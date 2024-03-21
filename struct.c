#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prox;
};

int main()
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    
    if (node == NULL){
        printf("error ao alloca memoria\n");
        return 1;
    }
    
    node ->data = 1; 
node -> prox = NULL;
printf("valor de data : %d\n", node ->data);
printf("valor do proximo ponteiro: %p\n", node->prox);

free(node);

return 0;
}
