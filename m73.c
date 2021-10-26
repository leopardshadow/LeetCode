/*
最簡單的想法是直接複製整張 matrux，這樣才能區分原本的 0 和新設的 0，space complexity 是 O(mn)。
如果改紀錄哪幾個 row, col 都要設成 0，space complexity 是 O(m + n)。
題目問有沒有辦法在 constant space complecity 下完成？
：偷用第一個 col 和第一個 row 來儲存該 row/col 的資訊
!!! 注意 range，一開始犯的錯是第一個 col 有人是 0，結果存哪 row/col 的第一個 col 和第一個 row 變全 0
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        bool first_col_is_0 = false,
             first_row_is_0 = false;
        for(int i = 0; i < m.size(); i++) {
            if(m[i][0] == 0) {
                first_col_is_0 = true;
                break;
            }
        }
        for(int i = 0; i < m[0].size(); i++) {
            if(m[0][i] == 0) {
                first_row_is_0 = true;
                break;
            }
        }
        // use the first row & col to store the information
        for(int y = 1; y < m.size(); y++) {
            for(int x = 1; x < m[0].size(); x++) {
                if(m[y][x] == 0) {
                    m[0][x] = 0;
                    m[y][0] = 0;
                }
            }
        }
        // use the information to set the matrix
        for(int i = 1; i < m.size(); i++) {
            if(m[i][0] == 0) {
                for(int j = 1; j < m[0].size(); j++) {
                    m[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < m[0].size(); i++) {
            if(m[0][i] == 0) {
                for(int j = 1; j < m.size(); j++) {
                    m[j][i] = 0;
                }
            }
        }
        // deal with first col
        if(first_col_is_0) {
            for(int i = 0; i < m.size(); i++) {
                m[i][0] = 0;
            }
        }
        // deal with first row
        if(first_row_is_0) {
            for(int i = 0; i < m[0].size(); i++) {
                m[0][i] = 0;
            }
        }

    }
};

/*
Runtime: 22 ms, faster than 29.13% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.3 MB, less than 54.04% of C++ online submissions for Set Matrix Zeroes.
*/