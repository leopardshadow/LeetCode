
// 2022.1.11

/*
這個寫法參考了討論區中 lee215 的做法，好精簡
---
原本我是想用一個 data member n，讓他左移、右移，但這樣好麻煩
---
這個做法把 states 都包在 function 裡，好讚!!
*/

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if(!root)
            return 0;
        val = (val << 1) | root->val;
        if(!root->left && !root->right)
            return val;
        else
            return sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};

/*
Runtime: 8 ms, faster than 53.68% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
Memory Usage: 16.7 MB, less than 43.41% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
*/
