/*
這題要只留下 BST 中，在 [low, high] 之間的節點
如果 root-val 在這個範圍內，那他自己不用動，但他的左、右可能被修改
如果 root->val 自己小於 low ，那他左邊就是 NULL 了，因為左邊都更小，所以回傳修改過後的右邊
如果 root->val 自己大於 high，那他右邊就是 NULL 了，因為右邊都更大，所以回傳修改過後的左邊
*/


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)
            return NULL;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

/*
Runtime: 16 ms, faster than 62.17% of C++ online submissions for Trim a Binary Search Tree.
Memory Usage: 24 MB, less than 7.06% of C++ online submissions for Trim a Binary Search Tree.
*/
