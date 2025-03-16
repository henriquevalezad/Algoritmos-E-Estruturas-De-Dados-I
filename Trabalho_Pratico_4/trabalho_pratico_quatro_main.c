#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int profit;
} sTrabalho;

void quicksortTrabalhos(sTrabalho* trabalho, int esquerda, int direita) {
    if (esquerda < direita) {
        int i = esquerda, j = direita;
        sTrabalho raiz = trabalho[(esquerda + direita) / 2];
        while (i <= j) {
            while (trabalho[i].difficulty < raiz.difficulty) i++;
            while (trabalho[j].difficulty > raiz.difficulty) j--;
            if (i <= j) {
                sTrabalho temp = trabalho[i];
                trabalho[i] = trabalho[j];
                trabalho[j] = temp;
                i++;
                j--;
            }
        }
        quicksortTrabalhos(trabalho, esquerda, j);
        quicksortTrabalhos(trabalho, i, direita);
    }
}

void quicksortFuncionarios(int* funcionarios, int esquerda, int direita) {
    if (esquerda < direita) {
        int i = esquerda, j = direita;
        int raiz = funcionarios[(esquerda + direita) / 2];
        while (i <= j) {
            while (funcionarios[i] < raiz) i++;
            while (funcionarios[j] > raiz) j--;
            if (i <= j) {
                int temp = funcionarios[i];
                funcionarios[i] = funcionarios[j];
                funcionarios[j] = temp;
                i++;
                j--;
            }
        }
        quicksortFuncionarios(funcionarios, esquerda, j);
        quicksortFuncionarios(funcionarios, i, direita);
    }
}

void organizaTrabalhos(sTrabalho* trabalho, int tamanho) {
    quicksortTrabalhos(trabalho, 0, tamanho - 1);
}

void organizaFuncionarios(int* funcionarios, int tamanho) {
    quicksortFuncionarios(funcionarios, 0, tamanho - 1);
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    sTrabalho* trabalho = (sTrabalho*)malloc(difficultySize * sizeof(sTrabalho));
    for (int i = 0; i < difficultySize; i++) {
        trabalho[i].difficulty = difficulty[i];
        trabalho[i].profit = profit[i];
    }
    organizaTrabalhos(trabalho, difficultySize);
    organizaFuncionarios(worker, workerSize);

    int maiorLucro = 0;
    int melhorLucro = 0;
    int contador = 0;

    for (int i = 0; i < workerSize; i++) {
        while (contador < difficultySize && trabalho[contador].difficulty <= worker[i]) {
            if (trabalho[contador].profit > melhorLucro) {
                melhorLucro = trabalho[contador].profit;
            }
            contador++;
        }
        maiorLucro += melhorLucro;
    }

    free(trabalho);
    return maiorLucro;
}

int main() {
    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {5, 6, 7, 8};
    
    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);
    
    int resultado = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);
    printf("maior lucro: %d", resultado);
    
    return 0;
}
