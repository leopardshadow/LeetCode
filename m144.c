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
        // only the order is changed
        /******************/
        arr[*i] = root->val;
        (*i) += 1;
        /******************/
        fillArray(root->left, arr, i);
        fillArray(root->right, arr, i);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = calSize(root);
    int *retArray = malloc(sizeof(int)*(*returnSize));
    int i = 0;
    fillArray(root, retArray, &i);
    return retArray;
}

/*
Same as 94, except inorder (94) and preorder (144)
*/

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Tree Preorder Traversal.
Memory Usage: 5.8 MB, less than 97.21% of C online submissions for Binary Tree Preorder Traversal.
*/