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




// 2021.12.12

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int n : nums)
            sum += n;
        
        // odd
        if(sum % 2)
            return false;
        
        int halfSum = sum / 2;
        
        vector<int> dp(halfSum + 1, 0);
        
        for(int i = 0; i < nums.size(); i++) {
            for(int s = halfSum; s >= 0; s--) {
                if(s - nums[i] >= 0)
                    dp[s] = max(dp[s], nums[i] + dp[s - nums[i]]);
            }
        }        
        return dp.back() == halfSum;
    }
};

/*
Runtime: 208 ms, faster than 43.15% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 9.9 MB, less than 77.84% of C++ online submissions for Partition Equal Subset Sum.
*/
