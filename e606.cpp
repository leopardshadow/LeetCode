
// 2022.9.7

/*
好像感冒了 GG
*/

class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root)
            return "";
        if (!root->left && !root->right)
            return to_string(root->val);
        if (!root->right)
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};
/*
Runtime: 58 ms, faster than 21.51% of C++ online submissions for Construct String from Binary Tree.
Memory Usage: 26 MB, less than 54.89% of C++ online submissions for Construct String from Binary Tree.
*/
