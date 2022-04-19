
// 2022.4.19

/*
偷懶的 O(n) space complexity 解法
*/

class Solution {
    vector<int> nums;
    int i;
public:
    void getNums(TreeNode* root) {
        if (!root) return;
        getNums(root->left);
        nums.push_back(root->val);
        getNums(root->right);
    }
    void recoverBST(TreeNode* root) {
        if (!root) return;
        recoverBST(root->left);
        root->val = nums[i++];
        recoverBST(root->right);
    }
    void recoverTree(TreeNode* root) {
        getNums(root);
        sort(nums.begin(), nums.end());
        i = 0;
        recoverBST(root);
    }
};
/*
Runtime: 51 ms, faster than 40.60% of C++ online submissions for Recover Binary Search Tree.
Memory Usage: 58.1 MB, less than 35.12% of C++ online submissions for Recover Binary Search Tree.
*/


/*
參考了討論區
嘗試不把整條 array 記下來的解法 (應該不能算 SC O(1)，遞迴呼叫的部分不是)
先用 array 來看，有兩種情況：換的在隔壁、換的不在隔壁
[1, 7, 3, 4, 5, 6, 2, 8]
    p  r        p  r
    *              *
---
[1, 3, 2, 4]
    p  r
*/

class Solution {
    TreeNode *prev;
    vector<TreeNode*> mistakes;
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        
        // 判斷條件！！！！！
        if (!mistakes[0] && root->val < prev->val)
            mistakes[0] = prev;
        if (mistakes[0] && root->val < prev->val)
            mistakes[1] = root;

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        mistakes = vector<TreeNode*>(2, NULL);
        inorder(root);
        swap(mistakes[0]->val, mistakes[1]->val);
    }
};
/*
Runtime: 44 ms, faster than 55.79% of C++ online submissions for Recover Binary Search Tree.
Memory Usage: 58.1 MB, less than 35.12% of C++ online submissions for Recover Binary Search Tree.
*/
