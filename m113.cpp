
// 2022.9.24

/*
這題要注意題目要求要到 leaf，但因為 node 值有正有負，如果中間就到 0 也不能計入
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    void traverse(TreeNode* root, int sum) {        
        if (!root)
            return;
        if (!root->left && !root->right && sum == root->val) {
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        traverse(root->left, sum - root->val);
        traverse(root->right, sum - root->val);
        path.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traverse(root, targetSum);
        return ans;
    }
};
/*
Runtime: 8 ms, faster than 92.19% of C++ online submissions for Path Sum II.
Memory Usage: 19.8 MB, less than 92.80% of C++ online submissions for Path Sum II.
*/
