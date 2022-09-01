
// 2022.9.1

/*
路徑上的最大值，可以像這樣用一個全域的變數去存，或是個別存在 call stack 裡 (多傳一個 int max 的參數)
*/


class Solution {
    int ans = 0;
    map<int, int> m;
    void solve(TreeNode* node) {
        
        if (!node)
            return;
        
        m[node->val]++;
        
        solve(node->left);
        
        if (m.rbegin()->first <= node->val)
            ans++;
        solve(node->right);

        m[node->val]--;
        if (m[node->val] == 0)
            m.erase(node->val);
    }
public:
    int goodNodes(TreeNode* root) {
        solve(root);
        return ans;
    }
};
/*
Runtime: 533 ms, faster than 5.02% of C++ online submissions for Count Good Nodes in Binary Tree.
Memory Usage: 164.3 MB, less than 5.05% of C++ online submissions for Count Good Nodes in Binary Tree.
*/
