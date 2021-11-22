/*
原本在寫了 450. Delete Node in a BST 後，看到那種寫法，想找一題 clone tree 的 (像 133. Clone Graph 那樣)
沒找到，但遇到了這題，就來寫寫看
全部自己寫的，但 performance 好爛，這裡有兩個寫法：
1. 把 original 對應到的 cloned 也一起傳來傳去
2. 先把左、右的資訊記錄下來，再讓 cloned iteratively 得移動
因為沒有用到 value 資訊而是用地址來比較，所以 follow-up 自然就解了~
*/
class Solution {
    vector<bool> direcs;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original)
            return NULL;
        if(original == target)
            return cloned;
        TreeNode *node = getTargetCopy(original->left, cloned->left, target);
        if(node)
            return node;
        node = getTargetCopy(original->right, cloned->right, target);
        if(node)
            return node;
        return NULL;  // will not return this in this question
    }
};

/*
Runtime: 1243 ms, faster than 5.08% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
Memory Usage: 164.1 MB, less than 21.50% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
*/


class Solution {
    vector<bool> direcs;
public:
    bool find(TreeNode* root, TreeNode* target) {
        if(!root)
            return false;
        else if(root == target)
            return true;
        direcs.push_back(true);
        if(find(root->left, target))
            return true;    
        direcs.pop_back();
        direcs.push_back(false);
        if(find(root->right, target))
            return true;
        direcs.pop_back();
        return false;  // will never returns this in this question
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        find(original, target);
        for(int i = 0; i < direcs.size(); i++) {
            if(direcs[i])
                cloned = cloned->left;
            else
                cloned = cloned->right;
        }
        return cloned;
    }
};

/*
Runtime: 726 ms, faster than 19.89% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
Memory Usage: 163.9 MB, less than 83.49% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
*/
