
// 2022.8.7

/*
---
一發幹掉 Hard DP 耶！
a|   e i u
e| a   i
i|   e   o
o|     i
u|     i o
*/

typedef long L;
const int M = 1000000007;
const int A = 0;
const int E = 1;
const int I = 2;
const int O = 3;
const int U = 4;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<L>> dp(2, vector<L>(5, 0));
        for (int i = 0; i < 5; i++)
            dp[0][i] = 1;
        
        for (int i = 0; i < n; i++) {
            int a = i % 2, b = (i + 1) % 2;
            dp[b][A] = dp[a][E];
            dp[b][E] = (dp[a][A] + dp[a][I]) % M;
            dp[b][I] = (dp[a][A] + dp[a][E] + dp[a][O] + dp[a][U]) % M;
            dp[b][O] = (dp[a][I] + dp[a][U]) % M;
            dp[b][U] = dp[a][A] ;
        }
        
        long ans = 0;
        for (int i = 0; i < 5; i++)
            ans += dp[(n - 1) % 2][i];
        
        return ans % M;
    }
};
/*
Runtime: 23 ms, faster than 73.83% of C++ online submissions for Count Vowels Permutation.
Memory Usage: 5.9 MB, less than 90.50% of C++ online submissions for Count Vowels Permutation.
*/
