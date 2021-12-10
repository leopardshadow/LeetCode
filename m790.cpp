// 2021.12.10

/*
Hint. DP
*/

class Solution {
public:
    int numTilings(int n) {
        
        vector<int> dp(max(5, n + 1), 0);
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        dp[4] = 11;
        
        if(n <= 3)
            return dp[n];
        
        for(int i = 5; i <= n; i++) {
            dp[i] = 2 * dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
