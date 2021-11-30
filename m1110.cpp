//***************************************************************************//
// 2021.11.30 before G VO

/*
這題要把樹切割，從他 list 裡面有的地方斷開成森林
用到了和之前寫刪除 BST 節點時類似的方式
```
    root->left = solve(root->left);
```

如果 root->left 恰好是要刪掉的，他會回傳 NULL，把 root->left 的值設成 0
---
要特別注意如果 root 就是要刪的怎麼辦
* root 要刪掉：直接 call，反正 root 不會被加進去
* root 不用刪：要自己加進答案裡，這個 node 一定會出現在答案裡，即使之後斷光光
---
所以在我的寫法中，只有兩個地方可能加東西
1. 整棵樹的 root
2. 要砍掉的節點，他的左、右 subtree (NULL 就不加，NULL 可能是原本就 NULL 或他的 children 也要被刪)
*/

class Solution {
    vector<TreeNode*> ans;
    unordered_set<int> m;
public:
    
    TreeNode* solve(TreeNode* root) {
        
        if(!root) {
            return root;
        }
        
        if(m.count(root->val)) {
            TreeNode *temp = solve(root->left);
            if(temp)
                ans.push_back(temp);
            temp = solve(root->right);
            if(temp)
                ans.push_back(temp);
            delete root; // delete here
            return NULL;
        }
        else {
            root->left = solve(root->left);
            root->right = solve(root->right);
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int d : to_delete)
            m.insert(d);
        // needs to handle this special case
        // if the one we're going to delete is root
        if(m.count(root->val)) {
            solve(root);
        }
        else {
            ans.push_back(root);
            solve(root);
        }
        
        return ans;
    }
};
