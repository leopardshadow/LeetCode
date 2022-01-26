 
// 2022.1.26

/*
一次 traverse 兩棵樹，看起不能 recursive 得跑過整棵樹，只能用 iterative
這是我一開始的想法
---
但是 hint 也叫人兩個 tree 分開做，最後再 sort ...
這樣寫是很簡單，但是時間複雜度是 O(n log n)，因為可以更快的
---

*/

class Solution {
    vector<int> ans;
    void inorder(TreeNode *node) {
        if(!node)
            return;
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Runtime: 136 ms, faster than 75.44% of C++ online submissions for All Elements in Two Binary Search Trees.
Memory Usage: 85.2 MB, less than 62.58% of C++ online submissions for All Elements in Two Binary Search Trees.
*/
