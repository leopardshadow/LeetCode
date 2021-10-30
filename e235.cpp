/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
啊啊啊啊  他是 BST 啊，一開始沒看清楚，還以為他是什麼一顆隨便的樹...
*/

// recursive

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         if(root->val > p->val && root->val > q->val)
//             return lowestCommonAncestor(root->left, p, q);
        
//         else if(root->val < p->val && root->val < q->val)
//             return lowestCommonAncestor(root->right, p, q);

//         return root;
//     }
// };

/*
Runtime: 44 ms, faster than 26.53% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.3 MB, less than 11.91% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/



// iterative

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        while(root->val > p->val && root->val > q->val ||
              root->val < p->val && root->val < q->val){
            if(root->val > p->val && root->val > q->val)
                root = root->left;
            else if(root->val < p->val && root->val < q->val)
                root = root->right;
        }

        return root;
    }
};

/*
Runtime: 42 ms, faster than 29.99% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.2 MB, less than 63.36% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/