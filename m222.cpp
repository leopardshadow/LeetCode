
// 2022.11.15

/*
不用到 complete tree 的偷懶做法
*/

class Solution {
    int ans;
    void traverse(TreeNode* root) {
        if (!root)
            return;
        ans++;
        traverse(root->right);
        traverse(root->left);
    }
public:
    int countNodes(TreeNode* root) {
        ans = 0;
        traverse(root);
        return ans;
    }
};
/*
Runtime: 45 ms, faster than 79.56% of C++ online submissions for Count Complete Tree Nodes.
Memory Usage: 30.9 MB, less than 20.93% of C++ online submissions for Count Complete Tree Nodes.
*/
