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
// class Solution {
// private:
//     vector<vector<int> > ans;
// public:
//     vector<vector<int> > levelOrder(TreeNode* root) {
//         levelOrderTraverse(root, 0);
//         return ans;
//     }
//     void levelOrderTraverse(TreeNode* root, int depth) {
//         if(!root) return;
//         // if that level doesn't exist yet
//         if(ans.size() <= depth)
//             ans.push_back(vector<int>());
//         ans[depth].push_back(root->val);
//         levelOrderTraverse(root->left, depth + 1);
//         levelOrderTraverse(root->right, depth + 1);
//     }
// };

/*
Runtime: 3 ms, faster than 83.06% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 13.6 MB, less than 8.50% of C++ online submissions for Binary Tree Level Order Traversal.
*/



class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        
        vector<vector<int> > ans;
        int depth = 0;
        vector<pair<TreeNode*, int> > q;
        pair<TreeNode*, int> p;
        
        if(root)
            q.push_back(pair<TreeNode*, int>(root, 0));
        
        while(!q.empty()) {
            p = q[0];
            q.erase(q.begin());
            if(ans.size() <= p.second)
                ans.push_back(vector<int>());

            ans[p.second].push_back(p.first->val);
            if(p.first->left)
                q.push_back(pair<TreeNode*, int>(p.first->left, p.second+1));
            if(p.first->right)
                q.push_back(pair<TreeNode*, int>(p.first->right, p.second+1));
        }
        return ans;
    }
};
/*
Runtime: 4 ms, faster than 75.79% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.5 MB, less than 61.82% of C++ online submissions for Binary Tree Level Order Traversal.
*/




//***************************************************************************//
// Review: 2021.11.28 before G VO

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            ans.push_back(vector<int>());

            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                TreeNode *node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 35.08% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.3 MB, less than 96.21% of C++ online submissions for Binary Tree Level Order Traversal.
*/
