/*
完全背包問題
和 1-0 取不取的背包問題最大的不同是 coins 迭代的方向!
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int c : coins) {
            for(int i = c; i <= amount; i++) {
                dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
};


/*
Runtime: 8 ms, faster than 90.98% of C++ online submissions for Coin Change 2.
Memory Usage: 7 MB, less than 88.19% of C++ online submissions for Coin Change 2.
*/
