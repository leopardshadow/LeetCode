// 2022.6.17

/*
原本以為只能 DP，偷看解答後發現有 greedy 的解法，而且滿直觀的
---
想法是如果在這個 node 放 camera，他自己、他的 parent 和他的左右 children 都會被蓋到
從下面開始看，就儘量往上放，讓他最有機會放一個就蓋到四個
---
先儘量衝到最底下再開始幹嘛 --> post-order
---
判斷條件是
!covered.count(node->left) --> 如果他下面有空的，不管左右，那我就 greedy 的選擇要放他身上，因為可以蓋到下面的，也有機會蓋到自己
!covered.count(node->right) --> 
(!par && !covered.count(node) --> 只有一個 node，他的左右都是 NULL
這裡不用特別檢查 node 本身，因為是由下而上的，如果左右都被蓋到了，他就會被留給更上層的蓋
---
有趣的 hard 題，這裡要寫的 code 其實不算多 ><
*/

class Solution {
    int ans;
    unordered_set<TreeNode*> covered;
    void dfs(TreeNode *node, TreeNode *par) {
        if (!node)
            return;
        
        dfs(node->left, node);
        dfs(node->right, node);
        
        if (!covered.count(node->left) || !covered.count(node->right) || (!par && !covered.count(node))) {
            ans++;
            covered.insert(node);
            covered.insert(node->left);
            covered.insert(node->right);
            covered.insert(par);
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        ans = 0;
        covered.insert(NULL);
        dfs(root, NULL);
        return ans;
    }
};
/*
Runtime: 33 ms, faster than 12.10% of C++ online submissions for Binary Tree Cameras.
Memory Usage: 23.8 MB, less than 18.52% of C++ online submissions for Binary Tree Cameras.
*/
