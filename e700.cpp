// 2022.4.14

/*
居然是第一次寫這題？？？？
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return NULL;
        else if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
/*
Runtime: 58 ms, faster than 44.30% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 34.8 MB, less than 66.88% of C++ online submissions for Search in a Binary Search Tree.
*/
