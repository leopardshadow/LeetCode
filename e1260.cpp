
// 2022.4.11

/*
TC: O(R C)
SC: O(R C)
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans = grid;
        int R = grid.size(), C = grid[0].size();
        for (int i = 0; i < R * C; i++) {
            int j = (i + k) % (R*C);
            int old_r = i / C, old_c = i % C;
            int new_r = j / C, new_c = j % C;
            ans[new_r][new_c] = grid[old_r][old_c];
        }
        return ans;
    }
};
/*
Runtime: 28 ms, faster than 79.20% of C++ online submissions for Shift 2D Grid.
Memory Usage: 14 MB, less than 40.46% of C++ online submissions for Shift 2D Grid.
*/


/*
一步一步移動
TC: o(k R C)
SC: O(1)
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int R = grid.size(), C = grid[0].size();
        k = k % (R * C);
        for (int i = 0; i < k; i++) {
            int lastNum = grid.back().back();
            for (int j = R * C - 1; j >= 1; j--) {  // note the order
                grid[j / C][j % C] = grid[(j-1) / C][(j-1) % C];    
            }
            grid[0][0] = lastNum;
        }
        return grid;
    }
};
/*
Runtime: 119 ms, faster than 7.98% of C++ online submissions for Shift 2D Grid.
Memory Usage: 13.9 MB, less than 87.46% of C++ online submissions for Shift 2D Grid.
*/




/*
嘗試不額外存 grid
剛剛想錯了，我把他依照 mod k 分組，但他們的數字不是只在組之間互換
---
應該先寫這題 https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int R = grid.size(), C = grid[0].size();
        k = k % (R * C);
        for (int i = 0; i < k; i++) {
            int temp = grid[(i + R * C - k)/C][(i + R * C - k)%C];
            int j;
            for (j = i + R * C - k; j - k >= 0; j -= k) {
                cout << "j - " << j << endl;
                grid[j/C][j%C] = grid[(j-k)/C][(j-k)%C];
            }
            
            int t = k - j % k;
            grid[t/C][t%C] = temp;
        }
        return grid;
    }
};
