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
補充：隨便的樹找 LCA 在 236.

!!!!!!!!!!!!
注意等號的位置
!!!!!!!!!!!!

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



/*
這題和 236. Lowest Common Ancestor of a Binary Tree 不同的的地方是：
236 是隨便的 tree，而這題是 binary serach tree，所以找的過程可以比較有效率
*/

//***************************************************************************//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root)
            return NULL;
        
        if (root->val >= p->val && root->val <= q->val ||
            root->val >= q->val && root->val <= p->val) {
            return root;
        }
        else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

/*
Runtime: 51 ms, faster than 9.97% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.4 MB, less than 11.76% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/


// 2022.8.12


