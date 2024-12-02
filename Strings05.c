//Digite um nome, calcule e retorne quantas letras tem esse nome
#include <stdio.h>

int main() {
    char nome[100];
    int tamanho = 0;

    fgets(nome, sizeof(nome), stdin);

    while (nome[tamanho] != '\0' && nome[tamanho] != '\n') {
        tamanho++;
    }

    printf("o nome tem %d letras", tamanho);

    return 0;
}
