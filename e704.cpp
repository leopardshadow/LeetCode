class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};

/*
Runtime: 36 ms, faster than 69.74% of C++ online submissions for Binary Search.
Memory Usage: 27.6 MB, less than 61.69% of C++ online submissions for Binary Search.
*/
