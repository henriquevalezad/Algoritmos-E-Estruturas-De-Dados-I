//faça um programa que leia um nome e imprima as 4 primeiras letras do nome
#include <stdio.h>

int main() {
    char nome[100];

    fgets(nome, sizeof(nome), stdin);

    for (int i = 0; i < 4 && nome[i] != '\0'; i++) {
        printf("%c", nome[i]);
    }

    return 0;
}
