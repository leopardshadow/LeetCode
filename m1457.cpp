
// 2022.9.14

/*
走到 leaf 時判斷是不是 palindrome
*/

class Solution {
    int ans = 0;
    int cnts[10] = { 0 };
    bool isPalin() {
        int odd = 0, even = 0;
        for (int i = 0; i < 10; i++) {
            if (cnts[i] % 2)
                odd++;
            else
                even++;
        }
        return odd <= 1;
    }
    void traverse(TreeNode* root) {
        
        if (!root)
            return;
        
        // leaf nodes
        if (!root->left && !root->right) {
            cnts[root->val]++;
            if (isPalin())
                ans++;
            cnts[root->val]--;
            return;
        }
        
        cnts[root->val]++;
        
        traverse(root->left);
        traverse(root->right);
        
        cnts[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        traverse(root);
        return ans;
    }
};
/*
Runtime: 599 ms, faster than 52.55% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
Memory Usage: 179.4 MB, less than 91.11% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
*/
