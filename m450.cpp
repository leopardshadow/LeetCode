/*
像這種 tree 的題目，要在腦袋中造樹好難 @@
現在還是 WA，先更新一下...
*/

/*
1. Search for a node to remove.
2. If the node is found, delete the node.
*/

class Solution {
    TreeNode *prevTarg;
    bool record;
public:
    Solution() {
        prevTarg = NULL;
        record = false;
    }
    
    TreeNode *findVal(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) {
            record = true;
            return root;
        }
        else if(root->val > key) {
            TreeNode *temp = findVal(root->left, key);
            if(record) {
                prevTarg = root;
                record = false;
            }
            return temp;
        }
        else {
            TreeNode *temp = findVal(root->right, key);
            if(record) {
                prevTarg = root;
                record = false;
            }
            return temp;
        }
    }
    TreeNode *deleteNode(TreeNode* root, int key) {
        
        // 1. find the value
        TreeNode *targetNode = findVal(root, key);
        if(!targetNode) return root;
        
        // the only node in the tree is going to be removed
        if(targetNode == root && !root->left && !root->right)
            return NULL;
        
        // 2. remove the target node
        // now we'd like to remove targetNode
        // we'll find some node to replace it
        // the one I'm gonna to choose is the biggest of its subtree
        // so there are 3 different possibilities:
        TreeNode *biggestSubnode, *prevBiggest;
        // (1) the one we'd like to remove has no subtrees
        if(!targetNode->left && !targetNode->right) {
            if(prevTarg && prevTarg->left && prevTarg->left->val == key)
                prevTarg->left = NULL;
            if(prevTarg && prevTarg->right && prevTarg->right->val == key)
                prevTarg->right = NULL;
        }
        // (2) it has right subtree -> find min from right subtree
        else if (targetNode->right) {
            prevBiggest = targetNode;
            biggestSubnode = targetNode->right;
            while(biggestSubnode->left) {
                prevBiggest = biggestSubnode;
                biggestSubnode = biggestSubnode->left;
            }
            prevBiggest->right = NULL;
            targetNode->val = biggestSubnode->val;
        }
        // (3) it only has left subtree -> find max from left subtree
        else {
            prevBiggest = targetNode;
            biggestSubnode = targetNode->left;
            while(biggestSubnode->right) {
                prevBiggest = biggestSubnode;
                biggestSubnode = biggestSubnode->right;
            }
            prevBiggest->left = NULL;
            targetNode->val = biggestSubnode->val;
        }
        return root;
    }
};
