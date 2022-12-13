// DP D13

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rSize = matrix.size(), 
            cSize = matrix[0].size();
        for(int r = 1; r < rSize; r++) {
            for(int c = 0; c < cSize; c++) {
                int left = c == 0 ? INT_MAX : matrix[r-1][c-1],
                    top = matrix[r-1][c],
                    right = c == cSize - 1 ? INT_MAX : matrix[r-1][c+1];
                matrix[r][c] += min(left, min(top, right));                
            }
        }
        int ans = INT_MAX;
        for(int c = 0; c < cSize; c++) {
            ans = min(ans, matrix[rSize-1][c]);
        }
        return ans;
    }
};

/*
Runtime: 4 ms, faster than 99.82% of C++ online submissions for Minimum Falling Path Sum.
Memory Usage: 9.8 MB, less than 55.12% of C++ online submissions for Minimum Falling Path Sum.
*/

// 2022.12.13
