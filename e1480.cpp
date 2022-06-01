
// 2022.6.1

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans[i] = sum;
        }
        return ans;
    }
};
/*
Runtime: 6 ms, faster than 32.99% of C++ online submissions for Running Sum of 1d Array.
Memory Usage: 8.5 MB, less than 38.06% of C++ online submissions for Running Sum of 1d Array.
*/
