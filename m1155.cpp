
// 2022.10.2

/*
自己寫的 DP!
---
#1: 如果要湊出 6，骰子點數 是 7, 8, 9 ... 的完全沒用
---
有兩個東西要維護：骰子的數量和目前的點數總和
*/

class Solution {
    const int M = 1000000007;
public:
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][j] --> i dices with sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 1; i <= min(k, target); i++) // #1
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int x = 1; x <= k; x++)
                    if (j - x >= 1)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % M;
            }
        }
        return dp[n][target];
    }
};
/*
Runtime: 135 ms, faster than 12.68% of C++ online submissions for Number of Dice Rolls With Target Sum.
Memory Usage: 8.4 MB, less than 45.97% of C++ online submissions for Number of Dice Rolls With Target Sum.
*/
