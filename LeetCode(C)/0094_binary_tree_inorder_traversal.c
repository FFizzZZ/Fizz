#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode *node, int *i, int *ret)
{
    if (node == NULL) {
        return;
    }

    traverse(node->left, i, ret);
    ret[*i] = node->val;
    *i += 1;
    traverse(node->right, i, ret);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * SIZE);
    int i = 0;

    traverse(root, &i, ret);
    *returnSize = i;

    return ret;
}
