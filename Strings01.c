//Faça um programa que entao leia uma string e a imprima
#include <stdio.h>

int main() {
    char string[100];

    fgets(string, sizeof(string), stdin);

    printf("A string digitada foi %s", string);

    return 0;
}
