
// 2022.2.27

/*
日常看錯題目 +1 = = 以為是要求各 level 個數的最大值
---
我是想找同一 level 中編號最小、最大的差
如何編號是一個重點，我是用 heap 的編法
---
一開始沒注意到範圍，吃了一個 Runtime Error
後來把 index 都改 unsigned long long wwwww
---
但其實這樣寫過是運氣好 XD
畢竟他只有寫答案可以塞進 32 bit 和 node 數量是 [1, 3000]
如果長一條斜斜的一定會炸掉
---
比較好的作法是用字串做大數減法 (二進位)
二進位跟 heap 超搭的，×2 和 ×2+1 只是平移後補 0/1
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans = 0;
        queue<pair<unsigned long long, TreeNode*>> q;
        q.push({1, root});
        while(!q.empty()) {
            int lvlCnt = q.size();
            unsigned long long minIdx = ULLONG_MAX, 
                               maxIdx = 0;
            for(int i = 0; i < lvlCnt; i++) {
                unsigned long long idx = q.front().first;
                TreeNode* node = q.front().second;
                q.pop();
                minIdx = min(minIdx, idx);
                maxIdx = max(maxIdx, idx);
                if(node->left)
                    q.push({idx * 2, node->left});
                if(node->right)
                    q.push({idx * 2 + 1, node->right});
            }
            ans = max(ans, maxIdx - minIdx + 1);
        }
        return ans;
    }
};
/*
Runtime: 8 ms, faster than 85.32% of C++ online submissions for Maximum Width of Binary Tree.
Memory Usage: 17.4 MB, less than 48.00% of C++ online submissions for Maximum Width of Binary Tree.
*/
