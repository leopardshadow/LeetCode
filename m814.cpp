
// 2022.9.6

/*
注意順序R
什麼 order
*/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
            return NULL;
        return root;
    }
};
/*
Runtime: 3 ms, faster than 71.58% of C++ online submissions for Binary Tree Pruning.
Memory Usage: 8.8 MB, less than 21.01% of C++ online submissions for Binary Tree Pruning.
*/
