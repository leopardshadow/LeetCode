
// 2022.7.16

/*
DP QQ．．．
for i ... for j ... 的雙層迴圈內的判斷條件不能分開來寫
例如 (i = 0, j = 0) 本來就應該被計算兩次
*/

class Solution {
    int mat(vector<vector<int>> x, int i, int j) {
        int m = x.size(), n = x[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n)
            return x[i][j];
        return 0;
    }
public:
    const int M = 1000000007;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long count = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        for (int move = 0; move < maxMove; move++) {
            vector<vector<int>> temp(dp);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0)
                        count = (count + dp[i][j]) % M;
                    if (i == m-1)
                        count = (count + dp[i][j]) % M;
                    if (j == 0)
                        count = (count + dp[i][j]) % M;
                    if (j == n-1)
                        count = (count + dp[i][j]) % M;

                    temp[i][j] = (mat(dp, i-1, j) + mat(dp, i+1, j) + mat(dp, i, j-1) + mat(dp, i, j+1)) % M;
                }
            }
            cout << count << endl;
            dp = temp;
        }
        
        return count;
    }
};
