// 以為之前寫過，但那題是 inorder + preorder
/*
這三題一起寫一寫ㄅ
105. Construct Binary Tree from Preorder and Inorder Traversal
106. Construct Binary Tree from Inorder and Postorder Traversal
889. Construct Binary Tree from Preorder and Postorder Traversal
*/


/*
Hint.

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                            int inStart, int inEnd,
                            int postStart, int postEnd) {
        ...
    }
    
(防雷線?)
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.

*/


/*

left-subtree
node
right-subtree
*/

/*

       .─────.                   
      (   3   )                  
       `─────'                   
      /       \
     /         \                    
    /           \                    
 .─────.         .─────.          
(   9   )       (  20   )         
 `─────'         `─────'          
                  /     \           
                 /       \
                /         \
          .─────.          .─────. 
         (  15   )        (   7   )
          `─────'          `─────' 
(正在試用 monodraw XD)

pre-order: 3 9 20 15 7
in-order: 9 3 15 20 7
post-order: 9 15 7 20 3

            0   1  2  3  4
in-order:   9 (3) 15 20  7
post-order: 9  15  7 20 (3)

key:
從 in-order 中抓到中間的 node，他左邊是 left subtree，右邊是 right subtree
怎麼抓中間的 node? 用 post-order 的最後一個來看
*/
class Solution {
    map<int, int> findInorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            findInorder[inorder[i]] = i;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                            int inStart, int inEnd,
                            int postStart, int postEnd) {
        if(inStart > inEnd)
            return NULL;
        else {
            int inMid = findInorder[ postorder[postEnd] ];
            int leftSize = inMid - inStart,
                rightSize = inEnd - inMid;
            TreeNode *node = new TreeNode(inorder[inMid]);
            node->left = buildTree(inorder, postorder, inStart, inMid-1, postStart, postStart + leftSize-1);
            node->right = buildTree(inorder, postorder, inMid+1, inEnd, postStart + leftSize, postEnd-1);
            return node;
        }
    }
};

/*
Runtime: 12 ms, faster than 90.14% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
Memory Usage: 26.4 MB, less than 54.93% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
*/
