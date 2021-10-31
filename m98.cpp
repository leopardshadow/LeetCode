/*
我是利用 BST 左邊所有節點都比這個節點小，右邊所有節點都比這個節點大，這樣遞迴往下
看到也有人是把他 in-order 的 traverse 過一次，他的印出來順序剛好會是排序過的，只要檢查這點就好了

我有特別處理值在 INT_MIN 和 INT_MAX 的 case，多寫了 shouldBigger 和 shouldSmaller
如果他的 range 都不在那麼邊邊，只要 inRange 就好了
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return shouldSmaller(root->left, root->val) &&
               shouldBigger(root->right, root->val);
    }
    // all the tree nodes should be in range (a, b)
    bool shouldInRange(TreeNode* root, int a, int b) {
        if(!root) return true;
        if(root->val <= a || root->val >= b) return false;
        return shouldInRange(root->left, a, root->val) && 
               shouldInRange(root->right, root->val, b);
    }
    // all the tree nodes should be bigger than n (> n)
    bool shouldBigger(TreeNode* root, int n) {
        if(!root) return true;
        if(root->val <= n)
            return false;
        return shouldInRange(root->left, n, root->val) && shouldBigger(root->right, root->val);
    }
    // all the tree nodes should be smaller than n (< n)
    bool shouldSmaller(TreeNode* root, int n) {
        if(!root) return true;
        if(root->val >= n)
            return false;
        return shouldSmaller(root->left, root->val) && shouldInRange(root->right, root->val, n);
    }
};

/*
Runtime: 4 ms, faster than 98.93% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.7 MB, less than 30.44% of C++ online submissions for Validate Binary Search Tree.
*/