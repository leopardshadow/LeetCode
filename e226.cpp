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
// recursive
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
                
//         if(!root)
//             return NULL;
        
//         // swap root->left & root->right
//         TreeNode* temp = root->left;
//         root->left = root->right;
//         root->right = temp;
        
//         invertTree(root->left);
//         invertTree(root->right);
        
//         return root;
//     }
// };

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.8 MB, less than 5.83% of C++ online submissions for Invert Binary Tree.
*/

//***************************************************************************//
// Review: 2021.11.28 before G VO

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode *left = root->left,
                 *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};

/*
Runtime: 4 ms, faster than 50.45% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.8 MB, less than 38.77% of C++ online submissions for Invert Binary Tree.
*/


// iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
                
        queue<TreeNode*> q;
        TreeNode *tn, *temp;
        
        if(root) q.push(root);
        
        while(!q.empty()) {
            tn = q.front();
            q.pop();
            
            if(!tn)
                continue;
            
            // swap left & right
            temp = tn->left;
            tn->left = tn->right;
            tn->right = temp;
            
            q.push(tn->left);
            q.push(tn->right);
        }
        
        return root;
    }
};


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.9 MB, less than 5.83% of C++ online submissions for Invert Binary Tree.
*/
