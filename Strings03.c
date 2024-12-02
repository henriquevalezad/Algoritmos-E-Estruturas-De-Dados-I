//Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’ (maiuscula ou minuscula).
#include <stdio.h>

int main() {
    char nome[100];

    fgets(nome, sizeof(nome), stdin);

    if (nome[0] == 'a' || nome[0] == 'A') {
        printf("%s", nome);
    } else {
        printf("o nome deve começar com a letra 'a'");
    }

    return 0;
}


