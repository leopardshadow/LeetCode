
//2022.4.13


/*
這題和 54. Spiral Matrix
 https://leetcode.com/problems/spiral-matrix/ 滿像的，都是 spiral matrix
---
好容易搞混 x,y 和 r,c QQ

(r,c)
     (0, +1)
     ------->
(0,0) (0,1) (0,2)  |
(1,0) (1,1)        | (+1, 0)
(2,0)              v
     <-------
     (0, -1)

---
一開始
    mat[r+dr[d]][c+dc[d]] != 0
寫成
    mat[r][c] != 0
所以一直換方向
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int dr[4] = {0, 1,  0, -1};
        int dc[4] = {1, 0, -1,  0};
        int d = 0, r = 0, c = 0;  // initial direction & position
        
        for (int i = 1; i <= n * n; i++) {
            
            mat[r][c] = i;
            
            // change direction
            if (r + dr[d] >= n ||
                r + dr[d] < 0 ||
                c + dc[d] >= n ||
                c + dc[d] < 0 ||
                mat[r+dr[d]][c+dc[d]] != 0)
                d = (d + 1) % 4;
            
            r += dr[d];
            c += dc[d];
        }        
        
        return mat;
    }
};
/*
Runtime: 4 ms, faster than 19.27% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.6 MB, less than 18.13% of C++ online submissions for Spiral Matrix II.
*/
