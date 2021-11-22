/*
像這種 tree 的題目，要在腦袋中造樹好難 @@
現在還是 WA，先更新一下...
嗚嗚嗚
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
        TreeNode *maxSubnode, *minSubnode, *prevBiggest;
        
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
            minSubnode = targetNode->right;
            while(minSubnode->left) {
                prevBiggest = minSubnode;
                minSubnode = minSubnode->left;
            }
            targetNode->val = minSubnode->val;
            if(prevBiggest == targetNode)
                prevBiggest->right = NULL;
            else
                prevBiggest->left = NULL;
        }
        
        // (3) it only has left subtree -> find max from left subtree
        else {
            prevBiggest = targetNode;
            maxSubnode = targetNode->left;
            while(maxSubnode->right) {
                prevBiggest = maxSubnode;
                maxSubnode = maxSubnode->right;
            }
            prevBiggest->left = NULL;
            targetNode->val = maxSubnode->val;
        }
        return root;
    }
};

//***************************************************************************//

/*
自己寫得好亂，還沒過 @@ 決定來看一下解答
他把情況分成三種處理
  1. 要被刪除的節點是 leaf node (沒有任何 subtree)
  2. 要被刪除的節點只有 1 支 subtree
  3. 要被刪除的節點有 2 支 subtree
  
這個寫法很漂亮的是用 recursive 處理了很多複雜判斷條件的 code (像上面那樣 ...)
而且他把找 target 和刪除做在一起。可能也是被 Leetcode 的 hint 影響吧，一開始我想先找到目標，再把他刪除，分成兩個區塊的 code。

下面這段的架構會出現在尋找的過程中，但他這邊是修改了 root->left/right
如果 target 比 root->val 小，那 target 會出現在左半邊，root->left 的值會被改掉 (如果 target 存在)
(這裡就不用設條件判斷是他下一個就被拿掉還是出現在更後面，反正用 return 的方式處理)

```
if(root->val > key) 
    root->left = deleteNode(root->left, key);
else if(root->val < key)
    root->right = deleteNode(root->right, key);
```

接著就是找到 target 時要做什麼

這裡分成 3 個 case，但大方向都不變，

1. 要被刪除的節點是 leaf node (沒有任何 subtree)
直接 delete 掉，return NULL
這裡和上面 `root->left = deleteNode(root->left, key)` 的配合好讚喔

2. 要被刪除的節點只有 1 支 subtree
直接跨過去後，delete root

3. 要被刪除的節點有 2 支 subtree
從右邊 (因為兩邊都有，所以必定有右邊) subtree 抓最小的，把 root 的值取代成這個最小的，
接著目標換成把這個最小的刪掉，這裡是我覺得很妙的一點，因為這個最小的一定沒有 left，所以找到他真的刪除時，他會用 1, 2 那邊的 code 刪除
*/

class Solution {
public:
    int findMin(TreeNode* root) {
        while(root->left) {
            root = root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key) 
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else {  // roo->val == key
            // 1. no leaf
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }
                
            // 3. both left & right subtrees -> find min from right
            else if(root->left && root->right) {
                int minValR = findMin(root->right);
                root->val = minValR;
                root->right = deleteNode(root->right, minValR);
            }
            
            // 2. one child
            else {
                TreeNode *temp;
                if(root->left) {
                    temp = root->left;
                    delete root;
                }
                else {
                    temp = root->right;
                    delete root;
                }
                return temp;
            }
        }
        return root;
    }
};

/*
Runtime: 34 ms, faster than 49.26% of C++ online submissions for Delete Node in a BST.
Memory Usage: 32.7 MB, less than 75.07% of C++ online submissions for Delete Node in a BST.
*/
