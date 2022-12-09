
// 2021.12.31 耶，跨年夜
// 大前年在英國跨年，前年在金六結，去年 12.31 考試所以在新竹，今年在台北，明年會在哪呢? XD
// 這是我首次完成 Leetcode 的月挑戰，第一個 Badge Get!! Dec, 2021
// 明年繼續加油 Annual Badge 好帥 R

/*
tree 的題目先決定如何 traversal 吧
感覺就是 inorder
---
我的想法是找到某個 node 往上的最大 (mx) / 最小值 (mi)
某值 a 的最大 differences 一定會發生在這兩個其中之一，不會是中間隨便某個數字
(這裡可以大概畫個圖感覺一下)
(寫完後發現和 Hint 說得一樣 XD)
---
在 recursively call root->left 和 right 時，去更新最大 / 最小值
*/

class Solution {
    
    int abs(int x) {
        return x >= 0 ? x : -x;
    }
    
    // mi --- mx, consider the case that a in between, > mx & < mi
    int cal(int mx, int mi, int a) {
        return max(abs(a - mx), abs(a - mi));
    }
    
    int maxAncestorDiff(int nmax, int nmin, TreeNode* root) {
        if(!root)
            return 0;
        int ret = max(
            maxAncestorDiff(max(nmax, root->val), min(nmin, root->val), root->left),
            maxAncestorDiff(max(nmax, root->val), min(nmin, root->val), root->right)
        );
        return max(ret, cal(nmax, nmin, root->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff(root->val, root->val, root);
    }
};

/*
Runtime: 4 ms, faster than 81.69% of C++ online submissions for Maximum Difference Between Node and Ancestor.
Memory Usage: 10.7 MB, less than 29.48% of C++ online submissions for Maximum Difference Between Node and Ancestor.
*/

// 2022.12.9
