/*
我原本狀態轉移部分寫成這樣
```
        for(int i = 0; i < nums.size(); i++) {
            for(int w = sum; w >= 0; w--) {
                if(w - nums[i] >= 0)
                    dp[w] = max(dp[w], nums[i] + dp[w - nums[i]]);
            }
        }
```
但其實可以精減成下面的，不用那個 if

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum += n;
        if(sum % 2 == 1)
            return false;
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int w = sum; w >= nums[i]; w--) {
                dp[w] = max(dp[w], nums[i] + dp[w - nums[i]]);
            }
        }
        return dp.back() == sum;
    }
};

/*
Runtime: 200 ms, faster than 46.67% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 9.9 MB, less than 81.36% of C++ online submissions for Partition Equal Subset Sum.
*/
