
// 2022.9.10

/*
參考了其他人的解答 ><
---
dp[i][0] 是最多 k 次交易中的必須付出的 **min** cost
dp[i][1] 是最多 k 次交易中的可以達到的 **max** profit

注意這個寫法 dp 陣列的意義，第一個是交易次數 k

在迴圈中
(1)
...
(2)
．．．
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if (k == 0)
            return 0;
        
        vector<vector<int>> dp(k + 1, {INT_MAX, 0});
        
        for (const int &price : prices) {
            for (int i = 1; i <= k; i++) {
                dp[i][0] = min(dp[i][0], price - dp[i-1][1]);
                dp[i][1] = max(dp[i][1], price - dp[i][0]);
            }
        }
        
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= 1; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        
        return dp[k][1];
    }
};
/*
Runtime: 20 ms, faster than 50.86% of C++ online submissions for Best Time to Buy and Sell Stock IV.
Memory Usage: 11 MB, less than 75.61% of C++ online submissions for Best Time to Buy and Sell Stock IV.
*/
