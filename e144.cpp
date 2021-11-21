// 看 Leetcode 上 submission 的紀錄，應該之前在實習前練習題目時有寫過，那時候用 C，但既然沒存
// 算了，這次來練習不用 recursion 的版本

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *tn = st.top();
            st.pop();
            if(tn == NULL)
                continue;
            ans.push_back(tn->val);
            // !!! 先 right 再 left !!! 他是 stack 啊啊啊
            st.push(tn->right);
            st.push(tn->left);
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 44.35% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.3 MB, less than 75.87% of C++ online submissions for Binary Tree Preorder Traversal.
*/
