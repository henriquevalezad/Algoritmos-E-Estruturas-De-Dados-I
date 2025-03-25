struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* esquerdo = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* direito = lowestCommonAncestor(root->right, p, q);

    if (esquerdo != NULL && direito != NULL) {
        return root;
    }
    
    if (esquerdo != NULL) {
        return esquerdo;
    } else {
        return direito;
    }
}
