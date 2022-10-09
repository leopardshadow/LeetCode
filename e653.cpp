
// 2022.10.9

/*
pre-order
記錄走過路徑的值
找的目標：target - val，如果能從走過的路徑找到，Gotcha!
*/

class Solution {
    unordered_set<int> s;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || 
               findTarget(root->right, k);
    }
};
/*
Runtime: 91 ms, faster than 30.90% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 38.7 MB, less than 33.49% of C++ online submissions for Two Sum IV - Input is a BST.
*/
