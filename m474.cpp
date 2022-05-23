
/*
dp[i][j]: the max size of subset that has at most i 0s and j 1s
Key: 2D 的狀態
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        vector<pair<int, int>> cnts(strs.size());
        for(int i = 0; i < strs.size(); i++) {
            int cnt0 = 0, cnt1 = 0;
            for(char c : strs[i]) {
                if(c == '0')
                    cnt0++;
                else
                    cnt1++;
            }
            cnts[i] = {cnt0, cnt1};
        }
        
        for(int i = 0; i < cnts.size(); i++) {
            for(int c0 = m; c0 >= cnts[i].first; c0--) {
                for(int c1 = n; c1 >= cnts[i].second; c1--) {
                    dp[c0][c1] = max(dp[c0][c1], dp[c0 - cnts[i].first][c1 - cnts[i].second] + 1);
                }
            }            
        }
        return dp[m][n];
    }
};


/*
Runtime: 296 ms, faster than 48.39% of C++ online submissions for Ones and Zeroes.
Memory Usage: 9.9 MB, less than 64.20% of C++ online submissions for Ones and Zeroes.
*/

// 2022.5.23
// ;
