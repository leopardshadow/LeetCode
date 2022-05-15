
// 2022.5.15

/*
先找到最大深度再拿最大深度的 node 值加在一起
*/

class Solution {
    
    int deepest = 0, sum = 0;
    
    void findDepth(TreeNode* root, int depth) {
        if (!root)
            deepest = max(deepest, depth - 1);
        else {
            findDepth(root->left, depth + 1);
            findDepth(root->right, depth + 1);
        }
    }
    
    void deepestSum(TreeNode* root, int depth) {
        if (!root)
            return;
        else if (depth == deepest)
            sum += root->val;
        else {
            deepestSum(root->left, depth + 1);
            deepestSum(root->right, depth + 1);
        }
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        findDepth(root, 0);
        deepestSum(root, 0);
        return sum;
    }
};
/*
Runtime: 149 ms, faster than 31.26% of C++ online submissions for Deepest Leaves Sum.
Memory Usage: 59.8 MB, less than 76.50% of C++ online submissions for Deepest Leaves Sum.
*/
