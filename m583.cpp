
// 2022.6.14

/*
這題一看就 DP 樣，但我寫不出來 QQ 最後看了討論區
---
和 Longest Common Subsequence (LCS) 有關
https://leetcode.com/problems/longest-common-subsequence/solution/
是 Premium @@
---
題目問的是從 s1, s2 刪掉一些數字讓他變得一樣，換個方式想，如果我知道刪完之後他們會長怎樣，就可以知道要刪幾個字 (不用知道過程，只在乎最後的樣子)
他們最後長成的模樣會是 Longest Common Subsequence (LCS)，留下最多，才會刪的最少
---
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
---
接下來就是 LCS 的事了
設定 dp[M+1][N+1] 的 table 來存值，其中 M = len(w1, N = len(w2)
dp[i][j] 存的東西是 w1[0:i) 和 w2[0:j) 的 LCS
w[0, i) 表示 w 第 i 位之前的 substring 
*/

class Solution {
    int lcs(string &w1, string &w2, int &m, int &n) {
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (w1[i-1] == w2[j-1] ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        return m + n - 2 * lcs(word1, word2, m, n);
    }
};
/*
Runtime: 38 ms, faster than 34.42% of C++ online submissions for Delete Operation for Two Strings.
Memory Usage: 12.3 MB, less than 34.50% of C++ online submissions for Delete Operation for Two Strings.
*/
