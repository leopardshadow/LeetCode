/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // both of them are NULL
        if(!root && !subRoot)
            return true;
        
        // one of them is NULL
        else if(!root || !subRoot)
            return false;
        
        bool b = false;
        if(root->val == subRoot->val) {
            b = isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right);
        }

        return b || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};