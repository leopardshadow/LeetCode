/*
原本以為這題只是考矩陣操作，看了一下討論區還是有滿有趣的做法
我的做法會把整張數獨走 3 次，分別處理 row, col 和 subbox 的重複
但其實也可以走一次就好，只是就要用空間換時間，需要 9 + 9 + 9 = 27 個 validator
*/

class Validator {
    int r;
public:
    Validator() {
        r = 0;
    }
    bool addNum(char c) {
        if(c == '.') // don't do anything for '.'
            return true;
        int n = (int)(c - '0');
        if(r & (1 << n))
            return false;  // not valid, the number has appeareds
        else
            r = r | (1 << n);
        return true;
    }
    void reset() {
        r = 0;
    }
};


// my original solution
class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        Validator vali;
        // 1. check each row
        for(int r = 0; r < 9; r++) {
            vali.reset();
            for(int c = 0; c < 9; c++) {
                if(!vali.addNum(board[r][c]))
                    return false;
            }
        }
        // 2. check each col
        for(int c = 0; c < 9; c++) {
            vali.reset();
            for(int r = 0; r < 9; r++) {
                if(!vali.addNum(board[r][c]))
                    return false;
            }
        }
        // 3. check subbox
        for(int rs = 0; rs < 3; rs++) {
            for(int cs = 0; cs < 3; cs++) {
                vali.reset();
                for(int ri = 0; ri < 3; ri++) {
                    for(int ci = 0; ci < 3; ci++) {
                        if(!vali.addNum(board[3*rs+ri][3*cs+ci]))
                            return false;
                    }
                }
            }
        }
        
        return true;
    }
};
/*
Runtime: 20 ms, faster than 79.93% of C++ online submissions for Valid Sudoku.
Memory Usage: 18 MB, less than 74.30% of C++ online submissions for Valid Sudoku.
*/

/////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        Validator row[9], col[9], subbox[9];
        // check each row, each col and each subbox by traversing the whole board one time
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(!row[r].addNum(board[r][c]) || !col[c].addNum(board[r][c]) || !subbox[3*(r/3) + c/3 ].addNum(board[r][c])) {
                   return false; 
                }
            }
        }
        return true;
    }
};

/*
Runtime: 16 ms, faster than 93.48% of C++ online submissions for Valid Sudoku.
Memory Usage: 18.1 MB, less than 74.30% of C++ online submissions for Valid Sudoku.
*/
