
// 2022.6.5

/*
跟昨天的好像，只差在把 ans 換成 ans.size()
---
更快的作法是，因為 n = [1, 9] 範圍很小，可以直接建表
res[10] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352}
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
        
    int totalNQueens(int n) {
        this->n = n;
        string emptyRow(n, '.');
        for(int i = 0; i < n; i++)
            board.push_back(emptyRow);
        solve(n, 0);
        return ans.size();
    }

};
/*
Runtime: 8 ms, faster than 52.21% of C++ online submissions for N-Queens II.
Memory Usage: 6.5 MB, less than 39.65% of C++ online submissions for N-Queens II.
*/
