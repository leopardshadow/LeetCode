/*
這算是 post-order 的 traversal
如果找到了就 return p/q
如果這個 node 左邊、右邊都有返回，他就是 LCA
如果只有一邊，那就表示他們的 LCA 在更下面的地方，原地 return

```
        if(!root)
            return NULL;
        if(root == p)
            return p;                
        if(root == q)
            return q;
```

這段的邏輯其實可以被精減成

```
if(!root || root == p || root == q)
  return root;
```

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root == p)
            return p;                
        if(root == q)
            return q;
        TreeNode *foundLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *foundRight = lowestCommonAncestor(root->right, p, q);
        if(foundLeft && foundRight)
            return root;
        else if(foundLeft)
            return foundLeft;
        else
            return foundRight;
    }
};

/*
Runtime: 30 ms, faster than 12.89% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 14.2 MB, less than 58.05% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
*/
