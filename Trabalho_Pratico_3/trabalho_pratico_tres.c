/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int getDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int fundoEsquerdo = getDepth(root->left);
    int fundoDireito = getDepth(root->right);

    if (fundoEsquerdo > fundoDireito) {
        return 1 + fundoEsquerdo;
    } else {
        return 1 + fundoDireito;
    }
}

struct TreeNode* findSubtree(struct TreeNode* root, int depth, int currDepth) {
    if (root == NULL) {
        return NULL;
    }
    
    if (currDepth == depth) {
        return root;
    }
    
    struct TreeNode* left = findSubtree(root->left, depth, currDepth + 1);
    struct TreeNode* right = findSubtree(root->right, depth, currDepth + 1);
    
    if (left != NULL && right != NULL) {
        return root;
    }
    
    if (left != NULL) {
        return left;
    } else {
        return right;
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int maxDepth = getDepth(root);
    return findSubtree(root, maxDepth, 1);
}
