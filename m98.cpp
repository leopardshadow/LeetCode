/*
我是利用 BST 左邊所有節點都比這個節點小，右邊所有節點都比這個節點大，這樣遞迴往下
看到也有人是把他 in-order 的 traverse 過一次，他的印出來順序剛好會是排序過的，只要檢查這點就好了 (補充：這樣比較簡單辣)

我有特別處理值在 INT_MIN 和 INT_MAX 的 case，多寫了 shouldBigger 和 shouldSmaller
如果他的 range 都不在那麼邊邊，只要 inRange 就好了
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return shouldSmaller(root->left, root->val) &&
               shouldBigger(root->right, root->val);
    }
    // all the tree nodes should be in range (a, b)
    bool shouldInRange(TreeNode* root, int a, int b) {
        if(!root) return true;
        if(root->val <= a || root->val >= b) return false;
        return shouldInRange(root->left, a, root->val) && 
               shouldInRange(root->right, root->val, b);
    }
    // all the tree nodes should be bigger than n (> n)
    bool shouldBigger(TreeNode* root, int n) {
        if(!root) return true;
        if(root->val <= n)
            return false;
        return shouldInRange(root->left, n, root->val) && shouldBigger(root->right, root->val);
    }
    // all the tree nodes should be smaller than n (< n)
    bool shouldSmaller(TreeNode* root, int n) {
        if(!root) return true;
        if(root->val >= n)
            return false;
        return shouldSmaller(root->left, root->val) && shouldInRange(root->right, root->val, n);
    }
};

/*
Runtime: 4 ms, faster than 98.93% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.7 MB, less than 30.44% of C++ online submissions for Validate Binary Search Tree.
*/

//***************************************************************************//
// Review: 2021.11.28 before G VO

/*
上次寫的作法好麻煩喔，請善用 BST inorder traversal 會是排序好的性質
如果他不是 BST，那麼 inorder traversal 就不會是 sorted 的
---
Q: 這是雙向箭頭嗎？有沒有 inorder traversal 會是排序好的，但不是 BST 的 binary tree
*/

class Solution {
    TreeNode *prevNode;
    bool isValid;
public:
    void inorder(TreeNode *node) {
        if(!node)
            return;
        
        inorder(node->left);
        
        if(prevNode) {
            if(prevNode->val >= node->val) {
                isValid = false;
                return;   // if it is already not valid, no need to check the rest
            }
        }
        prevNode = node;
        
        inorder(node->right);
    }
    
    bool isValidBST(TreeNode* root) {
        prevNode = NULL;
        isValid = true;
        inorder(root);
        return isValid;
    }
};

// 剛好都 89.64% 耶 XDD
/*
Runtime: 8 ms, faster than 89.64% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.6 MB, less than 89.64% of C++ online submissions for Validate Binary Search Tree.
*/





//******************************************************************************//
// 12.29 - Just Before A VO

class Solution {
    TreeNode *prev;
    bool inorder(TreeNode *node) {
        
        if(!node)
            return true;
        
        if(!inorder(node->left))
            return false;
        
        if(prev && prev->val >= node->val)
            return false;
        prev = node;

        return inorder(node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return inorder(root);
    }
};

/*
Runtime: 16 ms, faster than 28.63% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.7 MB, less than 30.33% of C++ online submissions for Validate Binary Search Tree.
*/


// 2022.8.11 HBD :D
