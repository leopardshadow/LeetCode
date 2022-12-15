
// 2022.12.15

/*
應該算是經典的 DP 題
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        dp[0][0] = (text1[0] == text2[0]);
        for (int j = 1; j < n2; j++)
            dp[0][j] = max(dp[0][j-1], (int)(text1[0] == text2[j]));
        for (int i = 1; i < n1; i++) {
            dp[i][0] = max(dp[i-1][0], (int)(text1[i] == text2[0]));
            for (int j = 1; j < n2; j++) {
                dp[i][j] = max(
                    dp[i-1][j-1] + (text1[i] == text2[j]),
                    max(dp[i-1][j], dp[i][j-1])
                );
            }
        }
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp.back().back();
    }
};
