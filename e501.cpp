/*
和 530. Minimum Absolute Difference in BST 基本上是同一個模子刻出來的
*/

class Solution {
    int maxTimes, curTimes;
    vector<int> ans;
    TreeNode *prevNode = NULL;
public:
    void inorder(TreeNode *curNode) {
        if(!curNode) return;
            
        inorder(curNode->left);
        
        //
        if(prevNode) {
            if(prevNode->val == curNode->val)
                curTimes++;
            else
                curTimes = 1;
        }
        else {
            curTimes = 1;
        }
        // when to add --------------------
        // 在更新完值之後就判斷當前的 node (curNode) 要不要加進答案
        if(curTimes > maxTimes) {
            maxTimes = curTimes;
            ans.clear();
            ans.push_back(curNode->val);
        }
        else if(curTimes == maxTimes) {
            ans.push_back(curNode->val);
        }
        // --------------------------------
            

        prevNode = curNode;
        
        inorder(curNode->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        maxTimes = 0;
        inorder(root);
        return ans;
    }
};
