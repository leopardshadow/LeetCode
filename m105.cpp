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

    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int, int> pos;
    
    TreeNode* buildTree(int preS, int preE, int inS, int inE) {
        
        if(preS > preE)
            return NULL;
        
        int inM = pos[preorder[preS]];
        int leftSize = inM - inS;
        int rightSize = inE - inM;
        
        TreeNode *root = new TreeNode(preorder[preS]);
        root->left = buildTree(preS + 1, preS + leftSize, inS, inM-1);
        root->right = buildTree(preE - rightSize + 1 , preE, inM+1, inE);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        this->preorder = preorder;
        this->inorder = inorder;
        
        for(int i = 0; i < preorder.size(); i++)
            pos[inorder[i]] = i;
        
        return buildTree(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};


/*
Runtime: 12 ms, faster than 92.99% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 26.6 MB, less than 17.02% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
*/