
// 2022.4.12

/*
看了一下討論區，大家 in-place 的解法都是利用 int 來區分狀態，如果一開始給的是 bool 好像就無法做了 ... 還以為有辦法做到「真的 inplace」
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> drs = {1, 1, 1, 0, 0,-1,-1,-1};
        vector<int> dcs = {1, 0,-1, 1,-1, 1, 0,-1};
        int R = board.size(), C = board[0].size();

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int cnt = 0;
                for (int adj = 0; adj < drs.size(); adj++) {
                    int dr = drs[adj], dc = dcs[adj];
                    if (r + dr < R && 
                        r + dr >= 0 && 
                        c + dc < C &&
                        c + dc >= 0 &&
                        board[r+dr][c+dc] & 1)
                        cnt++;
                }
                if (board[r][c]) {  // live cell
                    if (cnt == 2 || cnt == 3)
                        board[r][c] |= 2;
                    // else die (0)
                }
                else {  // dead cell
                    if (cnt == 3)
                        board[r][c] |= 2;
                }
            }
        }
        
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                board[r][c] >>= 1;
    }
};

// 有點意外會 100% ... 因為我用到了 & 和 | 嗎
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
Memory Usage: 6.9 MB, less than 84.44% of C++ online submissions for Game of Life.
*/
