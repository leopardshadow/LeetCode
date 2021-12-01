//***************************************************************************//
// 2021.12.1 before G VO

/*
雖然是 easy 但之前有點卡關 QQ
*/

class Solution {
public:
    // Key:
    bool solve(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return true;
        if(!t1 || !t2 || t1->val != t2->val)
            return false;
        return solve(t1->left, t2->right) && solve(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
