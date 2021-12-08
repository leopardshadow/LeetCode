// 2021.12.8

/*
決定好 tree traverse 的順序後，基本上就解完惹
*/

class Solution {
    int tiltSum = 0;
    int postorder(TreeNode *root) {
        if(!root)
            return 0;
        else {
            int lsum = postorder(root->left),
                rsum = postorder(root->right);
            tiltSum += abs(lsum - rsum);
            return lsum + rsum + root->val;
        }
    }
public:
    int findTilt(TreeNode* root) {
        postorder(root);
        return tiltSum;
    }
};

/*
Runtime: 33 ms, faster than 10.87% of C++ online submissions for Binary Tree Tilt.
Memory Usage: 23.6 MB, less than 96.69% of C++ online submissions for Binary Tree Tilt.
*/
