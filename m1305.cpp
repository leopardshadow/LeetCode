 
// 2022.1.26

/*
一次 traverse 兩棵樹，看起不能 recursive 得跑過整棵樹，只能用 iterative
這是我一開始的想法
---
但是 hint 也叫人兩個 tree 分開做，最後再 sort
如果先全部混在一起是很簡單，但是時間複雜度是 O(n log n)，因為可以更快的
---
但是如果一開始是分成兩個 list，就可以用像 merge sort 合併階段的方式去弄
時間複雜度可以降到 O(m + n)
*/


class Solution {
    vector<int> ans;
    void inorder(TreeNode *node) {
        if(!node)
            return;
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1);
        inorder(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Runtime: 136 ms, faster than 75.44% of C++ online submissions for All Elements in Two Binary Search Trees.
Memory Usage: 85.2 MB, less than 62.58% of C++ online submissions for All Elements in Two Binary Search Trees.
*/



// 時間複雜度降，執行時間卻增加好多，不過主要還是看複雜度啦 嗚
class Solution {
    void inorder(TreeNode *node, vector<int> &v) {
        if(!node)
            return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> ans, v1, v2;

        inorder(root1, v1);
        inorder(root2, v2);
        
        int i = 0, j = 0;
        
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] < v2[j]) {
                ans.push_back(v1[i]);
                i++;
            }
            else {
                ans.push_back(v2[j]);
                j++;    
            }
        }
        while(i < v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }
        while(j < v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }

        return ans;
    }
};

/*
Runtime: 271 ms, faster than 16.39% of C++ online submissions for All Elements in Two Binary Search Trees.
Memory Usage: 86.8 MB, less than 15.36% of C++ online submissions for All Elements in Two Binary Search Trees.
*/
