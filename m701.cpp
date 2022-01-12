/*
題目說只要是合法的 BST，差在哪裡隨便你
最簡單是放在原本 leaf 的位置，不用更改整棵樹的結構
對我來說，這題的迭代寫法比較簡單，遞迴反而比較不直觀
---
特別提一下遞迴的寫法，

```
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
```

那行 if 這裡的意思是，root 的 right 會被改掉，else 則是 root->left 會被改掉
至於改成什麼?
如果進的是 if 且 root->right == NULL，那他就會從 NULL 改指向 new 出來的 TreeNode
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if (!root)
            return new TreeNode(val);
        
        TreeNode *node = root, *prev = NULL;
        
        while (node) {
            prev = node;
            if (node->val > val)
                node = node->left;
            else
                node = node->right;
        }
        
        if (prev->val > val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);
        
        return root;
    }
};

/*
Runtime: 126 ms, faster than 20.42% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 56.9 MB, less than 48.05% of C++ online submissions for Insert into a Binary Search Tree.
*/



class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
            
        return root;
    }
};

/*
Runtime: 80 ms, faster than 90.55% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 57 MB, less than 48.05% of C++ online submissions for Insert into a Binary Search Tree.
*/


// 沒有偷看之前寫的，但寫法跟之前幾乎一模一樣 XD
// 2022.1.12

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        else if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        // root->val == val will not happen
        return root;
    }
};


/*
Runtime: 113 ms, faster than 33.03% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 56.8 MB, less than 80.92% of C++ online submissions for Insert into a Binary Search Tree.
*/
