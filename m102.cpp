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
private:
    vector<vector<int> > ans;
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        levelOrderTraverse(root, 0);
        return ans;
    }
    void levelOrderTraverse(TreeNode* root, int depth) {
        if(!root) return;
        // if that level doesn't exist yet
        if(ans.size() <= depth)
            ans.push_back(vector<int>());
        ans[depth].push_back(root->val);
        levelOrderTraverse(root->left, depth + 1);
        levelOrderTraverse(root->right, depth + 1);
    }
};

/*
Runtime: 3 ms, faster than 83.06% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 13.6 MB, less than 8.50% of C++ online submissions for Binary Tree Level Order Traversal.
*/