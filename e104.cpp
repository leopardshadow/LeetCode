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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

/*
Runtime: 7 ms, faster than 78.06% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.8 MB, less than 56.09% of C++ online submissions for Maximum Depth of Binary Tree.
*/


//***************************************************************************//
/*
之前寫的是遞迴作法，這次試試 BFS 的的迭代作法
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int i = q.size();
            while(i) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                i--;
            }
            // 這裡還滿關鍵的，如果這層的處理完已經沒有的話，那深度就會停在這層
            // 但如果 queue 有放東西進去的話，深度才會 +1
            if(q.empty())
                break;
            else
                depth++;
        }
        return depth;
    }
};

/*
Runtime: 27 ms, faster than 6.13% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.9 MB, less than 14.35% of C++ online submissions for Maximum Depth of Binary Tree.
*/



// 2022.2.14 情人節耶

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};

/*
Runtime: 4 ms, faster than 95.27% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.9 MB, less than 56.35% of C++ online submissions for Maximum Depth of Binary Tree.
*/
