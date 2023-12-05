/**#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Definição da estrutura da pilha
typedef struct Stack {
    Node *top;
    int size;
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Função para empilhar um elemento na pilha
void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// Função para desempilhar o último elemento da pilha
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "A pilha está vazia. Não é possível desempilhar.\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

// Função para imprimir todos os elementos da pilha
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return;
    }

    Node *current = stack->top;
    printf("Elementos na pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int tamanho, valor, opcao;
    
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tamanho);

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir valor na pilha\n");
        printf("2. Desempilhar último elemento\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (stack.size < tamanho) {
                    printf("Digite um valor para inserir na pilha: ");
                    scanf("%d", &valor);
                    push(&stack, valor);
                    printf("%d inserido com sucesso.\n", valor);
                    printStack(&stack);
                } else {
                    printf("A pilha está cheia. Não é possível inserir mais elementos.\n");
                }
                break;

            case 2:
                if (!isEmpty(&stack)) {
                    int poppedValue = pop(&stack);
                    printf("%d desempilhado com sucesso.\n", poppedValue);
                    printStack(&stack);
                } else {
                    printf("A pilha está vazia. Não é possível desempilhar.\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
**/ 
//same code just a bit simpler got to modify for pop to be done at the top of the pile and not the bottom 
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Tamanho máximo da pilha

typedef struct {
    int data[MAX_SIZE]; // Vetor para armazenar os elementos da pilha
    int top;            // Índice do topo da pilha
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack) {
    stack->top = -1; // Inicialmente, a pilha está vazia
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para empilhar um elemento na pilha
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("A pilha está cheia. Não é possível inserir mais elementos.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Função para desempilhar o elemento no topo da pilha
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia. Não é possível desempilhar.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Função para imprimir pilha
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Elementos na pilha: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int tamanho, valor;
    
    printf("Digite o tamanho da pilha (até %d): ", MAX_SIZE);
    scanf("%d", &tamanho);

    if (tamanho > MAX_SIZE) {
        printf("Tamanho excede o máximo permitido.\n");
        return 1;
    }

    printf("Inserindo valores na pilha...\n");

    while (stack.top < tamanho) {
        printf("Digite um valor para inserir na pilha: ");
        scanf("%d", &valor);
        push(&stack, valor);
        printf("%d inserido com sucesso.\n", valor);
    }

    printf("Pilha completa:\n");
    printStack(&stack);

    int opcao;
    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Desempilhar último elemento\n");
        printf("2. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!isEmpty(&stack)) {
                    int poppedValue = pop(&stack);
                    printf("%d desempilhado com sucesso.\n", poppedValue);
                    printStack(&stack);
                } else {
                    printf("A pilha está vazia. Não é possível desempilhar.\n");
                }
                break;

            case 2:
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
