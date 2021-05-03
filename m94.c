struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdlib.h>


int calSize(struct TreeNode* root) {
    if(!root)
        return 0;
    else
        return calSize(root->left) + calSize(root->right) + 1;
}


void fillArray(struct TreeNode* root, int *arr, int *i) {
    if(root) {
        fillArray(root->left, arr, i);
        arr[*i] = root->val;
        (*i) += 1;
        fillArray(root->right, arr, i);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = calSize(root);
    int *retArray = malloc(sizeof(int)*(*returnSize));
    int i = 0;
    fillArray(root, retArray, &i);
    return retArray;
}

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Tree Inorder Traversal.
Memory Usage: 5.7 MB, less than 95.61% of C online submissions for Binary Tree Inorder Traversal.
*/