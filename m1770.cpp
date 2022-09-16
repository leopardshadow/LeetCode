
// 2022.9.16

/*
討厭 DP
*/

class Solution {
    int n;
    vector<vector<int>> memo;
    int dp(vector<int>& nums, vector<int>& multipliers, int op, int left) {
        if (op == multipliers.size())
            return 0;
        
        if (memo[op][left] != INT_MIN)
            return memo[op][left];
        
        int l = nums[left] * multipliers[op] + dp(nums, multipliers, op + 1, left + 1);
        int r = nums[(n - 1) - (op - left)] * multipliers[op] + dp(nums, multipliers, op + 1, left);
        
        return memo[op][left] = max(l, r);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        memo.resize(multipliers.size() + 1, vector<int>(multipliers.size() + 1, INT_MIN));
        return dp(nums, multipliers, 0, 0);
    }
};
/*
Runtime: 640 ms, faster than 61.02% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
Memory Usage: 120 MB, less than 68.36% of C++ online submissions for Maximum Score from Performing Multiplication Operations.
*/
