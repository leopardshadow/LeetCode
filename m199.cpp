
// 2022.7.11

/*
這週輪到 tree 嗎？滿喜歡 tree 的題目！
*/

class Solution {
    vector<int> ans;
    void preorder(TreeNode *node, int depth) {
        if (node) {
            if (ans.size() < depth)
                ans.push_back(node->val);
            ans[depth - 1] = node->val;
            preorder(node->left, depth + 1);
            preorder(node->right, depth + 1);
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        preorder(root, 1);
        return ans;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
Memory Usage: 11.8 MB, less than 88.71% of C++ online submissions for Binary Tree Right Side View.
*/
