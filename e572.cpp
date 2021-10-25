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
        
        if(!root)
            return false;
        
        if(isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSameTree(TreeNode* a, TreeNode* b) {
        
        // both of them are NULL
        if(!a && !b)
            return true;
        
        // one of them is NULL
        else if(!a || !b)
            return false;
        
        // not the same
        else if(a->val != b->val)
            return false;
        
        // none of them is NULL
        else 
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);

    }
};

/*
Runtime: 42 ms, faster than 22.65% of C++ online submissions for Subtree of Another Tree.
Memory Usage: 28.8 MB, less than 83.19% of C++ online submissions for Subtree of Another Tree.
*/