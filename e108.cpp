
class Solution {
public:
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, start, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};

/*
Runtime: 16 ms, faster than 50.17% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 21.5 MB, less than 41.88% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
*/
