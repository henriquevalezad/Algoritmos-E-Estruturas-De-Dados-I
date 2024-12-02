//Crie um programa que calcula o comprimento de uma string (nao use a função ao strlen).
#include <stdio.h>

int main() {
    char string[100];
    int tamanho = 0;

    fgets(string, sizeof(string), stdin);

    while (string[tamanho] != '\0' && string[tamanho] != '\n') {
        tamanho++;
    }

    printf("o tamanho da string %d", tamanho);

    return 0;
}

