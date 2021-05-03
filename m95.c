struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdlib.h>

struct TreeNode** generateTrees(int n, int* returnSize){
    *returnSize = 1 << (n-1);
    struct TreeNode** root = malloc(sizeof(struct TreeNode*) * (*returnSize));
    int i, j, num, tmp;
    for(i = 0; i < *returnSize; i++) {
        root[i] = calloc(sizeof(struct TreeNode*), 1);
        tmp = i;
        for(j = 0; j < n; j++) {
            if(tmp )
        }
    }
    returnSize root;
}