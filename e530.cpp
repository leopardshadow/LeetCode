/*
雖然說要找任兩點之間的最小絕對值的差，但因為他是 binary search tree，所以其實他一定會發生在 inorder 順序的相鄰節點
*/
class Solution {
    TreeNode *prevNode = NULL;
    int ans = INT_MAX;
public:
    void inorder(TreeNode* root) {
        
        if(!root) return;
        
        //
        inorder(root->left);

        //
        if(prevNode)
            ans = min(ans, abs(prevNode->val - root->val));
        prevNode = root;
        
        //
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

/*
Runtime: 21 ms, faster than 35.57% of C++ online submissions for Minimum Absolute Difference in BST.
Memory Usage: 25.1 MB, less than 78.44% of C++ online submissions for Minimum Absolute Difference in BST.
*/
