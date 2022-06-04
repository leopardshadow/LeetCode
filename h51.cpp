// backtracking

/*
經典的八皇后題
要注意的是為避免輸出同樣的棋盤，我用 start 表示目前擺到哪
如果目前 Q 擺在 3，那下一個皇后要從 4 開始放，0~ 3 就不要再試了
0 1 2 3 4
5 6 7 8 9
...
---
以上是我一開始的想法，其實這份 code 有可以加速的地方，例如：
一個 row 就只能放一個 Q，當我知道 3 放了，那也不用檢查 4 了，直接跳 5 就行
*/

class Solution {
    vector<vector<string>> ans;
    vector<string> board;
    int n;
public:
    bool stillvalid(int r, int c) {
        // check horizonal and vertical
        for (int i = 0; i < n; i ++) {
            if (board[r][i] == 'Q' || board[i][c] == 'Q')
                return false;
        }
        // check X
        int direc[] = {-1, -1, 1, 1, -1};
        for (int d = 0; d < 4; d++) {
            int moveR = direc[d], moveC = direc[d+1];
            while (r + moveR >= 0 && r + moveR < n &&
                  c + moveC >= 0 && c + moveC < n) {
                if (board[r + moveR][c + moveC] == 'Q') {
                    return false;
                }
                moveR += direc[d];
                moveC += direc[d+1];
            }
        } 
        return true;
    }
    void solve(int qLeft, int start) {
        if(qLeft == 0) {
            ans.push_back(board);
            return;
        }
        for(int i = start; i < n * n; i++) {
            int r = i / n, c = i % n;
            if (stillvalid(r, c)) {
                board[r][c] = 'Q';
                solve(qLeft - 1, i + 1);
                board[r][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string emptyRow = "";
        for(int i = 0; i < n; i++)
            emptyRow += ".";
        for(int i = 0; i < n; i++)
            board.push_back(emptyRow);
        solve(n, 0);
        return ans;
    }
};

/*
Runtime: 784 ms, faster than 5.08% of C++ online submissions for N-Queens.
Memory Usage: 7.4 MB, less than 58.75% of C++ online submissions for N-Queens.
*/


class Solution {
    vector<vector<string>> ans;
    vector<string> board;
    int n;
public:
    bool stillvalid(int r, int c) {
        // check horizonal and vertical
        for (int i = 0; i < n; i ++) {
            if (board[r][i] == 'Q' || board[i][c] == 'Q')
                return false;
        }
        // check X
        int direc[] = {-1, -1, 1, 1, -1};
        for (int d = 0; d < 4; d++) {
            int moveR = direc[d], moveC = direc[d+1];
            while (r + moveR >= 0 && r + moveR < n &&
                  c + moveC >= 0 && c + moveC < n) {
                if (board[r + moveR][c + moveC] == 'Q') {
                    return false;
                }
                moveR += direc[d];
                moveC += direc[d+1];
            }
        } 
        return true;
    }
    void solve(int qLeft, int startRow) {
        if(qLeft == 0) {
            ans.push_back(board);
            return;
        }
        int r = startRow;
        for(int c = 0; c < n; c++) {
            if (stillvalid(r, c)) {
                board[r][c] = 'Q';
                solve(qLeft - 1, r + 1);
                board[r][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string emptyRow(n, '.');
        for(int i = 0; i < n; i++)
            board.push_back(emptyRow);
        solve(n, 0);
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 64.00% of C++ online submissions for N-Queens.
Memory Usage: 7.4 MB, less than 51.81% of C++ online submissions for N-Queens.
*/

// 2022.6.4 !
