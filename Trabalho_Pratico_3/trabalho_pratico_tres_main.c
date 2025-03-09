#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int profundidade(struct TreeNode* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int fundoEsquerdo = profundidade(raiz->left);
    int fundoDireito = profundidade(raiz->right);

    if (fundoEsquerdo > fundoDireito) {
        return 1 + fundoEsquerdo;
    } else {
        return 1 + fundoDireito;
    }
}

struct TreeNode* subArvore(struct TreeNode* raiz, int profundidade, int profundidadeAtual) {
    if (raiz == NULL) {
        return NULL;
    }
    
    if (profundidadeAtual == profundidade) {
        return raiz;
    }
    
    struct TreeNode* left = subArvore(raiz->left, profundidade, profundidadeAtual + 1);
    struct TreeNode* right = subArvore(raiz->right, profundidade, profundidadeAtual + 1);
    
    if (left != NULL && right != NULL) {
        return raiz;
    }
    
    if (left != NULL) {
        return left;
    } else {
        return right;
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* raiz) {
    int maxDepth = profundidade(raiz);
    return subArvore(raiz, maxDepth, 1);
}

struct TreeNode* criarNo(int valor) {
    struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novoNo->val = valor;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

int main() {
    struct TreeNode* raiz = criarNo(1);
    raiz->left = criarNo(2);
    raiz->right = criarNo(3);
    raiz->left->left = criarNo(4);
    raiz->left->right = criarNo(5);
    raiz->right->right = criarNo(6);
    raiz->left->left->left = criarNo(7);
    raiz->left->left->right = criarNo(8);

    struct TreeNode* subArvoreProfunda = subtreeWithAllDeepest(raiz);

    if (subArvoreProfunda != NULL) {
        printf(" %d\n", subArvoreProfunda->val);
    } else {
        printf("a\n");
    }

    return 0;
}
