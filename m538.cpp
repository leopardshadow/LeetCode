/*
BST inorder (left - mid - right) : ascending order
BST inorder (right - mid - left) : descending order
*/

class Solution {
    int sum = 0;
public:
    void inorder(TreeNode* node) {
        if(!node)
            return;
        inorder(node->right);
        
        sum += node->val;
        node->val = sum;
        
        inorder(node->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);        
        return root;
    }
};

/*
Runtime: 44 ms, faster than 33.11% of C++ online submissions for Convert BST to Greater Tree.
Memory Usage: 33.4 MB, less than 93.24% of C++ online submissions for Convert BST to Greater Tree.
*/
