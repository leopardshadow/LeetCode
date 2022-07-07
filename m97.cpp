
// 2022.7.7 七夕

/*
DP ... QQ
看別人 DP 的 code 都大概知道他的意思，但自己就是寫不出來(((
這題原本好像是 hard
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3)
            return false;
        // dp[i][j]: can s3[0, i+j] can be composed of s1[0, i] & s2[0, j]
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1));
        dp[0][0] = 1;
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i > 0) 
                    dp[i][j] = dp[i][j] | (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
                if (j > 0) 
                    dp[i][j] = dp[i][j] | (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));        
            }
        }
        return dp[n1][n2];
    }
};
/*
Runtime: 6 ms, faster than 63.84% of C++ online submissions for Interleaving String.
Memory Usage: 6.6 MB, less than 73.36% of C++ online submissions for Interleaving String.
*/
