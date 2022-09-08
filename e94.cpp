// 像這種題目要用 iterative 的方式寫都好不直觀喔 @@

// class Solution {
// public:
    
//     void inorder(TreeNode* root, vector<int> &v) {
//         if(!root) return;
//         inorder(root->left, v);
//         v.push_back(root->val);
//         inorder(root->right, v);
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inorder(root, ans);
//         return ans;
//     }
// };

// 嘗試從 recursive 改寫的話

// 如果要求用 iterative 應該不是 easy 等級吧

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

// Cool iterative solution !!!
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.4 MB, less than 23.68% of C++ online submissions for Binary Tree Inorder Traversal.
*/


// 2022.9.8
