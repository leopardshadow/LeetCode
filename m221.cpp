/*
Good sol.
https://leetcode.com/problems/maximal-square/discuss/1524547/O(N)-Space-oror-95-time-optimised-and-space-optimised-Upto-90-oror-C%2B%2B-Code

Nice explanation
https://leetcode.com/problems/maximal-square/discuss/1632145/C%2B%2B-EASY-TO-SOLVE-oror-Detailed-Explanation-of-DP-with-Visualization-and-dry-run
*/

class Solution {
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int R = matrix.size(), C = matrix[0].size();
        
        vector<vector<int>> dp(R, vector<int>(C, 0));
        
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(r == 0 || c == 0 || matrix[r][c] == '0')
                    dp[r][c] = matrix[r][c] - '0';
                else
                    dp[r][c] = 1 + min3(dp[r-1][c], dp[r][c-1], dp[r-1][c-1]);
                ans = max(ans, dp[r][c]);
            }
        }
        return ans * ans;
    }
};

/*
Runtime: 28 ms, faster than 42.74% of C++ online submissions for Maximal Square.
Memory Usage: 12 MB, less than 27.34% of C++ online submissions for Maximal Square.
*/
