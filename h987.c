
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calMinCol(struct TreeNode* root) {
    int col = 0;
    while(root->left) {
        --col;
        root = root->left;
    }
    return col;
}

int calMaxCol(struct TreeNode* root) {
    int col = 0;
    while(root->right) {
        ++col;
        root = root->right;
    }
    return col;
}

void traverseTree(struct TreeNode* root, int** returnColumns, int col, int *minCol) {
    if(!root)
        return;
    printf("%d\n", col-(*minCol));
    (*returnColumns)[col-(*minCol)] += 1;
    traverseTree(root->left, returnColumns, col-1, minCol);
    traverseTree(root->right, returnColumns, col+1, minCol);
}


int** verticalTraversal(struct TreeNode* root, int* returnSize, int** returnColumns){

    int minCol = calMinCol(root),
        maxCol = calMaxCol(root),
        colSize = maxCol - minCol + 1;
    
    printf("min = %d, max = %d, size = %d\n", minCol, maxCol, colSize);

    *returnSize = colSize;
    *returnColumns = calloc(sizeof(int), colSize);

    printf("oao\n");

    traverseTree(root, returnColumns, 0, &minCol);

    printf("...\n");


    for(int i = 0; i < colSize; i++) {
        printf("retrun size [%d] %d\n", i, (*returnColumns)[i]);
    }

    int **ans;

    ans = calloc(sizeof(int*), colSize);
    for(int i = 0; i < colSize; i++) {
        ans[i] = calloc(sizeof(int), (*returnColumns)[i]);
    }

    return ans;
}


void printTree(struct TreeNode* root) {
    if(!root) return;
    printTree(root->right);
    printf("%d\n", root->val);
    printTree(root->left);
}


int main(int argc, char const *argv[])
{
    int **ans;
    int returnSize;

    struct TreeNode* root = calloc(sizeof(struct TreeNode*), 1);
    root->val = 10;
    root->right = calloc(sizeof(struct TreeNode*), 1);
    root->left = 0;
    root->right->val = 20;
    root->right->right = calloc(sizeof(struct TreeNode*), 1);
    root->right->right->val = 30;
    root->right->left = 0;
    root->right->right->right = 0;
    root->right->right->left = 0;

    // printTree(root);

    verticalTraversal(root, &returnSize, ans);

    return 0;
}
