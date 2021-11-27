
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root){
    if(!root)
        return 0;
    if(root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);
    else
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);    
}

/*
Runtime: 4 ms, faster than 59.55% of C online submissions for Sum of Left Leaves.
Memory Usage: 6.3 MB, less than 55.06% of C online submissions for Sum of Left Leaves.
*/



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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        else if(root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.5 MB, less than 11.34% of C++ online submissions for Sum of Left Leaves.
*/



/*
練習用 BFS，迭代寫法
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            //----------------------------------------------
            if(n->left && !n->left->right && !n->left->left)
                sum += n->left->val;
            else if(n->left)
                q.push(n->left);
            //----------------------------------------------
            if(n->right)
                q.push(n->right);
        }
        return sum;
    }
};

/*
Runtime: 8 ms, faster than 25.12% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.6 MB, less than 8.89% of C++ online submissions for Sum of Left Leaves.
*/
