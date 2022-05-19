
// 2022.5.19

/*
連兩天 Hard 是怎樣。。。
好幾個星期沒出，現在是要補回來嗎？
---
還是好不擅長 DP，看了討論區
---
我現在在 (i, j) 的位置，有四個方向（上、下、左、右可以走），選其中最長的路 --> 這是 recursive step
可以走的條件是 (i', j') 還在 matrix 的範圍內且 mat[i][j] > mat[i'][j'] --> 這是 base case (path length = 1)
---
看了寫法之後感覺一切都很合理但自己就是沒辦法在看之前想到QQ
*/

class Solution {
    vector<vector<int>> dp;
    int maxPath;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        maxPath = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                maxPath = max(maxPath, solve(matrix, i, j, -1));
        }
        return maxPath;
    }
    
    int solve(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i < 0 || i >= matrix.size() ||
            j < 0 || j >= matrix[0].size() ||
            matrix[i][j] <= prev)
            return 0;
        else if (dp[i][j])
            ;
        else
            dp[i][j] = 1 + max({
                solve(matrix, i + 1, j, matrix[i][j]),
                solve(matrix, i - 1, j, matrix[i][j]),
                solve(matrix, i, j + 1, matrix[i][j]),
                solve(matrix, i, j - 1, matrix[i][j])
            });
        return dp[i][j];
    }
};
/*
Runtime: 126 ms, faster than 22.08% of C++ online submissions for Longest Increasing Path in a Matrix.
Memory Usage: 15.9 MB, less than 81.29% of C++ online submissions for Longest Increasing Path in a Matrix.
*/
