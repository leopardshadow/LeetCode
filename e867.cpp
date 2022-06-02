
// 2022.6.2

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> newMat(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                newMat[j][i] = matrix[i][j];
        return newMat;
    }
};
/*
Runtime: 13 ms, faster than 73.06% of C++ online submissions for Transpose Matrix.
Memory Usage: 10.6 MB, less than 78.16% of C++ online submissions for Transpose Matrix.
*/
