//***************************************************************************//
// 2021.11.30 before G VO

/*
用 -1 來判斷，早點結束
*/

class Solution {
public:
    int getHeight(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight = getHeight(root->left);
        if(leftHeight == -1)
            return -1;
        int rightHeight = getHeight(root->right);
        if(rightHeight == -1)
            return -1;
        if(abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(rightHeight, leftHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
};
