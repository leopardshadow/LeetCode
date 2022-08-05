
// 2022.8.5

/*
背包問題
之前有寫過好像沒存到？？？
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int n : nums) {
                if(i - n >= 0)
                    dp[i] += dp[i-n];
            }
        }
        return dp[target];
    }
};

