#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int levels[10000] = {0};
int final = 0;

int mmax(int a, int b) {
    return a < b ? b : a;
}

void dfs(struct TreeNode *root, int level) {
    final = mmax(final,level);
    levels[level]+=root->val;
    if (root->left != NULL) dfs(root->left, level+1);
    if (root->right != NULL) dfs(root->right, level+1);
}

int maxLevelSum(struct TreeNode* root) {
    for (int i=0; i<10000; i++) {
        levels[i] = 0;
    }
    dfs(root,0);
    int maxLevel = -1000000;
    int index = 0;
    for (int i=0; i<final; i++) {
        if (levels[i] > maxLevel) {
            index = i;
            maxLevel = levels[i];
        }
    }
    return index+1;
}

int main() {
    struct TreeNode d = {-8, nullptr, nullptr};
    struct TreeNode c = {7, nullptr, nullptr};
    struct TreeNode b = {0, nullptr, nullptr};
    struct TreeNode a = {7, &c, &d};
    struct TreeNode root = {1, &b, &a};

    int result = maxLevelSum(&root);

    printf("%d\n", result);
    return 0;
}