
// 原本 399，為了湊到 400，從 Top 100 Liked 挑一題 Medium 來湊 XD
// 紀念的第 400 題
// 200 題是面 G 的時候，花了六個月 (時間過好快！) double

/*
pre-order
*/

class Solution {
    TreeNode *prev = NULL; 
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        TreeNode *left = root->left, *right = root->right;
        
        if (!prev)
            prev = root;
        else {
            prev->right = root;
            prev->left = nullptr;
            prev = root;
        }
        
        flatten(left);
        flatten(right);
    }
    
};
/*
Runtime: 10 ms, faster than 45.27% of C++ online submissions for Flatten Binary Tree to Linked List.
Memory Usage: 12.8 MB, less than 40.81% of C++ online submissions for Flatten Binary Tree to Linked List.
*/
