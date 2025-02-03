#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50 //define a quantidade de caracteres para os dados 
#define TAM_BUFFER 10000 //define a quantidade de memoria que vai ser reservada para o malloc

int main() {
    void *pBuffer = malloc(sizeof(void *) * 3 + TAM_BUFFER);
    if (!pBuffer) {
        printf("nao foi possivel alocar a memoria");
        return 1;
    }

    *(void **)pBuffer = NULL;                        // ponteiro para o inicio da lista
    *(void **)(pBuffer + sizeof(void *)) = pBuffer + sizeof(void *) * 3;  // ponteiro para o proximo espaco livre

    do {
        printf("1- Adicionar Pessoa\n2- Remover Pessoa\n3- Buscar Pessoa\n4- Listar Todos\n5- Sair\n");
        scanf("%d", (int *)(pBuffer + sizeof(void *) * 2));
        getchar();

        if (*((int *)(pBuffer + sizeof(void *) * 2)) == 1) {  // adicionar pessoa
            void *livre = *(void **)(pBuffer + sizeof(void *));

            printf("nome: ");
            fgets(livre, TAM, stdin);
            ((char *)livre)[strcspn(livre, "\n")] = '\0';

            printf("idade: ");
            scanf("%d", (int *)(livre + TAM));
            getchar();

            printf("email: ");
            fgets(livre + TAM + sizeof(int), TAM, stdin);
            ((char *)(livre + TAM + sizeof(int)))[strcspn(livre + TAM + sizeof(int), "\n")] = '\0';

            *(void **)(livre + TAM + sizeof(int) + TAM) = *(void **)pBuffer;
            *(void **)pBuffer = livre;

            *(void **)(pBuffer + sizeof(void *)) = livre + TAM + sizeof(int) + TAM + sizeof(void *); // atualiza o ponteiro para o proximo espaco livre

        } else if (*((int *)(pBuffer + sizeof(void *) * 2)) == 2) {  // remove o nome
            if (*(void **)pBuffer == NULL) {
                printf("lista vazia\n");
            } else {
                void *nomeRemover = pBuffer + sizeof(void *) * 3 + TAM_BUFFER - TAM;
                printf("digite um nome para remover: ");
                fgets(nomeRemover, TAM, stdin);
                ((char *)nomeRemover)[strcspn(nomeRemover, "\n")] = '\0';

                void *atual = *(void **)pBuffer;
                void *anterior = NULL;

                while (atual != NULL) {
                    if (strcmp((char *)atual, (char *)nomeRemover) == 0) {
                        if (anterior == NULL) {
                            *(void **)pBuffer = *(void **)(atual + TAM + sizeof(int) + TAM);
                        } else {
                            *(void **)(anterior + TAM + sizeof(int) + TAM) = *(void **)(atual + TAM + sizeof(int) + TAM);
                        }
                        printf("nome  removida\n");
                        break;
                    }
                    anterior = atual;
                    atual = *(void **)(atual + TAM + sizeof(int) + TAM);
                }

                if (atual == NULL) {
                    printf("pessoa nao encontrada\n");
                }
            }

        } else if (*((int *)(pBuffer + sizeof(void *) * 2)) == 3) {  // buscar pessoa
            void *nomeBusca = pBuffer + sizeof(void *) * 3 + TAM_BUFFER - TAM;
            printf("procure um nome: ");
            fgets(nomeBusca, TAM, stdin);
            ((char *)nomeBusca)[strcspn(nomeBusca, "\n")] = '\0';

            void *atual = *(void **)pBuffer;
            while (atual != NULL) {
                if (strcmp((char *)atual, (char *)nomeBusca) == 0) {
                    printf("Nome: %s\n", (char *)atual);
                    printf("Idade: %d\n", *((int *)(atual + TAM)));
                    printf("Email: %s\n", (char *)(atual + TAM + sizeof(int)));
                    break;
                }
                atual = *(void **)(atual + TAM + sizeof(int) + TAM);
            }

            if (atual == NULL) {
                printf("pessoa nao encontrada\n");
            }

        } else if (*((int *)(pBuffer + sizeof(void *) * 2)) == 4) {  // listar todos
            void *atual = *(void **)pBuffer;
            if (atual == NULL) {
                printf("lista vazia\n");
            } else {
                while (atual != NULL) {
                    printf("nome: %s\n", (char *)atual);
                    printf("idade: %d\n", *((int *)(atual + TAM)));
                    printf("email: %s\n", (char *)(atual + TAM + sizeof(int)));
                    atual = *(void **)(atual + TAM + sizeof(int) + TAM);
                }
            }
        }

    } while (*((int *)(pBuffer + sizeof(void *) * 2)) != 5);

    free(pBuffer);
    return 0;
}
