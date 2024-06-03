#include <stdio.h>
#include <stdlib.h>

// Estruturas de dados para Fila de Prioridade Não Ordenada
typedef struct No {
    int dado;
    int prioridade;
    struct No* proximo;
} No;

typedef struct FilaPrioridade {
    No* cabeca;
} FilaPrioridade;

// Funções para Fila de Prioridade Não Ordenada
FilaPrioridade* criarFilaPrioridade() {
    FilaPrioridade* fp = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    fp->cabeca = NULL;
    return fp;
}

void inserir(FilaPrioridade* fp, int dado, int prioridade) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->prioridade = prioridade;
    novoNo->proximo = fp->cabeca;
    fp->cabeca = novoNo;
}

int removerMaiorPrioridade(FilaPrioridade* fp) {
    if (fp->cabeca == NULL) {
        printf("Fila está vazia\n");
        return -1;
    }
    No *temp = fp->cabeca, *prev = NULL, *noMaiorPrioridade = NULL, *prevMaiorPrioridade = NULL;
    int maiorPrioridade = -1;

    while (temp != NULL) {
        if (temp->prioridade > maiorPrioridade) {
            maiorPrioridade = temp->prioridade;
            noMaiorPrioridade = temp;
            prevMaiorPrioridade = prev;
        }
        prev = temp;
        temp = temp->proximo;
    }

    if (noMaiorPrioridade == fp->cabeca) {
        fp->cabeca = fp->cabeca->proximo;
    } else {
        prevMaiorPrioridade->proximo = noMaiorPrioridade->proximo;
    }

    int dado = noMaiorPrioridade->dado;
    free(noMaiorPrioridade);
    return dado;
}

// Estrutura de Dados para Heap usando Arrays
typedef struct {
    int* dados;
    int tamanho;
    int capacidade;
} Heap;

Heap* criarHeap(int capacidade) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->dados = (int*)malloc(capacidade * sizeof(int));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void inserirHeap(Heap* heap, int valor) {
    if (heap->tamanho == heap->capacidade) {
        printf("Heap está cheia\n");
        return;
    }
    heap->dados[heap->tamanho] = valor;
    int i = heap->tamanho;
    heap->tamanho++;
    
    while (i != 0 && heap->dados[(i - 1) / 2] < heap->dados[i]) {
        int temp = heap->dados[i];
        heap->dados[i] = heap->dados[(i - 1) / 2];
        heap->dados[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void maxHeapify(Heap* heap, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < heap->tamanho && heap->dados[esquerda] > heap->dados[maior]) {
        maior = esquerda;
    }

    if (direita < heap->tamanho && heap->dados[direita] > heap->dados[maior]) {
        maior = direita;
    }

    if (maior != i) {
        int temp = heap->dados[i];
        heap->dados[i] = heap->dados[maior];
        heap->dados[maior] = temp;
        maxHeapify(heap, maior);
    }
}

int removerMaxHeap(Heap* heap) {
    if (heap->tamanho == 0) {
        printf("Heap está vazia\n");
        return -1;
    }

    int raiz = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    maxHeapify(heap, 0);

    return raiz;
}

// Função merge para heaps
Heap* mergeHeaps(Heap* h1, Heap* h2) {
    int tamanhoTotal = h1->tamanho + h2->tamanho;
    Heap* heapMesclada = criarHeap(tamanhoTotal);

    for (int i = 0; i < h1->tamanho; i++) {
        inserirHeap(heapMesclada, h1->dados[i]);
    }

    for (int i = 0; i < h2->tamanho; i++) {
        inserirHeap(heapMesclada, h2->dados[i]);
    }

    return heapMesclada;
}

// Funções increase_key e decrease_key
void aumentarChave(Heap* heap, int i, int novoValor) {
    if (novoValor < heap->dados[i]) {
        printf("Novo valor é menor que o valor atual\n");
        return;
    }

    heap->dados[i] = novoValor;
    while (i != 0 && heap->dados[(i - 1) / 2] < heap->dados[i]) {
        int temp = heap->dados[i];
        heap->dados[i] = heap->dados[(i - 1) / 2];
        heap->dados[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void diminuirChave(Heap* heap, int i, int novoValor) {
    if (novoValor > heap->dados[i]) {
        printf("Novo valor é maior que o valor atual\n");
        return;
    }

    heap->dados[i] = novoValor;
    maxHeapify(heap, i);
}

int main() {
    // Teste da Fila de Prioridade Não Ordenada
    FilaPrioridade* fp = criarFilaPrioridade();
    inserir(fp, 10, 2);
    inserir(fp, 5, 1);
    inserir(fp, 20, 3);
    printf("Elemento removido com maior prioridade: %d\n", removerMaiorPrioridade(fp));

    // Teste da Heap usando Arrays
    Heap* heap = criarHeap(10);
    inserirHeap(heap, 10);
    inserirHeap(heap, 20);
    inserirHeap(heap, 5);
    printf("Elemento máximo removido da heap: %d\n", removerMaxHeap(heap));

    // Teste da Função merge
    Heap* h1 = criarHeap(5);
    inserirHeap(h1, 10);
    inserirHeap(h1, 5);

    Heap* h2 = criarHeap(5);
    inserirHeap(h2, 20);
    inserirHeap(h2, 15);

    Heap* heapMesclada = mergeHeaps(h1, h2);
    printf("Raiz da heap mesclada: %d\n", heapMesclada->dados[0]);

    // Limpeza de memória (não mostrado para simplicidade)

    return 0;
}
