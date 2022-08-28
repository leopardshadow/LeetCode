
// 2022.8.28

/*
先找到對角後排序
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        for (int d = - (C - 1); d <= (R - 1); d++) {
                 
            for (int r1 = 0; r1 < R; r1++) {
                for (int r2 = r1 + 1; r2 < R; r2++) {
                    int c1 = r1 - d, c2 = r2 - d;
                    if (c1 < 0 || c1 >= C ||
                        c2 < 0 || c2 >= C)
                        continue;
                    if (mat[r1][c1] > mat[r2][c2])
                        swap(mat[r1][c1], mat[r2][c2]);
                }
                
            }
        }
        return mat;
    }
};
/*
Runtime: 44 ms, faster than 5.28% of C++ online submissions for Sort the Matrix Diagonally.
Memory Usage: 8.5 MB, less than 98.60% of C++ online submissions for Sort the Matrix Diagonally.
*/
