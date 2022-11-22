/*
也是可以取很多樣東西的背包題目變形，只是這次他沒明確說要放進背包的東西是什麼
其實就是 1, 4, 9, 16, ..., n
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        for(int i = 1; i * i <= n; i++) {
            int sq = i * i;
            for(int w = sq; w <= n; w++) {
                dp[w] = min(dp[w], dp[w - sq] + 1);
            }
        }
        return dp[n];
    }
};

/*
Runtime: 160 ms, faster than 62.76% of C++ online submissions for Perfect Squares.
Memory Usage: 9.1 MB, less than 40.07% of C++ online submissions for Perfect Squares.
*/

// 2022.11.22
