// 可以利用 BST in-order 走過就是排序好的性質

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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        in_order(root, k);
        return ans;
    }
    // Let's find the order first
    void in_order(TreeNode* root, int &k) {
        if(!root)  return;
        in_order(root->left, k);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        in_order(root->right, k);
    }
};

/*
Runtime: 8 ms, faster than 99.73% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 24 MB, less than 98.70% of C++ online submissions for Kth Smallest Element in a BST.
*/


//***************************************************************************//
// Review: 2021.11.28 before G VO

class Solution {
    int i, k;
public:
    int inorder(TreeNode *node) {
        if(!node)
            return -1;
        int left = inorder(node->left);
        if(left >= 0)
            return left;
        
        if(i == k)
            return node->val;
        
        i++;
        return inorder(node->right);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        i = 1;
        this->k = k;
        return inorder(root);
    }
};

/*
Runtime: 16 ms, faster than 83.56% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 24 MB, less than 98.77% of C++ online submissions for Kth Smallest Element in a BST.
*/



//***************************************************************************//
// 2022.4.18

/*
inorder!
---
那時候沒看清楚範圍，>= 0 打成 > 0 吃了一個 WA ...
---
另外要注意順序 (左 -> 中 -> 右) 啊啊啊啊
*/

class Solution {
    int index;
public:
    int kthSmallest(TreeNode* root, int k) {
        index = k;
        return inorder(root);
    }
    int inorder(TreeNode* node) {
        if (!node)
            return -1;
        int ret = inorder(node->left);
        if (ret >= 0)
            return ret;
        
        index--;  // 1-indexed -> -1 first
        if (index == 0)
            return node->val;

        return inorder(node->right);
    }
};
/*
Runtime: 26 ms, faster than 45.50% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 24 MB, less than 87.81% of C++ online submissions for Kth Smallest Element in a BST.
*/
