
// 2022.12.10

/*
Key: 找到 subtree 的 sum 和全部的總和後就可以來比大小
比較各個 sum(subtree) * (wholeSum - sum(subtree))
*/

class Solution {
    set<int> s;
    int calSum(TreeNode *root) {
        if (!root)
            return 0;
        int sum = root->val + calSum(root->left) + calSum(root->right);
        s.insert(sum);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long sum = calSum(root), ans = 0;
        for (const int &n : s) {
            ans = max(ans, (sum - n) * n);
        }
        return ans % 1000000007;
    }
};
