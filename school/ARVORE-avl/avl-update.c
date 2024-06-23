#include <stdio.h>
#include <stdlib.h>

typedef struct nodoAVL {
    int info;
    struct nodoAVL *esq;
    struct nodoAVL *dir;
    int alt;
} nodoAVL;

int max(int a, int b);
int altura(nodoAVL *subarvore);
nodoAVL *rotacao_simples_esq(nodoAVL *k2);
nodoAVL *rotacao_simples_dir(nodoAVL *k2);
nodoAVL *rotacao_dupla_esq(nodoAVL *k3);
nodoAVL *rotacao_dupla_dir(nodoAVL *k3);
nodoAVL *inserirAVL(int info, nodoAVL *arv, nodoAVL *pai);
void imprimir(nodoAVL *raiz, int nivel);
nodoAVL *excluirAVL(nodoAVL *raiz, int info);
nodoAVL *encontrarMin(nodoAVL *arv);
nodoAVL *balancear(nodoAVL *arv);
nodoAVL *pesquisar(nodoAVL *raiz, int info);
void inserirUsuario(nodoAVL **raiz);
void excluirUsuario(nodoAVL **raiz);
void pesquisarUsuario(nodoAVL *raiz);

int main() {
    nodoAVL *raiz = NULL;

    inserirUsuario(&raiz);

    printf("Árvore AVL após inserções:\n");
    imprimir(raiz, 0);
    printf("\n---------------------\n");

    excluirUsuario(&raiz);

    printf("Árvore AVL após exclusão:\n");
    imprimir(raiz, 0);
    printf("\n---------------------\n");

    pesquisarUsuario(raiz);

    return 0;
}

void inserirUsuario(nodoAVL **raiz) {
    int n, info;
    printf("Quantos elementos deseja inserir na árvore? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &info);
        *raiz = inserirAVL(info, *raiz, NULL);
        printf("Árvore após inserir %d:\n", info);
        imprimir(*raiz, 0);
        printf("\n---------------------\n");
    }
}

void excluirUsuario(nodoAVL **raiz) {
    int info;
    printf("Digite o elemento que deseja excluir da árvore: ");
    scanf("%d", &info);
    *raiz = excluirAVL(*raiz, info);
}

void pesquisarUsuario(nodoAVL *raiz) {
    int info;
    printf("Digite o elemento que deseja pesquisar na árvore: ");
    scanf("%d", &info);
    nodoAVL *resultado = pesquisar(raiz, info);
    if (resultado != NULL) {
        printf("Elemento %d encontrado na árvore.\n", info);
    } else {
        printf("Elemento %d não encontrado na árvore.\n", info);
    }
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int altura(nodoAVL *subarvore) {
    return (subarvore == NULL) ? -1 : subarvore->alt;
}

nodoAVL *rotacao_simples_esq(nodoAVL *k2) {
    nodoAVL *k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
    k2->alt = max(altura(k2->esq), altura(k2->dir)) + 1;
    k1->alt = max(altura(k1->esq), k2->alt) + 1;
    return k1;
}

nodoAVL *rotacao_simples_dir(nodoAVL *k2) {
    nodoAVL *k1 = k2->dir;
    k2->dir = k1->esq;
    k1->esq = k2;
    k2->alt = max(altura(k2->dir), altura(k2->esq)) + 1;
    k1->alt = max(altura(k1->dir), k2->alt) + 1;
    return k1;
}

nodoAVL *rotacao_dupla_esq(nodoAVL *k3) {
    k3->esq = rotacao_simples_dir(k3->esq);
    return rotacao_simples_esq(k3);
}

nodoAVL *rotacao_dupla_dir(nodoAVL *k3) {
    k3->dir = rotacao_simples_esq(k3->dir);
    return rotacao_simples_dir(k3);
}

nodoAVL *inserirAVL(int info, nodoAVL *arv, nodoAVL *pai) {
    if (arv == NULL) {
        arv = (nodoAVL *)malloc(sizeof(nodoAVL));
        if (arv == NULL)
            return NULL;
        arv->info = info;
        arv->alt = 0;
        arv->esq = NULL;
        arv->dir = NULL;
    } else if (info < arv->info) {
        arv->esq = inserirAVL(info, arv->esq, arv);
        if (altura(arv->esq) - altura(arv->dir) > 1) {
            if (info < arv->esq->info)
                arv = rotacao_simples_esq(arv);
            else
                arv = rotacao_dupla_esq(arv);
        }
    } else if (info > arv->info) {
        arv->dir = inserirAVL(info, arv->dir, arv);
        if (altura(arv->dir) - altura(arv->esq) > 1) {
            if (info > arv->dir->info)
                arv = rotacao_simples_dir(arv);
            else
                arv = rotacao_dupla_dir(arv);
        }
    } else {
        printf("\n ERRO: chave já está na árvore");
        return NULL;
    }
    arv->alt = max(altura(arv->esq), altura(arv->dir)) + 1;
    return arv;
}

void imprimir(nodoAVL *raiz, int nivel) {
    if (raiz) {
        imprimir(raiz->dir, nivel + 1);
        printf("\n");
        for (int i = 0; i < nivel; i++)
            printf("\t");
        printf("%d\n", raiz->info);
        imprimir(raiz->esq, nivel + 1);
    }
}

nodoAVL *encontrarMin(nodoAVL *arv) {
    while (arv->esq != NULL)
        arv = arv->esq;
    return arv;
}

nodoAVL *balancear(nodoAVL *arv) {
    if (altura(arv->esq) - altura(arv->dir) > 1) {
        if (altura(arv->esq->esq) >= altura(arv->esq->dir))
            arv = rotacao_simples_esq(arv);
        else
            arv = rotacao_dupla_esq(arv);
    } else if (altura(arv->dir) - altura(arv->esq) > 1) {
        if (altura(arv->dir->dir) >= altura(arv->dir->esq))
            arv = rotacao_simples_dir(arv);
        else
            arv = rotacao_dupla_dir(arv);
    }
    arv->alt = max(altura(arv->esq), altura(arv->dir)) + 1;
    return arv;
}

nodoAVL *excluirAVL(nodoAVL *raiz, int info) {
    if (raiz == NULL)
        return NULL;

    if (info < raiz->info) {
        raiz->esq = excluirAVL(raiz->esq, info);
    } else if (info > raiz->info) {
        raiz->dir = excluirAVL(raiz->dir, info);
    } else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            nodoAVL *temp = raiz->esq ? raiz->esq : raiz->dir;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;
            free(temp);
        } else {
            nodoAVL *temp = encontrarMin(raiz->dir);
            raiz->info = temp->info;
            raiz->dir = excluirAVL(raiz->dir, temp->info);
        }
    }

    if (raiz == NULL)
        return raiz;

    return balancear(raiz);
}

nodoAVL *pesquisar(nodoAVL *raiz, int info) {
    if (raiz == NULL || raiz->info == info)
        return raiz;
    if (info < raiz->info)
        return pesquisar(raiz->esq, info);
    return pesquisar(raiz->dir, info);
}
