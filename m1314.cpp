// DP D14

//***************************************************************************//
// 2021.12.1 before G VO (今天的感覺炸了 QQ)

/*
先寫個暴力解法
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans(mat);
        int rSize = mat.size(),
            cSize = mat[0].size();
        for(int r = 0; r < rSize; r++) {
            for(int c = 0; c < cSize; c++) {
                int sum = 0;
                for(int rr = max(0, r - k); rr <= min(rSize - 1, r + k); rr++) {
                    for(int cc = max(0, c - k); cc <= min(cSize - 1, c + k); cc++) {
                        sum += mat[rr][cc];   
                    }
                }
                ans[r][c] = sum;
            }
        }
        return ans;
    }
};

/*
Runtime: 636 ms, faster than 10.07% of C++ online submissions for Matrix Block Sum.
Memory Usage: 9.3 MB, less than 76.52% of C++ online submissions for Matrix Block Sum.
*/
