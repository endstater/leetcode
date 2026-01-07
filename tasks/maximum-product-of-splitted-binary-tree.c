#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

unsigned long long mmax(unsigned long long a, unsigned long long b) {
    return a < b ? b : a;
}

unsigned long long sumDfs(struct TreeNode *root) {
    if (root->left != NULL) root->val+=sumDfs(root->left);
    if (root->right != NULL) root->val+=sumDfs(root->right);
    return root->val;
}

unsigned long long productDfs(struct TreeNode *root, unsigned long long *result, unsigned long long *rootSum) {
    if (root->left != NULL) *result = mmax(*result, productDfs(root->left, result, rootSum));
    if (root->right != NULL) *result = mmax(*result, productDfs(root->right, result, rootSum));
    return ((unsigned long long)*rootSum - (unsigned long long)root->val) * (unsigned long long) root->val;
}

int maxProduct(struct TreeNode* root) {
    unsigned long long result = 0;
    unsigned long long rootSum = 0;
    rootSum = sumDfs(root);
    productDfs(root, &result, &rootSum);
    return (int) (result % 1000000007);
}

int main() {
    struct TreeNode e = {6, nullptr, nullptr};
    struct TreeNode d = {5, nullptr, nullptr};
    struct TreeNode c = {4, nullptr, nullptr};
    struct TreeNode b = {3, &e, nullptr};
    struct TreeNode a = {2, &c, &d};
    struct TreeNode root = {1, &b, &a};

    int result = maxProduct(&root);

    printf("%d\n", result);
    return 0;
}