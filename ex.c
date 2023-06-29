#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da fila
typedef struct Node {
    int dado;
    struct Node* prox;
} Node;

typedef struct {
    Node* inicio;
    Node* fim;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Função para enfileirar um valor
void enfileirar(Fila* fila, int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->dado = valor;
    novoNode->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNode;
        fila->fim = novoNode;
    } else {
        fila->fim->prox = novoNode;
        fila->fim = novoNode;
    }
}

// Função para desenfileirar um valor
int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return -1;
    }

    Node* nodeInicio = fila->inicio;
    int valor = nodeInicio->dado;

    fila->inicio = nodeInicio->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(nodeInicio);

    return valor;
}

// Função para remover valores no intervalo dado da fila
void removerValoresNoIntervalo(Fila* fila, int num1, int num2) {
    Fila filaTemp;
    inicializarFila(&filaTemp);

    while (!filaVazia(fila)) {
        int valor = desenfileirar(fila);

        if (valor < num1 || valor > num2)
            enfileirar(&filaTemp, valor);
    }

    while (!filaVazia(&filaTemp))
        enfileirar(fila, desenfileirar(&filaTemp));
}

// Função para imprimir a fila
void imprimirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    Node* nodeAtual = fila->inicio;

    while (nodeAtual != NULL) {
        printf("%d ", nodeAtual->dado);
        nodeAtual = nodeAtual->prox;
    }

    printf("\n");
}

void main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);
    enfileirar(&fila, 4);
    enfileirar(&fila, 5);
    enfileirar(&fila, 6);
    enfileirar(&fila, 7);
    enfileirar(&fila, 8);
    enfileirar(&fila, 9);
    enfileirar(&fila, 10);

    printf("Fila original: ");
    imprimirFila(&fila);

    int num1 = 2;
    int num2 = 6;

    removerValoresNoIntervalo(&fila, num1, num2);

    printf("Fila após a remoção dos valores no intervalo [%d, %d]: ", num1, num2);
    imprimirFila(&fila);

   
}
