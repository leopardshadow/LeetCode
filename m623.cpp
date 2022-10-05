
// 2022.10.5

/*
Tree!
*/

class Solution {
    set<TreeNode*> temp;
    void findTarget(TreeNode* root, int d) {
        if (!root)
            return;
        if (d == 0) {
            temp.insert(root);
        }
        findTarget(root->left, d-1);
        findTarget(root->right, d-1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1)
            return new TreeNode(val, root, NULL);
        
        findTarget(root, depth - 2);
        for (auto n : temp) {
            n->left = new TreeNode(val, n->left, NULL);
            n->right = new TreeNode(val, NULL, n->right);
        }
        return root;
    }
};
/*
Runtime: 39 ms, faster than 34.83% of C++ online submissions for Add One Row to Tree.
Memory Usage: 25 MB, less than 62.88% of C++ online submissions for Add One Row to Tree.
*/
