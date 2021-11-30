//***************************************************************************//
// 2021.11.30 before G VO

class Solution {
public:
    
    // 最後沒用到，一開始錯誤的邏輯
    // bool equal(TreeNode* root1, TreeNode* root2) {
    //     if(!root1 && !root2)
    //         return true;
    //     else if(!root1 || !root2)
    //         return false;
    //     else if(root1->val != root2->val)
    //         return false;
    //     return equal(root1->left, root2->left) && equal(root1->right, root2->right);
    // }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 && !root2)
            return true;
        else if(!root1 || !root2)
            return false;
        else if(root1->val != root2->val)
            return false;
        
        TreeNode *l1 = root1->left,
                 *r1 = root1->right,
                 *l2 = root2->left,
                 *r2 = root2->right;
        return (flipEquiv(l1, l2) && flipEquiv(r1, r2)) || (flipEquiv(l1, r2) && flipEquiv(r1, l2));
    }
};

/*
Runtime: 4 ms, faster than 60.25% of C++ online submissions for Flip Equivalent Binary Trees.
Memory Usage: 12.2 MB, less than 48.37% of C++ online submissions for Flip Equivalent Binary Trees.
*/
