// class Solution {
//     vector<int> ans;
// public:
//     void postorder(TreeNode* root) {
//         if(!root) return;
//         postorder(root->left);
//         postorder(root->right);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         postorder(root);
//         return ans;
//     }
// };
/*
Runtime: 4 ms, faster than 43.74% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.5 MB, less than 63.08% of C++ online submissions for Binary Tree Postorder Traversal.
*/



// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();
//             if(!node) continue;
//             ans.insert(ans.begin(), node->val); // this operation here is actually not a O(1) one
//             st.push(node->left);
//             st.push(node->right);
//         }
//         return ans;
//     }
// };

/*
Runtime: 4 ms, faster than 43.74% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.4 MB, less than 86.17% of C++ online submissions for Binary Tree Postorder Traversal.
*/


// cool solution from discussion

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            if(!node) continue;
            st2.push(node);
            st1.push(node->left);
            st1.push(node->right);
        }
            while(!st2.empty()) {
            TreeNode* node = st2.top();
            st2.pop();
            if(!node) continue;
            ans.push_back(node->val);
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 43.74% of C++ online submissions for Binary Tree Postorder Traversal.
Memory Usage: 8.3 MB, less than 86.17% of C++ online submissions for Binary Tree Postorder Traversal.
*/
