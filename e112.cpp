/*
他要的是 root to leaf，所以
    1
   /    targetSum = 1 要回傳 false
  2 
 在寫 tree 的題目時要注意他到底要什麼啦 @@
 leaf 是左、右都是 NULL
*/
class Solution {
public:
    bool hasPathSum(int sum, TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(!root->left && !root->right)
            return sum + root->val == targetSum;
        return hasPathSum(sum + root->val, root->left, targetSum) ||
               hasPathSum(sum + root->val, root->right, targetSum);
    } 
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(0, root, targetSum);
    }
};

/*
Runtime: 20 ms, faster than 11.88% of C++ online submissions for Path Sum.
Memory Usage: 21.4 MB, less than 38.16% of C++ online submissions for Path Sum.
*/
