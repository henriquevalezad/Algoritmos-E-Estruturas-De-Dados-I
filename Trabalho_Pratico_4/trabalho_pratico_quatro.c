typedef struct {
    int difficulty;
    int profit;
} sTrabalho;

void organizaTrabalhos(sTrabalho* trabalho, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (trabalho[j].difficulty < trabalho[menor].difficulty) {
                menor = j;
            }
        }
        if (menor != i) {
            sTrabalho temp = trabalho[i];
            trabalho[i] = trabalho[menor];
            trabalho[menor] = temp;
        }
    }
}

void organizaFuncionarios(int* funcionarios, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (funcionarios[j] < funcionarios[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int temp = funcionarios[i];
            funcionarios[i] = funcionarios[menor];
            funcionarios[menor] = temp;
        }
    }
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
