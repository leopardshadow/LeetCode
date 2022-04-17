
// 2022.4.17

/*
lee215 的解只有五行，他在參數裡傳遞兩個東西
increasingBST(TreeNode root, TreeNode tail)
 - root 是原本的
 - tail 是 inorder order 的下一個 node
<有點難懂 OAO>
*/

class Solution {
    TreeNode *prev = NULL, *newRoot = NULL;
public:
    void inorder(TreeNode* node) {
        if (!node)
            return;
        inorder(node->left);
        if (!prev) {
            prev = node;
            newRoot = node;
        }
        else {
            prev->left = NULL;
            prev->right = node;
            prev = node;
        }
        inorder(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        prev->left = NULL;
        prev->right = NULL;
        return newRoot;
    }
};
/*
Runtime: 3 ms, faster than 65.44% of C++ online submissions for Increasing Order Search Tree.
Memory Usage: 7.7 MB, less than 77.99% of C++ online submissions for Increasing Order Search Tree.
*/
