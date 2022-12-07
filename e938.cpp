// 2021.12.14

/*
就只是 tree 的 traversal 加上符合條件的才加起來

不知道為什麼題目要特別說 All Node.val are unique，感覺用不太到 (?)
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, const int &low, const int &high) {
        
        if(!root)
            return 0;
        
        return (root->val >= low && root->val <= high ? root->val : 0) +
                rangeSumBST(root->left, low, high) +
                rangeSumBST(root->right, low, high);
    }
};

/*
Runtime: 120 ms, faster than 72.68% of C++ online submissions for Range Sum of BST.
Memory Usage: 64.7 MB, less than 18.44% of C++ online submissions for Range Sum of BST.
*/

// 
