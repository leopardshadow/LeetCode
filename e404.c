
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root){
    if(!root)
        return 0;
    if(root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);
    else
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);    
}

/*
Runtime: 4 ms, faster than 59.55% of C online submissions for Sum of Left Leaves.
Memory Usage: 6.3 MB, less than 55.06% of C online submissions for Sum of Left Leaves.
*/