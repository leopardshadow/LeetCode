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



// 2022.4.16

/*
他說要把 BST 轉成 greater tree，原先的 key 值要再加上所有大於他的 key 值
 --> inorder traversal
*/

class Solution {
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return NULL;
        convertBST(root->right);
        sum += root->val;
        root->val = sum; 
        convertBST(root->left);
        return root;
    }
};
/*
Runtime: 46 ms, faster than 68.13% of C++ online submissions for Convert BST to Greater Tree.
Memory Usage: 33.6 MB, less than 19.45% of C++ online submissions for Convert BST to Greater Tree.
*/
