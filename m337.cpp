/*
這題滿有趣的，結合了樹和 DP
兩個狀態：搶 / 不搶
* 搶這個節點的最大利益 = 他的左、右子節點都不能搶的利益總和
* 不搶這個節點的最大利益 = 左、右的最大利益總和 = max{左搶, 左不搶} + max{右搶, 右不搶}
---
因為我們從 leaf 開始弄，所以用 post-order 的 traversal
*/
class Solution {
                             // rob don't rob
    unordered_map<TreeNode*, pair<int, int>> m;
public:
    
    void postorder(TreeNode* root) {
        
        if(!root)
            return;

        // this is covered below
        // if(!root->left && !root->right) {
        //     m[root] = {root->val, 0};
        //     return;
        // }
            
        postorder(root->left);
        postorder(root->right);
        
        m[root] = {
            root->val + m[root->left].second + m[root->right].second, // rob
            max(m[root->left].first, m[root->left].second) + max(m[root->right].first, m[root->right].second)}; // don't rob
    }
    
    int rob(TreeNode* root) {
        m[NULL] = {0, 0};
        postorder(root);
        return max(m[root].first, m[root].second);
    }
};

/*
Runtime: 20 ms, faster than 48.00% of C++ online submissions for House Robber III.
Memory Usage: 25.6 MB, less than 25.04% of C++ online submissions for House Robber III.
*/
